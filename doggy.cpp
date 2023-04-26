#pragma warning(disable:4996) // Очень важно - без этого strcat не работает.

#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>

using namespace std;

struct Dogs {
    char Name[20] = { " " };
    int Class = 0;
    char stepName[20] = { " " };
};

void Show(Dogs* dog, int length) {
    for (int i = 0; i < length; i++) {
        cout << "Dog: " << i + 1 << " ";
        cout << "Name: "; cout << dog[i].Name; cout << endl;
        cout << "Class: "; cout << dog[i].Class; cout << endl;
        cout << "StepName: "; cout << dog[i].stepName; cout << endl;
        cout << endl;
    }
}

void Bark() {
    cout << "Гав";
}

void Cinput(Dogs* dog, int chose) {
    cout << "Dog: " << chose << "\n";
    chose -= 1;
    cout << "Name: "; cin >> dog[chose].Name; cout << endl;
    cout << "Class(int): "; cin >> dog[chose].Class; cout << endl;
    cout << "StepName: "; cin >> dog[chose].stepName; cout << endl;
    cout << endl;
}

void Doggy(Dogs* dog, int length) {
    int chose; int c = 0;
    do {

        system("cls");
        cout << "\n1 - Заполнение объектов.\n2 - Вывод\n3 - Подать голос\n4 - Пополнить список Собак\n5 - Выход\n";
        cout << "\nВыберите действие: "; cin >> chose;

        switch (chose) {
        case 1:
            cout << "Информацию о какой собаке вы хотите заполнить ? 1 - " << length << "\n";
            cin >> c;
            Cinput(dog, c);
            break;
        case 2:
            Show(dog, length); system("pause");
            break;
        case 3:
            Bark(); Sleep(1000);
            break;
        case 4:
            cout << "\nСколько прибыло собак ?\n";
            int many; many = 0; cin >> many;
            length += many;
            break;
        default:
            cout << "Выход :)"; Sleep(1000);
            break;
        }

    } while (chose != 5);

}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    //system("color B5");

    cout << "Сколько собак будет?\n";
    int a = 0; cin >> a;

    Dogs* dogs = new Dogs[100];

    Doggy(dogs, a);
}
