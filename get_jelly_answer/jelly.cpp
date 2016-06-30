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

/*
bool jelly::operator<(const jelly &jj) {
    if (pos.first < jj.pos.first)
        return true;
    else
        return pos.second < jj.pos.second;
}
*/


bool operator < (const jelly &a, const jelly &b) {
    if (a.pos.first == b.pos.first) {
        if (a.pos.second == b.pos.second) {
            if (a.color == b.color) {
                return a.dir < b.dir;
            }
            return a.color < b.color;
        }
        return a.pos.second < b.pos.second;
    }
    return a.pos.first < b.pos.first;
}

bool operator == (const jelly &a, const jelly &b) {
    return a.pos == b.pos && a.color == b.color && a.dir == b.dir;
}

bool operator != (const jelly &a, const jelly &b) {
    return !(a == b);
}

bool operator < (vector<jelly> &a, vector<jelly> &b) {
    for (int i = 0; i < a.size(); ++ i) {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return a[a.size() - 1] < b[b.size() - 1];
}

bool operator == (vector<jelly> &a, vector<jelly> &b) {
    for (int i = 0; i < a.size(); ++ i) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool operator != (vector<jelly> &a, vector<jelly> &b) {
    return !(a == b);
}

