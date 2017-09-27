#include <iostream>

using namespace std;

class Base{
    public:
        char sex;
        int age;
        virtual void BaseFun1(){
            cout << "Base Fun1" << endl;
        }
        virtual void BaseFun2(){
            cout << "Base Fun2" << endl;
        }
};

class Derive : public Base{
    public:
        char a;
        int b;
        virtual void DeriveFun1(){
            cout << "Derive Fun1" << endl;
        }
        virtual void DeriveFun2(){
            cout << "Derive Fun2" << endl;
        }
};

typedef void(*pFun)(void);

int main()
{
    Derive obj;
    int *vptr = (int *)&obj;
    pFun func1 = (pFun)*((int *)*vptr);
    pFun func2 = (pFun)*((int *)*vptr+1);
    pFun func3 = (pFun)*((int *)*vptr+2);
    pFun func4 = (pFun)*((int *)*vptr+3);
    cout << vptr << endl;
    func1();
    func2();
    func3();
    func4();
    cout << "sizeof Derive :" << sizeof(Derive) << endl;                
    return 0;
}
