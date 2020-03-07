//
// Created by Wanhui on 2/9/20.
//

/*
 * This a main function for algorithms tests.
 * */

#include <iostream>
#include "DataStruct/SingleNodeList.h"
#include "FindNumberIn2DArray.h"
#include "Median.h"
#include "ReplaceSpace.h"
#include "FindRepeatNumber.h"
#include "ReversePrint.h"
#include "NthUglyNumber.h"
#include "BuildTree.h"
#include "CQueue.h"
#include "Fibonacci.h"
#include "NumWays.h"
#include "MinArray.h"
#include "Exist.h"
#include "HammingWeight.h"
#include "PrintNumbers.h"
#include "DeleteNode.h"
#include "MovingCount.h"
#include "CuttingRopeI.h"
#include "CuttingRopeII.h"
#include "MyPow.h"
#include "Exchange.h"
#include "GetKthFromEnd.h"
#include "IsMatch.h"
#include "IsNumber.h"
#include "ValidateStackSequences.h"
#include "Permutation.h"
#include "MinStack.h"
#include "MajorityElement.h"
#include "GetLeastNumbers.h"
#include "MedianFinder.h"
#include "MaxSubArray.h"
#include "ReverseList.h"
#include "MergeTwoLists.h"
#include "GetIntersectionNode.h"
#include "CopyRandomList.h"
#include "IsSubStructure.h"
#include "TwoSum.h"
#include "MirrorTree.h"
#include "IsSymmetric.h"
#include "MaxSlidingWindow.h"

using namespace std;

