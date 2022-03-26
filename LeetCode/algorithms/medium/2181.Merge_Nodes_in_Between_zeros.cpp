class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* answer = new ListNode(0);
        ListNode* pMove = answer;
        head = head->next;
        while (head != nullptr) {
            if (head->val == 0) {
                if (head->next != nullptr) {
                    pMove->next = new ListNode(0);
                    pMove = pMove->next;
                }
            }
            pMove->val += head->val;
            head = head->next;
        }
        
        return answer;
    }
};
