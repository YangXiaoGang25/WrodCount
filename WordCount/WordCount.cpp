// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void wc(char *filename) {
	FILE *fp;
	char buffer[1000];
	char c;
	int bufferlen;
	int isLastBlank = 0; // 上个字符是否是空格(1表示是  0表示不是)
	int charCount = 0;
	int wordCount = 0;
	int i;

	if ((fp = fopen(filename, "rb")) == NULL) {
		printf("文件不能打开\n");
		exit(0);
	}
	while (fgets(buffer, 1000, fp) != NULL) {
		bufferlen = strlen(buffer);
		for (i = 0; i < bufferlen; i++) {
			c = buffer[i];
			if (c == ' ' || c == '\t') {
				if (isLastBlank == 0) {
					wordCount++;
				}
				isLastBlank = 1;
			}
			else if (c != '\n'&&c != '\r') {
				charCount++;
				isLastBlank = 0;
			}

		}
		if (isLastBlank == 0)
			wordCount++;
		isLastBlank = 1;

	}
	fclose(fp);

	printf("字符数：%d\n", charCount);
	printf("单词数：%d\n", wordCount);


}
int main() {
	char filename[] = "\\Users\\10438\\Desktop\\input_file_name.txt";
	wc(filename);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
