#include "bignum.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <signal.h>

//Конструкторы и деструктор:
BigNum::BigNum(const BigNum& big_num) {
	sign = big_num.sign;
	num_init(big_num.value);
}

BigNum::BigNum(long int num) {
	set_sign(num);
	num = abs(num);
	num_to_char_array(num);
}

BigNum::BigNum(char *num_val) {
	char * num = validate_char_input(num_val);
	set_sign(num);
	num_init(num);
}

BigNum::~BigNum() {}


/* *** Методы класса *** */
      
/* Private: */
void BigNum::num_init(const char *num){
	for (int i = 0; i < (size - strlen(num)); i++){
		value[i] = 0 + CHAR_TO_INT;
	}
	for (int i = size - 1, j = strlen(num); i >= (size - strlen(num)); i--, j--) {
		value[i] = num[j];
	}
}

void BigNum::set_sign(long int num) {
	if (num >= 0) {
		sign = POSITIVE;
		return;
	}
	sign = NEGATIVE;
}

void BigNum::set_sign(char *num) {	
	if (num[0] == MINUS_CHAR) {
		sign = NEGATIVE;
		return;
	}
	sign = POSITIVE;
}

bool BigNum::is_negative() const{
	return sign == NEGATIVE;
}

bool BigNum::is_positive() const{
	return sign == POSITIVE;
}

void BigNum::num_to_char_array(long int num){
	int i = size-1;
	do {
		value[i] = (num % BASE) + CHAR_TO_INT;
		num = num / BASE;
		i--;
	} while (num > 0);
	while (i >= 0) {
		value[i] = 0 + CHAR_TO_INT;
		i--;
	}
	value[size] = '\0';
}
 
char * BigNum::validate_char_input(char * input) { 
	char *tmp = new char (strlen(input));
	int i = 0;
	if (input[0] == '-') {
		tmp[0] = '-';
		i++;
	}
	int j = i;
	for (; i < strlen(input); i++) {
		if (isdigit(input[i])) {
			tmp[j] = input[i];
			j++;
		}
	}
	return tmp;

}

//TODO:
BigNum BigNum::add(const BigNum& big_num) {

}

bool BigNum::is_subtract(const BigNum& big_num) {
	// Проверяет такие случаи как "20 + (-20)"
	if (big_num.is_negative() && is_positive()) {
		return true;
	}
	return false;
}

BigNum BigNum::twoscomp(void) {
	if (sign == POSITIVE) {
		return *this;
	}
	for (int i = 0; i < size; i++) {
		value[i] = (BASE - 1 - (value[i] - CHAR_TO_INT)) + CHAR_TO_INT;
	}
	return *this;
}





/* Public: */
//TODO:???
istream& operator>>(istream & istr, BigNum big_num){
	
}

ostream& operator<<(ostream& str, const BigNum& big_num){
	if (strlen(big_num.value) > 0 && big_num.size > 0) {
		if (big_num.is_negative()) {
			str << BigNum::MINUS_CHAR;
		}
		for (int i = 0; i < big_num.size; i++) {
			str << big_num.value[i];
		}
	}
	str << endl;
	return str;
}

BigNum BigNum::operator ~ (void){
	BigNum result = BigNum(*this);
	result.twoscomp();
	return result;
}

/*
BigNum BigNum::operator = (const BigNum& big_num) {
	if (*this != big_num) {
		delete[] value;
		size = big_num.size;
		sign = big_num.sign;
		value = new char[size + 1];
		strcpy(value, big_num.value);
	}
	return *this;
}

BigNum BigNum::operator = (char* arr) {
	if (strcmp(value, arr) != 0) {
		BigNum *big_num = new BigNum(arr);
		return *big_num;
	}
	return *this;
}

BigNum BigNum::operator = (long num) {
	BigNum *big_num = new BigNum(num);
	if (*this != *big_num) {
		return *big_num;
	}
	delete big_num;
	return *this;
}

BigNum BigNum::operator+ (const BigNum& big_num) {
	if (is_subtract(big_num)) {
		return *this - big_num;
	}
	return addition(big_num);
}

BigNum BigNum::operator+ (long num) {
	BigNum big_num(num);
	if (is_subtract(big_num)) {
		return *this - big_num;
	}
	return *this + big_num;
}

BigNum BigNum::operator - (const BigNum& big_num) {
	// 20 - (-20)
	if (big_num.is_negative()) {
		BigNum temp(big_num);
		temp.sign = POSITIVE;
		return *this + temp;
	}
	//-20 - 20 == (-1) * 20 + 20
	if (big_num.is_negative() && is_negative()) {
		BigNum temp(big_num);
		temp.sign = NEGATIVE;
		return *this + temp;
	}
	BigNum *result = new BigNum();
	(*result).size = size > big_num.size ? size : big_num.size;
	result->initialize_value(result->size);
	if (*this > big_num) {
		result->carry_subtraction(*this, big_num);
	}
	else {
		result->carry_subtraction(big_num, *this);
		result->sign = NEGATIVE;
	}
	return *result;
}

BigNum BigNum::operator - (void) {
	BigNum *result = new BigNum(*this);
	result->sign = result->sign * -1;
	return *result;
}

BigNum BigNum::operator ~ (long num) {
	BigNum *big_num = new BigNum(num);
	BigNum *result = new BigNum();
	result = twoscomp(*big_num);
	delete big_num;
	return *result;
}


char * BigNum::get_value() {
	char * val = new char[size + 1];
	strcpy(val, value);
}*/

//TODO:
BigNum mul_by_ten(const BigNum& big_num) {

} 

BigNum div_by_ten(const BigNum& big_num) {

} 