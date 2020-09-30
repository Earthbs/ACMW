/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.
*/

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(A==NULL) return NULL;
   
    int count = 0;
    ListNode* temp = A;
    ListNode* node = NULL;
    while(temp != NULL){
        if(count == B) node = temp;
        temp = temp->next; count++;
    }
    if(count<=B) return A->next;
   
    temp = A;
    ListNode * prev = NULL;
    while(node != NULL){
        prev = temp;
        temp = temp->next;
        node = node->next;
    }
    prev->next = temp->next;
return A;
}

//or
//removeFromBegin is the number of jumps from the head, when temp will point to the node to be deleted
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
   if(A == NULL) return NULL;
   ListNode * temp = A;
   int count = 0;
   while(temp != NULL){
       count++; temp = temp->next;
   }
   if(count <= B){ //remove first element
       return A->next;
   }
   
   int removeFromBegin = count-B;
   ListNode * prev = NULL;
   temp = A;
   while(removeFromBegin--){
        prev = temp;
        temp = temp->next;
   }
   prev->next = temp->next;
   
return A;
}
