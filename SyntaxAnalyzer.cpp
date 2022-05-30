#include <iomanip>
#include "SyntaxAnalyzer.h"

SyntaxAnalyzer::SyntaxAnalyzer() {
    stk.push(18);
    stk.push(1);
    NTA = 0;
    in = NTX = NTM = 1;
    num_str = 0;
    flagErr = false;


    //Строка 1
    T[1][1] = &SyntaxAnalyzer::F1;
    for (int i = 2; i < 22; i++)
        T[1][i] = &SyntaxAnalyzer::A;
    T[1][22] = &SyntaxAnalyzer::C;
    T[1][23] = &SyntaxAnalyzer::T1;

    //Строка 2
    T[2][1] = &SyntaxAnalyzer::F3;
    T[2][2] = &SyntaxAnalyzer::B;
    T[2][3] = &SyntaxAnalyzer::B;
    T[2][4] = &SyntaxAnalyzer::F2;
    T[2][5] = &SyntaxAnalyzer::F4;
    T[2][6] = &SyntaxAnalyzer::F9;
    T[2][7] = &SyntaxAnalyzer::F5;
    T[2][8] = &SyntaxAnalyzer::F7;
    T[2][9] = &SyntaxAnalyzer::B;
    T[2][10] = &SyntaxAnalyzer::B;
    T[2][11] = &SyntaxAnalyzer::F6;
    T[2][12] = &SyntaxAnalyzer::F8;
    T[2][13] = &SyntaxAnalyzer::F2;
    T[2][14] = &SyntaxAnalyzer::B;
    T[2][15] = &SyntaxAnalyzer::B;
    T[2][16] = &SyntaxAnalyzer::F12;
    T[2][17] = &SyntaxAnalyzer::B;
    T[2][18] = &SyntaxAnalyzer::B;
    T[2][19] = &SyntaxAnalyzer::B;
    T[2][20] = &SyntaxAnalyzer::B;
    T[2][21] = &SyntaxAnalyzer::B;
    T[2][22] = &SyntaxAnalyzer::C;
    T[2][23] = &SyntaxAnalyzer::T2;

    //Строка 3
    T[3][1] = &SyntaxAnalyzer::F11;
    for (int i = 2; i < 22; i++)
        T[3][i] = &SyntaxAnalyzer::G1;
    T[3][10] = &SyntaxAnalyzer::G2;
    T[3][15] = &SyntaxAnalyzer::F10;
    T[3][16] = &SyntaxAnalyzer::next;
    T[3][22] = &SyntaxAnalyzer::C;
    T[3][23] = &SyntaxAnalyzer::T2;

    //Строка 4
    T[4][1] = &SyntaxAnalyzer::F13;
    for (int i = 2; i < 22; i++)
        T[4][i] = &SyntaxAnalyzer::D;
    T[4][16] = &SyntaxAnalyzer::next;
    T[4][22] = &SyntaxAnalyzer::C;
    T[4][23] = &SyntaxAnalyzer::T2;

    //Строка 5
    T[5][1] = &SyntaxAnalyzer::K2;
    T[5][2] = &SyntaxAnalyzer::F14;
    T[5][3] = &SyntaxAnalyzer::K1;
    T[5][4] = &SyntaxAnalyzer::K4;
    T[5][5] = &SyntaxAnalyzer::K4;
    T[5][6] = &SyntaxAnalyzer::K4;
    T[5][7] = &SyntaxAnalyzer::K1;
    T[5][8] = &SyntaxAnalyzer::K4;
    T[5][9] = &SyntaxAnalyzer::F14;
    T[5][10] = &SyntaxAnalyzer::K3;
    T[5][11] = &SyntaxAnalyzer::K4;
    T[5][12] = &SyntaxAnalyzer::K4;
    T[5][13] = &SyntaxAnalyzer::K4;
    T[5][14] = &SyntaxAnalyzer::K1;
    T[5][15] = &SyntaxAnalyzer::K1;
    T[5][16] = &SyntaxAnalyzer::next;
    T[5][17] = &SyntaxAnalyzer::F15;
    T[5][18] = &SyntaxAnalyzer::F16;
    T[5][19] = &SyntaxAnalyzer::K5;
    T[5][20] = &SyntaxAnalyzer::K5;
    T[5][21] = &SyntaxAnalyzer::K5;
    T[5][22] = &SyntaxAnalyzer::C;
    T[5][23] = &SyntaxAnalyzer::T3;

    //Строка 6
    T[6][1] = &SyntaxAnalyzer::K2;
    T[6][2] = &SyntaxAnalyzer::F20;
    T[6][3] = &SyntaxAnalyzer::K1;
    T[6][4] = &SyntaxAnalyzer::K4;
    T[6][5] = &SyntaxAnalyzer::K4;
    T[6][6] = &SyntaxAnalyzer::K4;
    T[6][7] = &SyntaxAnalyzer::K1;
    T[6][8] = &SyntaxAnalyzer::K4;
    T[6][9] = &SyntaxAnalyzer::F20;
    T[6][10] = &SyntaxAnalyzer::K3;
    T[6][11] = &SyntaxAnalyzer::K4;
    T[6][12] = &SyntaxAnalyzer::K4;
    T[6][13] = &SyntaxAnalyzer::K4;
    T[6][14] = &SyntaxAnalyzer::K1;
    T[6][15] = &SyntaxAnalyzer::K1;
    T[6][16] = &SyntaxAnalyzer::next;
    T[6][17] = &SyntaxAnalyzer::K6;
    T[6][18] = &SyntaxAnalyzer::K6;
    T[6][19] = &SyntaxAnalyzer::K6;
    T[6][20] = &SyntaxAnalyzer::K6;
    T[6][21] = &SyntaxAnalyzer::K6;
    T[6][22] = &SyntaxAnalyzer::C;
    T[6][23] = &SyntaxAnalyzer::T3;

    //Строка 7
    T[7][1] = &SyntaxAnalyzer::K2;
    T[7][2] = &SyntaxAnalyzer::F24;
    T[7][3] = &SyntaxAnalyzer::K1;
    T[7][4] = &SyntaxAnalyzer::K4;
    T[7][5] = &SyntaxAnalyzer::K4;
    T[7][6] = &SyntaxAnalyzer::K4;
    T[7][7] = &SyntaxAnalyzer::K1;
    T[7][8] = &SyntaxAnalyzer::K4;
    T[7][9] = &SyntaxAnalyzer::F24;
    T[7][10] = &SyntaxAnalyzer::K3;
    T[7][11] = &SyntaxAnalyzer::K4;
    T[7][12] = &SyntaxAnalyzer::K4;
    T[7][13] = &SyntaxAnalyzer::K4;
    T[7][14] = &SyntaxAnalyzer::K1;
    T[7][15] = &SyntaxAnalyzer::K1;
    T[7][16] = &SyntaxAnalyzer::next;
    T[7][17] = &SyntaxAnalyzer::K6;
    T[7][18] = &SyntaxAnalyzer::K6;
    T[7][19] = &SyntaxAnalyzer::K6;
    T[7][20] = &SyntaxAnalyzer::K6;
    T[7][21] = &SyntaxAnalyzer::K6;
    T[7][22] = &SyntaxAnalyzer::C;
    T[7][23] = &SyntaxAnalyzer::T3;

    //Строка 8
    T[8][1] = &SyntaxAnalyzer::K2;
    T[8][2] = &SyntaxAnalyzer::F28;
    T[8][3] = &SyntaxAnalyzer::K1;
    T[8][4] = &SyntaxAnalyzer::K4;
    T[8][5] = &SyntaxAnalyzer::K4;
    T[8][6] = &SyntaxAnalyzer::K4;
    T[8][7] = &SyntaxAnalyzer::K1;
    T[8][8] = &SyntaxAnalyzer::K4;
    T[8][9] = &SyntaxAnalyzer::F27;
    T[8][10] = &SyntaxAnalyzer::K3;
    T[8][11] = &SyntaxAnalyzer::K4;
    T[8][12] = &SyntaxAnalyzer::K4;
    T[8][13] = &SyntaxAnalyzer::K4;
    T[8][14] = &SyntaxAnalyzer::K1;
    T[8][15] = &SyntaxAnalyzer::K1;
    T[8][16] = &SyntaxAnalyzer::next;
    T[8][17] = &SyntaxAnalyzer::K6;
    T[8][18] = &SyntaxAnalyzer::K6;
    T[8][19] = &SyntaxAnalyzer::K6;
    T[8][20] = &SyntaxAnalyzer::K6;
    T[8][21] = &SyntaxAnalyzer::K6;
    T[8][22] = &SyntaxAnalyzer::C;
    T[8][23] = &SyntaxAnalyzer::T3;

    //Строка 9
    T[9][1] = &SyntaxAnalyzer::F19;
    T[9][2] = &SyntaxAnalyzer::K7;
    T[9][3] = &SyntaxAnalyzer::F19;
    T[9][4] = &SyntaxAnalyzer::O;
    T[9][5] = &SyntaxAnalyzer::O;
    T[9][6] = &SyntaxAnalyzer::O;
    T[9][7] = &SyntaxAnalyzer::F19;
    T[9][8] = &SyntaxAnalyzer::O;
    T[9][9] = &SyntaxAnalyzer::K7;
    T[9][10] = &SyntaxAnalyzer::F19;
    T[9][11] = &SyntaxAnalyzer::O;
    T[9][12] = &SyntaxAnalyzer::O;
    T[9][13] = &SyntaxAnalyzer::O;
    T[9][14] = &SyntaxAnalyzer::F19;
    T[9][15] = &SyntaxAnalyzer::F19;
    T[9][16] = &SyntaxAnalyzer::next;
    T[9][17] = &SyntaxAnalyzer::F17;
    T[9][18] = &SyntaxAnalyzer::F18;
    T[9][19] = &SyntaxAnalyzer::O;
    T[9][20] = &SyntaxAnalyzer::O;
    T[9][21] = &SyntaxAnalyzer::O;
    T[9][22] = &SyntaxAnalyzer::O;
    T[9][23] = &SyntaxAnalyzer::O;

    //Строка 10
    T[10][1] = &SyntaxAnalyzer::F23;
    T[10][2] = &SyntaxAnalyzer::K7;
    T[10][3] = &SyntaxAnalyzer::F23;
    T[10][4] = &SyntaxAnalyzer::O;
    T[10][5] = &SyntaxAnalyzer::O;
    T[10][6] = &SyntaxAnalyzer::O;
    T[10][7] = &SyntaxAnalyzer::F23;
    T[10][8] = &SyntaxAnalyzer::O;
    T[10][9] = &SyntaxAnalyzer::K7;
    T[10][10] = &SyntaxAnalyzer::F23;
    T[10][11] = &SyntaxAnalyzer::O;
    T[10][12] = &SyntaxAnalyzer::O;
    T[10][13] = &SyntaxAnalyzer::O;
    T[10][14] = &SyntaxAnalyzer::F23;
    T[10][15] = &SyntaxAnalyzer::F23;
    T[10][16] = &SyntaxAnalyzer::next;
    T[10][17] = &SyntaxAnalyzer::F23;
    T[10][18] = &SyntaxAnalyzer::F23;
    T[10][19] = &SyntaxAnalyzer::F21;
    T[10][20] = &SyntaxAnalyzer::F22;
    T[10][21] = &SyntaxAnalyzer::O;
    T[10][22] = &SyntaxAnalyzer::O;
    T[10][23] = &SyntaxAnalyzer::O;

    //Строка 11
    T[11][1] = &SyntaxAnalyzer::F26;
    T[11][2] = &SyntaxAnalyzer::K7;
    T[11][3] = &SyntaxAnalyzer::F26;
    T[11][4] = &SyntaxAnalyzer::K4;
    T[11][5] = &SyntaxAnalyzer::K4;
    T[11][6] = &SyntaxAnalyzer::K4;
    T[11][7] = &SyntaxAnalyzer::F26;
    T[11][8] = &SyntaxAnalyzer::K4;
    T[11][9] = &SyntaxAnalyzer::K7;
    T[11][10] = &SyntaxAnalyzer::F26;
    T[11][11] = &SyntaxAnalyzer::K4;
    T[11][12] = &SyntaxAnalyzer::K4;
    T[11][13] = &SyntaxAnalyzer::K4;
    T[11][14] = &SyntaxAnalyzer::F26;
    T[11][15] = &SyntaxAnalyzer::F26;
    T[11][16] = &SyntaxAnalyzer::next;
    T[11][17] = &SyntaxAnalyzer::F26;
    T[11][18] = &SyntaxAnalyzer::F26;
    T[11][19] = &SyntaxAnalyzer::F26;
    T[11][20] = &SyntaxAnalyzer::F26;
    T[11][21] = &SyntaxAnalyzer::F25;
    T[11][22] = &SyntaxAnalyzer::C;
    T[11][23] = &SyntaxAnalyzer::T2;

    //Строка 12
    T[12][1] = &SyntaxAnalyzer::E2;
    for (int i = 2; i < 22; i++)
        T[12][i] = &SyntaxAnalyzer::E1;
    T[12][3] = &SyntaxAnalyzer::b;
    T[12][10] = &SyntaxAnalyzer::E3; 
    T[12][16] = &SyntaxAnalyzer::next;
    T[12][22] = &SyntaxAnalyzer::C;
    T[12][23] = &SyntaxAnalyzer::T2;

    //Строка 13
    for (int i = 1; i < 24; i++)
        T[13][i] = &SyntaxAnalyzer::O;
    T[13][4] = &SyntaxAnalyzer::b;
    T[13][16] = &SyntaxAnalyzer::next;
    T[13][13] = &SyntaxAnalyzer::L;

    //Строка 14
    T[14][1] = &SyntaxAnalyzer::M2;
    for (int i = 2; i < 22; i++)
        T[14][i] = &SyntaxAnalyzer::M1;
    T[14][3] = &SyntaxAnalyzer::M3;
    T[14][7] = &SyntaxAnalyzer::b;
    T[14][10] = &SyntaxAnalyzer::M4;
    T[14][16] = &SyntaxAnalyzer::next;
    T[14][22] = &SyntaxAnalyzer::c;
    T[14][23] = &SyntaxAnalyzer::T3;

    //Строка 15
    T[15][1] = &SyntaxAnalyzer::H2;
    for (int i = 2; i < 22; i++)
        T[15][i] = &SyntaxAnalyzer::H1;
    T[15][10] = &SyntaxAnalyzer::a;
    T[15][16] = &SyntaxAnalyzer::next;
    T[15][22] = &SyntaxAnalyzer::c;
    T[15][23] = &SyntaxAnalyzer::T3;

    //Строка 16
    for (int i = 1; i < 24; i++)
        T[16][i] = &SyntaxAnalyzer::O;
    T[16][4] = &SyntaxAnalyzer::K;
    T[16][13] = &SyntaxAnalyzer::a;
    T[16][16] = &SyntaxAnalyzer::next;

    //Строка 17
    T[17][1] = &SyntaxAnalyzer::P2;
    for (int i = 2; i < 22; i++)
        T[17][i] = &SyntaxAnalyzer::P1;
    T[17][10] = &SyntaxAnalyzer::P3;
    T[17][14] = &SyntaxAnalyzer::a;
    T[17][15] = &SyntaxAnalyzer::P4;
    T[17][16] = &SyntaxAnalyzer::next;
    T[17][22] = &SyntaxAnalyzer::c;
    T[17][23] = &SyntaxAnalyzer::T3;

    //Строка 18
    for (int i = 1; i < 23; i++)
        T[18][i] = &SyntaxAnalyzer::P;
    T[18][16] = &SyntaxAnalyzer::next;
    T[18][23] = &SyntaxAnalyzer::c;
}


