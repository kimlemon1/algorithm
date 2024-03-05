#include <iostream>
// subclass에서 생성할때 initialization list로 superclass의 var
// 정의 가능하다. 안그럼 private value 정의 못함!!

// pure virtual func이 있으면 아예 해당 class로 객체 만들 수 없다
// virtual func이 private, public 위치에 대한 차이 공부

// 1. superclass private, subclass private : 아예 사용 불가
// 2. super에서 public, sub에서 private : sub에서 사용 불가
// 3. super에서 private, sub에서 public이면 sub에서 사용 가능!
class A{
    private:
        int val;
        virtual void pure_vir(void) = 0;

    public:
        A(int aval){
            val = aval;
        }
        int getval(void){
             return val;
        }
        void setval(int aval){
            val = aval;
        }


};
// subclass 생성자 모두 붙여야 한다! 이때 initialization list로 초기화화
class B: public A{
    private:
        int val2;
        

    public:
        B(int aval1, int aval2):A(aval1){
            val2 = aval2;
        }
        int getval2(void){
            return val2;
        }
        virtual void pure_vir(void){
            std::cout << "Pure" << std::endl;
        }
};

class C: public B{
    private:
        int val3;
    public:
        C(int aval1, int aval2, int aval3):B(aval1, aval2){
            val3 = aval3;
        }
};

int main(){
    //A a(100); pure virtual func이 있으면 abstract class되어 객체 만들수 없다!
    B b(150, 100);
    //C c(1, 2, 3);
    b.pure_vir();
    

    return 0;
}