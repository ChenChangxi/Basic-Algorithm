//// A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
////
//// Input Specification:
//// Each input file contains one test case. Each case starts with a line containing 0<N<100, the number of nodes in a tree, and M (<N), the number of non-leaf nodes. Then M lines follow, each in the format:
////
//// ID K ID[1] ID[2] ... ID[K]
////
//// where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
////
//// The input ends with N being 0. That case must NOT be processed.
////
//// Output Specification:
//// For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
////
//// The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output 0 1 in a line.
//
//// Sample Input:
//// 2 1
//// 01 1 02
//
//// Sample Output:
//// 0 1
//
//#include <iostream>
//#include <vector>
//#define SIZE 10000
//
//using namespace std;
//
//vector<vector<int>> tree;
//
//int counts[SIZE],nodes,childs,branchs,identity,depth;
//
//void dfs(int root,int level) {
//    if(level>depth) depth=level;
//    if(!tree[root].empty()) {
//        for(int i=0;i<tree[root].size();++i) {
//            dfs(tree[root][i],level+1);
//        }
//    } else counts[level]++;
//}
//
//int main() {
//    cin>>nodes>>branchs;
//    tree.resize(nodes+1);
//    for(int i=0;i<branchs;++i) {
//        cin>>identity>>childs;
//        tree[identity].resize(childs);
//        for(int j=0;j<childs;++j) {
//            cin>>tree[identity][j];
//        }
//    }
//    dfs(1,0);
//    for(int i=0;i<=depth;++i) {
//        cout<<counts[i]<<(i==depth?"":" ");
//    }
//}
//
////说明：这题没啥难的，虽然30分，但仍属于水题之列。
//
////分析：统计每一层叶子结点的个数，在dfs的时候加一个level即可，如果某一个结点没有孩子，那么它就是叶子结点，在hash数组中将对应层数的叶子结点个数加一，最后遍历整个hash数组，输出每一层的叶子结点数。
//
////注意：得求这棵树的深度，输出的时候需要用。
