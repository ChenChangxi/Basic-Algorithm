//// A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.
////
//// Input Specification:
//// Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (≤500) is the number of cities (and hence the cities are numbered from 0 to N−1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:
////
//// City1 City2 Distance Cost
////
//// where the numbers are all integers no more than 500, and are separated by a space.
////
//// Output Specification:
//// For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.
//
//// Sample Input:
//// 4 5 0 3
//// 0 1 1 20
//// 1 3 2 30
//// 0 3 4 10
//// 0 2 2 20
//// 2 3 1 20
//
//// Sample Output:
//// 0 2 3 3 40
//
//#include <iostream>
//#include <vector>
//#define SIZE 10000
//#define INF 99999999
//
//using namespace std;
//
//int nodes,edges,origin,target,scost=INF,visit[SIZE],weight[SIZE],adjmc[SIZE][SIZE],adjmd[SIZE][SIZE];
//
//vector<vector<int>> trace;vector<int> result,roads;
//
//void Dijkstra(int root) {
//    weight[root]=0;
//    for(int i=0;i<nodes;++i) {
//        int value=INF,index=0;
//        for(int j=0;j<nodes;++j) if(!visit[j]&&weight[j]<value) {value=weight[j];index=j;}
//        visit[index]=1;
//        for(int j=0;j<nodes;++j) {
//            if(!visit[j]&&adjmd[index][j]) {
//                int dis=weight[index]+adjmd[index][j];
//                if(dis<weight[j]) {trace[j].clear();trace[j].push_back(index);weight[j]=dis;}
//                else if(dis==weight[j]) trace[j].push_back(index);
//            }
//        }
//    }
//}
//
//void dfs(int root,int cost) {
//    roads.push_back(root);
//    if(root==origin) if(cost<scost) {scost=cost;result=roads;}
//    for(int i=0;i<trace[root].size();++i) dfs(trace[root][i],cost+adjmc[root][trace[root][i]]);
//    roads.pop_back();
//}
//
//int main() {
//    cin>>nodes>>edges>>origin>>target;fill(weight,weight+SIZE,INF);trace.resize(nodes);
//    for(int i=0,fnode,snode,cost,dis;i<edges;++i) {cin>>fnode>>snode>>dis>>cost;adjmd[fnode][snode]=adjmd[snode][fnode]=dis;adjmc[fnode][snode]=adjmc[snode][fnode]=cost;}
//    Dijkstra(origin);dfs(target,0);for(int i=(int)result.size()-1;i>=0;--i) cout<<result[i]<<" ";cout<<weight[target]<<" "<<scost;
//}
//
//
////说明：给出一张高速公路地图G，顶点为城市，边为城市之间的距离和代价，让你求一条从源点到目标点的一条最短距离路径，如果有多条，求那条代价最小的路径。
//
////分析：
//
////注意：
//
