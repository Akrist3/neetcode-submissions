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
        vector<int> arr;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp -> val);
            temp = temp-> next;
        } 
        temp = head;
        int i = 0;
        int j = arr.size()-1;
        while(i <= j){
            temp -> val = arr[i++];
            temp = temp -> next;
            if(i <= j){
                temp -> val = arr[j--];
                temp = temp -> next;
            }
        }      
    }
};
