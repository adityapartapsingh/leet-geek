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
        vector<int> criticalPoints;
        int index = 1; // start from 1 for clarity
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next) {
            index++;
            int valPrev = prev->val, valCurr = curr->val, valNext = curr->next->val;

            if ((valCurr > valPrev && valCurr > valNext) || 
                (valCurr < valPrev && valCurr < valNext)) {
                criticalPoints.push_back(index);
            }

            prev = curr;
            curr = curr->next;
        }

        if (criticalPoints.size() < 2) return {-1, -1};

        int minDist = INT_MAX;
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDist = min(minDist, criticalPoints[i] - criticalPoints[i-1]);
        }

        int maxDist = criticalPoints.back() - criticalPoints.front();
        return {minDist, maxDist};
    }
};
