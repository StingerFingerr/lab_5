//Лабараторная работа №5 по предмету ООП студента группы 924401, Мартиновича Алексея
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class person {//абстрактный базовый класс
protected:
	string name;
	int age;
public:
	virtual string print() = 0;//чисто виртаульные функции
	virtual void change_info() = 0;
};

class student :public person {
protected:
	string spec;
	long group;
public:
	student(string n, int a, string s, long g){
		name = n;
		age = a;
		spec = s;
		group = g;
	}
	string print() {
		return "\nИмя: " + name + "\nВозраст: " + to_string(age) + "\nСпециальность: " + spec + "\nНомер группы: " + to_string(group);
	}
	void change_info() {
		cout << "\n\nВведите новую инфу:\nИмя: ";
		cin >> name;
		cout << "Возраст: ";
		cin >> age;
		cout << "Специальность: ";
		cin >> spec;
		cout << "Номер группы: ";
		cin >> group;
	}
};
class gradstudent :public student {
protected:
	string grade;
public:
	gradstudent(string n, int a, string s, long g, string gr) :student(n, a, s, g) {
		grade = gr;
	}
	string print() {
		return "\nИмя: " + name + "\nВозраст: " + to_string(age) + "\nСпециальность: " + spec + "\nНомер группы: " + to_string(group) + "\nУченая степень: " + grade;
	}
	void change_info() {
		cout << "\n\nВведите новую инфу:\nИмя: ";
		cin >> name;
		cout << "Возраст: ";
		cin >> age;
		cout << "Специальность: ";
		cin >> spec;
		cout << "Номер группы: ";
		cin >> group;
		cout << "Ученая степень: ";
		cin >> grade;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	person* ptrPerson;
	student Student("Aleksey",18,"Game Dev",924401);
	ptrPerson = &Student;
	cout << ptrPerson->print();
	ptrPerson->change_info();
	cout << ptrPerson->print();
	gradstudent Gradstudent("Name", 25, "Speciality", 1234567, "Grade.");
	ptrPerson = &Gradstudent;
	cout << ptrPerson->print();
	ptrPerson->change_info();
	cout << ptrPerson->print();
	return 0;
}
