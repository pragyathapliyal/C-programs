#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    FILE *p,*q;
    char c[100], b[100];
    
    // Open the first file for writing and reading
    p=fopen("one.txt","w+");
    if(p==NULL)
        printf("error opening file one.txt");
    else {
        printf("Enter a string: ");
        fgets(c,100,stdin);
        fputs(c,p);
        rewind(p);
        fgets(c,80,p);
        puts(c);
    }
    
    // Reset file pointer to the beginning of the file
    rewind(p);
    
    // Open the second file for writing and reading
    q=fopen("two.txt","w+");
    if(q==NULL)
        printf("error opening file two.txt");
    else {
        // Read from the first file, convert to uppercase, and write to the second file
        while(fgets(b, sizeof(b), p) != NULL) {
            for(int i = 0; b[i] != '\0'; i++) {
                b[i] = toupper(b[i]);
            }
            fputs(b, q);
        }
        rewind(q); // Reset file pointer to the beginning of the file
        
        // Read from the second file and print its contents
        fgets(b, sizeof(b), q);
        printf("Content of file two.txt:\n%s", b);
    }
    
    // Close files
    fclose(p);
    fclose(q);
    
    return 0;
}
