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
#include "hospital.h"
using namespace std;

int main() {
    Hospital h;

    Patient testP("Test", "Patient", 9999, -1, "1990-01-01", "O+", "stable", "2024-01-01", "-1");
    Doctor testD("Test", "Doctor", 8888, "TestSpec", 10, 90000.0, 0.1);

    cout << "Testing individual Patient object:" << endl;
    testP.Print_Patient_Info();
    cout << "Status: " << testP.Patient_Status() << endl;
    cout << "Discharged? " << (testP.IsDischarged(testP.getdidate()) ? "Yes" : "No") << endl;

    cout << "\nTesting individual Doctor object:" << endl;
    testD.Print_Doctor_info();
    cout << "Total compensation: " << testD.calculate_compensation(testD.getsalary(), testD.getbonus()) << endl;

    int choice = -1;
    while (choice != 0) {
        cout << endl << "Hospital Menu" << endl;
        cout << "1. Show oldest patient" << endl;
        cout << "2. Count critical patients" << endl;
        cout << "3. Count in-patients" << endl;
        cout << "4. Show patient by ID" << endl;
        cout << "5. Show doctor by ID" << endl;
        cout << "6. Show assigned doctor of a patient" << endl;
        cout << "7. Show patients assigned to a doctor" << endl;
        cout << "8. Enroll new patient" << endl;
        cout << "9. Add new doctor" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            string tmp;
            getline(cin, tmp);
            cout << "Invalid input." << endl;
            continue;
        }

        try {
            if (choice == 1) {
                h.Find_Oldest_Patient();
            }
            else if (choice == 2) {
                cout << "Critical patients: " << h.Count_Critical_Patients() << endl;
            }
            else if (choice == 3) {
                cout << "In-patients: " << h.Count_In_Patients() << endl;
            }
            else if (choice == 4) {
                long int id;
                cout << "Enter patient ID: ";
                cin >> id;
                h.Show_Patient_by_ID(id);
            }
            else if (choice == 5) {
                int id;
                cout << "Enter doctor ID: ";
                cin >> id;
                h.Show_Doctor_by_ID(id);
            }
            else if (choice == 6) {
                long int pid;
                cout << "Enter patient ID: ";
                cin >> pid;
                h.Show_Assigned_Doctor(pid);
            }
            else if (choice == 7) {
                int did;
                cout << "Enter doctor ID: ";
                cin >> did;
                h.Show_Assigned_Patients(did);
            }
            else if (choice == 8) {
                cout << "Enter: Fname Lname ID AssignedDoctorID Birth Blood Diagnosis Admission Discharge" << endl;
                h.Append_Patient_To_File();
            }
            else if (choice == 9) {
                cout << "Enter: Fname Lname ID Specialty Experience Salary Bonus" << endl;
                h.Append_Doctor_To_File();
            }
            else if (choice == 0) {
                cout << "Exiting." << endl;
            }
            else {
                cout << "Invalid choice." << endl;
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
