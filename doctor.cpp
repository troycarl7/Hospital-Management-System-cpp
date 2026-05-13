#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cctype>
#include "doctor.h"
using namespace std;

Doctor::Doctor() {
	firstname = "";
	lastname = "";
	ID = 0;
	speciality = "";
	experience = 0;
	salary = 0;
	bonus = 0;
}
Doctor::Doctor(string f, string l, int id,
	string spe, int exp, double sal, double bon) {
	firstname = f;
	lastname = l;
	ID = id;
	speciality = spe;
	experience = exp;
	salary = sal;
	bonus = bon;
}

string Doctor::getfirstname() const { return firstname; }
string Doctor::getlastname() const { return lastname; }
int Doctor::getid() const { return ID; }
string Doctor::getspeciality() const { return speciality; }
int Doctor::getexperience() const { return experience; }
double Doctor::getsalary() const { return salary; }
double Doctor::getbonus() const { return bonus; }

void Doctor::setgetfirstname(const string& f) { firstname = f; }
void Doctor::setgetlastname(const string& l) { lastname = l; }
void Doctor::setgetid(const int& id) { ID = id; }
void Doctor::setgetspeciality(const string& spe) { speciality = spe; }
void Doctor::setgetexperience(const int& exp) { experience = exp; }
void Doctor::setgetsalary(const double& sal) { salary = sal; }
void Doctor::setgetbonus(const double& bon) { bonus = bon; }

int Doctor::calculate_compensation(const double& sal, const double& bon) {
	return sal * (1 + bon);
}
void Doctor::Print_Doctor_info() const {
	cout << setw(10) << firstname;
	cout << setw(10) << lastname;
	cout << setw(10) << ID;
	cout << setw(10) << speciality;
	cout << setw(10) << experience;
	cout << setw(10) << salary;
	cout << setw(10) << bonus << endl;
}
