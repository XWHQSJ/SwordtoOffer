//
// Created by Wanhui on 2/19/20.
//

#include <iostream>
#include "MovingCount.h"

//计算整数位数和函数
int Solution13::sum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }

    return s;
}

int Solution13::movingCount(int m, int n, int k) {
    //初始化标志数组
    std::vector<std::vector<bool>> visit(m, std::vector<bool>(n, false));
    //计数符
    int c = 0;
    dfs(m, n, k, 0, 0, c, visit);
    return c;
}

void Solution13::dfs(int m, int n, int k, int i, int j, int &count, std::vector<std::vector<bool>> &visit) {
    //满足位数和小于k
    if (sum(i) + sum(j) <= k) {
        //满足条件的数量+1
        count++;
        //该格子被访问过
        visit[i][j] = true;

        //判断向右+1：(i+1, j)，在矩阵内，且未被访问过
        if (i + 1 >= 0 && i + 1 < m && j >= 0 && j < n && !visit[i + 1][j]) {
            dfs(m, n, k, i + 1, j, count, visit);
        }
        //判断向下+1：(i, j+1)，在矩阵内，且未被访问过
        if (i >= 0 && i < m && j + 1 >= 0 && j + 1 < n && !visit[i][j + 1]) {
            dfs(m, n, k, i, j + 1, count, visit);
        }
    }
}


int Solution13::movingCount2(int m, int n, int k) {
    std::vector<std::vector<bool>> visit(m, std::vector<bool>(n, false));
    int c = 0;
    std::queue<std::pair<int, int>> que;
    //(0,0)初始化队列
    std::pair<int, int> p = std::make_pair(0, 0);
    que.push(p);
    //true初始化标志数组
    visit[p.first][p.second] = true;
    bfs(m, n, k, c, visit, que);
    return c;
}

void Solution13::bfs(int m, int n, int k, int &count, std::vector<std::vector<bool>> &visit,
                     std::queue<std::pair<int, int>> &que) {
    std::pair<int, int> p(0, 0);
    while (!que.empty()) {
        //取出队首节点
        p = que.front();
        que.pop();
        //将计数+1
        count++;
        if (p.first + 1 >= 0 && p.first + 1 < m && p.second >= 0 && p.second < n &&
            sum(p.first + 1) + sum(p.second) <= k && !visit[p.first + 1][p.second]) {
            que.push({p.first + 1, p.second});
            visit[p.first + 1][p.second] = true;
        }

        if (p.first >= 0 && p.first < m && p.second + 1 >= 0 && p.second + 1 < n &&
            sum(p.first) + sum(p.second + 1) <= k && !visit[p.first][p.second + 1]) {
            que.push({p.first, p.second + 1});
            visit[p.first][p.second + 1] = true;
        }
    }
}

