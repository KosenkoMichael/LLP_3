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
            // ���� condition == true, ������� "Access granted"
            puts("Access granted");
        }
        else {
            // ���� condition == false, ������� "Access denied" � ������� � ����� ������
            puts("Access denied");
        }
    }

    template<typename T>
    void access9(T a, T b, T c) {
        int64_t var_10, var_8;
        uint32_t eax;

        // ��������� ��������, ���������� ����� r8
        var_10 = a;
        var_8 = b;

        // �������� �������� var_10 (32-������ ����� �� ������������ 'SASS')
        eax = (uint32_t)(var_10 & 0xFFFFFFFF);
        if (eax == 0x55415353) {  // ASCII: 'SASS'
            // ��������� var_10+4 �� ��������� 0
            uint8_t* var_10_high = (uint8_t*)&var_10 + 4;
            if (*var_10_high != 0) {
                // ����� medium::check � false
                medium_check(false);
                return;
            }
        }

        // ���������� �������� � ������� (���������� ����� rdx � rcx, �������������� � float)
        int64_t diff = 0 - c;
        float diff_float = (float)diff;

        // ��������� diff_float � var_8 (������������, ��� var_8 � float)
        if (diff_float <= *((float*)&var_8)) {
            medium_check(true);  // ����� medium::check � true
        }
        else {
            medium_check(false); // ����� medium::check � false
        }
    }
}