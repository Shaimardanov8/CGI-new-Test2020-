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
	char* dec_data;
	str_decode(dec_data, data);
	cout << data << "<br>";
	cout << dec_data << "<br>";
	char* val;
	get_param_value(val, "fn", data);
	cout << "���: " << val << "<br>";
	delete[] val;
	get_param_value(val, "ln", data);
	cout << "�������: " << val << "<br>";
	delete[] val;
	
	delete[] data;
	delete[] dec_data;
}