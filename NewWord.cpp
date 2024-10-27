#include <iostream>
#include <fstream>
#include <string>
#include "NewWord.h"
// don't use namespace, it can lead to naming conflicts

NewWord::NewWord(const std::string& word) : _newWord(word) {
    
}

void NewWord::addWord(const std::string& word) {
    std::ofstream file("test.txt", std::ios::app); //open the words file

    if(file.is_open()) {
        file << word << std::endl; // write the new word to the words file
        file.close(); //close the words file
        std::cout << "Word successfully added!" << std::endl;
    } else {
        std::cerr << "Failed to open file" << std::endl;
    }

}