class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);

        int idx = 1;
        int firstCritical = -1;
        int prevCritical = -1;
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {

            // Check if curr is a critical point
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                // First critical point
                if (firstCritical == -1) {
                    firstCritical = idx;
                }
                else {
                    // Distance from previous critical point
                    minDistance = min(minDistance, idx - prevCritical);
                }

                prevCritical = idx;
            }

            idx++;
            prev = curr;
            curr = curr->next;
        }

        // Less than 2 critical points
        if (firstCritical == -1 || firstCritical == prevCritical)
            return ans;

        // Maximum distance = last - first
        ans[0] = minDistance;
        ans[1] = prevCritical - firstCritical;

        return ans;
    }
};