//// An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.
////
//// Figure 1
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.
////
//// Output Specification:
//// For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.
//
//// Sample Input:
//// 6
//// Push 1
//// Push 2
//// Push 3
//// Pop
//// Pop
//// Push 4
//// Pop
//// Pop
//// Push 5
//// Push 6
//// Pop
//// Pop
//
//// Sample Output:
//// 3 4 2 6 5 1
//
//#include <iostream>
//#include <string>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//vector<int> inorder,preorder;
//
//stack<int> work;
//
//string input,value;
//
//int nodes,counts;
//
//void dfs(int preRoot,int inLeft,int inRight) {
//    if(inLeft<=inRight) {
//        int inpos=inLeft;
//        while(inorder[inpos]!=preorder[preRoot]) ++inpos;
//        dfs(preRoot+1,inLeft,inpos-1);
//        dfs(preRoot+inpos-inLeft+1,inpos+1,inRight);
//        cout<<preorder[preRoot]<<(--counts==0?"":" ");
//    }
//}
//
//int main() {
//    cin>>nodes;
//    while(counts<nodes) {
//        cin>>input;
//        if(input.size()==3) {inorder.push_back(work.top());work.pop();++counts;}
//        else {cin>>value;preorder.push_back(stoi(value));work.push(stoi(value));}
//    }
//    dfs(0,0,nodes-1);
//}
//
////说明：给一个入栈和出栈顺序，让你求一棵二叉树。
//
////分析：首先我们知道，入栈顺序是这棵二叉树的先序序列，出栈顺序是这棵二叉树的中序序列，由二叉树的先序序列和中序序列就能够唯一的确定一棵二叉树。先序序列定根值，然后在中序序列中找到根值，根左边就是左子树，根右边就是右子树，递归即可，这题相当于是我用先序序列和中序序列做了一个二叉树的后序遍历，直接就能输出结果。（思考为什么？）
//
////注意：这题涉及到字符串处理，这个要注意一下，还有输入何时结束的问题，这个在我第一次刷的时候用了个比较笨的方法，其实直接数pop的个数就可以了，pop等于nodes即为结束。
