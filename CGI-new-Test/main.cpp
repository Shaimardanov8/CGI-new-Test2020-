#include <iostream>
#include "cgi.h"
using namespace std;

void main()
{
	cout << "Content-type: text/html; charset=Winows-1251\n\n";
	cout << "<form action='cgi.cgi' method='get'>";
	cout << "���: <input type='text' name='fn'><br>";
	cout << "�������: <input type='text' name='ln'><br>";
	cout << "<input type='submit' value='���������'>";
	cout << "</form>";
	char* data = nullptr;
	get_form_data(data);
	cout << data;	
}