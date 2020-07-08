//// Input our current position and a destination, an online map can recommend several paths. Now your job is to recommend two paths to your user: one is the shortest, and the other is the fastest. It is guaranteed that a path exists for any request.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers N (2≤N≤500), and M, being the total number of streets intersections on a map, and the number of streets, respectively. Then M lines follow, each describes a street in the format:
////
//// V1 V2 one-way length time
////
//// where V1 and V2 are the indices (from 0 to N−1) of the two ends of the street; one-way is 1 if the street is one-way from V1 to V2, or 0 if not; length is the length of the street; and time is the time taken to pass the street.
//
//// Finally a pair of source and destination is given.
////
//// Output Specification:
//// For each case, first print the shortest path from the source to the destination with distance D in the format:
////
//// Distance = D: source -> v1 -> ... -> destination
////
//// Then in the next line print the fastest path with total time T:
////
//// Time = T: source -> w1 -> ... -> destination
////
//// In case the shortest path is not unique, output the fastest one among the shortest paths, which is guaranteed to be unique. In case the fastest path is not unique, output the one that passes through the fewest intersections, which is guaranteed to be unique.
////
//// In case the shortest and the fastest paths are identical, print them in one line in the format:
////
//// Distance = D; Time = T: source -> u1 -> ... -> destination
//
//// Sample Input 1:
//// 10 15
//// 0 1 0 1 1
//// 8 0 0 1 1
//// 4 8 1 1 1
//// 3 4 0 3 2
//// 3 9 1 4 1
//// 0 6 0 1 1
//// 7 5 1 2 1
//// 8 5 1 2 1
//// 2 3 0 2 2
//// 2 1 1 1 1
//// 1 3 0 3 1
//// 1 4 0 1 1
//// 9 7 1 3 1
//// 5 1 0 5 2
//// 6 5 1 1 2
//// 3 5
//
//// Sample Output 1:
//// Distance = 6: 3 -> 4 -> 8 -> 5
//// Time = 3: 3 -> 1 -> 5
//
//// Sample Input 2:
//// 7 9
//// 0 4 1 1 1
//// 1 6 1 1 3
//// 2 6 1 1 1
//// 2 5 1 2 2
//// 3 0 0 1 1
//// 3 1 1 1 3
//// 3 2 1 1 2
//// 4 5 0 2 2
//// 6 5 1 1 2
//// 3 5
//
//// Sample Output 2:
//// Distance = 3; Time = 4: 3 -> 2 -> 5
//
//#include <iostream>
//#include <vector>
//#include <map>
//#define SIZE 10000
//
//using namespace std;
//
//int nodes,edges,origin,target,fast=SIZE,node=SIZE,cvisit[SIZE],tvisit[SIZE],cgraph[SIZE][SIZE],tgraph[SIZE][SIZE],cweight[SIZE],tweight[SIZE];
//
//vector<vector<int>> costs,times;
//
//vector<int> cresult,croads,tresult,troads;
//
//void Dijkstra(int root) {
//    cweight[root]=tweight[root]=0;
//    for(int i=0;i<nodes;++i) {
//        int cvalue=SIZE,tvalue=SIZE,cindex=0,tindex=0;
//        for(int j=0;j<nodes;++j) {
//            if(!tvisit[j]&&tweight[j]<tvalue) {tvalue=tweight[j];tindex=j;}
//            if(!cvisit[j]&&cweight[j]<cvalue) {cvalue=cweight[j];cindex=j;}
//        }
//        tvisit[tindex]=cvisit[cindex]=1;
//        for(int j=0;j<nodes;++j) {
//            if(!tvisit[j]&&tgraph[tindex][j]) {
//                int value=tweight[tindex]+tgraph[tindex][j];//由index到j
//                if(value<tweight[j]) {times[j].clear();times[j].push_back(tindex);tweight[j]=value;}
//                else if(value==tweight[j]) times[j].push_back(tindex);
//            }
//            if(!cvisit[j]&&cgraph[cindex][j]) {
//                int value=cweight[cindex]+cgraph[cindex][j];
//                if(value<cweight[j]) {costs[j].clear();costs[j].push_back(cindex);cweight[j]=value;}
//                else if(value==cweight[j]) costs[j].push_back(cindex);
//            }
//        }
//    }
//}
//
//void cdfs(int root,int time) {
//    croads.push_back(root);
//    if(root==origin&&time<fast) {fast=time;cresult=croads;}
//    for(int i=0;i<costs[root].size();++i) cdfs(costs[root][i],time+tgraph[costs[root][i]][root]);//由costs[root][i]到root
//    croads.pop_back();
//}
//
//void tdfs(int root,int juncs) {
//    troads.push_back(root);
//    if(root==origin&&juncs<node) {tresult=troads;node=juncs;}
//    for(int i=0;i<times[root].size();++i) tdfs(times[root][i],juncs+1);
//    troads.pop_back();
//}
//
//int main() {
//    cin>>nodes>>edges;fill(cweight,cweight+SIZE,SIZE);fill(tweight,tweight+SIZE,SIZE);
//    costs.resize(nodes);times.resize(nodes);
//    for(int i=0,fnode,snode,time,cost,flag;i<edges;++i) {
//        cin>>fnode>>snode>>flag>>cost>>time;
//        tgraph[fnode][snode]=time;tgraph[snode][fnode]=flag?0:time;
//        cgraph[fnode][snode]=cost;cgraph[snode][fnode]=flag?0:cost;
//    }
//    cin>>origin>>target;Dijkstra(origin);tdfs(target,1);cdfs(target,0);
//    if(cresult!=tresult) {
//        printf("Distance = %d: ",cweight[target]);
//        for(int i=(int)cresult.size()-1;i>=0;--i) cout<<cresult[i]<<(i?" -> ":"\n");
//        printf("Time = %d: ",tweight[target]);
//        for(int i=(int)tresult.size()-1;i>=0;--i) cout<<tresult[i]<<(i?" -> ":"\n");
//    } else {
//        printf("Distance = %d; Time = %d: ",cweight[target],tweight[target]);
//        for(int i=(int)cresult.size()-1;i>=0;--i) cout<<cresult[i]<<(i?" -> ":"\n");
//    }
//}
//
////说明：给你一个graph，每条边有一个cost和time，给一个出发地和目的地，求两条路径，第一条是cost最小的路径，如果有多条，选择time最小的那条，第二条是time最小的路径，如果有多条，选经过结点最少的路径。
//
////分析：这题没啥意思，就两次Dijkstra和dfs就解决了。
//
////注意：1、本题的图是有向图，这个注意，以前都是无向图，这就要求凡是根据邻接矩阵求边的长度的时候都必须有方向，明确由谁到谁。2、当cost相同的路径有多条时，在cost相同的那些路径中选time最小的那条。
