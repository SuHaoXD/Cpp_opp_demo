#include "biology.h"
#include <string>
#include <iostream>
using namespace std;

void Animal::setID(string ID)
{
	this->ID = ID;
}

string Animal::getID()const
{
	return this->ID;
}

void Animal::setName(string name)
{
	this->name = name;
}

string Animal::getName()const
{
	return this->name;
}

void Animal::setAge(unsigned short age)
{
	this->age = age;
}

unsigned short Animal::getAge()const
{
	return this->age;
}

void Animal::setSex(char sex)
{
	this->sex = sex;
}

char Animal::getSex()const
{
	return this->sex;
}

void Human::setId_number(string id_number)
{
	this->id_number = id_number;
}

string Human::getId_number()const
{
	return this->id_number;
}

void Human::setCompany_name(string company_name)
{
	this->company_name = company_name;
}

string Human::getCompany_name()const
{
	return this->company_name;
}

Animal::Animal() :ID("0"), name("none"), age(0), sex('M') {}

Animal::Animal(string ID, string name, unsigned short age, char sex) :
	ID(ID), name(name), age(age), sex(sex) {}


Panda::Panda() : Animal() {}


Panda::Panda(string ID, string name, unsigned short age, char sex)
	: Animal(ID, name, age, sex) {}


Panda::Panda(Panda &other)
{
	this->setID(other.getID());
	this->setName(other.getName());
	this->setAge(other.getAge());
	this->setSex(other.getSex());
}

Panda::~Panda()
{
	cout << "ID为：" << this->getID() << "的熊猫已被释放！" << endl;
}

void Panda::PrintInfo()
{
	cout << "ID is:" << this->getID()
		<< "	name is:" << this->getName()
		<< "	age is:" << this->getAge()
		<< "	sex is:" << this->getSex() << endl;
}

Human::Human():Animal(),id_number("none"),company_name("none")
{
	cout << "ID为：" << this->getID() << "的人类通过无参构造函数创建！" << endl;
}

Human::Human(string ID, string name, unsigned short age, char sex,string id_number,string company_name)
	:Animal(ID, name, age, sex), id_number(id_number), company_name(company_name)
{
	cout << "ID为：" << this->getID() << "的人类通过有参构造函数创建！" << endl;
}

Human::Human(const Human &other)
{
	this->setID(other.getID());
	this->setName(other.getName());
	this->setAge(other.getAge());
	this->setSex(other.getSex());
	this->setId_number(other.getId_number());
	this->setCompany_name(other.getCompany_name());
	cout << "ID为：" << this->getID() << "的人类调用了拷贝构造函数" << endl;
}

void Human::PrintInfo()const
{
	cout << "ID is:" << this->getID()
		<< "	name is:" << this->getName()
		<< "	age is:" << this->getAge()
		<< "	is:" << this->getSex()
		<< "	id_number is:" << this->getId_number()
		<< "	company_name is:" << this->getCompany_name() << endl;
}

bool Human::operator<(const Human &other) const
{
	if (this->getID()<other.getID())
	{
		return true;
	}
	return false;
}


Human::~Human()
{
	cout << "ID为：" << this->getID() << "的人类已被释放！" << endl;
}








