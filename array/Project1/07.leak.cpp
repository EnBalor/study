#include <stdio.h>
#include <stdlib.h>


//굳이 실행해보지 말것
void main()
{
	int *pnum = new int;
	scanf("1. 메모리 위치 : %d\n", pnum);

	pnum = new int;
	scanf("2. 메모리 위치 : %d\n", pnum);

	free(pnum);
}

/*
	첫번째 동적할당으로 메모리 위치를 저장
	이 후 다른 값을 대입하면, 해제시 처음 할당 받은 메모리 위치에 접근할 수 없기 때문에 메모리를 해제할 수 없다.
	위 코드를 실행하면 같은 변수라도 메모리 위치가 각기 다르게 나오는데 첫 번째 메모리를 해제해줘야하는데 값이 바뀌어 버려 해지할 수 없게 되는 것
*/