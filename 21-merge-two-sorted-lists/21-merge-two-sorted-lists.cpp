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


    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy_node = new ListNode(-1);
        ListNode* list3 = dummy_node;
        ListNode* ptr3 = list3;

        while (list1 != NULL && list2 != NULL){
            if (list1->val < list2->val){
                ptr3->next = list1;
                ptr3 = ptr3->next;
                list1 = list1->next;
            }
            else{
                ptr3->next = list2;
                ptr3 = ptr3->next;
                list2 = list2->next;
            }
        }
        while (list1 != NULL){
            ptr3->next = list1;
            ptr3 = ptr3->next;
            list1 = list1->next;
        }
        while (list2 != NULL){
            ptr3->next = list2;
            ptr3 = ptr3->next;
            list2 = list2->next;
        }

        list3 = list3->next;
        delete dummy_node;
        return list3;
    }

};