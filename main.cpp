#include <iostream>
#include "stringly_linked.h"

using namespace std;

int main(){
    SLinkedList* list = new SLinkedList();

    list->addFirst("hiep");
    Node* s = list->addLast("uet");
    list->addLast("tran duong");
    list->insertAfter("nbk", s);
    list->print();
    cout << endl;
    list->remove(s);
    list->print();
    cout << endl;
    Node* a = list->search("hiep");
    cout << a->element ;
    delete list;
    list->print();
    return 0;
}
