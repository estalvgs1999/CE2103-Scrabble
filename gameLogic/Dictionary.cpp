#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

#include "Dictionary.hpp"
#include "Player.hpp"
#include "GameDeck.hpp"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

Dictionary::Dictionary(){
    filePath = "../TextFiles/dictionary.txt";
}

bool Dictionary::searchInDictionary(string word) {
    string line;
    vector<string> row;
    ifstream dictionaryFile = ifstream(filePath);
    if (dictionaryFile.is_open()) {
        while (getline(dictionaryFile, line)) {
            if(line.substr(0, 1) == word.substr(0, 1)){
                boost::split(row, line, boost::is_any_of(","));
                return binary_search(row.begin(), row.end(), word);
            }
        }dictionaryFile.close();
    } else cout << "File could not be opened.";
    return false;
}

void Dictionary::writeInDictionary(string word) {
    fstream dictionaryFile(filePath, ios::app); //ios::in | ios::out
    if(dictionaryFile.is_open()) {
        dictionaryFile << word + "\n";
        dictionaryFile.close();
    }else cout << "Couldn't write in file";
}

#endif DICTIONARY_CPP