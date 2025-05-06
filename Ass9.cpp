// Department maintains student information. the file contains rollno, name, division, and address.
// Allow user to add, edit, delete, insert and search information of student. use Direct access file to
// maintain the data. 
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX = 100;
const char* FILENAME = "students.dat";

class Student {
public:
    int rollNo;
    char name[30];
    char division;
    char address[50];

    Student() {
        rollNo = -1;
        strcpy(name, "");
        division = '-';
        strcpy(address, "");
    }

    void input() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Address: ";
        cin.ignore();
        cin.getline(address, 50);
    }

    void display() {
        cout << "Roll No: " << rollNo << ", Name: " << name
             << ", Division: " << division << ", Address: " << address << endl;
    }
};

// Adds a student to the first empty slot
void addStudent() {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    Student s;
    s.input();
    Student temp;

    for (int i = 0; i < MAX; ++i) {
        file.seekg(i * sizeof(Student), ios::beg);
        file.read((char*)&temp, sizeof(Student));
        if (temp.rollNo == -1) {
            file.seekp(i * sizeof(Student), ios::beg);
            file.write((char*)&s, sizeof(Student));
            cout << "Student added successfully.\n";
            file.close();
            return;
        }
    }

    cout << "File is full. Cannot add more students.\n";
    file.close();
}

// Searches student by roll number
void searchStudent() {
    ifstream file(FILENAME, ios::binary);
    int roll;
    cout << "Enter Roll No to search: ";
    cin >> roll;
    Student s;
    bool found = false;

    for (int i = 0; i < MAX; ++i) {
        file.read((char*)&s, sizeof(Student));
        if (s.rollNo == roll) {
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}

// Deletes a student by roll number
void deleteStudent() {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;
    Student s;
    bool found = false;

    for (int i = 0; i < MAX; ++i) {
        file.seekg(i * sizeof(Student), ios::beg);
        file.read((char*)&s, sizeof(Student));
        if (s.rollNo == roll) {
            Student blank;
            file.seekp(i * sizeof(Student), ios::beg);
            file.write((char*)&blank, sizeof(Student));
            cout << "Record deleted.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}

// Edits a student by roll number
void editStudent() {
    fstream file(FILENAME, ios::in | ios::out | ios::binary);
    int roll;
    cout << "Enter Roll No to edit: ";
    cin >> roll;
    Student s;
    bool found = false;

    for (int i = 0; i < MAX; ++i) {
        file.seekg(i * sizeof(Student), ios::beg);
        file.read((char*)&s, sizeof(Student));
        if (s.rollNo == roll) {
            cout << "Existing Record:\n";
            s.display();
            cout << "Enter new details:\n";
            s.input();
            file.seekp(i * sizeof(Student), ios::beg);
            file.write((char*)&s, sizeof(Student));
            cout << "Record updated.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}

// Displays all students
void displayAll() {
    ifstream file(FILENAME, ios::binary);
    Student s;
    bool anyFound = false;

    for (int i = 0; i < MAX; ++i) {
        file.read((char*)&s, sizeof(Student));
        if (s.rollNo != -1) {
            s.display();
            anyFound = true;
        }
    }

    if (!anyFound)
        cout << "No records to display.\n";

    file.close();
}

int main() {
    // Create the file with 100 empty records only if it doesn't exist
    ifstream check(FILENAME, ios::binary);
    if (!check) {
        ofstream file(FILENAME, ios::binary);
        Student s;
        for (int i = 0; i < MAX; ++i)
            file.write((char*)&s, sizeof(Student));
        file.close();
        cout << "Initialized student database.\n";
    }
    check.close();

    int choice;
    do {
        cout << "\n--- Student Information System ---\n";
        cout << "1. Add Student\n2. Search Student\n3. Edit Student\n4. Delete Student\n5. Display All\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: editStudent(); break;
            case 4: deleteStudent(); break;
            case 5: displayAll(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid option!\n";
        }
    } while (choice != 0);

    return 0;
}
