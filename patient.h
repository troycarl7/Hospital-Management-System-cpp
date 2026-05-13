#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


class Patient {
private:
	string Fname;
	string Lname;
	long int ID;
	long int assdoc;
	string birth;
	string blood;
	string diagnosis;
	string admission;
	string didate;

public:
	Patient();
	Patient(string F, string L, long int id, long int ass, string b,
		string bl, string d, string adm, string did);

	string getFname() const;
	string getLname() const;
	long int getID() const;
	long int getassdoc() const;
	string getbirth() const;
	string getblood() const;
	string getdiagnosis() const;
	string getadmission() const;
	string getdidate() const;

	void setgetFname(const string& F);
	void setgetLname(const string& L);
	void setgetID(const long int& id);
	void setgetassdoc(const long int ass);
	void setgetbirth(const string& b);
	void setgetblood(const string& bl);
	void setgetdiagnosis(const string& d);
	void setgetadmission(const string& adm);
	void setgetdidate(const string& did);
	
	bool IsDischarged(const string& did);
	string Patient_Status() const;
	void Print_Patient_Info() const;

};

#endif
