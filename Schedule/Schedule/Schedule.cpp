#include<iostream>
#include<string>
#include<vector>
#include<thread>

using namespace std;

vector<string> schedule[8];

void add_class(const string& class_name, const int& day) {
    schedule[day].push_back(class_name);
    cout << "Добавлен урок: " << class_name << " на день " << day << endl;
}

void remove_class(const string& class_name, const int& day) {
    for (auto it = schedule[day].begin(); it != schedule[day].end(); it++) {
        if (*it == class_name) {
            schedule[day].erase(it);
            cout << "Удален урок: " << class_name << " на день " << day << endl;
            return;
        }
    }
    cout << "Урок не найден.\n" << endl;
}

int main() {
    setlocale(LC_ALL,"Russian");
    string class_name;
    int day;
    int choice;
    std::cout << "---Расписание занятий---" << std::endl;

    while (true) {
        cout << "\n[1] Добавить урок" << endl;
        cout << "[2] Удалить урок" << endl;
        cout << "[3] Посмотреть расписание" << endl;
        cout << "[4] Выход\n" << endl;
        cout << "Введите выбор: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nВведите название урока: ";
            cin.ignore();
            getline(cin, class_name);
            cout << "\nВведите день (1-7): ";
            cin >> day;
            if (day >= 1 && day <= 7) {
                thread tadd_class(add_class, class_name, day);
                tadd_class.join();
            }
            else {
                cout << "\n[Ошибка] Введен неверный день!\n";
            }
        }
        if (choice == 2) {
            cout << "\nВведите название урока: ";
            cin.ignore();
            getline(cin, class_name);
            cout << "\nВведите день (1-7): ";
            cin >> day;
            if (day >= 1 && day <= 7) {
                thread tremove_class(remove_class, class_name, day);
                tremove_class.join();
            }
            else {
                cout << "\n[Ошибка] Введен неверный день!\n";
            }
        }
        if (choice == 3) {
            for (int i = 1; i < 8; i++) {
                cout << "\nДень " << i << ": ";
                for (auto class_name : schedule[i]) {
                    cout << class_name << " ";
                }
                cout << endl;
            }
        }
        if (choice == 4) {
            return 0;
        }
        else {
            cout << "\n[Ошибка] Неверное значение!\n" << endl;
        }
    }
    return 0;
}