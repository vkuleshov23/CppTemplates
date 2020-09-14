#include "multitude.h"
#include <list>

//------private ------//


//------------//



template <class T>
void Multitude::Input(){
	int flag = 0, num = 0;
	int* flag_p = &flag;
	this->clear();

	std::cout << "Input Multitude: ";
	while (!flag){
 		num = input(flag_p);
 		if(flag != 2)
    		this->Set(num);
	};
};

