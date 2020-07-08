//// The lowest common ancestor (LCA) of two nodes U and V in a tree is the deepest node that has both U and V as descendants.
////
//// Given any two nodes in a binary tree, you are supposed to find their LCA.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers: M (≤ 1,000), the number of pairs of nodes to be tested; and N (≤ 10,000), the number of keys in the binary tree, respectively. In each of the following two lines, N distinct integers are given as the inorder and preorder traversal sequences of the binary tree, respectively. It is guaranteed that the binary tree can be uniquely determined by the input sequences. Then M lines follow, each contains a pair of integer keys U and V. All the keys are in the range of int.
////
//// Output Specification:
//// For each given pair of U and V, print in a line LCA of U and V is A. if the LCA is found and A is the key. But if A is one of U and V, print X is an ancestor of Y. where X is A and Y is the other node. If U or V is not found in the binary tree, print in a line ERROR: U is not found. or ERROR: V is not found. or ERROR: U and V are not found..
//
//// Sample Input:
//// 6 8
//// 7 2 3 4 6 5 1 8
//// 5 3 7 2 6 4 8 1
//// 2 6
//// 8 1
//// 7 9
//// 12 -3
//// 0 8
//// 99 99
//
//// Sample Output:
//// LCA of 2 and 6 is 3.
//// 8 is an ancestor of 1.
//// ERROR: 9 is not found.
//// ERROR: 12 and -3 are not found.
//// ERROR: 0 is not found.
//// ERROR: 99 and 99 are not found.
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//vector<int> inord,preord;
//
//int query,nodes,root,value,inf,ins;
//
//unordered_map<int,int> ihash;unordered_map<int,bool> exist;
//
//bool dfs(int preLeft,int inLeft,int inRight,int &inf,int &ins) {
//    if(inLeft<=inRight) {
//        int inpos=ihash[preord[preLeft]],lflag,rflag;  //降低运行时间
//        lflag=dfs(preLeft+1,inLeft,inpos-1,inf,ins);  //在左子树“查到了”两个或其中一个节点
//        rflag=dfs(preLeft+inpos-inLeft+1,inpos+1,inRight,inf,ins);
//        root=(lflag&&rflag)||((lflag||rflag)&&(inord[inpos]==inf||inord[inpos]==ins))?inord[inpos]:root;
//        return inord[inpos]==inf||inord[inpos]==ins||lflag||rflag?true:false;
//    } else return false;
//}
//
//int main() {
//    cin>>query>>nodes;
//    for(int i=0;i<nodes;++i) {scanf("%d",&value);inord.push_back(value);ihash[value]=i;}
//    for(int j=0;j<nodes;++j) {scanf("%d",&value);preord.push_back(value);exist[value]=true;}
//    for(int i=0;i<query;++i) {
//        scanf("%d %d",&inf,&ins);
//        if(!exist[inf]||!exist[ins])
//            cout<<"ERROR: "<<(exist[inf]?to_string(ins)+" is":exist[ins]?to_string(inf)+" is":to_string(inf)+" and "+to_string(ins)+" are")<<" not found.\n";
//        else {dfs(0,0,nodes-1,inf,ins);root!=inf&&root!=ins?printf("LCA of %d and %d is %d.\n",inf,ins,root):printf("%d is an ancestor of %d.\n",root==inf?inf:ins,root!=inf?inf:ins);}
//    }
//}
//
////说明：给你一棵二叉树的先序和中序序列，并给若干查询条件，让你求出每一个查询条件的两个节点的“最低公共祖先”。
//
////分析：很明显，二叉树的任意两个节点的位置关系有两种，第一种是两个节点在“同一条”从根结点到叶结点的路径中，第二种是两个节点在“不同”的从根结点到叶结点的路径中（也就是某条路径“分叉”了，最低公共祖先就是所谓的分叉点）。那么假如它们有最低公共祖先a，那么这两个节点一定分别在以a为根结点的树的左右子树中，或者其中一个节点是另一个节点的“最低公共祖先”（用反证法，假如在上面，不是“最低”，假如在下面，不是“公共祖先”），理解了这个，你就能理解我上面略为飘逸的写法（这里面对逻辑的要求很高，大家可以不像我那样写）。
//
////注意：1、这题需要降低运行时间，我用了scanf输入，unordered_map等等，但最有用的还是哈希表，我们以前在做这种题的时候都是遍历inord数组，找根结点的位置，这题我用了个hash数组，来存inord中元素中的位置，这样我根据value直接就能查到下标key，就能极大的降低运行时间。2、本题还要判断所给的两个节点存不存在，这个不能用存中序位置的hash数组来查，因为位置可能是0，这样就会把原来存在的节点判为不存在，必须另设一个hash数组来判断。
