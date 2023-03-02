#include <iostream>
#include "List.h"

int main(){
    List *l = new List();
    std::cout << l->toString() << " " << l->length() <<  "\n";
    l->insert(0, "data1");
    std::cout << l->toString() << " " << l->length() <<  "\n";
    l->insert(1, "data2");
    std::cout << l->toString() << " " << l->length() <<  "\n";
    std::cout << l->contains("data2") << "\n";
    l->remove(1);
    std::cout << l->toString() << " " << l->length() <<  "\n";

    return 0;
}