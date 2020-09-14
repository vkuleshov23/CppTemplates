#include "multitude.h"
#include <iostream>

using namespace std;

int main(){

	Multitude<char> d;
	d.Set('a'); d.Set('b'); d.Set('c'); d.Set('A');d.Set('E'); d.Set('d'); d.rmNum('b'); d.rmNum('c'); d.rmNum('f'); d.rmNum('C');
	cout << "Multitude<char> d: "; d.print();


	Multitude<char> e;
	e.Set('a'); e.Set('h'); e.Set('i'); e.Set('a'); e.Set('A'); e.Set('b'); e.Set('b'); e.rmNum('i'); e.rmNum('a'); e.rmNum('B'); e.rmNum('z');
	cout << "Multitude<char> e: "; e.print();

	Multitude<char> f = d + e;
	cout << "Multitude<char> f = d + e: "; f.print();

	Multitude<char> g = e - d;
	cout << "Multitude<char> g = e - d: "; g.print();

	Multitude<char> h = d - e;
	cout << "Multitude<char> h = d - e: "; h.print();

	Multitude<double> c;
	double num = 7.1, num2 = 2.2, num3 = 1.6, num4 = 4.9;
	c.Set(num); c.Set(num2); c.Set(num3); c.Set(num4); c.Set(num);
	cout << "Multitude<double> c: "; c.print();

	Multitude<double> a(c);
	cout << "Multitude<double> a(c): "; a.print();

	Multitude<double> j;
	j.Set(12.1); j.Set(11.2); j.Set(2.3); j.Set(2.2); j.Set(10.4); j.Set(7.1); j.Set(2.3); j.Set(5.523); j.Set(7.6); j.Set(4.9); j.rmNum(2.9);
	cout << "Multitude<double> j: "; j.print();

	Multitude<double> k = a + j;
	cout << "Multitude<double> k = a + j: "; k.print();

	Multitude<double> l = a - j;
	cout << "Multitude<double> l = a - j: "; l.print();

	Multitude<double> m = j - a;
	cout << "Multitude<double> m = j - a: "; m.print();

	Multitude<int> b;
	b.Set(12); b.Set(11); b.Set(2); b.Set(2); b.Set(10); b.Set(23); b.Set(18); b.Set(23); b.Set(12); b.Set(4); b.rmNum(2);
	cout << "Multitude<int> b: "; b.print();

	Multitude<int> i = b;
	cout << "Multitude<int> i = b: "; i.print();
	i.clear();
	cout << "i.clear(): "; i.print();

	list<int> list_ = b.Get_mult();

	Multitude<int> n;
	n.Set(1); n.Set(2); n.Set(3); n.Set(4);
	cout << "Multitude<int> n: "; n.print();

	n.Refill(list_);
	cout << "n.Refill(list_(b): "; n.print();

	Multitude<int> q;
	q.Set(4); q.Set(10); q.Set(11); q.Set(12); q.Set(18); q.Set(23);

	Multitude<int> p;
	p.Set(1); p.Set(2); p.Set(5); p.Set(3); p.Set(4); p.Set(11); p.Set(12); p.Set(18);

	Multitude<int> x;
	x.clear();
	x = q - p;
	x.print();
	c.clear();
	x = p - q;
	x.print();

	return 0;
};

// Доп: Set -> шаблон; (template <class T>);