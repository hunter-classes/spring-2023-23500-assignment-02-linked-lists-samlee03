#include <iostream>
#include "List.h"
#include "OList.h"

int main(){
    List *l = new List();

    OList *ol = new OList();

    ol->insert("test");
    ol->insert("choc");
    ol->insert("zed");
    ol->insert("astro");
    ol->insert("delphine");
    ol->insert("octopus");
    ol->insert("anticipate");
    // ol->insert("zz");
    // if ("zed" < "test"){
    //     std::cout << "less than\n";
    // }
    std::cout << ol->toString() <<  " " << ol->contains("test") <<  std::endl;

    // std::cout << ol->get(3) << std::endl;
    // ol->remove(3);
    ol->reverse();
    std::cout << ol->toString() <<  " " << ol->contains("test") <<  std::endl;


    // std::cout << l->toString() << " " << l->length() <<  "\n";
    // l->insert(0, "data1");
    // std::cout << l->toString() << " " << l->length() <<  "\n";
    // l->insert(1, "data2");
    // std::cout << l->toString() << " " << l->length() <<  "\n";
    // std::cout << l->contains("data2") << "\n";
    // l->remove(1);
    // std::cout << l->toString() << " " << l->length() <<  "\n";
    // std::string str1, str2;
    // str1 = "a";
    // str2 = "b";

    // if (str1 < str2){
    //     std::cout << "a is smaller than b" << std::endl;
    // } else {
    //     std::cout << "b is smaller than a" << std::endl;
    // }
    return 0;
}