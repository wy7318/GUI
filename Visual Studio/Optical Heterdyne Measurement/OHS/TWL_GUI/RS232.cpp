/* Serial line terminal program
 * characters can be displayed as in hex, decimal and ascii 
 * characters can be seperated by space, tab, newline or 'nothing'
 * local echo can be switched on or off
 *

 * by Albrecht Schmidt, Lancaster University - Oct 2001
 * http://www.comp.lancs.ac.uk/~albrecht 
 * Albrecht@comp.lancs.ac.uk
 * based on an example from Robert Mashlan - 
 *                    see http://r2m.com/~rmashlan/
 */

#include "stdafx.h"
#define STRICT
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ITLA.h"

#define MAXPORTS 16

char *comports[MAXPORTS] = { "\\\\.\\COM1",  "\\\\.\\COM2",  "\\\\.\\COM3",  "\\\\.\\COM4",
"\\\\.\\COM5",  "\\\\.\\COM6",  "\\\\.\\COM7",  "\\\\.\\COM8",
"\\\\.\\COM9",  "\\\\.\\COM10", "\\\\.\\COM11", "\\\\.\\COM12",
"\\\\.\\COM13", "\\\\.\\COM14", "\\\\.\\COM15", "\\\\.\\COM16" };

static LPCSTR _ports_id[MAXPORTS];
int _portsactive=0;
int DisplayMode, separator, echo, logNum;
static char _buf_out[10*MAXPORTS],_buf_in[10*MAXPORTS];
static BOOL _readytosend[MAXPORTS];
static int _bytestosend[MAXPORTS];
static int _received[MAXPORTS];

void PrintError( LPCSTR str)
{
   LPVOID lpMessageBuffer;
   int error = GetLastError();
   FormatMessage(
      FORMAT_MESSAGE_ALLOCATE_BUFFER |
      FORMAT_MESSAGE_FROM_SYSTEM,
      NULL,
      error,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), //The user default language
      (LPTSTR) &lpMessageBuffer,
      0,
      NULL
   );
   printf("%s: (%d) %s\n\n", str, error, (char*)lpMessageBuffer);
   LocalFree( lpMessageBuffer );
}

void RS232SetBuffer(unsigned char* buffer, int count, int port)
{
	int teller=0;
	while (teller<count)
	{
		_buf_out[teller+(port-1)*10]=buffer[teller];
		teller=teller+1;
	}
	_bytestosend[port-1]=_bytestosend[port-1]+count;
}

void RS232Send(int port)
{_readytosend[port-1]=true;}

BOOL RS232IsReceived(int count, int port)
{
	if (_received[port-1]<count)
		return false;
	else 
		return true;
}

int RS232EndReceived(unsigned char temp,int port)
{
	int teller=0;
	int position =-1;
	while (teller<_received[port-1] && position<0)
	{
		if (_buf_in[teller+10*(port-1)]==temp) position=teller;
		teller=teller+1;
	}
	return (position);
}

unsigned char* RS232ReadBuffer(unsigned char* buffer, int count,int port)
{
	int teller=0;
	while (teller<count)
	{
		buffer[teller]=_buf_in[teller+(port-1)*10];
		teller=teller+1;
		_received[port-1]=_received[port-1]-1;
	}
	teller=0;
	while (teller<_received[port-1])
	{
		_buf_in[teller+(port-1)*10]=_buf_in[teller+count];
		teller=teller+1;
	}
	return buffer;
}


DWORD CALLBACK ConInThread( HANDLE h )
{
   OVERLAPPED ov;
   HANDLE hconn = GetStdHandle(STD_INPUT_HANDLE);
   BOOL quit = FALSE;
   int activeport=_portsactive;

   //printf("started the CONINTHREAD\n");
   ZeroMemory(&ov,sizeof(ov));
   ov.hEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
   if(ov.hEvent == INVALID_HANDLE_VALUE) {PrintError("E001_CreateEvent failed"); SetCommMask(h,0);  return 0;   }
   SetConsoleMode(hconn,0);
   //printf("press Esc or Ctrl+C to terminate\n");    
   do //infinite loop
   {
	  DWORD read = 0;
      SetConsoleMode(hconn,0);
	  if(_readytosend[activeport-1]) 
	  {
         DWORD write=1;
				//printf("Sending %x  \n",_buf_out[0]);
					// send it to the com port
				char test[10];
				test[0]=_buf_out[10*(activeport-1)];
				test[1]=_buf_out[10*(activeport-1)+1];
				if( !WriteFile(h,test,write,&write,&ov) ) 
				{
					if(GetLastError() == ERROR_IO_PENDING) 
					{
						if( !GetOverlappedResult(h,&ov,&write,TRUE) ) {PrintError("E003_GetOverlappedResult failed");quit = TRUE;}
					}
				} 
				else 
				{	PrintError("E004_WriteFile failed");	quit = TRUE;	}
         //}
		_bytestosend[activeport-1]=_bytestosend[activeport-1]-1;
		int teller=0;
		while (teller<_bytestosend[activeport-1])
		{
			_buf_out[teller+10*(activeport-1)]=_buf_out[teller+1+10*(activeport-1)];
			teller=teller+1;
		}
		if (_bytestosend[activeport-1]==0) _readytosend[activeport-1]=false;
      }
   } while(!quit);
   // tell terminal thread to quit
   if (!SetCommMask(h,0)) {printf("SetCommMask-GetLastError: %i\n", GetLastError());   }
   return 0;
}


