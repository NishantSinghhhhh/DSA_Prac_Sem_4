// Input a list of more than 20 correctly spelled lowercase words. The words are inserted into the
// hash table. Handle collision using separate chaining. After input is obtained, each word that the
// user enters into the program is looked up within the hash table to see if it exists. If the user
// entered word exists within the hash table, then that word is spelled correctly.

#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

const int TABLE_SIZE = 10;

class HashTable{
    vector<list<string>> table;

    int hashFunction(const string& word){
        int hash = 0;
        for(char ch: word){
            hash = (hash*31 + ch) % TABLE_SIZE;

        }
        return hash;
    }

public:
    HashTable(){
        table.resize(TABLE_SIZE);
    }

    void insert(const string& word){
        int index = hashFunction(word);
        table[index].push_back(word);
    }

    bool search(const string& word){
        int index = hashFunction(word);

        for(const string& w: table[index]){
            if(w == word){
                return true;
            }
        }
        return false;
    }

    void loadDictionary() {
        vector<string> words = {
            "apple", "banana", "grape", "orange", "melon",
            "lemon", "cherry", "peach", "plum", "kiwi",
            "mango", "pear", "lime", "apricot", "fig",
            "date", "guava", "papaya", "coconut", "berry",
            "nectarine", "lychee", "tangerine", "quince", "dragonfruit"
        };

        for (const string& word : words) {
            insert(word);
        }

        cout << "Dictionary loaded with " << words.size() << " words.\n";
    }
};

int main(){
    HashTable hashTable;
    hashTable.loadDictionary();

    string input;
    cout << "\nEnter words to check spelling (type 'exit' to stop):\n";

    while(true){
        cout << "> ";

        cin>>input;

        if(input == "exit"){
            break;
        }
        if(hashTable.search(input)){
            cout << input << " is spelled correctly.\n";
        } else {
            cout << input << " is not found in the dictionary.\n";
        }
    }

}