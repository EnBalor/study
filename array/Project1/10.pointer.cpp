#include <stdio.h>


int main()
{
	//포인터변수선언
	int *numPtr;
	
	//int형 변수를 선언하고 10 입력
	int num = 10;

	//num의 메모리 주소를 포인터 변수에 입력
	numPtr = &num;

	printf("%p\n", numPtr);    // 포인터 변수 numPtr의 값 출력
	printf("%p\n", &num);     // num의 메모리 주소 출력

	return 0;
}

/*
	변수 이름 앞에 &(엠퍼센드)를 붙이면 그 변수의 주소를 알려줌
	해당 변수가 어디에 저장되어 있는지를 나타냄
*/