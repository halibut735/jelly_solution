//
//  solution.cpp
//  get_jelly_answer
//
//  Created by 中央政治局常委 on 16/6/30.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#include "solution.hpp"
#include <iostream>
#include <fstream>
using namespace std;

bool game::dfs(string &path) {
    bool ret = true;
    for (int i = 0; i < js.size(); ++ i) {
        if (!js[i].is_end()) {
            ret = false;
            break;
        }
    }
    if (ret) {
        solutions.push_back(path);
        return ret;
    }
    for (int i = 0; i < js.size(); ++ i) {
        path.push_back(js[i].color);
        path.push_back(dchar[js[i].dir]);
        vector<jelly> store(js);
        if (!maps_visited.count(js))
            if(move(i)) {
            cout << path << endl;
            maps_visited.insert(js);
            dfs(path);
            js = store;
        }
        path.pop_back();
        path.pop_back();
    }
    return ret;
}

bool game::move(short index, direction _dir) {
    pair<short, short> npos = js[index].pos + ass_dir[_dir];
    if (is_out_of_boundary(npos)) return false;
    
    for (int i = 0; i < js.size(); ++ i) {
        if (npos == js[i].pos)
            if(!move(i, _dir))
                return false;
    }
    short tmp_dir = changedir[npos.first][npos.second];
    if (tmp_dir >= 0 && js[index].dir != tmp_dir)
        cout << js[index].color << " dir:" << dchar[js[index].dir] << "->" << dchar[tmp_dir] << endl;
    js[index].dir = tmp_dir >= 0 ? tmp_dir : js[index].dir;
    //cout << js[index].color << " pos:" << npos.first << ", " << npos.second << endl;
    js[index].pos = npos;
    return true;
}

bool game::move(short index) {
    return game::move(index, (direction) js[index].dir);
}

bool game::restore(vector<jelly> &pre) {
    js = pre;
    return true;
}


bool game::is_out_of_boundary(pair<short, short> &npos) {
    if (npos.first < 0 || npos.first >= row) return true;
    if (npos.second < 0 || npos.second >= column) return  true;
    return false;
}

void game::read_conf() {
    fstream infile(conf_path);
    int jcnt, dircnt;
    short posx, posy, destx, desty, dir;
    short dirx, diry, d;
    char color;
    infile >> jcnt;
    js.resize(jcnt);
    for (int i = 0; i < jcnt; ++ i) {
        infile >> posx >> posy >> destx >> desty >> dir >> color;
        js[i].set(posx, posy, destx, desty, dir, color);
    }
    infile >> dircnt;
    memset(changedir, -1, sizeof(changedir));
    for (int i = 0; i < dircnt; ++ i) {
        infile >> dirx >> diry >> d;
        changedir[dirx][diry] = d;
    }
}

void game::print_path() {
    cout << "=================================" << endl;
    for (auto each : solutions) {
        cout << each << endl;
    }
}

void game::run() {
    read_conf();
    dfs(path);
    print_path();
}
