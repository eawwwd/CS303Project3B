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
    MorseCode_Translator() : root(new BTNode<char>(' '))
    {
        readMorseData();
    }
private:
    BTNode<char>* root;
    void readMorseData();
    void buildTree(char alphaChar, std::string morseStr);
};

void MorseCode_Translator::readMorseData()
{
    std::string filename = "morse.txt";
    std::ifstream morseFile;
    

    morseFile.open(filename, std::ifstream::in);

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
        buildTree(alphabet, morseCode);
    }

    morseFile.close();
};

void MorseCode_Translator::buildTree(char alphaChar, std::string morseStr)
{
    BTNode<char>* localRoot = root;
    for (std::string::iterator itr = morseStr.begin(); itr != morseStr.end(); ++itr)
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

std::string MorseCode_Translator::decode(std::string key, BTNode root)
{
    std::string result = "";
    BTNode current = root;
    
    for(int i = 0; i < key.length(); i++)
    {
        if(key[i] == '-')
        {
            if(current->left != NULL)
            {
                current = current->left;
            }
        }
        else if(key[i] == '.')
        {
            if(current-right != NULL)
            {
                current = current->right;
            }
        }
        else
        {
            result = result.append(current->data);
            current = root;
        }
        
    }
    
    return result;
}

#endif
