//// The task of this problem is simple: insert a sequence of distinct positive integers into a hash table first. Then try to find another sequence of integer keys from the table and output the average search time (the number of comparisons made to find whether or not the key is in the table). The hash function is defined to be H(key)=key%TSize where TSize is the maximum size of the hash table. Quadratic probing (with positive increments only) is used to solve the collisions.
////
//// Note that the table size is better to be prime. If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line contains 3 positive numbers: MSize, N, and M, which are the user-defined table size, the number of input numbers, and the number of keys to be found, respectively. All the three numbers are no more than 10^4. Then N distinct positive integers are given in the next line, followed by M positive integer keys in the next line. All the numbers in a line are separated by a space and are no more than 10^5.
////
//// Output Specification:
//// For each test case, in case it is impossible to insert some number, print in a line X cannot be inserted. where X is the input number. Finally print in a line the average search time for all the M keys, accurate up to 1 decimal place.
//
//// Sample Input:
//// 4 5 4
//// 10 6 4 15 11
//// 11 4 15 2
//
//// Sample Output:
//// 15 cannot be inserted.
//// 2.8
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int tsize,nodes,searc;double times;vector<int> thash;
//
//bool isPrime(int num) {for(int i=2;i*i<=num;++i) if(!(num%i)) return 0;return num==1?0:1;}
//
//int main() {
//    cin>>tsize>>nodes>>searc;while(!isPrime(tsize)) ++tsize;thash.resize(tsize);
//    for(int i=0,value,index,prob=0;i<nodes;++i,prob=0) {
//        cin>>value;do{index=(value+prob*prob)%tsize;++prob;} while(thash[index]&&prob<=tsize);
//        if(prob>tsize) printf("%d cannot be inserted.\n",value);else thash[index]=value;
//    }
//    for(int i=0,value,index,prob=0;i<searc;++i,prob=0)
//       {cin>>value;do{index=(value+prob*prob)%tsize;++prob;} while(thash[index]&&thash[index]!=value&&prob<=tsize);times+=prob;}
//    printf("%.1f",times/searc);
//}
//
////说明：给一个哈希表，并给出一个插入序列，把序列中的值依次插入哈希表，最后给一个查找序列，求平均查找长度。（冲突处理用二次探测再散列法）
//
////分析：无论是插入还是查找的key，它们在哈希表中的位置都是H（key）=（key+prob^2）%tsize。假如key不能插入，要把key输出。查找时，假如key不在表中，则查找失败（包括当前位置为0以及prob超过表长两种情况），prob即为查找长度。把prob做一个累加，平均查找长度=总查找长度/查找元素的个数。
//
////注意：假如给出哈希表长L不是素数，要选择比L大的第一个素数，素数问题很复杂，会在数论里面详细说。
