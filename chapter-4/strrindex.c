/*Return the index of t in s */
int strrindex(char *s, char t) {
    int i = -1;

    for (int j = 0; *s != '\0'; ++j, s++) {
        if (*s == t)
            i = j;
    }
    return i;
}
