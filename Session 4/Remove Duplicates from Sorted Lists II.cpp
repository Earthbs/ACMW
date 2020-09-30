/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL) return A;
    ListNode * dummy = new ListNode(0);
    dummy->next = A;
    ListNode* temp = dummy->next;
    ListNode * prev = dummy;
    while(temp != NULL){
        if(temp->next && temp->val == temp->next->val){
        while(temp->next && temp->val == temp->next->val){
            temp = temp->next;
        }
        prev->next = temp->next;
        }
        else prev = temp;
        temp = temp->next;
       
    }
   
return dummy->next;
} 

//or
//make 2 cases 0->1->1->2 and 0->1->2
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode * dummy = new ListNode(0);
    dummy->next = A;
    ListNode * temp = A;
    ListNode * prev = dummy;
    while(temp != NULL){
        int val = temp->val;
        if(temp->next && (temp->next)->val == val){ // don't include
            while(temp && temp->val == val){ //don't do while(temp->next), it will fail at 0->1->1
                temp = temp->next;
            }
             prev->next = temp;
             //dont change temp or prev
        }
        else{
            //only move prev and temp forward
            prev = temp;
            temp = temp->next;
        }
    }
    return dummy->next;
} 
