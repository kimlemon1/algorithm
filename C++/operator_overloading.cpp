#include <iostream>
using namespace std;
// 연산자 오버로딩 
// +, -, = 등 연산자를 해당 class type object끼리 사용 가능하게 만든다 .

// 2가지 방법으로 정의 가능 
// 1. class 내부 member function으로 정의

// class CVector {
//     public:
//         int x, y;
//         CVector() {}; // default constructor
//         CVector(int a, int b): x(a), y(b) {} // initialization list
//         CVector operator + (const CVector&); // 연산자 오버로딩도 함수다 operator {연산자 기호} 형식으로 헤더
// };

// CVector CVector::operator+ (const CVector& param){
//     CVector temp;
//     temp.x = x + param.x; // x : 자신의 맴버 변수, param.x : argument의 x 
//     temp.y = y + param.y;
//     return temp;
// }

// int main(){
//     CVector foo(3,1);
//     CVector bar(1,2);
//     CVector result; // 파이썬과 다르게 출력값을 저장할 공간을 밖에서 만들어야 한다
//     result = foo + bar;
//     cout << result.x << " " << result.y << endl;

//     return 0;
// }

// // 2. class 밖 non member function으로 정의: 그냥 class 밖에서 2개의 데이터 받아서 출력

// CVector operator+ (const CVector& first, const CVector& second){
//     CVector temp;
//     temp.x = first.x + second.x;
//     temp.y = first.x + second.y;
//     return temp;
// }

// // 1과 2 둘 중 한가지 방식만 사용해야 한다!! 둘 다 쓰면 에러 발생 



// static : gloabal 영역에 생성, 프로그램 끝날 때까지 존재하는 함수 또는 변수
// const : 값이 바뀌지 않는 값, 초기화 필수, 메모리에 바로 저장됨

// 3. Static members
// static 변수 : global variable로 정의되며 영역을 벗어나도 사라지지 않는다

// 3.1 class에서 정적 변수 : static member variable(class variable)
// 모든 객체가 동일한 주소의 변수를 공유한다 
// 객체 생성 전부터 전역 변수에 저장되어 있다 => 객체 생성 이전, main 밖에서 초기화 필수!!(전역 범위에서 초기화)
// class 내부에서 초기화도 불가능함
// class의 영역 제한 규칙 효과 받는다

// 3.2 class에서 정적 함수 : static member function
//다른 non-static member를 부를 수 없다, this 포인터 사용할 수 없다
// 모든 object에서 함께 사용한다
// but class의 영역 제한 규칙은 적용된다!! 따라서 public이 아니면 외부에서는 못 건든다 (global variable이지만 영역에 
// 제한이 생기니까 사용한다)
// static func는 static 인 맴버만 사용 가능하다! 
// 

// static member들은 object 없어도 class 이름으로 부를 수 있다. (영역 확인 필요)


class Dummy{
    public:
        static int n; // 항상 static은 전역에서 정의해야 한다
        Dummy(){n++;}; // 모든 object가 공유, 동일한 주소의 값에 계속 더한다
    //private:
    //    static int n; // 만일 private에 있다면 전역변수임에도 밖에서 그냥 접근하지 못한다!!

        static int get_static(void){ // static member function : 오직 static member만 사용할 수 있다!
            return n;
        }
};

int Dummy::n = 0; // 초기화, object가 아니니 ::을 사용해야 한다
// private이어도 전역에서 정의 가능

int main(){
    Dummy a; // n = 1
    Dummy b[5]; // 5개 생성! n =6
    cout << a.n << '\n';
    Dummy* c = new Dummy; //n = 7
    cout << Dummy::n << '\n';
    delete c;

    cout << Dummy::get_static() << endl;
    return 0;
}

// static const : class내에서 초기화 가능! 왜냐하면 앞으로 변하지 않는 값
// 변하지 않는 값이며 전역변수(모든 object가 동일 메모리 사용) + access specifier영향도 받는다 