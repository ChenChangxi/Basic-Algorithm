//// Given two sets of integers, the similarity of the sets is defined to be N(c)/N(t)×100%, where N(c) is the number of distinct common numbers shared by the two sets, and N(t) is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.
////
//// Input Specification:
//// Each input file contains one test case. Each case first gives a positive integer N (≤50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (≤10^4) and followed by M integers in the range [0,10^9]. After the input of sets, a positive integer K (≤2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.
//
//// Sample Input:
//// 3
//// 3 99 87 101
//// 4 87 101 5 87
//// 7 99 101 18 5 135 18 99
//// 2
//// 1 2
//// 1 3
//
//// Sample Output:
//// 50.0%
//// 33.3%
//
//#include <iostream>
//#include <unordered_map>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//
//int nodes,query;unordered_map<int,set<int>> sets;set<int> inc,ftem,stem;
//
//int main() {
//    cin>>nodes;
//    for(int i=1,eles,value;i<=nodes;++i)
//       {scanf("%d",&eles);for(int j=0;j<eles;++j) {scanf("%d",&value);sets[i].insert(value);}}
//    cin>>query;
//    for(int i=0,fset,sset;i<query;++i) {
//        scanf("%d %d",&fset,&sset);ftem=sets[fset];stem=sets[sset];
//        set_intersection(ftem.begin(),ftem.end(),stem.begin(),stem.end(),inserter(inc,inc.begin()));
//        printf("%.1f%%\n",(double)inc.size()*100/(ftem.size()+stem.size()-inc.size()));inc.clear();
//    }
//}
//
////说明：给若干集合，其中每两个集合的相似度是指Count（AnB）/Count（AuB），接着给出若干查询，让你求每个查询中两个集合的相似度。
//
////分析：对于每两个集合，我们首先求出它们的交集元素个数Count（AnB），接着它们的并集元素个数Count（AuB）=Count（A）+Count（B）-Count（AnB），然后求相似度即可。
//
////注意：1、intersection函数是algorithm库中求两个集合交集的函数，我们需要传两个集合的迭代器，以及一个新集合的插入迭代器（这里面有点复杂，有兴趣的同学看看C++primer）。2、algorithm库中还有个union函数，是求并集的，用法和交集相同，但是这题不能同时求交集和并集，否则最后一个测试点超时，只能用上面的公式来计算。3、printf中百分号一定要打两个才能输出。
