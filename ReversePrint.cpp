//
// Created by Wanhui on 2/14/20.
//

#include "ReversePrint.h"
#include <stack>

std::vector<int> Solution06::reversePrint(ListNode *head) {
    if (head == nullptr) {
        return {};
    }

    std::stack<int> stk;
    while (head) {
        stk.push(head->val);
        head = head->next;
    }

    std::vector<int> vec;
    // WARNing : stk.top != 0 is wrong!!!
    while (!stk.empty()) {
        vec.push_back(stk.top());
        stk.pop();
    }

    return vec;
}

std::vector<int> Solution06::reversePrint2(ListNode *head) {
    std::vector<int> vec;
    reverse(head, vec);

    return vec;
}

void Solution06::reverse(ListNode *head, std::vector<int>& vec) {
    if(!head) {
        return;
    }
    reverse(head->next, vec);
    vec.push_back(head->val);
}
