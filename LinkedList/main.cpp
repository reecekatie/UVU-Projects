//
//  main.cpp
//  Linked List
//
//  Created by Katie Reece on 1/29/19.
//  Copyright © 2019 Katie Reece. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Header.h"
using namespace std;
singleList a;
doubleList b;

void insertList(int val) {
    b.addNodeDouble(val);
}

int main(){
    
    string fileName;
    vector <int> data;
    int num;
    
    cout << "Enter file name: ";
    cin >> fileName;
    ifstream myfile (fileName);
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile >> num;
            data.push_back(num);
        }
        
        myfile.close();
    }
    
    else{
        cout << "Unable to open file" << endl;
    }
    
    for(int i = 0; i < data.size(); i++){
        a.addNode(data.at(i));
        
    }
    a.Print();
    a.Traverse(insertList);
    cout << "double" << endl;
    b.PrintDouble();
}
