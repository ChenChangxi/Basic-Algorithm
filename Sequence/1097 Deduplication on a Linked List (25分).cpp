//// Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (≤10^5) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by −1.
////
//// Then N lines follow, each describes a node in the format:
////
//// Address Key Next
////
//// where Address is the position of the node, Key is an integer of which absolute value is no more than 10(4), and Next is the position of the next node.
////
//// Output Specification:
//// For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input.
//
//// Sample Input:
//// 00100 5
//// 99999 -7 87654
//// 23854 -15 00000
//// 87654 15 -1
//// 00000 -15 99999
//// 00100 21 23854
//
//// Sample Output:
//// 00100 21 23854
//// 23854 -15 99999
//// 99999 -7 -1
//// 00000 -15 87654
//// 87654 15 -1
//
//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <unordered_map>
//#define SIZE 100000
//
//using namespace std;
//
//int start,nodes,data[SIZE],nexts[SIZE];unordered_map<int,int> exist;vector<int> lists,remos;
//
//void print() {
//    for(int i=0;i<lists.size();++i)
//       {if(i) printf("%05d\n",lists[i]);printf("%05d %d ",lists[i],data[lists[i]]);}
//}
//
//int main() {
//    cin>>start>>nodes;for(int i=0,value;i<nodes;++i) {cin>>value>>data[value]>>nexts[value];}
//    for(int i=start;i!=-1;i=nexts[i])
//        if(!exist[abs(data[i])]) {exist[abs(data[i])]=1;lists.push_back(i);} else remos.push_back(i);
//    print();printf("-1\n");lists=remos;print();if(lists.size()) printf("-1\n");
//}
//
////说明：给一个链表L，其中绝对值相同的元素叫做重复元素，去除其中所有重复元素，只保留首先出现在链表中的元素，被删除的元素组成一个新的链表N，求删除后的链表L以及链表N。
//
////分析：遍历链表，用hash数组来记录当前元素的绝对值是否出现过，出现过就把id加入remos中，没有就把id加入lists中，最后输出即可。
//
////注意：remos数组中可能没有元素，所以在最后输出-1的时候要判断一下。
