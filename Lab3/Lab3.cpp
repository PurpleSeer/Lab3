#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Human {
protected:
    string name;
    int age;
    int weight;
public:
    Human() {
        name = "~";
        age = 0;
        weight = 0;
    }
    Human(string name, int age, int weight) {
        this->name = name;
        this->age = age;
        this->weight = weight;
    }
    Human(const Human& h) {
        name = h.name;
        age = h.age;
        weight = h.weight;
    }
    ~Human() {}

    virtual void about_me() {
        cout << "Меня зовут "<< name.c_str()<< " мне "<< age <<" лет и я вешу "<< weight<< " кг.\n";
    }
};

class Student : public Human {
protected:
    int mark;
public:
    Student() {
        mark = 5;
    }
    Student(int mark) {
        this->mark - mark;
    }
    Student(const Student& s) {
        mark = s.mark;
    }
    ~Student() {}

    virtual void about_me() {
        cout << "Я студент " << name.c_str() << ", и имею средний бал " << mark << " за второй семестр\n";
    }
};

class Teacher :public Human {
protected:
    int work_experience;
public:
    Teacher() {
        work_experience = 5;
    }
    Teacher(int work_experience) {
        this->work_experience = work_experience;
    }
    Teacher(const Teacher& t) {
        work_experience = t.work_experience;
    }
    ~Teacher(){}

    virtual void about_me() {
        cout<< "Меня зовут " << name.c_str() << " и я преподаю программирование уже " <<work_experience<< " лет.\n";
    }
};

int main()
{


}
