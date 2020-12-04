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

class Storage {
public:
    Human** objects;
    Storage() {}
    ~Storage(){}

    void initialisat(int count) {
        objects = new Human * [count];
        for (int i = 0; i < count; ++i)
            objects[i] = NULL;
    }

    void add_object(int index, Human* object) {
        objects[index] = object;
    }

    void delete_object(int index) {
        delete objects[index];
        objects[index] = NULL;

    }

    void method(int index) {
        objects[index]->about_me();

    }

    bool check_empty(int index) {
        if (objects[index] == NULL)
            return true;
        else return false;
    }

    void appeal_all(int n) {
        for (int i = 0; i < n; ++i) {
            printf("[%d] место ", i);
            if (check_empty(i))
                printf("Пустое\n");
            else method(i);
        }
    }

    int occupied(int size) {
        int count_occupied = 0;
        for (int i = 0; i < size; ++i)
            if (!check_empty(i))
                ++count_occupied;
        return count_occupied;
    }
};

int main()
{


}
