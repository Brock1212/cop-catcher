#ifndef HASHTABLE_3358_H_
#define HASHTABLE_3358_H_
#include<iostream>
#include<vector>
using namespace std;

class HashTable_3358
{
public:
/****************************
constructor: Initializes hash table to a predetermined size.
*****************************/
HashTable_3358 ( );
/****************************
makeEmpty: Removes all the items from the hash table.
*****************************/
void makeEmpty();
/****************************
find: Returns true if s is in the hash table, else false.
*****************************/
bool find(string s) const;
/****************************
insert: Adds the string to the hash table, if it is not
already there. (If the hash table becomes 50% full, it rehashes.)
*****************************/
void insert (string s);

int getSize();

private:
int hash(string) const;
int probing(string) const;
void rehashing();
bool isPrime(int number);
int nextPrime (int number);
vector <string> hashtable;
unsigned int used;
};



#endif /* HASHTABLE_3358_H_ */
