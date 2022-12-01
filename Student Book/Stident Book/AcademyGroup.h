#pragma once
#include"Student.h"

class AcademyGroup
{
	Student** pSt;
	int count;
	
public:
	AcademyGroup();
	AcademyGroup(const AcademyGroup& obj);
	AcademyGroup(AcademyGroup&& obj);
	~AcademyGroup();
	int getCount()const;
	void Print();
	void AddStudents();
	void DeleteStudent();
	bool Check(char*);
	void EditStudent();
	void FindStudent();
	void Sort();
	void Save();
	void Load();
	AcademyGroup& operator=(const AcademyGroup& obj);
	AcademyGroup& operator=(AcademyGroup&& obj);
	Student& operator[](int index);
	friend std::ostream& operator << (std::ostream& os, AcademyGroup& obj);
};