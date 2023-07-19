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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        while(head && head->val==val)
            head=head->next;
        ListNode* start=head;
        while(start && start->next){
            if(start->next->val==val){
                start->next=start->next->next;
            }
            else
                start=start->next;
        }
        return head;
    }
};