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
        
        ListNode* sortedHead=(ListNode*)malloc(sizeof(ListNode));//虚拟头结点
        sortedHead->val=0x80000000;
        sortedHead->next=NULL;
        ListNode* s=(ListNode*)malloc(sizeof(ListNode));
        s->val=p->val;
        sortedHead->next=s;
        s->next=NULL;

        ListNode* preq=sortedHead;
        ListNode* q=sortedHead->next;

        while(p->next!=NULL){
            p=p->next;
            while(q!=NULL&&p->val>q->val){
                preq=q;
                q=q->next;
            }
            
            //插入操作
            ListNode* s=(ListNode*)malloc(sizeof(ListNode));
            s->val=p->val;
            s->next=preq->next;
            preq->next=s;
 
            preq=sortedHead;
            q=preq->next;
        }
        return sortedHead->next;
    }
};
