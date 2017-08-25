#include "HashTable_3358.h"

//***********************************************************
// HashTable_3358::HashTable_3358():constructor that sets hashtable size
// to 101 and makes it empty
// returns: nothing, void
//***********************************************************
HashTable_3358::HashTable_3358()
{
	hashtable.resize(101);
	makeEmpty();
}

//***********************************************************
// void HashTable_3358::makeEmpty(): makes hashtable empty
//
// returns: nothing, void
//***********************************************************
void HashTable_3358::makeEmpty()
{
	for (unsigned int i = 0; i < hashtable.size(); ++i)
		hashtable[i] = "EMPTY";
	used = 0;
}

//***********************************************************
// bool HashTable_3358:: find(string s) const: looks for string
// given in hashtable
//
// param-1 s: string being searched for
// returns: true if found
//***********************************************************
bool HashTable_3358:: find(string s) const
{
	int position = probing(s);
	if (hashtable[position] == s)
		return true;
	else
	    return false;
}

//***********************************************************
// void HashTable_3358:: insert (string s):: puts string in hashtable
//
// param-1 s: string to be put in hashtable
// returns: nothing, void
//***********************************************************
void HashTable_3358:: insert (string s)
{
	int index = probing(s);
	if (hashtable[index] == "EMPTY" )
	{
		 hashtable[index] = s;
		 if (++used > hashtable.size()/2)
		 		rehashing();
	}
}

//***********************************************************
// int HashTable_3358::hash(string key) const: gives string a
// numerical value to be used for storing
//
// param-1 key: string being hashed
// returns: hash value in table
//***********************************************************
int HashTable_3358::hash(string key) const
{
	int hashval = 0;

	for (unsigned int i = 0; i < key.length(); ++i)
		hashval = 37 * hashval + key[i];

	return hashval % hashtable.size();
}

//***********************************************************
// int HashTable_3358::probing(const string key) const: uses hash value
// to find an available place in table to put string
//
// param-1 key: string to be put in table
// returns: final place in table for string to be inserted
//***********************************************************
int HashTable_3358::probing(const string key) const
{
	int i = 0;
    unsigned int position = hash(key);

	while (hashtable[position] != "EMPTY" && hashtable[position] != key)
	{
		position += 2 * ++i - 1;
		if (position >= hashtable.size())
			position -= hashtable.size();
	}
	return position;
}

//***********************************************************
// void HashTable_3358::rehashing(): resises hashtable to next
// available prime and inserts values.
//
// returns: nothing, void
//***********************************************************
void HashTable_3358::rehashing()
{
	vector <string> oldtable(hashtable);

	hashtable.resize(nextPrime(2 * oldtable.size()));
	for (unsigned int i = 0; i < hashtable.size(); ++i)
		hashtable[i] = "EMPTY";

	makeEmpty();
	for (unsigned int i = 0; i < oldtable.size(); i++)
	{
		if (oldtable[i] != "EMPTY")
			insert(oldtable[i]);
	}
}

//***********************************************************
// bool HashTable_3358::isPrime(int number): says if number is prime
//
// param-1 number: number being checked
// returns: true if prime
//***********************************************************
bool HashTable_3358::isPrime(int number)
{
int i;
	for (i=2; i<number/2; i++)
	{
	  if (number % i == 0)
	   {
		 return false;
	   }
	}
	return true;
}

//***********************************************************
// int HashTable_3358::nextPrime (int number): looks for next prime
//
// param-1 number: previous prime number
// returns: next prime number
//***********************************************************
int HashTable_3358::nextPrime (int number)
{
	int x = number+1;
	while (!isPrime(x))
     x++;

	return x;
}

//***********************************************************
// int HashTable_3358::getSize(): returns number of used slots in table
//***********************************************************
int HashTable_3358::getSize()
{
	return used;
}
