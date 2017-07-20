#include <iostream>
#include <stdio.h>
using namespace std;

int sunday(char * source, char * pattern)
{
	int patternLen = strlen(pattern);
	int sourceLen = strlen(source);
	if (patternLen == 0) return 0;
	if (sourceLen < patternLen) return -1;

	// ����pattern���ַ���������λ�õ�ӳ��
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
	
	// ��ʼ��������rst������ܵ�ƥ��λ��
	int rst = 0;

	// ע��ѭ���ж�����������i < sourceLen - patternLen
	// ��Ϊ����source��pattern��ȫһ�������
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
				// �ж��±��Ƿ�Խ��
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