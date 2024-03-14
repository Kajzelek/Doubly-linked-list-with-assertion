// Two-way_List_with_assertion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main(string fileName, string type)
{
    vector<int> numbers;
    ifstream inputFile("liczby.txt");

    if (inputFile.good()) {
        int current_number = 0;
        while (inputFile >> current_number) {
            numbers.push_back(current_number);
        }

        inputFile.close();

        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << endl;
        }

        cout << endl;

    }
    else {
        cout << "Error!";
        _exit(0);
    }

    
    

    struct el {
        int v;
        el* next;
        el* previous;
        el();
        el(int v);
        virtual ~el();
    };


    class List {
        el* head;
        el* tail;
        el* addHead(int a) {
        }
        el* addTail(int a);
        el* removeHead();
        el* removeTail();

    public:
        List() {
            head = NULL;
            tail = NULL;
        }
        virtual ~List() {
            while (head) {
                el* tmp = head;
                head = head->next;
                delete tmp;
            }
            tail = nullptr;
        }
        el* add(int a) {
            return addTail(a);
        }

        el* removeValue(int a) {

        }
        void removeList();
        void showRightToLeft();
        void showLeftToRight();
        void swap(el* &tmp, el* &k);

    };
}

