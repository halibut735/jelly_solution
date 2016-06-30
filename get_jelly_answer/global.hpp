//
//  global.hpp
//  get_jelly_answer
//
//  Created by 中央政治局常委 on 16/6/30.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#ifndef global_hpp
#define global_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "jelly.hpp"
using namespace std;

const short column = 5;
const short row = 7;
pair<short, short> operator +(const pair<short, short> &a, const pair<short, short> &b);
bool operator < (const pair<short, short> &a, const pair<short, short> &b);


#endif /* global_hpp */
