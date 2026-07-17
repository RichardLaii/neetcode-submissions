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
    void reorderList(ListNode* head) {
        ListNode* first = head, *slow = head;
        ListNode* fast = head->next;
        ListNode* sec;
        while (fast && fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        sec = slow -> next;
        slow -> next = nullptr;
        ListNode* prev = nullptr,* curr = sec,* next;
        while (curr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* firstNext;
        ListNode* secNext;
        while (prev){
            firstNext = first -> next;
            secNext = prev -> next;
            first -> next = prev;
            prev -> next = firstNext;
            prev = secNext;
            first = firstNext;
        }

    }
};
