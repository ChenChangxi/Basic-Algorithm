//// The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
////
//// For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
////
//// Input Specification:
//// Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.
////
//// Output Specification:
//// For each test case, print the total time on a single line.
//
//// Sample Input:
//// 3 2 3 1
//
//// Sample Output:
//// 41
//
//#include <iostream>
//
//using namespace std;
//
//int nodes,times,temp;
//
//int main() {
//    cin>>nodes;
//    for(int i=0,value;i<nodes;++i) {cin>>value;times+=abs(temp-value)*(temp>value?4:6);temp=value;}
//    cout<<(times+nodes*5);
//}
//
////说明：电梯开始在0层，上一层需要6s，下一层需要4s，在每一层停留5s，现在给出一个楼层序列，电梯按顺序依次停留这些楼层，问你所需要的总时间，最后不用返回0层。
//
////分析：简单的序列遍历，求出相邻两层的间隔，下楼就乘4s，上楼就乘6s，然后做一个累加，最后加上每层楼停留时间后输出即可。
