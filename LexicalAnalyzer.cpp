#include "LexicalAnalyzer.h"
//ТОЛЬКО ДЛЯ КОДИРОВКИ // УДАЛИТЬ
LexicalAnalyzer::LexicalAnalyzer() : InitialVector(26), Table(26), TL(512), TS(512),
ferr("Errors.txt") {
    for (int i = 1; i <= 1024; i++)
        TO[i] = 0;
    pfunc = &LexicalAnalyzer::A1;
    NTO = 287;
    NTL = 1;
    NTS = 1;
    RZ = 1;
    RI = RCH = RP = RS = RSE = 0;

    InitialVector[0] = 0;
    InitialVector[1] = 0;
    InitialVector[2] = 0;
    InitialVector[3] = 0;
    InitialVector[4] = 1;
    InitialVector[5] = 3;
    InitialVector[6] = 5;
    InitialVector[7] = 0;
    InitialVector[8] = 11;
    InitialVector[9] = 0;
    InitialVector[10] = 0;
    InitialVector[11] = 12;
    InitialVector[12] = 0;
    InitialVector[13] = 14;
    InitialVector[14] = 0;
    InitialVector[15] = 0;
    InitialVector[16] = 0;
    InitialVector[17] = 17;
    InitialVector[18] = 23;
    InitialVector[19] = 26;
    InitialVector[20] = 0;
    InitialVector[21] = 0;
    InitialVector[22] = 0;
    InitialVector[23] = 0;
    InitialVector[24] = 0;
    InitialVector[25] = 0;

    for (int i = 0; i < 26; ++i) {
        Table[i].alternativa = 0;
        Table[i].pfunc = &LexicalAnalyzer::next;
    }
    Table[5].alternativa = 8;
    Table[17].alternativa = 22;
    Table[0].leter = 14;
    Table[1].leter = 4;
    Table[1].pfunc = &LexicalAnalyzer::A2q;
    Table[2].leter = 15;
    Table[3].leter = 18;
    Table[3].pfunc = &LexicalAnalyzer::F1b;
    Table[4].leter = 15;
    Table[5].leter = 20;
    Table[6].leter = 15;
    Table[6].pfunc = &LexicalAnalyzer::E1a;
    Table[7].leter = 19;
    Table[8].leter = 21;
    Table[9].leter = 2;
    Table[9].pfunc = &LexicalAnalyzer::E1b;
    Table[10].leter = 6;
    Table[10].pfunc = &LexicalAnalyzer::A2r;
    Table[11].leter = 5;
    Table[12].leter = 20;
    Table[12].pfunc = &LexicalAnalyzer::F1a;
    Table[13].leter = 5;
    Table[14].leter = 24;
    Table[15].leter = 20;
    Table[15].pfunc = &LexicalAnalyzer::C1a;
    Table[16].leter = 5;
    Table[17].leter = 20;
    Table[18].leter = 21;
    Table[19].leter = 18;
    Table[20].leter = 14;
    Table[20].pfunc = &LexicalAnalyzer::A2s;
    Table[21].leter = 13;
    Table[21].pfunc = &LexicalAnalyzer::G1a;
    Table[22].leter = 20;
    Table[23].leter = 5;
    Table[24].leter = 16;
    Table[24].pfunc = &LexicalAnalyzer::A2t;
    Table[25].leter = 15;
    Table[25].pfunc = &LexicalAnalyzer::A2u;
}

void LexicalAnalyzer::Start(char* filename) {
    ifstream fin(filename);
    if (!fin)
        throw 1;
    while (!fin.eof()) {
        getline(fin, str);
        str += '\n';
        Parse();
    }
    End();
    fin.close();
}

void LexicalAnalyzer::Parse() {
    for (int i = 0; i < str.size(); ++i) {
        Trans(str[i]);
        (this->*pfunc)();
    }
}

void LexicalAnalyzer::Trans(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        RK = Letter;
        RZN = ch - 'a' + 1;
    }
    if (ch >= 'A' && ch <= 'Z') {
        RK = Letter;
        RZN = ch - 'A' + 1;
    }
    if (ch >= '0' && ch <= '9') {
        RK = Digit;
        RZN = ch - '0';
    }
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        RK = Ar_oper;
        if (ch == '+')
            RZN = 1;
        else if (ch == '-')
            RZN = 2;
        else if (ch == '*')
            RZN = 3;
        else if (ch == '/')
            RZN = 4;
        else
            RZN = 5;
    }
    if (ch == ' ' || ch == '\t')
        RK = Space;
    if (ch == '.')
        RK = Point;
    if (ch == '\n')
        RK = CR;
    if (ch == '(')
        RK = Left_bracket;
    if (ch == ')')
        RK = Right_bracket;
    if (ch == '<' || ch == '>' || ch == '=') {
        RK = Attitude;
        if (ch == '=')
            RZN = 1;
        else if (ch == '<')
            RZN = 2;
        else
            RZN = 3;
    }
}

