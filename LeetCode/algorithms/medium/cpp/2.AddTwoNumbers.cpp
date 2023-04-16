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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int quo = (l1->val + l2->val) / 10;
        ListNode* answer = new ListNode((l1->val + l2->val) % 10);
        ListNode* ptr = answer;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr) {

            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int val = val1 + val2 + quo;
            quo = val / 10;

            ptr->next = new ListNode(val % 10);
            ptr = ptr->next;
            l1 = (l1 != nullptr) ? l1->next : l1;
            l2 = (l2 != nullptr) ? l2->next : l2;
        }
        if (quo > 0)
            ptr->next = new ListNode(quo);

        return answer;
    }
};
