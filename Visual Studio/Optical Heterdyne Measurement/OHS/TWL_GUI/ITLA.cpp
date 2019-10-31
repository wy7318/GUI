#include "stdafx.h"
//#include "RS232.h"
#include <stdlib.h>
#include "rs232_linux.h"
#include "stdio.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <math.h>
#include <conio.h>
#include "gnuplot.h"
#include "time.h""
#include <iomanip>      // std::setw
#include "globalFunc.h"
#include "ftd2xx.h"


#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

using namespace System;
using namespace std;

int _lastvalue = 0;
int minFreq = 0;
int maxFreq = 0;
int minPwr = 0;
int maxPwr = 0;
FT_HANDLE ftHandle;

unsigned char calcBIP4(unsigned char* data) { 
	unsigned char bip8 = (data[0] & 0x0f) ^ data[1] ^ data[2] ^ data[3]; 
	unsigned char bip4 = ((bip8 & 0xf0) >> 4) ^ (bip8 & 0x0f); 
	return bip4;
} 


int main() {
	GnuplotPipe gp;
	gp.sendLine("set xrange [-2:12]");
	gp.sendLine("set yrange [-1.2:1.2]");
	gp.sendLine("x=2");
	gp.sendLine("plot x**2");
	return 0;
}

unsigned char* ITLAAea(int reg, int data, int RW, int port)
{
	unsigned char buf[4];
	char temp[4] = "";
	unsigned char bip4;
	// Using current time as filename
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[80] = "";
	int i = 0, n = 0;

	strftime(buffer, 80, "%Y-%m-%d.txt", now);

	
	buf[0] = RW;
	buf[1] = reg;
	buf[2] = ((int)data >> 8) & 0xff;
	buf[3] = (int)data & 0xff;


	bip4 = calcBIP4(buf);
	buf[0] |= (bip4 << 4);	// Add in the BIP-4 checksum

	n = RS232_SendBuf(port, buf, 4);		// send command and data to ITLA
											//printf("%d\n", n);
	Delay_ms(100);		// Must keep the delay before getting response
	n = RS232_PollComport(port, buf, 4);	// read back from ITLA
											//printf("%d\n", n);
	buf[n] = 0;




	return buf;
}


unsigned char* ITLACommand(int reg, int data, int RW, int port)
{
	unsigned char buf[4];
	char temp[4] = "";
	unsigned char bip4;
	// Using current time as filename
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[80] = "";
	int i = 0, n = 0;

	strftime(buffer, 80, "%Y-%m-%d.txt", now);

	FILE *f = fopen(buffer, "a");
	if (f == NULL) {
		printf("Error opening file!\n");
		exit(-1);
	}

	buf[0] = RW;
	buf[1] = reg;
	buf[2] = ((int)data >> 8) & 0xff;
	buf[3] = (int)data & 0xff;

	printf("ITLA Send Command:");
	printf("\tReg.\tData\tRW\n");
	printf("\t\t(DEC)\t%02d\t%02d\t%02d\n", reg, data, RW);
	printf("Bytes before checksum\t%02x  %02x  %02x  %02x\n", buf[0], buf[1], buf[2], buf[3]);
	// write to file
	fprintf(f, "ITLA Send Command:");
	fprintf(f, "\tReg.\tData\tRW\n");
	fprintf(f, "\t\t(Dec)\t%02d\t%02d\t%02d\n", reg, data, RW);
	fprintf(f, "Bytes before checksum\t%02x  %02x  %02x  %02x\n", buf[0], buf[1], buf[2], buf[3]);

	

	bip4 = calcBIP4(buf);
	buf[0] |= (bip4 << 4);	// Add in the BIP-4 checksum
	printf("Bytes after checksum\t%2.2x  %2.2x  %2.2x  %2.2x\n", buf[0], buf[1], buf[2], buf[3]);
	fprintf(f, "Bytes after checksum\t%2.2x  %2.2x  %2.2x  %2.2x\n", buf[0], buf[1], buf[2], buf[3]);
	n = RS232_SendBuf(port, buf, 4);		// send command and data to ITLA
	//printf("%d\n", n);
	Delay_ms(100);		// Must keep the delay before getting response
	n = RS232_PollComport(port, buf, 4);	// read back from ITLA
	//printf("%d\n", n);
	buf[n] = 0;

	printf("Response from ITLA\t%2.2x  %2.2x  %2.2x  %2.2x\n\n", buf[0], buf[1], buf[2], buf[3]);
	fprintf(f, "Response from ITLA\t%2.2x  %2.2x  %2.2x  %2.2x\n\n", buf[0], buf[1], buf[2], buf[3]);
	_lastvalue = (int)buf[2] * 256 + (int)buf[3];
	printf("lastvalue %d \n",_lastvalue);
	


	fclose(f);
	//Delay_ms(100);

	return buf;
}



