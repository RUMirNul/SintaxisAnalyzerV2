#include "Generator.h"

void Generator::Start(char* nameIn) {
    SyntaxAnalyzer::Start(nameIn);
    if (flagErr) {
        cout << "� ��������� ���������� ������. �������� ����� � ������� ����� ��������� �������." << endl;
        return;
    }
    else
        cout << "������ ��������� �������� ��� ������." << endl;
}

