#include <stdio.h>
#include <string.h>
#include "clinic.h"

// Xoa dau xuong dong va ky tu thua trong bo nho dem
void xoaBoDem() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Them thuoc
void themThuoc(Prescription *p) {
    int n;
    printf("Nhap so luong loai thuoc: ");
    if (scanf("%d", &n) != 1 || n <= 0 || p->itemCount + n > MAX_ITEM) {
        printf("Loi nhap lieu hoac vuot qua gioi han!\n");
        xoaBoDem();
        return;
    }
    xoaBoDem();

    for (int i = 0; i < n; i++) {
        PrescriptionItem *it = &p->items[p->itemCount];
        
        printf("\n--- Thuoc thu %d ---\n", p->itemCount + 1);
        
        printf("Ma thuoc: ");
        scanf("%s", it->medicineId);
        xoaBoDem();

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
        scanf(" %[^\n]", it->usage);
        xoaBoDem();

        p->itemCount++;
    }
    printf("=> Them thanh cong!\n");
}

// Hien thi thuoc, tien
void hienThiThuoc(Prescription *p) {
    if (p->itemCount == 0) {
        printf("\nDon thuoc trong!\n");
        return;
    }
    
    printf("\n======================= DANH SACH DON THUOC ========================\n");
    printf("Ma don thuoc: %s | Ma luot kham: %s\n", p->prescriptionId, p->visitId);
    printf("--------------------------------------------------------------------\n");
    printf("%-5s | %-18s | %-8s | %-12s | %-18s\n", "STT", "Ma Thuoc", "SL", "Don Gia", "Huong Dan SD");
    printf("--------------------------------------------------------------------\n");
    
    double tongTien = 0;
    for (int i = 0; i < p->itemCount; i++) {
        PrescriptionItem it = p->items[i];
        double thanhTien = it.quantity * it.unitPrice;
        tongTien += thanhTien;
        
        printf("%-5d | %-18s | %-8d | %-12.2lf | %-18s\n",
            i + 1, it.medicineId, it.quantity, it.unitPrice, it.usage
        );
    }
    printf("--------------------------------------------------------------------\n");
    printf("TONG CONG TIEN THUOC: %.2lf VND\n", tongTien);
    printf("====================================================================\n");
}

// Xoa thuoc
void xoaThuoc(Prescription *p) {
    if (p->itemCount == 0) {
        printf("\nDon thuoc dang trong, khong co gi de xoa!\n");
        return;
    }
    
    char maXoa[MAX_ID];
    printf("Nhap ma thuoc can xoa: ");
    scanf("%s", maXoa);
    xoaBoDem();

    int foundIdx = -1;
    for (int i = 0; i < p->itemCount; i++) {
        if (strcmp(p->items[i].medicineId, maXoa) == 0) {
            foundIdx = i;
            break;
        }
    }

    if (foundIdx == -1) {
        printf("Khong tim thay ma thuoc '%s' trong don!\n", maXoa);
        return;
    }

    for (int i = foundIdx; i < p->itemCount - 1; i++) {
        p->items[i] = p->items[i + 1];
    }
    p->itemCount--;
    printf("=> Xoa thanh cong thuoc co ma '%s' khoi don!\n", maXoa);
}

int main() {
    Prescription don;
    don.itemCount = 0;
    strcpy(don.prescriptionId, "PRS01");
    strcpy(don.visitId, "VST01");

    int chon;
    do {
        printf("\n=== MENU QUAN LY DON THUOC ===\n");
        printf("1. Them thuoc\n");
        printf("2. Xem danh sach va tong tien\n");
        printf("3. Xoa thuoc khoi don\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        
        if (scanf("%d", &chon) != 1) {
            printf("Vui long nhap so!\n");
            xoaBoDem();
            continue;
        }
        xoaBoDem();

        switch (chon) {
            case 1: 
                themThuoc(&don); 
                break;
            case 2: 
                hienThiThuoc(&don); 
                break;
            case 3: 
                xoaThuoc(&don); 
                break;
            case 0: 
                printf("Thoat chuong trinh.\n"); 
                break;
            default: 
                printf("Sai lua chon! Vui long chon lai.\n");
        }
    } while (chon != 0);

    return 0;
}