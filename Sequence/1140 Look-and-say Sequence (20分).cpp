//// Look-and-say sequence is a sequence of integers as the following:
////
//// D, D1, D111, D113, D11231, D112213111, ...
////
//// where D is in [0, 9] except 1. The (n+1)st number is a kind of description of the nth number. For example, the 2nd number means that there is one D in the 1st number, and hence it is D1; the 2nd number consists of one D (corresponding to D1) and one 1 (corresponding to 11), therefore the 3rd number is D111; or since the 4th number is D113, it consists of one D, two 1's, and one 3, so the next number must be D11231. This definition works for D = 1 as well. Now you are supposed to calculate the Nth number in a look-and-say sequence of a given digit D.
////
//// Input Specification:
//// Each input file contains one test case, which gives D (in [0, 9]) and a positive integer N (≤ 40), separated by a space.
////
//// Output Specification:
//// Print in a line the Nth number in a look-and-say sequence of D.
//
//// Sample Input:
//// 1 8
//
//// Sample Output:
//// 1123123111
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int dups;string seq;
//
//int main() {
//    cin>>seq>>dups;seq+=" ";
//    for(int k=0;k<dups-1;++k)
//        for(int i=0,j=0;i<seq.size()-1;i+=2,j=i)
//           {while(seq[i]==seq[j]) ++j;seq.erase(i,j-i-1);seq.insert(i+1,to_string(j-i));}
//    cout<<seq.substr(0,seq.size()-1);
//}
//
////说明：对于递归序列S（i）有S（i+1）=LAS（S（i）），其中LAS为映射函数，它需要我们描述序列S（i）中的所有“连续相同”元素以及它们的重复次数。
//
////分析：我们需要求序列S1中的所有含有“连续相同”元素的子序列，并统计其元素个数c，只保留其中的一个元素m，并把c插入m后面，就得到了S2，以此归纳便可得出结果。
//
////注意：这题虽然是个序列问题，但用串来处理更方便，串本身就是一种特殊的序列，关于串处理的分析方法，各种函数的用法详见String那一章，这里我不再细说。
