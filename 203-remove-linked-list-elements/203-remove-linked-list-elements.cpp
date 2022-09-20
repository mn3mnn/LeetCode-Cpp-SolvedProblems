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
        if (head == NULL){
            return head;
        }
        while (head->val == val && head != NULL){
            head = head->next;
            if (head == NULL){
            return head;
        }
            
        }
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = ptr1->next;

        while(ptr2 != NULL){

            if (ptr2->val == val){
                ptr2 = ptr2->next;
                ptr1->next = ptr2;
            }
            else{
                ptr1 = ptr2;
                ptr2 = ptr2->next;
            }
        }
        return head;

    }
};