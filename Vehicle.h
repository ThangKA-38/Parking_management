#pragma once
#include<iostream>
#include <iomanip>
#include<string>
using namespace std;

class Vehicle {
protected:
	string bienso;
	int day, month, year;
public:
	Vehicle();
	Vehicle(string bienso, int day, int month, int year);
	virtual void input();    // thêm xe;
	virtual void display();   // sửa thông tin 

	//------------
	string getBienso();
	int getDay();
	int getMonth();
	int getYear();

	void setbienso(string bienso);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
};

//------chỉnh sửa ngày tháng--------
bool checkYear(int year);   // ktr năm nhuận

int checkDay(int month, int year);

bool check(int day, int month, int year);
void make(int number);

//--------chỉnh biển số--------

void deleteSpace(char str[], int position);  // xóa khoảng cách

void delete_spaceHead(char str[]); // xóa đầu

void delete_spaceEnd(char str[]); // xóa cuối

void delete_spaceMid(char str[]); // xóa giữa

string copyString(char* str, int length); // copy 

string spaceOfName(string& name); // tổng hợp

void inhoa(string& str);

