//// Scientific notation is the way that scientists easily handle very large numbers or very small numbers. The notation matches the regular expression [+-][1-9].[0-9]+E[+-][0-9]+ which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the number and its exponent's signs are always provided even when they are positive.
////
//// Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.
////
//// Input Specification:
//// Each input contains one test case. For each case, there is one line containing the real number A in scientific notation. The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.
////
//// Output Specification:
//// For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros.
//
//// Sample Input 1:
//// +1.23400E-03
//
//// Sample Output 1:
//// 0.00123400
//
//// Sample Input 2:
//// -1.2E+10
//
//// Sample Output 2:
//// -12000000000
//
//#include <iostream>
//#include <cmath>
//#include <string>
//
//using namespace std;
//
//string nots,real;int dots,code;
//
//int main() {
//    cin>>nots;dots=(int)nots.find('E');
//    code=stoi(nots.substr(dots+1));real=nots.substr(1,dots-1).erase(1,1);cout<<(nots[0]=='-'?"-":"");
//    if(code<0) {real=string(abs(code),'0')+real;cout<<real.insert(1,".");}
//    else cout<<(code<real.size()-1?real.insert(code+1,"."):real+string(code-real.size()+1,'0'));
//}
//
////说明：给出一个用科学计数法表示的数，让你转化为这个数的真值。
//
////分析：这题的思路正好和1060题是反过来的，首先求出有效数字串和阶码e。如果e是负数，就在串前面添e个0，最后在串下标为1的地方加上小数点。如果e是正数那么有两种情况，第一种是串带小数点，小数点在串下标为e+1的位置上，这种情况下e小于串长-1（串的结尾不能有小数点，因此e不能等于串长-1），第二种是串不带小数点，应该在串的后面补0，0的个数为e-串长+1。
//
////注意：这里用到了insert函数，有三参数和二参数这两种重载类型。三参数型的参数1为插入位置，参数2为重复次数，参数3为重复字符，二参数型的参数1为插入位置，参数2为插入字符串。
