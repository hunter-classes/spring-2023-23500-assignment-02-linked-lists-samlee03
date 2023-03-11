#include <iostream>
#include "Node.h"
#include "OList.h"

OList::OList(){
    head = nullptr;
}

OList::~OList(){
    head = nullptr;
}

void OList::insert(std::string value){
    Node *walker, *trailer;
    walker = this->head;
    trailer = nullptr;

    // return;
    Node *newNode = new Node(value);
    if (head == nullptr){ // First Item
        // head->setNext(newNode);
        newNode->setNext(head);
        head = newNode;
        return;
    }

    // if (trailer == nullptr){
    //     newNode->setNext(head);
    //     head->setNext(newNode);
    // }

    while (walker != nullptr){
        // std::cout << "This runs";
        if ((newNode->getData() < walker->getData()) && trailer == nullptr){ // Less than first item
            newNode->setNext(walker);
            head = newNode;
            return;
        }

        // if (trailer == nullptr && (newNode->getData() < walker->getData())){
        //     newNode->setNext(head);
        //     head->setNext(newNode);
        // }
        if (trailer != nullptr && (newNode->getData() < walker->getData())){
            trailer->setNext(newNode);
            newNode->setNext(walker);
            return;
        }

        trailer = walker;
        walker = walker->getNext();
        // return;
    }
    trailer->setNext(newNode);
    newNode->setNext(walker);
    // newNode->setNext(head);
    // head = newNode;
    return;
}

std::string OList::toString(){
    Node *tmp = this->head;
    std::string result = "head --> ";
    while (tmp != nullptr){
        result = result + tmp->getData();
        result = result + " --> ";
        tmp = tmp->getNext();
    }
    result = result + "nullptr";
    return result;
}

bool OList::contains(std::string value){
    Node *tmp = this->head;
    while (tmp != nullptr){
        if (tmp->getData() == value){
            return true;
        }
        tmp = tmp->getNext();
    }
    return false;
}

std::string OList::get(int loc){
    Node *walker = this->head;
    // trailer = nullptr;
    
    // int c = loc;
    while (loc > 0){
        // trailer = walker;
        walker = walker->getNext();
        loc--;
    }

    return walker->getData();
}

void OList::remove(int loc){
    Node *walker, *trailer;
    walker = this->head;
    trailer = nullptr;

    while (loc > 0){
        trailer = walker;
        walker = walker->getNext();
        loc--;
    }
    if (walker == nullptr){
        throw std::out_of_range("Tried to remove out of range");
    }
    if (trailer == nullptr){
        this->head = walker->getNext();
        delete walker;
        walker = nullptr;
    } else {
        trailer->setNext(walker->getNext());
        delete walker;
        walker = nullptr;
    }
    return;
}

void OList::reverse(){
    Node *tmp, *tmp1, *walker, *trailer; // tmp represents (unreversed) head of ordered list
    tmp = this->head;
    tmp1 = tmp;
    walker = this->head;
    trailer = nullptr;
    // Find last element
    while (walker->getNext() != nullptr){ // walker points to last element
        trailer = walker;
        walker = walker->getNext();   
    }
    this->head = walker; // New Head

    while (tmp->getNext() != trailer){ // Last set of switch
        walker->setNext(trailer);

        while (tmp1->getNext() != trailer){ // Finds the previous element to trailer
            tmp1 = tmp1->getNext();
        }
        //Manipulate pointers
        walker = trailer;
        trailer = tmp1;
        tmp1 = tmp;
    }
    walker->setNext(trailer);
    trailer->setNext(tmp);
    tmp->setNext(nullptr);
    // walker->setNext(trailer);

    // Manipulate pointers
    // walker = trailer;
    // trailer
    
    return;
}