#include <string>
#include <iostream>
#include "globalFunc.h"
#include <time.h>

using namespace std;
using namespace System;

void MarshalString(String ^ s, string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

void MarshalString(String ^ s, wstring& os) {
	using namespace Runtime::InteropServices;
	const wchar_t* chars =
		(const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

inline String^ AConvString(unsigned char *s)
{
	using namespace Runtime::InteropServices;
	return Marshal::PtrToStringAnsi(IntPtr((void *)s));
}

int my_atoi(unsigned char *p, int len) {
	int k = 0;
	for (int i = 0; i<len; i++) {
		k = (k << 3) + (k << 1) + (*p) - '0';
		p++;
	}
	return k;
}

void Delay_ms(int milliseconds) // cross-platform sleep function
{
	clock_t time_end;
	time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
	while (clock() < time_end)
	{
	}
}

int countlines(char *filename) {
	// count the number of lines in the file called filename                                    
	FILE *fp = fopen(filename, "r");
	int ch = 0;
	int lines = 0;

	if (fp == NULL) return 0;
	//char c;
	//for (c = getc(fp); c != EOF; c = getc(fp))
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (ch == '\n') lines++;
	}
	fclose(fp);
	return lines;
}