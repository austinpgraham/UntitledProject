#ifndef STD_H
#define STD_H
#include "math.h"
#include "string.h"

// A few useful ASCII contants;
#define ASCII_0 48
#define ASCII_9 57

/** 
 * Simple implementation of a function converting
 * a string to an integer.
 * 
 * Takes as input a string representing an integer.
 * If the given input is not an integer, then an
 * error is thrown.
 * 
 * "1234" -> 1234
*/
int atoi (char* str) {
    int result = 0;

    // Get the length of the string and check
    int length = str_len(str);
    if (length == 0) return 0;
    
    // Iterate over the string backwards to get the result
    int ptr = length - 1;
    while (ptr >= 0) {
        char ptr_char = str[ptr];

        // Check that if we are at the beginning of the 
        // string and the character is a negative sign,
        // then we return a negative result
        if (ptr == 0 && ptr_char == '-') return -result;

        // Use the ASCII value to get the numeric value.
        // At this point, we can check if it is a valid number. If not,
        // then we throw an error
        int adjusted_ascii = ptr_char - ASCII_0;

        // If invalid, return an error value
        if (adjusted_ascii < 0 || adjusted_ascii > 9) return 0;

        // Otherwise, add to the result
        result += adjusted_ascii * (int)mpow(10, length - ptr - 1);

        ptr--;
    }

    return result;
}
#endif
