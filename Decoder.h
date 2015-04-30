//
//  Decoder.h
//  CS303-Project3B
//
//  Created by Eric Wilson on 4/17/15.
//  Copyright (c) 2015 Eric Wilson. All rights reserved.
//

#ifndef __CS303_Project3B__Decoder__
#define __CS303_Project3B__Decoder__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Binary_Tree.h"
#include <string>
#include <map>

class Decoder {
public:
    //default constructor
    Decoder(std::istream& fin){
        //create new root
        decoderTree = new Binary_Tree<char>;
        if (fin.good()){
            //read file into object, this will also be where the tree is built
            while (!fin.eof()){
                //populate enoder map
                std::string tempStr = "";
                getline(fin, tempStr);
                encoder[tempStr[0]] = tempStr.substr(1, std::string::npos);
            }
        }
    }
    ~Decoder(){
        delete decoderTree;
    }
    
    std::string encode(std::string alphaStr);
private:
    //root
    Binary_Tree<char>* decoderTree = nullptr;
    std::string decodedString = "";
    std::map<char, std::string> encoder;
    
};

#endif /* defined(__CS303_Project3B__Decoder__) */
