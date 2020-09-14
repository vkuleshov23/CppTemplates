#include "input.h"
#include <iostream>
#include <vector>
#define diaps(a) ( ( ( (a) >= '0') && ( (a) <= '9') ) || ( (a) == '-') )

int input(int* flag_p) {
    char c;
    int num = 0;

    std::vector<char> v;

    while ((c = getchar()) != '\n' && !diaps(c));

    if (c != '\n') {
        v.push_back(c);
    } else {
        *flag_p = 2;
        return 0;
    }

    while ((c = getchar()) != '\n' && diaps(c)) {
        v.push_back(c);
    }

    v.push_back('\0');
    if (c == '\n')
        *flag_p = 1;

    num = atoi(&v[0]);
    v.clear();
    return num;
}
