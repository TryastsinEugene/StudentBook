#include "AcademyGroup.h"
#include<string>
#include<assert.h>
#include<io.h>

AcademyGroup::AcademyGroup()
{
	count = 0;
	pSt = nullptr;
}

AcademyGroup::AcademyGroup(const AcademyGroup& obj)
{
	count = obj.count;
	pSt = new Student * [count];
	for (int i = 0; i < count; i++)
		pSt[i] = new Student;

	for (int i = 0; i < count; i++)
		pSt[i] = obj.pSt[i];
}

AcademyGroup::AcademyGroup(AcademyGroup&& obj)
{
	count = obj.count;
	pSt = obj.pSt;
	obj.pSt = nullptr;
}

AcademyGroup::~AcademyGroup()
{
	
	if (pSt)
	{
		for (int i = 0; i < count; i++)		
			delete pSt[i];
		
		delete[]pSt;
		pSt = nullptr;
	}
}

int AcademyGroup::getCount()const { return count; }

bool AcademyGroup::Check(char* str)
{
	int size;
	for (int i = 0; i < count; i++)
	{	
		if (!strcmp(str, pSt[i]->getSurname()))
			return true;
	}
		
	return false;
}

void AcademyGroup::Sort()
{
	system("cls");
	if (!count)
	{
		cout << "The book is empty.\n";
		return;
	}
	else if (count == 1)
	{
		cout << "Only one student in the book.\n";
		return;
	}
	else
		for (int i = 1; i < count; i++)
			for (int j = 1; j < count; j++)
				if (strcmp(pSt[j - 1]->getSurname(), pSt[j]->getSurname()) > 0)
					swap(pSt[j], pSt[j - 1]);

	cout << "The book has sorted.\n";
	system("pause");
}

void AcademyGroup::EditStudent()
{
	system("cls");
	if (!count)
	{
		cout << "The book is empty.\n";
		return;
	}
	char surname[20];
	cout << "Enter surname of the student you`d like to edit: ";
	cin >> surname;
	if (!Check(surname))
		cout << "Student was not found.\n";
	else
	{
		char name[20];
		char sur[20];
		int age;
		char phone[15];
		double raiting;
		cout << "Enter a name: ";
		cin >> name;
		cout << "Enter a surname: ";
		cin >> sur;
		cout << "Enter an age: ";
		cin >> age;
		cout << "Enter a phone number: ";
		cin >> phone;
		cout << "Enter an average: ";
		cin >> raiting;
		
		for (int i = 0; i < count; i++)
		{
			if (!strcmp(surname, pSt[i]->getSurname()))
			{
				pSt[i]->setName(name);
				pSt[i]->setSurname(sur);
				pSt[i]->setAge(age);
				pSt[i]->setPhone(phone);
				pSt[i]->setRating(raiting);
			}
		}
	}
	
	system("pause");
}

void AcademyGroup::FindStudent()
{
	system("cls");
	if (!count)
	{
		cout << "The book is empty.\n";
		return;
	}
	char surname[20];
	cout << "Enter surname of the student you`d like to find: ";
	cin >> surname;
	if (!Check(surname))
		cout << "Student was not found.\n";
	else
	{
		for (int i = 0; i < count; i++)
			if (!strcmp(surname, pSt[i]->getSurname()))
				cout << *pSt[i];
	}
	system("pause");
}

void AcademyGroup::Save()
{
	FILE* f = nullptr;
	fopen_s(&f, "Student book.txt", "wb");
	if (!f)
	{
		perror("Error");
		return;
	}
	fwrite(&count, sizeof(int), 1, f);
	
	for (int i = 0; i < count; i++)
	{
		
		int size = strlen(pSt[i]->getName()) + 1;
		fwrite(&size, sizeof(int), 1, f);
		fwrite(pSt[i]->getName(), size, 1, f);

		int size1 = strlen(pSt[i]->getSurname()) + 1;
		fwrite(&size1, sizeof(int), 1, f);
		fwrite(pSt[i]->getSurname(), size1, 1, f);

		int age = pSt[i]->getAge();
		fwrite(&age, sizeof(age), 1, f);

		char phone[15];
		strcpy_s(phone, 15, pSt[i]->getPhone());
		fwrite(phone, sizeof(phone), 1, f);

		double raiting = pSt[i]->getRating();
		fwrite(&raiting, sizeof(double), 1, f);
		
	}

	fclose(f);
	cout << "Data of student has saved in file.\n";
	system("pause");
}

