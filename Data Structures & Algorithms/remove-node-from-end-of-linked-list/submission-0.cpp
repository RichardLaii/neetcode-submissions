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
        ListNode* tail = &dummy;
        ListNode* curr = head;
        int len = 0;
        while ( curr != nullptr){
            len++;
            curr = curr -> next;
        }
        int cnt = 0;
        curr = head;
        while ( curr != nullptr){
            if (cnt != len - n){
                tail->next = new ListNode(curr->val);
                tail = tail -> next;
            }
            // don't need it, we can just jump to the next curr
            /*
            else{
                tail -> next = curr -> next;
                tail = tail -> next;
            }
            */
            curr = curr -> next;
            cnt++;
        }
        
        return dummy.next;
    }
};
