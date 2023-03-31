// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

class Node {
    private:
        int data;
        Node* next;
    public:
        Node(int x = 0) {
            data = x;
            next = NULL;
        }
        int getData() {
            return data;
        }
        void setData(int x) {
            data = x;
        }
        Node* getNext() {
            return next;
        }
        void setNext(Node* p) {
            next = p;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
        }
        Node* getHead() {
            return head;
        }
        Node* getTail() {
            return tail;
        }

        // define operator + to add new node to the end of the list
        LinkedList operator+(int x) {
            Node* new_node = new Node(x);
            if (tail == NULL) {
                head = tail = new_node;
            }
            else {
                tail->setNext(new_node);
                tail = new_node;
            }
            return *this;
        }
        // define operator += to add new node to the end of the list
        LinkedList operator+=(int x) {
            return operator+(x);
        }
        
        void addHead(int x) {
            Node* new_node = new Node(x);
            if (head == NULL) {
                head = tail = new_node;
            }
            else {
                new_node->setNext(head);
                head = new_node;
            }
        }
        void addTail(int x) {
            Node* new_node = new Node(x);
            if (tail == NULL) {
                head = tail = new_node;
            }
            else {
                tail->setNext(new_node);
                tail = new_node;
            }
        }
        void addAfter(Node* index, int x) {
            Node* new_node = new Node(x);
            if (index == NULL) {
                head = tail = new_node;
            }
            else {
                new_node->setNext(index->getNext());
                index->setNext(new_node);
            }
        }
        void addAt(int x, int k) {
            Node* p = new Node(x);
            if (k == 0) {
                p->setNext(head);
                head = p;
            }
            else {
                Node* q = head;
                for (int i = 0; i < k - 1; i++) {
                    q = q->getNext();
                }
                p->setNext(q->getNext());
                q->setNext(p);
            }
        }
        void removeHead() {
            if (head == NULL) {
                return;
            }
            else if (head == tail) {
                delete head;
                head = tail = NULL;
            }
            else {
                Node* temp = head;
                head = head->getNext();
                delete temp;
            }
        }
        // method to find first node with data = x
        Node* findX(int x) {
            Node* p = head;
            while (p != NULL) {
                if (p->getData() == x) {
                    return p;
                }
                p = p->getNext();
            }
            return NULL;
        }
        // method to print all nodes
        void print() {
            Node* p = head;
            while (p != NULL) {
                cout << p->getData() << " ";
                p = p->getNext();
            }
            cout << endl;
        }
};


#endif