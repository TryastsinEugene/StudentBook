#include"Person.h"
#include"Student.h"
#include"AcademyGroup.h"
#include<conio.h>

void PrintMenu()
{
	char Menu[] = "1.Add students\n2.Delete student\n3.Print\n4.Search student\n5.Edit student\n6.Save in File\n7.Load\n8.Sort\n9.Exit\n";
	system("cls");
	cout << Menu;
}

int main()
{
	AcademyGroup obj;
	obj.AddStudents();
	system("pause");
	while (true)
	{
		PrintMenu();
		char res = _getch();
		switch (res)
		{
		case '1': obj.AddStudents();
			break;
		case '2': obj.DeleteStudent();
			break;
		case '3':obj.Print();
			break;
		case '4':obj.FindStudent();
			break;
		case '5':obj.EditStudent();
			break;
		case'6': obj.Save();
			break;
		case'7': obj.Load();
			break;
		case'8':obj.Sort();
			break;
		case '9':
			return 0;
		}
	}
   
	return 0;
	
}