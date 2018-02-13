#include <iostream>
using namespace std;

int findBySeq(int *numbers, int start_pos, int end_pos)
{
	int min = numbers[start_pos];
	for (int i = start_pos + 1; i <= end_pos; i++)
	{
		if (numbers[i] < min)
		{
			min = numbers[i];
		}
	}

	return min;
}

int minNumber(int* numbers,int length){
	
	if(numbers == NULL || length <= 0){
		return -1;
	}

	int start_pos = 0;
	int end_pos = length - 1;
	int mid_pos = start_pos;

	while(numbers[start_pos] >= numbers[end_pos]){

		if(end_pos - start_pos == 1){
			mid_pos = end_pos;
			break;
		}

		mid_pos = (end_pos + start_pos)/2;

		//特殊情况，当起始位置值、中间位置值、终点位置值三个值都相等时，无法判断最小值的位置
		//如由数组[0,1,1,1,1]形成的旋转数组[1,0,1,1,1]，位置（index）0、2、4的值都为1，此时只能通过顺序遍历0-4的每个元素才能得出最小值
		if(numbers[start_pos] == numbers[mid_pos] && numbers[mid_pos] == numbers[end_pos]){
			return findBySeq(numbers,start_pos,end_pos);
		}

		if(numbers[start_pos] <= numbers[mid_pos]){
			start_pos = mid_pos;
		}else if(numbers[mid_pos] <= numbers[end_pos]){
			end_pos = mid_pos;
		}

	}

	return numbers[mid_pos];
}

int main(){


	//int input[10] = {12,53,67,100,322,400,3,4,5,10};
	int input[10] = {1,1,0,1,1,1,1,1,1,1};
	int length = 10;

	int res = minNumber(input,length);


	cout<<res<<endl;

	return 0;
}
