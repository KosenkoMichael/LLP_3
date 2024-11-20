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
            // Если condition == true, выводим "Access granted"
            puts("Access granted");
        }
        else {
            // Если condition == false, выводим "Access denied" и выходим с кодом ошибки
            puts("Access denied");
        }
    }

    template<typename T>
    void access9(T a, T b, T c) {
        int64_t var_10, var_8;
        uint32_t eax;

        // Сохраняем значения, переданные через r8
        var_10 = a;
        var_8 = b;

        // Проверка значения var_10 (32-битная часть на соответствие 'SASS')
        eax = (uint32_t)(var_10 & 0xFFFFFFFF);
        if (eax == 0x55415353) {  // ASCII: 'SASS'
            // Проверяем var_10+4 на равенство 0
            uint8_t* var_10_high = (uint8_t*)&var_10 + 4;
            if (*var_10_high != 0) {
                // Вызов medium::check с false
                medium_check(false);
                return;
            }
        }

        // Выполнение операций с числами (расстояние между rdx и rcx, преобразование в float)
        int64_t diff = 0 - c;
        float diff_float = (float)diff;

        // Сравнение diff_float с var_8 (предполагаем, что var_8 — float)
        if (diff_float <= *((float*)&var_8)) {
            medium_check(true);  // Вызов medium::check с true
        }
        else {
            medium_check(false); // Вызов medium::check с false
        }
    }
}