#include "Person.h"
#include<string>
#include<iomanip>
using namespace std;

Person::Person()
{
	name = surname = nullptr;
	age = 0;
}

Person::Person(const char* name, const char* surname, int age)
{
	this->name = new char[strlen(name) + 1];
	this->surname = new char[strlen(surname) + 1];

	strcpy_s(this->name, strlen(name) + 1, name);
	strcpy_s(this->surname, strlen(surname) + 1, surname);
	this->age = age;
}

Person::Person(const Person& p)
{
	name = surname = nullptr;
	age = 0;
	name = new char[strlen(p.name) + 1];
	surname = new char[strlen(p.surname) + 1];
	strcpy_s(name, strlen(p.name) + 1, p.name);
	strcpy_s(surname, strlen(p.surname) + 1, p.surname);
	age = p.age;
}

void Person::Print() const
{
	printf("%s\n%s\n%d\n", name, surname, age);
}

Person::Person(Person&& obj)
{
	name = obj.name;
	surname = obj.surname;
	age = obj.age;
	obj.name = nullptr;
	obj.surname = nullptr;
	obj.age = 0;
}

Person::~Person()
{
		delete[]name;                 
		delete[]surname;
}

const char* Person::getName() const { return name; }

const char* Person::getSurname() const { return surname; }

int Person::getAge() { return age; }

void Person::setName(const char* name)
{
	delete[]this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Person::setSurname(const char* surname)
{
	delete[]this->surname;
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);
}

void Person::setAge(int age) { this->age = age; }

Person& Person::operator=(const Person& obj)
{
	if (this == &obj)
	{
		cout << "You tried to do self-appropriation!" << endl;
		return *this;
	}
	delete[]name;
	delete[]surname;
	name = new char[strlen(obj.name) + 1];
	surname = new char[strlen(obj.surname) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	strcpy_s(surname, strlen(obj.surname) + 1, obj.surname);
	age = obj.age;

	return *this;
}

Person& Person::operator=(Person&& obj)
{
	if (this == &obj)
	{
		cout << "You tried to do self-appropriation!" << endl;
		return *this;
	}
	delete[]name;
	delete[]surname;
	
	name = obj.name;
	surname = obj.surname;
	age = obj.age;
	obj.name = nullptr;
	obj.surname = nullptr;
	

	return *this;
}


istream& operator>>(istream& cin, Person& obj)
{
	char temp[50];
	cout << "Enter a name: ";
	cin >> temp;
	obj.setName(temp);
	cout << "Enter a surname: ";
	cin >> temp;
	obj.setSurname(temp);
	cout << "Enter an age: ";
	cin >> obj.age;

	return cin;
}

ostream& operator<<(ostream& cout, const Person& obj)
{
	cout << setw(10) <<"\nSurname:\t" << setw(20) << obj.surname
		<<  setw(10) << "\nName:\t" << setw(20) << obj.name
		<< setw(10) << "\nAge:\t" << setw(20) << obj.age << endl;

	return cout;
}
