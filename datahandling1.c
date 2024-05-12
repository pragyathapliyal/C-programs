#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main() {
    FILE *p,*q;
    char c[100], b[100];
    
    // Open the first file for reading
    p = fopen("one.txt", "r");
    if(p == NULL)
        printf("error opening file one.txt");
    else {
        // Read from the first file and replace special characters with '$'
        while(fgets(b, sizeof(b), p) != NULL) {
            for(int i = 0; b[i] != '\0'; i++) {
                // if(!isalnum(b[i]) || b[i] != ' ') 
                //     b[i] = '$';
                if(!isalnum(b[i]) && b[i] != ' ') 
    b[i] = '$';

                
            }
        }
        fclose(p); // Close the first file
        
        // Open the second file for writing
        q = fopen("two.txt", "w+");
        if(q == NULL)
            printf("error opening file two.txt");
        else {
            // Write the modified content to the second file
            fputs(b, q);
            
            // Reset file pointer to the beginning of the file
            rewind(q);
            
            // Read from the second file and print its contents
            fgets(b, sizeof(b), q);
            printf("Content of file two.txt:\n%s", b);
            
            fclose(q); // Close the second file
        }
    }
    
    return 0;
}
