// #include <stdio.h>
/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {
    	 // return 32 bits, only odd 0xAAAAAAAA

    	 // Define first section of oddbits
    	 int i = 0xAA;
    	 // Move left to form 16 bit integer
    	 int j = i << 8;
    	 // OR with previous first section to form 16 odd bits
    	 int k = i | j;
    	 // Move left to form 32 bit integer
    	 int l = k << 16;
    	 // OR with previous 16-bit section to form 32 odd bits
    	 int m = k | l;

  return m;
}

/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
	// Check that adding 1 to the inverse of x equals tmin
	// ~Tmin + 1 = Tmin
	int is_same = x ^ (~x + 1);

	// Check to ensure that 0x0 does not toggle 1
	return !(is_same + !x);
}

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	// Create a XOR gate out of NOT and AND
	// A & ~B | ~A & B
	// NAND XOR Formula from Wikipedia:
	// A XOR B = (A NAND (A NAND B)) NAND (B NAND (A NAND B))

	return ~(~(x & ~(x & y)) & ~(~(x & y) & y));
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	// Return z if x == 0, return z otherwise

	int x_is_one = (!x) + ~0; // Test if x is one or not
	// x_is_one == 1, return y, x_is_one == 0, return z
	return ((x_is_one) & y) | ( ~(x_is_one) & z);
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {

	int overflow;
	int one;

	// Fill up all the bits to the right of MSB
	x |= x >> 16;
	x |= x >> 8;
	x |= x >> 4;
	x |= x >> 2;
	x |= x >> 1;

	// Check if there is risk of overflow
	overflow = (x >> 31);

	// Increment with one to obtain the greatestBitPos Mask
	x = x + 1;

	// Bit mask for highest bit case
	one = 1 << 31;

	// Debugging Print Statements
	//printf("\n\n ----------");
	//printf("Input: %d \n", x);
	//printf("Shifted x: %d \n", x);
	//printf("overflow: %d \n", overflow);
	//printf("one: %d \n", one);

	// Return one if there is a risk of overflow, otherwise return x >> 1
	return (~one & (x >> 1)) | (one & overflow);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	// Get the sign bit of the int
	int neg_sign = (x >> 31);

	// Create a mask for the nth power
	int power_add = ~0 + (1 << n);

	// Add the mask to the original x, and shift it to n
	return ((neg_sign & power_add) + x) >> n;
}

