#include <string>


using namespace std;


string usage =
		"Usage:\n"
		"\t"	"mwget <file 1> [<file 2> ...]\n"
		"\n"
		"\t"	"Input files must have the following syntax:\n"
		"\t\t"		"file 1 name\n"
		"\t\t"		"file 1 url\n"
		"\t\t"		"file 2 name\n"
		"\t\t"		"file 2 url\n"
		"\t\t"		"..."
		"\n"
		"\n";

string status =
		"\n"
		"*********************************************\n"
		"\n"
		"Current file: %s\n"
		"\n"
		"Total"	" | Remaining"	" | Errors"	"\n"
		"%5u"	" | %-9u"	" | %-6u"	"\n"
		"\n"
		"Errors:\n"
		"%s\n"
		"*********************************************\n"
		"\n";

string err_open =		"Couldn't open file.                       File: ";
string err_unknown =	"Unknown error.                            File: ";
string err_code1 =		"Generic error.                            File: ";
string err_code2 =		"Operation cancelled.                      File: ";
string err_code3 =		"File I/O error.                           File: ";
string err_code4 =		"Network failure.                          File: ";
string err_code5 =		"SSL verification failure.                 File: ";
string err_code6 =		"Username/password authentication failure. File: ";
string err_code7 =		"Protocol errors.                          File: ";
string err_code8 =		"Server issued an error response.          File: ";
string err_code256 =	"Invalid host name.                        File: ";
string err_code1024 =	"Temporary failure in name resolution.     File: ";
string err_code2048 =	"403 - Forbidden.                          File: ";
