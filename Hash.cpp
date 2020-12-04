//
//  Hash.cpp
//  HashTable
//
//  Created by Katie Reece on 4/3/19.
//  Copyright © 2019 Katie Reece. All rights reserved.
//

#include "Hash.h"

hashTable::hashTable(){ //no argument initializer
    hash = new int[SIZE];
    for(int i = 0; i < SIZE; i++){
        hash[i] = -999; //initializes every value in hash table to -999
    }
}
void hashTable::insert(int value){ //inserts a value into the hash table and also detects collisions
    int collide = -1; //an arbitrary value to keep while loop going
    int key = findKey(value);
    while(collide == -1){
        if(hash[key] == -999){ //inserts the value into hash table if no collision is detected
            hash[key] = value;
            collide = 1;
        }
        else{//if collision is detected it will call the resolve function
            cout << "Collision detected at location " << key << ", for value " << value << endl;
            resolve(key);
            //cout << "Collision detected at " << key << "with value" << value << endl;
        }
    }
}

int hashTable::findKey(int value){ //calculates which key a value should be inserted at
    key = value % SIZE;
    return key;
}

void hashTable::resolve(int &key){ //if collision is detected it will perform a linear probe
    while(hash[key] != -999){
        key = key + 1;
        if(key > SIZE - 1){ //if there are no empty keys after a collision it will return to the start of the table and search for empty key
            key = 0;
        }
    }
}


void hashTable::show(){  //function prints the contents of the hash table. displays key number and value
    cout << "\nHASH TABLE" << endl;
    cout << "\nKey\tValue" << endl;
    for(int i = 0; i < SIZE; i++){
        cout << i << "\t" << hash[i] << endl;
    }
}

