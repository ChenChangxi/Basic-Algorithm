//// Being unique is so important to people on Mars that even their lottery is designed in a unique way. The rule of winning is simple: one bets on a number chosen from [1,10^4]. The first one who bets on a unique number wins. For example, if there are 7 people betting on { 5 31 5 88 67 88 17 }, then the second one who bets on 31 wins.
////
//// Input Specification:
//// Each input file contains one test case. Each case contains a line which begins with a positive integer N (≤10^5) and then followed by N bets. The numbers are separated by a space.
////
//// Output Specification:
//// For each test case, print the winning number in a line. If there is no winner, print None instead.
//
//// Sample Input 1:
//// 7 5 31 5 88 67 88 17
//
//// Sample Output 1:
//// 31
//
//// Sample Input 2:
//// 5 888 666 666 888 888
//
//// Sample Output 2:
//// None
//
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//
//using namespace std;
//
//unordered_map<int,int> counts;
//
//int nodes,first;vector<int> bets;
//
//int main() {
//    cin>>nodes;
//    for(int i=0,value;i<nodes;++i) {cin>>value;bets.push_back(value);counts[value]++;}
//    for(int i=0;i<nodes;++i) if(counts[bets[i]]==1) {first=bets[i];break;}
//    if(first) cout<<first;else cout<<"None";
//}
//
////说明：给定一个打赌序列，求出第一个只出现一次的数。
//
////分析：一个bets数组存输入序列，一个hash数组统计个数，遍历bets求出第一个在counts中统计值为1的数，如果全部出现超过一次输出None。
