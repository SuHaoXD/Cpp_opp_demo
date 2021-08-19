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

	Human h1("1", "张三", 20, 'M', to_string(rand()), "烽火"); 
	m_h[h1.getID()] = h1;


	v_h.push_back(h1);
	Human h2("2", "李四", 10, 'W', to_string(rand()), "烽火"); 
	v_h.push_back(h2);
	Human h3("3", "王五", 22, 'M', to_string(rand()), "烽火");
	v_h.push_back(h3);
	Human h4("4", "赵六", 23, 'M', to_string(rand()), "烽火");
	v_h.push_back(h4);
	Human h5("5", "张二", 21, 'W', to_string(rand()), "烽火");
	v_h.push_back(h5);
	Human h6("6", "王三", 15, 'M', to_string(rand()), "烽火");
	v_h.push_back(h6);
	Human h7("7", "刘三", 16, 'M', to_string(rand()), "烽火");
	v_h.push_back(h7);
	Human h8("8", "牛牛", 12, 'W', to_string(rand()), "烽火");
	v_h.push_back(h8);
	Human h9("9", "德德", 22, 'W', to_string(rand()), "烽火");
	v_h.push_back(h9);
	Human h10("10", "三三", 28, 'M', to_string(rand()), "烽火");
	v_h.push_back(h10);

	//v_h = { h1,h2,h3,h4,h5,h6,h7,h8,h9,h10 };

	for (auto &e : v_h)
	{
		l_h.push_back(e);
		s_h.insert(e);
		m_h[e.getID()] = e;
	}

	cout << "遍历数组" << endl;
	Print(v_h);

	cout << "遍历链表" << endl << endl;
	Print(l_h);

	cout << "遍历集合" << endl << endl;
	Print(s_h);

	cout << "遍历字典" << endl << endl;
	Print(m_h);

	//指定删除向量
	for (auto it = v_h.begin(); it != v_h.end(); )
	{
		if ((*it).getName() == "赵六")
		{
			it = v_h.erase(it);
			break;
		}
		else
		{
			++it;
		}
	}

	//指定删除列表
	for (auto it = l_h.begin(); it != l_h.end();)
	{
		if ((*it).getName() == "张三")
		{
			it = l_h.erase(it);
			break;
		}
		else
		{
			++it;
		}
	}

	//指定删除set
	for (auto it = s_h.begin(); it != s_h.end();)
	{
		if ((*it).getName() == "牛牛")
		{
			s_h.erase(it++);
			break;
		}
		else
		{
			++it;
		}
	}


	//指定删除map
	for (map <string, Human>::iterator it = m_h.begin(); it != m_h.end(); )
	{
		if ((*it).second.getName() == "王五")
		{
			m_h.erase(it++);
			break;
		}
		else
		{
			++it;
		}
	}
	cout << "指定删除后输出！" << endl;

	cout << "遍历数组" << endl;
	Print(v_h);

	cout << "遍历链表" << endl;
	Print(l_h);

	cout << "遍历集合" << endl;
	Print(s_h);

	cout << "遍历字典" << endl;
	Print(m_h);


	//删除vector
	for (auto it = v_h.begin(); it != v_h.end();)
	{
		it = v_h.erase(it);
	}

	//删除list
	for (auto it = l_h.begin(); it != l_h.end();)
	{
		it = l_h.erase(it);
	}

	//删除set
	for (auto it = s_h.begin(); it != s_h.end();)
	{
		s_h.erase(it++);
	}

	//删除map并回收
	for (auto it = m_h.begin(); it != m_h.end();)
	{
		m_h.erase(it++);
	}

	cout << "清空后输出！" << endl;

	cout << "遍历数组" << endl;
	Print(v_h);

	cout << "遍历链表" << endl;
	Print(l_h);

	cout << "遍历集合" << endl;
	Print(s_h);

	cout << "遍历字典" << endl;
	Print(m_h);



	system("pause");
	
}


void Print(vector<Human> v)
{
	if (v.empty())
	{
		cout << "该向量为空！" << endl;
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
		cout << "该list为空！" << endl;
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
		cout << "该set为空！" << endl;
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
		cout << "该map为空！" << endl;
		return;
	}
	for (auto &e : m)
	{
		e.second.PrintInfo();
	}
}


