/*
 * Logger
 * Copyright (c) 2018 - 2020 Ivan Kmeťo
 *
 * Licensed under the MIT License.
 * http://opensource.org/licenses/mit-license
 */

#include <string>
#include <fstream>

#include "Logger.h"


std::fstream filehandle{};

void Logger(std::string func, std::string file, int line) {
	std::string code = "Logging: Func: " + func + " in file: " + file;
	code += " on line " + std::to_string(line) + "\n";;

	std::cout << code;

	Log_Write(code);
}

bool Log_Open(std::string filename) {
	if (!filehandle.is_open()) {
		filehandle.open(filename.c_str(), std::ios_base::app | std::ios::out);

		_wsetlocale(LC_ALL, L"");
		std::ios_base::sync_with_stdio(false);
		filehandle.imbue(std::locale(""));

		return true;
	}
	return false;
}

bool Log_Close() {
	if (filehandle.is_open()) {
		filehandle.close();
		return true;
	}
	return false;
}

void Log_Write(std::string text) {
	if (filehandle.is_open()) {
		filehandle << text << "\n";
	}
}

void Log_Init(std::string filename) {
	if (!filehandle.is_open()) {
		filehandle.open(filename.c_str(), std::ios::out | std::ios::trunc);
		filehandle << "Debug Log\n--------------\n";
		filehandle.close();
	}
	filehandle << "Debug Log\n--------------\n";
	filehandle.close();
}

void Log_End(std::string filename) {
	if (!filehandle.is_open()) {
		filehandle.open(filename.c_str(), std::ios_base::app | std::ios::out);
		filehandle << "\nEND";
		filehandle.close();
	}
	filehandle << "\nEND";
	filehandle.close();
}

void Log_WriteIn(std::string text, std::string filename) {
	if (!filehandle.is_open()) {
		filehandle.open(filename.c_str(), std::ios_base::app | std::ios::out);
		filehandle << text << "\n";
		filehandle.close();
	}
	filehandle << text << "\n";
	filehandle.close();
}
