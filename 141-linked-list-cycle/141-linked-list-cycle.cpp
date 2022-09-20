/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:

    bool hasCycle(ListNode *head) {

        if (head == NULL || head->next==NULL){
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            if (slow == fast){
                return true;
            }

            slow = slow->next;
            fast = fast->next->next;
        }
        return false;

    }


//     bool hasCycle(ListNode *head) {

//         if (head == NULL || head->next==NULL){
//             return false;
//         }

//         map<ListNode*, int> mp;
//         ListNode *tmp = head;

//         while (tmp->next != NULL){
//             mp[tmp]++;
//             if (mp[tmp] > 1){
//                 return true;
//             }
//             tmp = tmp->next;
//         }

//         return false;
//     }
};

