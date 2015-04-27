//
//  main.cpp
//  CS303-Project3B
//
//  Created by Eric Wilson on 4/17/15.
//  Copyright (c) 2015 Eric Wilson. All rights reserved.
//

#include <iostream>
#include "Decoder.h"
#include <fstream>

int main() {
    std::ifstream fin;
    fin.open("code.txt", std::ifstream::in);
    if (fin.good())
        std::cout << "File opened!";
    Decoder decoder(fin);
    std::string inputStr;
    
    std::cout << "Please enter string to be encoded:\n";
    getline(std::cin, inputStr);
    std::cout << decoder.encode(inputStr);
    
    return 0;
}
