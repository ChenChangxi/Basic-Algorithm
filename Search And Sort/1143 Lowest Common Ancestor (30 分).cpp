//// The lowest common ancestor (LCA) of two nodes U and V in a tree is the deepest node that has both U and V as descendants.
////
//// A binary search tree (BST) is recursively defined as a binary tree which has the following properties:
////
//// ·The left subtree of a node contains only nodes with keys less than the node's key.
//// ·The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//// ·Both the left and right subtrees must also be binary search trees.
////
//// Given any two nodes in a BST, you are supposed to find their LCA.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers: M (≤ 1,000), the number of pairs of nodes to be tested; and N (≤ 10,000), the number of keys in the BST, respectively. In the second line, N distinct integers are given as the preorder traversal sequence of the BST. Then M lines follow, each contains a pair of integer keys U and V. All the keys are in the range of int.
////
//// Output Specification:
//// For each given pair of U and V, print in a line LCA of U and V is A. if the LCA is found and A is the key. But if A is one of U and V, print X is an ancestor of Y. where X is A and Y is the other node. If U or V is not found in the BST, print in a line ERROR: U is not found. or ERROR: V is not found. or ERROR: U and V are not found..
//
//// Sample Input:
//// 6 8
//// 6 3 1 2 5 4 8 7
//// 2 5
//// 8 7
//// 1 9
//// 12 -3
//// 0 8
//// 99 99
//
//// Sample Output:
//// LCA of 2 and 5 is 3.
//// 8 is an ancestor of 7.
//// ERROR: 9 is not found.
//// ERROR: 12 and -3 are not found.
//// ERROR: 0 is not found.
//// ERROR: 99 and 99 are not found.
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <unordered_map>
//
//using namespace std;
//
//vector<int> preord;unordered_map<int,int> phash,ihash,exist;
//
//int nodes,query,inf,ins,value,mindex;
//
//int main() {
//    cin>>query>>nodes;
//    for(int i=0;i<nodes;++i) {scanf("%d",&value);preord.push_back(value);phash[value]=i;exist[value]=1;}
//    for(int i=0;i<query;++i) {
//        scanf("%d %d",&inf,&ins);
//        if(!exist[inf]||!exist[ins])
//            cout<<"ERROR: "<<(exist[inf]?to_string(ins)+" is ":exist[ins]?to_string(inf)+" is ":to_string(inf)+" and "+to_string(ins)+" are ")<<"not found.\n";
//        else {
//            for(int j=0;j<=nodes;++j) if(preord[j]>=min(inf,ins)&&preord[j]<=max(inf,ins)) {mindex=j;break;}
//            inf!=preord[mindex]&&ins!=preord[mindex]?printf("LCA of %d and %d is %d.\n",inf,ins,preord[mindex]):printf("%d is an ancestor of %d.\n",preord[mindex]==inf?inf:ins,preord[mindex]!=inf?inf:ins);
//        }
//    }
//}
//
////说明：给一棵BST，并给若干查询条件，让你求每个查询条件中两个节点的“最低公共祖先”。
//
////分析：关于最低公共节点问题的分析，我在1151题中说的已经很详细了，这里不细说。但要注意这棵树是BST，根据BST的定义，它们的“最低公共祖先a“的值一定是在这两个节点b和c之间的（a，b，c在以a为根结点的树中）
//
////注意：
//
