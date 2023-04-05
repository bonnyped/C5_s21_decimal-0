#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ADD_SUB 1
#define MUL 2
#define DIV 3
#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define SYSBITS_CORRECT_MASK (int)0b10000000111111110000000000000000
#define SYSBITS_REVERSE_MASK (int)0b01111111000000001111111111111111
#define SYSBITS_SCALE_TOZERO (int)0b11111111000000001111111111111111
#define FULL_ZERO (int)0b00000000000000000000000000000000
#define FULL_ONES (int)0b11111111111111111111111111111111

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[6];
} BIG_decimal;

void clear_sys_bits(s21_decimal *num);
int get_sign(s21_decimal value);
void set_sign(int sign, s21_decimal *value);
unsigned int get_scale(s21_decimal value);
int set_scale(unsigned int scale, s21_decimal *value);

void copy_bits_dec(s21_decimal value, s21_decimal *dst);
void copy_bits_big(BIG_decimal value, BIG_decimal *dst);
void copy_bits_dec_to_big(s21_decimal value, BIG_decimal *dst);
void copy_bits_big_to_dec(BIG_decimal value, s21_decimal *dst);

int big_is_zero(BIG_decimal num);
int dec_is_zero(s21_decimal num);

int get_bit_big(BIG_decimal value, int num);
int get_bit_dec(s21_decimal value, int num);
int left_shift_big(BIG_decimal *value);
int add_big(BIG_decimal value_1, BIG_decimal value_2, BIG_decimal *result);
int sub_big(BIG_decimal value_1, BIG_decimal value_2, BIG_decimal *result);
int mul_big(BIG_decimal summer, BIG_decimal adder, BIG_decimal *result);
int mul_big_to_ten(BIG_decimal *value);
int div_big_once(BIG_decimal value_1, BIG_decimal value_2, BIG_decimal *result,
                 BIG_decimal *fraction);
int div_big(BIG_decimal value_1, BIG_decimal value_2, BIG_decimal *result,
            unsigned int *scale);
int div_big_to_ten(BIG_decimal *value, int *fraction);

int big_bits_is_less(BIG_decimal one, BIG_decimal two);
int big_bits_is_less_or_equal(BIG_decimal one, BIG_decimal two);
int big_bits_is_greater(BIG_decimal one, BIG_decimal two);
int big_bits_is_greater_or_equal(BIG_decimal one, BIG_decimal two);
int big_bits_is_equal(BIG_decimal one, BIG_decimal two);

int two_dec_to_big(s21_decimal value_1, s21_decimal value_2, BIG_decimal *left,
                   BIG_decimal *right, unsigned int *scale, int type);
int big_to_dec(BIG_decimal value, s21_decimal *result, unsigned int scale,
               int res_sign, int delete_zero);
int bank_rounding(BIG_decimal *value, int last_num, int last_num_count);
void zero_deleting(BIG_decimal *value, unsigned int *scale);
int is_all_zero_mul(s21_decimal value_1, s21_decimal value_2);
double my_pow_of_two(int count);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal one, s21_decimal two);
int s21_is_less_or_equal(s21_decimal one, s21_decimal two);
int s21_is_greater(s21_decimal one, s21_decimal two);
int s21_is_greater_or_equal(s21_decimal one, s21_decimal two);
int s21_is_equal(s21_decimal one, s21_decimal two);
int s21_is_not_equal(s21_decimal one, s21_decimal two);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif  // S21_STRING_H
