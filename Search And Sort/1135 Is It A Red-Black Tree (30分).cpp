//// There is a kind of balanced binary search tree named red-black tree in the data structure. It has the following 5 properties:
////
//// ·(1) Every node is either red or black.
//// ·(2) The root is black.
//// ·(3) Every leaf (NULL) is black.
//// ·(4) If a node is red, then both its children are black.
//// ·(5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.
////
//// For example, the tree in Figure 1 is a red-black tree, while the ones in Figure 2 and 3 are not.
////
////                          rbf1.jpg    rbf2.jpg    rbf3.jpg
////                          Figure 1    Figure 2    Figure 3
////
//// For each given binary search tree, you are supposed to tell if it is a legal red-black tree.
////
//// Input Specification:
//// Each input file contains several test cases. The first line gives a positive integer K (≤30) which is the total number of cases. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the preorder traversal sequence of the tree. While all the keys in a tree are positive integers, we use negative signs to represent red nodes. All the numbers in a line are separated by a space. The sample input cases correspond to the trees shown in Figure 1, 2 and 3.
////
//// Output Specification:
//// For each test case, print in a line "Yes" if the given tree is a red-black tree, or "No" if not.
//
//// Sample Input:
//// 3
//// 9
//// 7 -2 1 5 -4 -11 8 14 -15
//// 9
//// 11 -2 1 -7 5 -4 8 14 -15
//// 8
//// 10 -7 5 -6 8 15 -11 17
//
//// Sample Output:
//// Yes
//// No
//// No
//
//#include <iostream>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//struct node {
//    int data,index,left,right;
//};
//
//int cases,nodes,root;vector<node> tree;vector<int> preord,inord;bool cmp(int a,int b) {return abs(a)<abs(b);}
//
//int dfs(int preLeft,int inLeft,int inRight) {
//    if(inLeft<=inRight) {
//        int inpos=inLeft,index=(int)tree.size();while(preord[preLeft]!=inord[inpos]) ++inpos;
//        tree.push_back(node{preord[preLeft],index});
//        tree[index].left=dfs(preLeft+1,inLeft,inpos-1);
//        tree[index].right=dfs(preLeft+inpos-inLeft+1,inpos+1,inRight);
//        return index;
//    } return -1;
//}
//
//int dfsmin(int root) {
//    return root==-1?0:min(dfsmin(tree[root].left),dfsmin(tree[root].right))+(tree[root].data<0?0:1);
//}
//
//int dfsmax(int root) {
//    return root==-1?0:max(dfsmax(tree[root].left),dfsmax(tree[root].right))+(tree[root].data<0?0:1);
//}
//
//int main() {
//    cin>>cases;
//    for(int i=0,counts=0;i<cases;++i) {
//        cin>>nodes;for(int j=0,value;j<nodes;++j,counts=0) {cin>>value;preord.push_back(value);}
//        inord=preord;sort(inord.begin(),inord.end(),cmp);
//        root=dfs(0,0,nodes-1);inord.clear();preord.clear();
//        for(int k=0,m,n,v,a,b;k<nodes;++k) {
//            v=tree[k].data;a=tree[k].left;b=tree[k].right;m=(a<0?0:tree[a].data);n=(b<0?0:tree[b].data);
//            counts=(dfsmax(k)==dfsmin(k)&&(v>0||(v<0&&m>=0&&n>=0))?counts+1:counts);
//        }
//        cout<<(tree[root].data>0&&counts==nodes?"Yes":"No")<<"\n";tree.clear();
//    }
//}
//
////说明：给你一棵二叉查找树，并给出每一个节点的颜色，让你判断是不是红黑树。
//
////分析：
//
////注意：段错误，爆栈，可能原因。
