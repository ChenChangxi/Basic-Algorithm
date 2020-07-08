//// Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. And it is a simple standard routine to print the numbers in level-order. However, if you think the problem is too simple, then you are too naive. This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left. For example, for the following tree you must output: 1 11 5 8 17 12 20 15.
////
//// zigzag.jpg
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the inorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
//
//// Sample Input:
//// 8
//// 12 11 20 17 1 15 8 5
//// 12 20 17 11 15 8 5 1
//
//// Sample Output:
//// 1 11 5 8 17 12 20 15
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//struct node {
//    int data,level,index;
//    bool operator < (const node &a) const {
//        return level!=a.level?level<a.level:level%2==0?index<a.index:index>a.index;
//    }
//};
//
//vector<int> posord,inord;
//
//vector<node> levord;
//
//int nodes,value;
//
//void dfs(int inLeft,int posLeft,int posRight,int level,int index) {
//    if(posLeft<=posRight) {
//        int inroot=inLeft;while(inord[inroot]!=posord[posRight]) inroot++;
//        dfs(inLeft,posLeft,posLeft+inroot-inLeft-1,level+1,2*index);
//        dfs(inroot+1,posLeft+inroot-inLeft,posRight-1,level+1,2*index+1);
//        levord.push_back(node{posord[posRight],level,index});
//    }
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {cin>>value;inord.push_back(value);}
//    for(int i=0;i<nodes;++i) {cin>>value;posord.push_back(value);}
//    dfs(0,0,nodes-1,1,1);sort(levord.begin(),levord.end());
//    for(int i=0;i<nodes;++i) cout<<levord[i].data<<(i!=nodes-1?" ":"");
//}
//
////说明：这题给出后序序列和中序序列，让你输出zigzag（之字形，也就是从左到右然后再从右到左）形状的层序遍历序列。
//
////分析：这题不算难，在遍历过程中给每一个节点一个层序编号和节点所在层数，最后按照题目中的要求进行一个排序即可。
//
////注意：这种题的套路都是差不多的，定一个序列为“遍历”主序列，确定这个序列的根结点，然后确定这个根结点在另一个序列当中的位置，加上另一个序列的一个边界就能在“主序列”确定其中一棵子树大小，从而在“主序列”中唯一确定一棵二叉树。
