#include "cgi.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_get()
{
	//REQUEST_METHOD
	size_t realsize;
	char* value = new char[5];
	getenv_s(&realsize, value, 5, "REQUEST_METHOD");
	bool res = !_strcmpi(value, "GET");
	delete[] value;
	return res;
}

size_t get_content_length()
{
	//CONTENT_LENGTH
	size_t realsize;
	char* value = new char[11];
	getenv_s(&realsize, value, 11, "CONTENT_LENGTH");
	size_t size;
	if (!realsize) size = 0;
	else sscanf_s(value, "%d", &size);
	delete[] value;
	return size;
}

void get_form_data(char*& data)
{
	if (data) delete[] data;
	if (is_get())
	{
		//QUERY_STRING
		size_t realsize;
		char* value = new char[65536];
		getenv_s(&realsize, value, 65536, "QUERY_STRING");
		data = new char[realsize+1];
		strcpy_s(data, realsize+1, value);
		delete[] value;
	} else
	{
		size_t bufSize = get_content_length();
		data = new char[bufSize + 1];
		fread_s(data, 
			bufSize+1, 
			sizeof(char), 
			bufSize, 
			stdin
		);
		data[bufSize] = 0;
	}
}





