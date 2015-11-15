#include "Header.h"

Error::Error()
{
	Count = 0;
}

void Error::AddError(string baseMessage, string myMessage, int exitVal)
{
	if(baseMessage == err_unknown)
	{
		Message += '\t' + to_string(exitVal) + " - " + baseMessage + "\"" + myMessage + "\"\n";
	}
	else
	{
		Message += '\t' + baseMessage + "\"" + myMessage + "\"\n";
	}
	Count++;
}
