#include <iostream>
#include <string.h>
#include <locale.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define PI 3.14159265                                  
 
int LifeCount = 15;
class Mover {
public:
	int Speed;
	Mover() {
		Speed = 1 + rand() % (8 - 1 + 1);
	}

	int getSpeed() {
		return Speed;
	}
};

class Coordinates : public Mover {

public:
	double NewLongtitude = 900;
	double NewLatitude = 900;
	double Longtitude;
	double Latitude;
	double d;
	double L;
	double q;
	
	Coordinates(double longtitude, double lantitude) : Mover() {
		if (longtitude >= 0 && longtitude <= 180) 
			Longtitude = longtitude;
		else {
			cout << "ОШИБКА: Неверно задана долгота" << endl;
			Longtitude = -1;
		}
		if (lantitude >= 0 && lantitude <= 90) 
			Latitude = lantitude;
		else {
			cout << "ОШИБКА: Неверно задана широта" << endl;
			Latitude = -1;
		}
		
	}

	void setCoordinates(double longtitude, double latitude) 
	{		
		Longtitude = longtitude;
		Latitude = latitude;
		NewLatitude = latitude;
		NewLongtitude = longtitude;
	}

	double getLonglitude() {
		return Longtitude;
	}

	double getLatitude() {
		return Latitude;
	}

	void printCoordinates() {
		cout << "\nДолгота: " << getLonglitude() << endl;
		cout << "Широта: " << getLatitude() << endl;
	}
	
	void setNewCoordinates() {
		NewLongtitude = NewLongtitude + rand() % 1000 / 1000.;
		NewLatitude = NewLatitude + rand() % 1000 / 1000. ;
	}

	double getNewLongtitude() 
	{
		return NewLongtitude;
	}

	double getNewLatitude() 
	{
		return NewLatitude;
	}

	void getNewCoordinates()
	{
		cout << "\nНовая долгота: " << getNewLongtitude() << endl;
		cout << "Новая широта: " << getNewLatitude() << endl << endl;
	}
	double getDist() 
	{
		q = sin(Latitude) * sin(NewLatitude) + cos(Latitude) * cos(NewLatitude) * cos(abs(Longtitude - NewLongtitude));
		d = abs(acos(q));
		L = d * 6371;
		return L;
	}


};

class HUMAN : public Coordinates 
{
private:
	string _name;
	string _sureName;
	string _patronymiс;
	double _weight;
	double _height;
	int _speed;
	int _age;
	
	
public:
	HUMAN(string sureName, string name, string patronymiс, double age, double weight, double height, double longt, double latit) : Coordinates(longt, latit) {
		_name = name;
		_sureName = sureName;
		_patronymiс = patronymiс;
		_age = age;
		_weight = weight;
		_height = height;
		_speed = getSpeed();
		
	}

	string getName() {
		return _name;
	}

	string getSurename() {
		return _sureName;
	}

	string getPatronymic() {
		return _patronymiс;
	}

	int get_age() {
		return _age;
	}

	void printName() {
		cout << "Пользователь: " << getSurename();
		cout << " " << getName();
		cout << " " << getPatronymic()<<endl;
	}

	void setName(string name, string sureName, string patronymic) {
		_name = name;
		_sureName = sureName;
		_patronymiс = patronymic;
	}

	double getWeight() {
		return _weight;
	}

	double getHeight() {
		return _height;
	}

	void printParameters() {
		cout << "\nВозраст: " << get_age() << endl;
		cout << "\nВес: " << getWeight() << endl;
		cout << "Рост: " << getHeight() << endl;
	}

	void setParameters(int age, double weight, double height) {
		_age = age;
		_weight = weight;
		_height = height;
	}
};

void printHumanInfo(HUMAN* firstHuman);

void printBaseInfo(HUMAN* firstHuman);

int main() {
	setlocale(LC_ALL, "Russian");
	HUMAN* firstHuman = new HUMAN ("Иванов", "Иван", "Иванович", 23, 85, 189, 88, 77);
	HUMAN* secondhuman = new HUMAN("Петров", "Александр", "Геннадьевич", 69, 102, 175, 96.3, 89);

	printBaseInfo(firstHuman);
	for (int i = 0; i < LifeCount; i++) 
	{
		firstHuman->setNewCoordinates();
		firstHuman->getNewCoordinates();
	}
	printHumanInfo(firstHuman);

	printBaseInfo(secondhuman);
	for (int i = 0; i < LifeCount; i++) 
	{
		secondhuman->setNewCoordinates();
		secondhuman->getNewCoordinates();
	}
	printHumanInfo(secondhuman);

	return 0;
}

void printBaseInfo(HUMAN* human)
{
	human->printName();
	human->printParameters();
	human->printCoordinates();
}

void printHumanInfo(HUMAN* human)
{
	cout << "Скорость движения: " << human->getSpeed() << " км/ч" << endl;
	cout << "Расстояние: " << human->getDist() << " км" << endl;
	cout << "Время:" << human->getDist() / human->getSpeed() << " часов" << endl;
	cout << endl;
}
