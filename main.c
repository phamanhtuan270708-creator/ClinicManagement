#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clinic.h"

Patient patientList[MAX_DAILY_PATIENTS];
int patientCount = 0;

Visit visitList[MAX_VISITS];
int visitCount = 0;
int nextCaseNumber = 1;

Appointment appointmentList[MAX_DAILY_APPOINTMENT];
int appointmentCount = 0;

Prescription currentPrescription;
Payment paymentList[MAX_DAILY_PATIENTS];
int paymentCount = 0;

// // Khai bao ham medicalRecords
// void themMedicalRecord();
// void hienThiMedicalRecords();
// void timKiemMedicalRecord();

// Khai bao ham Prescription
void themPrescriptionItem(Prescription *p);
void hienThiPrescription(Prescription *p);
void thucHienThanhToan(Payment payments[], int *payCount, Prescription *p);
void hienThiDanhSachThanhToan(Payment payments[], int payCount);

// Doc lua chon menu
static int readMenuChoice(int *choice) {
    return readInteger(choice);
}


static void bookNewAppointment() {
    if (patientCount == 0) {
        printf("Chua co benh nhan nao! Vui long nhap danh sach benh nhan truoc.\n");
        return;
    }
    if (appointmentCount >= MAX_DAILY_APPOINTMENT) {
        printf("Lich hen trong ngay da day (%d).\n", MAX_DAILY_APPOINTMENT);
        return;
    }

    printf("\n==== DAT LICH HEN ===\n");
    Appointment *newAppointment = &appointmentList[appointmentCount];

    if (!inputAppointment(patientList, appointmentList, newAppointment, patientCount, appointmentCount)) {
        printf("Dat lich chua thanh cong. Vui long thu lai.\n");
        return;
    }
    newAppointment->status = APP_DANG_CHO;
    appointmentCount++;
    printAppointmentList(newAppointment, 1);

    char answerText[INPUT_BUFFER_SIZE];
    printf("Le Tan xac nhan lich hen nay (1: CO - 2: DE SAU): ");
    deleteFgets(answerText, INPUT_BUFFER_SIZE);

    if (answerText[0] == '1') {
        newAppointment->status = APP_THANH_CONG;
        printAppointmentList(newAppointment, 1);
    } else {
        printf("Lich hen van o trang thai Dang cho, co the xac nhan sau trong menu.\n");
    }
}

// Xac nhan lich hen da de sau
static void confirmPendingAppointment() {
    int pendingCount = 0;
    for (int index = 0; index < appointmentCount; index++) {
        if (appointmentList[index].status == APP_DANG_CHO) {
            printAppointmentList(&appointmentList[index], 1);
            pendingCount++;
        }
    }
    if (pendingCount == 0) {
        printf("Khong co lich hen nao dang cho xac nhan.\n");
        return;
    }

    char appointmentIdText[MAX_ID];
    printf("Nhap Ma Lich Hen can xac nhan: ");
    deleteFgets(appointmentIdText, MAX_ID);

    for (int index = 0; index < appointmentCount; index++) {
        if (strcmp(appointmentList[index].appointmentId, appointmentIdText) == 0) {
            if (appointmentList[index].status == APP_THANH_CONG) {
                printf("Lich hen nay da duoc xac nhan truoc do.\n");
            } else {
                appointmentList[index].status = APP_THANH_CONG;
                printAppointmentList(&appointmentList[index], 1);
            }
            return;
        }
    }
    printf("Khong tim thay Ma Lich Hen [%s].\n", appointmentIdText);
}


