// File Name: driver.cpp
//
// Author: Brock Yarbrough
// Date: 04/15/2015
// Assignment Number: 5
// CS 3358 Spring 2015
// Instructor: Jill Seaman
//
// Driver splits a file into n word sequences and stores them in a hashtable
// Then reads in another file and checks how many sequences it has in common by
// comparing the sequences to the ones already stored in the hashtable.

#include<iostream>
#include<fstream>
#include<vector>
#include"HashTable_3358.h"

using namespace std;

HashTable_3358 Table, Table2;

void listOfSequences( const int , ifstream &);

int sequenceComparisson( ifstream &, const int );

int main()
{
	string file1;
	string file2;
	int words_per_sequence;
	int copycat = 0;

	cout << "Please enter name of the first file to analyze: " << endl;
	cin >> file1;
	cout << "Please enter name of the second file to analyze: " << endl;
	cin >> file2;
	cout << "Please enter the number of words per sequence: " << endl;
	cin >> words_per_sequence;
	ifstream fin, fin2;
	fin.open(file1.c_str());
	fin2.open(file2.c_str());
	listOfSequences( words_per_sequence, fin);
	copycat = sequenceComparisson( fin2, words_per_sequence);
	cout << "Sequences in common: " << copycat << endl;

	fin.close();
	fin2.close();
	return 0;
}

//***********************************************************
// void listOfSequences(const int words_per_sequence, ifstream &fin)
// splits the file into n word sequences and stores into hashtable
//
// param-1 words_per_sequence: number of words per n word sequence
// param-2 fin: used to read from the file
// returns: nothing void
//***********************************************************
void listOfSequences( const int words_per_sequence, ifstream &fin)
{
	        string word;
			string line;
			int i = 0;
			int count = 0;
			int j = 0;
			while (!fin.eof())
			{
				count = 0;
				j = 0;
				line = "";
				while (j < i && !fin.eof())
				{
				   fin >> word;
				   ++j;
				}
				while ( count < words_per_sequence && !fin.eof())
				{
					fin >> word;
					line.append(word);
					line.append(" ");
					++count;
				}
				Table.insert(line);
				++i;
				if (!fin.eof())
				{
				  fin.clear();
				  fin.seekg(0, ios::beg);
				}
			}

}

//***********************************************************
// int sequenceComparisson(const int words_per_sequence, ifstream &fin)
// splits the file into n word sequences and compares with other file
//
// param-1 words_per_sequence: number of words per n word sequence
// param-2 fin: used to read from the file
// returns: number of sequences that are the same
//***********************************************************
int sequenceComparisson( ifstream &fin, const int words_per_sequence)
{
	    string word;
		string line;
		int i = 0;
		int count = 0;
		int j = 0;
		int common_sequences = 0;
		while (!fin.eof())
		{
			count = 0;
			j = 0;
			line = "";
			while (j < i && !fin.eof())
			{
			   fin >> word;
			   ++j;
			}
			while ( count < words_per_sequence && !fin.eof())
			{
				fin >> word;
				line.append(word);
				line.append(" ");
				++count;
			}
			if (!Table2.find(line))
			{
			  Table2.insert(line);
			  if (Table.find(line))
			   {
			     ++common_sequences;
			   }
			}
			++i;
			if (!fin.eof())
			{
			  fin.clear();
			  fin.seekg(0, ios::beg);
			}
		}

	return common_sequences;
}

