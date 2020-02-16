//
// Created by Wanhui on 2/16/20.
//

#include "MinArray.h"

int Solution11::minArray(std::vector<int> &numbers) {
    if(numbers.empty()){
        return 0;
    }

    int min = numbers[0];
    for(int i = 1; i < numbers.size(); i++){
        if(min>numbers[i]) min = numbers[i];
    }

    return min;
}

int Solution11::minArray2(std::vector<int> &numbers) {
    if(numbers.empty()){
        return 0;
    }

    int left = 0, rigth = numbers.size() - 1, mid = 0;

    while (left < rigth) {
        mid = left + (rigth - left) / 2;
        if(numbers[mid] < numbers[rigth]){
            rigth = mid;
        } else if(numbers[mid] > numbers[rigth]) {
            left = mid+1;
        } else {
            rigth--;
        }
    }

    return numbers[left];
}

