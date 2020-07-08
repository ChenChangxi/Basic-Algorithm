//// A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
////
//// ·The left subtree of a node contains only nodes with keys less than the node's key.
//// ·The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//// ·Both the left and right subtrees must also be binary search trees.
////
//// A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.
////
//// Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.
////
//// Output Specification:
//// For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
//
//// Sample Input:
//// 10
//// 1 2 3 4 5 6 7 8 9 0
//
//// Sample Output:
//// 6 3 8 1 5 7 9 0 2 4
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct node {
//    int data,left,right;
//};
//
//vector<node> tree;
//
//vector<int> values;
//
//int nodes,value,counts;
//
//void dfs(int root) {
//    if(tree[root].left) dfs(tree[root].left);
//    tree[root].data=values[counts++];
//    if(tree[root].right) dfs(tree[root].right);
//}
//
//int main() {
//    cin>>nodes;
//    values.resize(nodes);tree.resize(nodes+1);
//    for(int i=0;i<nodes;++i) cin>>values[i];
//    sort(values.begin(),values.end());
//    for(int i=1;i<=nodes/2;++i) {
//        tree[i].left=2*i;tree[i].right=(2*i+1<=nodes?2*i+1:0);
//    }
//    dfs(1);
//    for(int i=1;i<=nodes;++i) cout<<tree[i].data<<(i!=nodes?" ":"");
//}
//
////说明：这道题给定一个序列，让你求出一棵树，它同时是二叉搜索树和完全二叉树。对于每一个给定序列，这样的树唯一。
//
////分析：这道题我第一次写的时候想得复杂了。首先，有这样一个事实，假如给定序列的长度确定，也就是二叉树的结点数确定，又知道它是完全二叉树，那么这棵树的形状就能确定。接着，根据中序遍历二叉搜索树得到的一定是有序序列，把序列排序。最后中序遍历这棵完全二叉树，将对应的值赋给每一个结点就能得到所求二叉树。
//
////注意：因为这题让求的是最后的层序序列，所以在构建完全二叉树的时候我认为每个节点的“索引”是它们在的层序“编号”，于是，构建这棵二叉树的工作就是把每个节点的左孩子设置为索引*2，右孩子设置为索引*2+1（完全二叉树的特性），那么我顺序遍历这个数组，就是层序遍历这棵二叉树（仔细思考为什么？）
