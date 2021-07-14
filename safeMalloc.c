void *safeMalloc(int n) {
    void *p = malloc(n);
    if(p == NULL) {
        printf("Error: malloc(%d) failed. Out of memory?\n", n);
        exit(EXIT_FAILURE);
    }
    return p;
}