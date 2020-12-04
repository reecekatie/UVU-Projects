//
//  Header.h
//  Linked List
//
//  Created by Katie Reece on 1/30/19.
//  Copyright © 2019 Katie Reece. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};

class singleList{
private:
    node *head;
    node *tail;
public:
    singleList(){
        head = NULL;
        tail = NULL;
    }
    void addNode(int n){
        node *tmp = new node;
        tmp-> data = n;
        tmp-> next = NULL;
        if(head == NULL){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void Print(){
        node *p;
        p = head;
        while( p != NULL){
            cout << p->data << endl;
            p = p->next;
        }
    }
    void Traverse(void(*function) (int)){
        node *p;
        p = head;
        while( p != NULL){
            function(p->data);
            p = p->next;
            
        }
    }

};
class doubleList{
private:
    node *head;
    node *tail;
public:
    void addNodeDouble(int n){
        
        node *tmp = new node;
        tmp-> data = n;
        tmp-> next = NULL;
        
        if(head == NULL){
            head = tmp;
        }
        else if (head->data >= tmp->data) {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }
        
        else {
            node* cursor = head;
            
            while (cursor->next != NULL &&  cursor->next->data < tmp->data) {
                cursor = cursor->next;
            }
            
            tmp->next = cursor->next;
        
            if (cursor->next != NULL) {
                cursor->next = tmp;
            }
            cursor->next = tmp;
            tmp->prev = cursor;
        }
    }


    void PrintDouble(){
        node *p;
        p = head;
        while( p != NULL){
            cout << p->data << endl;
            p = p->next;
        }
    }
    
};
#endif /* Header_h */

