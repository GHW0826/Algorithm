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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        vector<int> number;
        while (head != nullptr) {
            number.push_back(head->val);
            head = head->next;
        }
        
        sort(number.begin(), number.end());
        ListNode* newHead = new ListNode(number[0]);
        ListNode* pmove = newHead;
        for (int i = 1; i < number.size(); ++i) {
            ListNode* newNode = new ListNode(number[i]);
            pmove->next = newNode;
            pmove = pmove->next;
        }

        return newHead;
    }
};
