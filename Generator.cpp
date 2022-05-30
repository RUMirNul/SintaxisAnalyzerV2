#include "Generator.h"

void Generator::Start(char* nameIn) {
    SyntaxAnalyzer::Start(nameIn);
    if (flagErr) {
        cout << "В программе обнаружены ошибки. Возможно атомы и лексемы будут построены неверно." << endl;
        return;
    }
    else
        cout << "Анализ программы завершён без ошибок." << endl;
}

