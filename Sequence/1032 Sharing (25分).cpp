//// To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, loading and being are stored as showed in Figure 1.
////
////                                          fig.jpg
////
////                                          Figure 1
////
//// You are supposed to find the starting position of the common suffix (e.g. the position of i in Figure 1).
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (≤10^5), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by −1.
////
//// Then N lines follow, each describes a node in the format:
////
//// Address Data Next
////
//// where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from { a-z, A-Z }, and Next is the position of the next node.
////
//// Output Specification:
//// For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output -1 instead.
//
//// Sample Input 1:
//// 11111 22222 9
//// 67890 i 00002
//// 00010 a 12345
//// 00003 g -1
//// 12345 D 67890
//// 00002 n 00003
//// 22222 B 23456
//// 11111 L 00001
//// 23456 e 67890
//// 00001 o 00010
//
//// Sample Output 1:
//// 67890
//
//// Sample Input 2:
//// 00001 00002 4
//// 00001 a 10001
//// 10001 s -1
//// 00002 a 10002
//// 10002 t -1
//
//// Sample Output 2:
//// -1
//
//#include <iostream>
//#include <unordered_map>
//#define SIZE 100000
//
//using namespace std;
//
//int nodes,fsta,ssta,nexts[SIZE];char data[SIZE];unordered_map<int,int> visit;
//
//int main() {
//    cin>>fsta>>ssta>>nodes;for(int i=0,value;i<nodes;++i) cin>>value>>data[value]>>nexts[value];
//    for(int i=ssta;i!=-1;i=nexts[i]) visit[i]=1;
//    for(int i=fsta;i!=-1;i=nexts[i]) if(visit[i]) {printf("%05d",i);return 0;} cout<<-1;
//}
//
////说明：给两个可能有公共后缀的链表，让你求它们公共后缀的第一个结点的id，如果没有公共后缀，输出-1。
//
////分析：用一个nexts数组和data数组分别来存下址映射和数据映射，首先遍历链表1并把所有结点在visit中设置为1，接着遍历链表2，第一个在visit数组中为被置为1的节点即为所求公共后缀的首结点。
