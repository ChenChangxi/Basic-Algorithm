//// In computer science, a heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. A common implementation of a heap is the binary heap, in which the tree is a complete binary tree. (Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))
////
//// One thing for sure is that all the keys along any path from the root to a leaf in a max/min heap must be in non-increasing/non-decreasing order.
////
//// Your job is to check every path in a given complete binary tree, in order to tell if it is a heap or not.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (1<N≤1,000), the number of keys in the tree. Then the next line contains N distinct integer keys (all in the range of int), which gives the level order traversal sequence of a complete binary tree.
////
//// Output Specification:
//// For each given tree, first print all the paths from the root to the leaves. Each path occupies a line, with all the numbers separated by a space, and no extra space at the beginning or the end of the line. The paths must be printed in the following order: for each node in the tree, all the paths in its right subtree must be printed before those in its left subtree.
////
//// Finally print in a line Max Heap if it is a max heap, or Min Heap for a min heap, or Not Heap if it is not a heap at all.
//
//// Sample Input 1:
//// 8
//// 98 72 86 60 65 12 23 50
//
//// Sample Output 1:
//// 98 86 23
//// 98 86 12
//// 98 72 65
//// 98 72 60 50
//// Max Heap
//
//// Sample Input 2:
//// 8
//// 8 38 25 58 52 82 70 60
//
//// Sample Output 2:
//// 8 25 70
//// 8 25 82
//// 8 38 52
//// 8 38 58 60
//// Min Heap
//
//// Sample Input 3:
//// 8
//// 10 28 15 12 34 9 8 56
//
//// Sample Output 3:
//// 10 15 8
//// 10 15 9
//// 10 28 34
//// 10 28 12 56
//// Not Heap
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int nodes,m,n;vector<int> tree,seq;
//
//void dfs(int root) {
//    seq.push_back(root);int i=2*root+1,j=2*root+2;
//    if(i>=nodes&&j>=nodes) for(int i=0;i<seq.size();++i) printf("%d%s",tree[seq[i]],(i==seq.size()-1?"\n":" "));
//    if(j<nodes) dfs(j);if(i<nodes) dfs(i);seq.pop_back();
//}
//
//int main() {
//    cin>>nodes;for(int i=0,value;i<nodes;++i) {cin>>value;tree.push_back(value);}
//    for(int i=1;i<nodes;++i) if(tree[i]>tree[(i+1)/2-1]) n=1;else m=1;dfs(0);
//    if(m&&!n) printf("Max Heap");else if(!m&&n) printf("Min Heap");else printf("Not Heap");
//}
//
////说明：给一棵完全二叉树，让你判断这棵二叉树是大顶堆，小顶堆，还是不是堆，最后从右向左输出从根到叶的所有路径。
//
////分析：判断堆的在1147题分析过，求所有路径做一个镜像先序的回溯即可，关于回溯和遍历的区别也在Graph里有详细说明。
