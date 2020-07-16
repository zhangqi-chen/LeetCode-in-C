/**
 * Given a string, find the length of the longest substring without repeating characters.
 */

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int flag[128] = {0};
    int head, rear = 1;  //rear = starting index + 1
    int longest = 0, curr;
    int length = strlen(s);
    if (length < 2) return length;
    for (head = 0; head < length; head++) {
        if (flag[s[head]] >= rear)
            rear = flag[s[head]] + 1;
        flag[s[head]] = head + 1;
        curr = head - rear + 2;
        if (curr > longest)
            longest = curr;
    }
    return longest;
}

int main() {
    char s[] = "pwwkew";
    int n;
    n = lengthOfLongestSubstring(s);
    printf("%d", n);
    return 0;
}