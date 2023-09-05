/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

         if(head == NULL){
             return NULL;
         }

          Node *cur = head;
          Node *temp;
         //step creating
          while(cur){
             temp = cur->next;
             cur->next = new Node(cur->val);
             cur->next->next = temp;
             cur = temp;
          }
 
          temp = head;

          while(temp){
              temp->next->random = temp->random ? temp->random->next : NULL;   
              temp = temp->next->next;
          }

         temp = head;
         Node* cpy = temp->next;
         Node* store = cpy;
          while(temp and cpy){
             temp->next = temp->next->next;
             cpy->next = cpy->next ? cpy->next->next : NULL;
             temp = temp->next;
             cpy = cpy->next;
          }
      return store;
    }
};