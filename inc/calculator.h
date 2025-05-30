/*********************************************************************************************************************
Copyright (c) 2025, Lucas Ahumada Checa Casquero <lucasahum@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*********************************************************************************************************************/

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/** @file calculator.h
 ** @brief Plantilla para la creación de archivos de de cabeceras en lenguaje C
 **/

/* === Headers files inclusions ==================================================================================== */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

/**Tipo de datos para el objeto calculadora */
typedef struct calculator_s * calculator_t;

/**Tipo de datos para las funciones de operación */
typedef int (*operation_func_t)(int , int);

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief Crea una nueva calculadora
 * 
 * @return Puntero a la calculadora creada
 */
calculator_t CalculatorCreate(void);

/**
 * @brief 
 * 
 * @param calculator Puntero a la calculadora
 * @param operator Operador asociado a la función
 * @param funtion Funcion que implementa la operación
 * @return true si la operacion fue agregada
 * @return false en caso contrario
 */
bool CalculatorAddOperation(calculator_t calculator, char operator,operation_func_t function);

/**
 * @brief Realiza una operacion a partir de una cadena de caracteres
 * 
 * @param calculator Puntero a calculadora
 * @param expression Cadena con la expresion a calcular
 * @return Resultado de la operacion
 */
int CalculatorCalculate(calculator_t calculator, const char * expression);

/**
 * @brief Operación de suma para agregar a la calculadora
 * 
 * @param a Primer operando
 * @param b Segundo operando
 * @return Resultado de la operacion
 */
int OperationAdd(int a, int b);

/**
 * @brief Operación de resta para agregar a la calculadora
 * 
 * @param a Primer operando
 * @param b Segundo operando
 * @return Resultado de la operación
 */
int OperationSubtract(int a, int b);

/**
 * @brief Operación de multiplicacion para agregar a la calculadora
 * 
 * @param a Primer operando
 * @param b Segundo operando
 * @return Resultado de la operacion
 */
int OperationMultiply(int a,int b);

/**
 * @brief Operacion de division para agregar a la calculadora
 * 
 * @param a Primer operando
 * @param b Segundo operando
 * @return Resultado de la operación
 */
int OperationDivision(int a,int b);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* CALCULATOR_H_ */
