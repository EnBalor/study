#include <stdio.h>

//전역변수
int num = 10;

void printGlobal()
{
	printf("%d\n", num);
}

int main()
{
	//선언한 10 출력
	printf("%d\n", num);

	//변수 값을 20으로 변경
	num = 20;

	//printglobal 함수에서 전역변수 값 출력
	printGlobal();

	return 0;
}