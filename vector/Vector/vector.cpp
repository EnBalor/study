#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	// 비어있는 vector를 생성한다

	vector<int> v2(5);
	// 기본값이 초기화된 5개의 원소를 가진 vector를 생성한다.


	vector<int> v3(5, 2);
	// 2로 초기화된 5개의 원소를 가진 vector를 생성한다

	vector<int> vec1(5);
	vector<int> vec2(vec1);
	// vec1을 복사한 vector를 생성한다

	v.assign(5, 2);
	// 2의 값으로 5개의 원소 할당.

	v.at(num);
	// num번째 원소를 참조, v[num]보다 느리지만 범위 점검을 수행

	v[num];
	// num번째 원소를 참조, v(num)보다 빠름

	v.front();
	// 첫번째 원소 참조

	v.back();
	// 마지막 원소 참조

	v.clear();
	// 모든 원소 제거, 원소만 제거하고 메모리는 남아 있음, size만 줄어들고 capacity는 유지

	v.push_back(7);
	// 마지막 원소 뒤에 7을 삽입

	v.pop_back();
	// 마지막 원소 제거

	v.reserve(n);
	// n개의 원소를 저장할 위치를 예약

	v.resize(n);
	// 크기를 n으로 변경, 더 커질 경우 default 값인 0을 ㅗ초기화

	v.resize(n, 3);
	// 크기를 n으로 변경, 더 커질 경우 인자값을 3으로 초기화

	v.size();
	// 원소 갯수를 리턴

	v.capacity();
	//할당된 공간의 크기를 리턴 size보다 크게 할당되어 있음
	/*
		새로운 원소가 추가되면 메모리 공간이 추가적으로 할당되는데, 매번 새 원소가 들어올 때마다 새로운 메모리를 할당하는 것은 비효율적
		reserve를 이용해 미리 할당하면 효율적
	*/

	v.insert(2, 3, 4);
	// 2번째 위치에 3개의 4를 삽입

	v.insert(2, 3);
	// 2번째 위치에 3의 값을 삽입

	return 0;
}