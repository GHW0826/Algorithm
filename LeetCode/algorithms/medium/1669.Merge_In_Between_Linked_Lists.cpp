class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pMove = list1;
        ListNode* pHead = nullptr;
        ListNode* pLast = nullptr;
        int cnt = 0;
        
        while (1) {
            if (cnt == a - 1)
                pHead = pMove;
            else if (cnt == b + 1) {
                pLast = pMove;
                break;
            }
            
            ++cnt;
            pMove = pMove->next;
        }
        pHead->next = list2;
        
        while (list2->next != nullptr)
            list2 = list2->next;
        list2->next = pLast;
        
        return list1;
    }
};
