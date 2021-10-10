#ifndef __rnd__
#define __rnd__

#include <cstdlib>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в диапазоне от 1 до 20
//------------------------------------------------------------------------------

inline auto Random() {
    return rand() % 20 + 1;
}

inline auto RandomDouble() {
    return 10 + (double)(rand()) / ((double)(RAND_MAX/(100 - 10)));
}

#endif //__rnd__
