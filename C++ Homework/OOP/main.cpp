/* main.cpp */
#include <iostream>
#include "students.h"

int main()
{
    // �������� ������� ������ Student
    Students student;

    std::string name;
    std::string last_name;

    // ���� ����� � ����������
    std::cout << "Name: ";
    getline(std::cin, name);

    // ���� �������
    std::cout << "Last name: ";
    getline(std::cin, last_name);

    // ���������� ����� � ������� � ������ ������ Students
    student.set_name(name);
    student.set_last_name(last_name);

    // ������
    int scores[5];
    // ����� ���� ������
    int sum = 0;

    // ���� ������������� ������ 
    for (int i = 0; i < 5; ++i) {
        std::cout << "Score " << i + 1 << ": ";
        std::cin >> scores[i];
        // ������������
        sum += scores[i];
    }

    // ��������� ������������� ������ � ������ ������ Student
    student.set_scores(scores);
    // ������� ������� ����
    float average_ball = sum / 5.0;
    // ��������� ������� ���� � ������ ������ Students
    student.set_average_ball(average_ball);
    // ������� ������ �� ��������
    std::cout << "Average ball for " << student.get_name() << " "
        << student.get_last_name() << " is "
        << student.get_average_ball() << std::endl;

    return 0;
}