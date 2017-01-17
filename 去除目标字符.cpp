/*去除字符串中的所有目标字符*/
int remove_target_char(char* str, char target_c) {
	if (str == NULL || target_c == 0) {
		return -1;
	}

	int len = strlen(str);

	/*这样的代码比多个if..else更优雅，简洁*/
	int index = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] != target_c) {
			str[index++] = str[i];
		}
	}

	str[index] = '\0';
	//释放多余内存空间；
	for (int j = index + 1; j < len; j++) {
		delete (str + j);
	}

	return 0;
}