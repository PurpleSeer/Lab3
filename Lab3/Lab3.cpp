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

int main()
{


}
