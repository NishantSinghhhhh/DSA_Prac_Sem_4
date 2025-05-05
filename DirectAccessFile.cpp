#include <iostream>
#include <fstream>
using namespace std;

// Simple structure to hold student info
struct Student {
    int rollno;
    char name[30];
    char division;
    char address[50];
};

// Add a student to the file
void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);

    cout << "\nEnter Roll No: ";
    cin >> s.rollno;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(s.name, 30);
    cout << "Enter Division: ";
    cin >> s.division;
    cout << "Enter Address: ";
    cin.ignore();
    cin.getline(s.address, 50);

    file.write((char*)&s, sizeof(s));
    file.close();
    cout << "Student added.\n";
}

// Display all student records
void displayStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);
    cout << "\nStudent Records:\n";

    while (file.read((char*)&s, sizeof(s))) {
        cout << "\nRoll No: " << s.rollno;
        cout << "\nName   : " << s.name;
        cout << "\nDiv    : " << s.division;
        cout << "\nAddress: " << s.address << "\n";
    }

    file.close();
}

// Search for a student by roll number
void searchStudent() {
    Student s;
    int roll;
    bool found = false;
    ifstream file("students.dat", ios::binary);

    cout << "Enter Roll No to search: ";
    cin >> roll;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.rollno == roll) {
            cout << "\nFound Student:\n";
            cout << "Roll No : " << s.rollno << "\n";
            cout << "Name    : " << s.name << "\n";
            cout << "Division: " << s.division << "\n";
            cout << "Address : " << s.address << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found.\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option.\n";
        }
    } while (choice != 4);

    return 0;
}
