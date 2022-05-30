#include <windows.h>

#include "Generator.h"
//ТОЛЬКО ДЛЯ КОДИРОВКИ // УДАЛИТЬ
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Generator gen;
    int answer;
    cout << "Выберите выберите вариант запуска программы:\n0 - Своя программа 1 - Программа из Льюиса 2 - Заготовленная программа 3 - Заготовленная программа с ошибками\n";
    cin >> answer;

    string str = "";

    switch (answer) {
    case 0:
        cout << "Введите имя файла: ";
        cin >> str;
        break;
    case 1:
        str = "Lyis.txt";
        break;
    case 2:
        str = "MBCode.txt";
        break;
    case 3:
        str = "CodeWErr.txt";
        break;
    default:
        cout << "Такого варианта нет!\n";
        return 1;
    }
    int n = str.length();
    char* name = &str[0];
    gen.Start(name);
    return 0;
}
