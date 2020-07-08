//// Unlike in nowadays, the way that boys and girls expressing their feelings of love was quite subtle in the early years. When a boy A had a crush on a girl B, he would usually not contact her directly in the first place. Instead, he might ask another boy C, one of his close friends, to ask another girl D, who was a friend of both B and C, to send a message to B -- quite a long shot, isn't it? Girls would do analogously.
////
//// Here given a network of friendship relations, you are supposed to help a boy or a girl to list all their friends who can possibly help them making the first contact.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers N (1 < N ≤ 300) and M, being the total number of people and the number of friendship relations, respectively. Then M lines follow, each gives a pair of friends. Here a person is represented by a 4-digit ID. To tell their genders, we use a negative sign to represent girls.
////
//// After the relations, a positive integer K (≤ 100) is given, which is the number of queries. Then K lines of queries follow, each gives a pair of lovers, separated by a space. It is assumed that the first one is having a crush on the second one.
////
//// Output Specification:
//// For each query, first print in a line the number of different pairs of friends they can find to help them, then in each line print the IDs of a pair of friends.
////
//// If the lovers A and B are of opposite genders, you must first print the friend of A who is of the same gender of A, then the friend of B, who is of the same gender of B. If they are of the same gender, then both friends must be in the same gender as theirs. It is guaranteed that each person has only one gender.
////
//// The friends must be printed in non-decreasing order of the first IDs, and for the same first ones, in increasing order of the seconds ones.
//
//// Sample Input:
//// 10 18
//// -2001 1001
//// -2002 -2001
//// 1004 1001
//// -2004 -2001
//// -2003 1005
//// 1005 -2001
//// 1001 -2003
//// 1002 1001
//// 1002 -2004
//// -2004 1001
//// 1003 -2002
//// -2003 1003
//// 1004 -2002
//// -2001 -2003
//// 1001 1003
//// 1003 -2001
//// 1002 -2001
//// -2002 -2003
//// 5
//// 1001 -2001
//// -2003 1001
//// 1005 -2001
//// -2002 -2004
//// 1111 -2003
//
//// Sample Output:
//// 4
//// 1002 2004
//// 1003 2002
//// 1003 2003
//// 1004 2002
//// 4
//// 2001 1002
//// 2001 1003
//// 2002 1003
//// 2002 1004
//// 0
//// 1
//// 2003 2001
//// 0
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <cmath>
//#include <map>
//#define SIZE 10000
//
//using namespace std;
//
//map<int,int> node;map<int,vector<int>> adjt;vector<pair<int,int>> result;
//
//int nodes,edges,query,adjm[SIZE][SIZE];
//
//string fnode,snode;
//
//int main() {
//    cin>>nodes>>edges;
//    for(int i=0,fid,sid;i<edges;++i) {
//        cin>>fnode>>snode;
//        fid=abs(stoi(fnode));sid=abs(stoi(snode));
//        node[fid]=(fnode[0]=='-'?-1:1);node[sid]=(snode[0]=='-'?-1:1);
//        adjm[fid][sid]=adjm[sid][fid]=1;
//        adjt[fid].push_back(sid);adjt[sid].push_back(fid);
//    }
//    cin>>query;
//    for(auto it=adjt.begin();it!=adjt.end();++it) sort(it->second.begin(),it->second.end());
//    for(int i=0,fnode,snode;i<query;++i) {
//        cin>>fnode>>snode;fnode=abs(fnode);snode=abs(snode);result.clear();
//        for(int j=0;j<adjt[fnode].size();++j) {
//            for(int k=0;k<adjt[snode].size();++k) {
//                int fcon=adjt[fnode][j],scon=adjt[snode][k];
//                if(fcon!=snode&&scon!=fnode&&node[fnode]==node[fcon]&&node[snode]==node[scon]&&adjm[fcon][scon]) result.push_back(pair<int,int>(fcon,scon));
//            }
//        }
//        cout<<result.size()<<"\n";for(int j=0;j<result.size();++j) printf("%04d %04d\n",result[j].first,result[j].second);
//    }
//}
//
////说明：给一个社交网络（无向图），每个点的数值部分代表id，符号代表性别，每条边代表两个人之间存在关系。现给定两个人（a，b），假如c和a认识，d和b认识，并且c和d又认识，那么我们就说（c，d）是（a，b）的一个First Contact。现在给出（a，b），求出满足所有条件的（c，d）。
//
////分析：这题难点在建图上，我们在求a的所有相邻结点c和b的所有相邻结点d时，邻接表比较方便，当我们判断c和d是否相邻时，邻接矩阵比较方便，所以这题同时建立了邻接表和邻接矩阵（这和以前是不相同的，以前邻接表存相邻节点而邻接矩阵存权值，而这题的邻接表和邻接矩阵是等价的）。
//
////注意：题目要求a，b，c，d互不相同，所以特别注意a和b同号的情况，假如a和b同号且相邻时，就会出现（c，a），（b，d）和（b，a）这三种不合法的情况，所以一定要在与a相邻的所有节点中排除b，在与b相邻的所有结点中排除a，然后进行讨论。
