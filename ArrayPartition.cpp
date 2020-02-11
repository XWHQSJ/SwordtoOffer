/*
 * 数组操作
 *
 * 输入一个无序整数数组，调整数组中数字的顺序，
 * 所有偶数位于数组的前半部分，使得所有奇数位于数组的后半部分。
 * 要求时间复杂度为O(n)。
 *
 * 输入描述:
 * 给定无序数组。
 * 长度不超过1000000。
 *
 * 输出描述:
 * 所有偶数位于数组的前半部分，所有奇数位于数组的后半部分。
 * 如果有多个答案可以输出任意一个正确答案。
 *
 * 示例1
 * 输入
 * 2 4 5 7 8 1
 *
 * 输出
 * 2 4 8 7 5 1
 *
 * */

#include <iostream>
#include <cstdio>
#include <vector>

/*
 * C语言获取数组大小的方法，但是无法获取数组中有意义元素的个数
 * */
#define GET_ARRAY_LEN(array, len) {len = sizeof(array) / sizeof(array[0]);}


/*
 * C++中使用模板获取数组大小的方法，但是无法获取数组中有意义元素的个数
 * */
template<class T, size_t N>
size_t getCount(T (&arr)[N]) {
    return N;
}

using namespace std;

/*
 * 方法1
 * 双指针lo为交换指针，cur是遍历指针，
 * 他们从同一侧开始移动，
 * 当为偶数时，双指针同时移动，并做交换操作
 * 当遍历指针指向奇数时，
 * 遍历指针移动，交换指针不移动
 * */
void partition(int *arr, int size) {
    int lo = -1;
    int cur = 0;
    while (cur < size) {
        if (~arr[cur] & 1) {
            ++lo;
            swap(arr[lo], arr[cur]);
        }
        ++cur;
    }
}

/*
 * 方法2
 * 双指针low为左侧指针，high为右侧指针，
 * 两指针分别从左右两侧开始遍历，
 * 当左侧指针指向偶数时，low指针向右移动，
 * 当右侧指针指向奇数时，high指针向左移动，
 * 当low指向奇数，同时high指向偶数时，进行交换操作
 * */
void partition1(int *arr, int size) {
    int low = 0;
    int high = size - 1;

    while (low != high) {
        while (low < high && ~arr[low] & 1) {
            low++;
        }
        while (low < high && arr[high] & 1) {
            high--;
        }

        swap(arr[low], arr[high]);
    }
}

/* 方法3
 * 增加数组oarr，使用空间换时间
 * 先遍历数组arr将偶数取出存入oarr中，
 * 再遍历一遍数据arr将奇数取出存入oarr中,
 * 其中c和r是用于记录存入oarr中的数据量的，
 * 目的是内存操作正确
 * */
void partition2(int *arr, int size) {
    int *oarr = nullptr;
    oarr = (int *) malloc(size * sizeof(int));

    int i = 0, c = 0;
    for (i = 0; i < size; ++i) {
        if ((arr[i] % 2) == 0) {
            oarr[c] = arr[i];
            ++c;
        }
    }

    int r = 0;
    for (i = 0; i < size; ++i) {
        if ((arr[i] % 2) == 1) {
            oarr[c + r] = arr[i];
            ++r;
        }
    }

    //根据测试场景需要，普通情况可不要
    for (i = 0; i < size; ++i) {
        arr[i] = oarr[i];
    }
}


int main() {
    int arr[6] = {2, 4, 5, 7, 8, 1};
    int size = getCount(arr);
    //GET_ARRAY_LEN(arr, size);

    std::cout << (~arr[0] & 1) << std::endl;

    //partition(arr, size);
    //partition1(arr, size);
    partition2(arr, size);

    for (int i = 0; i < 6; ++i) {
        printf("%d%c", arr[i], (i == 6 - 1 ? '\n' : ' '));
    }

    return 0;
}