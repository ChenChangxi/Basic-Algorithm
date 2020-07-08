//// There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.
////
//// The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.
////
//// When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.
////
////                                        PBMC.jpg
////
//// The above figure illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S(3), we have 2 different shortest paths:
////
//// 1·PBMC -> S(1) -> S(3). In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S(1) and then take 5 bikes to S(3), so that both stations will be in perfect conditions.
////
//// 2·PBMC -> S(2) -> S(3). This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 4 numbers: C(max) (≤100), always an even number, is the maximum capacity of each station; N (≤500), the total number of stations; S(p), the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers C(i) (i=1,⋯,N) where each C(i) is the current number of bikes at S(i) respectively. Then M lines follow, each contains 3 numbers: S(i), S(j), and T(ij) which describe the time T(ij) taken to move betwen stations S(i) and S(j). All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in the format: 0−>S(1)−>⋯−>S(p) . Finally after another space, output the number of bikes that we must take back to PBMC after the condition of S(p) is adjusted to perfect.
////
//// Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.
//
//// Sample Input:
//// 10 3 3 5
//// 6 7 0
//// 0 1 1
//// 0 2 1
//// 0 3 3
//// 1 3 1
//// 2 3 1
//
//// Sample Output:
//// 3 0->2->3 0
//
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//#define SIZE 501
//#define INF 99999999
//
//using namespace std;
//
//int nodes,edges,target,perfect,send=INF,take=INF,weight[SIZE],visit[SIZE],values[SIZE],adjm[SIZE][SIZE];
//
//vector<vector<int>> trace;
//
//vector<int> result,road;
//
//void Dijkstra(int origin) {
//    weight[origin]=0;
//    for(int i=0;i<=nodes;++i) {
//        int value=INF,index=0;
//        for(int j=0;j<=nodes;++j) if(weight[j]<value&&!visit[j]) {value=weight[j];index=j;}
//        visit[index]=1;
//        for(int j=0;j<=nodes;++j) {
//            if(!visit[j]&&adjm[index][j]) {
//                value=weight[index]+adjm[index][j];
//                if(value<weight[j]) {weight[j]=value;trace[j].clear();trace[j].push_back(index);}
//                else if(value==weight[j]) trace[j].push_back(index);
//            }
//        }
//    }
//}
//
//void dfs(int root) {
//    road.push_back(root);
//    if(!root) {
//        int need=0,back=0;
//        for(int i=(int)road.size()-1;i>=0;--i) {
//            need=back+values[road[i]]<0?need+abs(back+values[road[i]]):need;
//            back=values[road[i]]>0?back+values[road[i]]:values[road[i]]+back>0?values[road[i]]+back:0;
//        }
//        if((need<send)||(need==send&&back<take)) {result=road;send=need;take=back;}
//    }
//    for(int i=0;i<trace[root].size();++i) dfs(trace[root][i]);
//    road.pop_back();
//}
//
//int main() {
//    cin>>perfect>>nodes>>target>>edges;trace.resize(nodes+1);
//    for(int i=1;i<=nodes;++i) {cin>>values[i];values[i]-=perfect/2;}
//    for(int i=0,fnode,snode,value;i<edges;++i) {cin>>fnode>>snode>>value;adjm[fnode][snode]=adjm[snode][fnode]=value;}
//    fill(weight,weight+SIZE,INF);Dijkstra(0);dfs(target);
//    cout<<send<<" ";for(int i=(int)result.size()-1;i>=0;--i) cout<<result[i]<<(!i?" ":"->");cout<<take;
//}
//
////说明：这题的逻辑属于PAT里面相当复杂的了，是ACM的那种味道（PAT前面的题有一部分是顶级难度的，因为以前没有顶级，这就相当于是顶级了）。给你一张杭州所有自行车站的一张图G，点代表自行车站当前所拥有的自行车数量，边代表自行车站之间的距离，自行车站有一个“最大容量”，当自行车站的自行车数等于最大容量的一半时，我们称这个自行车站处于“最佳情况”，否则我们就必须要进行调整，少于最佳要“送过去”，多于最佳要“带回来”。现在给出源点（自行车管理中心）和目标点（问题车站），让你求出一条由源点到目标点的最短路径，如果有多条，求出可以送去最少的那条，如果仍然有多条，选择可以带回来最少的那条。
//
////分析：1⃣️、这题很多同学可能会遍历这条路径求出所有顶点的总自行车数-顶点数*最佳数量，但这样做显然不符合题意，因为这题是单向调整的（双向调整可以那么做），也就是说是从原点到目标点这条路径的调整，从目标点返回原点的时候我们只把多余的自行车带回来，不再进行调整，每个顶点的调整和后面的顶点没有关系，只和前面的顶点有关（所谓的无后效性）。2⃣️、那么这题的意思就是我们每到一站，假如这一站的自行车数>最佳数量，我们就带着剩余的自行车继续往前走，假如这一站自行车数<最佳数量，我们需要用我们以前从其他站带过来的自行车放在这里进行调整，直到走到终点站，假如此时有多余的自行车，那么我们就需要带回源点，假如此时自行车不够，那么我们就需要在出发时带一定数量的自行车。3⃣️、那么做法就是对dfs的时候每求的出一条路径，我们都需要从源点开始模拟一下上面这个过程，假设在开始时我们需要带回的自行车（back）和送去的自行车（send）都为0，假如这一站的自行车数大于最佳数量，back增加，假如这一站的自行车数量小于最佳数量，我们让前面积累的back去“补”，back减少，如果back不够补，那么我们就需要在开始的时候带，send增加。我们对每个顶点都求send和back，求到终点进行比较判断即可。4⃣️、在这个过程中，可以看出，send增加（低于最佳且back不够补）或者不变（高于最佳或者back够补），back增加（高于最佳），减少（低于最佳）或者不变（等于最佳），send是对每个不够的顶点进行累加的，back则是动态调整的。
//
////注意：这题我对每个顶点的自行车数目的都减去最佳数目（最大容量的一半），那么假如这个顶点为正数就表示剩余，为负数就表示不够，这样在dfs的时候就省了很多判断的代码。
