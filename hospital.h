#ifndef HOSPITAL_H
#define HOSPITAL_H

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
#include "doctor.h"
using namespace std;

class Hospital {
private:
    vector<Patient>* patients;
    vector<Doctor>* doctors;

public:
    Hospital();
    ~Hospital();

    void Find_Oldest_Patient() const;
    int Count_Critical_Patients() const;
    int Count_In_Patients() const;

    void Doctors_By_Specialty(const string& spe) const;

    void Show_Patient_by_ID(long int id) const;
    void Show_Doctor_by_ID(int id) const;

    void Show_Assigned_Doctor(long int patientID) const;
    void Show_Assigned_Patients(int doctorID) const;

    void Append_Patient_To_File();
    void Append_Doctor_To_File();
};

#endif
