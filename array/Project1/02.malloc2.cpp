#include <stdio.h>
#include <stdlib.h>

//동적할당
void main()
{
	//입력 받을 변수 선언
	int num;

	// 동적 할당을 위한 포인터 변수 선언
	int *pArr;

	printf("입력할 배열의 수 : ");
	scanf("%d", &num);

	//입력한 값 만큼 동적할당
	pArr = (int*)malloc(sizeof(int) * num);

	//배열에 수 입력
	for (int i = 0; i < num; i++)
	{
		printf("배열에 입력할 수 : ");
		scanf("%d", &pArr[i]);
	}

	//입력한 수 출력
	for (int i = 0; i < num; i++)
	{
		printf("%d번 배열 : %d\n", i, pArr[i]);
	}

	//동적할당 해제
	free(pArr);
}