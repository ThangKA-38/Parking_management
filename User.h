#pragma once
#include<iostream>
#include <iomanip>
#include<string>
using namespace std;
class User
{
protected:
	string name;
	int day, month, year;
public:
	User();
	User(string name, int day, int month, int year);
	virtual void AddName();    // thêm xe;
	virtual void displayName();   // sửa thông tin 

	//------------
	string getName();
	int getDay();
	int getMonth();
	int getYear();

	void setName(string name);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

};
//------chỉnh sửa ngày tháng--------
bool checkYear_User(int year);   // ktr năm nhuận

int checkDay_User(int month, int year);

bool check_User(int day, int month, int year);
void fix_time(int number);
//--------chỉnh tên người dùng--------

void deleteSpace_User(char str[], int position);

void delete_spaceHead_User(char str[]);

void delete_spaceEnd_User(char str[]);

void delete_spaceMid_User(char str[]);

string copyString_User(char* str, int length);

string spaceOfName_User(string& name);

string  formatName (string& name);
