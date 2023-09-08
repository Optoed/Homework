// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

//#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

//специальный тип данных, чтобы узнать - правильно ли создан объект класса или нет
enum StatusEr
{
	Err, OK
};

//Описание класса Кошки
class Fish
{
public:
	Fish(int weight, int age, bool gender, bool predatory, string habitat, string KPFC, int cost, bool poisonous); // конструктор - задаем породу, цвет, вес и год рождения, сделать надо при создании, 
											  // так как считаем, что не может быть кошка с пустой породой, бесцветная, с нулевым весом и без возраста
	Fish() { Status = Err; }				  // конструктор по умолчанию - добавляется для работы с указателями - нужен только для создания динамического объекта, 
											  // поэтому не может использовать в других случаях!
	~Fish();
//геттеры/селекторы - узнать значение атрибута (поля, характеристики объекта)
	string getPoroda();
	int getYearBirth();
	int getVes();
	string getColor();
	string getName();
// специальный
	bool getStatus(); //прежде чем начать работу с кошкой - узнать, а можно ли с ней работать
//сеттеры/модификаторы - установить (изменить) значение атрибута (поля, характеристики объекта), если это разрешено
	bool setUpVes(int v); //кошка может увеличить вес
	bool setDownVes(int v); //кошка может уменьшить вес
	bool setName(string nm); //кошка дали имя, или изменили его
//действия
	void Go();    // кошка идет
	void Voice(); // кошка мяукает 
	void Print(); //вывод информации о конкретном объекте, в дальнейшем лучше заменить на перегрузку операторов вывода!

private:
	string Poroda;
	int YearBirth;
	int Ves;
	string Color;
	string Name;
	int Status; //а можно ли с кошкой работать, или есть неверно определенные параметры

	bool ChangeVes(int v); //служебный метод класса, недоступен извне! Сделан для того, чтобы единым образом проверять на допустимость попытку изменить вес кошки
};

//реализация
Fish::Fish(string p, string cl, int v, int yb)
{
	if (p == "" || cl == "" || v <= 0 || yb <= 0) //заданы недопустимые значения полей - объект будет создан со статусом ошибка, чтобы нельзя было его использовать
		Status = Err;
	else {
		Poroda = p;
		YearBirth = yb;
		Ves = v;
		Color = cl;
		Name = "Безымянный кот";
		Status = OK; // всё в порядке, кошка создана
	}
}

Fish::~Fish()
{
}

string Fish::getPoroda()
{
	if (Status == OK) return Poroda;
	else return "";
}

int Fish::getYearBirth()
{
	if (Status == OK) return YearBirth;
	else return 0;
}

int Fish::getVes()
{
	if (Status == OK) return Ves;
	else return 0;
}

string Fish::getColor() 
{
	if (Status == OK) return Color;
	else return "";
}

string Fish::getName()
{
	if (Status == OK) return Name;
	else return "";
}

bool Fish::getStatus()
{
	return Status;
}


bool Fish::ChangeVes(int v)
{
	int tmpV = Ves + v;
	bool result = (tmpV >= 0); //не может у кошки быть отрицательный вес
	if (result) Ves = tmpV; // вес остался положительным и изменился на величину v
	return result; // вес не изменится, а метод вернет ложь
}

bool Fish::setUpVes(int v) //кошка может увеличить вес
{
	if (Status == OK)
		if (v <= 0) //отсекаем возможность ввести отрицательный шаг изменения веса, в противном случае можно вместо увеличения веса получить его уменьшение
			return false;
		else return ChangeVes(v);
	else false;
}

bool Fish::setDownVes(int v) //кошка может уменьшить вес
{
	if (Status == OK) 
		if (v <= 0) //отсекаем возможность ввести отрицательный шаг изменения веса, в противном случае можно вместо уменьшенияя веса получить его увеличение
			return false;
		else return ChangeVes(-v);
	else false;
}

bool Fish::setName(string nm) //кошка дали имя, или изменили его
{
	if (Status == OK)
		if (nm  == "")   // нельзя дать кошке пустое имя
			return false;
		else { 
			Name = nm;
			return true;
		}
	else false;
}

