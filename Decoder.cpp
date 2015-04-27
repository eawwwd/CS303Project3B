//
//  Decoder.cpp
//  CS303-Project3B
//
//  Created by Eric Wilson on 4/17/15.
//  Copyright (c) 2015 Eric Wilson. All rights reserved.
//

#include "Decoder.h"
#include <cctype>

std::string Decoder::encode(std::string alphaStr){
    std::string morseString = "";
    
    for (int i = 0; i < alphaStr.length(); ++i){
        if (isalpha(alphaStr[i])) {
            tolower(alphaStr[i]);
            morseString += Decoder::encoder[alphaStr[i]];
        }
        else
            morseString += " ";
    }
    
    return morseString;
}