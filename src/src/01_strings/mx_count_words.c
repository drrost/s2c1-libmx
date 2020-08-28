int mx_count_words(const char *str, char c) {
    if (str == 0) {
        return -1;
    }

    int isAlpha = 0;
    int count = 0;
    while (*str != '\0') {
        if (isAlpha == 0 && *str != c) {
            isAlpha = 1;
            count++;
        }
        if (*str == c) {
            isAlpha = 0;
        }
        str++;
    }
    return count;
}
