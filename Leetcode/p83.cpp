#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode *p;
	struct ListNode *q;
	int val;
	if (head==NULL) return head;
	p=head;
	if (p->next==NULL) return head;
	while (p){
		val=p->val;
		q=p->next;
		while (q && q->val==val) q=q->next;
		p->next=q;
		p=q;
	}
	return head;
}
struct ListNode* init(int n){
	int a;
	struct ListNode *head=(struct ListNode *)malloc (sizeof(struct ListNode));
	head->next=NULL;

	while (n--){
		struct ListNode *p=(struct ListNode *)malloc (sizeof(struct ListNode));
		scanf ("%d",&a);
		p->val=a;
		p->next=head->next;
		head->next=p;
	}
	return head;
}
int main (){
	struct ListNode *head;
	int n;
	scanf ("%d",&n);
	head=init(n);
	head=deleteDuplicates(head);
	head=head->next;
	while (head){
		printf ("%d ",head->val);
		head=head->next;
	}
	printf ("\n");
	return 0;
}