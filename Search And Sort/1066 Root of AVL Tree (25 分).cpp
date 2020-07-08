//// An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
////
//// Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print ythe root of the resulting AVL tree in one line.
//
//// Sample Input 1:
//// 5
//// 88 70 61 96 120
//
//// Sample Output 1:
//// 70
//
//// Sample Input 2:
//// 7
//// 88 70 61 96 120 90 65
//
//// Sample Output 2:
//// 88
//
//#include <iostream>
//
//using namespace std;
//
//struct node {
//    int data;
//    struct node *left,*right;
//};
//
//int nodes,value;node* root;
//
//node* LeftRotate(node* root) {
//    node* rnew=root->right;root->right=rnew->left;rnew->left=root;return rnew;
//}
//
//node* RightRotate(node* root) {
//    node* rnew=root->left;root->left=rnew->right;rnew->right=root;return rnew;
//}
//
//node* LeftRightRotate(node* root) {
//    root->left=LeftRotate(root->left);return RightRotate(root);
//}
//
//node* RightLeftRotate(node* root) {
//    root->right=RightRotate(root->right);return LeftRotate(root);
//}
//
//int getHeight(node* root) {
//    return root?max(getHeight(root->left),getHeight(root->right))+1:0;
//}
//
//int getSubstruct(node* root) {
//    return getHeight(root->right)-getHeight(root->left);
//}
//
//node* insert(int data,node* root) {
//    if(root) data>root->data?root->right=insert(data,root->right):root->left=insert(data,root->left);
//    else {root=new node();root->data=data;}
//    return getSubstruct(root)==2?getSubstruct(root->right)==1?LeftRotate(root):RightLeftRotate(root):getSubstruct(root)==-2?getSubstruct(root->left)==-1?RightRotate(root):LeftRightRotate(root):root;
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {
//        cin>>value;root=insert(value,root);
//    }
//    cout<<root->data;
//}
//
////说明：AVL树的插入过程我在1123题已经非常详细的分析过了，在这里我就不分析了，详见1123。
