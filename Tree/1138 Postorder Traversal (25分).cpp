//// Suppose that all the keys in a binary tree are distinct positive integers. Given the preorder and inorder traversal sequences, you are supposed to output the first number of the postorder traversal sequence of the corresponding binary tree.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 50,000), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print in one line the first number of the postorder traversal sequence of the corresponding binary tree.
//
//// Sample Input:
//// 7
//// 1 2 3 4 5 6 7
//// 2 3 1 5 4 7 6
//
//// Sample Output:
//// 3
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<int> preord,inord,posord;
//
//int nodes,value;
//
//void dfs(int inLeft,int preLeft,int preRight) {
//    if(preLeft<=preRight) {
//        int inpos=inLeft;while(preord[preLeft]!=inord[inpos]) ++inpos;
//        dfs(inLeft,preLeft+1,preLeft+inpos-inLeft);
//        dfs(inpos+1,preLeft+inpos-inLeft+1,preRight);
//        posord.push_back(preord[preLeft]);
//    }
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {cin>>value;preord.push_back(value);}
//    for(int i=0;i<nodes;++i) {cin>>value;inord.push_back(value);}
//    dfs(0,0,nodes-1);
//    cout<<posord[0];
//}
//
////说明：这题我就不分析了，算是很简单的，可以看1020，1086，1119和1127题。1020和1086我用的是中序为主的写法，由先序后序序列定根，然后在中序中分左右，1127和本题我用的是先序或后序为主的写法，中序定左子树长度，在先序后序中定左右子树，但他们要和1119题区分开，1119题找的是左孩子，然后判断，其他这些题找的都是这棵树的根结点然后判断。
