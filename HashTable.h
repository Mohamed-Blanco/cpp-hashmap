//
// Created by luftwaffe on 5/14/26.
//
#ifndef HASHMAPC___HASHTABLE_H
#define HASHMAPC___HASHTABLE_H
#include <vector>
#include <string>

class HashTable
{
public:
    [[nodiscard]] bool isEmpty() const ;
    int hashFunction(int key);
    void insertItem(int key,std::string_view value);
    void removeItem(int key);
    std::string_view searchItem(int key);
    void printHashTable();
    bool doesExists(int key); 
private:
    static const int m_hashGroups {10};
    std::vector<std::pair<int,std::string_view>> table[m_hashGroups];

    
};




#endif //HASHMAPC___HASHTABLE_H