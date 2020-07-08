//// On a broken keyboard, some of the keys are worn out. So when you type some sentences, the characters corresponding to those keys will not appear on screen.
////
//// Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the 1st line contains the original string, and the 2nd line contains the typed-out string. Each string contains no more than 80 characters which are either English letters [A-Z] (case insensitive), digital numbers [0-9], or _ (representing the space). It is guaranteed that both strings are non-empty.
////
//// Output Specification:
//// For each test case, print in one line the keys that are worn out, in the order of being detected. The English letters must be capitalized. Each worn out key must be printed once only. It is guaranteed that there is at least one worn out key.
//
//// Sample Input:
//// 7_This_is_a_test
//// _hs_s_a_es
//
//// Sample Output:
//// 7TI
//
//#include <iostream>
//#include <unordered_map>
//#include <string>
//
//using namespace std;
//
//string origin,target;unordered_map<char,int> exist;
//
//int main() {
//    cin>>origin>>target;
//    for(int i=0;i<target.size();++i) exist[toupper(target[i])]=1;
//    for(int i=0;i<origin.size();++i)
//        if(!exist[toupper(origin[i])]) {printf("%c",toupper(origin[i]));exist[toupper(origin[i])]=1;}
//}
//
////说明：给一个你要输入的字符串和最终显示在屏幕上的字符串，问哪些键坏了。
//
////分析：用一个hash数组存显示在屏幕上的字符，遍历原串，假如某字符在hash数组中为0，没有显示在屏幕上，就说明这个键坏了。
//
////注意：toupper是把小写字母转化为大写字母的函数，参数为字符的ASCII码，如果是小写字母返回其对应大写字母的ASCII码，否则返回原字符，它是C语言标准库中的函数。
