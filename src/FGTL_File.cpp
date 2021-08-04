/*
 * AUTHORS : <jonathanmarpaung88@gmail.com>
 * VERSION : 1.0.0
 * TYPE    : Script
 * LICENSE : MIT
 */
/* Include header C++ */
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstring>

/* Include header SDL2 */
#include <SDL2/SDL.h>

/* Include header */
#include "FGTL_File.h"

/*
 * @parameter { const char* { Path } }
 * This function used for get all
 * list file, (Filter file or directory)
 */
char* FGTL_Get_List_File(const char* path) \
{
	/* Create variable for 
	 * save all name file on 
	 * this variable 
	 */
	std::vector<std::string> ListOfFile;
	std::vector<std::string> tempListOfFile;

	/* This variable is used for 
	 * setup where's target for get 
	 * list file 
	 */
	std::filesystem::path Path(path);

	/* Check the folder is exist */
	if(!std::filesystem::exists(Path)) \
	{
		/* If folder is not exist 
		 * Print error message into
		 * console
		 */
		fprintf(stderr, \
			"[FGTL {Error}]: `Can't find : %s`\n", path);
		exit(1);
	}

	/* Check the path is folder */
	if(!std::filesystem::is_directory(Path)) \
	{
		/* If Path is not Folder 
		 * Print error message into
		 * console
		 */
		fprintf(stderr, \
			"[FGTL {Error}]: `Path Is Not Folder : %s`\n", path);
		exit(1);
	}

	/* If all has been checked 
	 * Get all list of directory
	 */
	for (auto& list : \
		std::filesystem::directory_iterator(((std::string)path))) \
	{
		/* Create variable temp 
		 * and filled from convert 
		 * into string 
		 */
		std::string tempList;
		std::string tempList2 = list.path().u8string();

		if(tempList2.empty()) \
		{
			/* The real name of file */
			tempListOfFile.push_back(tempList2);
			
			/* Remove './' */
			for(unsigned int index = 2; index < tempList2.length(); index++) \
			{
				tempList += tempList2[index];
			}
			
			/* If the last letter is not '/' */
			/* First create variable for temp path */
			std::string tempPath = path;
			if(tempPath[tempPath.length() - 1] != '/') \
			{
				/* Adding Character '/' */
				tempPath += "/";
			}

			/* This variable used for check is file or directory, 
			 * this used by combining tempList with path 
			 */
			std::string combining = tempPath + tempList;


			/* This variable is used for 
			 * For check it's directory 
			 * or file 
			 */
			std::filesystem::path isFile(combining.c_str());


			/* Check if is file and 
			 * push if this list is file 
			 */
			if(!std::filesystem::is_directory(isFile)) \
			{
				/* If this list is file
				 * push into vector 
				 */
				ListOfFile.push_back(tempList);
			}
		}
	}

	/* Create output variable 
	 * in type char* 
	 */
	char* output;

	/* Check if file of array it's not empty */
	if(ListOfFile.size() != 0) \
	{
		/* Create variable for 
		 * filled data list of name file 
		 */
		std::string listFile;
		
		/* Load name of file in ListOfFile */
		for(unsigned int index = 0; index < ListOfFile.size(); index++) \
		{
			/* Add name file with space */
			if(index == (ListOfFile.size() - 1)) \
			{
				listFile += tempListOfFile[index];
			} else \
			{
				listFile += tempListOfFile[index] + " ";
			}
		}

		/* Convert std::string into char*
		 * for return data from this function 
		 */
		char* output = (char*)malloc(listFile.length() - 1);
		memcpy(output, listFile.c_str(), listFile.length());
	} else \
	{
		/* If array of vector is empty 
		 * make char is have 1 byte is empty
		 */
		const char* empty = "";
		output = (char*)malloc(1);
		strcpy(output, empty);
	}


	/* Return the data after convert */
	return output;
}

/*
 * @parameter { const char* { Path } }
 * This function used for get all
 * list file, (Filter file or directory)
 * with check the extension
 */
