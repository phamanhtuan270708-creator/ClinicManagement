#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clinic.h"

Patient patientList[MAX_PATIENTS];
int patientCount = 0;

Prescription currentPrescription;
Payment paymentList[MAX_PATIENTS];
int paymentCount = 0;

//Khai bao ham patientAndQueue
void inputPatientList(Patient list[], int *n);
void printPatientList(const Patient list[], int n);
void inputQueueList(Patient *patient);
void sortQueue(Patient list[], int patientCount);
void printSortQueue(Patient list[], int patientCount);

// Khai bao ham medicalRecords
void themMedicalRecord();
void hienThiMedicalRecords();
void timKiemMedicalRecord();

// Khai bao ham Prescription
void themPrescriptionItem(Prescription *p);
void hienThiPrescription(Prescription *p);
void thucHienThanhToan(Payment payments[], int *payCount, Prescription *p);
void hienThiDanhSachThanhToan(Payment payments[], int payCount);

// Ham xoa bo nho dem
void clearBufferMain() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Menu benh nhan va hang cho
void menuPatientAndQueue() {
    int choice;
    do {
        printf("\n================ QUAN LY BENH NHAN & HANG CHO ================\n");
        printf("1. Nhap danh sach benh nhan\n");
        printf("2. In danh sach benh nhan\n");
        printf("3. Dang ky hang cho kham\n");
        printf("4. Sap xep va Hien thi bang dieu phoi hang cho kham\n");
        printf("0. Quay lai Menu chinh\n");
        printf("===============================================================\n");
        printf("Nhap lua chon: ");
        
        if (scanf("%d", &choice) != 1) {
            clearBufferMain();
            continue;
        }
        clearBufferMain();

        switch (choice) {
            case 1:
                inputPatientList(patientList, &patientCount);
                break;
            case 2:
                printPatientList(patientList, patientCount);
                break;
            case 3:
                if (patientCount == 0) {
                    printf("Chua co benh nhan nao! Vui long nhap danh sach benh nhan truoc.\n");
                } else {
                    for (int i = 0; i < patientCount; i++) {
                        printf("\n--- Thiet lap hang cho cho benh nhan %d/%d ---", i + 1, patientCount);
                        inputQueueList(&patientList[i]);
                    }
                }
                break;
            case 4:
                if (patientCount == 0) {
                    printf("Hang cho dang trong!\n");
                } else {
                    sortQueue(patientList, patientCount);
                    printSortQueue(patientList, patientCount);
                }
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

// Menu ho so kham benh
void menuMedicalRecords() {
    int choice;
    do {
        printf("\n================ QUAN LY HO SO KHAM BENH ================\n");
        printf("1. Them ho so kham benh moi\n");
        printf("2. Xem danh sach ho so kham benh\n");
        printf("3. Tim kiem ho so theo Ma luot kham\n");
        printf("0. Quay lai Menu chinh\n");
        printf("==========================================================\n");
        printf("Nhap lua chon: ");
        
        if (scanf("%d", &choice) != 1) {
            clearBufferMain();
            continue;
        }
        clearBufferMain();

        switch (choice) {
            case 1:
                themMedicalRecord();
                break;
            case 2:
                hienThiMedicalRecords();
                break;
            case 3:
                timKiemMedicalRecord();
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

// Menu thuoc va thanh toan
void menuPrescriptionAndPayment() {
    int choice;
    do {
        printf("\n================ QUAN LY DON THUOC & THANH TOAN ================\n");
        printf("1. Them thuoc vao don\n");
        printf("2. Xem chi tiet don thuoc\n");
        printf("3. Thanh toan\n");
        printf("4. Xem danh sach don thanh toan\n");
        printf("0. Quay lai Menu chinh\n");
        printf("=================================================================\n");
        printf("Nhap lua chon: ");
        
        if (scanf("%d", &choice) != 1) {
            clearBufferMain();
            continue;
        }
        clearBufferMain();

        switch (choice) {
            case 1:
                themPrescriptionItem(&currentPrescription);
                break;
            case 2:
                hienThiPrescription(&currentPrescription);
                break;
            case 3:
                thucHienThanhToan(paymentList, &paymentCount, &currentPrescription);
                break;
            case 4:
                hienThiDanhSachThanhToan(paymentList, paymentCount);
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

// menu chinh
int main() {
    // Khởi tạo đơn thuốc mẫu
    currentPrescription.itemCount = 0;
    strcpy(currentPrescription.prescriptionId, "DT001");
    strcpy(currentPrescription.visitId, "LK001");

    int mainChoice;
    do {
        printf("\n==================================================\n");
        printf("   HE THONG QUAN LY PHONG KHAM  \n");
        printf("==================================================\n");
        printf("1. Quan ly Benh nhan & Hang cho kham\n");
        printf("2. Quan ly Ho so kham benh\n");
        printf("3. Quan ly Don thuoc & Thanh toan\n");
        printf("0. Thoat\n");
        printf("==================================================\n");
        printf("Nhap lua chon cua ban: ");

        if (scanf("%d", &mainChoice) != 1) {
            clearBufferMain();
            continue;
        }
        clearBufferMain();

        switch (mainChoice) {
            case 1:
                menuPatientAndQueue();
                break;
            case 2:
                menuMedicalRecords();
                break;
            case 3:
                menuPrescriptionAndPayment();
                break;
            case 0:
                printf("\nDa thoat chuong trinh. Chuc ban mot ngay tot lanh!\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai!\n");
        }
    } while (mainChoice != 0);

    return 0;
}