//// A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
////
//// ·The left subtree of a node contains only nodes with keys less than the node's key.
//// ·The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//// ·Both the left and right subtrees must also be binary search trees.
////
//// Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.
////
////                                      figBST.jpg
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format left_index right_index, provided that the nodes are numbered from 0 to N−1, and 0 is always the root. If one child is missing, then −1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.
////
//// Output Specification:
//// For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.
//
//// Sample Input:
//// 9
//// 1 6
//// 2 3
//// -1 -1
//// -1 4
//// 5 -1
//// -1 -1
//// 7 -1
//// -1 8
//// -1 -1
//// 73 45 11 58 82 25 67 38 42
//
//// Sample Output:
//// 58 25 82 11 38 67 45 73 42
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct node {
//    int left,right,data,index;
//    bool operator < (const node &a) const {
//        return index<a.index;
//    }
//};
//
//vector<node> tree;
//
//vector<int> values;
//
//int nodes,lefts,rights,value,counts;
//
//void dfs(int root,int index) {
//    if(root!=-1) {
//        dfs(tree[root].left,2*index);
//        tree[root].data=values[counts++];tree[root].index=index;
//        dfs(tree[root].right,2*index+1);
//    }
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {cin>>lefts>>rights;tree.push_back(node{lefts,rights});}
//    for(int i=0;i<nodes;++i) {cin>>value;values.push_back(value);}
//    sort(values.begin(),values.end());dfs(0,1);sort(tree.begin(),tree.end());
//    for(int i=0;i<nodes;++i) cout<<tree[i].data<<(i==nodes-1?"\n":" ");
//}
//
////说明：
//
////分析：
//
////注意：