unsigned char* ITLACommand2(int reg, double data, int RW, int port) //double version of ITLAcommand
{
	unsigned char buf[4];
	char temp[4] = "";
	unsigned char bip4;
	// Using current time as filename
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	char buffer[80] = "";
	int i = 0, n = 0;

	strftime(buffer, 80, "%Y-%m-%d.txt", now);

	FILE *f = fopen(buffer, "a");
	if (f == NULL) {
		printf("Error opening file!\n");
		exit(-1);
	}

	buf[0] = RW;
	buf[1] = reg;
	buf[2] = ((int)data >> 8) & 0xff;
	buf[3] = (int)data & 0xff;

	printf("ITLA Send Command:");
	printf("\tReg.\tData\tRW\n");
	printf("\t\t(DEC)\t%02d\t%02d\t%02d\n", reg, data, RW);
	printf("Bytes before checksum\t%02x  %02x  %02x  %02x\n", buf[0], buf[1], buf[2], buf[3]);
	// write to file
	fprintf(f, "ITLA Send Command:");
	fprintf(f, "\tReg.\tData\tRW\n");
	fprintf(f, "\t\t(Dec)\t%02d\t%02d\t%02d\n", reg, data, RW);
	fprintf(f, "Bytes before checksum\t%02x  %02x  %02x  %02x\n", buf[0], buf[1], buf[2], buf[3]);



	bip4 = calcBIP4(buf);
	buf[0] |= (bip4 << 4);	// Add in the BIP-4 checksum
	printf("Bytes after checksum\t%2.2x  %2.2x  %2.2x  %2.2x\n", buf[0], buf[1], buf[2], buf[3]);
	fprintf(f, "Bytes after checksum\t%2.2x  %2.2x  %2.2x  %2.2x\n", buf[0], buf[1], buf[2], buf[3]);
	n = RS232_SendBuf(port, buf, 4);		// send command and data to ITLA
											//printf("%d\n", n);
	Delay_ms(100);		// Must keep the delay before getting response
	n = RS232_PollComport(port, buf, 4);	// read back from ITLA
											//printf("%d\n", n);
	buf[n] = 0;

	printf("Response from ITLA\t%2.2x  %2.2x  %2.2x  %2.2x\n\n", buf[0], buf[1], buf[2], buf[3]);
	fprintf(f, "Response from ITLA\t%2.2x  %2.2x  %2.2x  %2.2x\n\n", buf[0], buf[1], buf[2], buf[3]);
	_lastvalue = (int)buf[2] * 256 + (int)buf[3];
	printf("lastvalue %d \n", _lastvalue);



	fclose(f);
	//Delay_ms(100);

	return buf;
}
/*
unsigned char* SendCommand(int port, )
{}
*/



unsigned char* AEA(int port, int bytes)
{
	unsigned char* temp = NULL;
	unsigned char* outp = NULL;
	string stdStr = "";

	while (bytes > 0) {
		temp = ITLAAea(0, 0x0b, 0, port);
		outp = outp + temp[2];
		outp = outp + temp[3];
		bytes = bytes - 2;
	}
	std::sprintf(const_cast<char*>(stdStr.c_str()), "%X", outp);
	String^ str = gcnew String(stdStr.c_str());
	printf("%X\n\n", str);

	return outp; 
}


int ITLALastValue()
{
	return _lastvalue;
}




