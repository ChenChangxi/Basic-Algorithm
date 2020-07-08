//// Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences, or preorder and inorder traversal sequences. However, if only the postorder and preorder traversal sequences are given, the corresponding tree may no longer be unique.
////
//// Now given a pair of postorder and preorder traversal sequences, you are supposed to output the corresponding inorder traversal sequence of the tree. If the tree is not unique, simply output any one of them.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 30), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, first printf in a line Yes if the tree is unique, or No if not. Then print in the next line the inorder traversal sequence of the corresponding binary tree. If the solution is not unique, any answer would do. It is guaranteed that at least one solution exists. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
//
//// Sample Input 1:
//// 7
//// 1 2 3 4 6 7 5
//// 2 6 7 4 5 3 1
//
//// Sample Output 1:
//// Yes
//// 2 1 6 4 7 3 5
//
//// Sample Input 2:
//// 4
//// 1 2 3 4
//// 2 4 3 1
//
//// Sample Output 2:
//// No
//// 2 1 3 4
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> posord,preord,inorder;
//
//int nodes,value,flag;
//
//void dfs(int preLeft,int preRight,int posLeft,int posRight) {
//    if(preLeft<=preRight) {
//        int posin=posRight;while(--posin>=posLeft&&posord[posin]!=preord[preLeft+1]);
//        dfs(preLeft+1,preLeft+posin-posLeft+1,posLeft,posin); //默认preLeft+1为左子树根
//        inorder.push_back(preord[preLeft]);
//        flag=posRight-posin>1||posLeft==posRight?flag:flag+1;
//        dfs(preLeft+posin-posLeft+2,preRight,posin+1,posRight-1);
//    }
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {cin>>value;preord.push_back(value);}
//    for(int i=0;i<nodes;++i) {cin>>value;posord.push_back(value);}
//    dfs(0,nodes-1,0,nodes-1);
//    printf("%s\n",flag>0?"No":"Yes");
//    for(int i=0;i<nodes;++i) printf("%d%s",inorder[i],i!=nodes-1?" ":"\n");
//}
//
////说明：给出一棵二叉树的先序和后序序列，求出它的中序序列，如果不唯一，那么求出任意中序序列。
//
////分析：给定一个二叉树的先序和后序序列，是无法唯一确定一棵二叉树的，关键是要找先序序列中根结点的左孩子在后序序列当中的位置，如果后序序列中这个左孩子和根结点中间有元素，这棵二叉树就是确定的，否则这棵二叉树就是不确定的，以这个孩子为根结点的子树可能是这个二叉树的左子树，也可能是这棵二叉树的右子树。比如先序是”1” 2 3 4 ，后序是4 3 2 “1”，（1为根结点）那么此时2这个结点既可以看作是左子树的根结点（根据先序），也可以看作是右子树的根结点（根据后序），但假如先序是“1” 2 4 3，后序是4 2 3 ”1“，那么此时2这个节点必为左子树的根结点（思考为什么？）。
//
////注意：1、本题我们在划分序列的时候默认了先序序列中preLeft+1是左子树的根结点，以此为依据我们找到后序序列中和preLeft+1相等的节点，我们认为它是后序序列中左子树的根结点，当不确定情况发生后右子树会发生越界，因此不需要额外进行判断（先定右子树也是一样，我第一次刷的时候就是先定的右子树）。2、本题在找posin的时候会在左右两个边界出现问题即：preRight在最左和preLeft在最右都会发生越界，而这两种情况都发生在叶结点上，此时posin一定是小于posLeft的，所以加上一个判断就可以避免数组越界。（while(a&&b)中，当a为false，就不再判断b，直接退出循环。）
