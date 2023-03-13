// Code Taken from Class 
#include <iostream>
#include "Node.h"
#include "List.h"

List::List(){
    head = nullptr;
}


List::~List(){
    //delete head; // Delete head to release data?
    Node *walker = head;
    Node *trailer = nullptr;
    while (walker != nullptr){
        trailer = walker;
        walker = walker->getNext();
        delete trailer;
        trailer = nullptr;
    }
    std::cout << head << "\n";
}

void List::insert(std::string data){
    Node *tmp = new Node(data);
    tmp->setNext(head);
    head = tmp;
}

void List::insert(int loc, std::string data){
    Node *walker, *trailer;
    walker = this->head; // start of the list
    trailer = nullptr; // one behind

    while(loc>0 && walker != nullptr){
        loc=loc-1;
        trailer=walker;
        walker = walker->getNext();
    }
    if (loc > 0){
        throw std::out_of_range("Our insert is out of range");
    }

    Node *newNode = new Node(data);

    if (trailer == nullptr){
        // std::cout << "This runs";
        newNode->setNext(head);
        head = newNode;
    } else {
        // do the regular case 
        newNode->setNext(walker);
        trailer->setNext(newNode);
    }
}

void List::remove(int loc){
    Node *walker, *trailer;
    walker = this->head;
    trailer = nullptr;

    while (loc > 0){
        loc--;
        trailer = walker;
        walker = walker->getNext();
    }
    if (walker == nullptr){
        throw std::out_of_range("Tried to remove out of range"); 
    }
    if (trailer == nullptr){
        //removing the first item in the list
        head = walker->getNext();
        delete walker;
        walker = nullptr;
    } else {
        //general case
        trailer ->setNext(walker->getNext());
        delete walker;
        walker = nullptr;
    }
}

int List::length(){
    int count = 0;
    Node *walker = head;
    while (walker != nullptr){
        count++;
        walker = walker->getNext();
    }
    return count;
}

bool List::contains(std::string item){
    Node *walker = head;
    while (walker != nullptr){
        if (walker->getData() == item){
            return true;
        }
        walker = walker->getNext();
    }
    return false;
}

std::string List::toString(){
    Node *tmp = this->head;
    std::string result = "";
    while (tmp != nullptr){
        result = result + tmp->getData();
        result = result + "-->";
        tmp = tmp->getNext();
    }
    result = result + "nullptr";
    return result;
}