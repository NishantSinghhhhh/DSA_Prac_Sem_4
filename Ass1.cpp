// Consider the student database of N students and their marks. Make use of a hash table
// implementation to quickly insert and lookup students' Rollno and marks. Implement collision
// handling techniques- linear probing with chaining without replacement.
// Test case:
// Create a hash table of size 10.
// 1. Linear probing with chaining without replacement: Insert the following RollNos:
// (31,13,14,51,16,71,48,19)

#include <iostream>
using namespace std;

const int SIZE = 10;

struct Student {
    int rollNo;
    int marks;
    int link;
    bool occupied;

    Student() {
        rollNo = -1;
        marks = 0;
        link = -1;
        occupied = false;
    }
};

class HashTable {
    Student table[SIZE];

    int hashFunction(int rollNo) {
        return rollNo % SIZE;
    }

public:
    // Insert a roll number and marks into the hash table
    void insert(int rollNo, int marks) {
        int index = hashFunction(rollNo);

        // Case 1: Home slot is empty
        if (!table[index].occupied) {
            table[index].rollNo = rollNo;
            table[index].marks = marks;
            table[index].occupied = true;
            return;
        }

        // Case 2: Home slot is occupied — find next free slot
        int i = (index + 1) % SIZE;
        while (i != index && table[i].occupied) {
            i = (i + 1) % SIZE;
        }

        if (i == index) {
            cout << "Hash table is full!\n";
            return;
        }

        // Insert at free slot
        table[i].rollNo = rollNo;
        table[i].marks = marks;
        table[i].occupied = true;

        // Chain from home slot (without replacement)
        int j = index;
        while (table[j].link != -1) {
            j = table[j].link;
        }
        table[j].link = i;
    }

    // Display the hash table
    void display() {
        cout << "Index\tRollNo\tMarks\tLink\n";
        for (int i = 0; i < SIZE; ++i) {
            if (table[i].occupied)
                cout << i << "\t" << table[i].rollNo << "\t" << table[i].marks << "\t" << table[i].link << "\n";
            else
                cout << i << "\tEmpty\n";
        }
    }
};

int main() {
    HashTable ht;

    int rollNos[] = {31, 13, 14, 51, 16, 71, 48, 19};
    int n = sizeof(rollNos) / sizeof(rollNos[0]);

    // Insert roll numbers with dummy marks = rollNo + 50
    for (int i = 0; i < n; ++i) {
        ht.insert(rollNos[i], rollNos[i] + 50);
    }

    // Display final table
    cout << "Final Hash Table (Linear Probing with Chaining Without Replacement):\n";
    ht.display();

    return 0;
}