char* FGTL_Get_List_File_Extension(const char* path, 
	const char* extension) \
{
	/* Create variable for 
	 * save all name file on 
	 * this variable 
	 */
	std::vector<std::string> ListOfFile;
	std::vector<std::string> tempListOfFile;

	/* This variable is used for 
	 * setup where's target for get 
	 * list file 
	 */
	std::filesystem::path Path(path);

	/* Check the folder is exist */
	if(!std::filesystem::exists(Path)) \
	{
		/* If folder is not exist 
		 * Print error message into
		 * console
		 */
		fprintf(stderr, \
			"[FGTL {Error}]: `Can't find : %s`\n", path);
		exit(1);
	}

	/* Check the path is folder */
	if(!std::filesystem::is_directory(Path)) \
	{
		/* If Path is not Folder 
		 * Print error message into
		 * console
		 */
		fprintf(stderr, \
			"[FGTL {Error}]: `Path Is Not Folder : %s`\n", path);
		exit(1);
	}

	/* If all has been checked 
	 * Get all list of directory
	 */
	for (auto& list : \
		std::filesystem::directory_iterator(((std::string)path))) \
	{
		/* Create variable temp 
		 * and filled from convert 
		 * into string 
		 */
		std::string tempList;
		std::string tempList2 = list.path().u8string();

		/* Check if extension it's 
		 * same as parameter extension 
		 */
		if((std::string)list.path().extension() \
			== (std::string)extension && \
			!tempList2.empty()) \
		{
			/* The real name of file */
			tempListOfFile.push_back(tempList2);
			
			/* Remove './' */
			for(unsigned int index = 2; index < tempList2.length(); index++) \
			{
				tempList += tempList2[index];
			}
			
			/* If the last letter is not '/' */
			/* First create variable for temp path */
			std::string tempPath = path;
			if(tempPath[tempPath.length() - 1] != '/') \
			{
				/* Adding Character '/' */
				tempPath += "/";
			}

			/* This variable used for check is file or directory, 
			 * this used by combining tempList with path 
			 */
			std::string combining = tempPath + tempList;


			/* This variable is used for 
			 * For check it's directory 
			 * or file 
			 */
			std::filesystem::path isFile(combining.c_str());


			/* Check if is file and 
			 * push if this list is file 
			 */
			if(!std::filesystem::is_directory(isFile)) \
			{
				/* If this list is file
				 * push into vector 
				 */
				ListOfFile.push_back(tempList);
			}
		}
	}

	/* Create output variable 
	 * in type char* 
	 */
	char* output;

	/* Check if file of array it's not empty */
	if(ListOfFile.size() != 0) \
	{
		/* Create variable for 
		 * filled data list of name file 
		 */
		std::string listFile;
		
		/* Load name of file in ListOfFile */
		for(unsigned int index = 0; index < ListOfFile.size(); index++) \
		{
			/* Add name file with space */
			if(index == (ListOfFile.size() - 1)) \
			{
				listFile += tempListOfFile[index];
			} else \
			{
				listFile += tempListOfFile[index] + " ";
			}
		}

		/* Convert std::string into char*
		 * for return data from this function 
		 */
		output = (char*)malloc(listFile.length() - 1);
		memcpy(output, listFile.c_str(), listFile.length());
	} else \
	{
		/* If array of vector is empty 
		 * make char is have 1 byte is empty
		 */
		const char* empty = "";
		output = (char*)malloc(1);
		strcpy(output, empty);
	}

	/* Return the data after convert */
	return output;
}

/*
 * @parameter { const char* { Path } }
 * This function used for get all
 * list folder, (Filter folder or file)
 */
char* FGTL_Get_List_Folder(const char* path) \
{
	/* Create variable for 
	 * save all name folder on 
	 * this variable 
	 */
	std::vector<std::string> ListOfFolder;
	std::vector<std::string> tempListOfFolder;

	/* This variable is used for 
	 * setup where's target for get 
	 * list folder 
	 */
	std::filesystem::path Path(path);

	/* Check the folder is exist */
	if(!std::filesystem::exists(Path)) \
	{
		/* If folder is not exist 
		 * Print error message into
		 * console
		 */
		fprintf(stderr, \
			"[FGTL {Error}]: `Can't find : %s`\n", path);
		exit(1);
	}

	/* Check the path is folder */
	if(!std::filesystem::is_directory(Path)) \
	{
		/* If Path is not Folder 
		 * Print error message into
		 * console
		 */
		fprintf(stderr, \
			"[FGTL {Error}]: `Path Is Not Folder : %s`\n", path);
		exit(1);
	}

	/* If all has been checked 
	 * Get all list of directory
	 */
	for (auto& list : \
		std::filesystem::directory_iterator(((std::string)path))) \
	{
		/* Create variable temp 
		 * and filled from convert 
		 * into string 
		 */
		std::string tempList;
		std::string tempList2 = list.path().u8string();

		/* Check if tempList2 is empty */
		if(tempList2.empty()) \
		{
			/* The real name of folder */
			tempListOfFolder.push_back(tempList2);
			
			/* Remove './' */
			for(unsigned int index = 2; index < tempList2.length(); index++) \
			{
				tempList += tempList2[index];
			}
			
			/* If the last letter is not '/' */
			/* First create variable for temp path */
			std::string tempPath = path;
			if(tempPath[tempPath.length() - 1] != '/') \
			{
				/* Adding Character '/' */
				tempPath += "/";
			}

			/* This variable used for check is folder or file, 
			 * this used by combining tempList with path 
			 */
			std::string combining = tempPath + tempList;


			/* This variable is used for 
			 * For check it's directory 
			 * or file 
			 */
			std::filesystem::path isFolder(combining.c_str());


			/* Check if is file and 
			 * push if this list is folder 
			 */
			if(std::filesystem::is_directory(isFolder)) \
			{
				/* If this list is folder
				 * push into vector 
				 */
				ListOfFolder.push_back(tempList);
			}
		}
	}

	/* Create output variable 
	 * in type char* 
	 */
	char* output;

	/* Check if file of array it's not empty */
	if(ListOfFolder.size() != 0) \
	{
		std::string tempDirectory;

		for(int i = 0; i < ListOfFolder.size(); i++) \
		{
			if(i == ListOfFolder.size() - 1) \
			{
				tempDirectory += tempListOfFolder[i];
			} else \
			{
				tempDirectory += tempListOfFolder[i] + " ";
			}
		}

		output = new char[tempDirectory.length() + 1];
		strcpy(output, tempDirectory.c_str());
	} else \
	{
		/* If array of vector is empty 
		 * make char is have 1 byte is empty
		 */
		const char* empty = "";
		output = (char*)malloc(1);
		strcpy(output, empty);
	}

	/* Return the data after convert */
	return output;
}

