#include <iostream>
#include <string>
using namespace std;


// Copy constructor
//동일 class obj끼리 =으로 연결 시 obj1 = obj2 
// obj2의 모든 맴버가 obj1 으로 복사된다
// 사람이 당연시 여기는 것 수행하기 위해 abstract 된 것 

// 직접 Copy constructor 정의하는 경우 : deep copy 하고 싶을 때

// shallow copy : 맴버는 다 복사 but 포인터 맴버, 참조자가 가리키는 원본이 동일하다 => 두 obj가 static처럼 값을 공유하게 된다
// deep copy : pointer가 가리키는 원본 주소도 다른 곳에 복사해서 생성된다

class Example5{
    string* ptr; // 포인터면 input이 동적할당이라는 의미로 받아들이자
    public:
        Example5 (const string& str): ptr(new string(str)) {}
        Example5(){};
        ~Example5() { delete ptr;}

        //deep copy constructor , 따로 기호가 있는 것이 아니라 연산자 오버로딩처럼 함수를 만드는 것
        // 이 구현 방식으로 고정되어 있다!!
        Example5 (const Example5& x) : ptr(new string(x.content())){}

        // default copy constructor
        // Example5(const Example5& x) {
        //     ptr = x.ptr;  shallow copy가 된다!

        // }

        //copy assignment (복사 연산자) : = overloading해서 사용
        Example5& operator= (const Example5& x){
            delete ptr; // 이미 들어있는거 삭제
            ptr = new string(x.content());
            return *this; // 자기 자신 obj를 의미한다 
        }


        // default 복사 대입 연산자! 얕은 복사한다
        // Example5& operator= (const Example5& x){
        //     *ptr = x.content();
        //     return *this;
        // }

    
        const string& content() const { return *ptr;}
        void setcontnent(const string& str2){
            *ptr = str2;
        }


};

int main(){
    // Example5 foo{"Example"};
    // Example5 bar = foo;
    // cout << "bar's contennt : " << bar.content() << '\n';
    // bar.setcontnent("I have");
    // cout << "foo's contennt : " << foo.content() << '\n';
    // cout << "bar's contennt : " << bar.content() << '\n';

    Example5 ex1("I love");
    Example5 ex2;
    ex2 = ex1;
    cout << "ex2 content " << ex2.content() << '\n';
    ex2.setcontnent("love");
    cout << "ex1 content " << ex1.content() << '\n';
    cout << "ex2 content " << ex2.content() << '\n';




    return 0;
}

// Copy assignment
// = 연산자 오버로딩으로 구현한다, 복사 생성자와 구분 중요!
// 복사 생성자는 선언과 정의 한줄에 동시에 할 때
// 복사 연산자는 선언과 정의 분리된 경우, 정의할 때 = 으로 정의하는 것

