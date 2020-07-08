//// A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
////
//// Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
////
//// Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.
////
//// Input Specification:
//// Each input file contains one test case. For each case, The first line contains three positive numbers: N (≤10^5), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N−1, and the root supplier's ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:
////
//// Ki ID[1] ID[2] ... ID[Ki]
////
//// where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 10^10.
//
//// Sample Input:
//// 10 1.80 1.00
//// 3 2 3 5
//// 1 9
//// 1 4
//// 1 7
//// 0
//// 2 6 1
//// 1 8
//// 0
//// 0
//// 0
//
//// Sample Output:
//// 1.8362 2
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define INF 100000000
//
//using namespace std;
//
//vector<vector<int>> tree;
//
//int nodes,counts,childs,identity;
//
//double price,incre,total=INF;
//
//void dfs(int root,double price) {
//    if(!tree[root].empty()) {
//        for(int i=0;i<tree[root].size();++i) dfs(tree[root][i],price*(1+incre/100));
//    } else {counts=price<total?1:price==total?counts+1:counts;total=min(price,total);}
//}
//
//int main() {
//    cin>>nodes>>price>>incre;
//    tree.resize(nodes);
//    for(int i=0;i<nodes;++i) {
//        cin>>childs;tree[i].resize(childs);
//        for(int j=0;j<childs;++j) cin>>tree[i][j];
//    }
//    dfs(0,price);
//    printf("%.4f %d",total,counts);
//}
//
////说明：这题和1090题一摸一样，但这题让你求产品的最低单价的，我就不分析了，详见第1090题。
