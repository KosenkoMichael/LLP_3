#include<iostream>
#include <stdint.h>

using namespace std;
namespace var9 {
	template<typename T>
	struct S {
		T r8 = 0x55415353;
		T r8_10 = 0x00;
		T rdx = 0;
	};

    void medium_check(bool condition) {
        if (condition) {
            puts("Access granted");
        }
        else {
            puts("Access denied");
        }
    }

    template<typename T>
    void access9(T a, T b, T c) {
        int64_t var_10, var_8;
        uint32_t eax;

        var_10 = a;
        var_8 = b;

        eax = (uint32_t)(var_10 & 0xFFFFFFFF);
        if (eax == 0x55415353) {
            uint8_t* var_10_high = (uint8_t*)&var_10 + 4;
            if (*var_10_high != 0) {
                medium_check(false);
                return;
            }
        }

        int64_t diff = 0 - c;
        float diff_float = (float)diff;

        if (diff_float <= *((float*)&var_8)) {
            medium_check(true);
        }
        else {
            medium_check(false);
        }
    }
}