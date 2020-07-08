//// John got a full mark on PAT. He was so happy that he decided to hold a raffle（抽奖） for his followers on Weibo -- that is, he would select winners from every N followers who forwarded his post, and give away gifts. Now you are supposed to help him generate the list of winners.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives three positive integers M (≤ 1000), N and S, being the total number of forwards, the skip number of winners, and the index of the first winner (the indices start from 1). Then M lines follow, each gives the nickname (a nonempty string of no more than 20 characters, with no white space or return) of a follower who has forwarded John's post.
////
//// Note: it is possible that someone would forward more than once, but no one can win more than once. Hence if the current candidate of a winner has won before, we must skip him/her and consider the next one.
////
//// Output Specification:
//// For each case, print the list of winners in the same order as in the input, each nickname occupies a line. If there is no winner yet, print Keep going... instead.
//
//// Sample Input 1:
//// 9 3 2
//// Imgonnawin!
//// PickMe
//// PickMeMeMeee
//// LookHere
//// Imgonnawin!
//// TryAgainAgain
//// TryAgainAgain
//// Imgonnawin!
//// TryAgainAgain
//
//// Sample Output 1:
//// PickMe
//// Imgonnawin!
//// TryAgainAgain
//
//// Sample Input 2:
//// 2 3 5
//// Imgonnawin!
//// PickMe
//
//// Sample Output 2:
//// Keep going...
//
//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int nodes,skip,start;
//
//string value;unordered_map<string,int> exist;
//
//int main() {
//    cin>>nodes>>skip>>start;
//    if(start>nodes) {cout<<"Keep going...\n";return 0;}
//    for(int i=1;i<=nodes;++i)
//       {cin>>value;if(!((i-start)%skip)&&i>=start) {if(!exist[value]) {cout<<value+"\n";exist[value]=1;} else start++;}}
//}
//
////说明：某人发了一条微博，有很多人转发，每个人可能转发不止一次。现在要按转发序列进行一个抽奖，规则就是选定一个人s作为开始，以给定的间隔k往下抽。如果当前这个人m已经抽过，那么就跳过m，取m后面第一个没有抽过奖的人n，然后从n开始以k为间隔继续往下抽，依次类推。假如开始位置s大于抽奖序列的长度，没有人会被抽到，输出Keep going...。
//
////分析：我们需要判断序列中每个人的（m-s）%k是否为0，为0即符合抽奖条件。接着用一个hash数组来标记某个人m是否抽过奖，如果抽过奖就继续判断下一个人，同时让开始位置s增1，直到遇到一个没有抽过奖的人n输出，然后继续上述过程。（因为此时n的“相对”起始位置已经改变，不再是原来的s，如果我们想用（n-s）%k来继续判断，就在需要在找n时不断对s增1。）
//
////注意：因为m是从1开始的，这时当m-s为负数时也可能满足为k的整数倍，但此时m是在s的前面，不应该抽奖，因此一定要保证m>=s。
