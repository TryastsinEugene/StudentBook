#include "Student.h"
#include<iomanip>
#include<string>
using namespace std;

Student::Student()
{
	memset(phone, 0, 15);
	raiting = 0;
}

Student::Student(const char* name, const char* surname, const int age, const char* phone, double raiting)
	:Person(name, surname, age)
{
	strcpy_s(this->phone, 15, phone);
	this->raiting = raiting;
}

void Student::Print()const
{
	Person::Print();
	printf("%s\n%lf\n", phone, raiting);
}

Student::Student(const Student& obj):Person(obj)
{
	memset(this->phone, 0, 15);
	raiting = 0;
	strcpy_s(phone, 15, obj.phone);
	raiting = obj.raiting;
}

Student::Student(Student&& obj):Person((Person&&)obj)
{
	strcpy_s(phone, 15, obj.phone);
	raiting = obj.raiting;
	memset(obj.phone, 0, 15);
	obj.raiting = 0;
}

double Student::getRating() const { return raiting; }

const char* Student::getPhone() const { return phone; }

void Student::setPhone(const char* phone)
{
	strcpy_s(this->phone, 15, phone);
}

void Student::setRating(double average)
{
	raiting = average;
}

Student& Student::operator=(const Student& obj)
{
 	if (this == &obj)
	{
		cout << "Self-appropirate.\n";
		return *this;
	}
	Person::operator=(obj);
	strcpy_s(phone, 15, obj.phone);
	raiting = obj.raiting;

	return *this;
}

Student& Student::operator=(Student&& obj)
{
	if (this == &obj)
	{
		cout << "Self-appropirate.\n";
		return *this;
	}
	Person::operator=((Person&&)obj);
	strcpy_s(phone, 15, obj.phone);
	raiting = obj.raiting;
	memset(phone, 0, 15);
	obj.raiting = 0;

	return *this;
}

istream& operator >> (istream& cin, Student& s)
{
	char temp[50];
	cout << "Enter a name: ";
	cin >> temp;
	s.setName(temp);
	cout << "Enter a surname: ";
	cin >> temp;
	s.setSurname(temp);
	cout << "Enter an age: ";
	cin >> s.age;
	cout << "Enter a phone number: ";
	cin >> s.phone;
	cout << "Enter an average: ";
	cin >> s.raiting;

	return cin;
}

ostream& operator<<(ostream& cout, const Student& obj)
{
     cout <<  "\nSurname:\t" << "\t\t" << obj.surname
		<<  "\nName:\t" << "\t\t\t" << obj.name
		<<  "\nAge:\t" "\t\t\t" << obj.age 
		<<"\nPhone number:\t" <<  "\t\t" << obj.phone 
		<< "\nAverage:\t" << "\t\t" << obj.raiting <<endl;

	return cout;
}





