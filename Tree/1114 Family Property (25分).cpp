//// This time, you are supposed to help us collect the data for family-owned property. Given each person's family members, and the estate（房产）info under his/her own name, we need to know the size of each family, and the average area and number of sets of their real estate.
////
//// Input Specification:
//// Each input file contains one test case. For each case, the first line gives a positive integer N (≤1000). Then N lines follow, each gives the infomation of a person who owns estate in the format:
////
//// ID Father Mother k Child(1)⋯Child(k) M(estate) Area
////
//// where ID is a unique 4-digit identification number for each person; Father and Mother are the ID's of this person's parents (if a parent has passed away, -1 will be given instead); k (0≤k≤5) is the number of children of this person; Child(i)'s are the ID's of his/her children; M(estate) is the total number of sets of the real estate under his/her name; and Area is the total area of his/her estate.
////
//// Output Specification:
//// For each case, first print in a line the number of families (all the people that are related directly or indirectly are considered in the same family). Then output the family info in the format:
////
//// ID M AVG(sets) AVG(area)
////
//// where ID is the smallest ID in the family; M is the total number of family members; AVG(sets)  is the average number of sets of their real estate; and AVG(area) is the average area. The average numbers must be accurate up to 3 decimal places. The families must be given in descending order of their average areas, and in ascending order of the ID's if there is a tie.
//
//// Sample Input:
//// 10
//// 6666 5551 5552 1 7777 1 100
//// 1234 5678 9012 1 0002 2 300
//// 8888 -1 -1 0 1 1000
//// 2468 0001 0004 1 2222 1 500
//// 7777 6666 -1 0 2 300
//// 3721 -1 -1 1 2333 2 150
//// 9012 -1 -1 3 1236 1235 1234 1 100
//// 1235 5678 9012 0 1 50
//// 2222 1236 2468 2 6661 6662 1 300
//// 2333 -1 3721 3 6661 6662 6663 1 100
//
//// Sample Output:
//// 3
//// 8888 1 1.000 1000.000
//// 0001 15 0.600 100.000
//// 5551 4 0.750 100.000
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define SIZE 10002
//
//using namespace std;
//
//struct node {
//    int identity,total;
//    double estate,area;
//    bool operator < (const node &a) const {
//        return area/total!=a.area/a.total?area/total>a.area/a.total:identity<a.identity;
//    }
//};
//
//vector<node> results(SIZE),result;
//
//int nodes,identity,father,mother,childs,chid,counts,people[SIZE],estate[SIZE],area[SIZE],fhash[SIZE];
//
//int Find(int node) {
//    while(node!=people[node]) node=people[node];
//    return node;
//}
//
//void Union(int anode,int bnode) {
//    int aroot=Find(anode),broot=Find(bnode);
//    people[max(aroot,broot)]=min(aroot,broot);
//}
//
//int main() {
//    cin>>nodes;
//    for(int i=0;i<SIZE;++i) people[i]=i;
//    for(int i=0;i<nodes;++i) {
//        cin>>identity>>father>>mother>>childs;
//        if(father!=-1) Union(identity,father);if(mother!=-1) Union(identity,mother);
//        for(int j=0;j<childs;j++) {cin>>chid;Union(identity,chid);fhash[chid]=1;}
//        cin>>estate[identity]>>area[identity];fhash[identity]=fhash[father]=fhash[mother]=1;
//    }
//    for(int i=0;i<SIZE;++i) {
//        results[Find(i)].total+=1;results[i].identity=i;
//        results[Find(i)].estate+=estate[i];results[Find(i)].area+=area[i];
//    }
//    for(int i=0;i<SIZE;++i)
//        if(fhash[Find(i)]) {result.push_back(results[Find(i)]);fhash[Find(i)]=0;}
//    sort(result.begin(),result.end());cout<<result.size()<<"\n";
//    for(int i=0;i<result.size();++i)
//        printf("%04d %d %.3f %.3f\n",result[i].identity,result[i].total,result[i].estate/result[i].total,result[i].area/result[i].total);
//}
//
////说明：本题给出每个人的estate和area，以及这个人的父母和孩子，所有有血缘关系的人组成为一个“家族”，让你求一共有多少个“家族”以及每个家族一共有多少人，和每个家族的平均estate和area。
//
////分析：这是典型的并查集的应用，对于每个人，我们用hash数组来存每个人（identity）的estate和area，需要的时候直接查询即可，然后我们把这个人和他的父母孩子做一个Union操作，合并到一个集合中。建集之后遍历并查集，对每一个结点查找它在results数组中的“根结点”，并把estate和area累加到根结点上并统计个数（不能直接在estate和area数组中累加，思考为什么？）。最后遍历results数组，找到每个家族的根结点加入result数组中，sort一下，输出即可。
//
////注意：本题有两个关键注意的地方，第一个是题目中所要求的并查集中每一棵树的根结点是这棵树中identity最小的节点，这个在每次合并的时候选择父节点时总选择最小即可。还有一个问题就是本题的精彩之处，你如确定你在results中找到的根结点是题中所给，或者换句话说你怎么知道有多少个家族？首先不能根据total来判断，因为在遍历results数组的时候每个total都为1，那么对于那些只有一个人的家族，无法区分，还有不能根据estate来判断，因为可能会有家族没有财产，那么我的做法是设置一个fhash数组，只要输入了一个identity我就在对应的位置置1，最后遍历results数组的时候我只把fhash为1的“根结点”加入result数组中去，这样就避免了加入flag然后进行复杂的讨论。
