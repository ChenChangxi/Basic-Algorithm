//// A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
////
//// Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
////
//// Now given a supply chain, you are supposed to tell the total sales from all the retailers.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains three positive numbers: N (≤10(5)), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N−1, and the root supplier's ID is 0); P, the unit price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:
////
//// K(i) ID[1] ID[2] ... ID[K(i)]
////
//// where in the i-th line, K(i)
////​​  is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. K(j)
////​​  being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after K(j). All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 10(10).
//
//// Sample Input:
//// 10 1.80 1.00
//// 3 2 3 5
//// 1 9
//// 1 4
//// 1 7
//// 0 7
//// 2 6 1
//// 1 8
//// 0 9
//// 0 4
//// 0 3
//
//// Sample Output:
//// 42.4
//
//#include <iostream>
//#include <vector>
//#define SIZE 100000
//
//using namespace std;
//
//vector<vector<int>> tree;
//
//int phash[SIZE],nodes,childs,identity;
//
//double price,incre,total;
//
//void dfs(int root,double price) {
//    if(!tree[root].empty()) {
//        for(int i=0;i<tree[root].size();++i) {
//            dfs(tree[root][i],price*(1+incre/100));
//        }
//    } else total+=phash[root]*price;
//}
//
//int main() {
//    cin>>nodes>>price>>incre;
//    tree.resize(nodes);
//    for(int i=0;i<nodes;++i) {
//        cin>>childs;tree[i].resize(childs);
//        for(int j=0;j<childs;++j) cin>>tree[i][j];
//        if(childs==0) cin>>phash[i];
//    }
//    dfs(0,price);
//    printf("%.1f",total);
//}
//
////说明：这算是树的应用问题，关键在于对题目的理解，根结点是供应商，分支结点是经销商，并且商品的价格随着经手的经销商的增多按固定比率在不断增加，叶结点是零售商，给出了每个零售商所有的产品数，问你所有产品一共能卖多少钱。
//
////分析：做一个dfs，price是每一层的产品单价，遇到叶结点从phash拿到产品数，乘以单价，就是这个零售商卖的钱，最后相加即得结果。
//
////注意：r是百分率，也就是r%，要采用双精度来存，最后结果保留到小数点后一位。
