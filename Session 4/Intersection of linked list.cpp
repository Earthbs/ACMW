/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

 Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
   ListNode * tempA = A; ListNode * tempB = B;
   int countA = 0; int countB = 0;
   while(tempA != NULL){
       countA++; tempA = tempA->next;
   }
   while(tempB != NULL){
       countB++; tempB = tempB->next;
   }
   tempA = A; tempB = B;
   int countC = abs(countA-countB);
   if(countA > countB){
       while(countC--){
           tempA = tempA->next;
       }
   }
   else{
       while(countC--){
           tempB = tempB->next;
       }
   }
   while(tempA != NULL && tempB != NULL){
       if(tempA == tempB) return tempA;
       tempA = tempA->next;
       tempB = tempB->next;
   }
   return NULL;
}