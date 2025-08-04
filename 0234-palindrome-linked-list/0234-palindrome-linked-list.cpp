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
    bool isPalindrome(ListNode* head) {
        //find middle
        ListNode* fast= head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //reverse the second half
        ListNode* curr= slow;
        ListNode* temp = NULL;
       while(curr){
         ListNode* newnode= curr->next;
            curr->next = temp;
            temp = curr;
            curr= newnode;
            }

//check both linked list
ListNode* first = head;
ListNode* second = temp;
while(second){
if(first->val != second->val)return false;
    first=first->next;
    second= second->next;
}
return true;
    }
};