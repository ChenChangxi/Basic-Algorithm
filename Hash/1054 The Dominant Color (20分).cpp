//// Behind the scenes in the computer's memory, color is always talked about as a series of 24 bits of information for each pixel. In an image, the color with the largest proportional area is called the dominant color. A strictly dominant color takes more than half of the total area. Now given an image of resolution M by N (for example, 800×600), you are supposed to point out the strictly dominant color.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 2 positive numbers: M (≤800) and N (≤600) which are the resolutions of the image. Then N lines follow, each contains M digital colors in the range [0,2^24). It is guaranteed that the strictly dominant color exists for each input image. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, simply print the dominant color in a line.
//
//// Sample Input:
//// 5 3
//// 0 0 255 16777215 24
//// 24 24 0 0 24
//// 24 0 24 24 24
//
//// Sample Output:
//// 24
//
//#include <iostream>
//#include <string>
//#include <unordered_map>
//
//using namespace std;
//
//int length,weight;
//
//long long domin,value;
//
//unordered_map<long long,int> graph;
//
//int main() {
//    cin>>length>>weight;
//    for(int i=0,count=0;i<length;++i)
//        for(int j=0;j<weight;++j) {scanf("%lld",&value);graph[value]++;if(graph[value]>count) {domin=value;count=graph[value];}}
//    cout<<domin;
//
//}
//
////说明：给你一个二维数组图像，让你求出当中出现次数最多的元素。
//
////分析：设置一个hash数组来统计每个元素出现的次数，比较出现的次数，得出最大。
//
////注意：1、元素的值肯能会很大，得用longlong来存（0~2^24，longlong为2^32）2、输入用scanf否则会超时。3、必须变输入边比较判断，否则也会超时。
