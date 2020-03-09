#include <stddef.h>
#include <string.h>

/* Функция возвращает значение длины строки string,
 * умноженное на multiplier, и увеличивает на 1 значение,
 * на которое указывает count.
 */

int stringStat(const char *string, size_t multiplier, int *count) {
    (*count)++;
    return strlen(string) * multiplier;;
}
