#include <iostream>
#include <iomanip>
#include <time.h>
#include "windows.h"

using namespace std;

int main()
{
	HANDLE book = CreateFile(L"book.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	LARGE_INTEGER size;
	GetFileSizeEx(book, &size);

	cout << "The book's size is: " << size.QuadPart << endl;

}