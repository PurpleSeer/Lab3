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
    ~Storage(){} //деструктор

    void initialisat(int count) { //инициализация объекта
        objects = new Human * [count];
        for (int i = 0; i < count; ++i)
            objects[i] = NULL;
    }

    void add_object(int index, Human* object) { //добавление объекта
        objects[index] = object;
    }

    void delete_object(int index) { //удаление объекта
        delete objects[index];
        objects[index] = NULL;
    }

    void method(int index) { //вывод иформации об объекте
        objects[index]->about_me();
    }

    bool check_empty(int index) { //проверка на пустую ячейку
        if (objects[index] == NULL)
            return true;
        else return false;
    }

    void appeal_all(int n) { //вывод информации об объекте,если ячейка не пуста
        for (int i = 0; i < n; ++i) {
            printf("[%d] место ", i);
            if (check_empty(i))
                printf("Пустое\n");
            else method(i);
        }
    }

    int occupied(int size) { //подсчет занятых ячеек хранилища
        int count_occupied = 0;
        for (int i = 0; i < size; ++i)
            if (!check_empty(i))
                ++count_occupied;
        return count_occupied;
    }
};

Human* random_object(int variant) {
    switch (variant) {
    case 1:
        return new Student;
    case 2:
        return new Teacher;
    }
}

void doublesize(Storage& storage, int& size) // Функция для увеличения кол-ва элементов в хранилище в 2 раза
{
    Storage storage1;
    storage1.initialisat(size * 2);
    for (int i = 0; i < size; ++i)
        storage1.objects[i] = storage.objects[i];
    for (int i = size; i < (size * 2) - 1; ++i)
        storage1.objects[i] = NULL;
    size = size * 2;
    storage.initialisat(size);
    for (int i = 0; i < size; ++i)
        storage.objects[i] = storage1.objects[i];
}

int main()
{
    setlocale(0, "");
    Storage storage;
    srand(time(0));
    string text = " ";
    int n = 100; // Кол-во операций
    int count = 10; // Кол-во элементов
    storage.initialisat(count);

again:
    unsigned int start_time = clock();
    for (int i = 0; i < n; ++i) {
        int act = rand() % count; // Выбираем с каким объектом взаимодействуем
        int vibor = 1 + rand() % 3; // Выбираем какое действие произойдёт с выбранным объектом
        int k = 1 + rand() % 2;
        printf("[%d]", i + 1);
        switch (vibor) {
        case 1:
        again_add:
            if (storage.check_empty(act)) { // Если место свободно, то добавляем объект
                if (k == 1) {
                    text = "Student";
                }
                else text = "Teacher";
                printf(" Добавили в [%i] место хранилища объект класса %s\n", act, text.c_str());
                storage.add_object(act, random_object(k));
            }
            else
            {
                if (storage.occupied(count) == count)
                {
                    printf(" Хранилище полностью заполнено, увеличиваем кол-во элементов в хранилище в 2 раза\n");
                    doublesize(storage, count);
                }
                printf(" [%i] место хранилища занято, ищем свободное место в хранилище\n", act);
                while (storage.objects[act] != NULL)
                    act = (act + 1) % count;
                goto again_add;
            }
            break;
        case 2:
            if (!storage.check_empty(act)) { // Если место занято, то удаляем объект
                printf(" Освободили [%i] место хранилища\n", act);
                storage.delete_object(act);
            }
            else printf(" [%i] место хранилища пустое, освободить место в хранилище невозможно\n", act);
            break;
        case 3:
            if (!storage.check_empty(act)) { // Если место занято, то вызываем метод у объекта
                printf(" Запуск метода about_me() у [%i] объекта из хранилища\n", act);
                storage.method(act);
            }
            else printf(" [%i] место хранилища пустое, вызвать метод невозможно\n", act);
            break;
        }
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "\n" << "Время работы = " << search_time / 1000.0 << "сек" << endl;
    cout << "Общее кол-во занятых ячеек хранилища = " << storage.occupied(count) << endl;
    cout << "\n" << "Вы хотите посмотреть всё хранилище? 1 - Да, 2 - Нет : ";
    int a;
    cin >> a;
    if (a == 1) {
        storage.appeal_all(count);
    }
    cout << "Напишите сколько случайных операций выполнить : ";
    cin >> n;
    goto again;
}

