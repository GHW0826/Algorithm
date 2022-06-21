class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        else if (head->next == nullptr)
            return head;
        
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = head;
        while (next != nullptr) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};
