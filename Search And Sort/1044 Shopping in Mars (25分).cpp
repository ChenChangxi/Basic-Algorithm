// Shopping in Mars is quite a different experience. The Mars people pay by chained diamonds. Each diamond has a value (in Mars dollars M$). When making the payment, the chain can be cut at any position for only once and some of the diamonds are taken off the chain one by one. Once a diamond is off the chain, it cannot be taken back. For example, if we have a chain of 8 diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15. We may have 3 options:
//
// 1.Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3+2+1+5+4=15).
// 2.Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5+4+6=15).
// 3.Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8+7=15).
//
// Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.
//
// If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.
//
// Input Specification:
// Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤10^5), the total number of diamonds on the chain, and M (≤10^8), the amount that the customer has to pay. Then the next line contains N positive numbers D1⋯DN(Di≤10^3) for all i=1,⋯,N) which are the values of the diamonds. All the numbers in a line are separated by a space.
//
// Output Specification:
// For each test case, print i-j in a line for each pair of i ≤ j such that Di + ... + Dj = M. Note that if there are more than one solution, all the solutions must be printed in increasing order of i.
//
// If there is no solution, output i-j for pairs of i ≤ j such that Di + ... + Dj >M with (Di + ... + Dj −M) minimized. Again all the solutions must be printed in increasing order of i.
//
// It is guaranteed that the total value of diamonds is sufficient to pay the given amount.

// Sample Input 1:
// 16 15
// 3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13

// Sample Output 1:
// 1-5
// 4-6
// 7-8
// 11-11

// Sample Input 2:
// 5 13
// 2 4 5 7 9

// Sample Output 2:
// 2-4
// 4-5

#include <iostream>
#include <vector>
#include <map>
#define INF 1215752100

using namespace std;

int nodes,thre,minc=INF;vector<int> pays;map<int,int> subs;

int main() {
    cin>>nodes>>thre;pays.resize(nodes+1);for(int i=1;i<=nodes;++i) {cin>>pays[i];pays[i]+=pays[i-1];}
    for(int i=1,j=i,k=nodes,m=0,t=0;i<=nodes;++i,j=i,k=nodes) {
        while(j<=k) {m=(j+k)/2;t=pays[m]-pays[i-1];if(t>thre) k=m-1;else if(t<thre) j=m+1;else break;}
        if(t>=thre) if(t<=minc) {if(t<minc) subs.clear();minc=t;subs[i]=m;}
    }
    for(auto it=subs.begin();it!=subs.end();++it) printf("%d-%d\n",it->first,it->second);
}

//说明：给一个序列L和数n，让你找L中所有和为n的子序列，如果没有，就找和比n大，且误差最小的所有子序列。

//分析：我们首先求L对应的一个和数组S，d=S（j）-S（i-1）为序列L中元素i与j之间子序列的和，对于L中的每个元素i，我们用二分查找来求满足条件的j，然后把i和j加入map中自动升序排列并输出。

//注意：二分查找的各种边界很难定，我在这里就只分析一次，以后遇到自己分析。首先是结束条件，假如n为4，当前子序列为3和5，j=1指向3，k=2指向5，那么m=（1+2）/2=1指向3，那么此时满足S（m）<S（n），左边界j=m+1=2，此时j=k，退出，我们可以看出，假如在序列中查找不到n，那么此时二分查找算法中的m是自动指向n的后面的，因此我们直接求所有m的最小值即可满足题意。
