#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H

#include <stdio.h>
#include "clinic.h"

// Them thuoc
void themPrescriptionItem(Prescription *p) {
    if (p->itemCount >= MAX_ITEM) {
        printf("Don thuoc da dat gioi han toi da!\n");
        return;
    }
    
    PrescriptionItem *it = &p->items[p->itemCount];
    
    printf("Nhap ma thuoc: ");
    scanf("%s", it->medicineId);
    
    
    printf("Nhap so luong: ");
    scanf("%d", &it->quantity);
    
    
    printf("Nhap don gia: ");
    scanf("%lf", &it->unitPrice);
    
    
    printf("Nhap huong dan su dung: ");
    scanf("%s", it->usage);
    
    
    p->itemCount++;
    printf("=> Them muc thuoc thanh cong!\n");
}

// Hien thi
void hienThiPrescription(Prescription *p) {
    if (p->itemCount == 0) {
        printf("Don thuoc dang trong!\n");
        return;
    }
    
    double tongTienThuoc = 0;
    printf("\n--- CHI TIET DON THUOC ---\n");
    
    for (int i = 0; i < p->itemCount; i++) {
        double thanhTien = p->items[i].quantity * p->items[i].unitPrice;
        tongTienThuoc += thanhTien;
        printf("%d. Ma thuoc: %s | SL: %d | Gia: %.3lf | Thanh tien: %.3lf\n",
            i + 1, p->items[i].medicineId, p->items[i].quantity, p->items[i].unitPrice, thanhTien);
    }
    printf("=> Tong tien thuoc: %.3lf VND\n", tongTienThuoc);
}

// Thanh toan
void thucHienThanhToan(Payment payments[], int *payCount, Prescription *p) {
    if (*payCount >= MAX_DAILY_PATIENTS) {
        printf("Danh sach thanh toan da day!\n");
        return;
    }

    Payment pay;
    printf("Nhap ma don thuoc: ");
    scanf("%s", pay.paymentId);

    for (int i = 0; i < *payCount; i++) {
        int trung = 1;
        for (int j = 0; j < MAX_ID; j++) {
            if (payments[i].paymentId[j] != pay.paymentId[j]) {
                trung = 0;
                break;
            }
            if (pay.paymentId[j] == '\0') break;
        }
        if (trung == 1) {
            printf("Loi: Ma thanh toan '%s' da ton tai! Vui long nhap lai.\n", pay.paymentId);
            return;
        }
    }

    double tienThuoc = 0;
    int trungMa = 1;
    for (int i = 0; i < MAX_ID; i++) {
        if (pay.visitId[i] != p->visitId[i]) {
            trungMa = 0;
            break;
        }
        if (pay.visitId[i] == '\0') break;
    }

    if (trungMa == 1) {
        for (int i = 0; i < p->itemCount; i++) {
            tienThuoc += p->items[i].quantity * p->items[i].unitPrice;
        }
    }

    double phiDichVu;
    printf("Nhap phi dich vu: ");
    scanf("%lf", &phiDichVu);

    pay.totalAmount = tienThuoc + phiDichVu;

    printf("Nhap phuong thuc thanh toan: ");
    scanf("%s", pay.paymentMethods);
    
    payments[*payCount] = pay;
    (*payCount)++;
    p->itemCount = 0;
    printf("=> Thanh toan thanh cong! Tong tien: %.3lf VND\n", pay.totalAmount);
}

// Hien thi thanh toan
void hienThiDanhSachThanhToan(Payment payments[], int payCount) {
    if (payCount == 0) {
        printf("Chua co hoa don thanh toan nao!\n");
        return;
    }

    printf("\n--- DANH SACH THANH TOAN ---\n");
    for (int i = 0; i < payCount; i++) {
        printf("%d. MaTT: %s | Tong Tien: %.3lf VND | Phuong Thuc: %s\n",
            i + 1,
            payments[i].paymentId,
            payments[i].totalAmount,
            payments[i].paymentMethods
        );
    }
}
#endif
