//// Given a sequence of positive integers and another positive integer p. The sequence is said to be a perfect sequence if M≤m×p where M and m are the maximum and minimum numbers in the sequence, respectively.
////
//// Now given a sequence and a parameter p, you are supposed to find from the sequence as many numbers as possible to form a perfect subsequence.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains two positive integers N and p, where N (≤10^5) is the number of integers in the sequence, and p (≤10^9) is the parameter. In the second line there are N positive integers, each is no greater than 10^9.
////
//// Output Specification:
//// For each test case, print in one line the maximum number of integers that can be chosen to form a perfect subsequence.
////
//// Sample Input:
//// 10 8
//// 2 3 20 4 5 1 6 7 8 9
//
//// Sample Output:
//// 8
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int nodes,maxc;long long fact;vector<int> seq;
//
//int main() {
//    cin>>nodes>>fact;seq.resize(nodes);for(int i=0;i<nodes;++i) {cin>>seq[i];} sort(seq.begin(),seq.end());
//    for(int i=0,j=0;nodes-i+1>=maxc;++i) {while(j<nodes&&seq[j]<=seq[i]*fact) ++j;maxc=max(j-i,maxc);}
//    cout<<maxc;
//}
//
////说明：给一个序列L和因子f，让你从L中找尽可能多的数组成一个子序列R，使R中元素最大值为m，最小值为n，m和n满足m<=n*f。
//
////分析：这题关键在于求最小值n和最大值m，首先对L做一个排序，i作为左边界，指向n，j作为右边界，试探m，根据贪心的思想，在n确定时，要让序列最长，最大值m一定要最大。最后j指向m的后面，j-i即为当前子序列R的长度，试探不同的i求出最长子序列即可。
//
////注意：1、这题因为会超时，所以对i和j的边界也有一个要求。i到序列末尾的长度不能小于当前maxc，若是小于，则后面求出的序列长一定会小于maxc。下一个j从上一个m后面开始试探，因为根据上式，当n变大时，m不变或变大（思考什么情况下会不变？）。2、题中给出的f范围在10^9之内，因此要用longlong来表示。
