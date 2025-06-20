#include<bits/stdc++.h>
using namespace std;

class HashTable{
    public:
    static const int tsize=10;

    vector<string> table;

    int hashFunction(int key){
        return key % tsize;
    }

    HashTable(): table(tsize,"") {}//initialize here

    void insert(int key){
        
        int index = hashFunction(key);
        while(table[index] != ""){
            // if slot is occupied, probe to the next slot
            index = (index + 1) % tsize; 
        }
        table[index] = to_string(key);
    }

     void display(){
        for(int i = 0; i < tsize; i++){
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