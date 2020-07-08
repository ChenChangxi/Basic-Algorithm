//// A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.
////
//// Input Specification:
//// Each input file contains one test case. Each case starts with two positive integers N (<100) which is the total number of family members in the tree (and hence assume that all the members are numbered from 01 to N), and M (<N) which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:
////
//// ID K ID[1] ID[2] ... ID[K]
////
//// where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such a generation is unique, and the root level is defined to be 1.
//
//// Sample Input:
//// 23 13
//// 21 1 23
//// 01 4 03 02 04 05
//// 03 3 06 07 08
//// 06 2 12 13
//// 13 1 21
//// 08 2 15 16
//// 02 2 09 10
//// 11 2 19 20
//// 17 1 22
//// 05 1 11
//// 07 1 14
//// 09 1 17
//// 10 1 18
//
//// Sample Output:
//// 9 4
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define SIZE 100000
//
//using namespace std;
//
//vector<vector<int>> tree;
//
//int nodes,branchs,childs,identity,total,levels[SIZE],mnode,clevel;
//
//void dfs(int root,int level) {
//    levels[level]++;total=max(total,level);
//    if(!tree[root].empty()) {
//        for(int i=0;i<tree[root].size();++i) {
//            dfs(tree[root][i],level+1);
//        }
//    }
//}
//
//int main() {
//    cin>>nodes>>branchs;
//    tree.resize(nodes+1);
//    for(int i=0;i<branchs;++i) {
//        cin>>identity>>childs;
//        tree[identity].resize(childs);
//        for(int j=0;j<childs;++j) cin>>tree[identity][j];
//    }
//    dfs(1,1);
//    for(int i=1;i<=total;++i) {
//        if(levels[i]>mnode) {clevel=i;mnode=levels[i];}
//    }
//    printf("%d %d",mnode,clevel);
//}
//
////说明：这题需要你求出一棵树所有层中结点最多的层，以及这一层的结点数。
//
////分析：dfs的时候传一个level，遍历整个树的时候统计每一层的结点个数，最后遍历levels数组求最多的节点数及所在层。
//
////注意：这种求一个序列的最大值以及它的索引这种方法以后会经常见到，还有就是不知道一共有几层，所以在dfs要求树的层。
