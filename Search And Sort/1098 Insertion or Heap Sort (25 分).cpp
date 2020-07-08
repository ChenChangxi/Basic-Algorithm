//// According to Wikipedia:
////
//// Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
////
//// Heap sort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region. it involves the use of a heap data structure rather than a linear-time search to find the maximum.
////
//// Now given the initial sequence of integers, together with a sequence which is a result of several iterations of some sorting method, can you tell which sorting method we are using?
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then in the next line, N integers are given as the initial sequence. The last line contains the partially sorted sequence of the N numbers. It is assumed that the target sequence is always ascending. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print in the first line either “Insertion Sort” or “Heap Sort” to indicate the method used to obtain the partial result. Then run this method for one more iteration and output in the second line the resuling sequence. It is guaranteed that the answer is unique for each test case. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
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
//// 3 1 2 8 7 5 9 4 6 0
//// 6 4 5 1 0 3 2 7 8 9
//
//// Sample Output 2:
//// Heap Sort
//// 5 4 3 1 0 2 6 7 8 9
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int nodes,i,j,k,n;vector<int> forms,sorts;
//
//int main() {
//    cin>>nodes;for(int i=0,value;i<nodes;++i) {cin>>value;forms.push_back(value);}
//    for(int i=0,value;i<nodes;++i) {cin>>value;sorts.push_back(value);}
//    while(i<nodes&&sorts[i]<=sorts[i+1]) ++i;j=++i;while(i<nodes&&sorts[i]==forms[i]) ++i;
//    if(i==nodes) {printf("Insertion Sort\n");auto it=sorts.begin();sort(it,it+j+1);} else printf("Heap Sort\n");
//    if(i!=nodes) {n=nodes-1;while(sorts[n]>sorts[0]) --n;i=n;while(k<n&&i!=k) {swap(sorts[i],sorts[k]);i=k;j=2*k+1;if(j+1<n&&sorts[j+1]>sorts[j]) ++j;if(sorts[k]<sorts[j]) k=j;}}
//    for(int i=0;i<nodes;++i) cout<<(i?" ":"")<<sorts[i];
//}
//
////说明：给一个原始序列L和一个部分排序后的序列S（i），问你用的是插入排序还是堆排序，并输出相应排序的下一个迭代序列S（i+1）。
//
////分析：插入排序在1089题中已经说过了，这里不说，说一下堆排序，也是只说一次，后面不说。堆是一棵完全二叉树，当节点数n确定时，堆的形状就确定了，节点k的左孩子为2*k，右孩子为2*k+1，因此堆可以用顺序存储方式来表示。以大顶堆为例，它必须满足V（k）>max（V（2*k），V（2*k+1））。堆有两个关键操作，建堆和筛选，对于一个给定序列S（i），建堆就是分别以它的第n/2个节点（最后一个非叶结点）及前面的节点为根结点，向下逐步调整，假如当前根节点与其孩子结点的关系不满足上式，那么交换当前根节点与孩子子节点的位置。筛选是一个排序的过程，输出堆顶，将堆中最后一个元素与堆顶交换，然后从根结点向下调整，使堆重新满足上式。这样输出所有的元素后，序列就是一个有序序列。这题建堆的工作已经做完了，且筛选的工作也做了一部分，我们只需找到堆尾，然后与堆顶交换，再做一个调整即可。
//
////注意：这题大家可以分析一下堆排序的边界（模拟一下过程，重在分析i，j，k三个指针它们的作用），我同样在这里不再分析，需要注意的是我用了一个巧妙的办法把堆顶堆底互换和互换后调整时的两个swap函数结合成了一个。
