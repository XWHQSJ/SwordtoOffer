//
// Created by Wanhui on 2/19/20.
//

#ifndef SWORDTOOFFER_MOVINGCOUNT_H
#define SWORDTOOFFER_MOVINGCOUNT_H

/*
 * 剑指offer 13 机器人的运动范围
 *
 * 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
 * 一个机器人从坐标 [0, 0] 的格子开始移动，
 * 它每次可以向左、右、上、下移动一格（不能移动到方格外），
 * 也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
 * 但它不能进入方格 [35, 38]，因为3+5+3+8=19。
 * 请问该机器人能够到达多少个格子？
 *
 * 示例 1：
 *
 * 输入：m = 2, n = 3, k = 1
 * 输出：3
 *
 * 示例 1：
 *
 * 输入：m = 3, n = 1, k = 0
 * 输出：1
 *
 * 提示：
 * 1 <= n,m <= 100
 * 0 <= k <= 20
 * */

#include <unordered_map>
#include <vector>
#include <queue>

class Solution13 {
public:
    /*
     * DFS算法 -- 回溯法
     *
     * 12题使用的DFS深度优先搜索和回溯算法本题也能使用，
     * 与BFS不同的是，DFS遍历节点时，满足本题条件则计数符加1，并设置该节点标志为true，
     * 同时判断该节点的子节点是否也满足本题条件，进行递归操作。
     * DFS的思路要比BFS的思路要清晰一下，但本质是一样的，实测结果是：
     * BFS 4ms      DFS 8ms
     * */
    int movingCount(int m, int n, int k);

    /*
     * BFS算法 -- 队列实现
     *
     * 与12题相似，矩阵路径的求解方法可以归结为图或树的遍历/搜索方法，
     * 而图的通用搜索算法就是BFS(广度优先搜索)和DFS(优先搜索)。
     * BFS算法使用队列实现，当图或树的根节点满足条件，就入队，
     * 如果它的子节点满足条件，子节点入队，根节点出队，重复上述操作。
     * 本题与12题不同的是，12题需要将节点添加到路径中，
     * 而本题只需要计算满足条件的节点数量。
     *
     * 将根节点push到队列中初始化队列，同时初始化标志数组为true。
     * 使用BFS方法，当队列不为空，即取出队列的队首节点，并计数符加1，
     * 同时判断该节点的子节点是否满足题目条件，如果满足则push到队列的队尾，循环继续。
     * 本题从(0,0)开始，所以只需考虑向右(x+1,y)和向下(x,y+1)。
     * */
    int movingCount2(int m, int n, int k);

private:
    int sum(int n);

    void dfs(int m, int n, int k, int i, int j, int &count, std::vector<std::vector<bool>> &visit);

    void
    bfs(int m, int n, int k, int &count, std::vector<std::vector<bool>> &visit, std::queue<std::pair<int, int>> &que);
};


#endif //SWORDTOOFFER_MOVINGCOUNT_H
