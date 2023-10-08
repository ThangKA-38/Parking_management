#pragma once
#include"Vehicle.h"
#include"Car.h"
#include"Moto.h"
#include<vector>
#include<fstream>

class Vehicle_Management {
private:
	vector<Vehicle*> ListCar;
	vector<Vehicle*> ListMoto;
	char type;
public:
	Vehicle_Management();
	Vehicle_Management(char type);
	void Add();
	void Print();
	void Remove();
	//-----edit-----
	void Insert();
	void Replace();
	void Edit();

	// -----ghi file------
	void writeCar();
	void writeMoto();

	// ------- đọc file-------
	void readCar();
	void readMoto();

};
void enter_vitri(int i, int length);