void SyntaxAnalyzer::error(string errMsg) {
    cout << "ОШИБКА: Строка " << num_str << ' ' << errMsg << "\n";
    flagErr = true;
    if (TL[in].TokenClass == 23) {
        in++;
    }
    else {
        while (TL[in].TokenClass != 1)
            in++;
    }
    if (stk.top() == 1 || stk.top() == 2 || stk.top() == 4)
        return;
    else if (stk.top() == 16 || stk.top() == 18) {
        stk.pop();
        stk.push(2);
    }
    else {
        while (stk.top() != 4)
            stk.pop();
    }
}

void SyntaxAnalyzer::createAtom(int type, int atr1 = -1, int atr2 = -1, int atr3 = -1, int atr4 = -1) {
    TA[NTA].type = type;
    TA[NTA].atr1 = atr1;
    TA[NTA].atr2 = atr2;
    TA[NTA].atr3 = atr3;
    TA[NTA].atr4 = atr4;
    NTA++;
}

void SyntaxAnalyzer::printTA() {
    ofstream fout("TableAtoms.txt");
    if (!fout) {
        cout << endl << "Не удаётся сохранить таблицу атомов." << endl;
        return;
    }
    string types[18];
    types[0] = "ОКОНЧАНИЕ";
    types[1] = "НОМСТРОК";
    types[2] = "ПРИСВ";
    types[3] = "ПЕРЕХОД";
    types[4] = "ХРАН ПЕРЕХОД";
    types[5] = "ВОЗВРПЕРЕХОД";
    types[6] = "УСЛПЕРЕХОД";
    types[7] = "ХРАНЕНИЕ";
    types[8] = "МЕТКА";
    types[9] = "ПРОВЕРКА";
    types[10] = "УВЕЛИЧ";
    types[11] = "СЛОЖ";
    types[12] = "ВЫЧИТ";
    types[13] = "УМНОЖ";
    types[14] = "ДЕЛЕН";
    types[15] = "ЭКСП";
    types[16] = "ПЛЮС";
    types[17] = "МИНУС";
    for (int i = 0; i < NTA; i++) {
        fout << setw(15) << types[TA[i].type - 1] << " " << setw(3) << TA[i].atr1 << " "
            << setw(3) << TA[i].atr2 << " " << setw(3) << TA[i].atr3 << " "
            << setw(3) << TA[i].atr4 << endl;
    }
    fout.close();
}

