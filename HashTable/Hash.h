//
//  Hash.hpp
//  HashTable
//
//  Created by Katie Reece on 4/3/19.
//  Copyright © 2019 Katie Reece. All rights reserved.
//

#ifndef Hash_h
#define Hash_h
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;


const int SIZE = 20;
class hashTable{
private:
    int key;
    int value;
    int *hash;
    int *newArray;
public:
    hashTable();
    int findKey(int);
    void insert(int);
    void show();
    void resolve(int &key);

    
};

#endif /* Hash_h */
