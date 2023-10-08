#include"Moto.h"

Moto::Moto() {
}
Moto::Moto(string bienso, int day, int month, int year) : Vehicle(bienso, day, month, year) {

}

void Moto::Add() {
	Vehicle::input();
}
void Moto::Print() {

	Vehicle::display();

}