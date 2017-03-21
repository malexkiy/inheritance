/*	
*
*	+------------------------+---------+-----------+--------+
*	|                        | private | protected | public |
*	+------------------------+---------+-----------+--------+
*	| ������ �� ������       | ������  | ������    | ������ |
*	+------------------------+---------+-----------+--------+
*	| ������ �� ������������ | ������  | ������    | ������ |
*	| ������                 |         |           |        |
*	+------------------------+---------+-----------+--------+
*	| ������ �� �������      | ������  | ������    | ������ |
*	| ������� � �������      |         |           |        |
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


// public- � protected-����� �������� �������� ��� private-����� ������������
class B : private A {
public:
	void inh_private();

	void inh_protected();

	void inh_public();
};


// public- � protected-����� �������� �������� ��� protected-����� ������������
class C : protected A {
public:
	void inh_private();

	void inh_protected();

	void inh_public();
};


// public-����� �������� �������� ��� public-����� ������������; protected-����� �������� �������� ��� protected-����� ������������
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


	//a.private_method();	// ���������� - �.�. private

	//a.protected_method();	// ���������� - �.�. protected

	a.public_method();


	//b.public_method();	// ���������� - ����������� ��� private

	b.inh_private();		// ����� private- �� A

	b.inh_protected();		// ����� protected- �� A

	b.inh_public();			// ����� public- �� A


	//c.public_method();	// ���������� - ����������� ��� protected

	c.inh_private();		// ����� private- �� A

	c.inh_protected();		// ����� protected- �� A

	c.inh_public();			// ����� public- �� A


	d.public_method();		// ����� public- �� A ��������

	d.inh_private();		// ����� private- �� A

	d.inh_protected();		// ����� protected- �� A

	d.inh_public();			// ����� public- �� A

	return 0;
}


void B::inh_private()
{
	//private_method();		// ���������� - �.�. private � A
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
	//private_method();		// ���������� - �.�. private � A
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
	//private_method();		// ���������� - �.�. private � A
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
