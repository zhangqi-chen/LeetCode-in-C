/**
 * Validate if a given string can be interpreted as a decimal number.
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should gather all
 * requirements up front before implementing one. However, here is a list of characters
 * that can be in a valid decimal number:
 * 
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * 
 * Of course, the context of these characters also matters in the input.
 */

#include <bool.h>
#include <string.h>

bool isNumber(char* s) {
    bool decimal = false;  // flag of .
    bool neg = false;      // flag of +/-
    bool num = false;      // flag of numbers
    bool esign = false;    // flag of e
    bool finish = false;   // finish: there are spaces after a valid number
    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == ' ') {
            if (num || decimal || neg || esign)
                finish = true;
            continue;
        } else if (finish)  // non-space character after "finish", return false
            return false;
        if (s[i] >= '0' && s[i] <= '9') {
            num = true;
        } else if (s[i] == '-' || s[i] == '+') {
            if ((decimal || num || neg || esign) && s[i - 1] != 'e') {  // before e: no double -/+, after e: right after e sign
                return false;
            } else {
                neg = true;
            }
        } else if (s[i] == '.') {
            if (esign || decimal) {  // before e: no double decimal points, after e：forbidden
                return false;
            } else {
                decimal = true;
            }
        } else if (s[i] == 'e') {  // e must after a valid number
            if (!num || esign) {
                return false;
            } else {
                esign = true;
                num = false;
            }
        } else {
            return false;
        }
    }
    return num;
}
