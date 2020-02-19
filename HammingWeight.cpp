//
// Created by Wanhui on 2/18/20.
//

#include "HammingWeight.h"

//如果参数类型为int负数，则无法使用算术右移
//使用强制转换实现逻辑右移(unsigned int)n >> 1;
int Solution15::hammingWeight(uint32_t n) {
//    if(n<0){
//        return 0;
//    }

    int c = 0;
    while (n){
        //&与操作判断是否为1
        if(n&1){
            c++;
        }

        // 移位和除2都是算术右移
        n = n >> 1;
//        n /= 2;
    }

    return c;
}

int Solution15::hammingWeight2(uint32_t n) {
    n = (n & m1) + ((n >> 1) & m1);
    n = (n & m2) + ((n >> 2) & m2);
    n = (n & m4) + ((n >> 4) & m4);
    n = (n * (h01) >> 24);

    return n;
}

int Solution15::hammingWeight3(uint32_t n) {
    n = (n & m1 ) + ((n >>  1) & m1 );
    n = (n & m2 ) + ((n >>  2) & m2 );
    n = (n & m4 ) + ((n >>  4) & m4 );
    n = (n & m8 ) + ((n >>  8) & m8 );
    n = (n & m16) + ((n >> 16) & m16);
    
    return n;
}

int Solution15::hammingWeight4(uint32_t n) {
    n -= (n >> 1) & m1;
    n = (n & m2) + ((n >> 2) & m2);
    n = (n + (n >> 4)) & m4;
    n += n >>  8;
    n += n >> 16;

//    // 针对uint64_t的情况
//    n += n >> 32;
    
    return n &0xff;
}

int Solution15::hammingWeight5(uint32_t n) {
    n -= (n >> 1) & m1;
    n = (n & m2) + ((n >> 2) & m2);
    n = (n + (n >> 4)) & m4;
    return (n * h01)>>56;
}

int Solution15::hammingWeight6(uint32_t n) {
    uint32_t count;
    for (count=0; n; count++)
        n &= n-1;
    return count;
}

#define f(y) if ((n &= n-1) == 0) return y;
int Solution15::hammingWeight7(uint32_t n) {
    if (n == 0) return 0;
    f( 1) f( 2) f( 3) f( 4) f( 5) f( 6) f( 7) f( 8)
    f( 9) f(10) f(11) f(12) f(13) f(14) f(15) f(16)
    f(17) f(18) f(19) f(20) f(21) f(22) f(23) f(24)
    f(25) f(26) f(27) f(28) f(29) f(30) f(31) f(32)
    f(33) f(34) f(35) f(36) f(37) f(38) f(39) f(40)
    f(41) f(42) f(43) f(44) f(45) f(46) f(47) f(48)
    f(49) f(50) f(51) f(52) f(53) f(54) f(55) f(56)
    f(57) f(58) f(59) f(60) f(61) f(62) f(63)

    return 64;
}
