#ifndef __CS303_Project3B__MorseCode_Tree__
#define __CS303_Project3B__MorseCode_Tree__

#include "BTNode.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <string>

class MorseCode_Translator
{
public:
    MorseCode_Translator() {}
    void readMorseData();
    void buildNode(char alphaChar, std::string morseStr);

private:
    BTNode<char>* root;
};

void MorseCode_Translator::readMorseData()
{
    std::ifstream morseFile;
    std::string filename = "morse.txt";

    morseFile.open(filename, std::ios::in);

    // In case the file is not found, return
    if (!morseFile.is_open())
    {
        /*std::string message = filename + " not found";
        char* messageChar = new char[message.length() + 1];
        throw std::exception(messageChar);*/
        std::cout << filename + " not found"<< "\n";
        return;
    }

    std::string line;

    while (std::getline(morseFile, line))
    {
        char alphabet = line.at(0);
        //std::cout << alphabet << "\n";
        std::string morseCode = line.substr(1, line.length() - 1);
        //std::cout << morseCode << "\n";
        buildNode(alphabet, morseCode);
    }

    morseFile.close();
};

void MorseCode_Translator::buildNode(char alphaChar, std::string morseStr) 
{
    BTNode<char>* localRoot = root;
    for (std::string::iterator itr = morseStr.begin(); itr != morseStr.end(); ++itr)
    {
        if (*itr == '.')
        {
            localRoot->left = new BTNode<char>(' ');
            localRoot = localRoot->left;
        }
        else if (*itr == '_')
        {
            BTNode<char>* localNode;
            localRoot->right = localNode;
            localRoot = localRoot->right;
        }
    }

    localRoot->data = alphaChar;
}

#endif