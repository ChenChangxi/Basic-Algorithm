//// Sherlock Holmes received a note with some strange strings: Let's date! 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm. It took him only a minute to figure out that those strange strings are actually referring to the coded time Thursday 14:04 -- since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter D, representing the 4th day in a week; the second common character is the 5th capital letter E, representing the 14th hour (hence the hours from 0 to 23 in a day are represented by the numbers from 0 to 9 and the capital letters from A to N, respectively); and the English letter shared by the last two strings is s at the 4th position, representing the 4th minute. Now given two pairs of strings, you are supposed to help Sherlock decode the dating time.
////
//// Input Specification:
//// Each input file contains one test case. Each case gives 4 non-empty strings of no more than 60 characters without white space in 4 lines.
////
//// Output Specification:
//// For each test case, print the decoded time in one line, in the format DAY HH:MM, where DAY is a 3-character abbreviation for the days in a week -- that is, MON for Monday, TUE for Tuesday, WED for Wednesday, THU for Thursday, FRI for Friday, SAT for Saturday, and SUN for Sunday. It is guaranteed that the result is unique for each case.
//
//// Sample Input:
//// 3485djDkxh4hhGE
//// 2984akDfkkkkggEdsb
//// s&hgsfdk
//// d&Hyscvnm
//
//// Sample Output:
//// THU 14:04
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//string ostr,sstr,tstr,fstr,weeks[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
//
//int main() {
//    cin>>ostr>>sstr>>tstr>>fstr;
//    for(int i=0,counts=0;i<ostr.length()&&i<sstr.length();++i)
//        if(ostr[i]==sstr[i]) {
//            if(!counts&&ostr[i]>='A'&&ostr[i]<='G') {cout<<weeks[ostr[i]-'A'];++counts;}
//            else if(counts==1&&((ostr[i]>='A'&&ostr[i]<='N')||isdigit(ostr[i]))) {printf(" %02d",ostr[i]+(isdigit(ostr[i])?-'0':10-'A'));++counts;}
//        }
//    for(int i=0;i<tstr.length()&&i<fstr.length();++i)
//        if(tstr[i]==fstr[i]&&isalpha(tstr[i])) printf(":%02d",i);
//}
//
////说明：给出四个串，让你按一定的规则求出一个日期密码。
//
////分析：前两个串的第一个相同大写字母为星期（星期一～星期天分别为A～G），第二个相同大写字母或数字为小时（0时～23时分别为0～9，A～N），后两个串第一个相同字母所在的位置为分钟（串长小于60）。
//
////注意：isdigit函数用来判断一个字符是否是数字，isalpha函数用来判断一个字符是否是字母（不区分大小写），如果是则返回1，不是则返回0，它们都是C语言的标准库函数。
