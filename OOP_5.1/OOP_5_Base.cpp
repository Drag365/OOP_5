#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		printf("Base()\n");
	}

	virtual ~Base() {
		printf("~Base()\n");
	}
	void method1() {
		method2();
	}
	virtual void method2() {
		printf("Base::method2()\n");
	}
	void method3() {
		method4();
	}
	void method4() {
		printf("Base::method4()\n");
	}
};

class Desc :public Base {
private:
	int* arr;
public:
	Desc() {
		arr = new int[42];
		printf("Desc()\n");
	}
	~Desc() {
		delete arr;
		printf("~Desc()\n");
	}
	void method2() override {
		printf("Desc::method2()\n");
	}
	void method4() {
		printf("Desc::method4()\n");
	}
};
int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	printf("Создаем динамически объект класса Desc и удаляем\n");
	Desc* x = new Desc();
	delete x;

	printf("\nСоздаем динамически объект класса Base, помещая в него объект Desc и удаляем\n");
	Base* x1 = new Desc();
	delete x1;

	printf("\nКладем объект потомок Desc в переменную базового класса Base и вызываем виртуальный method2()\n");
	Base* x2 = new Desc();
	x2->method2();

	printf("\nВызываем унаследованный метод Base::method1(), который вызывает виртуальный method2()\n");
	x2->method1();

	printf("\nВызываем унаследованный метод Base::method3(), который вызывает невиртуальный method4()\n");
	x2->method3();

	printf("\nСоздаем динамически объект класса Base\n");
	Base* x3 = new Base();
	printf("\nВызываем у объекта Base невиртуальный метод method4()\n");
	x3->method4();
	printf("\nВызываем у переменной типа Base, хранящего объект Desc, невиртуальный метод method4()\n");
	x2->method4();
	printf("\nВызываем у объекта Base виртуальный метод method2()\n");
	x3->method2();
	printf("\nВызываем у переменной типа Base, хранящего объект Desc, виртуальный метод method2()\n");
	x2->method2();
}

