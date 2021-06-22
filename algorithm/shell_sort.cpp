/*
希尔排序也是一种插入排序，它是简单插入排序经过改进之后的一个更高效的版本，也称为缩小增量排序

增量序列为n/2,n/4...
对每个分组进行插入排序

希尔排序是非稳定排序算法。
*/
#include <iostream>
#include <vector>
using namespace std;

void Shell_sort(int a[],size_t n)
{
	int i,j,k,group;
	for (group = n/2; group > 0; group /= 2)//增量序列为n/2,n/4....直到1
	{
		for (i = 0; i < group; ++i)
		{
			for (j = i+group; j < n; j += group)
			{
				//对每个分组进行插入排序
				if (a[j - group] > a[j])
				{
					int temp = a[j];
					k = j - group;
					while (k>=0 && a[k]>temp)
					{
						a[k+group] = a[k];
						k -= group;
					}
					a[k] = temp;
				}
			}
		}
	}
}
 
int main(int argc, char**argv)
{
	int a[10] = {1,51,6,2,8,2,564,1,65,6};
 
	Shell_sort(a,10);
	for (int i = 0; i < 10; ++i)
	{
		cout<<a[i]<<" ";
	}
	cin.get();
	return 0;
}