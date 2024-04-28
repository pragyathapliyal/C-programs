#include <stdio.h>

// Structure to store student information
struct Student {
    int id;
    int m[5]; // Assuming 5 subjects
    int yearOfAdmission;
};

int main() {
    

    // Declare an array of structures to store information of multiple s
    struct Student s[3];

    // Input student information
   // printf("Enter information for %d students:\n", 3);
    for (int i = 0; i < 3; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter Student ID: ");
        scanf("%d", &s[i].id);
        printf("Enter m in 5 subjects: ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &s[i].m[j]);
        }
        printf("Enter Year of Admission: ");
        scanf("%d", &s[i].yearOfAdmission);
    }

    // Check if marks in more than 3 subjects are the same for each student
    printf("\nChecking if m in more than 3 subjects are the same for each student:\n");
    for (int i = 0; i < 3; i++) {
        int same = 0;
        for (int j = 0; j < 5 - 1; j++) {
            for (int k = j + 1; k < 5; k++) {
                if (s[i].m[j] == s[i].m[k]) {
                    same++;
                    if (same >= 3) {
                        printf("Student %d: marks in more than 3 subjects are the same.\n", s[i].id);
                        break;
                    }
                }
            }
            if (same >= 3) 
                break;
            
        }
        if (same < 3) 
            printf("Student %d: marks in less than 3 subjects are the same.\n", s[i].id);
        
    }

    // Find the student with the highest average m in top 4 subjects
    printf("\nFinding the student with the highest average m in top 4 subjects:\n");
    float maxav = 0;
    int x;
    for (int i = 0; i < 3; i++) {
        // Sort m in descending order to get top 4 subjects
        for (int j = 0; j < 5 - 1; j++) {
            for (int k = 0; k < 5 - j - 1; k++) {
                if (s[i].m[k] < s[i].m[k + 1]) {
                    int temp = s[i].m[k];
                    s[i].m[k] = s[i].m[k + 1];
                    s[i].m[k + 1] = temp;
                }
            }
        }
        // Calculate total m in top 4 subjects
        int totalm = 0;
        for (int j = 0; j < 4; j++) {
            totalm += s[i].m[j];
        }
        // Calculate average m
        float average = (float)totalm / 4;
        //printf("Student %d: Average m in top 4 subjects = %.2f\n", s[i].id, average);
        if (average > maxav) {
            maxav = average;
            x = s[i].id;
        }
    }
    printf("Student with the highest average m in top 4 subjects: Student %d\n", x);

    return 0;
}
