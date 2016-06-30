//
//  jelly.hpp
//  get_jelly_answer
//
//  Created by 中央政治局常委 on 16/6/29.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#ifndef jelly_hpp
#define jelly_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "global.hpp"
using namespace std;

enum direction{
    ldir = 0,
    rdir,
    udir,
    ddir
};
const char dchar[4] = {'L', 'R', 'U', 'D'};
const pair<short, short> ass_dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};


class jelly{
public:
    pair<short, short> pos;
    pair<short, short> dest;
    short dir;
    char color;
    jelly ():pos(0, 0), dest(0, 0), color('-'){}
    void set(short x, short y, short dx, short dy, short dir, char c);
    bool is_end();
    
    friend bool operator < (const jelly &a, const jelly &b) ;
    friend bool operator == (const jelly &a, const jelly &b);
    friend bool operator != (const jelly &a, const jelly &b) ;
};



#endif /* jelly_hpp */
