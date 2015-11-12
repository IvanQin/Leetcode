#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode *p,*q;
	struct ListNode *adv=(struct ListNode *)malloc(sizeof(struct ListNode));
	int val;
	if (head==NULL) return head;
	adv->next=head;
	p=adv;
	if (p->next==NULL) return head;
	while (p){
			val=p->next->val;
			//printf ("val=%d\n",val);
			q=p->next->next;
			if (q && q->val==val){
				while (q && q->val==val) q=q->next;
				p->next=q;
			}
			else p=p->next;
			if (p->next==NULL) break;
			
	}
	//printf ("hellm\n");
	return adv->next;
}
struct ListNode* init(int n){
	struct ListNode *head=(struct ListNode*)malloc (sizeof(ListNode));
	head=NULL;
	int a;
	while (n--){
		struct ListNode *p=(struct ListNode*)malloc (sizeof(ListNode));
		scanf ("%d",&a);
		p->val=a;
		p->next=head;
		head=p;
		
	}
	return head;
} 
int main (){
	struct ListNode *head;
	int n;
	scanf ("%d",&n);
	head=init(n);
	//head=head->next;
	head=deleteDuplicates(head);
	while (head){
		printf ("%d ",head->val);
		head=head->next;
	}
}