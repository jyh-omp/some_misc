/*
已知一系列朋友关系，如{{1<->2}, {2<->3}, {4<->8}...}而且朋友关系可以传递，现在输入任意两个人，判断它们是否是朋友关系。
	这是典型的并查集的应用。
	设置两个数组A,B，A用于存储所有的人，B[i]表示员工A[i]所在集合（朋友圈）。初始B中所有元素置B[i]=i，代表初始状态下每个元素构成
	自己独立的集合。
	并集操作：如果A[i]和A[j]是朋友关系，首先获取A[i]和A[j]所在的集合ID,set_i和set_j，如果集合ID相等，返回，否则B[set_i],
		  B[set_j]赋值为min{set_i, set_j}。
	查集操作：查找元素的集合ID时，需要循环查找，直到找到i和B[i]相等的情况，此时的i就是集合ID，如果不相等，i重新赋值为B[i]。
	判断输入的两个元素是否为朋友关系（也就是是否属于同一个朋友圈）的时候，只要对比下查找得到的集合ID是否相等就能得到结果。
*/
/*并查集可以用树这种数据结构来实现，也可以用数组来实现，除了A,B数组外再增加一个数组还可以存储更多的信息。*/

#include <iostream>
using namespace std;

/*设计成单例模式，因为朋友关系的实例整个应用程序只需要一个就OK。*/
class MyUnionFindSet {
public:
	virtual ~MyUnionFindSet();
	static MyUnionFindSet* GetInstance();
	void UnionSet(int a, int b);
	void FindSet(int a);
	int CheckFriendRelation(int x, int y);

private:
	MyUnionFindSet(vector<int> people, vector<pair<int, int>>& relation);
	static MyUnionFindSet* instance;

	//存储所有的元素；
	vector<int> A;
	//存储所有元素对应的集合ID；
	vector<int> B;
	//存储所有关系；
	vector<pair<int, int>> rel;
};

MyUnionFindSet* MyUnionFindSet::instance = NULL;

MyUnionFindSet::MyUnionFindSet(vector<int>& people, vector<pair<int, int>>& relation) {
	for (auto a : people) {
		A.push_back(a);
	}
	for (auto r : relation) {
		rel.push_back(r);
	}
	//初始每个元素为一个单独的集合。
	for (int i = 0; i < B.size(); i++) {
		B[i] = i; //简单起见，假设A[i]中存储的是i。
	}

	for (auto iter = rel.cbegin(); iter != rel.cend(); iter++) {
		UnionSet(iter->first, iter->second);
	}
}
MyUnionFindSet::~MyUnionFindSet() {}

/*根据已知关系合并两个集合*/
void MyUnionFindSet::UnionSet(int a, int b) {
	//i, j分别是a, b的集合ID
	i = FindSet(a);
	j = FindSet(b);
	if (i == j) {
		return;
	}
	/*最核心的操作*/
	if (i < j) {
		B[i] = j;
	} else {
		B[j] = i;
	}
}

/*查找元素所在的集合ID*/
void MyUnionFindSet::FindSet(int a) {
	int i = a;
	while (B[i] != i) {
		i = B[i];
	}
	return i;
}

int MyUnionFindSet::CheckFriendRelation(int x, int y) {
	return FindSet(x) == FindSet(y);
}

static MyUnionFindSet* MyUnionFindSet::GetInstance() {
	if (instance == NULL) {
		instance = New MyUnionFindSet();
	}
	return instance;
}



int main(int args, char** argv) {
	vector<int> people;
	for (int i = 1; i < 9; i++) {
		people.push_back(i);
	}
	vector<pair<int, int>> relation;
	relation.push_back(make_pair<int, int>(1, 2));
	relation.push_back(make_pair<int, int>(2, 6));
	relation.push_back(make_pair<int, int>(5, 7));
	relation.push_back(make_pair<int, int>(2, 5));
	relation.push_back(make_pair<int, int>(4, 8));

	my_ufs = MyUnionFindSet(people, relation);
	int x = 3, y = 7;
	int res = my_ufs.CheckFriendRelation(x, y);

	if (res == 0) {
		cout << "They are not friends." << endl;
	} else if (res == 1) {
		cout << "They are friends." << endl;
	} else {
		cout << "Some errors happened..." << endl;
	}
	
}