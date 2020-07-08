//// A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.
////
//// Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 10^3), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.Then K lines follow, each describes a road in the format:
////
//// P1 P2 Dist
////
//// where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.
////
//// Output Specification:
//// For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output “No Solution”.
//
//// Sample Input 1:
//// 4 3 11 5
//// 1 2 2
//// 1 4 2
//// 1 G1 4
//// 1 G2 3
//// 2 3 2
//// 2 G2 1
//// 3 4 2
//// 3 G3 2
//// 4 G1 3
//// G2 G1 1
//// G3 G2 2
//
//// Sample Output 1:
//// G1
//// 2.0 3.3
//
//// Sample Input 2:
//// 2 1 2 10
//// 1 G1 9
//// 2 G1 20
//
//// Sample Output 2:
//// No Solution
//
//#include <iostream>
//#include <cmath>
//#include <string>
//#include <vector>
//#include <algorithm>
//#define SIZE 10000
//#define INF 99999999
//
//using namespace std;
//
//int nodes,edges,stations,range,stat,weight[SIZE],visit[SIZE],graph[SIZE][SIZE];
//
//double total,average,minm;string fcity,scity;
//
//void Dijkstra(int root) {
//    weight[root]=0;
//    for(int i=1;i<=nodes+stations;++i) {
//        int value=SIZE,index=0;
//        for(int j=1;j<=nodes+stations;++j) if(!visit[j]&&weight[j]<value) {value=weight[j];index=j;}
//        visit[index]=1;
//        for(int j=1;j<=nodes+stations;++j)
//            if(!visit[j]&&graph[index][j]){int value=weight[index]+graph[index][j];weight[j]=value<weight[j]?value:weight[j];}
//    }
//}
//
//int main() {
//    cin>>nodes>>stations>>edges>>range;
//    for(int i=0,value=0,fnode,snode;i<edges;++i) {
//        cin>>fcity>>scity>>value;
//        fnode=fcity[0]=='G'?stoi(fcity.erase(0,1))+nodes:stoi(fcity);snode=scity[0]=='G'?stoi(scity.erase(0,1))+nodes:stoi(scity);
//        graph[fnode][snode]=graph[snode][fnode]=value;
//    }
//    for(int i=1,maxn=0,minn=SIZE;i<=stations;++i,maxn=0,minn=INF) {
//        fill(weight,weight+SIZE,INF);fill(visit,visit+SIZE,0);Dijkstra(i+nodes);
//        for(int j=1;j<=nodes;++j) {total+=weight[j];maxn=max(maxn,weight[j]);minn=min(minn,weight[j]);}
//        if((minn>minm||(minn==minm&&total/nodes<average))&&maxn<=range) {stat=i;average=total/nodes;minm=minn;} total=0;
//    }
//    if(average) {printf("G%d\n%.1f %.1f",stat,minm,average);} else printf("No Solution");
//}
//
////说明：给一张城市的地图，上面有若干居民区和station的备选地，让你求出一个station，使这个station到所有居民区的“最近”距离在所有station中是最远的，并且这个station到“最远”居民区的距离不超过给定范围，如果这样的路径不止一条，输出到所有居民区平均距离最小的那个station，否则输出index最小的station。
//
////分析：这个题的意思很绕，但不要被绕进去了，它的意思是说每个station都有距离它最近的那个居民区，也有距离最远的那个居民区，我们要求的这个station到距他最近那个居民区的距离，是所有station到它们”最近“居民区的距离当中“最远”的，并且每个station到"最远"的那个居民区的距离不能超过给定的范围（我们讨论一个station距离最近和最远的居民区都是在“最短路径”的状态下讨论的）。
//
////注意：1、erase函数第一个参数是“从哪里擦除”，第二个参数是“擦”多少个，和substr函数是一样的。2、求station到每个居民区的最短路径时，其他station也被允许出现在最短路径中。3、我们从小到大找的，所以假如“平均距离”相等，我们不去处理，就能保证当前index是小的index。
//
