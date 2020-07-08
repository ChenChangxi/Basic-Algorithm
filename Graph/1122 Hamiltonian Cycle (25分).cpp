//// The "Hamilton cycle problem" is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a "Hamiltonian cycle".
////
//// In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<N≤200), the number of vertices, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format Vertex1 Vertex2, where the vertices are numbered from 1 to N. The next line gives a positive integer K which is the number of queries, followed by K lines of queries, each in the format:
////
//// n V1 V2 ... Vn
////
//// where n is the number of vertices in the list, and Vi's are the vertices on a path.
////
//// Output Specification:
//// For each query, print in a line YES if the path does form a Hamiltonian cycle, or NO if not.
//
//// Sample Input:
//// 6 10
//// 6 2
//// 3 4
//// 1 5
//// 2 5
//// 3 1
//// 4 1
//// 1 6
//// 6 3
//// 1 2
//// 4 5
//// 6
//// 7 5 1 4 3 6 2 5
//// 6 5 1 4 3 6 2
//// 9 6 2 1 6 3 4 5 2 6
//// 4 1 2 5 1
//// 7 6 1 3 4 5 2 6
//// 7 6 1 2 5 4 3 1
//
//// Sample Output:
//// YES
//// NO
//// NO
//// NO
//// YES
//// NO
//
//#include <iostream>
//#include <vector>
//#define SIZE 10000
//
//using namespace std;
//
//int nodes,edges,query,visit[SIZE],graph[SIZE][SIZE];
//
//vector<int> sequen;
//
//int main() {
//    cin>>nodes>>edges;
//    for(int i=0,fnode,snode;i<edges;++i) {cin>>fnode>>snode;graph[fnode][snode]=graph[snode][fnode]=1;}
//    cin>>query;
//    for(int i=0,node,ham=1;i<query;++i,ham=1) {
//        cin>>node;
//        for(int j=0,value;j<node;++j) {cin>>value;sequen.push_back(value);}
//        for(int j=0;j<node-1;++j)
//            if(visit[sequen[j]]||!graph[sequen[j]][sequen[j+1]]) ham=0;else visit[sequen[j]]=1;
//        cout<<(ham&&node==nodes+1&&sequen[0]==sequen[node-1]?"YES\n":"NO\n");
//        fill(visit,visit+SIZE,0);sequen.clear();
//    }
//}
//
////说明：哈密顿路径是一条不重复包含所有顶点的“回路”（很像我们通常所说的dfs），现在给一条路径，让你判断是不是哈密顿回路。
//
////分析：我们只需关注哈密顿回路的特点即可。1、除了首尾节点必须相同，输入序列中任何节点互不相同。2、输入序列中的节点数有且仅有节点数+1个。3、序列中任意相邻的两个节点在图中相邻。
//
////注意：第三点很容易忽视，本题由于我们判断不重复的点从0～n-2，判断相邻也是从0～n-2，所以不用额外对其他点进行处理。
