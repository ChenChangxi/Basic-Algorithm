//// In the big cities, the subway systems always look so complex to the visitors. To give you some sense, the following figure shows the map of Beijing subway. Now you are supposed to help people with your computer skills! Given the starting position of your user, your task is to find the quickest way to his/her destination.
////
////                                     subwaymap.jpg
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains a positive integer N (≤ 100), the number of subway lines. Then N lines follow, with the i-th (i=1,⋯,N) line describes the i-th subway line in the format:
////
//// M S[1] S[2] ... S[M]
////
//// where M (≤ 100) is the number of stops, and S[i]'s (i=1,⋯,M) are the indices of the stations (the indices are 4-digit numbers from 0000 to 9999) along the line. It is guaranteed that the stations are given in the correct order -- that is, the train travels between S[i] and S[i+1] (i=1,⋯,M−1) without any stop.
////
//// Note: It is possible to have loops, but not self-loop (no train starts from S and stops at S without passing through another station). Each station interval belongs to a unique subway line. Although the lines may cross each other at some stations (so called "transfer stations"), no station can be the conjunction of more than 5 lines.
////
//// After the description of the subway, another positive integer K (≤ 10) is given. Then K lines follow, each gives a query from your user: the two indices as the starting station and the destination, respectively.
////
//// The following figure shows the sample map.
////
////                                     samplemap.jpg
////
//// Note: It is guaranteed that all the stations are reachable, and all the queries consist of legal station numbers.
////
//// Output Specification:
//// For each query, first print in a line the minimum number of stops. Then you are supposed to show the optimal path in a friendly format as the following:
////
//// Take Line#X1 from S1 to S2.
//// Take Line#X2 from S2 to S3.
//// ......
////
//// where Xi's are the line numbers and Si's are the station indices. Note: Besides the starting and ending stations, only the transfer stations shall be printed.
////
//// If the quickest path is not unique, output the one with the minimum number of transfers, which is guaranteed to be unique.
//
//// Sample Input:
//// 4
//// 7 1001 3212 1003 1204 1005 1306 7797
//// 9 9988 2333 1204 2006 2005 2004 2003 2302 2001
//// 13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
//// 4 6666 8432 4011 1306
//// 3
//// 3011 3013
//// 6666 2001
//// 2004 3001
//
//// Sample Output:
//// 2
//// Take Line#3 from 3011 to 3013.
//// 10
//// Take Line#4 from 6666 to 1306.
//// Take Line#3 from 1306 to 2302.
//// Take Line#2 from 2302 to 2001.
//// 6
//// Take Line#2 from 2004 to 1204.
//// Take Line#1 from 1204 to 1306.
//// Take Line#3 from 1306 to 3001.
//
//#include <iostream>
//#include <map>
//#include <vector>
//#define SIZE 10000
//
//using namespace std;
//
//int route,query,origin,target,visit[SIZE],minm=SIZE,mint=SIZE;
//
//vector<int> road,result;map<int,vector<int>> graph;map<int,int> edges;
//
//void dfs(int root,int node,int trans,int route) {
//    road.push_back(root);visit[root]=1;
//    if(root!=target) {
//        for(int i=0;i<graph[root].size();++i)
//            if(!visit[graph[root][i]]) dfs(graph[root][i],node+1,route!=edges[root+SIZE*graph[root][i]]?trans+1:trans,edges[root+SIZE*graph[root][i]]);}
//    else if((node<minm)||(node==minm&&trans<mint)) {minm=node;mint=trans;result=road;}
//    road.pop_back();visit[root]=0;
//}
//
//int main() {
//    cin>>route;
//    for(int i=1,value,fnode,snode;i<=route;++i) {
//        scanf("%d %d",&value,&fnode);
//        for(int j=1;j<value;++j) {scanf("%d",&snode);graph[fnode].push_back(snode);graph[snode].push_back(fnode);edges[fnode+SIZE*snode]=edges[snode+SIZE*fnode]=i;fnode=snode;}
//    }
//    cin>>query;
//    for(int i=0;i<query;++i) {
//        scanf("%d %d",&origin,&target);
//        dfs(origin,0,0,0);int start=origin,len=(int)result.size();cout<<minm<<"\n";
//        for(int j=1;j<len-1;++j)
//            if(edges[result[j]+SIZE*result[j+1]]!=edges[result[j]+SIZE*result[j-1]])
//                {printf("Take Line#%d from %04d to %04d.\n",edges[result[j]+SIZE*result[j-1]],start,result[j]);start=result[j];}
//        printf("Take Line#%d from %04d to %04d.\n",edges[result[len-1]+SIZE*result[len-2]],start,target);
//        minm=mint=SIZE;result.clear();
//    }
//}
//
////说明：给你一张城市的地铁网（无向图），一个节点代表一站，每一条边代表所连接的两站处于地铁的哪条线路上面，给一个起始站和终点站，让你求一条经过最少站的一条路径，假如这种路径有多条，选通过“交站”（也就是换乘最少）最少的哪条路径。（这题初看好像无从下手，但其实所有关于图的题，我们只要弄清楚点和边分别代表什么意思，并且弄清楚题中要求的什么就可以，所以我总结一下关于图问题的一个求解步骤：1、确定有向图还是无向图（1111题）。2、确定点和边的含义。3、选取的数据结构（1034题）。4、根据具体的问题选取合适的算法。）
//
////分析：这里我就可以总结一下dfs和回溯的区别了，很多同学搞不清楚这个。dfs是不重复遍历”所有点“，求符合条件的点的个数，它从哪里开始不重要，它只经过一条路径，这条路径是随机的，而回溯是不重复遍历某两点间的”所有不同路径“，在这条路径上，某一点只能出现一次，在不同路径上，某点可以重复出现。因此在回溯的时候进入一个点要把这个点压栈，同时在结束后要退栈，它们的共同点是它们都需要对每个点进行“判断”，只有符合条件且没有visit过的节点才继续遍历，同时回溯在退栈时visit数组也要置为0。我在以前很多题写回溯的时候没有设置visit数组的原因是那些图都是“拓扑”图，一定不可能有回路，同时目标点一定不会有后继。而这题说得很明显：It is possible to have loops，而目标站同时也可能会有后继。
//
////注意：这题id给的没有规律，所以我们用邻接矩阵建图的时候得到的是一个稀疏矩阵，在遍历时会超时，所以要用邻接表来存储。
