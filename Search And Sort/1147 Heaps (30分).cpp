//// In computer science, a heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. A common implementation of a heap is the binary heap, in which the tree is a complete binary tree. (Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))
////
//// Your job is to tell if a given complete binary tree is a heap.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers: M (≤ 100), the number of trees to be tested; and N (1 < N ≤ 1,000), the number of keys in each tree, respectively. Then M lines follow, each contains N distinct integer keys (all in the range of int), which gives the level order traversal sequence of a complete binary tree.
////
//// Output Specification:
//// For each given tree, print in a line Max Heap if it is a max heap, or Min Heap for a min heap, or Not Heap if it is not a heap at all. Then in the next line print the tree's postorder traversal sequence. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line.
//
//// Sample Input:
//// 3 8
//// 98 72 86 60 65 12 23 50
//// 8 38 25 58 52 82 70 60
//// 10 28 15 12 34 9 8 56
//
//// Sample Output:
//// Max Heap
//// 50 60 65 72 12 23 86 98
//// Min Heap
//// 60 58 52 38 82 70 25 8
//// Not Heap
//// 56 12 34 28 9 8 15 10
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define SIZE 10000
//
//using namespace std;
//
//int nodes,query,m,n,a,b;vector<int> tree,poso;
//
//void dfs(int root) {if(root<nodes) {dfs(2*root+1);dfs(2*root+2);poso.push_back(tree[root]);}}
//
//int main() {
//    cin>>query>>nodes;
//    for(int i=0;i<query;++i) {
//        for(int j=0,value;j<nodes;++j) {cin>>value;tree.push_back(value);} m=n=0;
//        for(int i=1;i<nodes;++i) if(tree[(i+1)/2-1]>tree[i]) m=1;else n=1;dfs(0);
//        if(m&&!n) printf("Max Heap\n");else if(!m&&n) printf("Min Heap\n");else printf("Not Heap\n");
//        for(int j=0;j<nodes;++j) printf("%d%s",poso[j],j!=nodes-1?" ":"\n");poso.clear();tree.clear();
//    }
//}
//
////说明：给一棵完全二叉树，让你判断这棵二叉树是大顶堆，小顶堆，还是不是堆，最后输出这棵二叉树的后序遍历序列。
//
////分析：简单的后根dfs，然后判断除根结点外每一个节点与它的“父节点”之间的关系，如果它比父节点大，则n置1，如果它比父节点小，m置1。如果这棵二叉树是堆，则m和n有且仅有一个为1，m为1是大顶堆，n为1是小顶堆，否则就不是堆。
//
////注意：这题假如判断第i个节点和它孩子结点的关系得定很多边界，直接判断与其父节点的关系就显得很简洁。第i个节点的父节点为i/2（从0开始的话是（i+1）/2-1），孩子结点为2*i和2*i+1（从0开始是2*i+1和2*i+2）。
