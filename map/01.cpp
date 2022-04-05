#include <iostream>
#include <map>
#include <string>

using namespace std;

// map 선언
map<string, int> m;
map<string, int> m2;
multimap<string, int> mm;


int main()
{
	// 새 요소를 맵에 삽입
	m.insert({ "A", 1 });
	m.insert({ "B", 2 });
	m["C"] = 3;
	m.insert(pair<string, int>("D", 4));

	cout << "map find" << endl;
	// A 찾기
	if (m.find("A") != m.end())
	{
		cout << "찾음" << endl;
	}

	else
	{
		cout << "없음" << endl;
	}
	cout << endl;

	map<string, int>::iterator iter;

	cout << "map 출력" << endl;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << "[" << iter->first << ", " << iter->second << "]" << " ";
	}
	cout << endl;
	cout << endl;

	cout << "map reverse 출력" << endl;
	map<string, int>::reverse_iterator riter;
	for (riter = m.rbegin(); riter != m.rend(); riter++)
	{
		cout << "[" << riter->first << ", " << riter->second << "]" << " ";
	}
	cout << endl;
	cout << endl;

	cout << "map empty" << endl;
	cout << m2.empty();
	cout << endl;
	cout << endl;


	m2.insert({ "E", 1 });
	m2.insert({ "F", 2 });
	m2["U"] = 3;
	m2.insert(pair<string, int>("gayle", 4));

	cout << "map swap" << endl;
	m.swap(m2);

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << "[" << iter->first << ", " << iter->second << "]" << " ";
	}
	cout << endl;

	for (iter = m2.begin(); iter != m2.end(); iter++)
	{
		cout << "[" << iter->first << ", " << iter->second << "]" << " ";
	}
	cout << endl;


	mm.insert({ "A", 1 });
	mm.insert({ "A", 2 });
	//mm["A"] = 3;
	//map과 다르게 operator를 사용해 원소를 추가 또는 수정이 불가능
	mm.insert(pair<string, int>("B", 4));
	mm.insert(pair<string, int>("B", 5));

	multimap<string, int>::iterator miter;

	// key값에 해당하는 맨 첫번째 원소
	multimap<string, int>::iterator lower = mm.lower_bound("A");

	// key값에 해당하는 맨 마지막 원소의 다음
	multimap<string, int>::iterator upper = mm.upper_bound("A");

	cout << "multimap count" << endl;
	cout << mm.count("A") << endl;
	cout << endl;


	cout << "multimap lower, upper" << endl;
	cout << "lower_iter : " << lower->first << ", " << lower->second << endl;
	cout << "upper_iter : " << upper->first << ", " << upper->second << endl;
	cout << endl;

	cout << "B 값의 인자" << endl;
	//중복 키 값이 존재하는 B 의 인자 출력.    
	for (miter = mm.equal_range("B").first; miter != mm.equal_range("B").second; miter++)
	{
		cout << "[" << miter->first << ", " << miter->second << "] ";
	}
	cout << endl;

	return 0;
}

/*
연산자 == != < > <= >= 가능
[]를 통해 원소의 수정 삭제가 가능
pair란 두 객체를 하나의 객체로 취급할 수 있게 묶어주는 클래스, map에서는 반드시 pair객체를 만들어서 원소를 추가한다 하는데 현재는 거의 사용하지 않는다 라고만 알고 있는데 뭐가 더 정확한지는 잘 모르겠지만
굳이 안써도 삽입수정이 가능한걸로 보아하니 필수는 아닌게 맞는 듯
*/