#ifndef _EXECUTIVE_H_
#define _EXECUTIVE_H_

/*  Noah Benham
	Miniproject 2
	18 Feb 2015
	C++ */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <thread>

#include "BinarySearchTree.h"

class Executive {
	private:
		std::string ciphertextStr = "";
		std::string firstWordOfCiphertext = "";
		int keyLength, firstWordLength;
		std::vector<std::string> possibleKeys;
		std::vector<std::string> dictStrings;
		BinarySearchTree* bstDict;

		/**
		@description Fills the initial program values, given user input.
		@param
		@return N/A - is type void
		*/
		void getParams();

		/**
		@description Attempts to crack the password with the provided key.
		@param std::string
		@return bool
		*/
		bool tryKey(std::string key);

		/**
		@description Generates all possible keys of keyLength.
		@param
		@return N/A - is type void
		*/
		void generatePossibleKeys();

		/**
		@description Reads in valid strings of firstWordLength and stores them into dictStrings
		@param
		@return N/A - is type void
		*/
		void readFile(std::istream& intFile);

		/**
		@description Compares values and prints matches.
		@param std::istream&
		@return N/A - is type void
		*/
		void crackPass(int threadID);

		/**
		@description Gets valid integer from user.
		@param
		@return void
		*/
		int getValidInt();

		/**
		@description Encrypts the given string.
		@param std::string plaintext, std::string key
		@return std::string
		*/
		std::string encryptStr(std::string plaintext, std::string key);
		
		/**
		@description Decrypts the given string.
		@param std::string ciphertext, std::string key
		@return std::string
		*/
		std::string decryptStr(std::string ciphertext, std::string key);

		/**
		@description Modulus helper
		@param
		@return void
		*/
		int mod(int a, int b);
		
	public:
		/**
		@description Constructor for executive class
		@param std::istream& intFile
		@return N/A - constructors do not return a value
		*/
		Executive(std::istream& intFile);

		/**
		@description Default destructor for executive class
		@param
		@return N/A - deconstructors do not return a value
		*/
		~Executive();

		/**
		@description Main class for Executive processing.
		@param
		@return N/A - is type void
		*/
		void mainProcess();
};

#endif
