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
        vector<int>ans(2,-1);
        vector<int>criticalPointIdx;
        int idx=1;
        ListNode* curr=head->next,*prev=head;
        while(curr->next!=NULL){
            if((curr->val>prev->val && curr->val>curr->next->val) || (curr->val<prev->val && curr->val<curr->next->val)){
                criticalPointIdx.push_back(idx);
            }
            idx++;
            prev=curr;
            curr=curr->next;
        }
        
        if(criticalPointIdx.size()<2) return ans;

        int minDistance=INT_MAX,maxDistance=criticalPointIdx.back()-criticalPointIdx[0];

        for(int i=1;i<criticalPointIdx.size();i++){
            minDistance=min(minDistance,criticalPointIdx[i]-criticalPointIdx[i-1]);
        }
        ans[0]=minDistance;
        ans[1]=maxDistance;
        return ans;
        
    }
};