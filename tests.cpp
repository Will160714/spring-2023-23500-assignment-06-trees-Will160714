#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

TEST_CASE("Recursive Insert"){
    BSTree* test = new BSTree();
    test -> insert(10);
    CHECK(test -> get_debug_string() == ", 10, ");
    test -> insert(0);
    test -> insert(10);
    test -> insert(-5);
    CHECK(test -> get_debug_string() == ", -5, , 0, , 10, ");
}


TEST_CASE("Recursive Search"){
    BSTree* test = new BSTree();
    test -> insert(0);
    test -> insert(-5);
    test -> insert(10);
    test -> insert(20);
    CHECK(test -> rsearch(-5));
    CHECK(test -> rsearch(0) == 0);
    CHECK(test -> rsearch(10) == 10);
    bool works = true;
    try{
        test -> rsearch(15);
    }
    catch(int e){
        works = false;
    }
    CHECK(works == false);
}

TEST_CASE("Deletion"){
    BSTree* test = new BSTree();
    //Not Found
    bool works = true;
    try{
        test -> deletion(0);
    }
    catch(int e){
        works = false;
    }

    CHECK(works == false);
    
    //Leaf
    test -> insert(30);
    test -> deletion(30);
    CHECK(test -> get_debug_string() == "");
    test -> insert(30);
    test -> insert(10);
    test -> deletion(10);
    CHECK(test -> get_debug_string() == ", 30, ");
    test -> insert(50);
    test -> deletion(50);
    CHECK(test -> get_debug_string() == ", 30, ");

    //1 Child
    test -> insert(10);
    test -> deletion(30);
    CHECK(test -> get_debug_string() == ", 10, ");
    test -> insert(30);
    test -> insert(20);
    test -> deletion(10);
    CHECK(test -> get_debug_string() == ", 20, , 30, ");
    test -> insert(5);
    test -> deletion(20);
    CHECK(test -> get_debug_string() == ", 5, , 30, ");

    //2 Children
    test = new BSTree();
    test -> insert(50);
    test -> insert(25);
    test -> insert(75);
    test -> deletion(50);
    CHECK(test -> get_debug_string() == ", 25, , 75, ");

    test = new BSTree();
    test -> insert(50);
    test -> insert(25);
    test -> insert(75);
    test -> insert(15);
    test -> insert(35);
    test -> insert(65);
    test -> insert(85);
    test -> deletion(75);
    CHECK(test -> get_debug_string() == ", 15, , 25, , 35, , 50, , 65, , 85, ");
    test -> deletion(25);
    CHECK(test -> get_debug_string() == ", 15, , 35, , 50, , 65, , 85, ");
}

TEST_CASE("Leaves"){
    BSTree* test = new BSTree();
    CHECK(test -> leaves() == 0);
    test -> insert(50);
    CHECK(test -> leaves() == 0);
    test -> insert(25);
    test -> insert(75);
    test -> insert(85);
    CHECK(test -> leaves() == 3);
}

//Root is 1
TEST_CASE("Height"){
    BSTree* test = new BSTree();
    CHECK(test -> height() == 0);
    test -> insert(50);
    CHECK(test -> height() == 1);
    test -> insert(25);
    test -> insert(75);
    CHECK(test -> height() == 2);
    test -> insert(15);
    test -> insert(35);
    test -> insert(45);
    CHECK(test -> height() == 4);
    test -> insert(85);
    test -> insert(100);
    test -> insert(84);
    test -> insert(80);
    test -> insert(79);
    CHECK(test -> height() == 6);
}

TEST_CASE("Sum at Level"){
    BSTree* test = new BSTree();
    test -> insert(100);
    CHECK(test -> sumLevel(1) == 100);
    test -> insert(50);
    test -> insert(150);
    CHECK(test -> sumLevel(2) == 200);
    test -> insert(25);
    CHECK(test -> sumLevel(3) == 25);
    test -> insert(125);
    test -> insert(175);
    CHECK(test -> sumLevel(3) == 325);
    CHECK(test -> sumLevel(10) == 0);
}