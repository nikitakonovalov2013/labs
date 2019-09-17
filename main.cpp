#include <iostream>
#include <cstring>
#include <cctype>

#include "bignum.h"

int main() {
    long int num_l = 0;
    char num_c[80];
    cout << "Введите число (цифра): ";
    cin >> num_l;
    cout << "Введите число (строка): ";
    cin >> num_c;
    BigNum big_num_c= BigNum(num_c);
    BigNum big_num_l= BigNum(num_l);
    cout << "Число long: " << big_num_l; 
    cout << "Число char: " << big_num_c;
    cout << "Дополнительный код: " << (~big_num_c);
    return 0;
}