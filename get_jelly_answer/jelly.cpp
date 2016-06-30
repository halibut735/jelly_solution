//
//  jelly.cpp
//  get_jelly_answer
//
//  Created by 中央政治局常委 on 16/6/29.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#include "jelly.hpp"



bool jelly::is_end() {
    //return pos.first == dest.first && pos.second == dest.second;
    return pos == dest;
}

void jelly::set(short x, short y, short dx, short dy, short _dir, char c) {
    pos = {x, y};
    dest = {dx, dy};
    dir = _dir;
    color = c;
}


bool operator < (const jelly &a, const jelly &b) {
    if (a.pos.first != b.pos.first)
        return a.pos.first < b.pos.first;
    if (a.pos.second != b.pos.second)
        return a.pos.second < b.pos.second;
    if (a.color != b.color)
        return a.color < b.color;
    return a.dir < b.dir;
}

bool operator == (const jelly &a, const jelly &b) {
    return a.pos == b.pos && a.color == b.color && a.dir == b.dir;
}

bool operator != (const jelly &a, const jelly &b) {
    return !(a == b);
}
