//// Given N integers, you are supposed to find the smallest positive integer that is NOT in the given list.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤10^5). Then N integers are given in the next line, separated by spaces. All the numbers are in the range of int.
////
//// Output Specification:
//// Print in a line the smallest positive integer that is missing from the input list.
//
//// Sample Input:
//// 10
//// 5 -25 9 6 1 3 4 2 5 17
//
//// Sample Output:
//// 7
//
//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//unordered_map<int,int> exist;
//
//int nodes,result;
//
//int main() {
//    cin>>nodes;
//    for(int i=0,value;i<nodes;++i) {cin>>value;exist[value]=1;}
//    while(exist[++result]);cout<<result;
//}
//
////说明：找一个集合中没有出现过的最小正整数。（这题也太水了吧）
//
////分析：设一个hash数组，输入的数在hash数组中置1，表示出现过，然后从一开始遍历hash数组，第一个为0的数即为所求。
