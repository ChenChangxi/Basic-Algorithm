//// The Japanese language is notorious for its sentence ending particles. Personal preference of such particles can be considered as a reflection of the speaker's personality. Such a preference is called "Kuchiguse" and is often exaggerated artistically in Anime and Manga. For example, the artificial sentence ending particle "nyan~" is often used as a stereotype for characters with a cat-like personality:
////
//// Itai nyan~ (It hurts, nyan~)
////
//// Ninjin wa iyada nyan~ (I hate carrots, nyan~)
////
//// Now given a few lines spoken by the same character, can you find her Kuchiguse?
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line is an integer N (2≤N≤100). Following are N file lines of 0~256 (inclusive) characters in length, each representing a character's spoken line. The spoken lines are case sensitive.
////
//// Output Specification:
//// For each test case, print in one line the kuchiguse of the character, i.e., the longest common suffix of all N lines. If there is no such suffix, write nai.
//
//// Sample Input 1:
//// 3
//// Itai nyan~
//// Ninjin wa iyadanyan~
//// uhhh nyan~
//
//// Sample Output 1:
//// nyan~
//
//// Sample Input 2:
//// 3
//// Itai!
//// Ninjinnwaiyada T_T
//// T_T
//
//// Sample Output 2:
//// nai
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#define INF 260
//
//using namespace std;
//
//vector<string> origins;int nodes,minv=INF,indexs;string value;
//
//int main() {
//    scanf("%d\n",&nodes);
//    for(int i=0;i<nodes;++i) {
//        getline(cin,value);reverse(value.begin(),value.end());
//        origins.push_back(value);minv=min(minv,(int)value.size());}
//    for(int i=0,same=0;i<minv&&!same;++i,!same?indexs++:NULL)
//        for(int j=0;j<origins.size()-1;++j)
//            if(origins[j][i]!=origins[j+1][i]) same=1;
//    value=value.substr(0,indexs);reverse(value.begin(),value.end());
//    cout<<(value.length()?value:"nai");
//}
//
////说明：给你一个人经常说的若干句话，让你找到他最喜欢说的结尾，即所有输入串的最长公共尾串。
//
////分析：很多串问题都可以归结为求子串的问题，所以我来总结一下串问题的做题方法，1、确定开始时原串的输入方法及处理方式。2、确定子串结束位置和条件，子串开始位置和条件，并由结束和起始定串长（索引相减或累加统计）。3、确定结束时原串的处理方式及输出格式。以这题为例，首先把输入串翻转，子串开始是原串起始位置，子串的结束是第一个不满足条件的位置或原串尾，然后用一个index用来统计子串长，最后在原串中截取子串输出。
//
////注意：1、reverse是串翻转函数，参数是开始和结尾迭代器，它是algorithm库中的函数。substr是求子串的函数，参数是子串开始位置和子串长度，它是string库中的函数。2、这里还出现了scanf，cin和getline这三个在串处理过程中很常见但很容易混淆的输入函数，它们很重要，但它们的区别我只说一遍。cin开始遇到空格或换行符把它们清除出缓冲区，然后开始读串，最后遇到空格或者换行符停止，不做任何操作。getline会读缓冲区中除了换行符以外的所有字符，读到换行符停止，并把它清除出缓冲区。scanf会严格按照你写的格式去读缓冲区。知道了这些，请大家详细分析我上面接收字符串的代码，体会为什么要那么写。
//
