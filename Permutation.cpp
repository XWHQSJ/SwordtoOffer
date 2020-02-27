//
// Created by Wanhui on 2/27/20.
//

#include <algorithm>
#include <set>
#include "Permutation.h"

std::vector<std::string> Solution38::permutation(std::string s) {
    if(s.empty()){
        return {};
    }

    std::sort(s.begin(), s.end());
    std::vector<std::string> res;
    std::vector<bool> visit(s.size(), false);
    std::string track;
    backtrack(res, s, track, visit);

    return res;
}

void Solution38::backtrack(std::vector<std::string> &res, std::string s, std::string &track, std::vector<bool> &visit) {
    if(track.size() == s.size()){
        res.push_back(track);
        return;
    }

    for(int i = 0; i < s.size(); i++){
        if(visit[i]){
            continue;
        }

        if(i > 0 && !visit[i-1] && s[i-1] == s[i]){
            continue;
        }
        visit[i] = true;

        track.push_back(s[i]);

        backtrack(res, s, track, visit);

        track.pop_back();
        visit[i] = false;
    }
}


std::vector<std::string> Solution38::permutation2(std::string s) {
    std::set<std::string> res;
    backtrack2(s, 0, res);

    return std::vector<std::string>(res.begin(), res.end());
}


void Solution38::backtrack2(std::string s, int start, std::set<std::string> &res) {
    if(start == s.size()){
        res.insert(s);
        return;
    }

    for(int i = start; i < s.size(); i++){
        std::swap(s[i], s[start]);
        backtrack2(s, start+1, res);
        std::swap(s[i], s[start]);
    }
}