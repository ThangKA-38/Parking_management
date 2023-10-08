#include "User.h"
User::User() {
    this->name = '\0';
    this->day = 0;
    this->month = 0;
    this->year = 0;
}
 User :: User(string name, int day, int month, int year) {
	 this->name = name;
	 this->day = day;
	 this->month = month;
	 this->year = year;
 }
 string User::getName() {
	 return this->name;
 }
 int User::getDay() {
	 return this->day;
 }
 int User::getMonth() {
	 return this->month;
 }
 int User::getYear() {
	 return this->year;
 }
 void User::setName(string name) {
	 this->name = name;
 };
 void User::setDay(int day) {
	 this->day = day;
 }
 void User::setMonth(int month) {
	 this->month = month;
 }
 void User::setYear(int year) {
	 this->year = year;
 }
 //------chỉnh sủa ngày-------
 bool checkYear_User(int year)
 {
     if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
     return false;
 }
 int checkDay_User(int month, int year)
 {


     switch (month)
     {
         // các tháng 31 ngày
     case 1: case 3: case 5: case 7:case 8:case 10: case 12:
         return  31;
         break;
         // các tháng 30 ngày
     case 4: case 6:case 9: case 11:
         return  30;
         break;
     case 2:
         if (checkYear_User(year)) return 29;
         else return 28;
         break;
     }


 }
 bool check_User(int day, int month, int year)
 {
     if (day < 1 || day > checkDay_User(month, year)) return false;
     if (month < 1 || month > 12) return false;
     if (year < 1000) return false;
     return true;
 }
 void fix_time_User(int number) {  // nếu nhập khác kiể integer sẽ báo sai

     cout << "\t\t [Khong Hop le]" << endl;
     cin.clear();
     cin.ignore(250, '\n');
 }
 // ------chỉnh sửa tên người dùng-------
 void deleteSpace_User(char str[], int position) {
     int length = strlen(str);
     for (int i = position; i < length; i++) {
         str[i] = str[i + 1];
     }
     str[length - 1] = '\0';
 }
 void delete_spaceHead_User(char str[]) {
     int i = 0;
     while (true) {
         if (str[i] == ' ') deleteSpace_User(str, i);
         else break;
     }
 }

 void delete_spaceEnd_User(char str[]) {
     while (true) {
         if (str[strlen(str) - 1] == ' ') deleteSpace_User(str, strlen(str) - 1);
         else break;
     }
 }

 void delete_spaceMid_User(char str[]) {
     int i, j;
     int len = strlen(str);
     for (i = 0; i < len; i++)
     {
         if (str[i] == ' ' && str[i + 1] == ' ')
         {
             for (j = i + 1; j < len; j++)
             {
                 str[j] = str[j + 1];
             }
             i--;
             len--;
         }
     }
 }

 string copyString_User (char* str, int length) {
     string s = "";
     for (int i = 0; i < length; i++) {
         s = s + str[i];
     }
     return s;
 }

 string spaceOfName_User(string& name) {
     char str[100];
     int length;
     length = name.copy(str, name.size());
     str[length] = '\0';
     delete_spaceHead_User(str);
     delete_spaceMid_User(str);
     delete_spaceEnd_User(str);
     name = copyString_User(str, strlen(str));
     return name;

 }
 string formatName(string& name) {
     string result = "";
     for (int i = 0; i < name.size(); i++)if (name[i] >= 'A' && name[i] <= 'Z')
     {
         name[i] += 32;
     }
     int i = 0;
     while (name[i] == ' ')i++;
     if (name[i] >= 'a' && name[i] <= 'z')name[i] -= 32;
     for (i; i < name.size(); i++)
     {
         if (name[i] == ' ')
         {
             while (name[i + 1] == ' ')i++;
             if (name[i + 1] >= 'a' && name[i + 1] <= 'z')
                 name[i + 1] -= 32;
         }
         result += name[i];
     }
     if (result[result.size() - 1] == ' ')result.pop_back();
     return result;
 }

 // -------nhập xuất--------
 void User::AddName() {
     cout << "\t\tNhap ten nguoi lam ca nay   :";
     do {
         getline(cin, this->name);
     } while (this->name.length() == 0);
     spaceOfName_User(this->name);
     formatName(this->name);
     do {
         // --ngày--
         cout << "\t\t Nhap ngay :"; cin >> this->day;
         while (cin.fail()) {
             fix_time_User(this->day);
             cout << "\t\t Nhap ngay :"; cin >> this->day;
         }
         //----tháng----
         cout << "\t\t Nhap thang :";  cin >> this->month;
         while (cin.fail()) {
             fix_time_User(this->month);
             cout << "\t\t Nhap thang :";  cin >> this->month;
         }
         // ----năm----
         cout << "\t\t Nhap nam :"; cin >> this->year;
         while (cin.fail()) {
             fix_time_User(this->year);
             cout << "\t\t Nhap nam :"; cin >> this->year;
         }
         if (!check_User(this->day, this->month, this->year)) {
             cout << "\t\tThoi gian khong hop le!" << endl;
         }
     } while (!check_User(this->day, this->month, this->year));



 }

 void User::displayName() {
     cout << " | " << setw(20) << left << this->name
          << " | " << setw(2) << left << this->day 
          << "/" << setw(2) << left << this->month 
          << "/" << setw(4) << left << this->year << " | " << endl;
 }