void LexicalAnalyzer::End() {
    if (pfunc == &LexicalAnalyzer::A1 || pfunc == &LexicalAnalyzer::A2 || pfunc == &LexicalAnalyzer::A3 ||
        pfunc == &LexicalAnalyzer::G1)
        pfunc = &LexicalAnalyzer::exit1;
    else if (pfunc == &LexicalAnalyzer::C1 || pfunc == &LexicalAnalyzer::D1)
        pfunc = &LexicalAnalyzer::exit3;
    else if (pfunc == &LexicalAnalyzer::C2 || pfunc == &LexicalAnalyzer::D2)
        pfunc = &LexicalAnalyzer::exit4;
    else if (pfunc == &LexicalAnalyzer::H1)
        pfunc = &LexicalAnalyzer::exit2;
    else if (pfunc == &LexicalAnalyzer::D5)
        pfunc = &LexicalAnalyzer::exit5;
    else
        pfunc = &LexicalAnalyzer::error2;
    (this->*pfunc)();
    SaveTableLex();
    SaveTableOperand();
    SaveTableString();
    ferr.close();
}


void LexicalAnalyzer::CreateToken() {
    Token t;
    t.TokenClass = RKL;
    t.TokenValue = -1;
    if (RKL == ROWLABEL || RKL == GOTO || RKL == GOSUB) {
        bool flag = true;
        for (int i = 1; i < NTS; i++) {
            if (TS[i] == RSTR) {
                t.TokenValue = i;
                flag = false;
                break;
            }
        }
        if (flag) {
            TS[NTS] = RSTR;
            t.TokenValue = NTS;
            NTS++;
        }
        RSTR = 0;
    }
    if (RKL == OPERAND || RKL == NEXT) {
        if (RI != 0) {
            int n;
            if (RK == Digit)
                n = RI + 26 * (RZN + 1);
            else
                n = RI;
            TO[n] = 1;
            t.TokenValue = n;
            RI = 0;
        }
        else {
            int n;
            if (RZ == 1)
                n = RCH * pow(10, RP - RS);
            else
                n = RCH / pow(10, RP + RS);
            RCH = RP = RS = 0;
            RZ = 1;
            for (int i = 287; i < NTO; i++)
                if (TO[i] == n) {
                    t.TokenValue = i;
                    TL[NTL] = t;
                    NTL++;
                    return;
                }
            TO[NTO] = n;
            t.TokenValue = NTO;
            NTO++;
        }
    }
    if (RKL == LET || RKL == FOR) {
        TO[RI] = 1;
        t.TokenValue = RI;
        RI = 0;
    }
    if (RKL == AR_OPER)
        t.TokenValue = RZN;
    if (RKL == ATTITUDE)
        t.TokenValue = ROT;
    TL[NTL] = t;
    NTL++;
}

