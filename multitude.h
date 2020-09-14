#ifndef _MULTITUDE_H_
#define _MULTITUDE_H_
#include <list>
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
class Multitude {
private:
	list<T> mult;
	T check(T num);
	auto getIter(T num);
	auto findplace(T num);
public:
	Multitude() : mult() { };
	Multitude(const Multitude& src) : mult(src.mult) { };
	void clear();
	// void Input();
	void Refill(list<T> src);
	void Set(T num);
	Multitude<T> operator=(const Multitude& b);
	list<T> Get_mult();
	Multitude<T> Get();
	void rmNum(T num);
	Multitude<T> operator+(const Multitude& b);
	Multitude<T> operator-(const Multitude& b);
	void print();
	~Multitude() { this->clear();};
};
#endif

template <class T> T Multitude<T>::check(T num) {                     // return 1 if no number is in / 0 if is not
 	if( this->mult.empty() ){                      					  // O(n)
 		return 1;
 	} else {
 		auto iter = this->mult.begin();
 		while(iter != this->mult.end()) {
 			if(num == *iter){
 				return 0;
 			};
 				iter++;
 		};
 		return 1;
 	};
 };

template <class T>
auto Multitude<T>::getIter(T num){                   // return Iter on num in list
	auto iter = this->mult.begin();                 // O(n)
	while(iter != this->mult.end()){
		if(num == *iter){
			return iter;
		};
		iter++;
	};
	return iter; //unuse
};

template <class T>
auto Multitude<T>::findplace(T num){
	auto iter = this->mult.begin();
	while(iter != this->mult.end()){
		if (num > *iter){
			iter++;
			if(num < *iter){
				return iter;
			};
		} else {
			return this->mult.begin();
		};
	};
	return this->mult.end();
};

template <class T>
void Multitude<T>::clear(){
	while(this->mult.size() != 0) 
		this->mult.pop_back();
};

template <class T>
void Multitude<T>::Refill(std::list<T> src){		
	auto iter = src.begin();
	while(iter != src.end()){
		Set(*iter);
		iter++;
	};
};

template <class T>
void Multitude<T>::Set(T num){                       // push new element if thouse not is in
	if(this->check(num)){
		this->mult.insert(findplace(num), num);	
	};
};

template <class T>
Multitude<T> Multitude<T>::operator=(const Multitude& b){
	this->mult = b.mult;
	Multitude a = *this;
	return a;
};

template <class T>
std::list<T> Multitude<T>::Get_mult(){    		    // return list of this class
	std::list<T> tmp = this->mult;
	return tmp;
};

template <class T>
Multitude<T> Multitude<T>::Get(){
	Multitude a = *this;
	return a;
};

template <class T>
void Multitude<T>::rmNum(T num){                     // remove element if thouse not is in
	if(!this->check(num)){                           // O(2n)
		this->mult.erase(getIter(num));
	};
};

template <class T>
Multitude<T> Multitude<T>::operator+(const Multitude& b){   // additional of set
	Multitude a = *this;                                    // O(n^2)
	auto iterB = b.mult.begin();

	while(iterB != b.mult.end()){
		a.Set(*iterB);
		iterB++;
	};
	return a;
};

template <class T>
Multitude<T> Multitude<T>::operator-(const Multitude& b){ // subtraction of set
	auto iterB = b.mult.begin();                   		  // O(2n^2)
	Multitude a = *this;

	while(iterB != b.mult.end()){
		a.rmNum(*iterB);
		iterB++;
	};
	return a;
};

template <class T>
void Multitude<T>::print() {                        // output to the screen
	auto iter = this->mult.begin();                 // O(n)
	std::cout <<"{  ";
	while(iter != this->mult.end()) {
 		std::cout << *iter << "  ";
 		iter++;
	};
	std::cout <<  "} \n";
};