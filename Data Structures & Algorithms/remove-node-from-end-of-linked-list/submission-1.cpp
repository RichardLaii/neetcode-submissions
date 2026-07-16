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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* curr = head;
        ListNode* prev = &dummy;
        int len = 0;
        while (curr != nullptr){
            len++;
            curr = curr -> next;
        }
        
        for (int i = 0; i < len-n; i++){
            prev = prev -> next;
        }
        prev -> next = prev -> next -> next;

        return dummy.next;

    }
};
