#include <stdio.h>
#include <stdlib.h>

//동적할당
void main()
{
	//크기가 3인 배열
	int arr[3] = { 1, 2, 3 };

	// 동적 할당을 위한 포인터 변수 선언
	int *pArr;

	// 공간 할당
	// malloc는 void 값을 반환하기 때문에 (int *)로 위 배열과 자료형을 일치하기 위해 형변환
	// int형크기 * 3 메모리 할당
	pArr = (int *)malloc(sizeof(int) * 3);

	if (pArr == NULL)
	{
		printf("error");
	}

	//해당 반복문을 통해 메모리를 할당한다.
	for (int i = 0; i < 3; i++)
	{
		pArr[i] = arr[i];
	}
	
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", pArr[i]);
	}
	// 할당된 공간 해제
	free(pArr);
}