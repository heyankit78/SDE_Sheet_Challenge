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
    void reverse(ListNode* s,ListNode* e){
       ListNode* p = NULL,*curr = s,*n = s->next;
      
        while(p!=e){
          curr->next = p;
          p = curr;
          curr = n;
          if(n!=NULL)n=n->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1){
          return head;
        }
       ListNode* s = head,*e = head;
        int p = k-1;
        while(p!=0){
          e = e->next;
          p--;
          if(e == NULL)return head;
        }
      ListNode* next_head = reverseKGroup(e->next,k);
      reverse(s,e);
      s->next = next_head;
      return e;
      
    }
};
