#include <stdio.h>
#include <string.h>
#include "clinic.h"

//Xoa dau xuong dong trong bo nho dem
void xoaBoDem() {
    while (getchar() != '\n');
}

//Them thuoc
void themThuoc(Prescription *p) {
    int n;
    printf("Nhap so luong loai thuoc: ");
    if (scanf("%d", &n) != 1 || n <= 0 || p->itemCount + n > MAX_ITEM) {
        printf("Loi nhap lieu!\n");
        xoaBoDem();
        return;
    }
    xoaBoDem();

    for (int i = 0; i < n; i++) {
        PrescriptionItem *it = &p->items[p->itemCount];
        
        printf("\n--- Thuoc thu %d ---\n", p->itemCount + 1);
        
        printf("Ma thuoc: ");
        fgets(it->medicineId, sizeof(it->medicineId), stdin);
        it->medicineId[strcspn(it->medicineId, "\n")] = 0;

        printf("So luong: ");
        while (scanf("%d", &it->quantity) != 1 || it->quantity <= 0) {
            printf("Nhap lai so luong (> 0): ");
            xoaBoDem();
        }
        xoaBoDem();

        printf("Don gia: ");
        while (scanf("%lf", &it->unitPrice) != 1 || it->unitPrice < 0) {
            printf("Nhap lai don gia (>= 0): ");
            xoaBoDem();
        }
        xoaBoDem();

        printf("Huong dan SD: ");
        fgets(it->usage, sizeof(it->usage), stdin);
        it->usage[strcspn(it->usage, "\n")] = 0;

        p->itemCount++;
    }
    printf("=> Them thanh cong!\n");
}

//Hien thi thuoc
void hienThiThuoc(Prescription *p) {
    if (p->itemCount == 0) {
        printf("\nDon thuoc trong!\n");
        return;
    }
    
    printf("\n--- DANH SACH DON THUOC ---\n");
    printf("%-5s | %-15s | %-10s | %-10s | %-15s\n", "STT", "Ma Thuoc", "SL", "Don Gia", "HDSD");
    for (int i = 0; i < p->itemCount; i++) {
        PrescriptionItem it = p->items[i];
        printf("%-5d | %-15s | %-10d | %-10.2lf | %-15s\n",
            i + 1, it.medicineId, it.quantity, it.unitPrice, it.usage
        );
    }
}

int main() {
    Prescription don;
    don.itemCount = 0;
    strcpy(don.prescriptionId, "PRS01");
    strcpy(don.visitId, "VST01");

    int chon;
    do {
        printf("0. Thoat\n");
        printf("\n=== MENU ===\n");
        printf("1. Them thuoc\n");
        printf("2. Xem danh sach\n");
        printf("Lua chon: ");
        
        if (scanf("%d", &chon) != 1) {
            printf("Vui long nhap so!\n");
            xoaBoDem();
            continue;
        }
        xoaBoDem();

        switch (chon) {
            case 1: themThuoc(&don); break;
            case 2: hienThiThuoc(&don); break;
            case 0: printf("Thoat.\n"); break;
            default: printf("Sai lua chon!\n");
        }
    } while (chon != 0);

    return 0;
}