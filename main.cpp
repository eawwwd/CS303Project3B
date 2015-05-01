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
//    mct.readMorseData();
	std::string hello = "hellohowareyou";
	std::cout << hello << std::endl;
	std::cout << mct.encode(hello) << std::endl;

	hello = mct.encode(hello);
	std::cout << hello << std::endl;
	std::cout << mct.decode(hello);

    system("pause");
    return 0;
}
