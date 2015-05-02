#ifndef __CS303_Project3B__MorseCode_Tree__
#define __CS303_Project3B__MorseCode_Tree__

#include "BTNode.h"
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <map>

class MorseCode_Translator
{
public:
    MorseCode_Translator() : root(new BTNode<char>(' '))
    {
        readMorseData();
    }
    std::string Decode(std::string key);
    std::string Encode(std::string alphaStr);
private:
    BTNode<char>* root;
    void readMorseData();
    void buildTree(char alphaChar, std::string morseStr);
    std::map<char, std::string> encoder;
};

// Read the Morse data (English character and Morse code) from a text file
void MorseCode_Translator::readMorseData()
{
    std::string filename = "morse.txt";
    std::ifstream morseFile;

    morseFile.open(filename, std::ifstream::in);

    // In case the file is not found, return
    if (!morseFile.is_open())
    {
        std::cout << filename + " not found" << "\n";
        return;
    }

    std::string line;

    while (std::getline(morseFile, line))
    {
        // A line in the text file will look like: a._
        // a is the character
        // ._ is the Morse code associated with the character
        char alphabet = line.at(0);
        std::string morseCode = line.substr(1, std::string::npos);

        // Build the morse tree and map
        buildTree(alphabet, morseCode);
        encoder[alphabet] = morseCode;
    }

    morseFile.close();
};

// Build the Morse tree with each line read from the text file
void MorseCode_Translator::buildTree(char alphaChar, std::string morseCode)
{
    BTNode<char>* localRoot = root;
    for (std::string::iterator itr = morseCode.begin(); itr != morseCode.end(); ++itr)
    {
        if (*itr == '.') // If dot, go left
        {
            if (localRoot->left == NULL)
            {
                localRoot->left = new BTNode<char>(' ');
            }
            localRoot = localRoot->left;
        }
        else if (*itr == '_') // If underscore, go right
        {
            if (localRoot->right == NULL)
            {
                localRoot->right = new BTNode<char>(' ');
            }
            localRoot = localRoot->right;
        }
    }

    if (localRoot != NULL)
    {
        localRoot->data = alphaChar;
    }
}

// Decode the morse string
std::string MorseCode_Translator::Decode(std::string morseString)
{
    std::string result = "";
    BTNode<char>* current = root;

    for (int i = 0; i < morseString.length(); i++)
    {
        if (morseString[i] == '.')
        {
            if (current->left != NULL)
            {
                current = current->left;
            }
        }
        else if (morseString[i] == '_')
        {
            if (current->right != NULL)
            {
                current = current->right;
            }
        }
        else
        {
            // Since the data of the root node is space,
            // a space will be appended into the string appropriately
            result += current->data;
            current = root;
        }
    }

    return result;
}

// Encode the English-character string
std::string MorseCode_Translator::Encode(std::string alphaStr)
{
    std::string morseString = "";
    // Iterate through string comparing each character to encoding map
    for (int i = 0; i < alphaStr.length(); ++i)
    {
        if (isalpha(alphaStr[i])) // Encode alphabetical character
        {
            char tempChar = tolower(alphaStr[i]);
            // Build return string
            morseString += MorseCode_Translator::encoder[tempChar] + " ";
        }
        else // Anything else will be treated as space
        {
            morseString += ' ';
        }
    }

    return morseString;
}

#endif
