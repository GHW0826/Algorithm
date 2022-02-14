class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pRemovePre = head;
        ListNode* pRemove = head;
        ListNode* pMove = head;
        bool range = false;
        
        for (int i = 0; i < n; ++i)
            pMove = pMove->next;
        
        if (pMove == nullptr)
            range = true;
        while (pMove != nullptr) {
            pRemovePre = pRemove;
            pRemove = pRemove->next;
            pMove = pMove->next;
        }
        
        if (range == true)
            head = head->next;
        else
            pRemovePre->next = pRemove->next;
        
        return head;
    }
};
