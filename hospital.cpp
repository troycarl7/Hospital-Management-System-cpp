#include <iostream>
#include <iomanip>
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cctype>
#include "hospital.h"
using namespace std;

static void parse_date(const string& s, int& y, int& m, int& d) {
    string digits;
    for (char c : s)
        if (isdigit((unsigned char)c))
            digits.push_back(c);

    if (digits.size() == 8) {
        y = stoi(digits.substr(0, 4));
        m = stoi(digits.substr(4, 2));
        d = stoi(digits.substr(6, 2));
    }
    else {
        y = 9999;
        m = 12;
        d = 31;
    }
}

static bool older(const string& a, const string& b) {
    int y1, m1, d1, y2, m2, d2;
    parse_date(a, y1, m1, d1);
    parse_date(b, y2, m2, d2);

    if (y1 != y2) return y1 < y2;
    if (m1 != m2) return m1 < m2;
    return d1 < d2;
}

Hospital::Hospital() {
    patients = new vector<Patient>();
    doctors = new vector<Doctor>();

    FILE* pf = fopen("patients.txt", "r");
    if (pf) {
        char F[50], L[50], birth[50], blood[50], diag[50], adm[50], did[50];
        long int id, assdoc;

        while (fscanf(pf, "%s %s %ld %ld %s %s %s %s %s",
            F, L, &id, &assdoc, birth, blood, diag, adm, did) == 9) {
            patients->emplace_back(F, L, id, assdoc, birth, blood, diag, adm, did);
        }
        fclose(pf);
    }

    FILE* df = fopen("doctors.txt", "r");
    if (df) {
        char F[50], L[50], spe[50];
        int id, exp;
        double sal, bon;

        while (fscanf(df, "%s %s %d %s %d %lf %lf",
            F, L, &id, spe, &exp, &sal, &bon) == 7) {
            doctors->emplace_back(F, L, id, spe, exp, sal, bon);
        }
        fclose(df);
    }
}

Hospital::~Hospital() {
    delete patients;
    delete doctors;
}

void Hospital::Find_Oldest_Patient() const {
    if (patients->empty()) {
        cout << "No patients found." << endl;
        return;
    }
    size_t oldest = 0;
    for (size_t i = 1; i < patients->size(); i++)
        if (older((*patients)[i].getbirth(), (*patients)[oldest].getbirth()))
            oldest = i;

    (*patients)[oldest].Print_Patient_Info();
}

int Hospital::Count_Critical_Patients() const {
    int c = 0;
    for (auto& p : *patients)
        if (p.Patient_Status() == "Critical")
            c++;
    return c;
}

int Hospital::Count_In_Patients() const {
    int c = 0;
    for (auto& p : *patients)
        if (p.getdidate() == "-1")
            c++;
    return c;
}

void Hospital::Doctors_By_Specialty(const string& spe) const {
    bool f = false;
    for (auto& d : *doctors)
        if (d.getspeciality() == spe) {
            cout << d.getfirstname() << " " << d.getlastname() << endl;
            f = true;
        }
    if (!f)
        cout << "No doctor with that specialty." << endl;
}

void Hospital::Show_Patient_by_ID(long int id) const {
    for (auto& p : *patients)
        if (p.getID() == id) {
            p.Print_Patient_Info();
            return;
        }
    cout << "No patient has the provided ID" << endl;
}

void Hospital::Show_Doctor_by_ID(int id) const {
    for (auto& d : *doctors)
        if (d.getid() == id) {
            d.Print_Doctor_info();
            return;
        }
    cout << "No patient has the provided ID" << endl;
}

void Hospital::Show_Assigned_Doctor(long int pid) const {
    long int did = -1;
    for (auto& p : *patients)
        if (p.getID() == pid) {
            did = p.getassdoc();
            break;
        }

    if (did == -1) {
        cout << "No patient has the provided ID" << endl;
        return;
    }

    for (auto& d : *doctors)
        if (d.getid() == did) {
            d.Print_Doctor_info();
            return;
        }

    cout << "No doctor assigned" << endl;
}

void Hospital::Show_Assigned_Patients(int did) const {
    bool f = false;
    for (auto& p : *patients)
        if (p.getassdoc() == did) {
            p.Print_Patient_Info();
            f = true;
        }
    if (!f)
        cout << "no patients assigned" << endl;
}

void Hospital::Append_Patient_To_File() {
    string F, L, birth, blood, diag, adm, did;
    long int id, assdoc;

    cin >> F >> L >> id >> assdoc >> birth >> blood >> diag >> adm >> did;

    FILE* pf = fopen("patients.txt", "a");
    fprintf(pf, "%s %s %ld %ld %s %s %s %s %s\n",
        F.c_str(), L.c_str(), id, assdoc,
        birth.c_str(), blood.c_str(),
        diag.c_str(), adm.c_str(), did.c_str());
    fclose(pf);

    patients->emplace_back(F, L, id, assdoc, birth, blood, diag, adm, did);
}

void Hospital::Append_Doctor_To_File() {
    string F, L, spe;
    int id, exp;
    double sal, bon;

    cin >> F >> L >> id >> spe >> exp >> sal >> bon;

    FILE* df = fopen("doctors.txt", "a");
    fprintf(df, "%s %s %d %s %d %lf %lf\n",
        F.c_str(), L.c_str(), id, spe.c_str(),
        exp, sal, bon);
    fclose(df);

    doctors->emplace_back(F, L, id, spe, exp, sal, bon);
}
