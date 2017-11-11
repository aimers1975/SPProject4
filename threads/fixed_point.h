#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H

/* Basic definitions of fixed point */
typedef int fixed_t;
/* 14 LSB used for fractional part */
#define FP_SHIFT_AMOUNT (1 << 14)

/* Macros */
/* Convert a value to fixed-point value */
#define FP_CONST(A) ((fixed_t)(A * FP_SHIFT_AMOUNT))
/* Add two fixed-point value */
#define FP_ADD(A,B) (A + B)
/* Add a fixed-point A and an int B */
#define FP_ADD_MIX(A,B) (A + (B * FP_SHIFT_AMOUNT))
/* Subtract two fixed-point value */
#define FP_SUB(A,B) (A - B)
/* Subtract int B from fixed-point A  */
#define FP_SUB_MIX(A,B) (A - (B * FP_SHIFT_AMOUNT))
/* Multiply fp A by int B */
#define FP_MULT_MIX(A,B) (A * B)
/* Divide fp A by int B */
#define FP_DIV_MIX(A,B) (A / B)
/* Multiply two fp value */
#define FP_MULT(A,B) ((fixed_t)(((int64_t) A) * B /FP_SHIFT_AMOUNT))
/* Divide two fp value */
#define FP_DIV(A,B) ((fixed_t)(((int64_t) A) * FP_SHIFT_AMOUNT / B))
/* Get integer part of a fp value */
#define FP_INT_PART(A) (A / FP_SHIFT_AMOUNT)
/* Get rounded integer of a fp value */
#define FP_ROUND(A) (A >= 0 ? ((A + FP_SHIFT_AMOUNT / 2) / FP_SHIFT_AMOUNT) \
                              : ((A - FP_SHIFT_AMOUNT / 2) / FP_SHIFT_AMOUNT))

#endif  

