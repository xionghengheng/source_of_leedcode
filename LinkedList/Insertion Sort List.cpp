/*
注意：
1.当新链表要插入最小值时，即插入一个新的头结点，那么原来的指向头结点的指针要更换。sortedList=s;使得sortedList指针也指向s所指的节点。（s为新头结点）
2.注意q和preq的关系，插入最大结点时，preq为最后一个结点，而q为NULL，所以循环条件是q!=NULL
*/

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode* p=head;
        ListNode* sortedList=(ListNode*)malloc(sizeof(ListNode));
        sortedList->val=p->val;
        sortedList->next=NULL;
        ListNode* q=sortedList;
        ListNode* preq=NULL;
        bool notmove=true;
        while(p->next!=NULL){
            p=p->next;
            while(q!=NULL&&p->val>q->val){
                preq=q;
                q=q->next;
                notmove=false;
            }
            
            ListNode* s=(ListNode*)malloc(sizeof(ListNode));
            if(notmove){
                if(p->val>q->val)
                    {s->val=p->val;q->next=s;s->next=NULL;}//插入尾部
                else 
                    {s->val=p->val;s->next=q;sortedList=s;}//插入头部
            }else{
                if(q==NULL)
                {
                    if(p->val>preq->val)
                       {s->val=p->val;preq->next=s;s->next=NULL;}//插入尾部
                }
                else{s->val=p->val;s->next=preq->next;preq->next=s;}//插入中间
            }
            q=sortedList;
            preq=NULL;
            notmove=true;
        }
        return sortedList;
    }
};
