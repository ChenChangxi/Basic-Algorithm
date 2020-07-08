//// A proper vertex coloring is a labeling of the graph's vertices with colors such that no two vertices sharing the same edge have the same color. A coloring using at most k colors is called a (proper) k-coloring.
////
//// Now you are supposed to tell if a given coloring is a proper k-coloring.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers N and M (both no more than 10^4), being the total numbers of vertices and edges, respectively. Then M lines follow, each describes an edge by giving the indices (from 0 to N−1) of the two ends of the edge.
////
//// After the graph, a positive integer K (≤ 100) is given, which is the number of colorings you are supposed to check. Then K lines follow, each contains N colors which are represented by non-negative integers in the range of int. The i-th color is the color of the i-th vertex.
////
//// Output Specification:
//// For each coloring, print in a line k-coloring if it is a proper k-coloring for some positive k, or No if not.
//
//// Sample Input:
//// 10 11
//// 8 7
//// 6 8
//// 4 5
//// 8 4
//// 8 1
//// 1 2
//// 1 4
//// 9 8
//// 9 1
//// 1 0
//// 2 4
//// 4
//// 0 1 0 1 4 1 0 1 3 0
//// 0 1 0 1 4 1 0 1 0 0
//// 8 1 0 1 4 1 0 5 3 0
//// 1 2 3 4 5 6 7 8 8 9
//
//// Sample Output:
//// 4-coloring
//// No
//// 6-coloring
//// No
//
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#define SIZE 10000
//
//using namespace std;
//
//struct node {
//    int fnode,snode;
//};
//
//vector<node> graph;vector<int> colors;
//
//int nodes,edges,query;unordered_map<int,int> visit;
//
//int main() {
//    cin>>nodes>>edges;
//    for(int i=0,fnode,snode;i<edges;++i) {cin>>fnode>>snode;graph.push_back(node{fnode,snode});}
//    cin>>query;
//    for(int i=0,count=0;i<query;++i,count=0) {
//        for(int j=0,color;j<nodes;++j) {cin>>color;colors.push_back(color);visit[color]=1;}
//        for(int j=0;j<edges;++j) if(colors[graph[j].fnode]!=colors[graph[j].snode]) ++count;
//        if(count==edges) printf("%d-coloring\n",(int)visit.size());else printf("No\n");
//        visit.clear();colors.clear();
//    }
//}
//
////说明：给一个无向图G，现在有k种颜色，给图G中每一个顶点涂一种颜色，若任意一条边的两个顶点颜色不同，则把这种涂色叫做proper k-coloring。现在给出若干种涂色方案，问你每种涂色方案是不是proper coloring，如果是，一共有多少种颜色。
//
////分析：这题由于每一次的操作是检查每一条边的两个节点的颜色是不是相同的，所以建图的时候我用了点-边数组。对于给定的一种涂色序列，colors数组中index为顶点编号，value为所涂颜色。然后依次检查每条边的两个顶点在colors数组中的颜色是否相同，如果每条边的两个顶点颜色都不相同，那么它就是一个proper coloring。最后map是hash数组，它的大小就是颜色的个数。
