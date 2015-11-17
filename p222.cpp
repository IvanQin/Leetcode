#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
/*int ans,maxn,num;
bool exist;
void deal(){
      ans=(1<<maxn)-1+num;
}
void DFS(struct TreeNode* root,int depth) {
    if (exist) return;
    if (depth>maxn){
      maxn=depth;
      num=0;
    }
    if (root->left==NULL && root->right==NULL){
          if (depth==maxn)
            num++;
          else exist=true;
    }
    if (root->left)
      DFS(root->left,depth+1);
    if (root->right)
      DFS(root->right,depth+1);
}
int countNodes(struct TreeNode* root) {
    if (root==NULL) return 0;
    exist=false;
    maxn=-1;
    DFS(root,0);
    deal();
    return ans;
}*/
int countNodes(struct TreeNode* root){
  //leftmost & rightmost
 int depth;
  if (root==NULL) return 0;
  struct TreeNode *r=root->right;
  struct TreeNode *l=root->left;
  depth=1;
  while (l && r){
    l=l->left;
    r=r->right;
    depth++;
  }
  if (l==NULL && r==NULL) return (1<<depth) -1;
  else return countNodes(root->left)+countNodes(root->right)+1; 
}
struct TreeNode* init (){
      struct TreeNode *root=(struct TreeNode*)malloc (sizeof(struct TreeNode));
      struct TreeNode *node1=(struct TreeNode*)malloc (sizeof(struct TreeNode));
      struct TreeNode *node2=(struct TreeNode*)malloc (sizeof(struct TreeNode));
      struct TreeNode *node3=(struct TreeNode*)malloc (sizeof(struct TreeNode));
      struct TreeNode *node4=(struct TreeNode*)malloc (sizeof(struct TreeNode));
      root->left=node1;
      root->right=node2;
      node1->left=node3;
      node1->right=node4;
      node2->left=NULL;
      node2->right=NULL;
      node3->left=NULL;
      node3->right=NULL;
      node4->left=NULL;
      node4->right=NULL;
      return root;
}
int main (){
      struct TreeNode *root=(struct TreeNode*)malloc (sizeof(struct TreeNode));
      root=init();
      printf ("%d\n",countNodes(root));
      return 0;
}