void Fish::Go()    // кошка идет. Ходить может только правильная кошка (та, которая создана)
{
	if (Status == OK) {
		cout << Name.c_str() << " пошел гулять\n";
		cout << "@  \n";
		cout << "   @\n";
		cout << "@  \n";
		cout << "   @\n";
	}
}

void Fish::Voice() // кошка мяукает. Мяукать может только правильная кошка (та, которая создана)
{
	if (Status == OK) {
		cout << Name.c_str() <<" сказал " << "M-r-r-r!\n";
	}
}

void Fish::Print() // вывод информации о конкретном объекте класса Кошка. Вывести можно информацию только о правильной кошке
{
	if (Status == OK) {
		cout << "\nЭкземпляр класса Кошки: " << "Имя - " << Fish::getName() << ", порода - " << Poroda.c_str() << ",\n";
		cout << "год рождения - " << YearBirth << ", вес - " << Ves << ".\n";
		cout << "Ах да, и цвет шёрстки - " << Color.c_str() << "\n\n";
	}
}

int main()
{
	bool check = false;
	cout << check << endl << endl;

	setlocale(LC_ALL, "Russian");
	//неправильно созданная кошка
	cout << "Создать 1-й объект кошка и поработать с ней\n"; 
	Fish Cat1("sdsd", "sdsd", -2, 2016); // создаем экземпляр класса Кошка, на задаем неверное значение вес
	//пытаемся с ней поработать
	cout << Cat1.getStatus() << endl;
		Cat1.setName("Барсик");
		Cat1.getVes();
		Cat1.Print();
		Cat1.Voice();
		Cat1.Go();
		if (Cat1.setDownVes(-5))
			cout << Cat1.getName().c_str() << " похудел на " << Cat1.getVes() << " кг. \n";
		else cout << "Ошибка ввода при уменьшении веса кота " << Cat1.getName().c_str() << "!\n";

	
	
	cout << "\nСоздать 2-й объект кошка и поработать с ней\n"; // создаем экземпляр класса Кошка
	Fish Cat2("Перс", "Белый", 2, 2015);

		Cat2.setName("Мурзик");
		Cat2.Print();
		Cat2.Voice();
		Cat2.Go();
		int StepV; //шаг изменения веса

		StepV = -1; //посадили на диету, но не правильно
		if (Cat2.setDownVes(StepV))
			cout << Cat2.getName().c_str() << " похудел на " << Cat2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при уменьшении веса кота "<< Cat2.getName().c_str() << "!\n";
		StepV = 1;//посадили на диету правильно
		if (Cat2.setDownVes(StepV))
			cout << Cat2.getName().c_str() << " похудел на " << Cat2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при уменьшении веса кота " << Cat2.getName().c_str() << "!\n";

		StepV = -1; // стали кормить, но не правильно
		if (Cat2.setUpVes(StepV))
			cout << Cat2.getName().c_str() << " поправился на " << Cat2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при увеличении веса кота " << Cat2.getName().c_str() << "!\n";
		StepV = 1; //кормят правильно
		if (Cat2.setUpVes(StepV))
			cout << Cat2.getName().c_str() << " поправился на " << Cat2.getVes() << " кг. \n";
		else cout << "Ошибка ввода при увеличении веса кота " << Cat2.getName().c_str() << "!\n";


	cout << "\nСоздать 3-й объект кошка и поработать с ней\n"; // создаем экземпляр класса Кошка
	Fish Cat3("Сиамка", "Серая", 3, 2001);

	Cat3.Print();

	//А теперь все кошки будут что-то делать вместе!
	cout << "\n\n А теперь все кошки будут что-то делать вместе!\n\n";
	Fish* lFish;
	lFish = new Fish[3];
	
	lFish[0] = Cat1;
	lFish[1] = Cat2;
	lFish[2] = Cat3;

	for (int i = 0; i < 3; i++)  
		{
			lFish[i].Voice();
			lFish[i].Go();
		}

	system("pause");
    return 0;
}

