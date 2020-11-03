//
//  NodeType.hpp
//  Lab07
//
//  Created by sws on 2019/12/06.
//  Copyright © 2019 sws. All rights reserved.
//

#ifndef NodeType_hpp
#define NodeType_hpp

#include <stdio.h>

/*
 *  NodeType
 */
template <typename T>
struct NodeType
{
    T data;
    NodeType<T>* next = nullptr;
};

#endif /* NodeType_hpp */
