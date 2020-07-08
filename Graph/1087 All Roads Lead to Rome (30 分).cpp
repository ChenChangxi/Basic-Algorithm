//// Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 2 positive integers N (2≤N≤200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N−1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format City1 City2 Cost. Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.
////
//// Output Specification:
//// For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommanded. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.
////
//// Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommanded route. Then in the next line, you are supposed to print the route in the format City1->City2->...->ROM.
//
//// Sample Input:
//// 6 7 HZH
//// ROM 100
//// PKN 40
//// GDN 55
//// PRS 95
//// BLN 80
//// ROM GDN 1
//// BLN ROM 1
//// HZH PKN 1
//// PRS ROM 2
//// BLN HZH 2
//// PKN GDN 1
//// HZH PRS 1
//
//// Sample Output:
//// 3 3 195 97
//// HZH->PRS->ROM
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#define SIZE 10000
//#define INF 99999999
//
//using namespace std;
//
//unordered_map<string,int> stoin;unordered_map<int,string> to_str;
//
//vector<int> result,trace;vector<vector<int>> roads;
//
//int nodes,edges,average,happy,route,values[SIZE],weight[SIZE],visit[SIZE],graph[SIZE][SIZE];
//
//string start,name,fname,sname;
//
//void dfs(int root,int total,int city) {
//    trace.push_back(root);
//    if(root==stoin[start]) ++route;
//    if(root==stoin[start]&&(total>happy||(total==happy&&total/city>average))) {result=trace;happy=total;average=total/city;}
//    for(int i=0;i<roads[root].size();++i) dfs(roads[root][i],total+values[roads[root][i]],city+1);
//    trace.pop_back();
//}
//
//void Dijkstra(string root) {
//    weight[stoin[root]]=0;
//    for(int i=0;i<nodes;++i) {
//        int value=INF,index=0;
//        for(int j=0;j<nodes;++j) if(!visit[j]&&weight[j]<value) {value=weight[j];index=j;}
//        visit[index]=1;
//        for(int j=0;j<nodes;++j) {
//            if(!visit[j]&&graph[index][j]) {
//                int value=weight[index]+graph[index][j];
//                if(value<weight[j]) {roads[j].clear();roads[j].push_back(index);weight[j]=value;}
//                else if(value==weight[j]) roads[j].push_back(index);
//            }
//        }
//    }
//}
//
//int main() {
//    cin>>nodes>>edges>>start;stoin[start]=0;to_str[0]=start;fill(weight,weight+nodes,INF);
//    roads.resize(nodes);
//    for(int i=1,value;i<nodes;++i) {cin>>name>>value;stoin[name]=i;to_str[i]=name;values[i]=value;}
//    for(int i=0,value;i<edges;++i) {cin>>fname>>sname>>value;graph[stoin[fname]][stoin[sname]]=graph[stoin[sname]][stoin[fname]]=value;}
//    Dijkstra(start);dfs(stoin["ROM"],values[stoin["ROM"]],0);
//    printf("%d %d %d %d\n",route,weight[stoin["ROM"]],happy,average);
//    for(int i=(int)result.size()-1;i>=0;--i) cout<<to_str[result[i]]<<(i?"->":"");
//}
//
////说明：给你一张地图，每个节点代表一个城市，每一个城市有一个happiness值，边代表城市之间的路径，每一条路径有一个cost，给出起始城市，求出一条到罗马的最小cost路径，如果这条路径不唯一，那么选择可以获得最大happinness值的那条。
//
////分析：构建图的时候用了string到int的一个hash映射，然后就是简单的Dijikstra和回溯，求出所给的路径。
//
////注意：1、求平均happiness值的时候不包括起始城市。2、INF弄大一点，否则测试点3通不过。
