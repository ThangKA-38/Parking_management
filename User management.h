#pragma once
#include"User.h"
#include<vector>
#include<fstream>
class User_Management
{
private:
	vector<User*>listPerson;
public:
	User_Management();
	void Add();
	void Print();
	void Remove();
	void Replace();
	//-----file-------
	void writePerson();
	void readPerson();
};

void enter_vitri_User(int vitri, int length);