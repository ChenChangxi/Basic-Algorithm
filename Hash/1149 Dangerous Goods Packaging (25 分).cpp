//// When shipping goods with containers, we have to be careful not to pack some incompatible goods into the same container, or we might get ourselves in serious trouble. For example, oxidizing agent （氧化剂） must not be packed with flammable liquid （易燃液体）, or it can cause explosion.
////
//// Now you are given a long list of incompatible goods, and several lists of goods to be shipped. You are supposed to tell if all the goods in a list can be packed into the same container.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers: N (≤10^4), the number of pairs of incompatible goods, and M (≤100), the number of lists of goods to be shipped.
////
//// Then two blocks follow. The first block contains N pairs of incompatible goods, each pair occupies a line; and the second one contains M lists of goods to be shipped, each list occupies a line in the following format:
////
//// K G[1] G[2] ... G[K]
////
//// where K (≤1,000) is the number of goods and G[i]'s are the IDs of the goods. To make it simple, each good is represented by a 5-digit ID number. All the numbers in a line are separated by spaces.
////
//// Output Specification:
//// For each shipping list, print in a line Yes if there are no incompatible goods in the list, or No if not.
//
//// Sample Input:
//// 6 3
//// 20001 20002
//// 20003 20004
//// 20005 20006
//// 20003 20001
//// 20005 20004
//// 20004 20006
//// 4 00001 20004 00002 20003
//// 5 98823 20002 20003 20006 10010
//// 3 12345 67890 23333
//
//// Sample Output:
//// No
//// Yes
//// Yes
//
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//
//using namespace std;
//
//int incom,query;
//
//unordered_map<int,vector<int>> pairs;unordered_map<int,int> exist;vector<int> goods;
//
//int main() {
//    cin>>incom>>query;
//    for(int i=0,fnode,snode;i<incom;++i) {cin>>fnode>>snode;pairs[fnode].push_back(snode);pairs[snode].push_back(fnode);}
//    for(int i=0,nodes,judge=0;i<query;++i,judge=0) {
//        cin>>nodes;
//        for(int j=0,value;j<nodes;++j) {cin>>value;exist[value]=1;goods.push_back(value);}
//        for(int j=0;j<nodes;++j)
//            for(int k=0;k<pairs[goods[j]].size();++k) if(exist[pairs[goods[j]][k]]) judge=1;
//        cout<<(judge?"No\n":"Yes\n");goods.clear();exist.clear();
//    }
//}
//
////说明：给一个两两不兼容的货物列表，并给定一些货物清单，问你每个清单上面的有没有不兼容的货物。
//
////分析：邻接表中存的是与某一货物不兼容的货物数组。每个清单输入时把货物在hash数组中对应的位置设置为1，然后检查清单上面的每个货物，看与它不兼容的所有货物有没有在hash数组中被设置为1的，若有，则说明清单上出现了两个不兼容的货物，输出No，否则输出Yes。
//
////注意：这题的意思虽然是清单上面的货物必须两两兼容，但不能在输入时对这些货物两两比较，那样时间复杂度会非常高，测试点2、3会超时。
