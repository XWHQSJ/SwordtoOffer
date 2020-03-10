cmake_minimum_required(VERSION 3.15)
project(SwordtoOffer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(SwordtoOffer

        #                ArrayPartition.cpp

        # 数据结构 —— 链表
        # 双链表
        DataStruct/BiNode.h
        DataStruct/DoubleNodeList.h
        # 单链表
        DataStruct/Node.h
        DataStruct/SingleNodeList.h

        # 需要构建合适的链表结构，
        # ReversePrint.cpp 和 DeleteNode.cpp中ListNode结构体冲突
        ReversePrint.cpp ReversePrint.h
        DeleteNode.cpp DeleteNode.h
        ReverseList.cpp ReverseList.h
        MergeTwoLists.cpp MergeTwoLists.h
        GetIntersectionNode.cpp GetIntersectionNode.h
        CopyRandomList.cpp CopyRandomList.h


        # 数据结构 —— 二叉树
        DataStruct/BinaryTree.h
        DataStruct/BiTreeNode.h

        


        # 数据结构测试文件
        #        DataStruct/test.cpp

        # 算法 —— 二分搜索
        #                Algorithm/BinarySearch.h

        main.cpp

        Median.cpp Median.h

        FindNumberIn2DArray.cpp FindNumberIn2DArray.h
        ReplaceSpace.cpp ReplaceSpace.h
        FindRepeatNumber.cpp FindRepeatNumber.h QuadSort.h
        NthUglyNumber.cpp NthUglyNumber.h
        BuildTree.cpp BuildTree.h
        CQueue.cpp CQueue.h
        Fibonacci.cpp Fibonacci.h
        NumWays.cpp NumWays.h
        MinArray.cpp MinArray.h
        Exist.cpp Exist.h
        HammingWeight.cpp HammingWeight.h
        PrintNumbers.cpp PrintNumbers.h

        MovingCount.cpp MovingCount.h
        CuttingRopeI.cpp CuttingRopeI.h
        CuttingRopeII.cpp CuttingRopeII.h
        MyPow.cpp MyPow.h
        Exchange.cpp Exchange.h
        GetKthFromEnd.cpp GetKthFromEnd.h
        IsMatch.cpp IsMatch.h
        IsNumber.cpp IsNumber.h
        ValidateStackSequences.cpp ValidateStackSequences.h
        Permutation.cpp Permutation.h
        MinStack.cpp MinStack.h
        MajorityElement.cpp MajorityElement.h
        GetLeastNumbers.cpp GetLeastNumbers.h
        MedianFinder.cpp MedianFinder.h
        MaxSubArray.cpp MaxSubArray.h
        IsSubStructure.cpp IsSubStructure.h
        MirrorTree.cpp MirrorTree.h
        TwoSum.cpp TwoSum.h
        IsSymmetric.cpp IsSymmetric.h
        MaxSlidingWindow.cpp MaxSlidingWindow.h
        MaxDepth.cpp MaxDepth.h
        SumNums.cpp SumNums.h SpiralOrder.cpp SpiralOrder.h)
