/*	
*
*	+------------------------+---------+-----------+--------+
*	|                        | private | protected | public |
*	+------------------------+---------+-----------+--------+
*	| доступ из класса       | открыт  | открыт    | открыт |
*	+------------------------+---------+-----------+--------+
*	| доступ из производного | закрыт  | открыт    | открыт |
*	| класса                 |         |           |        |
*	+------------------------+---------+-----------+--------+
*	| доступ из внешних      | закрыт  | закрыт    | открыт |
*	| функций и классов      |         |           |        |
*	+------------------------+---------+-----------+--------+
*
*/

#include <iostream>


class A {
private:
	void private_method() { std::cout << "A private" << std::endl; };

protected:
	void protected_method() { std::cout << "A protected" << std::endl; };

public:
	void public_method() { std::cout << "A public" << std::endl; };
};


// public- и protected-члены базового доступны как private-члены производного
class B : private A {
public:
	void inh_private();

	void inh_protected();

	void inh_public();
};


// public- и protected-члены базового доступны как protected-члены производного
class C : protected A {
public:
	void inh_private();

	void inh_protected();

	void inh_public();
};


// public-члены базового доступны как public-члены производного; protected-члены базового доступны как protected-члены производного
class D : public A {
public:
	void inh_private();

	void inh_protected();

	void inh_public();
};


int main()
{
	A a;
	B b;
	C c;
	D d;


	//a.private_method();	// недоступно - т.к. private

	//a.protected_method();	// недоступно - т.к. protected

	a.public_method();


	//b.public_method();	// недоступно - наследуется как private

	b.inh_private();		// вызов private- из A

	b.inh_protected();		// вызов protected- из A

	b.inh_public();			// вызов public- из A


	//c.public_method();	// недоступно - наследуется как protected

	c.inh_private();		// вызов private- из A

	c.inh_protected();		// вызов protected- из A

	c.inh_public();			// вызов public- из A


	d.public_method();		// вызов public- из A напрямую

	d.inh_private();		// вызов private- из A

	d.inh_protected();		// вызов protected- из A

	d.inh_public();			// вызов public- из A

	return 0;
}


void B::inh_private()
{
	//private_method();		// недоступно - т.к. private в A
	std::cout << "B private" << std::endl << std::endl;
}


void B::inh_protected()
{
	protected_method();
	std::cout << "B protected" << std::endl << std::endl;
}


void B::inh_public()
{
	public_method();
	std::cout << "B public" << std::endl << std::endl;
}


void C::inh_private()
{
	//private_method();		// недоступно - т.к. private в A
	std::cout << "C private" << std::endl << std::endl;
}


void C::inh_protected()
{
	protected_method();
	std::cout << "C protected" << std::endl << std::endl;
}


void C::inh_public()
{
	public_method();
	std::cout << "C public" << std::endl << std::endl;
}


void D::inh_private()
{
	//private_method();		// недоступно - т.к. private в A
	std::cout << "D private" << std::endl << std::endl;
}


void D::inh_protected()
{
	protected_method();
	std::cout << "D protected" << std::endl << std::endl;
}


void D::inh_public()
{
	public_method();
	std::cout << "D public" << std::endl << std::endl;
}
