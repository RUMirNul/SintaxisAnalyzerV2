#include <stack>
#include "LexicalAnalyzer.h"

using namespace std;
class SyntaxAnalyzer : public LexicalAnalyzer {
private:
    stack<int> stk;
    int in; //Указатель на вход
    int mch;//Магазинный символ
    int num_str; //Номер текущей строки
    typedef void(SyntaxAnalyzer::* pfuncType)();


    pfuncType T[20][24]; //Управляющая таблица
    int NTM; //Указатель на первый свободный элемент таблицы меток
    void printTA(); //Печать таблицы атомов
    void showStk();

public:
    int NTX; //Указатель на первый свободный элемент таблицы результатов атома хранения
    bool flagErr;//Флаг обнаружения ошибки
    int NTtemp; //Указатель на первый свободный элемент в таблицы промежуточных результатов
    struct atom {
        int type; //Тип атома
        int atr1; //Атрибут 1
        int atr2; //Атрибут 2
        int atr3; //Атрибут 3
        int atr4; //Атрибут 4
    };
    atom TA[512]; //Таблица атомов
    int NTA; //Указатель на первый свободный элемент таблицы атомов
    SyntaxAnalyzer();


    //Создание объекта-атома
    void createAtom(int, int, int, int, int);

    //Печать оишбки в файл
    void error(string);

    //------ПРОЦЕДУРЫ РАБОТЫ С ТАБЛИЦЕЙ ПЕРЕХОДОВ ------
    void F1();

    void F2();

    void F3();

    void F4();

    void F5();

    void F6();

    void F7();

    void F8();

    void F9();

    void F10();

    void F11();

    void F12();

    void F13();

    void F14();

    void F15();

    void F16();

    void F17();

    void F18();

    void F19();

    void F20();

    void F21();

    void F22();

    void F23();

    void F24();

    void F25();

    void F26();

    void F27();

    void F28();

    void a();

    void b();

    void c();

    void d();

    void e();

    void f();

    void g();

    void h();

    void j();

    void k();

    void i();

    void l();

    void m();

    void n();

    void o();

    void p();

    void q();

    void r();
    //Переход на новую строку (используется для пропуска комментариев)
    void next() {
        in++;
    }

    void Start(char* filename) {
        LexicalAnalyzer::Start(filename);
        NTtemp = NTO;
        NTX = 700;
        NTM = 256;
        for (int i = 1; i < NTL; i++) {
            if (TL[i].TokenClass == 17)
                TL[i].TokenClass = 22;
            if (TL[i].TokenClass == 18)
                TL[i].TokenClass = 23;
            if (TL[i].TokenClass == 19)
                TL[i].TokenClass = 16 + TL[i].TokenValue;
        }
        while (in < NTL) {
            mch = stk.top();
            switch (mch) {
            case 19:
                d();
                break;
            case 20:
                e();
                break;
            case 21:
                f();
                break;
            case 22:
                g();
                break;
            case 23:
                h();
                break;
            case 24:
                i();
                break;
            case 25:
                j();
                break;
            case 26:
                k();
                break;
            case 27:
                l();
                break;
            case 28:
                m();
                break;
            case 29:
                n();
                break;
            case 30:
                o();
                break;
            case 31:
                p();
                break;
            case 32:
                q();
                break;
            case 33:
                r();
                break;
            default:
                (this->*T[mch][TL[in].TokenClass])();
            }
        }
        printTA();
    }



    //Процедуры перехода на обработку ошибки

    void A() {
        error("Программа начинается неверно.");
    }

    void B() {
        error("Оператор начинается неверно.");
    }

    void G1() {
        error("Неожиданный вход после for-оператора.");
    }

    void G2() {
        error("Лишняя правая скобка в выражении после TO.");
    }

    void C() {
        error(" ");
    }

    void D() {
        error("Неожиданный вход после оператора.");
    }

    void K1() {
        error("Выражение незаконно - нет оперенда.");
    }

    void K2() {
        error("Оператор незакончен.");
    }

    void K3() {
        error("В выражении пропущен оперенд.");
    }

    void K4() {
        error("Неожиданный вход после выражения.");
    }

    void K5() {
        error("Выражение начинается с входа.");
    }

    void K6() {
        error("Два знака операции в выражении.");
    }

    void K7() {
        error("В выражении пропущен знак операции.");
    }

    void E1() {
        error("Неожиданный вход в if-операторе.");
    }

    void E2() {
        error("if-оператор незакончен.");
    }

    void E3() {
        error("Лишняя правая скобка в выражении после if.");
    }

    void L() {
        error("for-операторы вложены неверно. Пропущено next");
    }

    void M1() {
        error("Неожиданный вход в if-операторе.");
    }

    void M2() {
        error("if-оператор незакончен.");
    }

    void M3() {
        error("Два знака отношения в if-операторе.");
    }

    void M4() {
        error("Лишняя правая скобка в выражении после знака отношения.");
    }

    void H1() {
        error("Пропущена правая скобка перед входом.");
    }

    void H2() {
        error("Пропущена правая скобка в конце строки.");
    }

    void K() {
        error("for-операторы вложены неверно - лишнее next.");
    }

    void P1() {
        error("Неожиданный вход в for-операторе.");
    }

    void P2() {
        error("for-оператор незакончен.");
    }

    void P3() {
        error("Лишняя правая скобка в выражении после to.");
    }

    void P4() {
        error("to пропущено или не на своём месте в for-операторе.");
    }

    void P() {
        error("Программа продолжается после end-оператора.");
    }

    void T1() {
        error("Нет программы.");
    }

    void T2() {
        error("Пропущен end-оператор.");
    }

    void T3() {
        error("Программа кончается посреди оператора.");
    }

    void O() {
        error("Ошибка компилятора.");
    }
};

