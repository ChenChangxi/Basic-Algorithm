//// This is a problem given in the Graduate Entrance Exam in 2018: Which of the following is NOT a topological order obtained from the given directed graph? Now you are supposed to write a program to test each of the options.
////
////                                        gre.jpg
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives two positive integers N (≤ 1,000), the number of vertices in the graph, and M (≤ 10,000), the number of directed edges. Then M lines follow, each gives the start and the end vertices of an edge. The vertices are numbered from 1 to N. After the graph, there is another positive integer K (≤ 100). Then K lines of query follow, each gives a permutation of all the vertices. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// Print in a line all the indices of queries which correspond to "NOT a topological order". The indices start from zero. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line. It is graranteed that there is at least one answer.
//
//// Sample Input:
//// 6 8
//// 1 2
//// 1 3
//// 5 2
//// 5 4
//// 2 3
//// 2 6
//// 3 4
//// 6 4
//// 5
//// 1 5 2 3 6 4
//// 5 1 2 6 3 4
//// 5 1 2 3 6 4
//// 5 2 1 6 3 4
//// 1 2 3 4 5 6
//
//// Sample Output:
//// 3 4
//
//#include <iostream>
//#include <vector>
//#include <map>
//#define SIZE 10009
//
//using namespace std;
//
//map<int,vector<int>> inadj,outadj;vector<int> result;
//
//int nodes,edges,query,visit[SIZE];
//
//int main() {
//    cin>>nodes>>edges;
//    for(int i=0,fnode,snode;i<edges;++i) {cin>>fnode>>snode;outadj[fnode].push_back(i);inadj[snode].push_back(i);}
//    cin>>query;
//    for(int i=0,node=0;i<query;++i,node=0) {
//        for(int j=0,value,count=0;j<nodes;++j,count=0) {
//            cin>>value;
//            for(int k=0;k<inadj[value].size();++k) visit[inadj[value][k]]?++count:NULL;
//            for(int k=0;k<outadj[value].size();++k) visit[outadj[value][k]]=1;
//            if(count==inadj[value].size()) ++node;
//        }
//        if(node!=nodes) result.push_back(i);fill(visit,visit+SIZE,0);
//    }
//    for(int i=0;i<result.size();++i) cout<<result[i]<<(i!=result.size()-1?" ":"");
//}
//
////说明：给你一张有向图，并给你所有结点的一个序列，问这个序列是不是所有结点的一个“拓扑排序”。
//
////分析：我们在输入的时候给每一条边一个编号，建一个出度邻接表存以某节点为“起点”的所有边，和一个入度邻接表来存以某节点为“终点”的所有边（这再次说明了数据结构选的要方便解题，不必生搬硬套）。对于所给序列的每一个节点a，我们首先遍历a的出度数组，把其中的边在visit数组中相应的地方置1（删除以a为开始的所有边），并检查a的入度数组中的边在visit数组中是否为1（以a为结束的所有边是否已经被删除，也就是a的入度是否为0）。若序列中的每个点在上述两种操作后入度都为0，则这个序列是一个拓扑序列，否则就不是。
//
////注意：不能在判断某个节点后就立即退出循环，因为后面还有节点的输入，你要是退出之后这个序列接下来的节点会作为一个新序列重新判断（很多25分的题都有这个问题，写的时候注意）。
