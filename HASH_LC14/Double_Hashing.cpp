#include<bits/stdc++.h>
using namespace std;

class HashTable{
    static const int table_size = 10;
    vector<string> table;

    int hashFunction(int key){
        return key % table_size;
    }
    
    int hashFunction2(int key){
        return 1 + key % 5;
    }

public:
    
    HashTable() : table(table_size, "") { }  // initialize here

    void insert(int key){
        
        int index = hashFunction(key);
        int i = 1;
        while(table[index] != ""){
            
            // if slot is occupied, probe to the next slot, calculate next index based on double hashing
            index = (hashFunction(key) + i * hashFunction2(key)) % table_size; 
            i++;

            if (i >= table_size)
            {
                cerr << "Error: Could not insert key " << key << ". Table might be full or probing failed." << endl;
                return; // Exit if we've probed too many times
            }
        }
        table[index] = to_string(key);
    }

    void display(){
        for(int i = 0; i < table_size; i++){
            if(table[i] != ""){
                cout << "Index " << i << ": " << table[i] << endl;
            }
            else
            {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

int main(){

    HashTable ht;
    ht.insert(12);
    ht.insert(18);
    ht.insert(13);
    ht.insert(2);
    ht.insert(3);
    ht.insert(23);
    ht.insert(5);
    ht.insert(15);
    ht.display();

    return 0;
}