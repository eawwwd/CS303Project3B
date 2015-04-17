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
#include "BTNode.h"

class Decoder {
public:
    //default constructor
    Decoder(){
        root = new BTNode<char>;
    }
    ~Decoder(){
        delete root;
    }
    
private:
    //root
    BTNode<char>* root = nullptr;
    
};

#endif /* defined(__CS303_Project3B__Decoder__) */
