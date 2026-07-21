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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev= nullptr;
        ListNode* curr= head;
        while(curr) {
            ListNode* nextnode= curr->next;
            curr->next=prev;
            prev=curr;
            curr= nextnode;
        }
        ListNode* revhead= prev;
        int maxi= prev->val;
        while(prev && prev->next) {
            if(prev->next->val >= maxi) {
                maxi= prev->next->val;
                prev=prev->next;
            }
            else {
                prev->next= prev->next->next;
            }
        }
        ListNode* temp= nullptr;
        while(revhead) {
            ListNode* nnext = revhead->next;
            revhead->next= temp;
            temp= revhead;
            revhead= nnext;
        }
        return temp;
    }
};