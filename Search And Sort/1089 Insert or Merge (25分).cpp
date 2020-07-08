//// According to Wikipedia:
////
//// Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
////
//// Merge sort works as follows: Divide the unsorted list into N sublists, each containing 1 element (a list of 1 element is considered sorted). Then repeatedly merge two adjacent sublists to produce new sorted sublists until there is only 1 sublist remaining.
////
//// Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print in the first line either "Insertion Sort" or "Merge Sort" to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
//
//// Sample Input 1:
//// 10
//// 3 1 2 8 7 5 9 4 6 0
//// 1 2 3 7 8 5 9 4 6 0
//
//// Sample Output 1:
//// Insertion Sort
//// 1 2 3 5 7 8 9 4 6 0
//
//// Sample Input 2:
//// 10
//// 3 1 2 8 7 5 9 4 0 6
//// 1 3 2 8 5 7 4 9 0 6
//
//// Sample Output 2:
//// Merge Sort
//// 1 2 3 8 4 5 7 9 0 6
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int nodes,i,j,k;vector<int> forms,sorts;
//
//int main() {
//    cin>>nodes;for(int i=0,value;i<nodes;++i) {cin>>value;forms.push_back(value);}
//    for(int i=0,value;i<nodes;++i) {cin>>value;sorts.push_back(value);}
//    while(i<nodes&&sorts[i]<=sorts[i+1]) ++i;j=++i;while(j<nodes&&sorts[j]==forms[j]) ++j;
//    auto it=forms.begin();auto ite=forms.end();if(j!=nodes) printf("Merge Sort\n");else printf("Insertion Sort\n");
//    if(j==nodes) sort(it,it+i+1);else {k=1;j=0;while(i){if(forms==sorts) i=0;while(j<nodes/k) {sort(it+j*k,it+(j+1)*k);++j;}if(nodes%k) sort(it+j*k,ite);k*=2;j=0;}}
//    for(int i=0;i<nodes;++i) cout<<(i?" ":"")<<forms[i];
//}
//
////说明：给一个原始序列L和一个部分排序后的序列S（i），问你用的是插入排序还是归并排序，并输出相应排序的下一个迭代序列S（i+1）。
//
////分析：我们只需要关注一下插入排序和归并排序后序列的特点即可，假如S（i）是插入排序，那么S（i）中从左到右第一个无序元素k及其后面必与L中对应位置的元素相同，否则就是归并排序。插入排序的S（i+1）很简单，只需加上k再排个序即可。归并排序的S（i+1）则较难，因为对于归并排序，我们并不知道当前它是几路归并，那么我们可以让L从1路归并开始模拟，直到L=S（i），然后我们只需设置一个标志量让它多归并一次即可。
//
////注意：这题很多边界问题很难定，大家自己好好分析一下，来个头脑风暴，我就不一一分析了，一个好的算法选手应该对边界问题非常敏感，一看到这些脑子里能迅速的模拟出来同时考虑特殊位置，然后写出最简洁优秀的代码，这也是我们训练的一个目的。大家应该有这种感觉，排序的很多算法难就难在边界问题上，在这里我总结一下两种边界问题，第一种是“位置”和“长度”边界，包括起始位置s，结束位置e，第一个不满条件的位置p，那么序列长度l=p-s=e-s+1（sort函数中的end的含义就是p而不是e），同时千万要记得“位置”不能越界。第二种是“除”与“取模”边界，假如序列长为l，模为k，m=l/k的含义是序列l能被分为m个k（商），n=l%k的含义是把l分为m个k后序列剩下n个元素（余数），显然有l=m*k+n=l/k*k+l%k。当然很多时候以上两种问题会结合起来玩。
