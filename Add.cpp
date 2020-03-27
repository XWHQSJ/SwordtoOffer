//
// Created by Wanhui on 3/26/20.
//

#include "Add.h"

int Solution65::add(int a, int b) {
    // 无进位和、进位值
    int sum, carry;
    while (b != 0) {
        // 异或操作得无进位和
        sum = a ^ b;
        // 与操作后移位得进位值
        carry = ((unsigned int) (a & b) << 1);

        // 循环，直到进位为0
        a = sum;
        b = carry;
    }

    return a;
}
