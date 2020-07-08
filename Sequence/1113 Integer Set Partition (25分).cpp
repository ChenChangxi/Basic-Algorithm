//// Given a set of N (>1) positive integers, you are supposed to partition them into two disjoint sets A1 and A2 of n1 and n2 numbers, respectively. Let S1 and S2 denote the sums of all the numbers in A1 and A2, respectively. You are supposed to make the partition so that ∣n1−n2∣ is minimized first, and then ∣S1−S2∣ is maximized.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives an integer N (2≤N≤10^5), and then N positive integers follow in the next line, separated by spaces. It is guaranteed that all the integers and their sum are less than 2^31.
////
//// Output Specification:
//// For each case, print in a line two numbers: ∣n1−n2∣ and ∣S1−S2∣, separated by exactly one space.
//
//// Sample Input 1:
//// 10
//// 23 8 10 99 46 2333 46 1 666 555
//
//// Sample Output 1:
//// 0 3611
//
//// Sample Input 2:
//// 13
//// 110 79 218 69 3721 100 29 135 2 6 13 5188 85
//
//// Sample Output 2:
//// 1 9359
//
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <vector>
//
//using namespace std;
//
//long long total,segms;int nodes;vector<int> nums;
//
//int main() {
//    cin>>nodes;
//    for(int i=0,value;i<nodes;++i) {cin>>value;nums.push_back(value);total+=value;}
//    sort(nums.begin(),nums.end());
//    for(int i=0;i<nodes/2;++i) segms+=nums[i];cout<<(nodes%2?1:0)<<" "<<abs(total-2*segms);
//}
//
////说明：给一个集合A，让你把它分为A1和A2两个集合，它们的元素个数分别为n1和n2，集合中元素的和分别为S1和S2，这两个集合满足不相交，且在∣n1−n2∣最小的条件下∣S1−S2∣最大，现在让你求出这两个集合的∣n1−n2∣以及∣S1−S2∣。
//
////分析：这题用了一个贪心的思想。若要让∣n1−n2∣最小，A中的元素必须要尽可能“均分”给A1和A2，接着若要让∣S1−S2∣最大，那么A1中的元素要尽可能的大，A2中的元素要尽可能地小。综上我只需要把A按值做一个排序，后n/2分给A1，前n/2分给A2即可。（偶数均分，奇数多出来的元素要分给A1。）
//
////注意：1、这题的不重复是指元素（key）不重复，而不是值（value）不重复。2、假如A中元素和为S，显然有S=S1+S2，那么S1-S2=S-2*S2，所以这题在输入A的时候需要求一个S，然后遍历排序后的A求前n/2的和S2，最后用上述公式计算，否则会超时。3、题中告诉你S不超过2^31，显然需要用long long来表示。
