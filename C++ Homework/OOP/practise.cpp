#include <iostream>
using namespace std;

/* students.h */
#include <string>

class Students {
public:
    // Установка имени студента
    void set_name(std::string student_name)
    {
        name = student_name;
    }
    // Получение имени студента
    std::string get_name()
    {
        return name;
    }
    // Установка фамилии студента
    void set_last_name(std::string student_last_name)
    {
        last_name = student_last_name;
    }
    // Получение фамилии студента
    std::string get_last_name()
    {
        return last_name;
    }
    // Установка промежуточных оценок
    void set_scores(int student_scores[])
    {
        for (int i = 0; i < 5; ++i) {
            scores[i] = student_scores[i];
        }
    }
    // Установка среднего балла
    void set_average_ball(float ball)
    {
        average_ball = ball;
    }
    // Получение среднего балла
    float get_average_ball()
    {
        return average_ball;
    }

private:
    // Промежуточные оценки
    int scores[5];
    // Средний балл
    float average_ball;
    // Имя
    std::string name;
    // Фамилия
    std::string last_name;
};

/* main.cpp */
#include <iostream>
#include "students.h"

int main()
{
    // Создание объекта класса Student
    Students student;

    std::string name;
    std::string last_name;

    // Ввод имени с клавиатуры
    std::cout << "Name: ";
    getline(std::cin, name);

    // Ввод фамилии
    std::cout << "Last name: ";
    getline(std::cin, last_name);

    // Сохранение имени и фамилии в объект класса Students
    student.set_name(name);
    student.set_last_name(last_name);

    // Оценки
    int scores[5];
    // Сумма всех оценок
    int sum = 0;

    // Ввод промежуточных оценок 
    for (int i = 0; i < 5; ++i) {
        std::cout << "Score " << i + 1 << ": ";
        std::cin >> scores[i];
        // суммирование
        sum += scores[i];
    }

    // Сохраняем промежуточные оценки в объект класса Student
    student.set_scores(scores);
    // Считаем средний балл
    float average_ball = sum / 5.0;
    // Сохраняем средний балл в объект класса Students
    student.set_average_ball(average_ball);
    // Выводим данные по студенту
    std::cout << "Average ball for " << student.get_name() << " "
        << student.get_last_name() << " is "
        << student.get_average_ball() << std::endl;

    return 0;
}