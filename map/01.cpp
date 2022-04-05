#include <iostream>
#include <map>
#include <string>

using namespace std;

// map ����
map<string, int> m;
map<string, int> m2;
multimap<string, int> mm;


int main()
{
	// �� ��Ҹ� �ʿ� ����
	m.insert({ "A", 1 });
	m.insert({ "B", 2 });
	m["C"] = 3;
	m.insert(pair<string, int>("D", 4));

	cout << "map find" << endl;
	// A ã��
	if (m.find("A") != m.end())
	{
		cout << "ã��" << endl;
	}

	else
	{
		cout << "����" << endl;
	}
	cout << endl;

	map<string, int>::iterator iter;

	cout << "map ���" << endl;
	for (iter = m.begin(); iter != m.end(); iter++)
	{
		cout << "[" << iter->first << ", " << iter->second << "]" << " ";
	}
	cout << endl;
	cout << endl;

	cout << "map reverse ���" << endl;
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
	//map�� �ٸ��� operator�� ����� ���Ҹ� �߰� �Ǵ� ������ �Ұ���
	mm.insert(pair<string, int>("B", 4));
	mm.insert(pair<string, int>("B", 5));

	multimap<string, int>::iterator miter;

	// key���� �ش��ϴ� �� ù��° ����
	multimap<string, int>::iterator lower = mm.lower_bound("A");

	// key���� �ش��ϴ� �� ������ ������ ����
	multimap<string, int>::iterator upper = mm.upper_bound("A");

	cout << "multimap count" << endl;
	cout << mm.count("A") << endl;
	cout << endl;


	cout << "multimap lower, upper" << endl;
	cout << "lower_iter : " << lower->first << ", " << lower->second << endl;
	cout << "upper_iter : " << upper->first << ", " << upper->second << endl;
	cout << endl;

	cout << "B ���� ����" << endl;
	//�ߺ� Ű ���� �����ϴ� B �� ���� ���.    
	for (miter = mm.equal_range("B").first; miter != mm.equal_range("B").second; miter++)
	{
		cout << "[" << miter->first << ", " << miter->second << "] ";
	}
	cout << endl;

	return 0;
}

/*
������ == != < > <= >= ����
[]�� ���� ������ ���� ������ ����
pair�� �� ��ü�� �ϳ��� ��ü�� ����� �� �ְ� �����ִ� Ŭ����, map������ �ݵ�� pair��ü�� ���� ���Ҹ� �߰��Ѵ� �ϴµ� ����� ���� ������� �ʴ´� ��� �˰� �ִµ� ���� �� ��Ȯ������ �� �𸣰�����
���� �Ƚᵵ ���Լ����� �����Ѱɷ� �����ϴ� �ʼ��� �ƴѰ� �´� ��
*/