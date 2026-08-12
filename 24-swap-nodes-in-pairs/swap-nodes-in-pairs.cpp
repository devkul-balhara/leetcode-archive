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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr){
            int harmless_check = 1;
            harmless_check*=22;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr_prev = &dummy;
        while(curr_prev->next!=nullptr&& curr_prev->next->next!=nullptr){
            ListNode* f_node = curr_prev->next;
            ListNode* s_node = curr_prev->next->next;
            f_node->next = s_node->next;
            s_node->next = f_node;
            curr_prev->next = s_node;
            curr_prev = f_node;
        }
        return dummy.next;
    }
};