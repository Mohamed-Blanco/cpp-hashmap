//
// Created by luftwaffe on 5/14/26.
//
#ifndef HASHMAPC___HASHTABLE_H
#define HASHMAPC___HASHTABLE_H
#include <vector>
#include <string>
#include <optional>

class HashTable
{
public:
    [[nodiscard]] bool isEmpty() const ;
    int hashFunction(int key) const ;
    void insertItem(int key,std::string value); //its dangerous to use string_visew here because
    //what if we inserted an string that goes out of scope later.
    
    void removeItem(int key);
    std::optional<std::string> searchItem(int key);
    void printHashTable();
    bool doesExists(int key); 

    std::string& operator[](int key);
    

private:
    static const int m_hashGroups {10};
    std::vector<std::pair<int,std::string>> table[m_hashGroups];

    
};




#endif //HASHMAPC___HASHTABLE_H