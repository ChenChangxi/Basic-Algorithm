//// A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
////
//// Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
////
//// Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.
////
//// Input Specification:
//// Each input file contains one test case. For each case, The first line contains three positive numbers: N (≤10(5)), the total number of the members in the supply chain (and hence they are numbered from 0 to N−1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number S(i)is the index of the supplier for the i-th member. S(root) for the root supplier is defined to be −1. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 10(10).
//
//// Sample Input:
//// 9 1.80 1.00
//// 1 5 4 4 -1 4 5 3 6
//
//// Sample Output:
//// 1.85 2
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//vector<vector<int>> tree;
//
//int nodes,root,parent,total;
//
//double price,incre,costs;
//
//void dfs(int root,double price) {
//    if(!tree[root].empty()) {
//        for(int i=0;i<tree[root].size();++i) dfs(tree[root][i],price*(1+incre/100));
//    } else {total=costs<price?1:costs==price?total+1:total;costs=max(costs,price);}
//}
//
//int main() {
//    cin>>nodes>>price>>incre;
//    tree.resize(nodes);
//    for(int i=0;i<nodes;++i) {
//        cin>>parent;
//        if(parent==-1) root=i;
//        else tree[parent].push_back(i);
//    }
//    dfs(root,price);
//    printf("%.2f %d",costs,total);
//}
//
////说明：这题和1079题有点像（题意我就不分析了，详细请看1079题），但这道题是让你求单个产品的最大售价。
//
////分析：这道题实质上也就是求树的高度，以及有多少叶结点达到了这个高度，那么每到达一个叶子结点就进行一个判断就可以了，不断迭代更新，最后输出。
//
////注意：这题有一个重点是树的存储结构的，还记得吧，树的三种存储结构，这是双亲存储法，但我们要转化为孩子链表法，因为双亲法不能进行dfs。
