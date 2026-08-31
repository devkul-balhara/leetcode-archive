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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = -1, cnt = 0;
        vector<int> indices;
        while(head->next != NULL){
            int curr = head->val;
            int next = head->next->val;
            if(prev != -1 && (curr > prev && curr > next || curr < next && curr < prev)) indices.push_back(cnt);
            head = head->next;
            prev = curr;
            cnt++;
        }
        if(indices.size() < 2) return {-1,-1};
        int mini = 1e6;
        for(int i = 0; i < indices.size()-1; i++){
            mini = min(mini, indices[i+1]-indices[i]);
        }
        int maxi = indices.back()-indices[0];
        return {mini,maxi};
    }
};