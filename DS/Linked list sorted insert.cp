void sortedInsert(struct node** head, int x)
{
    struct node* cur=*head;
    struct node* pre;
    if((*head)->data > x){
        struct node *temp = new struct node(x);
        temp->next  = *head;
        *head = temp;
    }
    else{
        while(cur!=NULL){
            if(cur->data >x)
                break;
            pre = cur;
            cur = cur->next;  
        }
        struct node *temp = new struct node(x);
        pre->next = temp;
        temp->next = cur;
        
    }
    
    
}