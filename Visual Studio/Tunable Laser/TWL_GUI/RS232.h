#include "stdafx.h"
#define STRICT
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "ITLA.h"

void RS232SetBuffer(unsigned char* buffer,int count,int port);
void RS232Send(int port);
BOOL RS232IsReceived(int count,int port);
unsigned char* RS232ReadBuffer(unsigned char* buffer, int count, int port);
//int RS232InitPort(LPCSTR portid,int brate);
int RS232InitPort(int comport_number, int brate);
int RS232EndReceived(unsigned char temp,int port);

