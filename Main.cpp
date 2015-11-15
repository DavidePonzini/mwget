#include "Header.h"


Error errors;
List fileList;

int main(int ArgC, char** ArgV)
{
	if(ArgC == 1)
	{
		cout << usage;
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
	printf(status.c_str(), fileList.GetElemCount(), totalElements, errors.Count, errors.Message.c_str());

	while(fileList.GetElemCount() > 0)
	{
		FileInfo file = fileList.GetNext();

		int exit_val = Download(file.Name, file.Url);

		// Clear screen
		Clear();

		// Handle exit value
		switch(exit_val)
		{
		case 0:
			break;
		case 1:
			errors.AddError(err_code1, file.Name, exit_val);
			break;
		case 2:
			errors.AddError(err_code2, file.Name, exit_val);
			break;
		case 3:
			errors.AddError(err_code3, file.Name, exit_val);
			break;
		case 4:
			errors.AddError(err_code4, file.Name, exit_val);
			break;
		case 5:
			errors.AddError(err_code5, file.Name, exit_val);
			break;
		case 6:
			errors.AddError(err_code6, file.Name, exit_val);
			break;
		case 7:
			errors.AddError(err_code7, file.Name, exit_val);
			break;
		case 8:
			errors.AddError(err_code8, file.Name, exit_val);
		case 256:
			errors.AddError(err_code256, file.Name, exit_val);
			break;
		case 1024:
			errors.AddError(err_code1024, file.Name, exit_val);
			break;
		case 2048:
			errors.AddError(err_code2048, file.Name, exit_val);
			break;
		default:
			errors.AddError(err_unknown, file.Name, exit_val);
		}

		printf(status.c_str(), totalElements, fileList.GetElemCount(), errors.Count, errors.Message.c_str());
	}

	return 0;
}
