#include "biology.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <time.h>
#include <string>

using namespace std;
void Print(vector<Human> v);
void Print(list <Human> l);
void Print(set <Human> s);
void Print(map <string, Human> m);

int main()
{
	srand((int)time(0));
	vector <Human> v_h;
	list <Human> l_h;
	map <string,Human> m_h;
	set <Human> s_h;

	Human h1("1", "����", 20, 'M', to_string(rand()), "���"); 
	m_h[h1.getID()] = h1;


	v_h.push_back(h1);
	Human h2("2", "����", 10, 'W', to_string(rand()), "���"); 
	v_h.push_back(h2);
	Human h3("3", "����", 22, 'M', to_string(rand()), "���");
	v_h.push_back(h3);
	Human h4("4", "����", 23, 'M', to_string(rand()), "���");
	v_h.push_back(h4);
	Human h5("5", "�Ŷ�", 21, 'W', to_string(rand()), "���");
	v_h.push_back(h5);
	Human h6("6", "����", 15, 'M', to_string(rand()), "���");
	v_h.push_back(h6);
	Human h7("7", "����", 16, 'M', to_string(rand()), "���");
	v_h.push_back(h7);
	Human h8("8", "ţţ", 12, 'W', to_string(rand()), "���");
	v_h.push_back(h8);
	Human h9("9", "�µ�", 22, 'W', to_string(rand()), "���");
	v_h.push_back(h9);
	Human h10("10", "����", 28, 'M', to_string(rand()), "���");
	v_h.push_back(h10);

	//v_h = { h1,h2,h3,h4,h5,h6,h7,h8,h9,h10 };

	for (auto &e : v_h)
	{
		l_h.push_back(e);
		s_h.insert(e);
		m_h[e.getID()] = e;
	}

	cout << "��������" << endl;
	Print(v_h);

	cout << "��������" << endl << endl;
	Print(l_h);

	cout << "��������" << endl << endl;
	Print(s_h);

	cout << "�����ֵ�" << endl << endl;
	Print(m_h);

	//ָ��ɾ������
	for (auto it = v_h.begin(); it != v_h.end(); )
	{
		if ((*it).getName() == "����")
		{
			it = v_h.erase(it);
			break;
		}
		else
		{
			++it;
		}
	}

	//ָ��ɾ���б�
	for (auto it = l_h.begin(); it != l_h.end();)
	{
		if ((*it).getName() == "����")
		{
			it = l_h.erase(it);
			break;
		}
		else
		{
			++it;
		}
	}

	//ָ��ɾ��set
	for (auto it = s_h.begin(); it != s_h.end();)
	{
		if ((*it).getName() == "ţţ")
		{
			s_h.erase(it++);
			break;
		}
		else
		{
			++it;
		}
	}


	//ָ��ɾ��map
	for (map <string, Human>::iterator it = m_h.begin(); it != m_h.end(); )
	{
		if ((*it).second.getName() == "����")
		{
			m_h.erase(it++);
			break;
		}
		else
		{
			++it;
		}
	}
	cout << "ָ��ɾ���������" << endl;

	cout << "��������" << endl;
	Print(v_h);

	cout << "��������" << endl;
	Print(l_h);

	cout << "��������" << endl;
	Print(s_h);

	cout << "�����ֵ�" << endl;
	Print(m_h);


	//ɾ��vector
	for (auto it = v_h.begin(); it != v_h.end();)
	{
		it = v_h.erase(it);
	}

	//ɾ��list
	for (auto it = l_h.begin(); it != l_h.end();)
	{
		it = l_h.erase(it);
	}

	//ɾ��set
	for (auto it = s_h.begin(); it != s_h.end();)
	{
		s_h.erase(it++);
	}

	//ɾ��map������
	for (auto it = m_h.begin(); it != m_h.end();)
	{
		m_h.erase(it++);
	}

	cout << "��պ������" << endl;

	cout << "��������" << endl;
	Print(v_h);

	cout << "��������" << endl;
	Print(l_h);

	cout << "��������" << endl;
	Print(s_h);

	cout << "�����ֵ�" << endl;
	Print(m_h);



	system("pause");
	
}


void Print(vector<Human> v)
{
	if (v.empty())
	{
		cout << "������Ϊ�գ�" << endl;
		return;
	}
	for (auto &e : v)
	{
		e.PrintInfo();
	}
}

void Print(list <Human> l)
{
	if (l.empty())
	{
		cout << "��listΪ�գ�" << endl;
		return;
	}
	for (auto &e : l)
	{
		e.PrintInfo();
	}
}

void Print(set <Human> s)
{
	if (s.empty())
	{
		cout << "��setΪ�գ�" << endl;
		return;
	}
	for (auto &e : s)
	{
		e.PrintInfo();
	}
}

void Print(map <string, Human> m)
{	
	if (m.empty())
	{
		cout << "��mapΪ�գ�" << endl;
		return;
	}
	for (auto &e : m)
	{
		e.second.PrintInfo();
	}
}


