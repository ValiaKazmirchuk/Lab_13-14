// Lab_13-14.cpp : Створити лінійний двозв’язний список з цілих чисел. Вставити в список останній
// парний елемент після кожного непарного елемента.//

#include <iostream>
#include <list>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    list<int> List = { 3, 4, 7, 10, 9, 3, 7, 8, 8, 5, 4, 6 }; 

    cout << "Початковий список: ";
    for (int num : List) {
        cout << num << " ";
    }
    cout << endl;

    // Знаходимо останній парний елемент
    int lastElem = -1;
    for (int num : List) {
        if (num % 2 == 0) {
            lastElem = num;
        }
    }

    if (lastElem == -1) {
        cout << "У списку немає парних елементів. Операція не виконується." << endl;
        return 0;
    }

    // Вставка останнього парного елемента після кожного непарного
    for (auto it = List.begin(); it != List.end(); ++it) {
        if (*it % 2 != 0) {
            ++it; 
            List.insert(it, lastElem); 
            --it; 
        }
    }

    cout << "Змінений список:   ";
    for (int num : List) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}