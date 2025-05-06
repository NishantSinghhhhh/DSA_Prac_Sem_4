// Consider the student database of N students and their marks. Make use of a hash table
// implementation to quickly insert and lookup students' PNR and marks. Implement collision
// handling techniques- linear probing with chaining with replacement
// Test case :
// Create a hash table of size 10.
// Linear probing with chaining with replacement: Insert the following PNR: (11,
// 21,31,34,55,52,33)

#include <iostream>
using namespace std;

const int SIZE = 10;

struct Student {
    int pnr;
    int marks;
    bool occupied;
    int link;

    Student() {
        pnr = -1;
        marks = 0;
        occupied = false;
        link = -1;
    }
};

class HashTable {
    Student table[SIZE];

    int hashFunction(int pnr) {
        return pnr % SIZE;
    }

public:
    void insert(int pnr, int marks) {
        int home = hashFunction(pnr);

        if (!table[home].occupied) {
            // Empty home slot
            table[home].pnr = pnr;
            table[home].marks = marks;
            table[home].occupied = true;
            return;
        }

        int existingHome = hashFunction(table[home].pnr);
        if (existingHome != home) {
            // Replacement needed: current slot occupied by a displaced record
            Student displaced = table[home];

            // Insert new at correct home
            table[home].pnr = pnr;
            table[home].marks = marks;
            table[home].occupied = true;
            table[home].link = -1;

            // Reinsert displaced student elsewhere
            int i = (home + 1) % SIZE;
            while (table[i].occupied)
                i = (i + 1) % SIZE;

            table[i] = displaced;

            // Update link of correct home of displaced
            int dispHome = hashFunction(displaced.pnr);
            while (table[dispHome].link != -1)
                dispHome = table[dispHome].link;
            table[dispHome].link = i;
        } else {
            // Collision, find next slot
            int i = (home + 1) % SIZE;
            while (table[i].occupied)
                i = (i + 1) % SIZE;

            table[i].pnr = pnr;
            table[i].marks = marks;
            table[i].occupied = true;

            // Chain from home
            int j = home;
            while (table[j].link != -1)
                j = table[j].link;
            table[j].link = i;
        }
    }

    void display() {
        cout << "\nIndex\tPNR\tMarks\tLink\n";
        for (int i = 0; i < SIZE; ++i) {
            if (table[i].occupied)
                cout << i << "\t" << table[i].pnr << "\t" << table[i].marks << "\t" << table[i].link << endl;
            else
                cout << i << "\tEmpty\n";
        }
    }
};

int main() {
    HashTable ht;
    int pnrList[] = {11, 21, 31, 34, 55, 52, 33};
    int marksList[] = {70, 80, 75, 85, 90, 60, 65};

    for (int i = 0; i < 7; ++i)
        ht.insert(pnrList[i], marksList[i]);

    ht.display();

    return 0;
}
