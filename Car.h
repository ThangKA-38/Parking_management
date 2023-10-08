#pragma once
#include"Vehicle.h"


class Car : public Vehicle {
public:
	Car();
	Car(string bienso, int day, int month, int year);
public:
	virtual	void Add();
	virtual	void Print();
};
