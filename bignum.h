#ifndef BIGNUM_H
#define BIGNUM_H
#include <iostream>

using namespace std;

class BigNum {
private:
	static const int BASE = 10;
	static const char CHAR_TO_INT = '0';
	const int NEGATIVE = -1;
	const int POSITIVE = 1;
	const int SIGN_SIZE = 1;
	static const char MINUS_CHAR = '-';
	int size = 50;
	char value[50];
	int sign;
	
	void num_init(const char *);
	void set_sign(long int);
	void set_sign(char*);
	void num_to_char_array(long int);
	char * validate_char_input(char*);	
	
	bool is_negative(void) const;
	bool is_positive(void) const;
	bool is_subtract(const BigNum&);
	
	BigNum add(const BigNum&);
	BigNum mul(const BigNum&);
	BigNum div(const BigNum&);
	BigNum twoscomp(void);

public:
	BigNum(long int=0);
	BigNum(char *value);
	BigNum(const BigNum&);
	~BigNum();
	friend std::ostream& operator<<(std::ostream&, const BigNum&);
	friend std::istream& operator>> (std::istream&, BigNum);
	BigNum operator = (const BigNum&);
	BigNum operator = (char*);
	BigNum operator = (long int);
	BigNum operator + (const BigNum&);
	BigNum operator + (long int);
	BigNum operator - (const BigNum&);
	BigNum operator - (void);
	BigNum operator ~ (void);
	BigNum mul_by_ten(const BigNum&);
	BigNum div_by_ten(const BigNum&);
	char * get_value();
};
#endif