int main() {
    // FindNumberIn2DArray.cpp test
    std::vector<std::vector<int>> array = {{1, 2, 3, 4},
                                           {2, 3, 4, 5},
                                           {3, 4, 5, 6},
                                           {4, 5, 6, 7}};
    int target = 9;
    Solution04 solution04;
    bool b = solution04.findNumberIn2DArray(target, array);
    // assert(b);
    std::cout << b << std::endl;

    // Median.cpp test
    Solution04_1 solution04_1;
    std::vector<unsigned int> arr = {2, 3, 4};
    int n = arr.size();
    int x = 2;
    int add = solution04_1.median(n, x, arr);
    std::cout << add << std::endl;

    // ReplaceSpace.cpp test
    Solution05 solution05;
    char str[] = "hello world";
    int length = sizeof(str) / sizeof(str[0]);
    solution05.replaceSpace1(str, length);
    for (int i = 0; i < 13; ++i) {
        std::cout << str[i];
    }
    std::cout << "\n";

    char str2[] = "Hello World";
    solution05.replaceSpace(str2, length);
    for (int i = 0; i < 13; ++i) {
        std::cout << str2[i];
    }
    std::cout << "\n";

    std::string s = "Hello world";
    std::string str3;
    str3 = solution05.replaceSpace2(s);
    std::cout << str3 << std::endl;

    std::string str4;
    str4 = solution05.replaceSpace2(s);
    std::cout << str4 << std::endl;


    // FindRepeatNumber.cpp test
    Solution03 solution03;
    std::vector<int> vec = {2, 3, 1, 0, 2, 5, 3};
    int num;
    num = solution03.findRepeatNumber(vec);
    std::cout << num << std::endl;

    num = solution03.findRepeatNumber3(vec);
    std::cout << num << std::endl;

    num = solution03.findRepeatNumber2(vec);
    std::cout << num << std::endl;


    // ReversePrint.cpp test
    Solution06 solution06;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(2);
    SingleNodeList *singleNodeList = new SingleNodeList();
    singleNodeList->insertTail(node1);
    singleNodeList->insertTail(node2);
    singleNodeList->insertTail(node3);
    std::vector<int> result = solution06.reversePrint(node2);
    for (auto num : result) {
        std::cout << "result is " << num << std::ends;
    }
    std::cout << std::endl;


    // BuildTree.cpp test
    Solution07 solution07;


    // CQueue.cpp test
    Solution09 solution09;
    solution09.appendTail(3);
    solution09.appendTail(4);
    solution09.appendTail(5);
    int c = solution09.deleteHead();
    std::cout << c << std::endl;


    // Fibonacci.cpp test
    Solution10_1 solution10_1;
    int n3 = 5;
    int f = solution10_1.fibonacci(n3);
    std::cout << f << std::endl;

    f = solution10_1.fibonacci2(n3);
    std::cout << f << std::endl;


    // NumWays.cpp test
    Solution10_2 solution10_2;
    int n2 = 7;
    f = solution10_2.numWays(n2);
    std::cout << f << std::endl;

    f = solution10_2.numWays2(n2);
    std::cout << f << std::endl;


    // MinArray.cpp test
    Solution11 solution11;
    std::vector<int> num1 = {3, 4, 5, 1, 2};
    std::vector<int> num2 = {2, 2, 2, 0, 1};
    int m2 = solution11.minArray(num1);
    std::cout << m2 << std::endl;
    m2 = solution11.minArray2(num1);
    std::cout << m2 << std::endl;


    // Exit.cpp test
    Solution12 solution12;
    std::vector<std::vector<char>> board1 = {{'A', 'B', 'C', 'E'},
                                             {'S', 'F', 'C', 'S'},
                                             {'A', 'D', 'E', 'E'}};
    std::string word1 = "ABCCED";
    std::vector<std::vector<char>> board2 = {{'a', 'b'},
                                             {'c', 'd'}};
    std::string word2 = "abcd";
    std::vector<std::vector<char>> board3 = {{'a'}};
    std::string word3 = "ab";
    bool b1 = solution12.exist(board1, word1);
    std::cout << "b1 = " << b1 << std::endl;
    b1 = solution12.exist(board2, word2);
    if (!b1) {
        std::cout << "b1 = " << 0 << std::endl;
    }
    b1 = solution12.exist(board3, word3);
    if (!b1) {
        std::cout << "b1 = " << 0 << std::endl;
    }


    // MovingCount.cpp test
    Solution13 solution13;
    int m1 = 2, n9 = 3, k = 1;
    int m5 = 3, n10 = 1, k1 = 0;
    int m6 = 16, n11 = 8, k2 = 4;
    int c2 = solution13.movingCount(m1, n9, k);
    std::cout << "c2 = " << c2 << std::endl;
    c2 = solution13.movingCount(m5, n10, k1);
    std::cout << "c2 = " << c2 << std::endl;
    c2 = solution13.movingCount(m6, n11, k2);
    std::cout << "c2 = " << c2 << std::endl;

    int c3 = solution13.movingCount2(m1, n9, k);
    std::cout << "c3 = " << c3 << std::endl;
    c3 = solution13.movingCount2(m5, n10, k1);
    std::cout << "c3 = " << c3 << std::endl;
    c3 = solution13.movingCount2(m6, n11, k2);
    std::cout << "c3 = " << c3 << std::endl;


    // CuttingRopeI.cpp test
    Solution14_1 solution141;
    int n12 = 2, n13 = 3, n14 = 5, n15 = 6, n16 = 10, n17 = 11;
    int mul = solution141.cuttingRope(n12);
    std::cout << "mul2 = " << mul << std::endl;
    mul = solution141.cuttingRope(n13);
    std::cout << "mul3 = " << mul << std::endl;
    mul = solution141.cuttingRope(n14);
    std::cout << "mul5 = " << mul << std::endl;
    mul = solution141.cuttingRope(n15);
    std::cout << "mul6 = " << mul << std::endl;
    mul = solution141.cuttingRope(n16);
    std::cout << "mul10 = " << mul << std::endl;
    mul = solution141.cuttingRope(n17);
    std::cout << "mul11 = " << mul << std::endl;
    mul = solution141.cuttingRope2(n16);
    std::cout << "mul102 = " << mul << std::endl;
    mul = solution141.cuttingRope2(n17);
    std::cout << "mul112 = " << mul << std::endl;


    // CuttingRopeII.cpp test
    Solution14_2 solution142;
    int n18 = 60, n19 = 70, n20 = 100, n21 = 120;
    mul = solution142.cuttingRope(n18);
    std::cout << "mul18 = " << mul << std::endl;
    mul = solution142.cuttingRope(n19);
    std::cout << "mul19 = " << mul << std::endl;
    mul = solution142.cuttingRope(n20);
    std::cout << "mul20 = " << mul << std::endl;
    mul = solution142.cuttingRope(n21);
    std::cout << "mul21 = " << mul << std::endl;


    // HammingWeight.cpp test
    Solution15 solution15;
    uint32_t n4 = 00000000000000000000000000001011;
    uint32_t n5 = 00000000000000000000000010000000;
    uint32_t n6 = 9;
    int n7 = -3;
    int m3 = solution15.hammingWeight(n7);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight2(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight3(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight4(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight5(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight6(n6);
    std::cout << "m3 = " << m3 << std::endl;
    m3 = solution15.hammingWeight7(n6);
    std::cout << "m3 = " << m3 << std::endl;


    // MyPow.cpp test
    Solution16 solution16;
    double x1 = 2.00000, x2 = 2.10000;
    int n22 = 10, n23 = 3, n24 = -2;
    double m7 = 0;
    m7 = solution16.myPow(x1, n22);
    std::cout << "m7 = " << m7 << std::endl;
    m7 = solution16.myPow(x2, n23);
    std::cout << "m7 = " << m7 << std::endl;
    m7 = solution16.myPow(x1, n24);
    std::cout << "m7 = " << m7 << std::endl;


    // PrintNumber.cpp test
    Solution17 solution17;
    int n8 = 2;
    std::vector<int> m4 = solution17.printNumbers(n8);
    for (auto &num : m4) {
        std::cout << "num = " << num << " ";
    }
    std::cout << std::endl;


    // DeleteNode.cpp test
    Solution18 solution18;


    // IsMatch.cpp test
    Solution19 solution19;
    std::string s1 = "aa";
    std::string p = "a*";
    bool b2 = solution19.isMatch(s1, p);
    std::cout << "b2 = " << b2 << std::endl;
    b2 = solution19.isMatch2(s1, p);
    std::cout << "b2 = " << b2 << std::endl;
    b2 = solution19.isMatch2_2(s1, p);
    std::cout << "b2 = " << b2 << std::endl;

    // IsNumber.cpp test
    Solution20 solution20;
    std::string s3 = "75679.4172";
    bool b3 = solution20.isNumber(s3);
    std::cout << "b3 = " << b3 << std::endl;
    b3 = solution20.isNumber2(s3);
    std::cout << "b3 = " << b3 << std::endl;

    // Exchange.cpp test
    Solution21 solution21;
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> nums2 = solution21.exchange(nums);
    for (auto &num : nums2) {
        std::cout << "num is " << num << " ";
    }
    std::cout << std::endl;
    nums2 = solution21.exchange2(nums);
    for (auto &num : nums2) {
        std::cout << "num is " << num << " ";
    }
    std::cout << std::endl;
    nums2 = solution21.exchange3(nums);
    for (auto &num : nums2) {
        std::cout << "num is " << num << " ";
    }
    std::cout << std::endl;


    // GetKthFromEnd.cpp test
    Solution22 solution22;


    // ReverseList.cpp test
    Solution24 solution24;


    // MergeTwoLists.cpp test
    Solution25 solution25;


    // IsSubStructure.cpp test
    Solution26 solution26;


    // MirrorTree.cpp test
    Solution27 solution27;


    // IsSymmetric.cpp test
    Solution28 solution28;


    // MinStack.cpp test
    Solution30 solution30;
    solution30.push(-2);
    solution30.push(0);
    solution30.push(-3);
    std::cout << "min is " << solution30.min() << std::endl;
    solution30.pop();
    std::cout << "top is " << solution30.top() << std::endl;
    std::cout << "min is " << solution30.min() << std::endl;


    // ValidateStackSequences.cpp test
    Solution31 solution31;
    std::vector<int> pushed = {1, 2, 3, 4, 5};
    std::vector<int> popped = {4, 5, 3, 2, 1};
    bool b4 = solution31.validateStackSequences(pushed, popped);
    std::cout << "b4 = " << b4 << std::endl;


    // CopyRandomList.cpp test
    Solution35 solution35;


    // Permutation.cpp test
    Solution38 solution38;
    std::string string1 = "abc";
    std::vector<std::string> res = solution38.permutation(string1);
    std::cout << "res[0] : " << res[0] << std::endl;


    // MajorityElement.cpp test
    Solution39 solution39;
    std::vector<int> nums3 = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    std::vector<int> nums4 = {3, 2, 3};
    int index = solution39.majorityElement(nums3);
    std::cout << "index is " << index << std::endl;
    index = solution39.majorityElement(nums4);
    std::cout << "index is " << index << std::endl;
    index = solution39.majorityElement2(nums4);
    std::cout << "index is " << index << std::endl;
    index = solution39.majorityElement3(nums4);
    std::cout << "index is " << index << std::endl;
    index = solution39.majorityElement4(nums4);
    std::cout << "index is " << index << std::endl;
    index = solution39.majorityElement5(nums4);
    std::cout << "index is " << index << std::endl;


    // GetLeastNumbers.cpp test
    Solution40 solution40;
    std::vector<int> arr1 = {3, 2, 1};
    int k3 = 2;
    std::vector<int> res1 = solution40.getLeastNumbers(arr1, k3);
    for (auto num : res1) {
        std::cout << "num = " << num << std::ends;
    }
    std::cout << std::endl;
    res1 = solution40.getLeastNumbers2(arr1, k3);
    for (auto num : res1) {
        std::cout << "num = " << num << std::ends;
    }
    std::cout << std::endl;


    // MedianFinder.cpp test
    Solution41 solution41;
    solution41.addNum4(1);
    solution41.addNum4(2);
    std::cout << "findMedian is " << solution41.findMedian4() << std::endl;
    solution41.addNum4(3);
    std::cout << "findMedian is " << solution41.findMedian4() << std::endl;


    // MaxSubArray.cpp test
    Solution42 solution42;
    std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res2 = solution42.maxSubArray(nums1);
    std::cout << "res2 is " << res2 << std::endl;
    res2 = solution42.maxSubArray2(nums1);
    std::cout << "res2 is " << res2 << std::endl;
    res2 = solution42.maxSubArray3(nums1);
    std::cout << "res2 is " << res2 << std::endl;


    // NthUglyNumber.cpp test
    Solution49 solution49;
    int n1 = 10;
    int m = 0;
    m = solution49.nthUglyNumber(n1);
    std::cout << m << std::endl;

    // GetIntersectionNode.cpp test
    Solution52 solution52;


    // TwoSum.cpp test
    Solution57 solution57;
    std::vector<int> nums7 = {14, 15, 16, 22, 53, 60};
    int target1 = 76;
    std::vector<int> ans = solution57.twoSum(nums7, target1);
    for (auto a : ans) {
        std::cout << "ans = " << a << std::ends;
    }
    std::cout << std::endl;
    ans = solution57.twoSum2(nums7, target1);
    for (auto a : ans) {
        std::cout << "ans = " << a << std::ends;
    }
    std::cout << std::endl;



    // MaxSlidingWindow.cpp test
    Solution59_1 solution591;
    std::vector<int> nums5 = {1, 3, -1, -3, 5, 3, 6, 7};
    int k4 = 3;
    std::vector<int> ans1 = solution591.maxSlidingWindow(nums5, k4);
    for(auto a : ans1){
        std::cout << "a = " << a << std::ends;
    }
    std::cout << std::endl;


    return 0;
}

