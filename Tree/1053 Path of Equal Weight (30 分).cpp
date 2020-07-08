//// Given a non-empty tree with root R, and with weight W(i) assigned to each tree node T(i). The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.
////
//// Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in the following figure: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in the figure.
////
//// Input Specification:
//// Each input file contains one test case. Each case starts with a line containing 0<N≤100, the number of nodes in a tree, M (<N), the number of non-leaf nodes, and 0<S<2^30, the given weight number. The next line contains N positive numbers where W(i) (<1000) corresponds to the tree node T(i). Then M lines follow, each in the format:
////
//// ID K ID[1] ID[2] ... ID[K]
////
//// where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.
////
//// Output Specification:
//// For each test case, print all the paths with weight S in non-increasing order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.
////
//// Note: sequence {A(1),A(2),⋯,A(n)} is said to be greater than sequence {B(1),B(2),⋯,B(m)} if there exists 1≤k<min{n,m} such that A(i)=B(i) for i=1,⋯,k, and A(k+1)>B(k+1).
//
//// Sample Input:
//// 20 9 24
//// 10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
//// 00 4 01 02 03 04
//// 02 1 05
//// 04 2 06 07
//// 03 3 11 12 13
//// 06 1 09
//// 07 2 08 10
//// 16 1 15
//// 13 3 14 16 17
//// 17 2 18 19
//
//// Sample Output:
//// 10 5 2 7
//// 10 4 10
//// 10 3 3 6 2
//// 10 3 3 6 2
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//vector<int> weight,trace;
//
//vector<vector<int>> tree,paths;
//
//int nodes,branchs,sum,weigh,identity,childs;
//
//bool cmp(int a,int b) {
//    return weight[a]>weight[b];
//}
//
//void dfs(int root,int counts,vector<int> trace) {
//    trace.push_back(root);
//    if(!tree[root].empty()) {
//        for(int i=0;i<tree[root].size();++i) {
//            dfs(tree[root][i],counts+weight[tree[root][i]],trace);
//        }
//    } else if(counts==sum) paths.push_back(trace);
//}
//
//int main() {
//    cin>>nodes>>branchs>>sum;
//    tree.resize(nodes);weight.resize(nodes);
//    for(int i=0;i<nodes;++i) cin>>weight[i];
//    for(int i=0;i<branchs;++i) {
//        cin>>identity>>childs;
//        tree[identity].resize(childs);
//        for(int j=0;j<childs;++j) cin>>tree[identity][j];
//        sort(tree[identity].begin(),tree[identity].end(),cmp);
//    }
//    dfs(0,weight[0],trace);
//    for(int i=0;i<paths.size();++i) {
//        for(int j=0;j<paths[i].size();++j) {
//            cout<<weight[paths[i][j]]<<(j==paths[i].size()-1?"\n":" ");
//        }
//    }
//}
//
////说明：这题就是让求从根到叶的某一条路径，这条路径上所有点的权值之和等于给定sum。
//
////分析：那么这题就是用dfs，每一层额外传一个权值和以及路径上点的数组，一旦到了叶结点，就比对这条路径上权值跟给定数值的大小，如果相等，就把这条路径加入到我们求的路径数组当中，最后输出路径数组中的每一条路径即可
//
////注意：路径1>路径2的意思是，路径1和路径2从左到右逐个元素相比，比到第一个不相等的数，这个数是路径1>路径2的。那么这道题我把每一个结点的所有孩子结点按照权值从大到小进行排列，最后我dfs的时候求出的路径就一定是从大到小的（大家可以自己思考一下为什么），这也是这道题的巧妙之处。
