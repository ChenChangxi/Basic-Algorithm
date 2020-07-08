//// Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 2 positive integers: N (≤1000), the number of users; and L (≤6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:
////
//// M[i] user_list[i]
////
//// where M[i] (≤100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.
////
//// Then finally a positive K is given, followed by K UserID's for query.
////
//// Output Specification:
//// For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can trigger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.
//
//// Sample Input:
//// 7 3
//// 3 2 3 4
//// 0
//// 2 5 6
//// 2 3 1
//// 2 3 4
//// 1 4
//// 1 5
//// 2 2 6
//
//// Sample Output:
//// 4
//// 5
//
//#include <iostream>
//#include <vector>
//#define SIZE 10000
//
//using namespace std;
//
//vector<vector<int>> graph;
//
//int nodes,mlevel,query,total,levels[SIZE],visit[SIZE];
//
//void dfs(int root,int level) {
//    if((!visit[root]||level<levels[root])&&level<=mlevel) {
//        visit[root]=1;levels[root]=level;
//        for(int i=0;i<graph[root].size();++i) dfs(graph[root][i],level+1);
//    }
//}
//
//int main() {
//    cin>>nodes>>mlevel;graph.resize(nodes+1);
//    for(int i=1,value;i<=nodes;++i) {
//        scanf("%d",&value);
//        for(int j=0,next=0;j<value;++j){scanf("%d",&next);graph[next].push_back(i);}}
//    cin>>query;
//    for(int i=0,value;i<query;++i) {
//        fill(levels,levels+SIZE,SIZE);scanf("%d",&value);dfs(value,0);
//        for(int i=1;i<=nodes;++i)total=levels[i]<=mlevel?total+1:total;
//        printf("%d\n",total-1);total=0;fill(visit,visit+SIZE,0);
//    }
//}
//
////说明：给一个社交网络的有向图，顶点代表人，有向边表示关注与被关注，假如一个人发了一条微博，所有关注他的人都会转发，但最多只能转发一定的层数，问你给定层数的情况下最多可能有多少人会转发这条微博？
//
////分析：以前有很多同学认为dfs和bfs没啥区别，这道题就展现了它们非常重要的一个区别，同时也非常好的说明了树的图的差异。假如是dfs的话，如下图1，1是源点，求三层及以内的所有结点，那么假如按照1-2-3-4这样来遍历的话，4处于第四层的位置，但假如是1-5-4这样来遍历的话，4就处于第三层的位置，而由于4已经被遍历（dfs是不重复遍历所有结点），因此最终的结果只是1、2、3，这样就会出现错误。而这样的错误是如何造成的呢，答案就是回路，如下图2，假如是树的话，那么当我们dfs的时候从根结点到其他每一个节点的路径有只有一条，那么此时我就可以进行一次dfs就能得到所有结点的层数（Tree那里好多题都是这样写的，此时dfs和bfs是等价的），但假如是图的话，从某个顶点a到另一个顶点b的路径会有很多条，那么b相对于a的层数也就不确定了，而bfs就没有这个问题，图1中第一层为1，第二层为2，5，第三层为3，4，这样就是对的。总结一下，图的dfs不能解决层的问题，而bfs却可以（bfs的写法请详见1091题），而这题我为什么我可以用dfs呢？那是因为我修改了遍历的条件，维护了一个level数组，它不再是纯粹意义上的dfs了，假如当前顶点没有visit过或者顶点在当前层数小与level数组中的层数就继续遍历，就避免了上面的那个问题。
//
////注意：题目中给的边是a->b，是一个有向边，表示a关注了b，而我们dfs的时候需要知道关注了b的人有哪些，所以在构建图的邻接表时我们是逆向构建的。
//
////附图：1-2-3-4 (1和5，4和5相邻)           1    （图2）
////      \ 5 /                          / \
////      （图1）                        2---3
