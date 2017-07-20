#include <iostream>
#include <stdio.h>
using namespace std;

int sunday(char * source, char * pattern)
{
	int patternLen = strlen(pattern);
	int sourceLen = strlen(source);
	if (patternLen == 0) return 0;
	if (sourceLen < patternLen) return -1;

	// 建立pattern中字符与最后出现位置的映射
	const int CHAR_RANGE = 128;
	char map[CHAR_RANGE];
	for (int i = 0; i < CHAR_RANGE; ++i)
	{
		map[i] = -1;
	}
	for (int i = 0; i < patternLen; ++i)
	{
		map[pattern[i]] = i;
	}
	
	// 开始搜索，用rst保存可能的匹配位置
	int rst = 0;

	// 注意循环判断条件不能是i < sourceLen - patternLen
	// 因为存在source和pattern完全一样的情况
	for (int i = 0; i < sourceLen;)
	{
		int j = 0;
		for (; j < patternLen;)
		{
			if (source[i] == pattern[j])
			{
				++i;
				++j;
			}
			else
			{
				int nextIndex = rst + patternLen;
				// 判断下标是否越界
				if (nextIndex > sourceLen) return -1;
				i = nextIndex - map[source[nextIndex]];
				rst = i;
				break;
			}
		}
		if (j == patternLen)
		{
			return rst;
		}
	}
	return -1;
}

int main(int argc, char ** argv)
{
	cout << sunday("mississippi", "sippj") << endl;
	cout << sunday("mississippi", "issipi") << endl;
	cout << sunday("abcabc", "cab") << endl;
	cout << sunday("a", "a") << endl;
	cout << sunday("abcabc", "t") << endl;
	cout << sunday("bcabc", "") << endl;
	cout << sunday("", "abc") << endl;

	getchar();
	return 0;
}