String^ ITLAshow(int reg, int data, int RW, int port)
{
	unsigned char buf[4] = "";
	char temp[4] = "";
	unsigned char bip4 = NULL;
	int i = 0, n = 0;
	string stdStr = "";

	buf[0] = RW;
	buf[1] = reg;
	buf[2] = (data >> 8) & 0xff;
	buf[3] = data & 0xff;

	printf("ITLA Send Command:");
	printf("\tReg.\tData\tRW\n");
	printf("\t\t(DEC)\t%02d\t%02d\t%02d\n", reg, data, RW);
	printf("Bytes before checksum\t%02x  %02x  %02x  %02x\n", buf[0], buf[1], buf[2], buf[3]);

	bip4 = calcBIP4(buf);
	buf[0] |= (bip4 << 4);	// Add in the BIP-4 checksum
	printf("Bytes after checksum\t%02x  %02x  %02x  %02x\n", buf[0], buf[1], buf[2], buf[3]);
	n = RS232_SendBuf(port, buf, 4);		// send command and data to ITLA
											//printf("%d\n", n);
	Delay_ms(100);		// Must keep the delay before getting response
	n = RS232_PollComport(port, buf, 4);	// read back from ITLA
											//printf("%d\n", n);
	buf[n] = 0;

	printf("Response from ITLA\t%02x  %02x  %02x  %02x\n\n", buf[0], buf[1], buf[2], buf[3]);
	std::sprintf(const_cast<char*>(stdStr.c_str()), "%02x%02x%02x%02x", buf[0], buf[1], buf[2], buf[3]);
	String^ str = gcnew String(stdStr.c_str());
	_lastvalue = (int)buf[2] * 256 + (int)buf[3];
	//printf("lastvalue %d \n",_lastvalue);

	return str;
}

double Round_off(double N, double n)
{
	int h;
	double l, a, b, c, d, e, i, j, m, f, g;
	b = N;
	c = floor(N);

	// Counting the no. of digits to the left of decimal point 
	// in the given no. 
	for (i = 0; b >= 1; ++i)
		b = b / 10;

	d = n - i;
	b = N;
	b = b * pow(10, d);
	e = b + 0.5;
	if ((float)e == (float)ceil(b)) {
		f = (ceil(b));
		h = f - 2;
		if (h % 2 != 0) {
			e = e - 1;
		}
	}
	j = floor(e);
	m = pow(10, d);
	j = j / m;

	return j;
}


double ThzToNm(double thz)
{
	double nm = ((299792458 * pow(10,-3) / thz) * 100 + .5);
	cout << nm << " nm\n";
	
	return nm/100;
}

double NmtoThz(double nm)
{
	double thz = (int)((299792458 * pow(10, -3) / nm)*100 + .5);
	cout << thz << " THz\n";
	return thz / 100;
}




bool openPort(void)
{
	FT_STATUS ftStatus;

	/* When this fails on OSX run: sudo kextunload -b com.FTDI.driver.FTDIUSBSerialDriver */
	if ((ftStatus = FT_OpenEx((char *)"FT230X Basic UART", FT_OPEN_BY_DESCRIPTION, &ftHandle)) != FT_OK) {
		cout << "Error in FT_OpenEx:" << ftStatus;
		return false;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	if ((ftStatus = FT_ResetDevice(ftHandle)) != FT_OK) {
		cout << "Error in FT_ResetDevice:" << ftStatus;
		return false;
	}
	if ((ftStatus = FT_Purge(ftHandle, FT_PURGE_RX | FT_PURGE_TX)) != FT_OK) {
		cout << "Error in FT_Purge:" << ftStatus;
		return false;
	}
	if ((ftStatus = FT_SetUSBParameters(ftHandle, 65536, 65536)) != FT_OK) {
		cout << "Error in FT_SetUSBParameters:" << ftStatus;
		return false;
	}
	if ((ftStatus = FT_SetChars(ftHandle, 0, 0, 0, 0)) != FT_OK) {
		cout << "Error in FT_SetChars:" << ftStatus;
		return false;
	}
	if ((ftStatus = FT_SetTimeouts(ftHandle, 10, 5000)) != FT_OK) {
		cout << "Error in FT_SetTimeouts:" << ftStatus;
		return false;
	}
	if ((ftStatus = FT_SetBaudRate(ftHandle, 9600)) != FT_OK) {
		cout << "Error in FT_SetBaudRate:" << ftStatus;
		return false;
	}
	if ((ftStatus = FT_SetDataCharacteristics(ftHandle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_NONE)) != FT_OK) {
		cout << "Error in FT_SetDataCharacteristics:" << ftStatus;
		return false;
	}
	cout << "FTDI device with description" << " FT230X Basic UART " << "opened and configured";

	return true;
}

bool closePort(void)
{
	FT_STATUS ftStatus;

	if ((ftStatus = FT_Close(ftHandle)) != FT_OK) {
		cout << "VCSEL: Failed to close port";
		return false;
	}
	cout << "VCSEL: Port closed.";

	return true;
}