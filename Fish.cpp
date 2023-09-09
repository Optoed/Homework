//Made by Optoed.
//All rights reserved © 


//Сюжет: 
//Мы, как истинные гастрономические гении, любим готовить и пробовать новые изысканные блюда. В очередной раз, придя в наш любимый дорогущий магазин, мы узнаём,
//что до конца года в этом магазине (а в другие мы ходить не хотим) будет продаваться только рыба (живая или уже не особо).
//Ах да, чуть не забыл, рыба может оказаться просроченной (и станет ядовитой), либо изначально была ядовитой... Удачи)

//#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

#define endl '\n'
#define see(x) cout << (#x) << " = " << x << endl

struct KPFC { //это КБЖУ рыбы))
	double kilocalories;
	double proteins;
	double fats;
	double carbohydrates;
};

//enum StatusEr //специальный тип данных, чтобы узнать - правильно ли создан объект класса или нет
//{
//	Err, OK //поменял местами для удобства, чтобы Err = 0 (как будто false) и OK = 1 (как будто true)
//};


class Fish //Описание класса Рыбы
{
public:

	Fish(bool FISH_IS_BOUGHT, double weight_in_kilo, bool alive, int shelf_life, bool poisonous, int cost_per_kilo, KPFC kpfc, int cooking_time);  //string name, string gender, string habitat, string predatory - решил убрать
	// конструктор - задаем пол, место обитания, хищность, вес, возраст (и срок годности), ядовитость, стоимость в магазине, КБЖУ, время готовки - заполняем при создании
	// так как считаем, что рыба не может быть "инкогнито" без данных
	Fish() { Status = false };				  // конструктор по умолчанию - добавляется для работы с указателями - нужен только для создания динамического объекта, 
	// поэтому не может использовать в других случаях!
	~Fish();
	//геттеры/селекторы - узнать значение атрибута (поля, характеристики объекта)
	bool getFish_is_Bought();  //Если не указано, значит по умолчанию НЕ куплена
	double getWeight_in_kilo();
	int getShelf_life();
	bool getPoisonous();   //если не указано, значит по умолчанию НЕ ядовита
	bool getAlive();		//если не указано, значит по умолчанию НЕ жива
	int getCost_per_kilo();
	KPFC getKpfc();
	int getCooking_time();
	// специальный
	bool getStatus(); //прежде чем начать работу с рыбой - узнать, а можно ли с ней работать

	//сеттеры/модификаторы - установить (изменить) значение атрибута (поля, характеристики объекта), если это разрешено
	int setShelf_life(int days); //если подождать несколько (n) дней, то количество дней до истечения срока годности уменьшится на n
	//string setName(string name); //Мы можем дать имя своей рыбе (..а потом её съесть)

	//действия рыбы
	void DoNothing();  // рыба может ничего не делать
	void PlayDead();   // рыба может притвориться мёртвой и попытаться нас обмануть

	//наши действия с этой рыбой
	void Buy_fish(); //купить
	void Kill_fish(); //ну...
	void Cook_and_Eat_fish(); //приготовить и съесть
	void FishLivesMatter(); //освободить рыбу

private:

	bool FISH_IS_BOUGHT;
	double weight_in_kilo;
	bool alive;
	int shelf_life;
	bool poisonous;
	int cost_per_kilo;
	KPFC kpfc;
	int cooking_time;

	bool Status; //а можно ли с рыбой работать, или есть неверно определенные параметры (не все, а только важные для нас, как для покупателя, а именно:
	//weight_in_kilo, alive, shelf_life, poisonous (но в моменте мы про это не знаем), cost_per_kilo, kpfc, cooking_time)

	bool setAlive();  //Если рыба была живой, то мы можем это изменить..
	bool setStatus(); //поменять статус на Err, если мы её съели или отпустили на волю..
	bool setFish_is_Bought(); //Если она не была куплена, то купив её, мы изменим это значение
};

//реализация
Fish::Fish(bool fb, double wik, bool a, int sl, bool p, int cpk, KPFC kk, int ct)
{
	if (wik <= 0.0 || cpk <= 0 || ct <= 0 || kk.kilocalories <= 0.0 || kk.proteins <= 0.0 || kk.fats <= 0.0 || kk.carbohydrates < 0.0 || (a == true && sl <= 0))
		//заданы недопустимые значения полей - объект будет создан со статусом ошибка, чтобы нельзя было его использовать
		Status = false;
	
	else {
		FISH_IS_BOUGHT = fb;
		weight_in_kilo = wik;
		alive = a;
		poisonous = p;
		shelf_life = sl;
		if (shelf_life <= 0) {  //если срок годности оказался просроченным, то съев рыбу, мы отравимся
			poisonous = true;
		}
		cost_per_kilo = cpk;
		kpfc = kk;
		cooking_time = ct;
		Status = true; // всё в порядке, рыба создана
	}
}

