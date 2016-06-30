//
//  global.cpp
//  get_jelly_answer
//
//  Created by 中央政治局常委 on 16/6/30.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#include "global.hpp"

pair<short, short> operator +(const pair<short, short> &a, const pair<short, short> &b) {
    return {a.first + b.first, a.second + b.second};
}

bool operator < (const pair<short, short> &a, const pair<short, short> &b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
