#include <iostream>
using namespace std;
#define MAX 3500
#define MAXLETTER 15
#pragma warning (disable : 4996)

struct dict {
	char word[MAX][MAXLETTER];
	int quantity;//收录的单词数量
}mydict;

void loadDict(char* path)
{
	FILE* fp = fopen(path, "r");
	int i = 0;
	for (int i = 0; fgets(mydict.word[i], MAXLETTER - 1, fp) != NULL; i++)
	{
		mydict.quantity = i + 1;
	}
	
}

bool sqseek(int& times, char* target)//返回0或1，代表是否找到
{
	times = 1;//查找了多少次
	for (int i = 0; i < mydict.quantity; i++)
	{
		if (strcmp(mydict.word[i], target) == 0)
		{
			return 1;
		}
		times++;
	}
	return 0;
}

bool midseek(int& times, char* target)
{
	int range[2] = { 0,mydict.quantity - 1 };
	times = 1;
	while (range[0] != range[1]-1)
	{
		
		int mid = (range[0] + range[1]) / 2;
		if (strcmp(mydict.word[mid], target) > 0)//表明要查找的词在前面
		{
			range[1] = mid;
		}
		else if (strcmp(mydict.word[mid], target) < 0)
		{
			range[0] = mid;
		}
		else
		{
			return 1;
		}
		times++;

	}

	if (strcmp(mydict.word[range[0]], target) != 0 && strcmp(mydict.word[range[1]], target) != 0)
	{
		return 0;
	}
	
}

int main()
{
	char* path = new char[50];
	cin >> path;
	loadDict(path);
	int times = 1;

	char* target = new char[15];
	cin >> target;
	sprintf(target, "%s\n", target);

	cout << sqseek(times, target) << " ";
	cout << times << endl;

	cout << midseek(times, target) << " ";
	cout << times << endl;

}