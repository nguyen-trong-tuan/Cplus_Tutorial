#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>

using namespace std;

char str_buff[50];
string str;
char * p_str;
uint16_t index = 0;
void push(char ch)
{
	str_buff[index] = ch;
	index++;
	if (index >= sizeof(str_buff))
	{
		cout << "string buffer overflow" << endl;
	}
}
void rst_str_buff(void)
{
	memset(str_buff, '\0', strlen(str_buff));
	index = 0;
}
void clear_front_back(string str)
{
	int index = 0;
	
	while (str.back() == ' ')
	{
		str.pop_back();
	}
	int length = (int)str.length();
	while (str[index] == ' ')
	{
		index++;
	}
	for (int i = index; i < length; i++)
	{
		if ((str[i] == ' ') && (str[i - 1] == ' '))
		{
			continue;
		}
		else
		{
			push((char)(str[i]));
		}
	}
}
void repair(void)
{
	int i = 0;
	int length = (int)strlen(str_buff);
	for (i = 1; i < length; i++)
	{
		if (str_buff[i-1] == ' ')
		{
			str_buff[i] = toupper((int)(str_buff[i]));
		}
		else
		{
			str_buff[i] = tolower((int)(str_buff[i]));
		}
	}
	str_buff[0] = toupper(str_buff[0]);
}
int main()
{
	while (1)
	{
		rst_str_buff();
		cout << "nhap vao day mot chuoi" << endl;
		getline(cin, str);
		clear_front_back(str);
		repair();
		cout << str_buff << endl;
		
	}
}