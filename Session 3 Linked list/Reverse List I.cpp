/*
Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.
*/
ListNode* Solution::reverseList(ListNode* A) {
    ListNode* prev = NULL;
    ListNode* temp =A;
    ListNode* nex;
    while(temp != NULL){
     nex = temp->next;
     temp->next = prev;
     prev = temp;
     temp = nex;
    }
return prev;
}