void SyntaxAnalyzer::F1() {
    stk.pop();
    stk.push(16);
    stk.push(2);
    createAtom(2, TL[in].TokenValue);
    num_str = TS[TL[in].TokenValue];
    in++;
}

void SyntaxAnalyzer::F2() {
    stk.pop();
    int k = stk.top();
}

void SyntaxAnalyzer::F3() {
    createAtom(2, TL[in].TokenValue);
    num_str = TS[TL[in].TokenValue];
    in++;
}

void SyntaxAnalyzer::F4() {
    stk.pop();
    stk.push(4);
    stk.push(0);
    stk.push(TL[in].TokenValue);
    stk.push(19);
    stk.push(3);
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F5() {
    stk.pop();
    stk.push(4);
    createAtom(4, TL[in].TokenValue);
    in++;
}

void SyntaxAnalyzer::F6() {
    stk.pop();
    stk.push(4);
    stk.push(0);
    stk.push(0);
    stk.push(0);
    stk.push(0);
    stk.push(20);
    stk.push(5);
    stk.push(14);
    stk.push(5);
    stk.push(5);
    stk.push(8);
    stk.push(12);
    stk.push(8);
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F7() {
    stk.pop();
    stk.push(4);
    createAtom(5, TL[in].TokenValue);
    in++;
}

void SyntaxAnalyzer::F8() {
    stk.pop();
    stk.push(4);
    createAtom(6);
    in++;
}

void SyntaxAnalyzer::F9() {
    int p, s, t, u, v, y;
    p = TL[in].TokenValue;
    y = num_str;
    s = NTX;
    NTX++;
    t = NTX;
    NTX++;
    u = NTM;
    NTM++;
    v = NTM;
    NTM++;
    stk.pop();
    stk.push(4);
    stk.push(v);
    stk.push(22);
    stk.push(u);
    stk.push(26);
    stk.push(t);
    stk.push(p);
    stk.push(25);
    stk.push(y);
    stk.push(0);
    stk.push(p);
    stk.push(24);
    stk.push(3);
    stk.push(13);
    stk.push(4);
    stk.push(v);
    stk.push(t);
    stk.push(s);
    stk.push(p);
    stk.push(23);
    stk.push(u);
    stk.push(22);
    stk.push(t);
    stk.push(0);
    stk.push(21);
    stk.push(2);
    stk.push(3);
    stk.push(s);
    stk.push(0);
    stk.push(21);
    stk.push(2);
    stk.push(5);
    stk.push(17);
    stk.push(0);
    stk.push(p);
    stk.push(19);
    stk.push(3);
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F10() {
    stk.pop();
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F11() {
    TO[NTO] = 1;
    stk.pop();
    stk.pop();
    int p = stk.top();
    stk.pop();
    stk.pop();
    stk.push(TO[NTO]);
    stk.push(p);
}

void SyntaxAnalyzer::F12() {
    stk.pop();
    stk.push(4);
    in++;
}

void SyntaxAnalyzer::F13() {
    stk.pop();
    stk.push(2);
    createAtom(2, TL[in].TokenValue);
    num_str = TS[TL[in].TokenValue];
    in++;
}

void SyntaxAnalyzer::F14() {
    stk.pop();
    stk.push(0);
    stk.push(9);
    stk.push(2);
    stk.push(6);
}

void SyntaxAnalyzer::F15() {
    stk.pop();
    stk.push(NTtemp);
    stk.push(9);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(32);
    stk.push(2);
    stk.push(6);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F16() {
    stk.pop();
    stk.push(NTtemp);
    stk.push(9);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(33);
    stk.push(2);
    stk.push(6);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F17() {
    stk.pop();
    int p = stk.top();
    stk.pop();
    stk.push(NTtemp);
    stk.push(9);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(p);
    stk.push(27);
    stk.push(3);
    stk.push(6);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F18() {
    stk.pop();
    int p = stk.top();
    stk.pop();
    stk.push(NTtemp);
    stk.push(9);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(p);
    stk.push(28);
    stk.push(3);
    stk.push(6);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F19() {
    stk.pop();
    int p = stk.top();
    stk.pop();
    int i = stk.top() - 1;
    stk.pop();
    stack<int> tmp;
    while (i != 0) {
        tmp.push(stk.top());
        stk.pop();
        i--;
    }
    while (stk.top() != 0) {
        tmp.push(stk.top());
        stk.pop();
    }
    stk.pop();
    stk.push(p);
    while (!tmp.empty()) {
        stk.push(tmp.top());
        tmp.pop();
    }
}

void SyntaxAnalyzer::F20() {
    stk.pop();
    stk.push(0);
    stk.push(10);
    stk.push(2);
    stk.push(7);
}

void SyntaxAnalyzer::F21() {
    stk.pop();
    int p = stk.top();
    stk.pop();
    stk.push(NTtemp);
    stk.push(10);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(p);
    stk.push(29);
    stk.push(3);
    stk.push(7);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F22() {
    stk.pop();
    int p = stk.top();
    stk.pop();
    stk.push(NTtemp);
    stk.push(10);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(p);
    stk.push(30);
    stk.push(3);
    stk.push(7);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F23() {
    stk.pop();
    int p = stk.top();
    stk.pop();
    int i = stk.top() - 1;
    stk.pop();
    stack<int> tmp;
    while (i != 0) {
        tmp.push(stk.top());
        stk.pop();
        i--;
    }
    while (stk.top() != 0) {
        tmp.push(stk.top());
        stk.pop();
    }
    stk.pop();
    stk.push(p);
    while (!tmp.empty()) {
        stk.push(tmp.top());
        tmp.pop();
    }
}

void SyntaxAnalyzer::F24() {
    stk.pop();
    stk.push(0);
    stk.push(11);
    stk.push(2);
    stk.push(8);
}

void SyntaxAnalyzer::F25() {
    stk.pop();
    int p = stk.top();
    stk.pop();
    int t = stk.top();
    stk.push(NTtemp);
    stk.push(11);
    stk.push(NTtemp);
    stk.push(0);
    stk.push(p);
    stk.push(31);
    stk.push(3);
    stk.push(8);
    NTtemp++;
    in++;
}

void SyntaxAnalyzer::F26() {
    stk.pop();
    int p = stk.top();
    stk.pop();
    int i = stk.top() - 1;
    stk.pop();
    stack<int> tmp;
    while (i != 0) {
        tmp.push(stk.top());
        stk.pop();
        i--;
    }
    while (stk.top() != 0) {
        tmp.push(stk.top());
        stk.pop();
    }
    stk.pop();
    stk.push(p);
    while (!tmp.empty()) {
        stk.push(tmp.top());
        tmp.pop();
    }

}

void SyntaxAnalyzer::F27() {
    stk.pop();
    int p = stk.top();
    stk.pop();
    stk.push(15);
    stk.push(p);
    stk.push(5);
    in++;
}

void SyntaxAnalyzer::F28() {
    stk.pop();
    int i = stk.top() - 1;
    stk.pop();
    stack<int> tmp;
    while (i != 0) {
        tmp.push(stk.top());
        stk.pop();
        i--;
    }
    while (stk.top() != 0) {
        tmp.push(stk.top());
        stk.pop();
    }
    stk.pop();
    stk.push(TL[in].TokenValue);
    while (!tmp.empty()) {
        stk.push(tmp.top());
        tmp.pop();
    }
    in++;
}

void SyntaxAnalyzer::a() {
    stk.pop();
    in++;
}

void SyntaxAnalyzer::b() {
    stk.pop();
    int i = stk.top() - 1;
    stk.pop();
    stack<int> tmp;
    while (i != 0) {
        tmp.push(stk.top());
        stk.pop();
        i--;
    }
    stk.pop();
    stk.push(TL[in].TokenValue);
    while (!tmp.empty()) {
        stk.push(tmp.top());
        tmp.pop();
    }
    in++;
}

void SyntaxAnalyzer::c() {
    createAtom(1);
    in++;
}

void SyntaxAnalyzer::d() {
    int k1, k2;
    stk.pop();
    k1 = stk.top();
    stk.pop();
    k2 = stk.top();
    stk.pop();
    createAtom(3, k1, k2);
}

void SyntaxAnalyzer::e() {
    int p, q, r, s;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    s = stk.top();
    stk.pop();
    createAtom(7, p, q, r, s);
}

void SyntaxAnalyzer::f() {
    int p, q;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    createAtom(8, p, q);
}

void SyntaxAnalyzer::g() {
    int p;
    stk.pop();
    p = stk.top();
    stk.pop();
    createAtom(9, p);
}

void SyntaxAnalyzer::h() {
    int p, q, r, s;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    s = stk.top();
    stk.pop();
    createAtom(10, p, q, r, s);
}

void SyntaxAnalyzer::i() {
    int k1, k2;
    stk.pop();
    k1 = stk.top();
    stk.pop();
    k2 = stk.top();
    stk.pop();
    if (k1 != k2)
        error("Переменная в next-операторе отлична от переменной for-оператора.");
    stk.pop();
}

void SyntaxAnalyzer::l() {
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    createAtom(12, p, q, r);
}

void SyntaxAnalyzer::j() {
    int p, q;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    createAtom(11, p, q);
}

void SyntaxAnalyzer::k() {
    int p;
    stk.pop();
    p = stk.top();
    stk.pop();
    createAtom(4, p);
}

void SyntaxAnalyzer::n() {
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    createAtom(14, p, q, r);
}

void SyntaxAnalyzer::m() {
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    createAtom(13, p, q, r);
}

void SyntaxAnalyzer::o() {
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    createAtom(15, p, q, r);
}

void SyntaxAnalyzer::p() {
    int p, q, r;
    stk.pop();
    p = stk.top();
    stk.pop();
    q = stk.top();
    stk.pop();
    r = stk.top();
    stk.pop();
    createAtom(16, p, q, r);
}

void SyntaxAnalyzer::q() {
    int k1, k2;
    stk.pop();
    k1 = stk.top();
    stk.pop();
    k2 = stk.top();
    stk.pop();
    createAtom(17, k1, k2);
}

void SyntaxAnalyzer::r() {
    int k1, k2;
    stk.pop();
    k1 = stk.top();
    stk.pop();
    k2 = stk.top();
    stk.pop();
    createAtom(18, k1, k2);
}

void SyntaxAnalyzer::showStk() {
    stack<int> stk2;
    int k;
    cout << endl << "Содержимое стека:";
    while (!stk.empty()) {
        k = stk.top();
        cout << endl << k;
        stk2.push(k);
        stk.pop();
    }
    while (!stk2.empty()) {
        k = stk2.top();
        stk.push(k);
        stk2.pop();
    }
    cout << endl << "-----------------------------" << endl;
}