class Solution {
public:
    ListNode* removeElements(ListNode* head, int&val) {
        if(head==NULL){
            return NULL;
        }
        ListNode*newNode=new ListNode(NULL);
        newNode->next=head;
        ListNode*prev=newNode;
        ListNode*curr=head;
        while(curr!=NULL){
            if(curr->val==val){
               ListNode*temp=curr;
                prev->next=curr->next;
                curr=curr->next;
               delete(temp);
            }
            else{
               prev=curr;
               curr=curr->next;
            }
        }
        return newNode->next;
    }
};