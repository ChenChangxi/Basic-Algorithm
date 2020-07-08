//// Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.
//
//// Sample Input:
//// 5 7 5
//// 1 2 3 4 5 6 7
//// 3 2 1 7 5 6 4
//// 7 6 5 4 3 2 1
//// 5 6 4 3 7 2 1
//// 1 7 6 5 4 3 2
//
//// Sample Output:
//// YES
//// NO
//// NO
//// YES
//// NO
//
//#include <iostream>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//int size,nodes,query;stack<int> pops;
//
//int main() {
//    cin>>size>>nodes>>query;
//    for(int i=0,k=0,seq=0;i<query;++i,k=0,seq=0) {
//        for(int j=0,value;j<nodes;++j)
//           {cin>>value;while(k<value) pops.push(++k);if(pops.top()!=value||pops.size()>size) seq=1;else pops.pop();}
//        cout<<(seq?"NO\n":"YES\n");while(!pops.empty()) pops.pop();
//    }
//}
//
////说明：给一个数N和栈容量S，入栈序列是从1到N的一个顺序序列，现在给你若干序列，让你判断它是不是一个出栈序列。
//
////分析：用一个栈来模拟这个过程，k为已入栈的最大元素，v为出栈序列中的当前元素，假如v比k大，就需要不断入栈，假如v比k小或相等，它必然要等于栈顶元素（思考为什么？），否则这个就不是一个出栈序列，同时在这个过程中，栈的大小不能超过S。
//
////注意：stl中的stack和queue都没有clear方法，所以必须手动清空。
