#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"
#include "OList.h"
#include "Node.h"

TEST_CASE("OList insert() routine"){
    OList *ol = new OList();
    // Check whether ol is empty
    CHECK(ol -> toString() == "head --> nullptr");
    // Insertion
    ol -> insert("apple"); // First Item
    CHECK(ol -> toString() == "head --> apple --> nullptr");
    ol -> insert("aaron"); // Item before First
    CHECK(ol -> toString() == "head --> aaron --> apple --> nullptr");
    ol -> insert("cat"); // Item last
    CHECK(ol ->toString() == "head --> aaron --> apple --> cat --> nullptr");
    ol -> insert("dog"); 
    CHECK(ol -> toString() == "head --> aaron --> apple --> cat --> dog --> nullptr");

    // IN between insert
    ol -> insert("ball");
    CHECK(ol -> toString() == "head --> aaron --> apple --> ball --> cat --> dog --> nullptr");
    delete ol;
    ol = nullptr;
    CHECK(ol == nullptr);
}

TEST_CASE("Olist contains() routine"){
    OList *ol = new OList();
    // Insertion
    ol -> insert("apple"); 
    ol -> insert("aaron"); 
    ol -> insert("cat"); 
    ol -> insert("dog"); 
    ol -> insert("ball");

    CHECK(ol -> contains("random") == false);
    CHECK(ol -> contains("cat") == true);
    CHECK(ol -> contains("apple") == true);
    CHECK(ol -> contains("ball") == true );
}

TEST_CASE("Olist get() routine"){
    OList *ol = new OList();
    // Insertion
    ol -> insert("apple"); 
    ol -> insert("aaron"); 
    ol -> insert("cat"); 
    ol -> insert("dog"); 
    ol -> insert("ball");

    CHECK(ol -> get(0) == "aaron");
    CHECK(ol -> get(3) == "cat");
    CHECK(ol -> get(4) == "dog");

    delete ol;
    ol = nullptr;

}
TEST_CASE("OList remove() routine"){
    OList *ol = new OList();
    // Insertion
    ol -> insert("apple"); 
    ol -> insert("aaron"); 
    ol -> insert("cat"); 
    ol -> insert("dog"); 
    ol -> insert("ball");

    ol -> remove(0);
    CHECK(ol -> toString() == "head --> apple --> ball --> cat --> dog --> nullptr");
    ol -> remove(3);
    CHECK(ol -> toString() == "head --> apple --> ball --> cat --> nullptr");
    ol -> remove (1);
    CHECK(ol -> toString() == "head --> apple --> cat --> nullptr");

    delete ol;
    ol = nullptr;
}

TEST_CASE("OList reverse() routine"){
    OList *ol = new OList();
    // Insertion

    // Multiple Elements
    ol -> insert("apple"); 
    ol -> insert("aaron"); 
    ol -> insert("cat"); 
    ol -> insert("dog"); 
    ol -> insert("ball");

    ol -> reverse();
    CHECK(ol -> toString() == "head --> dog --> cat --> ball --> apple --> aaron --> nullptr");

    // One Element
    OList *ol2 = new OList();
    ol2 -> insert("ashley");
    ol2 -> reverse();
    CHECK(ol2 -> toString() == "head --> ashley --> nullptr");

    //Two Elements
    OList *ol3 = new OList();
    ol3 -> insert("ankle");
    ol3 -> insert("shoulder");
    ol3 -> reverse();
    CHECK(ol3 -> toString() == "head --> shoulder --> ankle --> nullptr");

    delete ol;
    delete ol2;
    delete ol3;
    ol = nullptr;
    ol2 = nullptr;
    ol3 = nullptr;
}

