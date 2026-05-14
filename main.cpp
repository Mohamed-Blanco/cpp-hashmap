#include <iostream>
#include "HashTable.h"


int main()
{

    HashTable ht {}; 

    //testing the insert functionality
    ht.insertItem(908,"Mohamed");
    ht.insertItem(905,"Tom");
    ht.insertItem(902,"Hassan"); 
    ht.insertItem(999,"Mostapha"); 

    if(ht.isEmpty())
    {
        std::cout << "[Warning] The insert functionality is not working.\n"; 
    } 

    if(ht.searchItem(999) != "Mostapha")
    {
        std::cout << "[ERROR] The search is not working !\n"; 
    } else
    {
        std::cout << "[INFO] The search key : 999 Was found.\n"; 
    }

    ht.printHashTable(); 

    ht.removeItem(999); 
    ht.removeItem(905); 

    ht.printHashTable(); 

    if(ht.isEmpty())
    {
        std::cout << "[Warning] The insert functionality is not working.\n"; 
    } 
}