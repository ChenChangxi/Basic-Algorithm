//// When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A social cluster is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.
////
//// Input Specification:
//// Each input file contains one test case. For each test case, the first line contains a positive integer N (≤1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:
////
//// Ki : hi[1] hi[2] ... hi[Ki]
////
//// where Ki(>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].
////
//// Output Specification:
//// For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.
//
//// Sample Input:
//// 8
//// 3: 2 7 10
//// 1: 4
//// 2: 5 3
//// 1: 4
//// 1: 3
//// 1: 4
//// 4: 6 8 1 5
//// 1: 4
//
//// Sample Output:
//// 3
//// 4 3 1
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define SIZE 100000
//
//using namespace std;
//
//int persons,hobby,hobid,people[SIZE],hobbys[SIZE],cluster[SIZE];
//
//vector<int> results;
//
//int Find(int node) {
//    while(people[node]!=node) node=people[node];
//    return node;
//}
//
//void Union(int anode,int bnode) {
//    int aroot=Find(anode),broot=Find(bnode);
//    people[aroot]=broot;
//}
//
//int main() {
//    cin>>persons;
//    for(int i=1;i<=persons;++i) people[i]=i;
//    for(int i=1;i<=persons;++i) {
//        scanf("%d: ",&hobby);
//        for(int j=0;j<hobby;++j) {
//            cin>>hobid;if(hobbys[hobid]==0) hobbys[hobid]=i;Union(i,hobbys[hobid]);
//        }
//    }
//    for(int i=1;i<=persons;++i) cluster[Find(i)]++;
//    for(int i=1;i<=persons;++i) if(cluster[i]!=0) results.push_back(cluster[i]);
//    sort(results.begin(),results.end(),greater<int>());cout<<results.size()<<"\n";
//    for(int i=0;i<results.size();++i) cout<<results[i]<<(i!=results.size()-1?" ":"");
//}
//
////说明：每个人有若干爱好，那些有相同爱好的人归为同一个集合，对“有相同爱好”作如下定义：假如一个人和这个集合中至少一个人的至少一个爱好相同，那么就说他们有“相同爱好”，最后问你一共有几个集合，每个集合中有多少人，降序输出。
//
////分析：这题非常明显得用并查集来解决问题。并查集本质上是一个森林，它是树的应用，它有两个基本操作：查找和合并，查找操作找的是某一个节点所在树的“根结点”，合并操作是把两棵树合并为一个树。那么这题首先要设置一个people数组作为“人”的并查集，和一个hobbys数组来存每一个hobby所对应的“某个人”。对于某个人的一个爱好，首先查hobby数组找到有这个爱好的人，把这两个人所在的树“合并”为一棵树，即能满足有“相同爱好”的定义。然后遍历people数组，统计每一个cluster中的人数，最后降序排列然后输出即可。
//
////注意：因为当一个爱好第一次出现的时候没有其他有这个爱好的人，这个时候需要把hobby数组中对应的hobby设置为这个人，那么它的接下来的操作就是这棵树和自己Union，这就会使people数组中这棵树根结点的“下一个”节点为他自己，等于没有合并。因此为了Find方便，我们就必须在建树前把并查集中的每一个元素的“下一个”节点设置成它自己（开始时每一个节点都是根结点），来了配合find中while查找到根结点时的停止条件，思考一下为什么？
