#include "Header.h"


Cell::Cell(FileInfo file)
{
	Info = file;
	Next = NULL;
}


List::List()
{
	Head = NULL;
	Tail = NULL;
	NoElems = 0;
}

void List::Add(FileInfo file)
{
	if(!Head)
	{
		Head = new Cell(file);
		Tail = Head;
	}
	else
	{
		Tail->Next = new Cell(file);
		Tail = Tail->Next;
	}

	NoElems++;
}

FileInfo List::GetNext()
{
	if(!Head)
	{
		FileInfo dummy;
		return dummy;
	}

	Cell* tmp = Head;
	Head = Head->Next;
	if(!Head)	// Head is now pointing to NULL, meaning there are no more elements
		Tail = NULL;

	FileInfo val = tmp->Info;

	delete tmp;
	NoElems--;

	return val;
}

unsigned int List::GetElemCount()
{
	return NoElems;
}
