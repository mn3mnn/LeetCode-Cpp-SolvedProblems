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

    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;

        while (ptr2 != NULL && ptr2->next != NULL){
            // reverse the arrow between every two nodes 
            ListNode* tmp = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = tmp;
        }
        
        // reverse last arrow
        ptr2->next = ptr1;
        
        // set the next of the last node to null ptr
        head->next = NULL;

        return ptr2;

    }
};