void AcademyGroup::Load()
{
	system("cls");
	FILE* f = nullptr;
	fopen_s(&f, "Student book.txt", "rb");
	if (!f)
	{
		perror("Error");
		return;
	}
	int amount;
	fread(&amount, sizeof(int), 1, f);
	count = amount;
	pSt = new Student * [count];

	for (int i = 0; i < amount; i++)
	{
		int size;
		fread(&size, sizeof(int), 1, f);
		char name[20];
		fread(name,  sizeof(char), size, f);

		int size1;
		fread(&size1, sizeof(int), 1, f);
		char surname[20];
		fread(surname, sizeof(char), size1, f);

		int age;
		fread(&age, sizeof(int), 1, f);

		char phone[15];
		fread(phone, sizeof(char), 15, f);

		double average;
		fread(&average, sizeof(double), 1, f);

		Student* temp = new Student(name, surname, age, phone, average);
		pSt[i] = temp;
	}
	fclose(f);
	system("pause");
}

AcademyGroup& AcademyGroup::operator=(const AcademyGroup& obj)
{
	if (this == &obj)
	{
		cout << "You tried to do self-appropriation!" << endl;
		return *this;
	}
	for (int i = 0; i < count; i++)
		delete pSt[i];
	delete[]pSt;

	count = obj.count;
	pSt = new Student * [count];
	for (int i = 0; i < count; i++)
		pSt[i] = new Student(*(obj.pSt[i]));
	
	return *this;
}

AcademyGroup& AcademyGroup::operator=(AcademyGroup&& obj)
{
	if (this == &obj)
	{
		cout << "You tried to do self-appropriation!" << endl;
		return *this;
	}
	
	for (int i = 0; i < count; i++)
		delete pSt[i];
	delete[]pSt;

	count = obj.count;
	pSt = obj.pSt;

	obj.pSt = nullptr;
	obj.count = 0;

	return *this;
}

Student& AcademyGroup::operator[](int index)
{
	assert(index >= 0 && index < count);
	return *pSt[index];
}

void AcademyGroup::Print()
{
	system("cls");
	if (!count)
		cout << "The book is empty.\n";
	for (int i = 0; i < count; i++)
		cout << *pSt[i];
	
	system("pause");
}

void AcademyGroup::AddStudents()
{
	system("cls");
	cout << "Enter a quantity of elements to add: ";
	int n;
	cin >> n;
	Student** temp = new Student * [count += n];
	for (int i = 0; i < count - n; i++)
		temp[i] = pSt[i];
	
	delete[]pSt;
	pSt = temp;
	for (int i = count - n; i < count; i++)
	{
		Student* t = new Student;
		cin >> *t;
		pSt[i] = t;
	}
}

void AcademyGroup::DeleteStudent()
{
	system("cls");
	if (!count)
	{
		cout << "The book is empty.\n";
		return;
	}
	char surname[20];
	cout << "Enter surname of student you`d like to delete: ";
	cin >> surname;
	if (!Check(surname))
		cout << "Student was not found.\n";
	else
	{
		int index;
		for (int i = 0; i < count; i++)
		{
			if (strcmp(surname, pSt[i]->getSurname()) == 0)
				index = i;
		}

		Student** temp = new Student * [--count];
		for (int i = 0; i < count + 1; i++)
			index > i ? temp[i] = pSt[i] : temp[i] = pSt[i + 1];
					
		delete pSt[index];
		delete[]pSt;
		pSt = temp;
		cout << "Student has deleted.\n";
	}
	
	system("pause");
}

ostream& operator << (ostream& cout, AcademyGroup& a)
{
	for (int i = 0; i < a.count; i++)
		cout << *(a.pSt[i]);

	return cout;
}