//// The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers. The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.
////
//// Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains two positive numbers: MSize (≤10^4) and N (≤MSize) which are the user-defined table size and the number of input numbers, respectively. Then N distinct positive integers are given in the next line. All the numbers in a line are separated by a space.
////
//// Output Specification:
//// For each test case, print the corresponding positions (index starts from 0) of the input numbers in one line. All the numbers in a line are separated by a space, and there must be no extra space at the end of the line. In case it is impossible to insert the number, print "-" instead.
//
//// Sample Input:
//// 4 4
//// 10 6 4 15
//
//// Sample Output:
//// 0 1 4 -
//
//#include <iostream>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int tsize,nodes;vector<int> thash;
//
//bool isPrime(int num) {for(int i=2;i<=sqrt(num);++i) if(!(num%i)) return 0;return num==1?0:1;}
//
//int main() {
//    cin>>tsize>>nodes;while(!isPrime(tsize)) ++tsize;thash.resize(tsize);
//    for(int i=0,prob=0,value,index;i<nodes;++i,prob=0){
//        cin>>value;do{index=(value+prob*prob)%tsize;++prob;} while(thash[index]&&prob<=tsize);
//        cout<<(i?" ":"")<<(!thash[index]?to_string(index):"-");if(!thash[index]) thash[index]=1;
//    }
//}
//
////说明：给一个哈希表，并给出一个插入序列，让你求出序列中每个数插入哈希表中的位置，冲突处理用二次探测再散列法。
//
////分析：每个插入的数key在哈希表中的位置H（key）=（key+prob^2）%tsize，其中prob（为非负且<=size）为探测因子，如果经过探测每个位置都不能插入，输出-。
//
////注意：假如给出哈希表长L不是素数，要选择比L大的第一个素数，素数问题很复杂，会在数论里面详细说。
