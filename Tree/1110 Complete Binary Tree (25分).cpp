//// Given a tree, you are supposed to tell if it is a complete binary tree.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤20) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.
////
//// Output Specification:
//// For each case, print in one line YES and the index of the last node if the tree is a complete binary tree, or NO and the index of the root if not. There must be exactly one space separating the word and the number.
//
//// Sample Input 1:
//// 9
//// 7 8
//// - -
//// - -
//// - -
//// 0 1
//// 2 3
//// 4 5
//// - -
//// - -
//
////Sample Output 1:
////YES 8
//
//// Sample Input 2:
//// 8
//// - -
//// 4 5
//// 0 6
//// - -
//// 2 3
//// - 7
//// - -
//// - -
//
//// Sample Output 2:
//// NO 1
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define SIZE 10000
//
//using namespace std;
//
//struct node {
//    int index,left,right,level;
//    bool operator < (const node &a) const {
//        return level<a.level;
//    }
//};
//
//vector<node> tree;
//
//int nodes,root=-1,nhash[SIZE];
//
//string lefts,rights;
//
//void dfs(int root,int level) {
//    if(tree[root].left!=-1) dfs(tree[root].left,2*level);
//    if(tree[root].right!=-1) dfs(tree[root].right,2*level+1);
//    tree[root].level=level;
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {
//        cin>>lefts>>rights;
//        tree.push_back(node{i,lefts=="-"?-1:stoi(lefts),rights=="-"?-1:stoi(rights)});
//        if(lefts!="-") nhash[stoi(lefts)]=1;if(rights!="-") nhash[stoi(rights)]=1;
//    }
//    while(nhash[++root]!=0);
//    dfs(root,1);
//    sort(tree.begin(),tree.end());
//    if(tree[nodes-1].level!=nodes) cout<<"NO "<<root;
//    else cout<<"YES "<<tree[nodes-1].index;
//}
//
////说明：给你一棵二叉树，你来判断是不是完全二叉树。
//
////分析：这题就是考察完全二叉树的性质的，将一个二叉树的节点按照如下规则进行编号：假设当前节点编号为i，规定左节点为2*i，右结点为2*i+1，这样递归进行。那么假如这个二叉树是完全二叉树，那么这棵树结点的最大编号必和二叉树的节点数相同。
//
////注意：根结点一定要从1开始编号，才有上面的性质。
