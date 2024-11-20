#include<iostream>
#include <stdint.h>
#include <stdbool.h>

using namespace std;

namespace var3 {
    void check(bool flag) {
        printf(flag ? "access granted" : "access denied");
    }
    template<typename T>
    struct S {
        int rdx_8 = 10;
    };
    template<typename T>
    class C {
    public:
        int first = 1;
        int second = 2;
        int third = 10;
        int fourth = 1;
        bool hard_check(S<T>* srtuctur) {
            auto r9 = this;
            auto r10 = this->second;
            auto edx = 0x128E3FB9;
            int i = 0;
            int eax=0;
            int r8=0;
            while (1) {
                r8 = reinterpret_cast<uintptr_t>(r9) & 9;
                if (r8 == 0)           
                    break;

                eax = (int)(int8_t)r8;  
                r9++;                    
                eax ^= edx;            
                eax *= this->first; // [rcx]
                edx = 0;                 
                eax += this->second; // [rcx + 4]
                eax /= this->third;  // [rcx + 8]

                if (++i == r10)
                    break;
            }
            if (this->fourth == eax) {
                return true;
            }
            else {
                return false;
            }
        }
    };
    template<typename T>
    void access3(C<T>* clas, S<T>* structur) {
        auto r13 = clas; // rcx
        auto r12 = structur; // rdx
        if (structur == nullptr) {
            check(false);
            return;
        }
        if (structur->rdx_8 <= 9) {
            check(false);
            return;
        }
        check(clas->hard_check(structur));
    }
}