#include"Car.h"

Car::Car() {
}
Car::Car(string bienso, int day, int month, int year) : Vehicle(bienso, day, month, year) {

}
void Car::Add() {
	Car::input();
}
void Car::Print() {
	Car::display();

}