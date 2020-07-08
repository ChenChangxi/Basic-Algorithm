//// British astronomer Eddington liked to ride a bike. It is said that in order to show off his skill, he has even defined an "Eddington number", E -- that is, the maximum integer E such that it is for E days that one rides more than E miles. Eddington's own E was 87.
////
//// Now given everyday's distances that one rides for N days, you are supposed to find the corresponding E (≤N).
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤10^5), the days of continuous riding. Then N non-negative integers are given in the next line, being the riding distances of everyday.
////
//// Output Specification:
//// For each case, print in a line the Eddington number for these N days.
////
//// Sample Input:
//// 10
//// 6 7 6 9 3 10 8 2 7 8
//
//// Sample Output:
//// 6
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define SIZE 200000
//
//using namespace std;
//
//int days,edd,maxe,miles[SIZE],couns[SIZE];
//
//int main() {
//    cin>>days;for(int i=0,value;i<days;++i) {cin>>value;miles[value]++;maxe=max(maxe,value);}
//    for(int i=maxe-1;i>=0;--i) {couns[i]=miles[i+1]+couns[i+1];if(couns[i]>=i) {cout<<i;return 0;}}
//}
//
////说明：给一个序列，假如这个序列中大于m的数有n个，且n>=m，那么把n加入集合K中，集合K中最大的元素叫做序列的爱丁顿数。
//
////分析：coun数组中第i个数的含义是大于i的数有多少个，miles数组中第i个数的含义是等于i的数有多少个，显然coun是一个递归数组，根据Count（>i）=Count=（>=i+1）=Count（i+1）+Count（>i+1）可以求出coun，那么爱丁顿数即为（Max（i)|coun（i）>=i）。
