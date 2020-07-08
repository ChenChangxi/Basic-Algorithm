//// People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.
////
//// Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?
////
//// Input Specification:
//// Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return \n. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].
////
//// Output Specification:
//// For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.
////
//// Note that words are case insensitive.
//
//// Sample Input:
//// Can1: "Can a can can a can? It can!"
//
//// Sample Output:
//// can 5
//
//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//string origin,subs,target;map<string,int> exist;int nodes;
//
//int main() {
//    getline(cin,origin);origin+=" ";
//    for(int i=0;i<origin.size();++i)
//       {if(isalnum(origin[i])) subs+=tolower(origin[i]);else {subs!=""?exist[subs]++:NULL;subs="";}}
//    for(auto it=exist.begin();it!=exist.end();++it) {if(it->second>nodes) {subs=it->first;nodes=it->second;}}
//    cout<<subs<<" "<<nodes;
//}
//
//
////说明：给你某个人说的一段话，让你找到这个人在这段话中最常说的单词，其中有效的单词是指连续的字母和数字组成的子串，假如有多个，输出按字典序（lexicographically）最小的。
//
////分析：本题关键是求一个连续的“字母数字子串”，开始位置是第一个符合条件的位置，结束位置是第一个不符合条件，且辅助串不空的位置，他们之间就是求得的一个单词，然后用一个hash数组来统计每个单词出现的次数，最后输出出现次数最多的单词。
//
////注意：1、isalnum是判断字母数字的函数，参数为字符的ASCII码，如果是字母数字返回1否则就是0。tolower是把大写字母转化为小写字母的函数，参数为字符的ASCII码，如果是大写字母返回其对应小写字母的ASCII码，否则返回原字符，它们是C语言标准库中的函数。2、map底层是红黑树，会自动按字典序升序排序，关于字典序，我会在Analog中详细说明（那里用的比较多）。3、这题到第一个不符合条件地方判断，所以结尾子串无法判断，这和1077题不同，那题只判断一个子串，无论到没到结尾都能判断出正确的子串。
