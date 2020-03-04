//
// Created by Wanhui on 2/19/20.
//

#include <iostream>
#include "MovingCount.h"

// 计算整数位数和函数
int Solution13::sum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }

    return s;
}

int Solution13::movingCount(int m, int n, int k) {
    // 初始化标志数组
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    // 计数符
    int c = 0;
    dfs(m, n, k, 0, 0, c, visited);
    return c;
}

void Solution13::dfs(int m, int n, int k, int i, int j, int &count, std::vector<std::vector<bool>> &visited) {
    // 满足位数和小于k
    if (sum(i) + sum(j) <= k) {
        // 满足条件的数量+1
        count++;
        // 该格子被访问过
        visited[i][j] = true;

        // 判断向右+1：(i+1, j)，在矩阵内，且未被访问过
        if (i + 1 >= 0 && i + 1 < m && j >= 0 && j < n && !visited[i + 1][j]) {
            dfs(m, n, k, i + 1, j, count, visited);
        }
        // 判断向下+1：(i, j+1)，在矩阵内，且未被访问过
        if (i >= 0 && i < m && j + 1 >= 0 && j + 1 < n && !visited[i][j + 1]) {
            dfs(m, n, k, i, j + 1, count, visited);
        }
    }
}


int Solution13::movingCount2(int m, int n, int k) {
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
    int c = 0;
    std::queue<std::pair<int, int>> que;
    // (0,0)初始化队列
    std::pair<int, int> p = std::make_pair(0, 0);
    que.push(p);
    // true初始化标志数组
    visited[p.first][p.second] = true;
    bfs(m, n, k, c, visited, que);
    return c;
}

void Solution13::bfs(int m, int n, int k, int &count, std::vector<std::vector<bool>> &visited,
                     std::queue<std::pair<int, int>> &que) {
    std::pair<int, int> p(0, 0);
    while (!que.empty()) {
        // 取出队首节点
        p = que.front();
        que.pop();
        // 将计数+1
        count++;

        // 机器人向右边移动，
        // 判断右边的点是否符合条件
        if (p.first + 1 >= 0 && p.first + 1 < m && p.second >= 0 && p.second < n &&
            sum(p.first + 1) + sum(p.second) <= k && !visited[p.first + 1][p.second]) {
            // 符合条件的点push到队列中，等待下一轮的遍历
            // 同时设置该符合的点可访问
            que.push({p.first + 1, p.second});
            visited[p.first + 1][p.second] = true;
        }

        // 机器人向下移动，
        // 判断下边的点是否符合条件
        if (p.first >= 0 && p.first < m && p.second + 1 >= 0 && p.second + 1 < n &&
            sum(p.first) + sum(p.second + 1) <= k && !visited[p.first][p.second + 1]) {
            que.push({p.first, p.second + 1});
            visited[p.first][p.second + 1] = true;
        }
    }
}

