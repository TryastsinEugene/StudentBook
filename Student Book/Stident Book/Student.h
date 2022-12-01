#pragma once
#include"Person.h"
class Student :public Person
{
	char phone[14];
	double raiting;
public:
	Student();
	Student(const char* name, const char* surname, const int age, const char* phone, double raiting);
	Student(const Student& obj);
	Student(Student&& obj);
	void Print()const;
	double getRating()const;
	const char* getPhone() const;
	void setPhone(const char* phone);
	void setRating(double average);

	Student& operator=(const Student& obj);
	Student& operator=(Student&& obj);
	friend istream& operator >>(istream& cin, Student& obj);
	friend ostream& operator <<(ostream& cout, const Student& obj);
};