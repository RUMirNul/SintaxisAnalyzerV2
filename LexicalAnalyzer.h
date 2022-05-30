#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//ТОЛЬКО ДЛЯ КОДИРОВКИ // УДАЛИТЬ
using namespace std;

class LexicalAnalyzer {
private:
    string str; //Строка входного файла
    typedef void(LexicalAnalyzer::* pfuncType)(); //Указатель на функции состояния
    pfuncType pfunc;
    int RCH; //Регистр числа
    int RZ;  //Регистр знака порядка
    int RP;  //Регистр порядка
    int RS;  //Регистр счётчика
    int RKL; //Регистр класса лексем
    int ROT; //Регистр значения отношения
    int RZN; //Регистр значение символа
    int RSOS;//Регистр состояния
    int ROB; //Регистр обнаружения
    int RK;  //Регистр значения класса символа
    int RSTR;//Регистр строки
    int RI;  //Регистр номера буквы в имени переменной
    ofstream ferr; //Файл ошибок
    int RSE; //Регистр счётчика ошибок
    vector<int> InitialVector; //Начальный вектор
    enum RK {
        Letter, Digit, Ar_oper, Attitude, Left_bracket, Right_bracket, Point, Space, CR, EndFile, Other
    };
    enum RKL {
        ROWLABEL = 1, OPERAND, ATTITUDE, NEXT, LET, FOR, GOTO, GOSUB, LEFT_BRACKET, RIGHT_BRACKET, IF,
        RETURN, END, _TO, STEP, REM, _ERROR, ENDFILE, AR_OPER
    };

    //------ПРОЦЕДУРЫ РАБОТЫ С ТАБЛИЦЕЙ ПЕРЕХОДОВ ------
    void A1();

    void A2();

    void A3();

    void B1();

    void C1();

    void C2();

    void D1();

    void D2();

    void D3();

    void D4();

    void D5();

    void D6();

    void E1();

    void E2();

    void F1();

    void F2();

    void F3();

    void G1();

    void H1();

    //Вычисление символа, который видим
    void Trans(char);

    //Анализ символов
    void Parse();

    //Конец работы анализатора и запись информации в файлы
    void End();

    //Содание токена
    void CreateToken();

    //Запись таблицы лексемы в файл
    void SaveTableLex();

    //Сохранение таблицы операндов в файл
    void SaveTableOperand();

    //Сохранение таблицы строк в файл
    void SaveTableString();

public:
    LexicalAnalyzer();

    //Запуск синтаксическго анализатора
    void Start(char*);

    vector<int> TS; //Таблица строк

    //Структора для хранения токена Хранит класс и значение токена
    struct Token {
        int TokenClass;
        int TokenValue;
    };
    vector<Token> TL; //Таблица лексем

    double TO[1024]; //Таблица оперендов
    int NTO; //Указатель на первый свободный элемент в TO
    int NTS; //Указатель на первый свободный элемент таблицы строк
    int NTL; //Указатель на первый свободный элемент в ТL

    struct node {
        int leter;
        int alternativa;

        void (LexicalAnalyzer::* pfunc)();
    };

    vector<node> Table; //Таблица для распознавания

    //-----------------------------------------------------------------Процедуры---------------------------------------------------
    void next() {
        ROB++;
    }

    void A1a() {
        CreateToken();
        pfunc = &LexicalAnalyzer::A1;
    }

    void A1b() {
        RP = 0;
        CreateToken();
        pfunc = &LexicalAnalyzer::A1;
    }

    void A1c() {
        CreateToken();
        pfunc = &LexicalAnalyzer::A1;
    }

    void A1d() {
        CreateToken();
        pfunc = &LexicalAnalyzer::A1;
    }

    void A1e() {
        A1a();
        pfunc = &LexicalAnalyzer::A1;
    }

    void A1f() {
        RKL = _ERROR;
        CreateToken();
        pfunc = &LexicalAnalyzer::A1;
    }

