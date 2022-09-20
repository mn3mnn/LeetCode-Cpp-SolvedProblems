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
        
        if (head == NULL){
            return false;
        }

        vector<ListNode*> vec;
        vec.push_back(NULL);
        ListNode *tmp = head;

        while (tmp->next != NULL){
            if (std::find(vec.begin(), vec.end(), tmp) != vec.end()){
                return true;
            }
            vec.push_back(tmp);
            tmp = tmp->next;
        }
        return false;

    }
};

