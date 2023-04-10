#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		printf("Base()\n");
	}
	Base(Base *obj) {
		printf("Base(Base *obj)\n");
	}
	Base(Base &obj) {
		printf("Base(Base &obj)\n");
	}
	Base(const Base& obj) {
		printf("Base(const Base &obj)\n");
	}
	virtual ~Base() {
		printf("~Base()\n");
	}
};

class Desc :public Base {
public:
	Desc() {
		printf("Desc()\n");
	}
	Desc(Desc *obj) {
		printf("Desc(Desc *obj)\n");
	}
	Desc(Desc &obj) {
		printf("Desc(Desc &obj)\n");
	}
	Desc(const Desc& obj) {
		printf("Desc(const Desc &obj)\n");
	}
	~Desc() {
		printf("~Desc()\n");
	}

};

void func1(Base obj);
void func2(Base *obj);
void func3(Base &obj);

Base out1();
Base out2();
Base* out3();
Base* out4();
Base& out5();
Base& out6();

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	printf("Создаем объект класса Base\n");
	Base x1;

	printf("\nСоздаем динамически объект класса Base\n");
	Base *x2 = new Base();

	printf("\nВызываем func1(Base obj) передававая статический Base объект func1(x1):\n");
	func1(x1);

	printf("\nВызываем func2(Base *obj) передававая статический Base объект func2(&x1):\n");
	func2(&x1);

	printf("\nВызываем func3(Base &obj) передававая статический Base объект func3(x1):\n");
	func3(x1);

	printf("\nВызываем func1(Base obj) передававая динамический Base объект func1(*x2):\n");
	func1(*x2);

	printf("\nВызываем func2(Base *obj) передававая динамический Base объект func2(x2):\n");
	func2(x2);

	printf("\nВызываем func3(Base &obj) передававая динамический Base объект func3(*x2):\n");
	func3(*x2);

	printf("Создаем объект класса Desc\n");
	Desc x3;

	printf("\nВызываем func1(Base obj) передававая статический Desc объект func1(x3):\n");
	func1(x3);

	printf("\nВызываем func2(Base *obj) передававая статический Desc объект func2(&x3):\n");
	func2(&x3);

	printf("\nВызываем func3(Base &obj) передававая статический Desc объект func3(x3):\n");
	func3(x3);

	printf("\nСоздаем динамически объект класса Desc\n");
	Desc* x4 = new Desc();

	printf("\nВызываем func1(Base obj) передававая динамический Desc объект func1(*x4):\n");
	func1(*x4);

	printf("\nВызываем func2(Base *obj) передававая динамический Desc объект func2(x4):\n");
	func2(x4);

	printf("\nВызываем func3(Base &obj) передававая динамический Desc объект func3(*x4):\n");
	func3(*x4);

	

	printf("\nВыполняем: Base b1 = out1():\n");
	Base b1 = out1();
	printf("\nВыполняем: Base b2 = out2():\n");
	Base b2 = out2();
	printf("\nВыполняем: Base *b3 = out3():\n");
	Base *b3 = out3();
	printf("\nВыполняем: Base* b4 = out4():\n");
	Base* b4 = out4();
	printf("\nВыполняем: Base& b5 = out5():\n");
	Base& b5 = out5();
	printf("\nВыполняем: Base& b6 = out6():\n");
	Base& b6 = out6();

	printf("\nВыполняем: Base b7; b7 = out1():\n");
	Base b7;
	b7 = out1();
	printf("\nВыполняем: Base b8; b8 = out2():\n");
	Base b8;
	b8 = out2();
	printf("\nВыполняем: Base b9; b9 = out3():\n");
	Base b9;
	b9 = out3();
	printf("\nВыполняем: Base b10; b10 = out4():\n");
	Base b10;
	b10 = out4();
	printf("\nВыполняем: Base b11; b11 = out5():\n");
	Base b11;
	b11 = out5();
	printf("\nВыполняем: Base b12; b12 = out6():\n");
	Base b12;
	b12 = out6();
	printf("\nВыход из программы:\n");

	
}

void func1(Base obj) {
	printf("func1(Base obj)\n");
}
void func2(Base *obj) {
	printf("func1(Base *obj)\n");
}
void func3(Base &obj) {
	printf("func1(Base &obj)\n");
}
Base out1() {
	Base b;
	return b;
}
Base out2() {
	Base* b = new Base();
	return *b;
};
Base* out3() {
	Base b;
	return &b;
};
Base* out4() {
	Base* b = new Base();
	return b;
};
Base& out5() {
	Base b;
	return b;
};
Base& out6() {
	Base* b = new Base();
	return *b;
};