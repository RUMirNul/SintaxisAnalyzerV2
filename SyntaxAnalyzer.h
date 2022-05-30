#include <stack>
#include "LexicalAnalyzer.h"
////������ ��� ��������� // �������
using namespace std;
class SyntaxAnalyzer : public LexicalAnalyzer {
private:
    stack<int> stk;
    int in; //��������� �� ����
    int mch;//���������� ������
    int num_str; //����� ������� ������
    typedef void(SyntaxAnalyzer::* pfuncType)();


    pfuncType T[20][24]; //����������� �������
    int NTM; //��������� �� ������ ��������� ������� ������� �����
    void printTA(); //������ ������� ������
    void showStk();

public:
    int NTX; //��������� �� ������ ��������� ������� ������� ����������� ����� ��������
    bool flagErr;//���� ����������� ������
    int NTtemp; //��������� �� ������ ��������� ������� � ������� ������������� �����������
    struct atom {
        int type; //��� �����
        int atr1; //������� 1
        int atr2; //������� 2
        int atr3; //������� 3
        int atr4; //������� 4
    };
    atom TA[512]; //������� ������
    int NTA; //��������� �� ������ ��������� ������� ������� ������
    SyntaxAnalyzer();


    //�������� �������-�����
    void createAtom(int, int, int, int, int);

    //������ ������ � ����
    void error(string);

    //------��������� ������ � �������� ��������� ------
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
    //������� �� ����� ������ (������������ ��� �������� ������������)
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



    //��������� �������� �� ��������� ������

    void A() {
        error("��������� ���������� �������.");
    }

    void B() {
        error("�������� ���������� �������.");
    }

    void G1() {
        error("����������� ���� ����� for-���������.");
    }

    void G2() {
        error("������ ������ ������ � ��������� ����� TO.");
    }

    void C() {
        error(" ");
    }

    void D() {
        error("����������� ���� ����� ���������.");
    }

    void K1() {
        error("��������� ��������� - ��� ��������.");
    }

    void K2() {
        error("�������� ����������.");
    }

    void K3() {
        error("� ��������� �������� �������.");
    }

    void K4() {
        error("����������� ���� ����� ���������.");
    }

    void K5() {
        error("��������� ���������� � �����.");
    }

    void K6() {
        error("��� ����� �������� � ���������.");
    }

    void K7() {
        error("� ��������� �������� ���� ��������.");
    }

    void E1() {
        error("����������� ���� � if-���������.");
    }

    void E2() {
        error("if-�������� ����������.");
    }

    void E3() {
        error("������ ������ ������ � ��������� ����� if.");
    }

    void L() {
        error("for-��������� ������� �������. ��������� next");
    }

    void M1() {
        error("����������� ���� � if-���������.");
    }

    void M2() {
        error("if-�������� ����������.");
    }

    void M3() {
        error("��� ����� ��������� � if-���������.");
    }

    void M4() {
        error("������ ������ ������ � ��������� ����� ����� ���������.");
    }

    void H1() {
        error("��������� ������ ������ ����� ������.");
    }

    void H2() {
        error("��������� ������ ������ � ����� ������.");
    }

    void K() {
        error("for-��������� ������� ������� - ������ next.");
    }

    void P1() {
        error("����������� ���� � for-���������.");
    }

    void P2() {
        error("for-�������� ����������.");
    }

    void P3() {
        error("������ ������ ������ � ��������� ����� to.");
    }

    void P4() {
        error("to ��������� ��� �� �� ���� ����� � for-���������.");
    }

    void P() {
        error("��������� ������������ ����� end-���������.");
    }

    void T1() {
        error("��� ���������.");
    }

    void T2() {
        error("�������� end-��������.");
    }

    void T3() {
        error("��������� ��������� ������� ���������.");
    }

    void O() {
        error("������ �����������.");
    }
};

