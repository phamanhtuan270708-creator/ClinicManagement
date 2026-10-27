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
    xoaBoDem();
    
    printf("Nhap so luong: ");
    scanf("%d", &it->quantity);
    xoaBoDem();
    
    printf("Nhap don gia: ");
    scanf("%lf", &it->unitPrice);
    xoaBoDem();
    
    printf("Nhap huong dan su dung: ");
    scanf("%s", it->usage);
    xoaBoDem();
    
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
    printf("\n--- CHI TIET DON THUOC (%s) ---\n", p->prescriptionId);
    printf("Ma luot kham: %s\n", p->visitId);
    
    for (int i = 0; i < p->itemCount; i++) {
        double thanhTien = p->items[i].quantity * p->items[i].unitPrice;
        tongTienThuoc += thanhTien;
        printf("%d. Ma thuoc: %s | SL: %d | Gia: %.2lf | Thanh tien: %.2lf\n",
            i + 1, p->items[i].medicineId, p->items[i].quantity, p->items[i].unitPrice, thanhTien);
    }
    printf("=> Tong tien thuoc: %.2lf\n", tongTienThuoc);
}

// Thanh toan
void thucHienThanhToan(Payment payments[], int *payCount, Prescription *p) {
    if (*payCount >= MAX_PATIENTS) {
        printf("Danh sach thanh toan da day!\n");
        return;
    }

    Payment pay;
    printf("Nhap ma thanh toan: ");
    scanf("%s", pay.paymentId);
    xoaBoDem();

    printf("Nhap ma luot kham: ");
    scanf("%s", pay.visitId);
    xoaBoDem();

    int laLichOnline, daDenKham;
    printf("Hinh thuc (1. Online, 0. Offline): ");
    scanf("%d", &laLichOnline);
    xoaBoDem();

    if (laLichOnline == 1) {
        printf("Benh nhan da den kham chua? (1. Da den, 0. Chua den): ");
        scanf("%d", &daDenKham);
        xoaBoDem();
        if (daDenKham == 0) {
            printf("=> LOI: Lich hen online chua den kham, khong duoc tinh thanh toan!\n");
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
    xoaBoDem();

    pay.totalAmount = tienThuoc + phiDichVu;

    printf("Nhap phuong thuc thanh toan: ");
    scanf("%s", pay.paymentMethods);
    xoaBoDem();

    payments[*payCount] = pay;
    (*payCount)++;
    printf("=> Thanh toan thanh cong! Tong tien: %.2lf\n", pay.totalAmount);
}

// Hien thi thanh toan
void hienThiDanhSachThanhToan(Payment payments[], int payCount) {
    if (payCount == 0) {
        printf("Chua co hoa don thanh toan nao!\n");
        return;
    }

    printf("\n--- DANH SACH THANH TOAN ---\n");
    for (int i = 0; i < payCount; i++) {
        printf("%d. MaTT: %s | MaVK: %s | Tong Tien: %.2lf | Phuong Thuc: %s\n",
            i + 1,
            payments[i].paymentId,
            payments[i].visitId,
            payments[i].totalAmount,
            payments[i].paymentMethods
        );
    }
}

<<<<<<< HEAD
=======
int main() {
    Prescription don;
    don.itemCount = 0;
    
    char pId[] = "DON01";
    char vId[] = "KHACH01";
    for(int i = 0; i < 6; i++) {
        don.prescriptionId[i] = pId[i];
        don.visitId[i] = vId[i];
    }

    Payment danhSachThanhToan[MAX_PATIENTS];
    int soLuongThanhToan = 0;
    int chon;

    do {
        printf("\n=== QUAN LY PHONG KHAM ===\n");
        printf("1. Them thuoc\n");
        printf("2. Xem don thuoc\n");
        printf("3. Thanh toan\n");
        printf("4. Xem danh sach thanh toan\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        
        if (scanf("%d", &chon) != 1) {
            xoaBoDem();
            continue;
        }
        xoaBoDem();

        if (chon == 1) {
            themPrescriptionItem(&don);
        } else if (chon == 2) {
            hienThiPrescription(&don);
        } else if (chon == 3) {
            thucHienThanhToan(danhSachThanhToan, &soLuongThanhToan, &don);
        } else if (chon == 4) {
            hienThiDanhSachThanhToan(danhSachThanhToan, soLuongThanhToan);
        }
    } while (chon != 0);

    return 0;
}
>>>>>>> be685d99501154e507fdd9f8093141615a70167a
#endif
