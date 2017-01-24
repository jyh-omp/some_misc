#include <ifstream>

using namespace std;

const char SP_CHAR = 0xFF;

int rhe_encoding(const char* file_path) {
	ifstream ifs;
	ifs.open(file_path, ios::in|ios:binary);
	if(!ifs) {
		return -1;
	}

	//计算文件大小；
	ifs.seekg(0, ifs.end);
	auto length = ifs.tellg();
	ifs.seekg(0, ifs.beg); //读取index回到文件开头；

	char* buffer = new char[length];
	char* res_buf = new char[length];

	//ifs.get(buffer, length);
	//read data as a block;
	ifs.read(buffer, length);
	ifs.close();

	int index = 0;
	int res_index = 0;  //结果文件中写index；
	while(index < length) {
		//前驱指针；
		int forward = 1;
		while(buffer[index] == buffer[index + forward] && index + forward < length) {
			forward++;
		}
		if(forward > 3) { //符合压缩的条件；
			res_buf[res_index++] = sp_char;
			res_buf[res_index++] = forward;
			res_buf[res_index++] = buffer[index];
		} else {
			//将原有内容直接拷贝；
			memcpy(res_buf + res_index, buffer + index, forward);
			res_index += forward;
		}
		
		index += forward;
	}	
}