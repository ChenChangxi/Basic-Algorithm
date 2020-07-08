//// It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.
////
//// For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.
////
//// Input Specification:
//// Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.
////
//// Output Specification:
//// For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.
//
//// Sample Input:
//// 3 2 3
//// 1 2
//// 1 3
//// 1 2 3
//
//// Sample Output:
//// 1
//// 0
//// 0
//
//#include <iostream>
//#define SIZE 10000
//
//using namespace std;
//
//int nodes,edges,checks,visit[SIZE],adjm[SIZE][SIZE];
//
//void dfs(int root,int expel) {
//    if(!visit[root]&&root!=expel) {
//        visit[root]=1;
//        for(int i=1;i<=nodes;++i) if(adjm[root][i]) dfs(i,expel);
//    }
//}
//
//int main() {
//    cin>>nodes>>edges>>checks;
//    for(int i=0,fnode,snode;i<edges;++i) {scanf("%d %d",&fnode,&snode);adjm[fnode][snode]=adjm[snode][fnode]=1;}
//    for(int i=0,check,repair=0;i<checks;++i,repair=0) {
//        cin>>check;fill(visit,visit+SIZE,0);
//        for(int j=1;j<=nodes;++j) if(!visit[j]&&j!=check) {repair++;dfs(j,check);}
//        cout<<repair-1<<"\n";
//    }
//}
//
////说明：给定某一图G，去掉某一结点a以及以它为顶点的所有边e，问你至少需要多少边才能使G重新成为连通图。
//
////分析：简单的dfs。对图G的每一个顶点做一个去掉a的dfs，统计一共又多少连通分量，那么需要的边数等于连通分量数-1。
//
////注意：1、不管是统计连通分量数还是dfs的时候都要排除点a。2、输入要用scanf，否则会超时。
