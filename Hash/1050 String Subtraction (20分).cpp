//// Given two strings S(1) and S(2) , S=S(1)−S(2) is defined to be the remaining string after taking all the characters in S(2) from S(1) . Your task is simply to calculate S(1)−S(2) for any given strings. However, it might not be that simple to do it fast.
////
//// Input Specification:
//// Each input file contains one test case. Each case consists of two lines which gives S(1) and S(2) , respectively. The string lengths of both strings are no more than 10^4 . It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.
////
//// Output Specification:
//// For each test case, print S(1)−S(2) in one line.
//
//// Sample Input:
//// They are students.
//// aeiou
//
//// Sample Output:
//// Thy r stdnts.
//
//#include <iostream>
//#include <unordered_map>
//#include <string>
//
//using namespace std;
//
//string origin,target;unordered_map<char,int> exist;int indexs;
//
//int main() {
//    getline(cin,origin);
//    getline(cin,target);
//    for(int i=0;i<target.size();++i) exist[target[i]]=1;
//    while(indexs<origin.size()) if(exist[origin[indexs]]) origin.erase(indexs,1);else ++indexs;
//    cout<<origin;
//}
//
////说明：对于一个原串和给定串，在原串中删除那些给定串中出现过的字符。
//
////分析：对于给定串的每个字符，在hash数组中置为1，然后遍历原串，看每一个字符是否在hash数组中被置为1，如果是则删除这个字符，不是则继续遍历。
//
////注意：1、在原串中删除一个字符时字符指针不要动，如abcde，当前指针在第三个位置指向c，删除c后的串为abde，字符指针还在第三个位置指向d，假如此时指针加1，指向e，会少判断。2、注意erase函数的使用，第一个参数是删除位置，第二个参数是删除字符的个数。
