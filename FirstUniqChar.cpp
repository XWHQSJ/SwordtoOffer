//
// Created by Wanhui on 3/18/20.
//

#include <unordered_map>
#include "FirstUniqChar.h"

char Solution50::firstUniqChar(std::string s) {
    if(s.empty()){
        return ' ';
    }

    std::unordered_map<char, int> unorderedMap;
    // 为每个字符存储哈希表
    for(char ch : s){
        unorderedMap[ch]++;
    }

    for(char ch : s){
        // 找到出现次数为1的字符
        if(unorderedMap[ch] == 1){
            return ch;
        }
    }

    // 找不到出现次数为1的字符
    return ' ';
}
