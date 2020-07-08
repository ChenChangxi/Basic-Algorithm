//// Given a syntax tree (binary), you are supposed to output the corresponding infix expression, with parentheses reflecting the precedences of the operators.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20) which is the total number of nodes in the syntax tree. Then N lines follow, each gives the information of a node (the i-th line corresponds to the i-th node) in the format:
////
//// data left_child right_child
////
//// where data is a string of no more than 10 characters, left_child and right_child are the indices of this node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by −1. The figures 1 and 2 correspond to the samples 1 and 2, respectively.
////
////                             infix1.JPG    infix2.JPG
////                              Figure 1    Figure 2
////
//// Output Specification:
//// For each case, print in a line the infix expression, with parentheses reflecting the precedences of the operators. Note that there must be no extra parentheses for the final expression, as is shown by the samples. There must be no space between any symbols.
//
//// Sample Input 1:
//// 8
//// * 8 7
//// a -1 -1
//// * 4 1
//// + 2 5
//// b -1 -1
//// d -1 -1
//// - -1 6
//// c -1 -1
//
//// Sample Output 1:
//// (a+b)*(c*(-d))
//
//// Sample Input 2:
//// 8
//// 2.35 -1 -1
//// * 6 1
//// - -1 4
//// % 7 8
//// + 2 3
//// a -1 -1
//// str -1 -1
//// 871 -1 -1
//
//// Sample Output 2:
//// (a*2.35)+(-(str%871))
//
//#include <iostream>
//#include <string>
//#include <vector>
//#define SIZE 10000
//
//using namespace std;
//
//struct node {
//    string data;
//    int left,right;
//};
//
//vector<node> tree;
//
//string express,result;
//
//int nodes,lefts,rights,troot,rhash[SIZE];
//
//string dfs(int root) {
//    return tree[root].right!=-1?"("+(tree[root].left!=-1?dfs(tree[root].left):"")+tree[root].data+dfs(tree[root].right)+")":tree[root].data;
//}
//
//int main() {
//    cin>>nodes;tree.push_back(node{"",0,0});
//    for(int i=0;i<nodes;++i) {
//        cin>>express>>lefts>>rights;
//        tree.push_back(node{express,lefts,rights});
//        if(lefts!=-1) rhash[lefts]=1;if(rights!=-1) rhash[rights]=1;
//    }
//    while(rhash[++troot]);
//    cout<<(dfs(troot).length()!=1?dfs(troot).substr(1,dfs(troot).length()-2):dfs(troot));
//}
//
////说明：让你求一棵语法树的中缀表达式（也就是中序遍历）。
//
////分析：注意分析语法树的特征，一个节点只有三种情况，叶结点，有左右孩子的分支和只有右孩子的分支，不存在只有左孩子的分支（也就是说存在-a，但不存在a-），后两种情况前面需要加括号，理解了这些原理你就能明白我上面略为风骚的写法。
//
////注意：题目中明确告诉你最终的中缀表达式没有多余的括号，所以要去掉最外面的括号，但假如只有一个节点的话，根据dfs它最后的中缀表达式不含括号，因此不用去掉（只有这一种情况不需要去掉多余的括号，思考为什么？）
