#include "patient.h"
#include <stdio.h>
#include <string.h>


//Delete '\n'
void deleteFgets (char *buffer, int max_len) {
    fgets(buffer, max_len,stdin); 
    size_t len = strlen(buffer);
    if(len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] == '\0';
    }
}

//define stdin 1 patient
void inputPatient (patient * p) {
    printf("Nhập ID Bệnh Nhân: ");
    deleteFgets (p ->patient_id, MAX_ID);

    printf("Nhập SĐT Bệnh Nhân: ");
    deleteFgets (p ->phone_number, MAX_PHONE);

    printf("Nhập Họ và Tên Bệnh Nhân: ");
    deleteFgets (p ->full_name, MAX_NAME);

    printf("Nhap Ngày Sinh Bệnh Nhân: ");
    deleteFgets (p ->date_of_birth, MAX_DATE);

}

// define print ttin 1 patient
void printPatient (const patient * p) {
    printf("| %-10s | %-13s | %-25s | %-12s | \n", p ->patient_id, p ->phone_number, p ->full_name, p ->date_of_birth);
}

//define tĩnh
void inputPatientList (patient list[], int * n) {
    printf("Nhập Số Lượng Bệnh Nhân Hiện Tại: "); | printf("(Tối Đa%d):, MAX_PATIENTS");
    scanf("%d", &n);
    getchar();

    //neu gia tri cua bien ma con tro n tro toi>max
    if (*n > MAX_PATIENTS) {
        printf("Vượt quá kích thước mảng! Tự động đặt lại thành %d\n",MAX_PATIENTS);
        *n = MAX_PATIENTS;
    }
    for(int i = 0; i < *n; i++) {
        printf("\n=== Nhập Thông Tin Bệnh Nhân Thứ %d ===\n", i+1);
        inputPatient(&list[i]);
    }
}

void printPatientList (const patient list [], int n) {
    printf("\n==== Danh Sách Bệnh NHân ====\n");
    printf("| %-10s | %-13s | %-25s | %-12s |\n", "Mã ID", "SĐT", "Họ và Tên", "Ngay sinh");
    printf("--------------------------------\n");

    for(int i = 0; i < n, i++) {
        printPatient(&list[i]);
    }
}