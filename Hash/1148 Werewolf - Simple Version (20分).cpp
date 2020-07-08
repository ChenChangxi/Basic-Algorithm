//// Werewolf（狼人杀） is a game in which the players are partitioned into two parties: the werewolves and the human beings. Suppose that in a game,
////
//// ·player #1 said: "Player #2 is a werewolf.";
//// ·player #2 said: "Player #3 is a human.";
//// ·player #3 said: "Player #4 is a werewolf.";
//// ·player #4 said: "Player #5 is a human."; and
//// ·player #5 said: "Player #4 is a human.".
////
//// Given that there were 2 werewolves among them, at least one but not all the werewolves were lying, and there were exactly 2 liars. Can you point out the werewolves?
////
//// Now you are asked to solve a harder version of this problem: given that there were N players, with 2 werewolves among them, at least one but not all the werewolves were lying, and there were exactly 2 liars. You are supposed to point out the werewolves.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (5≤N≤100). Then N lines follow and the i-th line gives the statement of the i-th player (1≤i≤N), which is represented by the index of the player with a positive sign for a human and a negative sign for a werewolf.
////
//// Output Specification:
//// If a solution exists, print in a line in ascending order the indices of the two werewolves. The numbers must be separated by exactly one space with no extra spaces at the beginning or the end of the line. If there are more than one solution, you must output the smallest solution sequence -- that is, for two sequences A=a[1],...,a[M] and B=b[1],...,b[M], if there exists 0≤k<M such that a[i]=b[i] (i≤k) and a[k+1]<b[k+1], then A is said to be smaller than B. In case there is no solution, simply print No Solution.
//
//// Sample Input 1:
//// 5
//// -2
//// +3
//// -4
//// +5
//// +4
//
//// Sample Output 1:
//// 1 4
//
//// Sample Input 2:
//// 6
//// +6
//// +3
//// +1
//// -5
//// -2
//// +4
//
//// Sample Output 2 (the solution is not unique):
//// 1 5
//
//// Sample Input 3:
//// 5
//// -2
//// -3
//// -4
//// -5
//// -1
//
//// Sample Output 3:
//// No Solution
//
//#include <iostream>
//#include <cmath>
//#include <unordered_map>
//#include <vector>
//
//using namespace std;
//
//int nodes;vector<int> says;
//
//int main() {
//    cin>>nodes;says.resize(nodes+1);for(int i=1;i<=nodes;++i) cin>>says[i];
//    for(int i=1;i<=nodes;++i)
//        for(int j=i+1;j<=nodes;++j) {
//            vector<int> wolf(nodes+1,1),liar;wolf[i]=wolf[j]=-1;
//            for(int k=1;k<=nodes;++k) if(says[k]*wolf[abs(says[k])]<0) liar.push_back(k);
//            if(liar.size()==2&&wolf[liar[0]]*wolf[liar[1]]<0) {cout<<i<<" "<<j;return 0;}
//        }
//    cout<<"No Solution";
//}
//
////说明：狼人杀游戏的玩家被分为人和狼人，这些玩家里面只有两个狼人，剩下的都是人，给出每个玩家说的一句关于其他玩家是人还是狼人的一个判断，已知只有一个狼人和一个人在撒谎，问你哪两个人可能是狼人，如果有多种情况，输出最小的那个狼人序列。
//
////分析：首先我们假设这些玩家中的任意两个是狼，然后设一个wolf数组，它用+1和-1记录了一个玩家是人还是狼，然后遍历所有玩家，找出撒谎的人。在判断一个人a是否在撒谎时，只需要判断a说的这个人b在wolf数组中的符号和a说的是否相同，不同即在撒谎。最后判断撒谎的这两个人时，只需要判断这两个人在wolf数组中的符号是否相异，若相异，则说明它们肯定是一狼一人。
//
////注意：最小序列的含义我只在这里说一遍，其他的地方不再重复。最小序列又叫字典序（字典的单词就是按照这个顺序排的），我们假设s和t从左到右第一个不相同的位置为x，s（x）=a，而t（x）=b。s<t的含义就是a<b，或者当x不存在时s为t的同始子序列（串同样）。这题在求所有组合时i和j都是从左到右数的，只要求出满足条件的i和j就是最小序列。
