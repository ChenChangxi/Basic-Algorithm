//// The following is from Max Howell @twitter:
////
//// Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
////
//// Now it's your turn to prove that YOU CAN invert a binary tree!
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node from 0 to N−1, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.
////
//// Output Specification:
//// For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
//
//// Sample Input:
//// 8
//// 1 -
//// - -
//// 0 -
//// 2 7
//// - -
//// - -
//// 5 -
//// 4 6
//
//// Sample Output:
//// 3 7 2 6 4 0 5 1
//// 6 5 7 4 3 2 0 1
//
//#include <iostream>
//#include <string>
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
//vector<int> inorder;
//
//string lefts,rights;
//
//int nodes,root,counts,nhash[SIZE];
//
//void dfs(int root,int level) {
//    if(tree[root].right!=-1) dfs(tree[root].right,2*level);
//    tree[root].level=level;inorder.push_back(root);
//    if(tree[root].left!=-1) dfs(tree[root].left,2*level+1);
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {
//        cin>>lefts>>rights;
//        tree.push_back(node{i,lefts=="-"?-1:stoi(lefts),rights=="-"?-1:stoi(rights)});
//        if(lefts!="-") nhash[stoi(lefts)]=1;if(rights!="-") nhash[stoi(rights)]=1;
//    }
//    for(int i=0;i<nodes;++i) if(!nhash[i]) root=i;
//    dfs(root,1);
//    sort(tree.begin(),tree.end());
//    for(int i=0;i<nodes;++i) cout<<tree[i].index<<(i==nodes-1?"\n":" ");
//    for(int i=0;i<nodes;++i) cout<<inorder[i]<<(i==nodes-1?"":" ");
//}
//
////说明：让你倒转一棵二叉树（所谓倒转的意思就是每一个结点的左右孩子交换），最后输出倒转二叉树的层序和中序序列。
//
////分析：这题建完树之后其实不用做任何操作，求翻转二叉树的中序序列我们只需要对二叉树进行一个“镜像”的中序遍历即可，在镜像中序遍历过程中我们可以求出每一个结点在“镜像完全二叉树”中的序号，这个序号就是层序索引，最后将所有结点按照层序索引进行排序，我们就能够得到层序序列。（即使这棵树不是完全二叉树也没有关系，思考为什么？）
//
////注意：1、本题的难点其实是二叉树的存储方式，这个不好理解，简单来说就是我们给二叉树每个节点一个标号，这个标号就是这个结点在数组中的索引，那么left就是左孩子在数组中的索引，right就是右孩子在数组中的索引（注意，这个不是层序索引，这是人为规定的序号，和1064题有所区别），那么没有在孩子结点中出现的索引即为这个二叉树根结点的索引。2、这题最后要输出的是原来的索引，但是在层序排序的时候原来的顺序会被打乱，因此每个节点要保存它们最初索引用来输出。
