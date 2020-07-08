//// Given a singly linked list, you are supposed to rearrange its elements so that all the negative values appear before all of the non-negatives, and all the values in [0,K] appear before all those greater than K. The order of the elements inside each class must not be changed. For example, given the list being 18→7→-4→0→5→-6→10→11→-2 and K being 10, you must output -4→-6→-2→7→0→5→10→18→11.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10^5) which is the total number of nodes, and a positive K (≤10^3). The address of a node is a 5-digit nonnegative integer, and NULL is represented by −1.
////
//// Then N lines follow, each describes a node in the format:
////
//// Address Data Next
////
//// where Address is the position of the node, Data is an integer in [−10^5,10^5], and Next is the position of the next node. It is guaranteed that the list is not empty.
////
//// Output Specification:
//// For each case, output in order (from beginning to the end of the list) the resulting linked list. Each node occupies a line, and is printed in the same format as in the input.
//
//// Sample Input:
//// 00100 9 10
//// 23333 10 27777
//// 00000 0 99999
//// 00100 18 12309
//// 68237 -6 23333
//// 33218 -4 00000
//// 48652 -2 -1
//// 99999 5 68237
//// 27777 11 48652
//// 12309 7 33218
//
//// Sample Output:
//// 33218 -4 68237
//// 68237 -6 48652
//// 48652 -2 12309
//// 12309 7 00000
//// 00000 0 99999
//// 99999 5 23333
//// 23333 10 00100
//// 00100 18 27777
//// 27777 11 -1
//
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//#define SIZE 100010
//
//using namespace std;
//
//int nodes,start,thres,data[SIZE],nexts[SIZE];unordered_map<int,vector<int>> res;
//
//int main() {
//    cin>>start>>nodes>>thres;for(int i=0,value;i<nodes;++i) cin>>value>>data[value]>>nexts[value];
//    for(int i=start;i!=-1;i=nexts[i]) data[i]<0?res[0].push_back(i):data[i]<=thres?res[1].push_back(i):res[2].push_back(i);
//    for(int i=0,coun=0;i<3;++i) for(int j=0;j<res[i].size();++j) {if(coun++) printf("%05d\n",res[i][j]);printf("%05d %d ",res[i][j],data[res[i][j]]);} printf("-1");
//}
//
////说明：数k把数轴分为（-∞，k）【0，k】（k，+∞）三个区间，现在给一个链表L，要你把L中的值排序，规则是在同一区间的元素按L中的原序排，在不同区间的元素按值的大小排。
//
////分析：设三个数组，代表三个区间，然后遍历L，把L中的元素依次加入三个数组，接着按区间顺序输出三个数组即可满足上述排序要求。
//
////注意：在处理输出格式时，判定第一个数不能用i和j，因为哪个区间没有值是不确定的，因此要设置一个标志来定第一个数。
