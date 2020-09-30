/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL) return A;
    ListNode* temp = A;
    while(temp!=NULL){
        ListNode* nex = temp->next;
        while(nex!=NULL && temp->val == nex->val) nex = nex->next;
        temp->next = nex;
        temp = temp->next;
    }
return A;
}

//or
ListNode* Solution::deleteDuplicates(ListNode* A) {
  ListNode * temp = A;
  while(temp != NULL){
      while(temp->next && (temp->next)->val == temp->val){
          temp->next = (temp->next)->next;
      }
      temp = temp->next;
  }
return A;
}
