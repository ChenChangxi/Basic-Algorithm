//// A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:
////
//// ·The left subtree of a node contains only nodes with keys less than the node's key.
//// ·The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
//// ·Both the left and right subtrees must also be binary search trees.
////
//// If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.
////
//// Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, first print in a line YES if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or NO if not. Then if the answer is YES, print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.
//
//// Sample Input 1:
//// 7
//// 8 6 5 7 10 8 11
//
//// Sample Output 1:
//// YES
//// 5 7 6 8 11 10 8
//
//// Sample Input 2:
//// 7
//// 8 10 11 8 6 7 5
//
//// Sample Output 2:
//// YES
//// 11 8 10 7 5 6 8
//
//// Sample Input 3:
//// 7
//// 8 6 8 5 10 9 11
//
//// Sample Output 3:
//// NO
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//vector<int> preord,inord,posord;
//
//int nodes,value,judgep,judgem;
//
//void dfs(int preLeft,int inLeft,int inRight,int flag) {
//    if(inLeft<=inRight) {
//        int inpos=flag?inLeft:inRight;
//        while(preord[preLeft]!=inord[inpos]) flag?inpos++:inpos--;
//        dfs(preLeft+1,inLeft,inpos-1,flag);
//        dfs(preLeft+inpos-inLeft+1,inpos+1,inRight,flag);
//        posord.push_back(preord[preLeft]);
//    }
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<nodes;++i) {cin>>value;preord.push_back(value);} inord=preord;
//    for(int i=0,j=i+1,k=i+1;i+2<nodes;++i,j=i+1,k=i+1) {
//        while(j+1<nodes&&(preord[j]<preord[i]||preord[j+1]>=preord[i])) ++j;
//        while(k+1<nodes&&(preord[k]>=preord[i]||preord[k+1]<preord[i])) ++k;
//        if(j==nodes-1) judgep++;if(k==nodes-1) judgem++;
//    }
//    if(judgem!=nodes-2&&judgep!=nodes-2) {cout<<"NO"<<"\n";return 0;} else cout<<"YES"<<"\n";
//    if(judgep==nodes-2) sort(inord.begin(),inord.end());
//    else sort(inord.begin(),inord.end(),greater<int>());
//    dfs(0,0,nodes-1,judgep==nodes-2?1:0);
//    for(int i=0;i<nodes;++i) cout<<posord[i]<<(i==nodes-1?"":" ");
//}
//
////说明：给你一个序列，让你判断它是不是BST的先序序列或者镜像BST的先序序列（注意，不是BST的镜像先序序列，这是有区别的），如果是的话，需要输出BST或者镜像BST的后序序列。
//
////分析：本题的关键之处在于如何判断是不是BST或者镜像BST。假如是BST，顺序遍历先序序列，节点a从左到右找到第一个不大于它的节点b，a到b之间的节点一定是a的左子树比a小（思考为什么？），b后面的节点一定比a大（这个可以用反证法来证明，假如b后面有结点c比a小，那么c一定是a的左子树，又因为c不是a的左子树，因此c一定比a大，证明完毕！！）。假如先序序列中的每一个元素都满足这个条件，那么我们就可以说它是BST的先序遍历序列，镜像BST相似。
//
////注意：本题每个节点的value值可能相同，那么在dfs在中序序列中找当前子树的根结点时，当是BST的时候就应该从小到大，因为BST的中序序列一定是递增的，那么我就可以保证当有相同元素时，我找的根结点是第一个元素，其他的元素都是根结点的右边（相同元素在右子树），符合题中关于BST的定义，这也就是排序中所说的稳定性。镜像BST相似，应该从大到小。
