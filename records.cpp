#include <stdio.h>
#include <string.h>
#include "clinic.h"

MedicalRecord records[MAX_ID];
int recordCount = 0;

// Xoa dau xuong dong trong bo nho dem
void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Nhap so nguyen
int inputInt(const char *message) {
    int value;
    while (1) {
        printf("%s", message);
        if (scanf("%d", &value) == 1) {
            clearBuffer();
            return value;
        }
        printf("Loi: Chi duoc nhap so nguyen! Vui long nhap lai.\n");
        clearBuffer();
    }
}

// Nhap so thuc
float inputFloat(const char *message) {
    float value;
    while (1) {
        printf("%s", message);
        if (scanf("%f", &value) == 1) {
            clearBuffer();
            return value;
        }
        printf("Loi: Chi duoc nhap so thuc! Vui long nhap lai.\n");
        clearBuffer();
    }
}

// Ham nhap chu
int inputText(const char *message, char text[], int size) {
    int c;
    int i = 0;
    
    printf("%s", message);
    
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < size - 1) {
            text[i++] = (char)c;
        }
    }
    text[i] = '\0';
    
    return 1;
}

// Kiem tra luot kham co ton tai chua
int findRecord(const char *visitId) {
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(records[i].visitId, visitId) == 0)
            return i;
    }
    return -1;
}

// Them ho so
void addMedicalRecord(void) {
    if (recordCount >= MAX_ID) {
        printf("Danh sach ho so da day!\n");
        return;
    }

    MedicalRecord temp;

    inputText("Nhap luot kham: ", temp.visitId, sizeof(temp.visitId));
    
    if (findRecord(temp.visitId) != -1) {
        printf("Loi: Luot kham da co ho so!\n");
        return;
    }

    inputText("Nhap trieu chung: ", temp.symptoms, sizeof(temp.symptoms));

    temp.height = inputFloat("Nhap chieu cao (cm): ");
    temp.weight = inputFloat("Nhap can nang (kg): ");

    inputText("Nhap chan doan: ", temp.diagnosis, sizeof(temp.diagnosis));

    records[recordCount] = temp;
    recordCount++;

    printf("Them ho so kham benh thanh cong!\n");
}

//Hien thi danh sach
void displayMedicalRecords(void) {
    if (recordCount == 0) {
        printf("Chua co ho so kham benh!\n");
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        printf("\n--- Ho so %d ---\n", i + 1);
        printf("Luot kham  : %s\n", records[i].visitId);
        printf("Trieu chung: %s\n", records[i].symptoms);
        printf("Chieu cao  : %.1f cm\n", records[i].height);
        printf("Can nang   : %.1f kg\n", records[i].weight);
        printf("Chan doan  : %s\n", records[i].diagnosis);
    }
}

//Tim kiem ho so
void searchMedicalRecord(void) {
    char searchId[20];
    inputText("Nhap luot kham can tim: ", searchId, sizeof(searchId));

    int index = findRecord(searchId);

    if (index == -1) {
        printf("Khong tim thay ho so!\n");
        return;
    }

    printf("\n--- Thong tin ho so tim thay ---\n");
    printf("Luot kham  : %s\n", records[index].visitId);
    printf("Trieu chung: %s\n", records[index].symptoms);
    printf("Chieu cao  : %.1f cm\n", records[index].height);
    printf("Can nang   : %.1f kg\n", records[index].weight);
    printf("Chan doan  : %s\n", records[index].diagnosis);
}

int main(void) {
    int choice;

    do {
        printf("\n===== MEDICAL RECORD =====\n");
        printf("0. Thoat\n");
        printf("1. Them ho so kham benh\n");
        printf("2. Hien thi ho so\n");
        printf("3. Tim kiem ho so\n");

        choice = inputInt("Lua chon: ");

        switch (choice) {
            case 1:
                addMedicalRecord();
                break;
            case 2:
                displayMedicalRecords();
                break;
            case 3:
                searchMedicalRecord();
                break;
            case 0:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}