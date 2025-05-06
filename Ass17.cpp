// Department maintains student information. the file contains rollno, name, division, and address.
// Allow user to add, edit, delete, insert and search information of student. use sequential file to
// maintain the data
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Student {
    int rollNo;
    string name;
    string division;
    string address;

    string to_string() const {
        return std::to_string(rollNo) + "," + name + "," + division + "," + address;
    }

    static Student from_string(const string& data) {
        stringstream ss(data);
        string part;
        vector<string> parts;
        while (getline(ss, part, ',')) parts.push_back(part);
        return {stoi(parts[0]), parts[1], parts[2], parts[3]};
    }
};

const string FILE_NAME = "students.txt";

void addStudent(const Student& s) {
    ofstream file(FILE_NAME, ios::app);
    file << s.to_string() << endl;
    file.close();
}

void displayAll() {
    ifstream file(FILE_NAME);
    string line;
    cout << "\nRollNo\tName\tDivision\tAddress" << endl;
    while (getline(file, line)) {
        Student s = Student::from_string(line);
        cout << s.rollNo << "\t" << s.name << "\t" << s.division << "\t\t" << s.address << endl;
    }
    file.close();
}

void searchStudent(int roll) {
    ifstream file(FILE_NAME);
    string line;
    bool found = false;
    while (getline(file, line)) {
        Student s = Student::from_string(line);
        if (s.rollNo == roll) {
            cout << "\nRecord Found:\n";
            cout << "RollNo: " << s.rollNo << "\nName: " << s.name
                 << "\nDivision: " << s.division << "\nAddress: " << s.address << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Record not found!\n";
    file.close();
}

void deleteStudent(int roll) {
    ifstream file(FILE_NAME);
    ofstream temp("temp.txt");
    string line;
    bool deleted = false;
    while (getline(file, line)) {
        Student s = Student::from_string(line);
        if (s.rollNo == roll) {
            deleted = true;
            continue;
        }
        temp << line << endl;
    }
    file.close();
    temp.close();
    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());
    if (deleted) cout << "Record deleted successfully.\n";
    else cout << "Record not found!\n";
}

void editStudent(int roll, const Student& newDetails) {
    ifstream file(FILE_NAME);
    ofstream temp("temp.txt");
    string line;
    bool edited = false;
    while (getline(file, line)) {
        Student s = Student::from_string(line);
        if (s.rollNo == roll) {
            temp << newDetails.to_string() << endl;
            edited = true;
        } else {
            temp << line << endl;
        }
    }
    file.close();
    temp.close();
    remove(FILE_NAME.c_str());
    rename("temp.txt", FILE_NAME.c_str());
    if (edited) cout << "Record updated successfully.\n";
    else cout << "Record not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Record Manager ---\n";
        cout << "1. Add Student\n2. Display All\n3. Search by RollNo\n4. Delete Record\n5. Edit Record\n6. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Roll No: "; cin >> s.rollNo; cin.ignore();
            cout << "Name: "; getline(cin, s.name);
            cout << "Division: "; getline(cin, s.division);
            cout << "Address: "; getline(cin, s.address);
            addStudent(s);
        } else if (choice == 2) {
            displayAll();
        } else if (choice == 3) {
            int roll; cout << "Enter RollNo to search: "; cin >> roll;
            searchStudent(roll);
        } else if (choice == 4) {
            int roll; cout << "Enter RollNo to delete: "; cin >> roll;
            deleteStudent(roll);
        } else if (choice == 5) {
            Student s;
            cout << "Roll No to Edit: "; cin >> s.rollNo; cin.ignore();
            cout << "New Name: "; getline(cin, s.name);
            cout << "New Division: "; getline(cin, s.division);
            cout << "New Address: "; getline(cin, s.address);
            editStudent(s.rollNo, s);
        } else if (choice == 6) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

// 1. Add Student
// > Roll No: 1
// > Name: John
// > Division: A
// > Address: Pune

// 2. Display All
// > RollNo Name Division Address
// > 1     John    A       Pune

// ------------------------------------------------------------------------------------------------------

// Here’s a detailed explanation of how this **sequential file-based student management system** works in C++:

// ---

// ## 🎯 Objective

// Maintain student records with fields:

// * `RollNo`
// * `Name`
// * `Division`
// * `Address`

// And support operations like:

// 1. Add
// 2. Display
// 3. Search
// 4. Edit
// 5. Delete
//    ...using **sequential file storage** (`students.txt`).

// ---

// ## 📦 Structure Definition

// ```cpp
// struct Student {
//     int rollNo;
//     string name;
//     string division;
//     string address;
// };
// ```

// Two helper methods:

// * `to_string()` – converts a `Student` to a CSV string
// * `from_string()` – parses a line from the file back into a `Student` object

// ---

// ## 💾 File Used

// ```cpp
// const string FILE_NAME = "students.txt";
// ```

// Stores all student records **line by line** in CSV format:

// ```
// 1,John,A,Pune
// 2,Sara,B,Mumbai
// ```

// ---

// ## 🔧 Core Functions

// ### 1. `addStudent()`

// Appends a student record to the file:

// ```cpp
// ofstream file(FILE_NAME, ios::app);
// file << s.to_string() << endl;
// ```

// ---

// ### 2. `displayAll()`

// Reads each line from the file, converts to a `Student` and prints it:

// ```cpp
// ifstream file(FILE_NAME);
// while (getline(file, line)) {
//     Student s = Student::from_string(line);
//     // print s
// }
// ```

// ---

// ### 3. `searchStudent(int roll)`

// Reads each line and checks if `rollNo` matches. If found, it prints the record.

// ---

// ### 4. `deleteStudent(int roll)`

// * Opens the original file for reading.
// * Writes every line **except the one to delete** into a temp file.
// * Replaces the original file with the temp file.

// This simulates deletion in a sequential file.

// ---

// ### 5. `editStudent(int roll, Student newDetails)`

// Same as delete, but:

// * If roll matches, write the **new details**.
// * Else, copy the old line as-is.

// ---

// ## 🧪 Sample I/O

// ### Adding:

// ```
// Roll No: 1
// Name: John
// Division: A
// Address: Pune
// ```

// Saved as:

// ```
// 1,John,A,Pune
// ```

// ### Searching:

// ```
// Enter RollNo to search: 1
// Record Found:
// RollNo: 1
// Name: John
// Division: A
// Address: Pune
// ```

// ---

// ## 🧠 Notes

// * File is **sequential**: appending is easy, but searching/editing/deleting needs reading the whole file.
// * Temporary file is used to simulate editing or deleting.
// * Easy to port into C++ classes if needed.

// ---

// ## ✅ Summary Table

// | Operation   | Method            | File Handling Type  |
// | ----------- | ----------------- | ------------------- |
// | Add         | `addStudent()`    | Append (`ios::app`) |
// | Display All | `displayAll()`    | Read (`ifstream`)   |
// | Search      | `searchStudent()` | Read (`ifstream`)   |
// | Delete      | `deleteStudent()` | Read+Write via temp |
// | Edit        | `editStudent()`   | Read+Write via temp |

// ---

// Would you like a version of this that uses **binary file storage** for better performance and fixed-size records?
