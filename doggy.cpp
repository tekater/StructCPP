#pragma warning(disable:4996) // Очень важно - без этого strcat не работает.

#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>

using namespace std;

struct Dogs {
    char Name[20];
    int Class;
    char stepName[20];
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
void Cinput(Dogs* dog, int length) {
    for (int i = 0; i < length; i++) {
        cout << "Dog: " << i + 1 << "\n";
        cout << "Name: "; cin >> dog[i].Name; cout << endl;
        cout << "Class(int): "; cin >> dog[i].Class; cout << endl;
        cout << "StepName: "; cin >> dog[i].stepName; cout << endl;
        cout << endl;
    }
}
void Doggy(Dogs* dog,int length) {
    int chose;
    do {
        system("cls");
    cout << "\n1 - Заполнение объектов.\n2 - Вывод\n3 - Подать голос\n4 - Выход\n";
    cout << "\nВыберите действие: "; cin >> chose;
    switch (chose) {
    case 1:
        Cinput(dog, length);
        break;
    case 2:
        Show(dog, length);
        Sleep(1000);
        break;
    case 3:
        Bark();
        Sleep(1000);
        break;
    default:
        cout << "Выход :)";
        Sleep(1000);
        break;
    }
    } while (chose != 4);
}
int main()
{
    setlocale(0, "");
    srand(time(NULL));
    //system("color B5");
    cout << "Сколько собак будет?\n";
    int a = 0; cin >> a;
    Dogs* dogs = new Dogs[a];
    Doggy(dogs,a);
}
