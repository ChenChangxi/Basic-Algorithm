//// The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.
////
//// Now given any string, you are supposed to tell the number of PAT's contained in the string.
////
//// Input Specification:
//// Each input file contains one test case. For each case, there is only one line giving a string of no more than 10^5 characters containing only P, A, or T.
////
//// Output Specification:
//// For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.
//
//// Sample Input:
//// APPAPT
//
//// Sample Output:
//// 2
//
//#include <iostream>
//#include <string>
//#define MODE 1000000007
//
//using namespace std;
//
//long long pcou,acou,tnum;string origin;
//
//int main() {
//    cin>>origin;
//    for(int i=(int)origin.size();i>=0;--i)
//       {if(origin[i]=='T') ++tnum;if(origin[i]=='A') acou+=tnum;if(origin[i]=='P') pcou+=acou;}
//    cout<<pcou%MODE;
//}
//
////说明：给定串s中只包含'P','A','T'三种字母，求串s中有序（P，A，T）对的个数。
//
////分析：
////一、原理：有四种情况，1、PAT三个字母都确定，PAT个数为1；2、PA确定T不确定，对于A后面每一个Ti都可以变为情况1，PAT的个数即为A后面T的个数M；3、P确定，A和T不确定，对于P后面的每一个Ai可以变为情况2，求出来一个Mi，那么PAT的个数即为N=M1+M2+···+Mi；4、P，A，T都不确定，对于每一个Pi可以变为情况3，求出一个Ni，最后PAT的总个数L=N1+N2+···+Ni。
////二、做法：这是个累加的过程，从后往前用tnum统计T（即M），遇到一个A就把当前T的个数（即Mi）累计加到acou上（即N），遇到P就把当前的acou（即Ni）累加到pcou上（即L），最后L的值即为有序对（P，A，T）的个数。
//
////注意：最后的结果可能很大，要对1000000007取模（至于为什么我就不细说了，可以看柳神的博客）。
//
////情况：1、PAT；2、PA{TTTTTT}；3、P{AAA}{TTT}{AAA}{T}；4、{PPP}{TT}{AAA}{P}{TT}{A}{T}。
