//
// Created by luftwaffe on 5/14/26.
//

#include "HashTable.h"
#include <vector>
#include <iterator>
#include <iostream> 
#include <optional>

// O(hashGroups) check
bool HashTable::isEmpty() const
{
    int sum{};
    for (int i {};i < m_hashGroups ; ++i)
    {
        sum+= std::size(table[i]);
    }

    if (sum == 0) return true;
    return false;
}


int HashTable::hashFunction(int key) const
{
    return key%m_hashGroups; // simple hash function not the actual one
}

void HashTable::insertItem(int key, std::string value)
{

    int hashValue = hashFunction(key);
 
    auto& cell = table[hashValue];
    
    auto beginP = begin(cell); 
    bool keyExists {};

    while(beginP != end(cell))
    {
        if(beginP->first == key)
        {
            keyExists = true ; 
            beginP->second = value; 
            std::cout << "[WARNING The Key "<< key <<" << Already Exists]. \n"; 
            break; 
        }
        ++beginP; 
    }
    
    if(!keyExists)
    {
        cell.emplace_back(key,value); 
    } 
}


void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto beginP = begin(cell); 

    while(beginP != end(cell))
    {
        if(beginP->first == key)
        {
            beginP = cell.erase(beginP);
            std::cout << "[INFO] Pair removed. \n";  
            return ; 
        }
        ++beginP; 
    }
    
    std::cout << "[WARNING] Pair was not present in the HashTable. \n";  
}

std::optional<std::string>  HashTable::searchItem(int key)
{
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto beginP = begin(cell); 

    while(beginP != end(cell))
    {
        if(beginP->first == key)
        {
            return beginP->second; 
        }
        ++beginP; 
    }
    
    std::cout << "[WARNING] Pair was not present in the HashTable. \n"; 
    return std::nullopt; 
}

void HashTable::printHashTable()
{

    for(int i{}; i < m_hashGroups ; ++i)
    {
        if(table[i].size() != 0)
        {
            auto beginP = begin(table[i]); 
            while(beginP != end(table[i]))
            {
                std::cout << "[INFO] Key : " << beginP->first << " , Value : " << beginP->second << "\n";
                ++beginP; 
            }
        }
    }
}

bool HashTable::doesExists(int key)
{

    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto beginP = begin(cell); 

    while(beginP != end(cell))
    {
        if(beginP->first == key)
        {
            std::cout << "[The Key "<< key <<" << Already Exists]. \n"; 
            return true;
        }
        ++beginP;
    }
    
    return false ;  
}


std::string& HashTable::operator [](int key)
{
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto beginP = begin(cell); 

    while(beginP != end(cell))
    {
        if(beginP->first == key)
        {
            return beginP->second; 
        }
        ++beginP; 
    }
    
    //treating the non existing case : 
    return cell.emplace_back(key,"").second; 
    
}