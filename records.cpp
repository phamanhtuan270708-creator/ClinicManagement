#include <stdio.h>
#include "clinic.h"

MedicalRecord records[MAX_ID];
int recordCount = 0;

// Xoa dau xuong dong trong bo nho dem
void xoaBoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Kiem tra luot kham co ton tai hay khong
int findRecord(const char *visitId) {
    for (int i = 0; i < recordCount; i++) {
        int match = 1;
        for (int j = 0; j < MAX_ID; j++) {
            if (records[i].visitId[j] != visitId[j]) {
                match = 0;
                break;
            }
            if (visitId[j] == '\0') break;
        }
        if (match) return i;
    }
    return -1;
}

// Them ho so
void themMedicalRecord() {
    if (recordCount >= MAX_ID) {
        printf("Danh sach ho so da day!\n");
        return;
    }

    MedicalRecord temp;

    printf("Nhap luot kham: ");
    scanf("%s", temp.visitId);
    xoaBoDem();

    if (findRecord(temp.visitId) != -1) {
        printf("Loi: Luot kham da co ho so!\n");
        return;
    }

    printf("Nhap trieu chung: ");
    scanf("%s", temp.symptoms);
    xoaBoDem();

    printf("Nhap chieu cao (cm): ");
    scanf("%f", &temp.height);
    xoaBoDem();

    printf("Nhap can nang (kg): ");
    scanf("%f", &temp.weight);
    xoaBoDem();

    printf("Nhap chan doan: ");
    scanf("%s", temp.diagnosis);
    xoaBoDem();

    records[recordCount] = temp;
    recordCount++;

    printf("=> Them ho so kham benh thanh cong!\n");
}

// Hien thi danh sach
void hienThiMedicalRecords() {
    if (recordCount == 0) {
        printf("Chua co ho so kham benh!\n");
        return;
    }

    printf("\n--- DANH SACH HO SO KHAM BENH ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%d. Luot kham: %s | Trieu chung: %s | Chieu cao: %.1f cm | Can nang: %.1f kg | Chan doan: %s\n",
            i + 1, records[i].visitId, records[i].symptoms, records[i].height, records[i].weight, records[i].diagnosis);
    }
}

// Tim kiem ho so
void timKiemMedicalRecord() {
    char searchId[20];
    printf("Nhap luot kham can tim: ");
    scanf("%s", searchId);
    xoaBoDem();

    int index = findRecord(searchId);

    if (index == -1) {
        printf("Khong tim thay ho so!\n");
        return;
    }

    printf("\n--- THONG TIN HO SO TIM THAY ---\n");
    printf("Luot kham  : %s\n", records[index].visitId);
    printf("Trieu chung: %s\n", records[index].symptoms);
    printf("Chieu cao  : %.1f cm\n", records[index].height);
    printf("Can nang   : %.1f kg\n", records[index].weight);
    printf("Chan doan  : %s\n", records[index].diagnosis);
}

int main() {
    int chon;

    do {
        printf("\n=== QUAN LY HO SO KHAM BENH ===\n");
        printf("1. Them ho so kham benh\n");
        printf("2. Xem danh sach ho so\n");
        printf("3. Tim kiem ho so\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");

        if (scanf("%d", &chon) != 1) {
            xoaBoDem();
            continue;
        }
        xoaBoDem();

        if (chon == 1) {
            themMedicalRecord();
        } else if (chon == 2) {
            hienThiMedicalRecords();
        } else if (chon == 3) {
            timKiemMedicalRecord();
        } else if (chon == 0) {
            printf("Thoat chuong trinh!\n");
        } else {
            printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);

    return 0;
}