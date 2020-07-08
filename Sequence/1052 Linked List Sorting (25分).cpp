//// A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains a positive N (<10^5) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by −1.
////
//// Then N lines follow, each describes a node in the format:
////
//// Address Key Next
////
//// where Address is the address of the node in memory, Key is an integer in [−10^5,10^5], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.
////
//// Output Specification:
//// For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.
//
//// Sample Input:
//// 5 00001
//// 11111 100 -1
//// 00001 0 22222
//// 33333 100000 11111
//// 12345 -1 33333
//// 22222 1000 12345
//
//// Sample Output:
//// 5 12345
//// 12345 -1 00001
//// 00001 0 11111
//// 11111 100 22222
//// 22222 1000 33333
//// 33333 100000 -1
//
//#include <iostream>
//#include <unordered_map>
//#include <algorithm>
//#include <vector>
//#define SIZE 100000
//
//using namespace std;
//
//int nodes,start,nexts[SIZE],data[SIZE];unordered_map<int,int> dhash;vector<int> datas;
//
//int main() {
//    cin>>nodes>>start;
//    for(int i=0,value;i<nodes;++i) {cin>>value>>data[value]>>nexts[value];dhash[data[value]]=value;}
//    for(int i=start;i!=-1;i=nexts[i]) datas.push_back(data[i]);sort(datas.begin(),datas.end());
//    nodes=(int)datas.size();printf("%d",nodes);if(nodes) printf(" %05d\n",dhash[datas[0]]);else printf(" -1");
//    for(int i=0;i<datas.size();++i)
//    {printf("%05d %d ",dhash[datas[i]],datas[i]);if(i!=nodes) printf("%05d\n",dhash[datas[i+1]]);else printf("-1");}
//}
//
//
////说明：给一个链表，让你把其中的元素按值的大小重新排列，并按照输入的格式来输出新的链表。
//
////分析：把元素的值加入datas数组重新排列。然后对于datas中的每个元素，去phash中去查它们的id，以及它们下一个元素的id输出即可。
//
////注意：1、这题给的链表可能会有多余元素，所以在构建完之后必须要遍历一遍再加入datas数组。2、链表还可能为空，这个时候要输出0 -1。
