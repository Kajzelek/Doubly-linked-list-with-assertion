// Two-way_List_with_assertion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main(string fileName, string type)
{
    /*
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

    
    */
 

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
            el* tmp = new el(a);
            if (!head) {
                head = tail = tmp;
            }
            else {
                tmp->next = head;
                head->previous = tmp;
                head = tmp;
            }
  
            return tmp;
        }

        el* addTail(int a) {
            el* tmp = new el(a);
            if (!head) {
                head = tail = tmp;
            }
            else {
                tail->next = tmp;
                tmp->previous = tail;
                tail = tmp;
            }
            
            return tmp;   
        }

        el* removeHead(){

            if (!head) {
                return nullptr;
            }

            el* tmp = head;

            if (head = tail) {
                head = tail = nullptr;
            }
            else {
                head = head->next;
                head->previous = nullptr;
            }

            delete tmp;
            return head;
        }

        el* removeTail() {
            el* tmp = tail;

            if (!head) {
                return nullptr;
            }

            if (head = tail) {
                head = tail = nullptr;
            }
            else {
                tail = tail->previous;
                tail->next = nullptr;
            }
            
            delete tmp;
            return tail;
        }

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
            el* tmp = head;
            while (tmp) {
                if (tmp->v == a) {
                    if (tmp == head) {
                        removeHead();
                        tmp = head;
                    }
                    else if (tmp = tail) {
                        removeTail();
                        tmp = nullptr;
                    }
                    else {
                        tmp = tmp->next;
                        if (tmp->v = a) {
                            tmp->next->previous = tmp->previous;
                            tmp->previous->next = tmp->next;
                            el* toDelete = tmp;
                            tmp = tmp->next;
                            delete toDelete;
                        }
                    }
                }
                else {
                    tmp = tmp->next;
                }
            }
            return head;
        }
        void removeList() {
            while (head){
                el* tmp = head;
                head->next = tmp;
                delete tmp;
            }
            tail = nullptr;
        }
        void showRightToLeft() {
            el* tmp = tail;
            while (tmp) {
                cout << tmp->v << " ";
                tmp = tmp->previous;
            }
            cout << endl;
        }
        void showLeftToRight() {
            el* tmp = head;
            while (tmp) {
                cout << tmp->v << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
        void swap(el*& tmp, el*& k) {
            int temp = tmp->v;
            tmp->v = k->v;
            k->v = temp;
        }

    };


    List lista1;
    lista1.add(1);
    lista1.add(3);
    lista1.add(2);
    lista1.add(9);
    lista1.add(8);
    lista1.add(19);
    lista1.add(7);
    lista1.add(3);
    lista1.add(10);
    lista1.add(3);

    lista1.showRightToLeft();
    lista1.showLeftToRight();

    lista1.removeValue(3);

    lista1.showLeftToRight();




}