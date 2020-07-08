//// As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.
////
//// Input Specification:
//// Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, C(1) and C(2) - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c(1), c(2) and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C(1) to C(2).
////
//// Output Specification:
//// For each test case, print in one line two numbers: the number of different shortest paths between C(1) and C(2), and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
//
//// Sample Input:
//// 5 6 0 2
//// 1 2 1 5 3
//// 0 1 1
//// 0 2 2
//// 0 3 1
//// 1 2 1
//// 2 4 1
//// 3 4 1
//
//// Sample Output:
//// 2 4
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define SIZE 7000
//
//using namespace std;
//
//int nodes,edges,origin,target,teams,roads,adjm[SIZE][SIZE]; //邻接矩阵
//
//vector<int> values,visit,weight;
//
//vector<vector<int>> trace;
//
//void Dijkstra(int root) {
//    weight[root]=0;
//    for(int i=0;i<nodes;++i) {
//        int index=0,value=SIZE;
//        for(int j=0;j<nodes;++j) if(!visit[j]&&weight[j]<value) {value=weight[j];index=j;}
//        visit[index]=1;
//        for(int k=0;k<nodes;++k) {
//            value=weight[index]+adjm[index][k];
//            if(!visit[k]&&adjm[index][k]) {
//                if(value<weight[k]) {weight[k]=value;trace[k].clear();trace[k].push_back(index);}
//                else if(value==weight[k]) trace[k].push_back(index);
//            }
//        }
//    }
//}
//
//void dfs(int root,int rescue) {
//    if(root==origin) {roads++;teams=max(rescue,teams);}
//    for(int i=0;i<trace[root].size();++i)
//        dfs(trace[root][i],rescue+values[trace[root][i]]);
//}
//
//int main() {
//    cin>>nodes>>edges>>origin>>target;visit.resize(nodes);trace.resize(nodes);
//    for(int i=0,value;i<nodes;++i) {cin>>value;values.push_back(value);weight.push_back(SIZE);}
//    for(int i=0,fnode,snode,value;i<edges;++i) {cin>>fnode>>snode>>value;adjm[fnode][snode]=adjm[snode][fnode]=value;}
//    Dijkstra(origin);dfs(target,values[target]);cout<<roads<<" "<<teams;
//}
//
////说明：给一张城市地图，点代表救每个城市援队的数量，边代表城市间的距离，给出出目标城市，和你所在的城市，求一条到目标城市的最短路径，如果最短路径有多条，求救援队数量最多的那条。
//
////分析：非常典型的Dijkstra+回溯，在Dijkstra的过程中更新“源点”到某一个点a的“最短”路径，一旦发现一条比
