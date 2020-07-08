//// Some scientists took pictures of thousands of birds in a forest. Assume that all the birds appear in the same picture belong to the same tree. You are supposed to help the scientists to count the maximum number of trees in the forest, and for any pair of birds, tell if they are on the same tree.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains a positive number N (≤10^4) which is the number of pictures. Then N lines follow, each describes a picture in the format:
////
//// K B(1) B(2) ... B(K)
////
//// where K is the number of birds in this picture, and B(i)'s are the indices of birds. It is guaranteed that the birds in all the pictures are numbered continuously from 1 to some number that is no more than 10^4.
////
//// After the pictures there is a positive number Q (≤10^4) which is the number of queries. Then Q lines follow, each contains the indices of two birds.
////
//// Output Specification:
//// For each test case, first output in a line the maximum possible number of trees and the number of birds. Then for each query, print in a line Yes if the two birds belong to the same tree, or No if not.
//
//// Sample Input:
//// 4
//// 3 10 1 2
//// 2 3 4
//// 4 1 5 7 8
//// 3 9 6 4
//// 2
//// 10 5
//// 3 7
//
//// Sample Output:
//// 2 10
//// Yes
//// No
//
//#include <iostream>
//#include <algorithm>
//#define SIZE 100000
//
//using namespace std;
//
//int pictures,bird,bpre,bnext,qpre,qnext,tree,btol,query,birds[SIZE];
//
//int Find(int node) {
//    while(birds[node]) node=birds[node];
//    return node;
//}
//
//void Union(int anode,int bnode) {
//    int aroot=Find(anode),temp;
//    while(birds[bnode]) {temp=bnode;bnode=birds[bnode];birds[temp]=aroot;}  //调整
//    birds[bnode]=aroot;
//}
//
//int main() {
//    cin>>pictures;
//    for(int i=0;i<pictures;++i) {
//        cin>>bird>>bpre;btol=max(btol,bpre);
//        for(int j=1;j<bird;++j) {cin>>bnext;btol=max(bnext,btol);Union(bpre,bnext);bpre=bnext;}
//    }
//    for(int i=1;i<=btol;++i) {if(!birds[i]) ++tree;} printf("%d %d\n",tree,btol);
//    cin>>query;
//    for(int i=0;i<query;++i) {
//        cin>>bpre>>bnext;
//        if(Find(bpre)==Find(bnext)) printf("Yes\n");else printf("No\n");
//    }
//}
//
////说明：每一行的输入是一张照片上的所有鸟的id，只要两只鸟出现在同一张照片上，我们就认为他们在一棵树上，现在给你若干张照片，问你一共有多少鸟，多少树，接着给若干查询条件，每个条件有两只鸟，问他们是否在一棵树上。
//
////分析：典型的并查集的应用，给定一张照片，查照片上的每一只鸟当前在哪一棵树上，并把所有的树合并为一棵树，最后遍历并查集，查找根结点，有多少根结点就有多少棵树，而鸟的数量就取鸟的最大id，查询的时候用Find操作，如果在一棵树上那么他们的根结点就相同，否则就不相同。
//
////注意：1、这题比1114题简单的地方就在于题目中明确告诉你鸟的id从1到n是continuous的，那么最大id即为鸟的数量，但并查集是两两合并的，因此要设置pre和next指针来进行两两合并，同时不要忘了只有一只鸟的情况（这一点在求最大值的时候体现出来，思考为什么？）。2、这题还有就是降低查询时间，因为这题是150ms，不降低查询时间测试点3会超时，降低查询时间的方法就是让某一棵树的所有结点指向根结点。
