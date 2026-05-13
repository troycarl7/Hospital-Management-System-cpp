#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cctype>
#include "patient.h"
using namespace std;

Patient::Patient() {
	Fname = "";
	Lname = "";
	ID = 0;
	assdoc = 0;
	birth = "";
	blood = "";
	diagnosis = "";
	admission = "";
	didate = "";
}
Patient::Patient(string F, string L, long int pid, long int ass, string b,
	string bl, string d, string adm, string did) {
	Fname = F;
	Lname = L;
	ID = pid;
	assdoc = ass;
	birth = b;
	blood = bl;
	diagnosis = d;
	admission = adm;
	didate = did;
}

string Patient::getFname() const { return Fname; }
string Patient::getLname() const { return Lname; }
long int Patient::getID() const { return ID; }
long int Patient::getassdoc() const { return assdoc; }
string Patient::getbirth() const { return birth; }
string Patient::getblood() const { return blood; }
string Patient::getdiagnosis() const { return diagnosis; }
string Patient::getadmission() const { return admission; }
string Patient::getdidate() const { return didate; }


void Patient::setgetFname(const string& F) { Fname = F; }
void Patient::setgetLname(const string& L) { Lname = L; }
void Patient::setgetID(const long int& pid) { ID = pid; }
void Patient::setgetassdoc(const long int ass) { assdoc = ass; }
void Patient::setgetbirth(const string& b) { birth = b; }
void Patient::setgetblood(const string& bl) { blood = bl; }
void Patient::setgetdiagnosis(const string& d) { diagnosis = d; }
void Patient::setgetadmission(const string& adm) { admission = adm; }
void Patient::setgetdidate(const string& did) { didate = did; }
bool Patient::IsDischarged(const string& did) {
	if (did != "-1") return true;
	else return false;
}
string Patient::Patient_Status() const{
	string status = diagnosis;
	string compare = status.substr(0, status.find(' '));

	if (compare == "critical" || compare == "Critical") {
		return "Critical";
	}
	else if (compare == "moderate" || compare == "Moderate") {
		return "Moderate";
	}
	else return "Stable";
}
void Patient::Print_Patient_Info() const {
	cout << setw(10) << Fname;
	cout << setw(10) << Lname;
	cout << setw(10) << ID;
	cout << setw(10) << assdoc;
	cout << setw(10) << birth;
	cout << setw(10) << blood;
	cout << setw(10) << diagnosis;
	cout << setw(10) << admission;
	cout << setw(10) << didate << endl;
}
