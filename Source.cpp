#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <iomanip>
#include <time.h>
#include "windows.h"
#include <map>

#define _CRT_SECURE_NO_WARNING
using namespace std;

int main()
{
	HANDLE book = CreateFile(L"book.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	LARGE_INTEGER size;
	GetFileSizeEx(book, &size);

	cout << "The book's size is: " << size.QuadPart << endl;

	DWORD bytesToRead;
	char* Text = new char[size.QuadPart + 1];
	ReadFile(book, Text, size.QuadPart, &bytesToRead, NULL);
	CloseHandle(book);

	map<string, size_t> words;
	char* word = strtok(Text, " .,-\n\t\r:;!?()"); 
	while (word != NULL)
	{
		words[word]++;
		word = strtok(NULL, " .,-\n\t\r:;!?()=\"");
	}

	map<int, string> result;

	for (auto it = words.begin(); it != words.end(); ++it)
	{
		result[(*it).second] = (*it).first;
	}

	for (auto iter = result.begin(); iter != result.end(); ++iter)
	{
		cout << (*iter).first << " : " << (*iter).second << endl;
	}

	return 0;


}