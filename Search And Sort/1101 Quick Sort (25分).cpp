//// There is a classical process named partition in the famous quick sort algorithm. In this process we typically choose one element as the pivot. Then the elements less than the pivot are moved to its left and those larger than the pivot to its right. Given N distinct positive integers after a run of partition, could you tell how many elements could be the selected pivot for this partition?
////
//// For example, given N=5 and the numbers 1, 3, 2, 4, and 5. We have:
////
//// ·1 could be the pivot since there is no element to its left and all the elements to its right are larger than it;
//// ·3 must not be the pivot since although all the elements to its left are smaller, the number 2 to its right is less than it as well;
//// ·2 must not be the pivot since although all the elements to its right are larger, the number 3 to its left is larger than it as well;
//// ·and for the similar reason, 4 and 5 could also be the pivot.
////
//// Hence in total there are 3 pivot candidates.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤10^5). Then the next line contains N distinct positive integers no larger than 10^9. The numbers in a line are separated by spaces.
////
//// Output Specification:
//// For each test case, output in the first line the number of pivot candidates. Then in the next line print these candidates in increasing order. There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.
//
//// Sample Input:
//// 5
//// 1 3 2 4 5
//
//// Sample Output:
//// 3
//// 1 4 5
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int nodes;vector<long long> res,fro,bac,ans;
//
//int main() {
//    cin>>nodes;res.resize(nodes);fro.resize(nodes);bac.resize(nodes);for(int i=0;i<nodes;++i) cin>>res[i];fro=bac=res;
//    for(int i=1;i<nodes;++i) fro[i]=max(res[i],fro[i-1]);for(int i=nodes-2;i>=0;--i)bac[i]=min(res[i],bac[i+1]);
//    for(int i=0;i<nodes;++i) if(res[i]==fro[i]&&res[i]==bac[i]) ans.push_back(res[i]);
//    printf("%d\n",(int)ans.size());sort(ans.begin(),ans.end());for(int i=0;i<ans.size();++i) cout<<ans[i]<<(i!=ans.size()-1?" ":"");printf("\n");
//}
//
//
////说明：选定一个元素p作为枢轴，对某序列做快速排序，现在给出排序后的结果L，问你那些元素可能为被选枢轴？
//
////分析：分析枢轴p的特点，p左边的元素必须全部小于p，p右边的元素必须全部大于p。那么设两个数组S和R，S中第i个元素的含义是从0到i的最大元素，R中第i个元素的含义是从i到序列尾最小的元素，如果S（i）=R（i）=L（i），说明i是它左边序列的最大元素，同时也是它右边序列的最小元素，即符合题意。
//
////注意：这题当没有枢轴的时候要在下面多打一个换行，否则会格式错误。
