//// The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains an integer N (in [3,10^5]), followed by N integer distances D(1) D(2) ⋯ D(N) , where D(i) is the distance between the i-th and the (i+1)-st exits, and D(N) is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (≤10^4), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 10^7.
////
//// Output Specification:
//// For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.
//
//// Sample Input:
//// 5 1 2 4 14 9
//// 3
//// 1 3
//// 2 5
//// 4 1
//
//// Sample Output:
//// 3
//// 10
//// 7
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int nodes,query;vector<int> sums;
//
//int main() {
//    cin>>nodes;sums.resize(nodes+1);
//    for(int i=1;i<=nodes;++i) {cin>>sums[i];sums[i]+=sums[i-1];} cin>>query;
//    for(int i=0,j,k,value;i<query;++i)
//       {cin>>j>>k;value=sums[max(j-1,k-1)]-sums[min(j-1,k-1)];cout<<(min(value,sums[nodes]-value))<<"\n";}
//}
//
//
////说明：给一个环，并给出环中点距的一个序列，并给出若干查询，每个查询有两个点，问你这两点最短距离是多少。（正向或反向）
//
////分析：数据结构用和数组，sum[k]存的是某一点k+1到点1的距离，那么i到j的正向距离L=sum[j-1]-sum[i-1]，反向距离R=环周长-L。
