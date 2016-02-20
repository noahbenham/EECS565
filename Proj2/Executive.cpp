/*  Noah Benham
	Miniproject 2
	26 Feb 2015
	C++ */

#include "Executive.h"

#define NUM_THREADS     8

// TODO whitespace removal from string

Executive::Executive(std::istream& dataFile) {
	getParams(); // get user input

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	// Start timing

	readFile(dataFile); // read file

	// Stop timing
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << "Search tree generation time " << duration << " miliseconds.\n\n";
}

Executive::~Executive() { }

void Executive::mainProcess() {
	std::thread th[NUM_THREADS]; // define threads

	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	// Start timing

	generatePossibleKeys();

	// Launch thread group
	for (int i = 0; i < NUM_THREADS; ++i) {
		th[i] = std::thread(&Executive::crackPass, this, i);
	}
	//Join the threads with the main thread
	for (int i = 0; i < NUM_THREADS; ++i) {
		th[i].join();
	}

	// Stop timing
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << "\nSearching time " << duration << " miliseconds.\n";
}

void Executive::getParams() {
	std::cout << "Enter string of ciphertext: ";
	std::getline(std::cin, ciphertextStr);
	std::cout << "Enter key length: ";
	keyLength = getValidInt();
	std::cout << "Enter first word length: ";
	firstWordLength = getValidInt();

	std::transform(ciphertextStr.begin(), ciphertextStr.end(), ciphertextStr.begin(), ::toupper);

	firstWordOfCiphertext = ciphertextStr.substr(0, firstWordLength);
}

bool Executive::tryKey(std::string key) {
	std::string decryptedStr = decryptStr(firstWordOfCiphertext, key);

	return bstDict->search(decryptedStr);
}

void Executive::generatePossibleKeys() {
	std::string thisKey(keyLength, 'A'); // fill first key string with all current letter (A on first loop)

	do {
		int incrementIndex = keyLength - 1;
		while (incrementIndex >= 0) {
			possibleKeys.push_back(thisKey);
			char currChar = thisKey.at(incrementIndex);
			thisKey.at(incrementIndex) = (char)((int)currChar + 1);
			if (thisKey.at(incrementIndex) > 'Z') {
				if (incrementIndex > 0) {
					thisKey.at(incrementIndex) = 'A';
				}
				incrementIndex--;
			}
			else {
				break;
			}
		}

	} while (thisKey.at(0) <= 'Z');
}

void Executive::readFile(std::istream& intFile) {
	std::string currString; // String we are currently processing

	while (std::getline(intFile, currString)) { // process each line from the file
		if (currString.length() == firstWordLength) {
			dictStrings.push_back(currString);
		}
	}

	bstDict = new BinarySearchTree(dictStrings);
}

void Executive::crackPass(int threadID) {
	// Multithreaded password crack function

	for (int i = threadID; i < possibleKeys.size(); i = i + NUM_THREADS) { // process each line from the file
		bool resultForCurrAttempt = tryKey(possibleKeys[i]);

		if (resultForCurrAttempt) { // line decrypted successfully, matched to a key
			std::cout << "Plaintext: " << decryptStr(ciphertextStr, possibleKeys[i]) << "\n";
			std::cout << "Key: " << possibleKeys[i] << "\n";
		}
	}
}

int Executive::getValidInt() {
	int x = 0;
	bool loop = true;
	while (loop)
	{
		std::string s;
		std::getline(std::cin, s);

		std::stringstream stream(s);
		if (stream >> x)
		{
			loop = false;
			continue;
		}
		std::cout << "Invalid, try again: ";
	}
	return x;
}

std::string Executive::encryptStr(std::string plaintext, std::string key) {
	std::string output;

	for (int i = 0; i < plaintext.length(); i++) {
		int mVal = (int)plaintext.at(i) - (int)('A') + 1; // 1-26
		int kVal = (int)key.at(i % key.length()) - (int)('A') + 1; // 1-26
		int newVal = (mVal + kVal - 1) % 26 + 1; // 1-26
		int toAscii = newVal + (int)('A') - 1;

		output += (char)toAscii;
	}
	return output;
}

std::string Executive::decryptStr(std::string ciphertext, std::string key) {
	std::string output;

	for (int i = 0; i < ciphertext.length(); i++) {
		int mVal = (int)ciphertext.at(i) - (int)('A') + 1; // 1-26
		int kVal = (int)key.at(i % key.length()) - (int)('A') + 1; // 1-26
		int thisval = (mVal - kVal - 1);
		int newVal = mod(thisval, 26) + 1; // 1-26
		int toAscii = newVal + (int)('A') - 1;

		output += (char)toAscii;
	}
	return output;
}

int Executive::mod(int a, int b) {
	if (b < 0)
		return mod(-a, -b);
	int ret = a % b;
	if (ret < 0)
		ret += b;
	return ret;
}
