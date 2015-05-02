//
//  main.cpp
//  CS303-Project3B
//
//  Created by Eric Wilson on 4/17/15.
//  Copyright (c) 2015 Eric Wilson. All rights reserved.
//
#include "MorseCode_Translator.h"

int main(){
    MorseCode_Translator mct;
    std::string example = "Hello, how are you?";
    std::string encodedString = mct.Encode(example);
    std::string decodedString = mct.Decode(encodedString);


    std::cout << "Example string: " << example << "\n";
    std::cout << "Encoded string: " << encodedString << "\n";
    std::cout << "Decoded string: " << decodedString << "\n";

    system("pause");
    return 0;
}
