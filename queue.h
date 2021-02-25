#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class TBD>
class dynamicQueue {
private:
    struct Node {
        TBD item;
        Node* next;

        Node(TBD item){
            this->item = item;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int count;
    int capacity;

public:
    //capacity of zero means unlimited
    dynamicQueue(int capacity = 0){
        if (capacity < 0){
            throw invalid_argument("capacity cannot be less than zero");
        }
        head = NULL;
        tail = NULL;
        count = 0;
        this->capacity = capacity;
    }

    //copy constructor
    dynamicQueue(const dynamicQueue& other){
        cout <<"copy constructor called" <<endl;
        purgeQueue();
        head = NULL;
        tail = NULL;
        count = other.count;
        capacity = other.capacity;

        if (other.head != NULL){
            Node* otherPtr = other.head;
            Node* last = new Node (otherPtr->item);
            head = last;
            tail = last;

            while (otherPtr->next != NULL) {
                otherPtr = otherPtr->next;
                Node* temp = new Node(otherPtr->item);
                tail->next = temp;
                tail = tail->next;
            }
        }
    }

    dynamicQueue& operator=(const dynamicQueue& other){
        cout <<"Assignmengt operator called" <<endl;
        return *this;
    }
    ~dynamicQueue(){
        purgeQueue();
    }
    int getSize(){
        return count;
    }
    int getCapacity(){
        return capacity;
    }
    bool empty(){
        return (head == NULL);
    }
    bool full(){
        return (count == capacity);
    }
    TBD getHead(){
        if (head == NULL){
            throw underflow_error("Queue is empty!!!");
        }
        return head->item;
    }
    TBD getTail(){
        if (tail == NULL){
            throw underflow_error("queue is empty!!!");
        }
        return tail->item;
    }
    void push(TBD newItem){
        //use capacity of zero to indicate unlimited
        if (capacity != 0 && count == capacity){
            throw overflow_error("queue is at capacity!!!");
        }
        //insert at the head;

        if (head == NULL){
            cout <<"adding " <<newItem << " to the start of queue" <<endl;
            Node* temp = new Node(newItem);
            head = temp;
            tail = temp;
        } else{
            cout <<"adding "<<newItem <<" to end of queue" <<endl;
            Node* temp = new Node(newItem);
            tail->next = temp;
            tail = tail->next;
        }
        count++;
    }

    void pop(){
        if (head == NULL){
            throw underflow_error("queue is empty!!!");
        }
        cout <<"deleting "<<head->item <<"from queue" <<endl;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    TBD printQueue(){
        Node* current = head;

        //iterate until we reach end of list
        while (current != NULL){
            return current->item;
            current = current->next;
        }
    }
    void purgeQueue(){
        Node* current = head;
        Node* temp;

        //iterate until we reach end of list
        while (current != NULL){
            temp = current;
            current = current->next;

            cout <<"deleting " <<temp->item <<endl;
            delete temp;
        }
        count = 0;
        head = NULL;
        tail = NULL;
    }



};