Fish::~Fish()
{
}

bool Fish::getFish_is_Bought()
{
	if (Status) {
		return FISH_IS_BOUGHT;
	}
	else {
		return false;
	}
}

double Fish::getWeight_in_kilo() {
	if (Status) {
		return weight_in_kilo;
	}
	return 0;
}

int Fish::getShelf_life() {
	if (Status) {
		return shelf_life;
	}
	return 0;
}

bool Fish::getPoisonous() {
	if (Status) {
		return poisonous;
	}
	return false;
}

bool Fish::getAlive() {
	if (Status) {
		return alive;
	}
	return false;
}

int Fish::getCost_per_kilo() {
	if (Status) {
		return cost_per_kilo;
	}
	return 0;
}

KPFC Fish::getKpfc() {
	if (Status) {
		return kpfc;
	}
	return { 0.0, 0.0, 0.0, 0.0 };
}

int Fish::getCooking_time() {
	if (Status) {
		return cooking_time;
	}
	return 0;
}

bool Fish::getStatus()
{
	return Status;
}

int Fish::setShelf_life(int days) {//если подождать несколько (n) дней, то количество дней до истечения срока годности уменьшится на n
	if (Status) {
		if (!getAlive()) { //пока жива, срок годности не истекает
			shelf_life -= abs(days);
			if (shelf_life <= 0) { //стала ядовитой, тк срок годности истёк
				poisonous = true;
			}
		}
		return shelf_life;
	}
	return 0;
} 

void Fish::DoNothing() {
	if (Status) {
		if (getAlive) {
			cout << "Рыба профессионально ничего не делает...\n";
		}
		else {
			cout << "У рыбы неплохо получается ничего не делать (учитывая, что она вроде как не жива)\n";
		}
	}
}

void Fish::PlayDead() {
	if (Status) {
		if (getAlive) {
			cout << "Рыба притворилась мёртвой в надежде, что это ей поможет (нет)\n";
		}
		else {
			cout << "Рыба крайне натурально.. кхм притворилась мёртвой\n";
		}
	}
}

void Fish::Buy_fish() {
	if (Status) {
		if (FISH_IS_BOUGHT == true) {
			cout << "Рыба уже куплена\n";
		}
		else {
			cout << "Мы покупаем эту рыбку и отдаем за неё свои кровные " << weight_in_kilo * cost_per_kilo << " рублей\n";
			FISH_IS_BOUGHT = true;
		}
	}
}

void Fish::Kill_fish() {
	if (Status) {
		if (alive) {
			cout << "Рыба отправилась к праотцам\n";
			alive = false;
		}
		else {
			cout << "Рыба уже была НЕживой\n";
		}
	}
}

void Fish::Cook_and_Eat_fish() {
	if (Status) {
		if (alive) {
			cout << "Мы не станем кушать рыбу заживо\n";
		}
		else {
			cout << "На приготовление рыбы уйдёт " << cooking_time << " минут\n";
			cout << "Блюдо будет содержать: " << kpfc.carbohydrates * weight_in_kilo / 10 << " килокалорий,\n"
				<< kpfc.proteins * weight_in_kilo / 10 << " белка,\n"
				<< kpfc.fats * weight_in_kilo / 10 << " жиров и\n"
				<< kpfc.carbohydrates * weight_in_kilo / 10 << " углеводов\n";

			Status = false; //то есть рыба теперь нам не доступна, тк мы её съели

			if (poisonous) {
				if (shelf_life > 0) {
					cout << "Нам не повезло, рыба оказалась ядовита и мы отправились вместе с рыбой к праотцам\n";
				}
				else {
					cout << "Нам не повезло, рыба оказалась просроченной и мы отправились вместе с рыбой к праотцам\n";
				}
				//exit(0); //Наш главный герой умер, программа завершается
				//system("pause");
			}
			else {
				cout << "Нам повезло, рыба оказалась НЕ ядовитой и НЕ просроченной, и мы хорошо покушали\n";
			}
		}
	}
}

