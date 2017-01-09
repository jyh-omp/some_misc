/*hash结点数据结构*/
class HashItem {
public:
	HashItem(string k, string v):key(k), val(v) {}
	const string& GetKey() {
		return key;
	}
	const string& GetVal() {
		return val;
	}
	void SetVal(string ) {
		val = v;
	}

private:
	string key, val;
};


/*哈希表数据结构*/
class HashTable() {
public:
	HashTable() {}
	void Set(string key, string val) {
		//hash_func为特定的哈希函数；
		int idx = hash_func(key) % SIZE;
		/*处理哈希地址冲突，使用开发地址法的线性探测方式*/
		while (table[idx] && table[idx]->GetKey() != key) {
			idx = (idx + 1) % SIZE;
		}
		if (table[idx]) {
			table[idx]->SetVal(key);
		} else {
			table[idx] = make_shared<HashItem>(key, val);
		}
	}

	const string Get(string key) {
		int idx = hash_func(key) % SIZE;
		while (table[idx] && table[idx]->GetKey() != key) {
			idx = (idx + 1) % SIZE;
		}
		return table[idx] ? table[idx]->GetVal() : -1;
	}

private:
	static const int SIZE = 256;	
	vector<shared_ptr<HashItem>> table(SIZE);
}
