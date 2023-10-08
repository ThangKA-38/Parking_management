#include"Vehicle Management.h"

Vehicle_Management::Vehicle_Management() {
	this->type = 0;
}

Vehicle_Management::Vehicle_Management(char type) {
	this->type = type;
}


void Vehicle_Management::writeMoto() {
	fstream wri; //ghi file 
	wri.open("\DataMoto.txt", fstream::out);
	wri << ListMoto.size() << ",";
	for (int i = 0; i < ListMoto.size(); i++) {
		wri << ListMoto[i]->getBienso() << ","
			<< ListMoto[i]->getDay() << ","
			<< ListMoto[i]->getMonth() << ","
			<< ListMoto[i]->getYear() << "\n";
	}
	wri.close();
}
void Vehicle_Management::writeCar() {
	fstream wri; //ghi file 
	wri.open("\DataOto.txt", fstream::out);
	wri << ListCar.size() << ",";
	for (int i = 0; i < ListCar.size(); i++) {
		wri << ListCar[i]->getBienso() << ","
			<< ListCar[i]->getDay() << ","
			<< ListCar[i]->getMonth() << ","
			<< ListCar[i]->getYear() << "\n";
	}
	wri.close();
}

void Vehicle_Management::readCar() {
	fstream re("DataOto.txt", ios::in);
	Vehicle* temp;
	int  i = 0;;
	string length, biensoT, dayT, monthT, yearT;
	getline(re, length, ',');
	int templength = stoi(length);
	while (i < templength) {
		getline(re, biensoT, ',');
		getline(re, dayT, ',');
		getline(re, monthT, ',');
		getline(re, yearT, '\n');

		int tempday = stoi(dayT);  // stoi() hàm chuyển từ string qua int
		int tempmonth = stoi(monthT);
		int tempyear = stoi(yearT);
		temp = new Car(biensoT, tempday, tempmonth, tempyear);

		ListCar.push_back(temp);
		i++;
	}

	re.close();
}
void Vehicle_Management::readMoto() {

	fstream re("DataMoto.txt", ios::in);
	Vehicle* temp;
	string bienso, day, month, year;

	int  i = 0;;
	string length, biensoT, dayT, monthT, yearT;
	getline(re, length, ',');
	int templength = stoi(length);
	while (i < templength) {
		getline(re, biensoT, ',');
		getline(re, dayT, ',');
		getline(re, monthT, ',');
		getline(re, yearT, '\n');

		int tempday = stoi(dayT);  // stoi() hàm chuyển từ string qua int
		int tempmonth = stoi(monthT);
		int tempyear = stoi(yearT);
		temp = new Moto(biensoT, tempday, tempmonth, tempyear);

		ListMoto.push_back(temp);
		i++;
	}
	re.close();
}
void enter_vitri(int vitri, int length) {
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
// -----------THÊM XE-----------
void Vehicle_Management::Add() {
	cout << "\t\t--------------------------------------------" << endl;
	cout << "\t\t[1]  Oto \n\t\t[2] Xe may:" << endl;
	cout << "\t\tChon loai xe    :";
	cin >> type;

	if (type == 49) {  // theo bảng ASCII thì 49 = 1
		Vehicle* temp = new Car;
		temp->input();
		ListCar.push_back(temp);   // luu vao mang vector
		writeCar();
	}
	else if (type == 50) {
		Vehicle* temp = new Moto;
		temp->input();
		ListMoto.push_back(temp);
		writeMoto();
	}
	else {
		cout << "\n\t\tCHON SAI!" << endl;
	}
	if (type == 49 || type == 50) {
		cout << "\n\t\t----------------------------------------------" << endl;
		cout << "\t\t         XE DA DUOC THEM THANH CONG     " << endl;
		cout << "\n\t\t----------------------------------------------" << endl;
	}
}

//-------IN XE---------
void Vehicle_Management::Print() {
	cout << "\t\t--------------------------------------------" << endl;
	cout << "\t\t[1]  Oto \n\t\t[2] Xe may:" << endl;
	cout << "\t\tChon bang  :";
	cin >> type;
	if (type == 49) {
		ListCar.clear();
		readCar();
		cout << "\t\t---------------------Oto-------------------" << endl;

		cout << "\t\t| " << setw(6) << left << "Thu tu"
			<< " | " << setw(15) << left << "Bien So Xe"
			<< " | " << setw(10) << left << "Thoi gian" << " | " << endl;
		cout << "\t\t__________________________________________" << endl;
		for (int i = 0; i < ListCar.size(); i++) {
			cout << "\t\t| " << setw(6) << left << i + 1;
			ListCar[i]->display();
			cout << "\t\t------------------------------------------" << endl;
		}

	}
	else if (type == 50) {
		ListMoto.clear();
		readMoto();
		cout << "\t\t------------------Xe may------------------" << endl;

		cout << "\t\t| " << setw(6) << left << "Thu tu"
			<< " | " << setw(15) << left << "Bien So Xe"
			<< " | " << setw(10) << left << "Thoi gian" << " | " << endl;
		cout << "\t\t__________________________________________" << endl;
		for (int i = 0; i < ListMoto.size(); i++) {
			cout << "\t\t| " << setw(6) << left << i + 1;
			ListMoto[i]->display();
			cout << "\t\t------------------------------------------" << endl;
		}

	}
	else {
		cout << "\n\t\tCHON SAI!" << endl;
	}

}

//------------------------XÓA-------------
void Vehicle_Management::Remove() {
	cout << "\t\t--------------------------------------------" << endl;
	int vitri;
	if (type == 49) {
		cout << "\t\tNhap vi tri can xoa  : ";
		do {
			cin >> vitri;
			if (vitri < 0 || vitri >ListCar.size()) {
				cout << "\t\t nhap lai  : ";
			}
		} while (vitri < 0 || vitri >ListCar.size());

		enter_vitri(vitri, ListCar.size());// khi nhập kí tự sẽ báo sai

		for (int i = 0; i < ListCar.size(); i++) {// vecter chạy tu
			if (i == (vitri - 1)) {
				ListCar.erase(ListCar.begin() + i);
			}
		}
		cout << "\n\t\t XOA THANH CONG !" << endl;
		writeCar();
	}
	else if (type == 50) {
		cout << "\t\tNhap vi tri can xoa  : ";
		do {
			cin >> vitri;
			if (vitri < 0 || vitri >ListMoto.size()) {
				cout << "\t\t nhap lai  : ";
			}
		} while (vitri < 0 || vitri >ListMoto.size());

		enter_vitri(vitri, ListMoto.size());// khi nhập kí tự sẽ báo sai
		for (int i = 0; i < ListMoto.size(); i++) {
			if (i == (vitri - 1)) {
				ListMoto.erase(ListMoto.begin() + i);
			}
		}
		cout << "\n\t\t XOA THANH CONG !" << endl;
		writeMoto();
	}
	else
		cout << "\n\t\tCHON SAI!" << endl;

}

///----------------CHỈNH SỬA-------------
//------CHÈN----
void Vehicle_Management::Insert() {
	int vitri;
	Vehicle* temp;
	cout << "\t\tNhap vi tri can chen  : ";
	cin >> vitri;
	while (cin.fail()) {  //dùng để kiểm tra nếu có ký tự char nào thì nó sẽ báo không nhập được.
		cout << "\t\t [Khong hop le]" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\t\tNhap vi tri can chen  : ";
			cin >> vitri;
	}
	cout << "\t\t--------------------------------------------" << endl;
	if (type == 49) {
		if (vitri < 0 || vitri > ListCar.size()) {
			cout << " \t\t Khong Co vi tri nay !";
		}
		else {
			temp = new Car;
			temp->input();
			ListCar.emplace(ListCar.begin() + (vitri - 1), temp); // hàm mở rộng vị trí 
			cout << "\t\tChen Thanh Cong " << endl;
		}
		writeCar();
	}
	else if (type == 50) {
		if (vitri < 0 || vitri > ListMoto.size()) {
			cout << " \t\t Khong Co vi tri nay !";
		}
		else {
			temp = new Moto;
			temp->input();
			ListMoto.emplace(ListMoto.begin() + (vitri - 1), temp);
			cout << "\t\tChen Thanh Cong " << endl;
		}
		writeMoto();
	}
	else
		cout << "\t\tChon sai!" << endl;
}


//------THAY THẾ-----
void Vehicle_Management::Replace() {
	int vitri;
	Vehicle* temp;
	cout << "\t\tNhap vi tri can thay the  : ";
	cin >> vitri;
	while (cin.fail()) {  //dùng để kiểm tra nếu có ký tự char nào thì nó sẽ báo không nhập được.
		cout << "\t\t [Khong hop le]" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cout << "\t\tNhap vi tri can thay the  : ";
		cin >> vitri;
	}
	cout << "\t\t--------------------------------------------" << endl;
	if (type == 49) {
		if (vitri < 0 || vitri > ListCar.size()) {
			cout << " \t\t Khong Co vi tri nay !";
		}
		else {
			temp = new Car;
			temp->input();
			ListCar.emplace(ListCar.begin() + (vitri - 1), temp);
			ListCar.erase(ListCar.begin() + vitri);
			cout << "\t\tThay The Thanh Cong " << endl;
		}
		writeCar();
	}
	else if (type == 50) {
		if (vitri < 0 || vitri > ListMoto.size()) {
			cout << " \t\t Khong Co vi tri nay !";
		}
		else {
			temp = new Moto;
			temp->input();
			ListMoto.emplace(ListMoto.begin() + (vitri - 1), temp);
			ListMoto.erase(ListMoto.begin() + vitri);
			cout << "\t\tThay The Thanh Cong " << endl;
		}
		writeMoto();
	}
	else
		cout << "\t\tChon sai!" << endl;
}
void Vehicle_Management::Edit() {
	char typeEdit;
	cout << "\n\t\t   [1]: Thay The Xe " << endl
		<< "\n\t\t   [2]: Chen Xe " << endl;
	cout << "\t\tNhap tuy chon  : ";
	cin >> typeEdit;
	switch (typeEdit) {
	case 49:
		Replace();
		break;
	case 50:
		Insert();
		break;
	default:
		cout << "\t\tChon sai!" << endl;
	}

}