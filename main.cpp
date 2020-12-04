//this program initializes a hash table that has 20 keys. it will take in a value read in from file p5data.txt and insert it into hash table
//collisions will be detected and a linear probe will occur to find a new key to insert the value into. if there are excess values it will
//display excess values without inserting them into table. Project 5 for CS 2420-601 at UVU, Spring 2019.
//
//  main.cpp
//  HashTable
//
//  Created by Katie Reece on 4/3/19.
//  Copyright © 2019 Katie Reece. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "Hash.h"

int main(){
    string fileName;
    int num;
    vector <int> store;
    
    hashTable hash;
    cout << "Kaitlyn Reece\n10811741\nCS 2420-601\nProject 5\n" << endl;
    cout << "Enter file name: ";
    cin >> fileName;
    ifstream myfile (fileName);
    
    if (myfile.is_open()){
        while (!myfile.eof()){ //while loop to read in data from file and insert into a temporary vector
                myfile >> num;
                store.push_back(num);
            }
        for(int i = 0; i < store.size(); i++){ //for loop inserts value into a hash table by calling insert function
            if(i < SIZE){
                 hash.insert(store[i]);
            }
        }
        for(int i = SIZE; i < store.size(); i++){ //displays any remaining values that weren't inserted into hash table
            cout << "Hash Table full. Unable to insert value " << store[i] << endl;
        }
        hash.show(); //prints contents of the hash table
        myfile.close();
        
    }
    else{
        cout << "Unable to open file" << endl; //if file is not found
    }

    return 0;
}

