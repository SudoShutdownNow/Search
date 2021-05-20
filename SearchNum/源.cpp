#include <iostream>
using namespace std;
#define MAX 500

bool midseek(int& times, int target, int* source, int quantity)
{
	int range[2] = { 1,quantity};
	times = 0;
	while (range[0] != range[1] - 1)
	{
		times++;
		int mid = floor(float(range[0] + range[1]) / 2);
		if (*(source+mid-1) > target)//表明要查找的词在前面
		{
			range[1] = mid-1;
		}
		else if (*(source + mid - 1) < target)
		{
			range[0] = mid+1;
		}
		else
		{
			return 1;
		}
		

	}

	if (*(source + range[0] - 1) == target )
	{
		times++;
		return 1;
	}
	else if(*(source + range[1] - 1) == target)
	{
		times += 2;
		return 1;
	}
	else
	{
		return 0;
	}

}

void main()
{
	int source[MAX];
	int i = 0 , temp;
	while (cin >> temp)
	{
		if (temp == -1)
		{
			break;
		}
		source[i] = temp;
		i++;
	}
	int times,target;
	cin >> target;

	midseek(times, target, source, i);
	cout << times;
}