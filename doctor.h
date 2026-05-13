#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cctype>


class Doctor {
private:
	string firstname;
	string lastname;
	int ID;
	string speciality;
	int experience;
	double salary;
	double bonus;
public:
	Doctor();
	Doctor(string f, string l, int id, 
		string spe, int exp, double sal, double bon);

	string getfirstname() const;
	string getlastname() const;
	int getid() const;
	string getspeciality() const;
	int getexperience() const;
	double getsalary() const;
	double getbonus() const;

	void setgetfirstname(const string& f);
	void setgetlastname(const string& l);
	void setgetid(const int& id);
	void setgetspeciality(const string& spe);
	void setgetexperience(const int& exp);
	void setgetsalary(const double& sal);
	void setgetbonus(const double& bon);

	
	int calculate_compensation(const double& sal, const double& bon);
	void Print_Doctor_info() const;




};


#endif
