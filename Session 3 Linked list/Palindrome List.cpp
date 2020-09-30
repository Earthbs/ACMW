/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
*/
ListNode * reverse(ListNode * A){
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

int Solution::lPalin(ListNode* A) {
    ListNode * temp = A;
    int count = 0;
    while(temp != NULL){count++; temp = temp->next;}
    if(count == 0 || count == 1) return 1;  //to avoid error at 39, if count = 1
    
    temp = A;
    ListNode * prev = NULL;
    int count2 = count/2;
    while(count2--){
        prev = temp;
        temp = temp->next;
    }
    
    if(count%2 != 0) temp = temp->next;
    ListNode * tempB = reverse(temp);
    
    ListNode * tempA = A;
    while(tempB != NULL){
        if(tempA->val != tempB->val) return 0;
        tempA = tempA->next; tempB = tempB->next;
    }
return 1;
}