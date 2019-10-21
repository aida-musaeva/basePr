#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class pet {
public:
	virtual void eat() = 0;		//polymorphism
	virtual void sleep() = 0;
	virtual void play() = 0;
	void setAge(unsigned int a) //encapsulation
	{
		age = a;
	}
protected:
	unsigned int age;
};

class cat : public pet {		//inheritance
public:
	cat(string s) :name(s)
	{
	}
	void eat()
	{
		cout << "cat eat" << endl;
	}
	void play()
	{
		cout << "cat play" << endl;
	}
	void sleep()
	{
		cout << "cat sleep" << endl;
	}
	void mew()
	{
		cout << "Meow!" << endl;
	}
	string name;
};
class dog : public pet {
public:
	dog(string s) :name(s) {

	}
	void eat()
	{
		cout << "dog eat" << endl;
	}
	void play()
	{
		cout << "dog play" << endl;
	}
	void sleep()
	{
		cout << "dog sleep" << endl;
	}
	string name;
	void bark()
	{
		cout << "Woof!" << endl;
	}
};
int main()
{
	cat Barsik("Barsik");
	dog Rex("Rex");
	pet *p1 = &Barsik;
	pet *p2 = &Rex;
	p1->setAge(1);
	p2->setAge(2);
	p1->eat();
	p2->sleep();
	return 0;
}
