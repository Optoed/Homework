#include <iostream>
using namespace std;

/* students.h */
#include <string>

class Students {
public:
    // ��������� ����� ��������
    void set_name(std::string student_name)
    {
        name = student_name;
    }
    // ��������� ����� ��������
    std::string get_name()
    {
        return name;
    }
    // ��������� ������� ��������
    void set_last_name(std::string student_last_name)
    {
        last_name = student_last_name;
    }
    // ��������� ������� ��������
    std::string get_last_name()
    {
        return last_name;
    }
    // ��������� ������������� ������
    void set_scores(int student_scores[])
    {
        for (int i = 0; i < 5; ++i) {
            scores[i] = student_scores[i];
        }
    }
    // ��������� �������� �����
    void set_average_ball(float ball)
    {
        average_ball = ball;
    }
    // ��������� �������� �����
    float get_average_ball()
    {
        return average_ball;
    }

private:
    // ������������� ������
    int scores[5];
    // ������� ����
    float average_ball;
    // ���
    std::string name;
    // �������
    std::string last_name;
};

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