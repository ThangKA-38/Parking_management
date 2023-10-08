#include"Vehicle.h"

Vehicle::Vehicle() {
    this->bienso = '\0';
    this->day = 0;
    this->month = 0;
    this->year = 0;
}
Vehicle::Vehicle(string bienso, int day, int month, int year) {
    this->bienso = bienso;
    this->day = day;
    this->month = month;
    this->year = year;
}
string Vehicle::getBienso() {
    return this->bienso;
}
int Vehicle::getDay() {
    return this->day;
}
int Vehicle::getMonth() {
    return this->month;
}
int Vehicle::getYear() {
    return this->year;
}
void Vehicle::setbienso(string bienso) {
    this->bienso = bienso;
};
void Vehicle::setDay(int day) {
    this->day = day;
}
void Vehicle::setMonth(int month) {
    this->month = month;
}
void Vehicle::setYear(int year) {
    this->year = year;
}
//------chỉnh sủa ngày-------
bool checkYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
    return false;
}
int checkDay(int month, int year)
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
        if (checkYear(year)) return 29;
        else return 28;
        break;
    }


}
bool check(int day, int month, int year)
{
    if (day < 1 || day > checkDay(month, year)) return false;
    if (month < 1 || month > 12) return false;
    if (year < 1000) return false;
    return true;
}
void fix_time(int number) {  // nếu nhập khác kiể integer sẽ báo sai
   
        cout << "\t\t [Khong Hop le]" << endl;
        cin.clear();
        cin.ignore(250, '\n');
}

// ------chỉnh sửa biển số-------
void deleteSpace(char str[], int position) {
    int length = strlen(str);
    for (int i = position; i < length; i++) {
        str[i] = str[i + 1];
    }
    str[length - 1] = '\0';
}
void delete_spaceHead(char str[]) {
    int i = 0;
    while (true) {
        if (str[i] == ' ') deleteSpace(str, i);
        else break;
    }
}

void delete_spaceEnd(char str[]) {
    while (true) {
        if (str[strlen(str) - 1] == ' ') deleteSpace(str, strlen(str) - 1);
        else break;
    }
}

void delete_spaceMid(char str[]) {
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

string copyString(char* str, int length) {
    string s = "";
    for (int i = 0; i < length; i++) {
        s = s + str[i];
    }
    return s;
}

string spaceOfName(string& name) {
    char str[100];
    int length;
    length = name.copy(str, name.size());
    str[length] = '\0';
    delete_spaceHead(str);
    delete_spaceMid(str);
    delete_spaceEnd(str);
    name = copyString(str, strlen(str));
    return name;
}
void inhoa(string& str)
{
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}
//--------------
void Vehicle::input() {
    cout << "\t\tbien so xe\t: ";
    do {
        getline(cin, this->bienso);
    } while (this->bienso.length() == 0);
    inhoa(this->bienso);
    spaceOfName(this->bienso);
    
    do {
        // --ngày--
        cout << "\t\t Nhap ngay :";cin >> this->day;
        while (cin.fail()) {
            fix_time(this->day);
            cout << "\t\t Nhap ngay :"; cin >> this->day;
            }
        //----tháng----
        cout << "\t\t Nhap thang :";  cin >> this->month;
        while (cin.fail()) {
            fix_time(this->month);
            cout << "\t\t Nhap thang :";  cin >> this->month;
        }
        // ----năm----
        cout << "\t\t Nhap nam :"; cin >> this->year;
        while (cin.fail()) {
            fix_time(this->year);
            cout << "\t\t Nhap nam :"; cin >> this->year;
        }
        if (!check(this->day, this->month, this->year) ) {
            cout << "\t\tThoi gian khong hop le!" << endl;
        }
    } while (!check(this->day, this->month, this->year));


}

void Vehicle::display() {
    cout << " | " << setw(15) << left << this->bienso
        << " | " << setw(2) << left << this->day << "/" << setw(2) << left << this->month << "/" << setw(4) << left << this->year << " | " << endl;
}

