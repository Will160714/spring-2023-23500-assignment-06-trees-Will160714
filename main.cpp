#include "BSTree.h"

int main(){
    BSTree* test = new BSTree;
    bool works = true;

    //Recursive Search
    std::cout << "Searching for a non-existent value\n";
    try{
        test -> rsearch(0);
    }
    catch(int e){
        std::cout << "Value not found in the tree\n" << std::endl;
    }

    std::cout << "Searching for a existent value\n";
    test -> insert(100);
    if(test -> rsearch(100) == 100)
        std::cout << "Successful" << std::endl;
    std::cout << std::endl;

    //Recursive Insert
    std::cout << "Recursive Insert" << std::endl;
    test = new BSTree();
    test -> insert(100);
    std::cout << "Original State: " << test -> get_debug_string() << std::endl;
    test -> insert(50);
    test -> insert(150);
    std::cout << "After State: " << test -> get_debug_string() << "\n\n";

    //Delete
    std::cout << "Deletion" << std::endl;
    test = new BSTree();
    test -> insert(100);
    test -> insert(50);
    test -> insert(150);
    test -> insert(110);
    test -> insert(200);
    test -> insert(0);
    test -> insert(75);
    std::cout << "Removal of No Children Node" << std::endl;
    std::cout << "Before: " << test -> get_debug_string() << std::endl;
    test -> deletion(200);
    std::cout << "After: " << test -> get_debug_string() << "\n\n";
    
    std::cout << "Removal of 1 Children Node" << std::endl;
    std::cout << "Before: " << test -> get_debug_string() << std::endl;
    test -> deletion(150);
    std::cout << "After: " << test -> get_debug_string() << "\n\n";

    std::cout << "Removal of 2 Children Node" << std::endl;
    std::cout << "Before: " << test -> get_debug_string() << std::endl;
    test -> deletion(50);
    std::cout << "After: " << test -> get_debug_string() << "\n\n";

    //Leaves
    std::cout << "Count Leaves of BSTree" << std::endl;
    test = new BSTree();
    test -> insert(100);
    test -> insert(50);
    test -> insert(150);
    test -> insert(0);
    std::cout << "Tree: " << test -> get_debug_string() << std::endl;
    std::cout << "Leaves: " << test -> leaves() << "\n\n";

    //Height
    std::cout << "Height of BSTree (root is 1)" << std::endl;
    test -> insert(100);
    test -> insert(50);
    test -> insert(150);
    test -> insert(25);
    test -> insert(75);
    test -> insert(200);
    test -> insert(300);
    test -> insert(250);
    test -> insert(400);
    std::cout << "Tree: " << test -> get_debug_string() << std::endl;
    std::cout << "Height: " << test -> height() << "\n\n";

    //Sum at Any Given Level
    std::cout << "Sum at Any Given Level (root is 1)" << std::endl;
    std::cout << "Tree: " << test -> get_debug_string() << std::endl;
    std::cout << "Sum at an Invalid Level: " << test -> sumLevel(-1) << std::endl;
    std::cout << "Sum at Root: " << test -> sumLevel(1) << std::endl;
    std::cout << "Sum at Level 2: " << test -> sumLevel(2) << std::endl;
    std::cout << "Sum at an Over Level: " << test -> sumLevel(100) << std::endl;
}