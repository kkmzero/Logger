/*
 * Abandoned implementation of basic C++ logging utility for MSVC projects.
 *
 * CC0 1.0 Universal (CC0 1.0) Public Domain Dedication
 * https://creativecommons.org/publicdomain/zero/1.0/
 */

#pragma once

#include <iostream>


void Logger(std::string func, std::string file, int line);

#define Error(x)\
	if (x) {\
	Logger(#x, __FILE__, __LINE__);\
}

bool Log_Open(std::string);
bool Log_Close();
void Log_Write(std::string);
void Log_Init(std::string);
void Log_End(std::string);
void Log_WriteIn(std::string text, std::string);
