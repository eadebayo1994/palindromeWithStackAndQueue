/*
 * Emmanuel Adebayo
 * 2/23/21
 * main.cpp
 * priority quueue with linked list
 *//*
 * Emmanuel Adebayo
 * 2/23/21
 * main.cpp
 * a palindrome program that uses queue and stack
 */
#pragma once
#include <iostream>
#include <string>
#include "queue.h"
#include "stack.h"
using namespace std;

void readLineOfText(string text){

    dynamicQueue<char>palindromeQueue;
    DynamicStack<char>palindromeStack;

    for (int i = 0; i < text.length(); i++) {
        putchar(toupper(text[i]));

        palindromeQueue.push(putchar(toupper(text[i])));
        palindromeStack.push(putchar(toupper(text[i])));

    }

    for (int i = 0; i < 1; ++i) {
        if (palindromeQueue.printQueue() == palindromeStack.printStack()){
            cout<<"yes" <<endl;
        }
        else {
            cout <<"nah"<<endl;
        }
    }


}

int main() {
    readLineOfText("racecar");
    readLineOfText("redivider");
    return 0;
}
