#include "Header.h"

int Download(string name, string url)
{
	string command = "wget -c -O '" + name + "' '" + url + "'";
	return system(command.c_str());
}

void Clear()
{
	system("clear");
}
