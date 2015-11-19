#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
         int val;
         struct TreeNode *left;
         struct TreeNode *right;
     };
void createTree(struct TreeNode* root){
    struct TreeNode *sub1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *sub2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *sub3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    //struct TreeNode sub1,sub2;
    root->left=sub1;
    root->right=sub2;
    sub1->left=NULL;
    sub2->left=NULL;
    sub1->right=NULL;
    sub2->right=sub3;
    sub3->left=NULL;
    sub3->right=NULL;
    
}
int depth;
int max (int a,int b){
    if (a==-1) return b;
    else return a>b?a:b;
}
void DFS (struct TreeNode *root,int d){
    if (root->left==NULL && root->right==NULL)
    depth=max(depth,d);
    if (root->left)
    DFS(root->left,d+1);
    if (root->right)
    DFS(root->right,d+1);
}

int maxDepth(struct TreeNode *root) {
    depth=-1;
    if (!root) return 0;
    DFS(root,1);
    return depth;
}

int main (){
    struct TreeNode *tree=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    createTree(tree);
    printf ("%d\n",maxDepth(tree));
    printf ("No you are not");
    
}
