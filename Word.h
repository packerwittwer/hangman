#ifndef WORD_H
#define  WORD_H
#include <string>

class Word {
    private:
        std::string _word; //variable
    public:
        std::string getWord(); //method
        Word(); //constructor
};

#endif