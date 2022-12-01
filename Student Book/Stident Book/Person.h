#pragma once
#include<iostream>
using namespace std;

class Person
{
protected:
	char* name;
	char* surname;
	int age;
public:
	Person();
	Person(const char* name, const char* surname, int age);
	Person(const Person&);	
	void Print()const;
	~Person();
	Person(Person&& obj);
	const char* getName()const;
	const char* getSurname()const;
	int getAge();
	void setName(const char* name);
	void setSurname(const char* surname);
	void setAge(int age);
	Person& operator = (const Person& obj);
	Person& operator = (Person&& obj);
	friend istream& operator >>(istream& cin, Person& obj);
	friend ostream& operator << (ostream&, const Person&);
};


