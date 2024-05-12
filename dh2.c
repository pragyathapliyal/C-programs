#include <stdio.h>
#include <string.h>

int main() {
    FILE *p;
    char c[100];
    int count = 0;
    
    p = fopen("one.txt", "w+");
    if (p == NULL) {
        printf("Error opening file one.txt");
    } else {
        printf("Enter a string: ");
        fgets(c, 80, stdin);
        fputs(c, p);
        rewind(p);
        
        while (fgets(c, 80, p) != NULL) {
            for (int i = 0; c[i] != '\0'; i++) {
                if (c[i] == 'A' || c[i] == 'U' || c[i] == 'O' || c[i] == 'I' || c[i] == 'E' || c[i] == 'u' || c[i] == 'o' || c[i] == 'i' || c[i] == 'e' || c[i] == 'a') {
                    count++;
                }
            }
        }
        printf("Number of vowels: %d", count);
    }
    fclose(p);
    return 0;
}

