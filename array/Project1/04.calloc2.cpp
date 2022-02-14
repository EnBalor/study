#include <stdio.h>
#include <stdlib.h>

//동적할당
void main()
{
	// 동적 할당을 위한 포인터 변수 선언
	int *pArr;

	//calloc은 할당된 공간의 값을 모두 0으로 바꾸기 때문에 배열을 할당하고 값을 초기화할 필요가 있을 때 사용하면 편함 
	pArr = (int *)calloc(3, sizeof(int));

	if (pArr == NULL)
	{
		printf("error");
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", pArr[i]);
	}
	// 할당된 공간 해제
	free(pArr);
}