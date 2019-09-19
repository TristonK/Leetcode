/**
 * Definition for singly-linked list.
 */
 #include<bits/stdc++.h>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

////28 ms	10.3 MB

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1flag=(l1==NULL);
        int l2flag=(l2==NULL);
        int carrybit=0;
        if(l1flag){
            return l2;
        }
        if(l2flag){
            return l1;
        }
        ListNode* l3 = new ListNode(0);
        ListNode* cur = l3;
        while(l1!=NULL||l2!=NULL||carrybit){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carrybit;
            carrybit = 0;
            if(sum>=10){
                carrybit = 1;
                sum-=10;
            }
            cur->next = new ListNode(sum);
            cur=cur->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return l3->next;
    }
};