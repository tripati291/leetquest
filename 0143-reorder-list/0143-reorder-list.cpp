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
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow= slow->next;
            fast= fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next= nullptr;

        ListNode* prev= nullptr;
        ListNode* cur= second;

        while(cur) {
            ListNode* nextnode= cur->next;
            cur->next= prev;
            prev=cur;
            cur= nextnode;
        }
        ListNode* first= head;
        while(prev) {
            ListNode* temp1= first->next;
            ListNode* temp2= prev->next;
            first->next = prev;
            prev->next= temp1;

            first= temp1;
            prev= temp2;

        }
        
    }
};

// divide the list into 2 halves 
//reverse the second half 
//alternatively take one element from one list and attach one element to the next list to it