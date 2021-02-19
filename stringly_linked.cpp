#include "stringly_linked.h"

void SLinkedList::addFirst(const char* s){
    head = new Node(s, head);
}

Node* SLinkedList::addLast(const char* s){
    Node* newNode = new Node(s, nullptr);
    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* last = head;
        while(last->next != nullptr){
            last = last->next;
        }
        last->next = newNode;
    }
    return newNode;
}

void SLinkedList::print(){
    for( Node* p = head; p != nullptr; p = p->next ){
        cout << p->element << " " ;
    }
}

const char* SLinkedList::removeFirst(){
    const char* old_element = head->element;
    Node* old = head;
    head = head->next;
    delete old;
    return old_element;
}

Node* SLinkedList::insertAfter(const char* s, Node* node){
    Node* newNode = new Node(s, node->next);
    node->next = newNode;
    return newNode;
}

void SLinkedList::remove(Node* node){
    if(node == head){
        Node* old = head;
        head = head->next;
        delete old;
    }
    else{
        Node* p = head;
        while(p->next != node && p!=nullptr){
            p = p->next;
        }
        p->next = node->next;
        delete node;
    }
}

Node* SLinkedList::search(const char* s, Node* node){
    Node* p = head;
    if(p->element == s) return p;
    if(p == nullptr) return nullptr;
    return search(s, node->next);
}

void SLinkedList::free(Node* node){
    if(node != nullptr){
        free(node->next);
        delete node;
    }
}

void SLinkedListWithTail::addFirst(const char* s){
    head = new Node(s, head);
    if(tail == nullptr){
        tail = head;
    }
}

void SLinkedListWithTail::addLast(const char* s){
    Node* newNode = new Node(s, NULL);
    if(head == nullptr){
        head = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void SLinkedListWithTail::print(){
    for( Node* p = head; p != nullptr; p = p->next ){
        cout << "(" << p->element << ")" ;
    }
}

void SLinkedListWithTail::removeLast(){
    if (head != tail){
        Node* p = head;
        while(p->next != tail){
            p = p->next;
        }
        delete tail;
        tail = p;
        tail->next = nullptr;
    }
    else {
        if (head != nullptr){
            delete head;
            head = nullptr;
            tail = nullptr;
        }
    }
}

void SLinkedListWithTail::removeFirst(){
    Node* old = head;
    head = head->next;
    delete old;
}
