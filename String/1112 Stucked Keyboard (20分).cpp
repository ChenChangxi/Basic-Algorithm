//// On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will appear repeatedly on screen for k times.
////
//// Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string.
////
//// Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed k times whenever it is pressed. For example, when k=3, from the string thiiis iiisss a teeeeeest we know that the keys i and e might be stucked, but s is not even though it appears repeatedly sometimes. The original string could be this isss a teest.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the 1st line gives a positive integer k (1<k≤100) which is the output repeating times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from {a-z}, {0-9} and _. It is guaranteed that the string is non-empty.
////
//// Output Specification:
//// For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key.
//
//// Sample Input:
//// 3
//// caseee1__thiiis_iiisss_a_teeeeeest
//
//// Sample Output:
//// ei
//// case1__this_isss_a_teest
//
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int sucks;string origin;unordered_map<char,int> exist,visit;
//
//int main() {
//    scanf("%d\n",&sucks);getline(cin,origin);origin+=" ";
//    for(int i=0;i<origin.size();++i) exist[origin[i]]=0;
//    for(int i=1,j=0;i<origin.size();++i) {if(origin[i]!=origin[j]) {if((i-j)%sucks) exist[origin[j]]=1;j=i;}}
//    for(int i=0;i<origin.size()-1;++i)
//       {if(!exist[origin[i]]) cout<<origin[i];if(exist[origin[i]]<=0) {origin.erase(i,sucks-1);exist[origin[i]]=-1;}}
//    cout<<"\n"<<origin.substr(0,origin.size()-1);
//}
//
////说明：给一个用某键盘输入的串，假如某一个字符在串中连续出现一定的次数，我们就认为这个键坏了，现在问你那些键坏了，并输出原本想要输入的串。
//
////分析：这题的关键问题是在串中求有“连续相同字符”的子串，结束为第一个不满足条件的位置，开始为上一个子串的结束的位置，那么它们之间就是所求子串。假如存在一个子串的长不是重复值的整数倍，那么这个按出这个子串的键就没坏（这样避免了很多讨论）。最后处理原串，在坏键的每个重复串中保留一个字符。
//
////注意：1、由于每次是到第一个不满足条件的位置判断前面子串，这就导致了结尾的串没办法，所以在结尾加一个空格符，这样结尾的串就可以判断，最后把空格去掉即可。2、由于这题在处理每个坏键重复串时保留了一个字符，所以在删除字符后指针要向后移动一位，比如abcdeeefg，当前指针在e，在删除e后为abcdefg，指针要向后移动一位到f，这和1050题是不同的。
