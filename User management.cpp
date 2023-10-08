#include "User management.h"

User_Management::User_Management() {

}
//----------dungf file---------
void User_Management::writePerson() {
	fstream wri; //ghi file 
	wri.open("\DataPerson.txt", fstream::out);
	wri << listPerson.size() << ",";
	for (int i = 0; i < listPerson.size(); i++) {
		wri << listPerson[i]->getName() << ","
			<< listPerson[i]->getDay() << ","
			<< listPerson[i]->getMonth() << ","
			<< listPerson[i]->getYear() << "\n";
	}
	wri.close();
}

void User_Management::readPerson() {
	fstream re("DataPerson.txt", ios::in);
	User* temp;
	int  i = 0;;
	string length, nameT, dayT, monthT, yearT;
	getline(re, length, ',');
	int templength = stoi(length);
	while (i < templength) {
		getline(re, nameT, ',');
		getline(re, dayT, ',');
		getline(re, monthT, ',');
		getline(re, yearT, '\n');

		int tempday = stoi(dayT);  // stoi() hàm chuyển từ string qua int
		int tempmonth = stoi(monthT);
		int tempyear = stoi(yearT);
		temp = new User(nameT, tempday, tempmonth, tempyear);

		listPerson.push_back(temp);
		i++;
	}

	re.close();
}

void enter_vitri_User(int vitri, int length) {
	while (cin.fail()) {  //dùng để kiểm tra nếu có ký tự char nào thì nó sẽ báo không nhập được.
		cout << "\t\t [Khong hop le]" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\t\tNhap vi tri can xoa  : ";
		do {
			cin >> vitri;
			if (vitri < 0 || vitri >length) {
				cout << "\t\t nhap lai  : ";
			}
		} while (vitri < 0 || vitri >length);
	}

}
//---------các chức năng--------
void User_Management::Add() {
	User* temp  = new User();
	cout << "\t\t--------------------------------------------" << endl;

	temp->AddName();
	listPerson.push_back(temp);
	cout << "\n\t\t--------------------------------------" << endl;
	cout << "\t\t         THEM THANH CONG     " << endl;
	cout << "\n\t\t--------------------------------------" << endl;
	writePerson();
}
//
void User_Management :: Print() {
	listPerson.clear();
	readPerson();
	cout << "\t\t-------------------Lich su dang nhap-------------------" << endl;

	cout << "\t\t| " << setw(6) << left << "Thu tu"
		<< " | " << setw(20) << left << "Ten nguoi lam"
		<< " | " << setw(10) << left << "Thoi gian" << " | " << endl;
	cout << "\t\t_____________________________________________" << endl;
	for (int i = 0; i < listPerson.size(); i++) {
		cout << "\t\t| " << setw(6) << left << i + 1;
		listPerson[i]->displayName();
	cout << "\t\t---------------------------------------------" << endl;
	}
}
//
void User_Management::Remove() {
	int vitri;
	cout << "\t\tNhap vi tri can xoa  : ";
	do {
		cin >> vitri;
		if (vitri < 0 || vitri >listPerson.size()) {
			cout << "\t\t nhap lai  : ";
		}
	} while (vitri < 0 || vitri >listPerson.size());

	enter_vitri_User(vitri, listPerson.size());// khi nhập kí tự sẽ báo sai

	for (int i = 0; i < listPerson.size(); i++) {
		if (i == (vitri - 1)) {
			listPerson.erase(listPerson.begin() + i);
		}
	}
	cout << "\n\t\t XOA THANH CONG !" << endl;
	writePerson();
}
//
void User_Management::Replace() {
	User* temp = new User;
	int vitri;
	cout << "\t\tNhap vi tri can thay the  : ";
	cin >> vitri;
	while (cin.fail()) {  //dùng để kiểm tra nếu có ký tự char nào thì nó sẽ báo không nhập được.
		cout << "\t\t [Khong hop le]" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\t\tNhap vi tri can thay the  : ";
		cin >> vitri;
	}
	if (vitri < 0 || vitri > listPerson.size()) {
		cout << " \t\t Khong Co vi tri nay !";
	}
	else {
		temp->AddName();
		listPerson.emplace(listPerson.begin() + (vitri - 1), temp);
		listPerson.erase(listPerson.begin() + vitri);
		cout << "\t\tTHAY THE THANH CONG ! " << endl;
	}
	
	writePerson();
}