//// If a machine can save only 3 significant digits, the float numbers 12300 and 12358.9 are considered equal since they are both saved as 0.123×10^5 with simple chopping. Now given the number of significant digits on a machine and two float numbers, you are supposed to tell if they are treated equal in that machine.
////
//// Input Specification:
//// Each input file contains one test case which gives three numbers N, A and B, where N (<100) is the number of significant digits, and A and B are the two float numbers to be compared. Each float number is non-negative, no greater than 10^100, and that its total digit number is less than 100.
////
//// Output Specification:
//// For each test case, print in a line YES if the two numbers are treated equal, and then the number in the standard form 0.d[1]...d[N]*10^k (d[1]>0 unless the number is 0); or NO if they are not treated equal, and then the two numbers in their standard form. All the terms must be separated by a space, with no extra space at the end of a line.
////
//// Note: Simple chopping is assumed without rounding.
//
//// Sample Input 1:
//// 3 12300 12358.9
//
//// Sample Output 1:
//// YES 0.123*10^5
//
//// Sample Input 2:
//// 3 120 128
//
//// Sample Output 2:
//// NO 0.120*10^3 0.128*10^3
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int save;string fnum,snum,mant;
//
//string getmach(string real) {
//    int dots=(int)real.find('.'),fnzo=0;if(dots!=-1) real.erase(dots,1);while(real[fnzo]=='0'&&fnzo<real.size()) ++fnzo;
//    mant=real.size()-fnzo>=save?real.substr(fnzo,save):real.substr(fnzo)+string(save-real.size()+fnzo,'0');
//    return "0."+mant+"*10^"+to_string(mant[0]-'0'?dots!=-1?dots-fnzo:(int)real.size()-fnzo:0);
//}
//
//int main() {
//    cin>>save>>fnum>>snum;
//    cout<<(getmach(fnum)==getmach(snum)?"YES "+getmach(fnum):"NO "+getmach(fnum)+" "+getmach(snum));
//}
//
////说明：给你两个浮点数的真值，让你求它们规格化后的机器码，包括尾数和阶码（题中给出了尾数小数点后需要保留x位有效数字），最后比较这两个数机器码的大小。
//
////分析：关键问题在于求小数点的位置a，以及从左到右第一个非0数的位置b。尾数是以b为始，长度为x的子串，长度不够要补0。阶码是a-b。（为了使正负阶码都可用上式表示，所以在题中先去掉小数点然后再求b。如123·4的阶码按上式是3-0=3，但0·001234的阶码去掉小数点前按上式为1-4=-3不对，去掉后b就变为3，阶码变为1-3=-2就对了。小数点去掉后并不影响求尾数。）
//
////注意：1、这题要注意对0做特殊处理，如0000·0就不能写成0·000*10^3，而要写成0·000*10^0，所以求阶码的时候要判断一下尾数是否为0。2、这里出现了匿名类。想创建一个有连续重复字符的字符串，有以下两种写法，后者便是匿名类，它通常是我们要创建一个临时对象时使用。有很多题我直接使用node创建结构体，那就是匿名类，我只在这里说一次，后面不再说。3、find函数用来查找某个字符在串中出现的位置，参数1为开始查找的位置，参数2为要查找的字符，没有参数1默认从开始位置查找，返回值为字符在串中第一次出现的位置，如果没有查到则返回-1，这题给出的数可能没有小数点，所以出现-1要进行额外的处理。
//
////写法：写法1 string a(m,n)；写法2 string(m,n)。其中m是重复次数，n是重复字符。
