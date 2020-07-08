//// One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threthold, respectively.
////
//// Then N lines follow, each in the following format:
////
//// Name1 Name2 Time
////
//// where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.
////
//// Output Specification:
//// For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.
//
//// Sample Input 1:
//// 8 59
//// AAA BBB 10
//// BBB AAA 20
//// AAA CCC 40
//// DDD EEE 5
//// EEE DDD 70
//// FFF GGG 30
//// GGG HHH 20
//// HHH FFF 10
//
//// Sample Output 1:
//// 2
//// AAA 3
//// GGG 3
//
//// Sample Input 2:
//// 8 70
//// AAA BBB 10
//// BBB AAA 20
//// AAA CCC 40
//// DDD EEE 5
//// EEE DDD 70
//// FFF GGG 30
//// GGG HHH 20
//// HHH FFF 10
//
//// Sample Output 2:
//// 0
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//
//using namespace std;
//
//map<string,vector<string>> graph;
//
//map<string,int> weight,visit,gang,nodes;
//
//int edges,thres,value,total,nums,maxw;string fnode,snode,head;
//
//void dfs(string root) {
//    if(!visit[root]) {
//        visit[root]=1;nums+=1;
//        for(int i=0,value=0;i<graph[root].size();++i) {value=weight[root+graph[root][i]];total+=value;dfs(graph[root][i]);nodes[root]+=value;nodes[graph[root][i]]+=value;}
//    }
//}
//
//int main() {
//    cin>>edges>>thres;
//    for(int i=0;i<edges;++i) {cin>>fnode>>snode>>value;graph[fnode].push_back(snode);weight[fnode+snode]=max(weight[fnode+snode],value);}
//    for(auto it=graph.begin();it!=graph.end();++it)
//        {dfs(it->first);for(auto itn=nodes.begin();itn!=nodes.end();++itn) if(itn->second>maxw) {maxw=itn->second;head=itn->first;} total>thres&&nums>2?gang[head]=nums:NULL;total=nums=maxw=0;nodes.clear();}
//    cout<<gang.size()<<"\n";for(auto it=gang.begin();it!=gang.end();++it) cout<<it->first<<" "<<it->second<<"\n";
//}
//
////说明：给你一个电话网，这个网是一个有向图，每个节点代表一个人，每一条边代表一个人给另一个人打电话，权重代表通话时长，每一个极大连通子图（连通分量）是一个通话集，通话集中通话时间最多的人是这个集合的代表，问你一共有多少通话集，以及每个通话集中有多少人。
//
////分析：1⃣️、这个题我在第一次做的时候考虑复杂了，其实基本思路就是一个dfs，对于每个节点a，遍历它的所有边，首先把所有边累加到通话集的权重上去，接着把所有边累加到a的权重上去，最后把相应的边累加到和a相邻的节点上去。这样就能统计出这个通话集中每个人的通话时长，通话集中的人数以及通话集的总通话时间，按照题中的要求取舍即可。2⃣️、这题我在选数据结构的时候费了一番功夫，和第一次写不同，我用了邻接表，这里我就能总结一下邻接表和邻接矩阵的区别了，以后在这个地方我不会花太多笔墨分析我选数据结构的原因。我们知道，邻接矩阵是一个二维数组，这就决定了它的key一定是一个数，且是自然数，假如key是一个字符串，邻接矩阵就不能用（或者可以通过hash映射，把一个字符串映射为一个整数，这样需要两个map，s-i和i-s，见1087题），而邻接表是记录每一个节点所相邻的节点的索引，所以它的缺点是无法存储边的权值，这个时候我们可以通过拼接两个key代表一条有向边来存储权值，因为key是唯一的，所以拼接起来的有向边也是唯一的。所以假如我们需要关注边的权值，“尽量”用邻接矩阵存储，假如只关注节点之间的相邻关系，那么用邻接表来存储，此外，有时还要看题中数据的输入格式。（注意，以上讨论和点的权值没有关系）
//
////注意：1、题目中给了一个阀值，只有这个通话集中的总通话时长大于给定的阀值，并且这个通话集中的人数大于二，这个通话集才会被统计。2、每个人的通话时间包括这个人给别人打电话的时间以及别人给他打电话的总和。3、题目中要求最后根据每一个通话集的字母表顺序升序排序，map底层是红黑树，所以它会自动根据key的大小升序排序。（这个排序是需要费时间的，可能会导致有些题超时，所以在有些题目中不必要的情况下用unordered_map）。
