class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<int, int> table;
        ListNode* p1 = nullptr;
        ListNode* p2 = head;
        ListNode* p3 = head;

        while (p3 != nullptr) {
            p3 = p3->next;
            if (table[p2->val] == 0) {
                ++table[p2->val];
                p1 = p2;
                p2 = p3;
            }
            else {
                p1->next = p3;
                p2 = p3;
            }
        }

        return head;
    }
};
