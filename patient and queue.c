#include "clinic.h"
#include <stdio.h>
#include <string.h>


//Delete '\n'
void deleteFgets (char *buffer, int max_len) {
    fgets(buffer, max_len,stdin); 
    size_t len = strlen(buffer);
    if(len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

//define stdin 1 patient
void inputPatient (Patient * p) {
    printf("Nhap ID Benh Nhan: ");
    deleteFgets (p ->patientId, MAX_ID);

    printf("Nhap sdt Benh Nhan: ");
    deleteFgets (p ->phone, MAX_PHONE);

    printf("Nhap Ho va Ten Benh Nhan: ");
    deleteFgets (p ->fullName, MAX_NAME);

    printf("Nhap Ngay Sinh Benh Nhan: ");
    deleteFgets (p ->dateOfBirth, MAX_DATE);

}

// define print ttin 1 patient
void printPatient (const Patient * p) {
    printf("| %-10s | %-13s | %-25s | %-12s | \n", p ->patientId, p ->phone, p ->fullName, p ->dateOfBirth);
}

//define tĩnh
void inputPatientList (Patient list[], int * n) {
    printf("Nhap So Luong Benh Nhan Hien Tai (Toi da %d): ", MAX_PATIENTS);
    scanf("%d",  n);
    getchar();

    //neu gia tri cua bien ma con tro n tro toi>max
    if (*n > MAX_PATIENTS) {
        printf("Vuot qua kich thuoc mang! Tu dong dat lai thanh %d\n",MAX_PATIENTS);
        *n = MAX_PATIENTS;
    }
    for(int i = 0; i < *n; i++) {
        printf("\n=== Nhap Thong Tin Benh Nhan Thu %d ===\n", i+1);
        inputPatient(&list[i]);
    }
}

void printPatientList (const Patient list [], int n) {
    printf("\n==== Sanh Sach Benh Nhan ====\n");
    printf("| %-10s | %-13s | %-25s | %-12s |\n", "Ma ID", "SDT", "Ho va Ten", "Ngay sinh");
    printf("--------------------------------\n");

    for(int i = 0; i < n;i++) {
        printPatient(&list[i]);
    }
}
