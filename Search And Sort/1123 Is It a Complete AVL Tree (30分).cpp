//// An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.
////
////                                   F1.jpg    F2.jpg
////                                   F3.jpg    F4.jpg
////
//// Now given a sequence of insertions, you are supposed to output the level-order traversal sequence of the resulting AVL tree, and to tell if it is a complete binary tree.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains a positive integer N (≤ 20). Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, insert the keys one by one into an initially empty AVL tree. Then first print in a line the level-order traversal sequence of the resulting AVL tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line. Then in the next line, print YES if the tree is complete, or NO if not.
//
//// Sample Input 1:
//// 5
//// 88 70 61 63 65
//
//// Sample Output 1:
//// 70 63 88 61 65
//// YES
//
//// Sample Input 2:
//// 8
//// 88 70 61 96 120 90 65 68
//
//// Sample Output 2:
//// 88 65 96 61 70 90 120 68
//// NO
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct node {
//    int data,index;
//    struct node *left,*right;
//    bool operator < (const node &a) const {
//        return index<a.index;
//    }
//};
//
//int nodes,value,subtract;node* root;
//
//vector<node> level;
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
//int getHeight(node* root) {     //树的“高度”
//    return root?max(getHeight(root->left),getHeight(root->right))+1:0;
//}
//
//int getSubtract(node *root) {   //求一棵树的“平衡因子”
//    return getHeight(root->right)-getHeight(root->left);
//}
//
//node* insert(int data,node* root) {    //在树上“插入”一个节点
//    if(root) data>root->data?root->right=insert(data,root->right):root->left=insert(data,root->left);
//    else {root=new node();root->data=data;}
//    return getSubtract(root)==2?getSubtract(root->right)==1?LeftRotate(root):RightLeftRotate(root):getSubtract(root)==-2?getSubtract(root->left)==-1?RightRotate(root):LeftRightRotate(root):root;
//}
//
//void dfs(node* root,int index) {   //遍历AVL树
//    if(root->left) dfs(root->left,2*index);if(root->right) dfs(root->right,2*index+1);
//    root->index=index;level.push_back(*root);
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {cin>>value;root=insert(value,root);}
//    dfs(root,1);sort(level.begin(),level.end());
//    for(int i=0;i<nodes;++i) cout<<level[i].data<<(i==nodes-1?"\n":" ");
//    cout<<(level[nodes-1].index==nodes?"YES":"NO");
//}
//
////说明：给一个序列，让你建立一个二叉平衡树，并输出它的层序遍历序例，并判断它是不是完全二叉树。平衡二叉树是左子树右右子树高度（也就是树的最大层数）之差的绝对值小于2的二叉平衡树，这个差叫做AVL树的“平衡因子”。
//
////分析：层序和完全二叉树已经很熟悉了，我主要说说建立二叉平衡树的过程。建立AVL树就是不断比较各节点的大小最后“下沉”到叶结点的过程，在插入后如果当前结点的“平衡因子”被破坏，需要进行调整，有四种情况，这四种情况又可以分为两大种情况，一是根结点和他的孩子结点的平衡因子是“同号”的，那么就只用左或者右调整，二是根结点和他的孩子结点的平衡因子是“异号”的，那么必须是左右都调整（画张图，思考为什么？），整个过程是递归进行的，直到AVL树建立完毕。
//
////注意：1、所有搜索树在建树之前它的形状是不清楚的（很像Java中的反射，一切都在运行时确定），这和以前遇到过的题不一样，因此不能用索引法来建树，必须用我们熟悉的链式存储法来建树。2、这里有个关键问题是假如不平衡（也就是某个节点平衡因子为2或者-2）时，它的孩子结点（高度较高的那个孩子）的平衡因子必为1或者-1（画张图，思考为什么？），因此我在讨论某结点的时候讨论了2，-2和其他情况（1，-1，0），而讨论它的孩子结点的时候只讨论了1和其他情况（-1）。3、可能我的代码写的比较飘逸，大家可以不按我那样写，就看看我的思路和分析，然后自己能写出来就行了。
