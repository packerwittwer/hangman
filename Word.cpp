#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Word.h"

Word::Word() {

}

std::string Word::getWord() {
    std::ifstream file("words.txt"); //open the words file
    std::string word; 
    std::vector<std::string> words;

    while (getline(file, word)) {
        words.push_back(word);
    }

    srand(time(NULL)); //get the current time to seed, so it will always be a different number to ensure randomability
    int randomIndex = rand() % words.size(); //select a random index
    std::string randomWord = words[randomIndex];

    return randomWord;
}