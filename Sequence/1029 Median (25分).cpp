//// Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
////
//// Given two increasing sequences of integers, you are asked to find their median.
////
//// Input Specification:
//// Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (≤2×10^5) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.
////
//// Output Specification:
//// For each test case you should output the median of the two given sequences in a line.
//
//// Sample Input:
//// 4 11 12 13 14
//// 5 9 10 15 16 17
//
//// Sample Output:
//// 13
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int fnods,snods,val,pos,j,k;vector<int> seq;
//
//int main() {
//    cin>>fnods;for(int i=0;i<fnods;++i) {scanf("%d",&val);seq.push_back(val);} cin>>snods;pos=(snods+fnods+1)/2;
//    for(int i=0;i<snods;++i)
//       {scanf("%d",&val);while(++k!=pos&&j<fnods&&seq[j]<val) ++j;if(k==pos) cout<<(seq[j]<val&&j!=fnods?seq[j]:val);}
//    if(k<pos) cout<<seq[j+pos-k-1];
//}
//
////说明：给两个有序序列A和B，把这两个序列合并为一个新的有序序列N，求这个序列的中位数m（（Count（A）+count（B）+1）/2）。
//
////分析：这就相当于把序列B中的元素按大小“插入”序列A（插入排序的思想）。对于B中的元素b，我们首先要找A中“第一个”比b大的元素a，这就是元素b插入的位置，我们设置k统计当前遍历的元素个数，同时用j来探测a，在这个过程中一旦k为m，即求得结果。关于m的位置有以下4种情况，情况1是探测过程中在A中出现的，情况2是探测结束后在B中出现的，情况3是A中不存在时在B中出现的，情况4是B中不存在时在A中出现的。其中情况2和3可归为一种情况，在输入B时我们设置判断条件区别1跟23，在输入后假如出现情况4即k依然不等于m，那么此时m在A中的位置就为j+k-m-1。（思考为什么？这也是个难点）
//
////情况：A 1⃣️ 1 2 3 *4   6 7  2⃣️ 1 2   4 5    3⃣️ 1 2 3                  4⃣️ 1  3 4  *6 7 8 9 10 11
////     B             5             *3                 4 *5 6 7 8 9         2    5
//
////注意：这题用任何其他方法都会超时，它的通过率是0·14，在PAT的难题排行榜上应该拥有姓名。
