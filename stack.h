#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class TBD>
class DynamicStack {
private:
    struct Node {
        TBD item;
        Node* next;

        Node(TBD item){
            this->item = item;
            next = NULL;
        }

    };

    Node* top;
    int count;
    int capacity;

public:
    // capacity of zero means "unlimited"

    DynamicStack(int capacity = 0){
        if (capacity < 0) {
            throw invalid_argument("capacity cannot be less than zero");
        }
        top = NULL;
        count = 0;
        this->capacity = capacity;
    }

    ~DynamicStack(){
        purgeStack();
    }

    int getSize(){
        return count;
    }
    int getCapacity(){
        return capacity;
    }

    bool empty() {
        return (top == NULL);
    }

    TBD getTop(){
        if (top == NULL){
            throw underflow_error("Stack is Empty!!!");
        }
        return top->item;
    }

    void push(TBD newItem){

        //use capacity of zero to indicate unlimited
        if (capacity != 0 && count == capacity){
            throw overflow_error("Stack is at capacity!!!");
        }
        //insert at the head
        cout<< "Adding " <<newItem <<" to top of stack. "<<endl;
        Node* temp = new Node(newItem);
        temp->next = top;
        top = temp;

        count++;
        //end of insert;
    }
    void pop(){
        if (top == NULL) {
            throw underflow_error("Stack is Empty!!!");
        }
        cout<<"Deleting " <<top->item << " from stack "<<endl;
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    TBD printStack(){
        Node* current = top;

        //iterate until we reach of the list;
        while (current != NULL){
            return current->item;
            current = current->next;
        }
    }

    void purgeStack(){
        Node* current = top;
        Node* temp;

        //iterate until we reach end of list
        while (current != NULL){
            temp = current;
            current = current->next;

            cout<<"Deleting "<<temp->item <<endl;
            delete temp;
        }
        count = 0;
    }


};

