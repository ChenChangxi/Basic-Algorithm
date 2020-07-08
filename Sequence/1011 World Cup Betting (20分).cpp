//// With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.
////
//// Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.
////
//// For example, 3 games' odds are given as the following:
////
////  W    T    L
//// 1.1  2.5  1.7
//// 1.2  3.1  1.6
//// 4.1  1.2  1.1
////
//// To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1×3.1×2.5×65%−1)×2=39.31 yuans (accurate up to 2 decimal places).
////
//// Input Specification:
//// Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.
////
//// Output Specification:
//// For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.
//
//// Sample Input:
//// 1.1 2.5 1.7
//// 1.2 3.1 1.6
//// 4.1 1.2 1.1
//
//// Sample Output:
//// T T W 39.31
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//double bets[3],buys[3],value,total=1;string type[3]={"W","T","L"};
//
//int main() {
//    for(int i=0;i<3;++i)
//        for(int j=0;j<3;++j) {cin>>value;if(value>bets[i]) {bets[i]=value;buys[i]=j;}}
//    for(int i=0;i<3;++i)
//       {total*=bets[i];cout<<type[(int)buys[i]]<<" ";} printf("%.2f",(total*0.65-1)*2);
//}
//
////说明：世界杯上有三场比赛，每场比赛有胜平负三种结果，每种结果一个赔率，现在我们要买每场比赛最高赔率的那个结果，问你每场比赛买的哪个结果，并按(赔率之积×65%−1)×2求出最大收益。
//
////分析：bets数组保存每场比赛最高赔率，buys数组保存每场比赛买的结果，最后遍历这两个数组分别统计收益和输出结果，最后输出最大收益即可。
