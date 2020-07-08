//// The basic task is simple: given N real numbers, you are supposed to calculate their average. But what makes it complicated is that some of the input numbers might not be legal. A legal input is a real number in [−1000,1000] and is accurate up to no more than 2 decimal places. When you calculate the average, those illegal numbers must not be counted in.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤100). Then N numbers are given in the next line, separated by one space.
////
//// Output Specification:
//// For each illegal input number, print in a line ERROR: X is not a legal number where X is the input. Then finally print in a line the result: The average of K numbers is Y where K is the number of legal inputs and Y is their average, accurate to 2 decimal places. In case the average cannot be calculated, output Undefined instead of Y. In case K is only 1, output The average of 1 number is Y instead.
//
//// Sample Input 1:
//// 7
//// 5 -3.2 aaa 9999 2.3.4 7.123 2.35
//
//// Sample Output 1:
//// ERROR: aaa is not a legal number
//// ERROR: 9999 is not a legal number
//// ERROR: 2.3.4 is not a legal number
//// ERROR: 7.123 is not a legal number
//// The average of 3 numbers is 1.38
//
//// Sample Input 2:
//// 2
//// aaa -9999
//
//// Sample Output 2:
//// ERROR: aaa is not a legal number
//// ERROR: -9999 is not a legal number
//// The average of 0 numbers is Undefined
//
//#include <iostream>
//#include <cmath>
//#include <string>
//
//using namespace std;
//
//int nodes,counts;string numb;double total;
//
//int main() {
//    cin>>nodes;
//    for(int i=0,nots=0,legal=0;i<nodes;++i,nots=0,legal=0) {
//        cin>>numb;
//        for(int j=0;j<numb.size();++j) {
//            if(numb[j]=='.') ++nots;
//            if((numb[j]>='0'&&numb[j]<='9')||(nots==1&&numb[j]=='.'&&numb.size()-j-1<=2)||(numb[j]=='-'&&!j)) continue;legal=1;
//        }
//        if(legal||stod(numb)>1000||stod(numb)<-1000) cout<<"ERROR: "+numb+" is not a legal number\n";else {++counts;total+=stod(numb);}
//    }
//    printf("The average of %d number%s is ",counts,counts==1?"":"s");!counts?printf("Undefined\n"):printf("%.2f\n",total/counts);
//}
//
//
////说明：给出若干数字求平均值，这个数字必须是合法的，即必须是-1000到1000的整数或者小数部分不超过两位的或小数。
//
////分析：关键在于判断给定串是不是一个合法数字，首先对于输入串的每一位只有三种情况，1、1到9之间的字符；2、减号字符，并且只能出现在第一个；3、小数点字符，只能出现一次，并且小数部分必须不大于两位。如果满足以上情况，对于整个串来说，还一定要是在-1000到1000这个范围内，只有满足以上全部这些条件，我们才能判断它是一个合法的数字。
//
////注意：假如只有一个数字，要输出number，如果0个或者超过1个，则输出numbers。
