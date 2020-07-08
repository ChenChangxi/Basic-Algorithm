//// One important factor to identify acute stroke (急性脑卒中) is the volume of the stroke core. Given the results of image analysis in which the core regions are identified in each MRI slice, your job is to calculate the volume of the stroke core.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 4 positive integers: M, N, L and T, where M and N are the sizes of each slice (i.e. pixels of a slice are in an M×N matrix, and the maximum resolution is 1286 by 128); L (≤60) is the number of slices of a brain; and T is the integer threshold (i.e. if the volume of a connected core is less than T, then that core must not be counted).
////
//// Then L slices are given. Each slice is represented by an M×N matrix of 0's and 1's, where 1 represents a pixel of stroke, and 0 means normal. Since the thickness of a slice is a constant, we only have to count the number of 1's to obtain the volume. However, there might be several separated core regions in a brain, and only those with their volumes no less than T are counted. Two pixels are connected and hence belong to the same region if they share a common side, as shown by Figure 1 where all the 6 red pixels are connected to the blue one.
////
////                                  figstroke.jpg
////
////                                    Figure 1
////
//// Output Specification:
//// For each case, output in a line the total volume of the stroke core.
//
//// Sample Input:
//// 3 4 5 2
//// 1 1 1 1
//// 1 1 1 1
//// 1 1 1 1
//// 0 0 1 1
//// 0 0 1 1
//// 0 0 1 1
//// 1 0 1 1
//// 0 1 0 0
//// 0 0 0 0
//// 1 0 1 1
//// 0 0 0 0
//// 0 0 0 0
//// 0 0 0 1
//// 0 0 0 1
//// 1 0 0 0
//
//// Sample Output:
//// 26
//
//#include <iostream>
//#include <queue>
//#define X 1300
//#define Y 130
//#define Z 130
//
//using namespace std;
//
//struct node {
//    int x,y,z;
//};
//
//queue<node> stack;
//
//int length,weight,height,thres,total,result,visit[X][Y][Z],graph[X][Y][Z],x[6]={1,-1,0,0,0,0},y[6]={0,0,1,-1,0,0},z[6]={0,0,0,0,1,-1};
//
//bool legal(node dot)
//     {return graph[dot.x][dot.y][dot.z]&&!visit[dot.x][dot.y][dot.z]&&dot.x>=0&&dot.y>=0&&dot.z>=0&&dot.x<length&&dot.y<weight&&dot.z<height?1:0;}
//
//void bfs(node dot) {
//    if(legal(dot)) {stack.push(dot);visit[dot.x][dot.y][dot.z]=1;}
//    while(!stack.empty()) {
//        node now=stack.front();stack.pop();++total;
//        for(int i=0;i<6;++i) {
//            node nea={now.x+x[i],now.y+y[i],now.z+z[i]};
//            if(legal(nea)) {visit[nea.x][nea.y][nea.z]=1;stack.push(nea);}
//        }
//    }
//}
//
//int main() {
//    cin>>length>>weight>>height>>thres;
//    for(int i=0;i<height;++i)
//        for(int j=0;j<length;++j)
//            for(int k=0;k<weight;++k) cin>>graph[j][k][i];
//    for(int i=0;i<length;++i)
//        for(int j=0;j<weight;++j)
//            for(int k=0;k<height;++k) {bfs(node{i,j,k});if(total>=thres) result+=total;total=0;}
//    cout<<result;
//}
//
////说明：给一张大脑的三维立体坐标图，某个点为1表示这一点有病变，为0表示健康。一个点的“上”，“下”，“左”，“右”，“前”，“后”的点叫做这个点的相邻点。假如某个点有病变，它的相邻点也有病变，那么我们说这两个点在一个“区域”。当一个区域中的病变点的个数超过阀值，我们就称这个区域为一个肿瘤，现在让你求所有肿瘤中的病变点的个数总和。
//
////分析：这里就涉及到了dfs和bfs的另一个重要区别了（第一个见1076题），那就是dfs在遍历中是不会“退栈”的，它是一个递归的过程，每处理一个节点，这个节点压入堆栈中去，继续进行下一层递归。而bfs不同，在bfs中，每处理一个节点，我们都会把它弹出堆栈，然后才去处理下一个节点，这就导致在dfs中我们可能会遇到堆栈寄存器溢出的问题。PAT的OJ上面说的很清楚，段错误是指数组越界或者堆栈溢出，它通常是在递归的时候没写返回条件，而当数据量极大的时候（这题是三维数组，数据量可以视为很大），也会出现堆栈溢出的问题。这题就是一个很好的例子，用dfs去写的话有两个测试点有段错误，因此对于数据量极大的题目，我们需要考虑用bfs。
//
////注意：1、注意这题给的可不是邻接矩阵，而是一个三维立体坐标图，所以在bfs的时候对“相邻”的判定方法和邻接矩阵不同。某个值为1的点A坐标为（x，y，z），假如B坐标为（x+-1，y+-1，z+-1）且B的值也为1，并且B的每个坐标不超过给定边界，我们就说点A和点B相邻。2、因为bfs要频繁的进行push操作，所以我把每一个点的坐标抽象成了一个结构体。在求当前点A相邻点的时候和其他的题不同，邻接表直接可以查到A相邻结点，邻接矩阵是遍历所有点，找到与A相邻的点，而这题是遍历A的每一个“方向”找到相邻点，我们把六个方向抽象成为六个向量，这六个向量组成了一个向量组，我们遍历向量组中的所有向量，找到与A相邻的那个方向。（这点和邻接矩阵有点像）3、这题在构建图的时候要和题中给的输入方式相对应，假设图形的“行”，“列”，“高”分别为R，C，H。题中首先输入的是“行”，每行有C个点，有因此最内层循要循环C次，接着输入的是一个“切片”，每个切片有R行，第二层要循环R次，最后输入了H个切片，因此最外层要循环H次，这样我们才能正确构建出题中要求的图形。三维数组graph的三个下标哪一个是长，哪一个是宽，哪一个是高可以任意决定，只需要bfs的时候与之对应即可。
