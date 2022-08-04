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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        set<pair<int, int>> table;
        
        int i = 0;
        ListNode* node = head;
        while (node != nullptr) {
            table.insert(make_pair(node->val, i));
            node = node->next;
            ++i;
        }
        
        int pos = (*std::next(table.begin(), n)).second;
        ListNode* prev = head;
        ListNode* remove = head;
        while (pos > 0) {
            prev = remove;
            remove = remove->next;
            --pos;
        }
        prev->next = remove;
        return head;
    }
};