void menuAppointment() {
    int choice = -1;
    do {
        printf("\n================ QUAN LY LICH HEN ================\n");
        printf("1. Xac nhan lich hen\n");
        printf("2. Xac nhan lich hen dang cho\n");
        printf("3. Xem danh sach lich hen\n");
        printf("0. Quay lai Menu chinh\n");
        printf("==================================================\n");
        printf("Nhap lua chon: ");

        int readResult = readMenuChoice(&choice);
        if (readResult == -1) { return; }
        if (readResult == 0) { choice = -1; continue; }

        switch (choice) {
            case 1: bookNewAppointment(); break;
            case 2: confirmPendingAppointment(); break;
            case 3: printAppointmentList(appointmentList, appointmentCount); break;
            case 0: break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}


void menuVisit() {
    int choice = -1;
    do {
        printf("\n================ QUAN LY LUOT KHAM ================\n");
        printf("1. Nhap luot kham\n");
        printf("2. Xem danh sach luot kham\n");
        printf("0. Quay lai Menu chinh\n");
        printf("===================================================\n");
        printf("Nhap lua chon: ");

        int readResult = readMenuChoice(&choice);
        if (readResult == -1) { return; }
        if (readResult == 0) { choice = -1; continue; }

        switch (choice) {
            case 1:
                if (patientCount == 0) {
                    printf("Chua co benh nhan nao! Vui long nhap danh sach benh nhan truoc.\n");
                } else if (visitCount >= MAX_VISITS) {
                    printf("Da day so luot kham toi da (%d).\n", MAX_VISITS);
                } else {
                    inputVisitList(visitList, &visitCount, &nextCaseNumber);
                }
                break;
            case 2:
                printVisitList(visitList, visitCount);
                break;
            case 0: break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}


void menuPatientAndQueue() {
    int choice = -1;
    do {
        printf("\n================ QUAN LY BENH NHAN & HANG CHO ================\n");
        printf("1. Nhap danh sach benh nhan\n");
        printf("2. In danh sach benh nhan\n");
        printf("3. Dang ky hang cho kham\n");
        printf("4. Sap xep va Hien thi bang dieu phoi hang cho kham\n");
        printf("0. Quay lai Menu chinh\n");
        printf("===============================================================\n");
        printf("Nhap lua chon: ");

       int readResult = readMenuChoice(&choice);

       if (readResult == -1) {
          return;
      }
       if (readResult == 0) {
          choice = -1;
            continue;
       }

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
                    for (int index = 0; index < patientCount; index++) {
                        printf("\n--- Thiet lap hang cho cho benh nhan %d/%d ---", index + 1, patientCount);
                        inputQueueList(&patientList[index]);
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
            case 0: break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

// // Menu ho so kham benh
// void menuMedicalRecords() {
//     int choice = -1;
//     do {
//         printf("\n================ QUAN LY HO SO KHAM BENH ================\n");
//         printf("1. Them ho so kham benh moi\n");
//         printf("2. Xem danh sach ho so kham benh\n");
//         printf("3. Tim kiem ho so theo Ma luot kham\n");
//         printf("0. Quay lai Menu chinh\n");
//         printf("==========================================================\n");
//         printf("Nhap lua chon: ");

//         int readResult = readMenuChoice(&choice);
//         if (readResult == -1) { return; }
//         if (readResult == 0) { choice = -1; continue; }

//         switch (choice) {
//             case 1: themMedicalRecord(); break;
//             case 2: hienThiMedicalRecords(); break;
//             case 3: timKiemMedicalRecord(); break;
//             case 0: break;
//             default: printf("Lua chon khong hop le!\n");
//         }
//     } while (choice != 0);
// }


void menuPrescriptionAndPayment() {
    int choice = -1;
    do {
        printf("\n================ QUAN LY DON THUOC & THANH TOAN ================\n");
        printf("1. Them thuoc vao don\n");
        printf("2. Xem chi tiet don thuoc\n");
        printf("3. Thanh toan\n");
        printf("4. Xem danh sach don thanh toan\n");
        printf("0. Quay lai Menu chinh\n");
        printf("=================================================================\n");
        printf("Nhap lua chon: ");

        int readResult = readMenuChoice(&choice);
        if (readResult == -1) { return; }
        if (readResult == 0) { choice = -1; continue; }

        switch (choice) {
            case 1: themPrescriptionItem(&currentPrescription); break;
            case 2: hienThiPrescription(&currentPrescription); break;
            case 3: thucHienThanhToan(paymentList, &paymentCount, &currentPrescription); break;
            case 4: hienThiDanhSachThanhToan(paymentList, paymentCount); break;
            case 0: break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}


int main() {
    
    currentPrescription.itemCount = 0;
    strcpy(currentPrescription.prescriptionId, "DT001");
    strcpy(currentPrescription.visitId, "LK001");

    int mainChoice = -1;
    do {
        printf("\n==================================================\n");
        printf("   HE THONG QUAN LY PHONG KHAM  \n");
        printf("==================================================\n");
        printf("1. Quan ly Benh nhan & Hang cho kham\n");
        printf("2. Quan ly Lich hen\n");
        printf("3. Quan ly Luot kham\n");
        // printf("4. Quan ly Ho so kham benh\n");
        printf("4. Quan ly Don thuoc & Thanh toan\n");
        printf("0. Thoat\n");
        printf("==================================================\n");
        printf("Nhap lua chon cua ban: ");

        int readResult = readMenuChoice(&mainChoice);
        if (readResult == -1) { break; }
        if (readResult == 0) { mainChoice = -1; continue; }

        switch (mainChoice) {
            case 1: menuPatientAndQueue(); break;
            case 2: menuAppointment(); break;
            case 3: menuVisit(); break;
            // case 4: menuMedicalRecords(); break;
            case 4: menuPrescriptionAndPayment(); break;
            case 0:
                printf("\nDa thoat chuong trinh. Chuc ban mot ngay tot lanh!\n");
                break;
            default:
                printf("\nLua chon khong hop le. Vui long chon lai!\n");
        }
    } while (mainChoice != 0);

    return 0;
}
