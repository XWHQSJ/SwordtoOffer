//
// Created by Wanhui on 2/27/20.
//

#include <algorithm>
#include "Permutation.h"

std::vector<std::string> Solution38::permutation(std::string s) {
    if(s.empty()){
        return {};
    }

    // 对字符串进行排序
    std::sort(s.begin(), s.end());
    std::vector<std::string> res;
    // 标记字符是否遍历过
    std::vector<bool> visit(s.size(), false);
    std::string track;
    backtrack(res, s, track, visit);

    return res;
}

void Solution38::backtrack(std::vector<std::string> &res, std::string s, std::string &track, std::vector<bool> &visited) {
    // 回溯结束条件
    if(track.size() == s.size()){
        res.push_back(track);
        return;
    }

    // 选择和选择列表
    for(int i = 0; i < s.size(); i++){
        // 排除不合法的选择
        if(visited[i]){
            continue;
        }

        if(i > 0 && !visited[i-1] && s[i-1] == s[i]){
            continue;
        }
        visited[i] = true;

        // 做选择
        track.push_back(s[i]);
        // 进入下一次决策树
        backtrack(res, s, track, visited);
        // 撤销选择
        track.pop_back();
        visited[i] = false;
    }
}


std::vector<std::string> Solution38::permutation2(std::string s) {
    // 去重处理
    std::set<std::string> res;
    backtrack2(s, 0, res);

    return std::vector<std::string>(res.begin(), res.end());
}


void Solution38::backtrack2(std::string s, int start, std::set<std::string> &res) {
    // 回溯结束条件
    if(start == s.size()){
        res.insert(s);
        return;
    }

    for(int i = start; i < s.size(); i++){
        // 做选择
        std::swap(s[i], s[start]);
        // 进入下一次决策树
        backtrack2(s, start+1, res);
        // 撤销选择
        std::swap(s[i], s[start]);
    }
}