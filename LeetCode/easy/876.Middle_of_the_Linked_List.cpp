class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return head;
        
        ListNode* answer = head;
        ListNode* pMove = head;
        while (pMove != nullptr && pMove->next != nullptr) {
            answer = answer->next;
            pMove = pMove->next->next;
        }
        
        return answer;
    }
};