void LexicalAnalyzer::A1() {
    switch (RK) {
    case Digit:
        E2a();
        break;
    case Space:
        break;
    case CR:
        break;
    default:
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::A2() {
    switch (RK) {
    case Letter:
        C2a();
        break;
    case Digit:
        D1a();
        break;
    case Ar_oper:
        A2a();
        break;
    case Attitude:
        H1a();
        break;
    case Left_bracket:
        A2h();
        break;
    case Right_bracket:
        A3b();
        break;
    case Point:
        D6b();
        break;
    case Space:
        break;
    case CR:
        pfunc = &LexicalAnalyzer::A1;
        break;
    }
}

void LexicalAnalyzer::A3() {
    switch (RK) {
    case Letter:
        B1a();
        break;
    case Digit:
        D1a();
        break;
    case Ar_oper:
        A2a();
        break;
    case Attitude:
        H1a();
        break;
    case Left_bracket:
        A2h();
        break;
    case Right_bracket:
        A3b();
        break;
    case Point:
        D6b();
        break;
    case Space:
        break;
    case CR:
        pfunc = &LexicalAnalyzer::A1;
        break;
    }
}

void LexicalAnalyzer::B1() {
    switch (RK) {
    case Letter:
        M1();
        break;
    case Space:
        break;
    case CR:
        A1f();
        break;
    default:
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::C1() {
    switch (RK) {
    case Letter:
        C2d();
        break;
    case Space:
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::C2() {
    switch (RK) {
    case Letter:
        B1b();
        break;
    case Digit:
        A3a();
        break;
    case Ar_oper:
        A2g();
        break;
    case Attitude:
        H1b();
        break;
    case Left_bracket:
        A2k();
        break;
    case Right_bracket:
        A3c();
        break;
    case Space:
        break;
    case CR:
        A1a();
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::D1() {
    switch (RK) {
    case Letter:
        M2();
        break;
    case Digit:
        D1b();
        break;
    case Ar_oper:
        A2c();
        break;
    case Attitude:
        H1c();
        break;
    case Left_bracket:
        A2l();
        break;
    case Right_bracket:
        A3d();
        break;
    case Point:
        D2c();
        break;
    case Space:
        break;
    case CR:
        A1b();
        break;
    }
}

void LexicalAnalyzer::D2() {
    switch (RK) {
    case Letter:
        M3();
        break;
    case Digit:
        D2a();
        break;
    case Ar_oper:
        A2c();
        break;
    case Attitude:
        H1c();
        break;
    case Left_bracket:
        A2l();
        break;
    case Right_bracket:
        A3d();
        break;
    case Space:
        break;
    case CR:
        A1c();
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::D3() {
    switch (RK) {
    case Digit:
        D5a();
        break;
    case Ar_oper:
        D4a();
        break;
    case Space:
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::D4() {
    switch (RK) {
    case Digit:
        D5b();
        break;
    case Space:
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::D5() {
    switch (RK) {
    case Letter:
        B1c();
        break;
    case Digit:
        D5c();
        break;
    case Ar_oper:
        A2c();
        break;
    case Attitude:
        H1c();
        break;
    case Left_bracket:
        A2l();
        break;
    case Right_bracket:
        A3d();
        break;
    case Space:
        break;
    case CR:
        A1d();
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::D6() {
    switch (RK) {
    case Digit:
        D2b();
        break;
    case Space:
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::E1() {
    switch (RK) {
    case Digit:
        E2b();
        break;
    case Space:
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::E2() {
    switch (RK) {
    case Letter:
        B1e();
        break;
    case Digit:
        E2c();
        break;
    case Attitude:
        H1f();
        break;
    case Space:
        break;
    case Ar_oper:
        A2f();
        break;
    case Left_bracket:
        A2j();
        break;
    case Right_bracket:
        A3g();
        break;
    case CR:
        A1e();
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::F1() {
    switch (RK) {
    case Letter:
        F2a();
        break;
    case Space:
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::F2() {
    switch (RK) {
    case Digit:
        F3a();
        break;
    case Attitude:
        A2o();
        break;
    case Space:
        break;
    default:
        G1b();
    }
}

void LexicalAnalyzer::F3() {
    switch (RK) {
    case Attitude:
        A2o();
        break;
    case Space:
        break;
    default:
        RSE++;
        G1b();
    }
}

void LexicalAnalyzer::G1() {
    switch (RK) {
    case CR:
        pfunc = &LexicalAnalyzer::A1;
        break;
    default:
        pfunc = &LexicalAnalyzer::G1;
    }
}

void LexicalAnalyzer::H1() {
    switch (RK) {
    case Letter:
        C2b();
        break;
    case Digit:
        D1c();
        break;
    case Ar_oper:
        A2g();
        break;
    case Attitude:
        A2p();
        break;
    case Left_bracket:
        A2k();
        break;
    case Right_bracket:
        A3c();
        break;
    case Point:
        D6a();
        break;
    case Space:
        break;
    case CR:
        A1a();
        break;
    }
}

void LexicalAnalyzer::SaveTableLex() {
    ofstream fout("TableTokens.txt");
    if (!fout)
        throw 1;
    char Tclass[19][15] = { "LABEL", "OPERAND", "ATTITUDE", "NEXT", "LET", "FOR", "GOTO", "GOSUB", "LEFTBRACKET",
                           "RIGHTBRACKET", "IF", "RETURN", "END", "TO", "STEP", "REM", "ERROR", "ENDMARCER",
                           "OPERATION" };
    for (int i = 1; i < NTL; i++) {
        fout.width(3);
        fout << i - 1 << "   " << Tclass[TL[i].TokenClass - 1] << " " << TL[i].TokenValue << endl;
    }
    fout.close();
}

void LexicalAnalyzer::SaveTableOperand() {
    ofstream fout("TableOperands.txt");
    if (!fout)
        throw 1;
    for (int i = 1; i < 287; ++i) {
        fout.width(3);
        if (TO[i])
            fout << i << ' ' << TO[i] << endl;
    }
    for (int i = 287; i < NTO; ++i) {
        fout.width(3);
        fout << i << ' ' << TO[i] << endl;
    }
    fout.close();
}

void LexicalAnalyzer::SaveTableString() {
    ofstream fout("TableStrings.txt");
    if (!fout)
        throw 1;
    for (int i = 1; i < NTS; ++i) {
        fout.width(3);
        fout << i << " " << TS[i] << endl;
    }
    fout.close();
}