DWORD CALLBACK Terminal( HANDLE h )
{
   HANDLE hconn = GetStdHandle(STD_OUTPUT_HANDLE);
   DWORD mask;
   DWORD i;
   OVERLAPPED ov;
   int activeport=_portsactive;
  
   //printf("started the TERMINAL\n");
   ZeroMemory(&ov,sizeof(ov));
   // create event for overlapped I/O
   ov.hEvent = CreateEvent(NULL,FALSE,FALSE,NULL);
   if(ov.hEvent == INVALID_HANDLE_VALUE)		PrintError("E006_CreateEvent failed");
   // wait for received characters
   if(!SetCommMask(h,EV_RXCHAR))				PrintError("E007_SetCommMask failed");
   while( 1 ) 
   {
      // get the event mask
      if( !WaitCommEvent(h,&mask,&ov) ) 
	  {
         //printf("after waitcomevent\n");
		 DWORD e = GetLastError();
         if( e == ERROR_IO_PENDING ) 
		 {
            DWORD r;
			//printf("inside error io pending\n");
            if( !GetOverlappedResult(h,&ov,&r,TRUE) ) { // printf("inside overlap results\n");              
			PrintError("E008_GetOverlappedResult failed");          break;     }
         } 
		 else 
		 {  PrintError("E009_WaitCommEvent failed"); break;}
      }
      // if no event, then UI thread terminated with SetCommMask(h,0)
      if( mask == 0 ) break;
      if( mask & EV_RXCHAR) 
	  {
         char buf[10];
         DWORD read;
         do 
		 {
            read = 0;
            if( !ReadFile(h,buf,sizeof(buf),&read,&ov) ) 
			{
               if( GetLastError() == ERROR_IO_PENDING ) 
			   {
                  if( !GetOverlappedResult(h,&ov,&read,TRUE) )	  {PrintError("E010_GetOverlappedResult failed");break;}
               } 
			   else 
			   {  PrintError("E011_ReadFile failed");break;}
            }
            if(read)
		 	  // WriteFile(hconn,buf,read,&read,NULL);
			  for (i=0; i<read; i++) 
				{//printf("0x%x", (unsigned char)buf[i]); printf(" ");
				_buf_in[_received[activeport-1]+(activeport-1)*10]=buf[i];
				_received[activeport-1]=_received[activeport-1]+1;}
		 } while(read);
      }
      mask = 0;
   }
   CloseHandle(ov.hEvent);  // close the event
   return 0;  
 }

BOOL isnewport(LPCSTR portid)
{
	BOOL goon=true;
	int teller=0;
	while (teller < MAXPORTS)
	{
		if (_ports_id[teller] == portid) goon = false;
		teller = teller + 1;
	}
	return goon;
}

int RS232InitPort(int comport_number, int brate)
{
	if (isnewport(comports[comport_number]))
    {
		DWORD listener,writer;
        //HANDLE h = CreateFile(portid,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_FLAG_OVERLAPPED,NULL);
		HANDLE h = CreateFile(comports[comport_number], GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
		if (h == INVALID_HANDLE_VALUE) PrintError("E012_Failed to open port"); 
		else 
		{
			_ports_id[_portsactive] = comports[comport_number];
			_readytosend[_portsactive] = 0;
			_bytestosend[_portsactive] = 0;
			_received[_portsactive] = 0;
			// set timeouts
			 COMMTIMEOUTS cto = { 2, 1, 1, 0, 0 };
			 DCB dcb;
			 if (!SetCommTimeouts(h, &cto))		PrintError("E013_SetCommTimeouts failed");
			 // set DCB
			 DisplayMode = 0;  //output is ascii
			 separator = 0;  //separator is space
			 echo = 1;//echo is on
			 logNum = 0; //log is off
			 memset(&dcb,0,sizeof(dcb));
			 dcb.DCBlength = sizeof(dcb);
			 dcb.BaudRate = brate;
			 dcb.fBinary = 1;
			 dcb.fDtrControl = DTR_CONTROL_ENABLE;
			 dcb.fRtsControl = RTS_CONTROL_ENABLE;
			 dcb.Parity = NOPARITY;
			 dcb.StopBits = ONESTOPBIT;
			 dcb.ByteSize = 8;
			 if(!SetCommState(h,&dcb))            PrintError("E014_SetCommState failed");
			 //Start RS-232 Receiver
			 _portsactive=_portsactive+1;
			 HANDLE hconout = CreateThread(NULL,0,Terminal,h,0,&listener);
			 if( hconout == INVALID_HANDLE_VALUE ) {PrintError("E005_CreateThread failed\n");return 0;}
			 //Start RS-232 Sender
			 HANDLE hconin = CreateThread(NULL,0,ConInThread,h,0,&writer);
			 if( hconin == INVALID_HANDLE_VALUE ) {PrintError("E005_CreateThread failed\n");return 0;}	
			 return _portsactive;
		  }
	}
	return 0;
}