    void A2a() {
        RKL = AR_OPER;
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2b() {
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2c() {
        CreateToken();
        RKL = AR_OPER;
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2h() {
        RKL = LEFT_BRACKET;
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2l() {
        CreateToken();
        RKL = LEFT_BRACKET;
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2g() {
        CreateToken();
        RKL = AR_OPER;
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2p() {
        if (ROT == 2 && RZN == 1)
            ROT = 4;
        else if (ROT == 3 && RZN == 1)
            ROT = 5;
        else if (ROT == 2 && RZN == 3)
            ROT = 6;
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2r() {
        RKL = IF;
        A2b();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2k() {
        CreateToken();
        RKL = LEFT_BRACKET;
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2s() {
        RKL = RETURN;
        A2b();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2q() {
        RKL = END;
        A2b();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2o() {
        if (RZN == 1)
            CreateToken();
        else {
            G1b();
            return;
        }
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2u() {
        RKL = _TO;
        A2b();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2j() {
        CreateToken();
        RKL = LEFT_BRACKET;
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2f() {
        CreateToken();
        RKL = AR_OPER;
        CreateToken();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A2t() {
        RKL = STEP;
        A2b();
        pfunc = &LexicalAnalyzer::A2;
    }

    void A3a() {
        CreateToken();
        pfunc = &LexicalAnalyzer::A3;
    }

    void A3b() {
        RKL = RIGHT_BRACKET;
        CreateToken();
        pfunc = &LexicalAnalyzer::A3;
    }

    void A3c() {
        CreateToken();
        RKL = RIGHT_BRACKET;
        CreateToken();
        pfunc = &LexicalAnalyzer::A3;
    }

    void A3d() {
        CreateToken();
        RKL = RIGHT_BRACKET;
        CreateToken();
        pfunc = &LexicalAnalyzer::A3;
    }

    void A3g() {
        CreateToken();
        RKL = RIGHT_BRACKET;
        CreateToken();
        pfunc = &LexicalAnalyzer::A3;
    }

    void B1a() {
        ROB = InitialVector[RZN - 1];
        pfunc = &LexicalAnalyzer::B1;
    }

    void B1b() {
        CreateToken();
        ROB = InitialVector[RZN - 1];
        pfunc = &LexicalAnalyzer::B1;
    }

    void B1c() {
        CreateToken();
        ROB = InitialVector[RZN - 1];
        pfunc = &LexicalAnalyzer::B1;
    }

    void B1e() {
        CreateToken();
        ROB = InitialVector[RZN - 1];
        pfunc = &LexicalAnalyzer::B1;
    }

    void C1a() {
        RKL = NEXT;
        pfunc = &LexicalAnalyzer::C1;
    }

    void C2a() {
        RKL = OPERAND;
        RI = RZN;
        pfunc = &LexicalAnalyzer::C2;
    }

    void C2b() {
        CreateToken();
        RKL = OPERAND;
        RI = RZN;
        pfunc = &LexicalAnalyzer::C2;
    }

    void C2d() {
        RI = RZN;
        pfunc = &LexicalAnalyzer::C2;
    }

    void D1a() {
        RKL = OPERAND;
        RCH = RZN;
        pfunc = &LexicalAnalyzer::D1;
    }

    void D1b() {
        RCH *= 10;
        RCH += RZN;
        pfunc = &LexicalAnalyzer::D1;
    }

    void D1c() {
        CreateToken();
        RKL = OPERAND;
        RCH = RZN;
        pfunc = &LexicalAnalyzer::D1;
    }

    void D2a() {
        RS++;
        RCH *= 10;
        RCH += RZN;
        pfunc = &LexicalAnalyzer::D2;
    }

    void D2b() {
        RS = 1;
        RCH = RZN;
        pfunc = &LexicalAnalyzer::D2;
    }

    void D2c() {
        RS = 0;
        pfunc = &LexicalAnalyzer::D2;
    }

    void D3a() {
        RS = 0;
        pfunc = &LexicalAnalyzer::D3;
    }

    void D4a() {
        if (RZN == 1)
            RZ = 1;
        else if (RZN == 2)
            RZ = -1;
        pfunc = &LexicalAnalyzer::D4;
    }

    void D5a() {
        RZ = 1;
        RP = RZN;
        pfunc = &LexicalAnalyzer::D5;
    }

    void D5b() {
        RP = RZN;
        pfunc = &LexicalAnalyzer::D5;
    }

    void D5c() {
        RP *= 10;
        RP += RZN;
        pfunc = &LexicalAnalyzer::D5;
    }

    void D6a() {
        CreateToken();
        RKL = OPERAND;
        pfunc = &LexicalAnalyzer::D6;
    }

    void D6b() {
        RKL = OPERAND;
        pfunc = &LexicalAnalyzer::D6;
    }

    void E1a() {
        RKL = GOTO;
        pfunc = &LexicalAnalyzer::E1;
    }

    void E1b() {
        RKL = GOSUB;
        pfunc = &LexicalAnalyzer::E1;
    }

    void E2a() {
        RKL = ROWLABEL;
        RSTR = RZN;
        pfunc = &LexicalAnalyzer::E2;
    }

    void E2b() {
        RSTR = RZN;
        pfunc = &LexicalAnalyzer::E2;
    }

    void E2c() {
        RSTR *= 10;
        RSTR += RZN;
        pfunc = &LexicalAnalyzer::E2;
    }

    void F1a() {
        RKL = LET;
        pfunc = &LexicalAnalyzer::F1;
    }

    void F1b() {
        RKL = FOR;
        pfunc = &LexicalAnalyzer::F1;
    }

    void F2a() {
        RI = RZN;
        pfunc = &LexicalAnalyzer::F2;
    }

    void F3a() {
        RI += (RZN) * 26;
        pfunc = &LexicalAnalyzer::F3;
    }

    void G1a() {
        RKL = REM;
        CreateToken();
        pfunc = &LexicalAnalyzer::G1;
    }

    void G1b() {
        RKL = _ERROR;
        CreateToken();
        pfunc = &LexicalAnalyzer::G1;
    }

    void H1a() {
        RKL = ATTITUDE;
        ROT = RZN;
        pfunc = &LexicalAnalyzer::H1;
    }

    void H1b() {
        CreateToken();
        RKL = ATTITUDE;
        ROT = RZN;
        pfunc = &LexicalAnalyzer::H1;
    }

    void H1c() {
        CreateToken();
        RKL = ATTITUDE;
        ROT = RZN;
        pfunc = &LexicalAnalyzer::H1;
    }

    void H1f() {
        H1b();
        RKL = ATTITUDE;
        ROT = RZN;
        pfunc = &LexicalAnalyzer::H1;
    }

    void M1() {
        if (ROB == 0) {
            G1b();
            return;
        }
        if (RZN == Table[ROB - 1].leter) {
            (this->*(Table[ROB - 1].pfunc))();
        }
        else {
            ROB = Table[ROB - 1].alternativa;
            if (ROB)
                (this->*(Table[ROB - 1].pfunc))();
            else
                G1b();
        }
    }

    void M2() {
        if (RZN == 5) {
            D3a();
            return;
        }
        else {
            CreateToken();
            ROB = InitialVector[RZN - 1];
            pfunc = &LexicalAnalyzer::B1;
        }
    }

    void M3() {
        if (RZN == 5)
            pfunc = &LexicalAnalyzer::D3;

    }
    //-----------------------Процедуры выхода из анализа и обработки ошибок--------------------------------------

    void exit1() {
        RKL = ENDFILE;
        CreateToken();
    }

    void exit2() {
        CreateToken();
        RKL = ENDFILE;
        CreateToken();
    }

    void exit3() {
        CreateToken();
        RKL = ENDFILE;
        CreateToken();
    }

    void exit4() {
        CreateToken();
        RKL = ENDFILE;
        CreateToken();
    }

    void exit5() {
        CreateToken();
        RKL = ENDFILE;
        CreateToken();
    }

    void error2() {
        cout << "ОШИБКА[ЛА] " << str << "\n";
        RKL = _ERROR;
        CreateToken();
        RKL = ENDFILE;
        CreateToken();
    }
};