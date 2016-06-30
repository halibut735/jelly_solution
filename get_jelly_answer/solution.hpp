//
//  solution.hpp
//  get_jelly_answer
//
//  Created by 中央政治局常委 on 16/6/30.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#ifndef solution_hpp
#define solution_hpp

#include <stdio.h>
#include <set>
#include "global.hpp"
#include "jelly.hpp"
using namespace std;

class game {
public:
    game(string _conf_path):conf_path(_conf_path){}
    void run();
    
    bool friend operator < (const vector<jelly> &a, const vector<jelly> &b);
    bool friend operator == (const vector<jelly> &a, const vector<jelly> &b);
    bool friend operator != (const vector<jelly> &a, const vector<jelly> &b);
private:
    string conf_path;
    short changedir[row][column];
    vector<jelly> js;
    string path;
    vector<string> solutions;
    set<vector<jelly>> maps_visited;
    
    bool move(short index);
    bool move(short index, direction _dir);
    bool is_out_of_boundary(pair<short, short> &npos);
    void read_conf();
    bool dfs(string &path);
    void print_path();
};


#endif /* solution_hpp */
