#ifndef stringly_linked.h
#define stringly_linked.h
#include <iostream>

using namespace std;

struct Node {
    const char* element;
    Node* next;

    Node(const char* e = nullptr, Node* n = nullptr){
        element = e;
        next = n;
    }
};

struct SLinkedList {

    Node* head;
    long size;

    SLinkedList() {
        head = nullptr;
    }

    void free(Node* node);

    ~SLinkedList(){
        free(head);
    }

    void addFirst(const char* s);
    Node* addLast(const char* s);
    void print();
    const char* removeFirst();
    Node* insertAfter(const char* s, Node* node);
    void remove(Node* node);
    Node* search(const char* key, Node* node);
    Node* search(const char* key){
        return search(key, head);
    }

};

struct SLinkedListWithTail {

    Node* head;
    Node* tail;

    SLinkedListWithTail() {
        head = nullptr;
        tail = nullptr;
    }

    void addFirst(const char* s);
    void addLast(const char* s);
    void print();
    void removeLast();
    void removeFirst();
};

#endif // stringly_linked
