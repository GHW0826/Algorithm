
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return false;
        vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        
       for (int i = 0; i < arr.size() / 2; ++i)
           if (arr[i] != arr[arr.size() - 1 - i])
               return false;
        return true;
    }
};

