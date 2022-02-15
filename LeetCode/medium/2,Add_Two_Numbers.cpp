class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode((l1->val + l2->val) % 10);
        ListNode* pMove = answer;
        int carry = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr) {
            int num1 = 0, num2 = 0;
            if (l1 != nullptr)
                num1 = l1->val;
            if (l2 != nullptr)
                num2 = l2->val;
            
            pMove->next = new ListNode((num1 + num2 + carry) % 10);
            pMove = pMove->next;
            
            if ((num1 + num2 + carry) >= 10)
                carry = 1;
            else
                carry = 0;
            
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (carry > 0)
            pMove->next = new ListNode(carry);
        
        return answer;
    }
};
