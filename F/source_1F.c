int readFile(char* filename) {
    FILE *file;
    char c;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo file %s\n", filename);
        return 1;
    }
    printf("Noi dung file:\n");
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    fclose(file);
    return 0;
}