/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
	// Return 1 if x is positive
	// Return 0 if x is negative

	// Get the sign bit and take the NOT
	return !(x >> 31);
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {

	int original = x; // Copy the original int
	int new = (x << 1); // Bit shift it left to multiply by 2
	int sign = (original >> 31); // Copy sign
	int overflow = (new >> 31) ^ (original >> 31); // Check if overflow occurred

	int tmax = ~(1 << 31); // Set TMax
	int tmin = ~tmax; // Set TMin

	// Choose what to return
	int return_min = (sign) & tmin;
	int return_max = ~(sign) & tmax;

	//	Debugging Print statements
	//	printf("Input: %d \n", x);
	//	printf("tmax: %d, tmin: %d \n", tmax, tmin);

	// Return appropriate values and check for overflows
	return ((new) & ~overflow) | (overflow & (return_min | return_max));
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {

	// Copy the signs
	int sign_x = !!(x >> 31);
	int sign_y = !!(y >> 31);

	// Check if there are different signs
	int diff_signs = sign_x ^ sign_y;

	// Create return for if there are different signs
	int different_signs = (diff_signs) & (x >> 31);

	int difference = !((y + (~x)) >> 31); // Figure out the difference between the two

	// Figure out which one is smaller, they have the same sign
	int same_signs = (!(diff_signs)) & difference;

	return same_signs | different_signs;
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {

	int zero = 0x30; // ASCII Code for 0
	int nine = 0x39; // ASCII Code for 9

	// Find the difference between the two ASCII codes
	int difference_nine = !((nine + (~x + 1)) >> 31);
	int difference_zero = !!((zero + (~x)) >> 31);

	//	Debugging print statements
	//	printf("Input: %d \n", x);
	//	printf("diff_nine: %d, diff_zero: %d \n", difference_nine, difference_zero);

	// Both have to be true in order for it to be between
	return difference_nine & difference_zero;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
	int fourth;
	int three_fourths;
	int final;
	int shifted_bits;
	int extra;
	int rem;
	int checker;

	// Take the absolute of x
	int sign_bit = (x >> 31) & 1;
	int invert = (~sign_bit) + 1;
	x = (x ^ invert) + sign_bit;

	checker = ~(3 << 30); // Create a mask for everything but the two greatest bits
	fourth = (x >> 2) &  checker; // Take the fourth power
	three_fourths = fourth + fourth + fourth; // three * 1/4 is three-fourths

	// Find the bits that are lost due to the shift of two left
	shifted_bits = x & 0x3;

	// Multiple these two bits by three
	extra = shifted_bits + shifted_bits + shifted_bits;

	// divide them by 4 to get remainder
	rem = (extra >> 2);

	// Add remainder to original three-fourths
	final = three_fourths + rem;

	// Debugging print statements
	//printf("------------- \nInput: %d \n", x);
	//printf("sign_bit: %d \n", sign_bit);
	//printf("New x?: %d \n", x);
	//printf("half: %d, Fourth: %d \n", half, fourth);
	//printf("Shifted_bits: %d \n", shifted_bits);

	// Convert this to the 2's complement if necessary
	return (final ^ invert) + sign_bit;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	// Log base 2 in binary is the position of the MSB minus one

	int n = 0;

	// Binary search
	// Check blocks of bits one at a time to find the greatest bit

	// Check most significant 16-bits first
	int check = ( (!!(x >> 16)) << 31 >> 31);
	// If there is a bit in
	n += check & 16;
	x = x >> (check & 16);

	check = ( (!!(x >> 8)) << 31 >> 31);
	n += check & 8;
	x = x >> (check & 8);

	check = ( (!!(x >> 4)) << 31 >> 31);
	n += check & 4;
	x = x >> (check & 4);

	check = ( (!!(x >> 2)) << 31 >> 31);
	n += check & 2;
	x = x >> (check & 2);

	check = ( (!!(x >> 1)) << 31 >> 31);
	n += check & 1;
	return n;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	//printf("Input: %d \n", uf);
	int exp = 0x7F800000;
	int m = uf & 0x7FFFFF;
	// unsigned new_uf = (uf & ( ~(1 << 31))) | ( ~(sign_bit) >> 31);
	unsigned new_uf = (uf ^ (1 << (31)));

	if (((exp & uf) == exp) && m){
		return uf;
	}

	//unsigned new_uf = (uf | (~sign_bit << 31));
	//printf("sign_bit: %d \n", sign_bit);

	return new_uf;

}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {

	//printf("Input: %d \n", x);

	int neg_int = 0x80000000;
	unsigned sign_bit = 0;
	unsigned temp_exp;
	unsigned carry;
	unsigned exponent;
	unsigned mantissa;
	//printf("sign_bit: %d \n", sign_bit);

	//int power_add = (~0 + (1 << n));
	//int power = ((neg_sign & power_add) + x) >> n;

	// If integer is 0, return 0 for floating point value
	if (x == 0x00000000){
		//printf("Avoided \n");
		return 0x00000000;
	}

	if (x & neg_int) {
			sign_bit = neg_int;
			x = -x;
			//printf("Avoided2 \n");
	}

	temp_exp = 31; // The highest possible exponent

	// if integer is max
	while (1){
		if (x & neg_int){
			break;
		}
		temp_exp = temp_exp - 1;
		x = x << 1;
	}

	carry = 0;

	// Check for carry over
	if ((x & 0xFF) > 0x80)  {
		carry = 1;
	} else if ((x & 0x000001ff) == 0x180) {
		carry = 1;
	}

	exponent = ((temp_exp + 127) << 23);

	mantissa = ((x & 0x7fffffffu) >> 8) + carry;

	//printf("carry: %d \n", carry);
	//printf("exponent: %d \n", exponent);

	return sign_bit + exponent + mantissa;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {

	int neg_int = 0x80000000;
	unsigned overflow_risk;
	if (uf == neg_int || uf == 0){
		return uf;
	}

	overflow_risk = (!((uf>>23)&0xff));

	if (((uf >> 23) & 0xFF) == 0xFF){
		return uf;
	} else if (overflow_risk) {
		return (uf & (1 << 31)) | (uf << 1);
	}

	return uf + (1 << 23);
}
