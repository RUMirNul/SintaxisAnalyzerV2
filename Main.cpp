#include <windows.h>

#include "Generator.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Generator gen;
    int answer;
    cout << "�������� �������� ������� ������� ���������:\n0 - ���� ��������� 1 - ��������� �� ������ 2 - ������������� ��������� 3 - ������������� ��������� � ��������\n";
    cin >> answer;

    string str = "";

    switch (answer) {
    case 0:
        cout << "������� ��� �����: ";
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
        cout << "������ �������� ���!\n";
        return 1;
    }

    int n = str.length();
    char* name = &str[0];
    gen.Start(name);
    return 0;
}
