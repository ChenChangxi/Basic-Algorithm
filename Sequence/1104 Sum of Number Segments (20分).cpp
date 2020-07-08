//// Given a sequence of positive numbers, a segment is defined to be a consecutive subsequence. For example, given the sequence { 0.1, 0.2, 0.3, 0.4 }, we have 10 segments: (0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) (0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) and (0.4).
////
//// Now given a sequence, you are supposed to find the sum of all the numbers in all the segments. For the previous example, the sum of all the 10 segments is 0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N, the size of the sequence which is no more than 10^5 . The next line contains N positive numbers in the sequence, each no more than 1.0, separated by a space.
////
//// Output Specification:
//// For each test case, print in one line the sum of all the numbers in all the segments, accurate up to 2 decimal places.
//
//// Sample Input:
//// 4
//// 0.1 0.2 0.3 0.4
//
//// Sample Output:
//// 5.00
//
//#include <iostream>
//
//using namespace std;
//
//int nodes;double value;long long total;
//
//int main() {
//    cin>>nodes;for(int i=1;i<=nodes;++i) {cin>>value;total+=(long long)(value*1000)*i*(nodes-i+1);}
//    printf("%.2f",total/1000.0);
//}
//
////说明：给出一个序列，让你求所有子序列，并求出所有子序列相加的和。
//
////分析：
////做法：原序列中的第k个元素为v，v在所有子序列中一共出现了t=k*（nodes-k+1）次，那么所有子序列中v的和即为s=v*t，所以我们只需要求序列中所有元素的s并累加，即可求出所有子序列的和。
////证明：我们假设原序列为（bef）v（aft），bef有k-1个元素，aft有nodes-k个元素，那么对于所有含有v的子序列，v的前面元素的个数有从0到k-1个共k种情况，v后面的元素个数有从0到nodes-k个共nodes-k+1种情况，根据乘法原理，一共有k*（nodes-k+1）种情况（子序列中各元素的顺序和原序列中相同）。为什么我在这里要证一下，因为数论的第1049题用的思想和本题相同，那题要更加精彩，所以我在这里说过之后那题就相对好理解一点了。
//
////注意：很佩服这位同学能钻的这么深，计算机通常是没有办法存精确的浮点数的，比如0·3在计算机中其实是0·300000000001（debug的时候可以看到），产生了0·000000000001的误差，当数据量很大时，误差就会积累到小数点后两位上去了，所以这题不能用double来做。我们要把小数点后的有效位向左移动到整数部分，并把它强转乘longlong类型，这时double的误差就会消失，最后求出结果后再把小数点向右移回去即可，这题有效数字最多到小数点后3位，4位的话在相乘过程中就会超出longlong的范围。但注意不是所有题都是这样，因为这题nodes最大为10^5，那么上述公式就会出现50000*50000的这种情况，而其他题根据题意，它们的浮点运算的值通常都是比较小的，比如价格等等，所以要具体问题，具体分析。
//
////博客：这位同学提交了测试用例的修改意见，现在这道题的测试点已修改。 https://blog.zhengrh.com/post/about-double/
