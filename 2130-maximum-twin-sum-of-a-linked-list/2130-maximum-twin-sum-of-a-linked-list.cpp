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
    int pairSum(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* slow = head;
        int n=0;
        while(slow) {
            mp[n]= slow->val;
            n++;
            slow= slow->next;
        }
        int maxi=0;
       
        for(int i=0; i<n/2; i++) {
           maxi = max(maxi, mp[i] + mp[n-1-i]);
        }
        return maxi;
    }
};