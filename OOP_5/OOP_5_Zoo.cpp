#include <iostream>
using namespace std;

class Animal {
public:
	virtual void sound() = 0;
	virtual string classname() {
		return "Animal";
	}
	virtual bool isA(const string& who) {
		return who == "Animal";
	}
};

class Dog :public Animal {
public:
	string classname() override{
		return "Dog";
	}
	void sound() {
		printf("Wow-wow\n");
	}
	void chaseCat() {
		printf("chaseCat()\n");
	}
	virtual bool isA(const string& who) {
		return who == "Dog" || Animal::isA(who);
	}
};


class Cat :public Animal {
public:
	string classname() override {
		return "Cat";
	}
	void sound() {
		printf("Mew-mew\n");
	}
	void catchMouse() {
		printf("catchMouse()\n");
	}
	virtual bool isA(const string& who) {
		return who == "Cat" || Animal::isA(who);
	}
};

class Manul :public Cat {
public:
	string classname() override {
		return "Manul";
	}
	virtual bool isA(const string& who) {
		return who == "Manul" || Cat::isA(who);
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	//Пример зачем может понадобиться хранить объект в классе предке и использовать виртуальные методы
	printf("Создаем массив объектов Animal, в котором будем хранить предков класса Animal, рандомно записываем в массив объекты Cat, Manul или Dog и в цикле просим каждый объект произнести звук:\n");
	const int ZOO_SIZE = 10;
	Animal* zoo[ZOO_SIZE];

	for (int i = 0; i < ZOO_SIZE; i++) {
		int r = rand() % 3;
		if (r == 0)
			zoo[i] = new Cat();
		else if (r == 1)
			zoo[i] = new Dog();
		else
			zoo[i] = new Manul();
	}

	//for (int i = 0; i < 10; i++)
		//zoo[i]->sound();


	printf("\nВызываем у объектов Саt и предка Cat из нашего массива метод catchMouse() при помощи classname() и небезопасного приведения:\n");
	for (int i = 0; i < ZOO_SIZE; i++)
		if (zoo[i]->classname() == "Cat" || zoo[i]->classname() == "Manul")
			static_cast<Cat*>(zoo[i])->catchMouse();

	printf("\nВызываем у объектов Саt и предка Cat из нашего массива метод catchMouse() при помощи isA() и небезопасного приведения:\n");
	for (int i = 0; i < ZOO_SIZE; i++)
		if (zoo[i]->isA("Cat"))
			static_cast<Cat*>(zoo[i])->catchMouse();

	printf("\nВызываем у объектов Саt и предка Cat из нашего массива метод catchMouse() при помощи безопасного приведения dynamic_cast:\n");
	for (int i = 0; i < ZOO_SIZE; i++) {
		Cat* c = dynamic_cast<Cat*>(zoo[i]);
		if (c != nullptr)
			c->catchMouse();
	}

}

