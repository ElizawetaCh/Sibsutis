#include <iostream>
#include <string.h>
#include <locale.h>
#include <cstdlib>
#include <math.h>

using namespace std;

#define PI 3.14159265                                  

class moving {
public:
	double newdolg;
	double newshirot;
	int speed;
	moving() {
		speed = 1 + rand() % (8 - 1 + 1);
		newdolg = 0 + rand() % (180 - 0 + 1);
		newshirot = 0 + rand() % (90 - 0 + 1);
	}

	int get_speed() {
		return speed;
	}

	
	
	
	double get_newlongtitude() {
		return newdolg;
	}

	double get_newlatitude() {
		return newshirot;
	}

	void get_newCoordinates() {
		cout << "\nНовая долгота: " << get_newlongtitude() << endl;
		cout << "Новая широта: " << get_newlatitude() << endl << endl;
	}

	//void mathematic() {
	//	q = sin(latitude) * sin(newshirot) + cos(latitude) * cos(newshirot) * cos(abs(longtitude - newdolg));
	//	d = acos(q);
	//	L = d * 6371;
	//}

	//double det_dist() {
	//	return L;
	//}
};

class Coordinates : public moving {
public:
	double longtitude;
	double latitude;
	double d;
	double L;
	double q;
	
	Coordinates(double dolg, double shirot) : moving() {
		if (dolg >= 0 && dolg <= 180) 
			longtitude = dolg;
		else {
			cout << "ОШИБКА: Неверно задана долгота" << endl;
			longtitude = -1;
		}
		if (shirot >= 0 && shirot <= 90) 
			latitude = shirot;
		else {
			cout << "ОШИБКА: Неверно задана широта" << endl;
			latitude = -1;
		}
	}

	void set_Coordinates(double dolg, double shirot) {
		longtitude = dolg;
		latitude = shirot;
	}

	double get_longtitude() {
		return longtitude;
	}

	double get_latitude() {
		return latitude;
	}

	void get_Coordinates() {
		cout << "\nДолгота: " << get_longtitude() << endl;
		cout << "Широта: " << get_latitude() << endl;
	}
	double get_dist() {
		q = sin(latitude) * sin(newshirot) + cos(latitude) * cos(newshirot) * cos(abs(longtitude - newdolg));
		d = abs(acos(q));
		L = d * 6371;
		return L;
	}

	
};

class HUMAN : public Coordinates {
private:
	string name;
	string surname;
	string patronymiс;
	double weight;
	double height;
	int speed;
	int age;
	
	
public:
	HUMAN(string sn, string nm, string pt, double a, double w, double h, double longt, double latit) : Coordinates(longt, latit) {
		name = nm;
		surname = sn;
		patronymiс = pt;
		age = a;
		weight = w;
		height = h;
		speed = get_speed();
		
	}

	string get_nm() {
		return name;
	}

	string get_sn() {
		return surname;
	}

	string get_pt() {
		return patronymiс;
	}

	int get_age() {
		return age;
	}

	void get_name() {
		cout << "Пользователь: " << get_sn();
		cout << " " << get_nm();
		cout << " " << get_pt()<<endl;
	}

	void set_name(string nm, string sn, string pt) {
		name = nm;
		surname = sn;
		patronymiс = pt;
	}

	double get_weight() {
		return weight;
	}

	double get_height() {
		return height;
	}

	void get_parameters() {
		cout << "\nВозраст: " << get_age() << endl;
		cout << "\nВес: " << get_weight() << endl;
		cout << "Рост: " << get_height() << endl;
	}

	void set_parameters(int a, double w, double h) {
		age = a;
		weight = w;
		height = h;
	}
	

	
};

int main() {
	setlocale(LC_ALL, "Russian");
	HUMAN* firsthuman = new HUMAN ("Иванов", "Иван", "Иванович", 23, 85, 189, 88, 77);
	firsthuman->get_name();
	firsthuman->get_parameters();
	firsthuman->get_Coordinates();
	firsthuman->get_newCoordinates();
	cout << "Скорость движения: " << firsthuman->get_speed() << " км/ч" << endl;
	cout << "Расстояние: " << firsthuman->get_dist() << " км" << endl;
	cout << "Время:" << firsthuman->get_dist()/ firsthuman->get_speed()<< " часов"<<endl;
	cout << endl;
	HUMAN* secondhuman = new HUMAN("Петров", "Александр", "Геннадьевич", 69, 102, 175, 96.3, 89);
	secondhuman->get_name();
	secondhuman->get_parameters();
	secondhuman->get_Coordinates();
	secondhuman->get_newCoordinates();
	cout << "Скорость движения: " << secondhuman->get_speed() << " км/ч" << endl;
	cout << "Расстояние: " << secondhuman->get_dist() << " км" << endl;
	cout << "Время:" << secondhuman->get_dist() / secondhuman->get_speed() << " часов"<<endl;
	cout << endl;
}