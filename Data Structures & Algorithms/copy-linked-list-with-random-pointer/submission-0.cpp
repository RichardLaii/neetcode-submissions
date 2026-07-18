/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* newHead = nullptr;
        Node* tail = nullptr;
        Node* curr = head;

        while (curr){
            Node* newNode = new Node(curr->val);
            mp[curr] = newNode;

            if (newHead == nullptr){
                newHead = newNode;
                tail = newHead;
            }
            else{
                tail -> next = newNode;
                tail = tail -> next;
            }
            curr = curr -> next;
        }
        curr = head;
        while (curr){
            Node* copy = mp[curr];
            copy -> random = mp[curr -> random];
            curr = curr -> next;
        }
        return newHead;
    }
};
