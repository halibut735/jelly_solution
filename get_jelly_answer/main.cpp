//
//  main.cpp
//  get_jelly_answer
//
//  Created by 中央政治局常委 on 16/6/28.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <set>
#include "jelly.hpp"
#include "global.hpp"
#include "solution.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    cout << "Please revise the map info if anything is wrong: row(" << row << ") && column(" << column << ")." << endl;
    string path("/Users/bingoboy/Downloads/others/jelly/game38.txt");
    game test(path);
    test.run();
    return 0;
}
