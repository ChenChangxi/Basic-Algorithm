//// A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
////
//// ·The left subtree of a node contains only nodes with keys less than or equal to the node’s key.
//// ·The right subtree of a node contains only nodes with keys greater than the node’s key.
//// ·Both the left and right subtrees must also be binary search trees.
////
//// Insert a sequence of numbers into an initially empty binary search tree. Then you are supposed to count the total number of nodes in the lowest 2 levels of the resulting tree.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (<=1000) which is the size of the input sequence. Then given in the next line are the N integers in [-1000 1000] which are supposed to be inserted into an initially empty binary search tree.
////
//// Output Specification:
//// For each case, print in one line the numbers of nodes in the lowest 2 levels of the resulting tree in the format:
////
//// n1 + n2 = n
////
//// where n1 is the number of nodes in the lowest level, n2 is that of the level above, and n is the sum.
//
//// Sample Input:
//// 9
//// 25 30 42 16 20 20 35 -5 28
//
//// Sample Output:
//// 2 + 4 = 6
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//struct node {
//    int data,left,right,level;
//};
//
//vector<node> tree;
//
//int nodes,value,lnode,anode,root=-1,maxlev;
//
//int dfs(int root,int data,int level) {
//    if(root!=-1) data>tree[root].data?tree[root].right=dfs(tree[root].right,data,level+1):tree[root].left=dfs(tree[root].left,data,level+1);
//    else tree.push_back(node{data,-1,-1,level});return root==-1?(int)tree.size()-1:root;
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {cin>>value;root=dfs(root,value,1);}
//    for(int i=0;i<nodes;++i) maxlev=max(maxlev,tree[i].level);
//    for(int i=0;i<nodes;++i) tree[i].level==maxlev?lnode++:tree[i].level==maxlev-1?anode++:NULL;
//    printf("%d + %d = %d\n",lnode,anode,lnode+anode);
//}
//
////说明：给你一棵BST的插入序列，构建这棵BST并输出后两层的结点数。
//
////分析：首先输出后两层很简单，以前大量这种题，我就不多说了，我主要说说树存储方法的选取。这次我尝试了用索引法去构建BST，通常像搜索树这种数据结构在插入前它的形状是不确定的，所以得用链表法去建树。但同样也可以用索引来建树，假如当前节点不为空，他么就返回这个节点在tree数组中的索引，假如当前节点为空，就在tree数组中push一个node，它的索引就是tree的size-1，然后返回它的索引，这样递归进行，这样就能建树。这样的方法我在红黑树那题也用了，但这样的方法只适合于不做操作的搜索树，假如像AVL树那种还要旋转的，索引就比较麻烦了，建议还是用链表来写，但多一点尝试总是有好处的。
//
////注意：今天我算是见到奇观了，上面的代码在clang++编译器下面能AC，在g++编译器下AC不了，所以以后搞算法竞赛尽量用clang++编译器。
