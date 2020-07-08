//// A clique is a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. A maximal clique is a clique that cannot be extended by including one more adjacent vertex. (Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))
////
//// Now it is your job to judge if a given subset of vertices can form a maximal clique.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers Nv (≤ 200), the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.
////
//// After the graph, there is another positive integer M (≤ 100). Then M lines of query follow, each first gives a positive number K (≤ Nv), then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each of the M queries, print in a line Yes if the given subset of vertices can form a maximal clique; or if it is a clique but not a maximal clique, print Not Maximal; or if it is not a clique at all, print Not a Clique.
//
//// Sample Input:
//// 8 10
//// 5 6
//// 7 8
//// 6 4
//// 3 6
//// 4 5
//// 2 3
//// 8 2
//// 2 7
//// 5 3
//// 3 4
//// 6
//// 4 5 4 3 6
//// 3 2 8 7
//// 2 2 3
//// 1 1
//// 3 4 3 6
//// 3 3 2 1
//
//// Sample Output:
//// Yes
//// Yes
//// Yes
//// Yes
//// Not Maximal
//// Not a Clique
//
//#include <iostream>
//#include <algorithm>
//#define SIZE 100000
//
//using namespace std;
//
//int nodes,edges,query,visit[SIZE],graph[SIZE][SIZE];
//
//int main() {
//    cin>>nodes>>edges;
//    for(int i=0,fnode,snode;i<edges;++i) {cin>>fnode>>snode;graph[fnode][snode]=graph[snode][fnode]=1;}
//    cin>>query;
//    for(int i=0,node,clique=1,total=0;i<query;++i,clique=1,total=0) {
//        cin>>node;fill(visit,visit+SIZE,0);
//        for(int j=0,value;j<node;++j) {cin>>value;visit[value]=1;}
//        for(int j=1,count=0;j<=nodes;++j,count=0) {
//            for(int k=1;k<=nodes;++k) {
//                if(visit[j]&&visit[k]&&!graph[j][k]&&j!=k) clique=0;if(!visit[j]&&visit[k]&&graph[j][k]) ++count;
//            }
//            total=max(total,count);
//        }
//        cout<<(!clique?"Not a Clique":total==node?"Not Maximal":"Yes")<<"\n";
//    }
//}
//
////说明：简单无向图G的一个子图为S，假如S中任意两点都相邻，那么就称S为G的一个Clique，假如G-S中不存在一个节点，使这个节点加入S后的新图仍然是一个Clique，那么原S就是Maximal（Clique）。现在给出若干点集，问你每个点集是不是Clique或者Maximal。
//
////分析：用邻接矩阵存图，设置一个visit数组，每输入一个点就把visit数组中相应的点置为1，表示它在当前输入的集合中。然后两两比较图中所有的点，假如这两个点都在集合中（visit都为1），但却不相邻，说明输入的集合不是Clique，我们同时统计不在集合中的某点（visit为0）和集合中所有点（visit为1）相邻的个数total，假如total等于集合大小，说明它和集合中所有点相邻，把它加入集合仍然是Clique，说明它不是Maximal（Clique），否则就是Maximal（Clique）。
//
////注意：你不能在判断某个不在集合中的点和集合中所有点相邻后立马输出NotMaximal，因为后面还有可能出现某两个在集合中的点不相邻这种情况，所以一定要全部比较完之后再去判断。