void Fish::FishLivesMatter() {
	if (Status) {
		if (alive) {
			cout << "Мы решили освободить рыбу, отвезли её в горпарк и выпустили в водоём\nHappy End!\n";
		}
		else {
			cout << "Мы настолько благородны, что решили свободить рыбу... Жаль, что она этого не оценит.\n";
		}
		Status = false;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp >> 0");

	//неправильно созданная рыба
	cout << "Создать 1-й объект fish1 и поработать с ней\n";
	// создаем экземпляр класса Fish (правильные данные) и пытаемся с ней поработать
	Fish fish1(false, 1.3, false, 7, false, 100, { 113.9, 13.5, 5.6, 1.3 }, 15);  
	//bool FISH_IS_BOUGHT, double weight_in_kilo, bool alive, int shelf_life, bool poisonous, int cost_per_kilo, KPFC kpfc, int cooking_time
	cout << "Данные о рыбе fish1:\n";
	see(fish1.getFish_is_Bought());
	see(fish1.getAlive());
	see(fish1.getCost_per_kilo());
	see(fish1.getKpfc().kilocalories);
	see(fish1.getKpfc().proteins);
	see(fish1.getKpfc().fats);
	see(fish1.getKpfc().carbohydrates);
	see(fish1.getPoisonous());
	see(fish1.getShelf_life());
	see(fish1.getStatus());
	see(fish1.getWeight_in_kilo());

	fish1.Buy_fish();
	fish1.Buy_fish();
	fish1.DoNothing();
	see(fish1.getFish_is_Bought());

	fish1.Cook_and_Eat_fish();
	fish1.PlayDead();
	fish1.Kill_fish();
	fish1.Kill_fish();
	fish1.PlayDead();
	see(fish1.getAlive());

	fish1.setShelf_life(5);
	see(fish1.getShelf_life());
	see(fish1.getPoisonous());

	fish1.Cook_and_Eat_fish();
	see(fish1.getStatus());
	fish1.FishLivesMatter();


	cout << "\nСоздать 2-й объект fish2 (неправильные данные) и поработать с ней\n"; // создаем экземпляр класса Fish
	Fish fish2(false, -1.3, false, 7, false, 100, { -113.9, 13.5, 5.6, 1.3 }, 15);
	cout << "Данные о рыбе fish1:\n";
	see(fish2.getFish_is_Bought());
	see(fish2.getAlive());
	see(fish2.getCost_per_kilo());
	see(fish2.getKpfc().kilocalories);
	see(fish2.getKpfc().proteins);
	see(fish2.getKpfc().fats);
	see(fish2.getKpfc().carbohydrates);
	see(fish2.getPoisonous());
	see(fish2.getShelf_life());
	see(fish2.getStatus());
	see(fish2.getWeight_in_kilo());

	fish2.Buy_fish();
	fish2.Buy_fish();
	fish2.DoNothing();
	see(fish2.getFish_is_Bought());

	fish2.Cook_and_Eat_fish();
	fish2.PlayDead();
	fish2.Kill_fish();
	fish2.Kill_fish();
	fish2.PlayDead();
	see(fish2.getAlive());

	fish2.setShelf_life(11);
	see(fish2.getShelf_life());
	see(fish2.getPoisonous());

	fish2.Cook_and_Eat_fish();
	see(fish2.getStatus());
	fish2.FishLivesMatter();



	Fish fish3(true, 1.3, true, 7, true, 1000, { 103.2, 16.2, 4.2, 1.1 }, 25);
	Fish fish4(true, 1.3, true, 7, true, 1000, { 103.2, 16.2, 4.2, 1.1 }, 25);
	Fish fish5(true, 1.3, true, 7, true, 1000, { 103.2, 16.2, 4.2, 1.1 }, 25);
	
	//Реализация холодильника - один массив, и магазин - другой массив. При создании (либо сами лично и выборочно) рыбы
	//помещаем её в один из векторов в зависимости
	//от FISH_IS_BOUGHT и дальше уже удаляем из магазина и добавляем в холодильник при покупке

	cout << "\n\n А теперь все кошки будут что-то делать вместе!\n\n";
	Fish* lFish;
	lFish = new Fish[3];

	lFish[0] = fish3;
	lFish[1] = fish4;
	lFish[2] = fish5;

	for (int i = 0; i < 3; i++)
	{
		lFish[i].Voice();
		lFish[i].Go();
	}

	system("pause");
	return 0;
}
