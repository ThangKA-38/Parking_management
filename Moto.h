#pragma once
#include"Vehicle.h"


class Moto : public Vehicle {
public:
	Moto();
	Moto(string bienso, int day, int month, int year);
public:
	virtual void Add();
	virtual void Print();
};