/*
 * @parameter { const char* { Path } }
 * This function used for get all
 * content in directory
 */
char* FGTL_Get_List(const char* path) \
{
	/* Create variable for 
	 * save all name folder on 
	 * this variable 
	 */
	std::vector<std::string> tempListContent;

	/* This variable is used for 
	 * setup where's target for get 
	 * list folder 
	 */
	std::filesystem::path Path(path);

	/* Check the folder is exist */
	if(!std::filesystem::exists(Path)) \
	{
		/* If folder is not exist 
		 * Print error message into
		 * console
		 */
		fprintf(stderr, \
			"[FGTL {Error}]: `Can't find : %s`\n", path);
		exit(1);
	}

	/* Check the path is folder */
	if(!std::filesystem::is_directory(Path)) \
	{
		/* If Path is not Folder 
		 * Print error message into
		 * console
		 */
		fprintf(stderr, \
			"[FGTL {Error}]: `Path Is Not Folder : %s`\n", path);
		exit(1);
	}

	/* If all has been checked 
	 * Get all list of directory
	 */
	for (auto& list : \
		std::filesystem::directory_iterator(((std::string)path))) \
	{
		/* Create variable temp 
		 * and filled from convert 
		 * into string 
		 */
		std::string tempList2 = list.path().u8string();

		/* Check if tempList2 is empty */
		if(tempList2.empty()) \
		{
			/* Push into tempListContent */
			tempListContent.push_back(tempList2);
		}
	}

	/* Create output variable 
	 * in type char* 
	 */
	char* output;

	/* Check if file of array it's not empty */
	if(tempListContent.size() != 0) \
	{
		std::string tempDirectory;

		for(int i = 0; i < tempListContent.size(); i++) \
		{
			if(i == tempListContent.size() - 1) \
			{
				tempDirectory += tempListContent[i];
			} else \
			{
				tempDirectory += tempListContent[i] + " ";
			}
		}

		output = new char[tempDirectory.length() + 1];
		strcpy(output, tempDirectory.c_str());
	} else \
	{
		/* If array of vector is empty 
		 * make char is have 1 byte is empty
		 */
		const char* empty = "";
		output = (char*)malloc(1);
		strcpy(output, empty);
	}

	/* Return the data after convert */
	return output;
}

/*
 * @parameter { const char* { Path / Or File } }
 * This function used for check the parameter
 * it's folder or file (if folder true) |
 * (if file false)
 */
int FGTL_Its_Folder(const char* path_or_file) \
{
	/* This variable is used for
	 * return the result
	 */
	int result = 0;

	/* This variable is used for 
	 * setup where's target for get 
	 * for check
	 */
	std::filesystem::path Path(path_or_file);

	/* Check it's exist */
	if(!std::filesystem::exists(Path)) \
	{
		/* If it's not exist 
		 * Print error message into
		 * console
		 */
		fprintf(stderr, \
			"[FGTL {Error}]: `Can't find : %s`\n", path_or_file);
		exit(1);
	}

	/* Check the path is folder */
	if(std::filesystem::is_directory(Path)) \
	{
		/* If Path is Folder
		 * change result into true
		 * or in number is 1
		 */
		result = 1;

	}

	/* Return the variable result */
	return result;
}

/*
 * @parameter { const char* { Path / Or File } }
 * This function used for check exist file
 * or directory
 */
int FGTL_Exist_Content(const char* path_or_file) \
{
	/* This variable is used for
	 * return the result
	 */
	int result = 0;

	/* This variable is used for 
	 * setup where's target for get 
	 * for check
	 */
	std::filesystem::path Path(path_or_file);

	/* Check it's exist */
	if(std::filesystem::exists(Path)) \
	{
		/* If content it's exist
		 * change result into true
		 * or in number is 1
		 */
		result = 1;
	}

	/* Return the variable result */
	return result;
}