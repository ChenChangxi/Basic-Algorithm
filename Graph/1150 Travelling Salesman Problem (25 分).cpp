//// The "travelling salesman problem" asks the following question: "Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?" It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science. (Quoted from "https://en.wikipedia.org/wiki/Travelling_salesman_problem".)
////
//// In this problem, you are supposed to find, from a given list of cycles, the one that is the closest to the solution of a travelling salesman problem.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<N≤200), the number of cities, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format City1 City2 Dist, where the cities are numbered from 1 to N and the distance Dist is positive and is no more than 100. The next line gives a positive integer K which is the number of paths, followed by K lines of paths, each in the format:
////
//// n C(1) C(2) ... C(n)
////
//// where n is the number of cities in the list, and C(i)'s are the cities on a path.
////
//// Output Specification:
//// For each path, print in a line Path X: TotalDist (Description) where X is the index (starting from 1) of that path, TotalDist its total distance (if this distance does not exist, output NA instead), and Description is one of the following:
////
//// ·TS simple cycle if it is a simple cycle that visits every city;
//// ·TS cycle if it is a cycle that visits every city, but not a simple cycle;
//// ·Not a TS cycle if it is NOT a cycle that visits every city.
////
//// Finally print in a line Shortest Dist(X) = TotalDist where X is the index of the cycle that is the closest to the solution of a travelling salesman problem, and TotalDist is its total distance. It is guaranteed that such a solution is unique.
//
//// Sample Input:
//// 6 10
//// 6 2 1
//// 3 4 1
//// 1 5 1
//// 2 5 1
//// 3 1 8
//// 4 1 6
//// 1 6 1
//// 6 3 1
//// 1 2 1
//// 4 5 1
//// 7
//// 7 5 1 4 3 6 2 5
//// 7 6 1 3 4 5 2 6
//// 6 5 1 4 3 6 2
//// 9 6 2 1 6 3 4 5 2 6
//// 4 1 2 5 1
//// 7 6 1 2 5 4 3 1
//// 7 6 3 2 5 4 1 6
//
//// Sample Output:
//// Path 1: 11 (TS simple cycle)
//// Path 2: 13 (TS simple cycle)
//// Path 3: 10 (Not a TS cycle)
//// Path 4: 8 (TS cycle)
//// Path 5: 3 (Not a TS cycle)
//// Path 6: 13 (Not a TS cycle)
//// Path 7: NA (Not a TS cycle)
//// Shortest Dist(4) = 8
//
//#include <iostream>
//#include <string>
//#include <vector>
//#define SIZE 20005
//
//using namespace std;
//
//int nodes,edges,query,value=SIZE,indexs,visit[SIZE],graph[SIZE][SIZE];
//
//vector<int> sequ;
//
//int main() {
//    cin>>nodes>>edges;
//    for(int i=0,fnode,snode,value;i<edges;++i) {cin>>fnode>>snode>>value;graph[fnode][snode]=graph[snode][fnode]=value;}
//    cin>>query;
//    for(int i=1,node,count=0,adj=1,total=0;i<=query;++i,count=total=0,adj=1) {
//        cin>>node;for(int j=0,value;j<node;++j) {cin>>value;sequ.push_back(value);}
//        for(int j=0;j<node-1;++j)
//            {if(!visit[sequ[j]]) {++count;visit[sequ[j]]=1;} if(!graph[sequ[j]][sequ[j+1]]) adj=0;total+=graph[sequ[j]][sequ[j+1]];}
//        cout<<"Path "<<i<<": "<<(adj?to_string(total):"NA")<<((adj&&count==nodes&&node==nodes+1&&sequ[0]==sequ[node-1])?" (TS simple cycle)\n":(adj&&count==nodes&&sequ[0]==sequ[node-1])?" (TS cycle)\n":" (Not a TS cycle)\n");
//        if(adj&&sequ[0]==sequ[node-1]&&count==nodes&&total<value) {value=total;indexs=i;} fill(visit,visit+SIZE,0);sequ.clear();
//    }
//    printf("Shortest Dist(%d) = %d\n",indexs,value);
//}
//
////说明：给定一张图G，我们想要求出一个包含所有点的“最短”回路，这是个P=NP问题。那么给定若干序列，让你判断每个序列是不是一个包含所有点的回路，并求出其中最短的那条回路。
//
////分析：对于给定序列，假如满足1、这个序列中包含图中所有点；2、序列中任意相邻两点在图中相邻；3、首尾节点相同。这三个条件，那么它就是一个TScycle，假如它还满足除了首尾节点，序列中每个节点只出现一次，那么它是SimpleCycle，所以你的代码必须求出这四个条件，然后判断，并累加符合条件路径的总权值，求出最短的那条。
//
////注意：本题和1122题哈密顿路径很像，但也有不一样的地方，哈密顿路径等价于SimpleCycle，但TScycle不要求序列中除了首尾节点每个节点只出现一次，可以多次出现。
