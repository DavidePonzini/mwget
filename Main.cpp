#include "Header.h"


Error errors;
List fileList;

int main(int ArgC, char** ArgV)
{
	if(ArgC == 1)
	{
		cerr << usage;
		return 200;
	}

	// Get file content
	for(int i=1; i < ArgC; i++)
	{
		string line;
		bool stop = false;

		ifstream InFile;
		InFile.open(ArgV[i]);

		if(!InFile)
		{
			errors.AddError(err_open, ArgV[i], -1);
			stop = true;
		}

		while(!stop)
		{
			FileInfo newFile;

			if(!getline(InFile, line))
			{
				stop = true;
				break;
			}
			newFile.Name = line;

			if(!getline(InFile, line))
			{
				stop = true;
				break;
			}
			newFile.Url = line;

			fileList.Add(newFile);
		}

		InFile.close();
	}

	// Start downloading
	Clear();

	unsigned int totalElements = fileList.GetElemCount();
	FileInfo file;
	int ExitValue;

	while(fileList.GetElemCount() > 0)
	{
		// Clear screen
		Clear();

		// Get next file to download
		file = fileList.GetNext();

		// Print Status
		printf(status.c_str(), file.Name.c_str(), totalElements, fileList.GetElemCount(), errors.Count, errors.Message.c_str());

		// Download
		ExitValue = Download(file.Name, file.Url);

		// Handle exit value
		switch(ExitValue)
		{
		case 0:
			break;
		case 1:
			errors.AddError(err_code1, file.Name, ExitValue);
			break;
		case 2: // Ctrl + C
/*			errors.AddError(err_code2, file.Name, ExitValue);
			break;
*/			return 2;
		case 3:
			errors.AddError(err_code3, file.Name, ExitValue);
			break;
		case 4:
			errors.AddError(err_code4, file.Name, ExitValue);
			break;
		case 5:
			errors.AddError(err_code5, file.Name, ExitValue);
			break;
		case 6:
			errors.AddError(err_code6, file.Name, ExitValue);
			break;
		case 7:
			errors.AddError(err_code7, file.Name, ExitValue);
			break;
		case 8:
			errors.AddError(err_code8, file.Name, ExitValue);
		case 256:
			errors.AddError(err_code256, file.Name, ExitValue);
			break;
		case 1024:
			errors.AddError(err_code1024, file.Name, ExitValue);
			break;
		case 2048:
			errors.AddError(err_code2048, file.Name, ExitValue);
			break;
		default:
			errors.AddError(err_unknown, file.Name, ExitValue);
		}
	}

	return 0;
}
