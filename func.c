#include <stdio.h>
#include <string.h>
#include <windows.h>

size_t Strlen               (const char *row);
int      Puts                  (const char *row);
char *Strcpy               (char *dest, const char *src);
char *Strcat               (char *dest, const char *src);
int    strcmp                (const char *s1, const char *s2);
int    Strcmp               (const char *s1, const char *s2);
void  check_strlen       (void);
void  check_puts         (void);
void  check_strcpy      (void);
void  check_strcat      (void);
void  check_strcmp     (void);

int main(void) {
    SetConsoleOutputCP(1251);
    check_strcpy();
    return 0;
}

void check_strlen(void) {
    char cat[10] = "cat";

    int Len = Strlen(cat);
    printf("Длина строки %d\n", Len);

    int Len_ref = strlen(cat);
    printf("А должна быть %d\n", Len_ref);
}

void check_puts(void) {
    char cat[10] = "cat";

    if (Puts(cat) == EOF) {
        printf("ERROR Puts\n");
    }

    printf("А должно быть %s\n", cat);
}

size_t Strlen(const char *row) {
    int i = 0;
    while (row[i] != '\0') {
        i++;
    }
    return   i;
}

int Puts(const char *row) {
    if (row == NULL) {
        return EOF;
    }
    int i = 0;
    for (; row[i] != '\0'; i++) {
        if (putchar(row[i]) == EOF){
            return EOF;
        }
    }
    putchar('\n');
    return i;
}

void check_strcpy(void) {

    char cat[30];
    Strcpy(cat, "Ваша песенка спета...");
    printf("Скопировалось: %s\n", cat);

    char cat2[30];
    strcpy(cat2, "Ваша песенка спета...");
    printf("А должно быть %s\n", cat2);
}

char * Strcpy(char *dest, const char *src) { //handle null
    int i = 0;
    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    return dest;
}

void check_strcat(void) {

    char cat[30] = "Ваша ";
    Strcat(cat, "песенка спета...");
    printf("Скопировалось: %s\n", cat);

    char cat2[30] = "Ваша ";
    strcat(cat2, "песенка спета...");
    printf("А должно быть %s\n", cat2);
}

char *Strcat(char *dest, const char *src) {
    int i_dest = 0;
    while (dest[i_dest] != '\0') {
        i_dest++;
    }
    int i_src = 0;
    for (; src[i_src] != '\0'; i_src++) {
        dest[i_dest] = src[i_src];
        i_dest++;
    }
    return dest;
}

void check_strcmp(void) {
    char cat1[10] = "b";
    char cat2[10] = "ba";
    printf("Функция вернула: %d\n", Strcmp(cat1, cat2));
    printf("А должно быть %d\n", strcmp(cat1, cat2));
}

int Strcmp(const char *s1, const char *s2) {     //strNcmp
    int i1 = 0;
    for (; s1[i1] != '\0'; i1++) {}
    int i2 = 0;
    for (; s2[i2] != '\0'; i2++) {}
    int i_min = min(i1, i2);
    int i = 0;
    for (; i < i_min; i++) {
        if (s1[i] > s2[i]) {return 1;}
        else if (s1[i] < s2[i]) {return -1;}
    }
    if (i1 > i2) {return 1;}
    else if (i1 < i2) {return -1;}
    else {return 0;}
}

//2) strncmp
//3) strstr, getline
