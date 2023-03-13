#include <iostream>
#include "List.h"
#include "OList.h"

int main(){
    List *l = new List();

    OList *ol = new OList();

    // std::cout << ol->toString() <<  " "  <<  std::endl;
    std::cout << "--- Ordered List ---\n";
    std::cout << "Before Reverse:\n";
    ol->insert("test");
    ol->insert("choc");
    ol->insert("zed");
    ol->insert("astro");
    ol->insert("delphine");
    ol->insert("octopus");
    ol->insert("anticipate");
    ol->insert("zz");

    std::cout << ol->toString() <<  " " <<  std::endl;
    std::cout << "Getting Index 1 Element: " << ol->get(1) << std::endl;
    std::cout << "Contains zed: " << ol->contains("zed") << std::endl;
    std::cout << "Removing Index 2 Element\n";
    ol->remove(2);
    std::cout << ol->toString() <<  " " <<  std::endl;

    std::cout << "Reversed:\n";
    ol->reverse();
    std::cout << ol->toString() <<  " " <<  std::endl;
    
    delete ol;

    return 0;
}