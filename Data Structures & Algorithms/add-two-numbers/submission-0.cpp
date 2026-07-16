/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        int carry = 0, digit;
        int sum = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0){
            int x = 0, y = 0;
            if (l1)
                x = l1->val;
            if (l2)
                y = l2->val;
            sum = x + y + carry;
            digit = sum % 10;
            carry = sum / 10;
            tail->next = new ListNode(digit);
            tail = tail->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return dummy.next;
    }
};
