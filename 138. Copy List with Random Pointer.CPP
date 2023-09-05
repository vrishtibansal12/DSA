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
        Node *start = new Node(0);
        start->next=head;
        Node* move=head;
        
        while(move){
            Node* temp = new Node(move->val);
            //temp->val=move->val;
            temp->next=move->next;
            move->next=temp;
            move=move->next->next;
        }
        
        move=head;
        while(move){
            if(move->random)
                move->next->random=move->random->next;
            else
                move->next->random=NULL;
            move=move->next->next;
        }
        
        Node* temp;
        
        move=start;
        while(move->next){
            temp=move->next->next;
            move->next->next=move->next->next->next;
            move->next=temp;
            move=move->next;
        }
        // move=start->next;
        // while(move){
        //     cout<<move->val<<" ";
        //     move=move->next;
        // }
            
        return start->next;
        
    }
};