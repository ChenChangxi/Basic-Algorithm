//// Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.
//
//// Sample Input:
//// 7
//// 2 3 1 5 7 6 4
//// 1 2 3 4 5 6 7
//
//// Sample Output:
//// 4 1 6 3 5 7 2
//
//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//vector<int> posord,inord;
//
//map<int,vector<int>> levord;
//
//int nodes,value,counts;
//
//void dfs(int posRoot,int inLeft,int inRight,int level) {
//    if(inLeft<=inRight) {
//        levord[level].push_back(posord[posRoot]);
//        int inpos=inRight;
//        while(posord[posRoot]!=inord[inpos]) --inpos;
//        dfs(posRoot-(inRight-inpos+1),inLeft,inpos-1,level+1);   //左子树
//        dfs(posRoot-1,inpos+1,inRight,level+1);  //右子树
//    }
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {cin>>value;posord.push_back(value);}
//    for(int i=0;i<nodes;++i) {cin>>value;inord.push_back(value);}
//    dfs(nodes-1,0,nodes-1,0);
//    for(auto it=levord.begin();it!=levord.end();++it) {
//        for(int i=0;i<it->second.size();++i,++counts) {
//            cout<<it->second[i]<<(counts==nodes-1?"":" ");
//        }
//    }
//}
//
////说明：我们知道根据后序和中序序列能够唯一确定一颗二叉树，这道题让你求出这棵二叉树的层序序列，属于常规题。
//
////分析：首先后序序列最后一个结点就是整个树的根结点，因此我们用后序序列来定根结点的值。接着我们求根结点在中序序列中的位置，根结点左边即为左子树，根结点右边即为右子树，递归可得结果。这里在递归的过程中我用了一个map来存储每一层有哪些结点，最后输出map即为层序遍历序列。
//
////注意：1、注意边界条件是inLeft<=inRight。2、一定记住在递归的时候尽量少用全局变量，否则一些非常隐蔽的变量值的改变在debug的时候不容易被发现。
