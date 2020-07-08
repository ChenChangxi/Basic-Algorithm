//// In graph theory, an Eulerian path is a path in a graph which visits every edge exactly once. Similarly, an Eulerian circuit is an Eulerian path which starts and ends on the same vertex. They were first discussed by Leonhard Euler while solving the famous Seven Bridges of Konigsberg problem in 1736. It has been proven that connected graphs with all vertices of even degree have an Eulerian circuit, and such graphs are called Eulerian. If there are exactly two vertices of odd degree, all Eulerian paths start at one of them and end at the other. A graph that has an Eulerian path but not an Eulerian circuit is called semi-Eulerian. (Cited from https://en.wikipedia.org/wiki/Eulerian_path)
////
//// Given an undirected graph, you are supposed to tell if it is Eulerian, semi-Eulerian, or non-Eulerian.
////
//// Input Specification:
//// Each input file contains one test case. Each case starts with a line containing 2 numbers N (≤ 500), and M, which are the total number of vertices, and the number of edges, respectively. Then M lines follow, each describes an edge by giving the two ends of the edge (the vertices are numbered from 1 to N).
////
//// Output Specification:
//// For each test case, first print in a line the degrees of the vertices in ascending order of their indices. Then in the next line print your conclusion about the graph -- either Eulerian, Semi-Eulerian, or Non-Eulerian. Note that all the numbers in the first line must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line.
//
//// Sample Input 1:
//// 7 12
//// 5 7
//// 1 2
//// 1 3
//// 2 3
//// 2 4
//// 3 4
//// 5 2
//// 7 6
//// 6 3
//// 4 5
//// 6 4
//// 5 6
//
//// Sample Output 1:
//// 2 4 4 4 4 4 2
//// Eulerian
//
//// Sample Input 2:
//// 6 10
//// 1 2
//// 1 3
//// 2 3
//// 2 4
//// 3 4
//// 5 2
//// 6 3
//// 4 5
//// 6 4
//// 5 6
//
//// Sample Output 2:
//// 2 4 4 4 3 3
//// Semi-Eulerian
//
//// Sample Input 3:
//// 5 8
//// 1 2
//// 2 5
//// 5 4
//// 4 1
//// 1 3
//// 3 2
//// 3 4
//// 5 3
//
//// Sample Output 3:
//// 3 3 4 3 3
//// Non-Eulerian
//
//#include <iostream>
//#include <map>
//#include <vector>
//#define SIZE 10000
//
//using namespace std;
//
//int nodes,edges,even,connect,visit[SIZE];
//
//map<int,vector<int>> graph;
//
//void dfs(int root) {if(!visit[root]) {visit[root]=1;for(int i=0;i<graph[root].size();++i) dfs(graph[root][i]);}}
//
//int main() {
//    cin>>nodes>>edges;
//    for(int i=0,fnode,snode;i<edges;++i) {cin>>fnode>>snode;graph[fnode].push_back(snode);graph[snode].push_back(fnode);}
//    for(int i=1;i<=nodes;++i)
//        {if(!visit[i]) {++connect;dfs(i);} cout<<graph[i].size()<<(i!=nodes?" ":"\n");!(graph[i].size()%2)?even++:NULL;}
//    cout<<(nodes==even&&connect==1?"Eulerian":even==nodes-2&&connect==1?"Semi-Eulerian":"Non-Eulerian");
//}
//
////说明：欧拉路径是指一条不重复遍历所有边的路径（哈密顿路径是不重复遍历所有点），假如这条欧拉路径路径起始点和结束点一样，则称它是欧拉回路。题中给你了判定方法，假如每个节点度都是偶数，则是欧拉回路，假如只有两个节点度为奇数，它是一条欧拉路径，但不是一条回路，其他情况都不是欧拉路径。现在给你一个图，问你这张图有没有欧拉路径或者欧拉回路。
//
////分析：用邻接表来存图，这样我们在对每个顶点dfs后可以直接知道它的度是多少，便于统计和输出。
//
////注意：题目中说的很清楚，只有连通图才考虑欧拉路径，所以必须得有一个dfs来统计连通分量。
