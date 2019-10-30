#include <string>
#include <iostream>

#pragma once

using namespace std;
using namespace System;

void MarshalString(String ^ s, string& os);
void MarshalString(String ^ s, wstring& os);

inline String^ AConvString(unsigned char *s);
int my_atoi(unsigned char *p, int len);
void Delay_ms(int milliseconds);
int countlines(char *filename);