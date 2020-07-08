//// "Damn Single (单身狗)" is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big party, so they can be taken care of.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 50,000), the total number of couples. Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is a positive integer M (≤ 10,000) followed by M ID's of the party guests. The numbers are separated by spaces. It is guaranteed that nobody is having bigamous marriage (重婚) or dangling with more than one companion.
////
//// Output Specification:
//// First print in a line the total number of lonely guests. Then in the next line, print their ID's in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line.
//
//// Sample Input:
//// 3
//// 11111 22222
//// 33333 44444
//// 55555 66666
//// 7
//// 55555 44444 10000 88888 22222 11111 23333
//
//// Sample Output:
//// 5
//// 10000 23333 44444 55555 88888
//
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//
//using namespace std;
//
//unordered_map<int,int> relate,chash;
//
//vector<int> people,result;
//
//int couple,ncome;
//
//int main() {
//    cin>>couple;
//    for(int i=0,fnode,snode;i<couple;++i) {cin>>fnode>>snode;relate[fnode]=snode;relate[snode]=fnode;}
//    cin>>ncome;
//    for(int i=0,value;i<ncome;++i) {cin>>value;chash[relate[value]]=1;people.push_back(value);}
//    for(int i=0;i<ncome;++i) if(!chash[people[i]]) result.push_back(people[i]);
//    cout<<result.size()<<"\n";sort(result.begin(),result.end());
//    for(int i=0;i<result.size();++i) printf("%s%05d",!i?"":" ",result[i]);
//}
//
////说明：给出若干对夫妇，并给出一个出席派对的名单，请问名单上都有谁单身（包括没有配偶的和配偶没来的）。
//
////分析：对于名单上的每个人，我都在hash数组中把他的配偶置为一，相当于向他的配偶发出了一个通知，通知自己来了，那么每个人在hash数组中为一的含义就是自己的配偶是来了（没有配偶的和配偶没来的都不会被通知到，对应位置为0），最后所有对应位置为0的人就是派对上的单身狗，输出。
//
////注意：最后输出必须是五位的，前面有0要补，这在后面非常常见。
