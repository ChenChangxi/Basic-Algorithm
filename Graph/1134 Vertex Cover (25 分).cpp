//// A vertex cover of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. Now given a graph with several vertex sets, you are supposed to tell if each of them is a vertex cover or not.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers N and M (both no more than 10^4), being the total numbers of vertices and the edges, respectively. Then M lines follow, each describes an edge by giving the indices (from 0 to N−1) of the two ends of the edge.
////
//// After the graph, a positive integer K (≤ 100) is given, which is the number of queries. Then K lines of queries follow, each in the format:
////
//// N(v) v[1] v[2]⋯v[Nv]
////
//// where N(v) is the number of vertices in the set, and v[i]'s are the indices of the vertices.
////
//// Output Specification:
//// For each query, print in a line Yes if the set is a vertex cover, or No if not.
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
//// 5
//// 4 0 3 8 4
//// 6 6 1 7 5 4 9
//// 3 1 8 4
//// 2 2 8
//// 7 9 8 7 6 5 4 2
//
//// Sample Output:
//// No
//// Yes
//// Yes
//// No
//// No
//
//#include <iostream>
//#include <vector>
//#define SIZE 10000
//
//using namespace std;
//
//vector<vector<int>> graph;
//
//int nodes,edges,query,visit[SIZE];
//
//int main() {
//    cin>>nodes>>edges;graph.resize(nodes);
//    for(int i=0,fnode,snode;i<edges;++i) {cin>>fnode>>snode;graph[fnode].push_back(i);graph[snode].push_back(i);}
//    cin>>query;
//    for(int i=0,value,count=0;i<query;++i,count=0) {
//        cin>>value;fill(visit,visit+SIZE,0);
//        for(int j=0,node;j<value;++j) {cin>>node;for(int k=0;k<graph[node].size();++k) visit[graph[node][k]]=1;}
//        for(int j=0;j<edges;++j) count=visit[j]?count+1:count;cout<<(count==edges?"Yes":"No")<<"\n";
//    }
//}
//
////说明：给你一张无向图G，现在有一个点的集合为V，一个边的集合为E，如果某一节点a出现在V中，就把G中所有连接a的边加入到E中（或者叫把所有以a为顶点的边加入E中），假如E包含G中的所有边，那么我们把这个V叫做G的VertexCover。现在给你若干点集，让你判断它是不是VertexCover。
//
////分析：这题在输入的时候我们默认的给每条边一个“编号”，采用了一个邻接表来存每个节点的所有边的编号（跟以前不同，这也说明选数据结构的时候不能太死板，要按题中要求来弄）。对于给的一个点集，我们遍历每个点的所有边，把相应边在visit数组中的位置设置为1，最后遍历visit数组，假如1的个数为所给的边数，那么这个点集就“包含”了所有边，就输出Yes。
