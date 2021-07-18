#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>
#include <cstdlib>

using namespace std;

string str_buff;
string str;
char * p_str;
uint16_t index = 0;

void push(char ch)
{
	str_buff.push_back(ch);//cho nay khong duoc dung lenh str_buff.at(index) = ch; boi vi ta khong biet str_buff co do lon la bao nhieu phan tu, ham memset ko lam dieu nay
	//ham memset o ben duoi chi xoa di 40 o nho bat dau tu dia chi dau tien chu ko phai la cap phat 40 o nho cho string, ngoai ra, ta co the dung phuong thuc insert cung duoc
	index++;
	if (index >= sizeof(str_buff))
	{
		cout << "string buffer overflow" << endl;
	}
}
void rst_str_buff(void)
{
	memset(&str_buff, '\0', 40);
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
	while (str.at(index) == ' ')
	{
		index++;
	}
	for (int i = index; i < length; i++)
	{
		if ((str.at(i) == ' ') && (str.at(i-1) == ' '))
		{
			continue;
		}
		else
		{
			push((char)(str.at(i)));
		}
	}
}
void repair(void)
{
	int i = 0;
	int length = (int)(str_buff.length());
	for (i = 1; i < length; i++)
	{
		if (str_buff.at(i-1) == ' ')
		{
			str_buff.at(i) = toupper((int)(str_buff.at(i)));
		}
		else
		{
			str_buff.at(i) = tolower((int)(str_buff.at(i)));
		}
	}
	str_buff.at(0) = toupper(str_buff.at(0));
}
int main()
{
//	cin >> str_buff.at(2);
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