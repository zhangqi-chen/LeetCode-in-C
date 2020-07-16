/**
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
 * 
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * 
 * The . character does not represent a decimal point and is used to separate number sequences.
 * 
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of
 * the second first-level revision.
 * 
 * You may assume the default revision number for each level of a version number to be 0. For example, version number
 * 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level
 * revision number are both 0.
 */

int compareVersion(char* version1, char* version2) {
    int i, j;
    int v1 = 0;
    for (i = 0; version1[i] >= '0' && version1[i] <= '9'; ++i) {
        v1 = v1 * 10 + version1[i] - '0';
    }
    int v2 = 0;
    for (j = 0; version2[j] >= '0' && version2[j] <= '9'; ++j) {
        v2 = v2 * 10 + version2[j] - '0';
    }
    if (v1 > v2) return 1;
    if (v1 < v2) return -1;
    if (version1[i] == '.') ++i;
    if (version2[j] == '.') ++j;
    if (version1[i - 1] == '.' || version2[j - 1] == '.') return compareVersion(version1 + i, version2 + j);
    return 0;
}