/**
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer
 * division should truncate toward zero.
 */

int calculate(char* s) {
    int* stack = (char*)malloc(sizeof(int) * strlen(s));
    int size = 0;
    while (*s) {
        if (*s == ' ') {
            ++s;
            continue;
        } else if (*s >= '0' && *s <= '9') {
            int n = *s++ - '0';
            while (*s >= '0' && *s <= '9') {
                n = n * 10 + (*s++ - '0');
            }
            --s;
            stack[size++] = n;
        } else {
            if (size > 2 && (*s == '+' || *s == '-')) {
                stack[size - 3] += stack[size - 2] == '+' ? stack[size - 1] : -stack[size - 1];
                size -= 2;
            }
            stack[size++] = *s++;
            continue;
        }
        if (size > 2 && stack[size - 2] == '*') {
            stack[size - 3] *= stack[size - 1];
            size -= 2;
        } else if (size > 2 && stack[size - 2] == '/') {
            stack[size - 3] /= stack[size - 1];
            size -= 2;
        }
        ++s;
    }
    if (size > 2) stack[size - 3] += stack[size - 2] == '+' ? stack[size - 1] : -stack[size - 1];
    return stack[0];
}