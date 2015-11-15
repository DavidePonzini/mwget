#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>


using namespace std;


int Download(string, string);
void Clear();


struct Error {
	string Message;
	unsigned int Count;

	Error();
	void AddError(string, string, int);
};

struct FileInfo {
	string Name;
	string Url;
};

struct Cell {
	FileInfo Info;
	Cell* Next;

	Cell(FileInfo);
};

class List {
	Cell* Head;
	Cell* Tail;
	unsigned int NoElems;
public:
	List();
	void Add(FileInfo);
	FileInfo GetNext();
	unsigned int GetElemCount();
};


// Strings
extern string usage;
extern string status;
extern string err_open;
extern string err_unknown;
extern string err_code1;
extern string err_code2;
extern string err_code3;
extern string err_code4;
extern string err_code5;
extern string err_code6;
extern string err_code7;
extern string err_code8;
extern string err_code256;
extern string err_code1024;
extern string err_code2048;
