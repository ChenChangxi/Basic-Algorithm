//// Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10^5 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (≤10^5), the total number of coins) and M (≤10^3), the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print in one line the two face values V1 and V2 (separated by a space) such that V1+V2=M and V1≤V2. If such a solution is not unique, output the one with the smallest V1. If there is no solution, output No Solution instead.
//
//// Sample Input 1:
//// 8 15
//// 1 2 8 7 2 4 11 15
//
//// Sample Output 1:
//// 4 11
//
//// Sample Input 2:
//// 7 14
//// 1 8 7 2 4 11 15
//
//// Sample Output 2:
//// No Solution
//
//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//unordered_map<int,int> exist;
//
//int nodes,pay;
//
//int main() {
//    cin>>nodes>>pay;
//    for(int i=0,value;i<nodes;++i) {cin>>value;exist[value]++;}
//    for(int i=1;i<=pay/2;++i)
//        if((exist[i]--)&&exist[pay-i]) {cout<<i<<" "<<pay-i;return 0;} cout<<"No Solution";
//}
//
////分析：某人有若干一定面额的硬币，现在买一件东西需要付钱，问有没有两个硬币正好可以付这件东西的钱。
//
////说明：设置一个hash数组，index为硬币的面值，value为硬币个数，然后遍历hash数组，假如某个面值的硬币的存在，
//
////注意：
