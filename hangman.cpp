#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "Word.h"
using namespace std;

vector<string> hangman = {"  |      (_)", //for incorrectCount, print out that many items from this list
                        "  |       |",        
                        "  |      \\|/",
                        "  |       |",
                        "  |       |",
                        "  |      / \\",
                        "  |",
                        "__|_____"}; //
vector<string> emptyNoose = {"  |",  //for every other digit after incorrect count, print out that many items from this list (if incorrectCount is 3, print the first 3 items from the first list. Then starting from the 4th item in this list through the end of the list)
                            "  |",
                            "  |",
                            "  |",
                            "  |",
                            "  |",
                            "  |",
                            "__|_____"};

int main() {
    Word word;
    int incorrectCount = 0; //set a counter for incorrect guesses
    int correctCount = 0; //set a counter for the correct guesses
    list<string> guessList; //list to hold all the guesses
    string randomWord = word.getWord();

    while (correctCount != randomWord.size() + 1 && incorrectCount != 6) { //create a loop that runs as long as the game isn't over (incorrectCount is < 8, and the word isn't complete)

        system("cls"); //clear the console so you don't end up with a freak ton of posts

        cout << "  _______" << endl; //print the first two lines of the noose, because those will always be the same.
        cout << "  |/      |    word: ";
        for (char i : randomWord){ //display the guessed letters, and unguessed letters as '_'
            string character(1, i);
            if (find(guessList.begin(), guessList.end(), character) != guessList.end()) {
                cout << i << " ";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
        for (int i = 0; i < incorrectCount; i++) { //display the noose according to the incorrect count
            cout << hangman[i] << endl;
        }

        for (int i = incorrectCount; i < emptyNoose.size(); i++) {  //display the rest of the noose according to the correctCount
            cout << emptyNoose[i] << endl;
        }

        if (correctCount == randomWord.size()) { //let the full word and noose be printed out before breaking the while loop
        correctCount++;
        incorrectCount++;
        break;
        }

        // print out the guessed list
        cout << "Already guessed:";
        for (string guessedLetter : guessList) {
            cout << guessedLetter;
        }

        cout << endl; //spacer

        //let a user enter a letter/guess
        cout << "Enter a letter: ";
        string guess;
        cin >> guess;
        bool found;
        if (guess.size() != 1) { // make sure they only enter one letter
            continue;
        } else {
            found = false;
            for (char c : randomWord) { //check if the letter is in the word
                string letter(1, c); //cast char to string

                if (guess == letter){
                    correctCount++;
                    found = true; //set the found value to true if the letter is found in the word
                }
            }

            if (!found) { //increment the incorrectCount if the letter isn't found in the word
                incorrectCount++;
            }
            
            // add the guess to the guessList if it's not already in it
            // also use this to prevent the same guess being added more than once

            if (find(guessList.begin(), guessList.end(), guess) == guessList.end()) {
                    guessList.push_back(guess);
                }
            }
    } //while loop end

    if (correctCount == randomWord.length() + 1) {
        cout << "You win!!";
    } else {
        system("cls"); //do this to just print out the whole hangman
        cout << "  _______" << endl; //print the first two lines of the noose
        cout << "  |/      |" << endl;
        for (int i = 0; i < hangman.size(); i++) {
            cout << hangman[i] << endl;
        }
        cout << "You lose!! The word was " << randomWord;
    }
    return 0;
}