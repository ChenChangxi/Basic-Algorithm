//// Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10^5) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.
////
//// Then N lines follow, each describes a node in the format:
////
//// Address Data Next
////
//// where Address is the position of the node, Data is an integer, and Next is the position of the next node.
////
//// Output Specification:
//// For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.
//
//// Sample Input:
//// 00100 6 4
//// 00000 4 99999
//// 00100 1 12309
//// 68237 6 -1
//// 33218 3 00000
//// 99999 5 68237
//// 12309 2 33218
//
//// Sample Output:
//// 00000 4 33218
//// 33218 3 12309
//// 12309 2 00100
//// 00100 1 99999
//// 99999 5 68237
//// 68237 6 -1
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define SIZE 100000
//
//using namespace std;
//
//int start,nodes,skip,coun,data[SIZE],nexts[SIZE];vector<int> lists,inver;
//
//int main() {
//    cin>>start>>nodes>>skip;for(int i=0,value;i<nodes;++i) cin>>value>>data[value]>>nexts[value];
//    for(int i=start;i!=-1;i=nexts[i]) lists.push_back(i);nodes=(int)lists.size();inver=lists;
//    for(int i=0;i<nodes/skip*skip;++i) inver[i]=lists[i/skip*skip+skip-i%skip-1];
//    for(int i=0;i<nodes;++i)
//       {if(i) printf("%05d\n",inver[i]);printf("%05d %d ",inver[i],data[inver[i]]);} printf("-1");
//}
//
////说明：给一个链表L，从第一个节点开始，每间隔k个结点为一个子链表，把所有子链表倒转，不够k个节点的子链表不做处理，最后将这些倒转后的子链表连接成为一个新的链表R并输出。
//
////分析：原链表L与倒转链表R中的元素有着一一对应的关系，对应法则为R（i）=L（i/k*k+k-i%k-1）。对于R中的每个i，m=i/k的含义是i在R的“第m个”子链表Rm中，那么m*k就是Rm的起始位置，p=i%k-1是i在Rm中的位置，k-p就是i在Lm中的位置，然后m*k+k-p就是i在L中的位置，这样当我们遍历R中的所有位置，并在L中找到对应的元素后，就求出了R。
//
////注意：1、最后一个子链表可能不够k个节点从而不用处理，所以我们只需先令R=L，然后处理到最后一个满足条件的子链表即可。2、在输出的时候我们只输出当前的节点id和data，它的next可以用下一个节点去“补”，这样做的好处是不用判断链表在哪里结束，当要把多个链表合并成一个链表时（如1133题），这种方法就显得很简单，少判断了很多东西。
