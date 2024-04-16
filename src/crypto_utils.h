//! @file crypto_utils.h
//! @brief Утилитарные функции, требуемые для удобной работы с библиотекой
//!

#ifndef __CRYPTO_UTILS_H
#define __CRYPTO_UTILS_H

#include "./crypto_types.h"

/*!
 * @brief Функция для перевода шестнадцатеричной строки в массив байтов
 * @param[in] src - шестнадцатеричная строка\n
 * @param[out] dst - буффер для массива байтов\n
 * @param[in] cnt - количество байтов в итоговом массиве\n
 * @return Код возврата. Если в src не находятся валидные цифры шестнадцатеричной системы, возвращается CRYPTO_BAD_INPUT, иначе CRYPTO_OK.
 */

crypto_res_t crypto_hex2b(char* src, crypto_uint8_t* dst, int cnt);

/*!
 * @brief Функция для перевода массива байтов в шестнадцатеричную строку
 * @param[in] src - исходный массив байтов
 * @param[out] dst - буффер для итоговой строки
 * @param[in] cnt - количество байтов для перевода
 */

void crypto_b2hex(crypto_uint8_t* src, char* dst, int cnt);

#endif
