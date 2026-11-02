#include <stdio.h>
#include "clinic.h"
#include <string.h>


static int checkPatientId (const Patient patients [], int patientCount, const char *patientId) {
    for (int i = 0 ; i < patientCount; i++) {
        if(strcmp(patients[i].patientId,patientId) == 0) return 1;
    }
    return 0;
}

static int slotIsTaken (const Appointment list[], int appointmentCount, const char *date, const char *timeSlot) {
    for (int i = 0; i < appointmentCount; i++) {
        if(strcmp(list[i].appointmentDate,date) == 0 && strcmp(list [i].timeSlot,timeSlot) == 0) return 1;
    }
    return 0;
}

int inputAppointment (const Patient patients [],const Appointment list[], Appointment *appointment, int patientCount, int appointmentCount) {
    
    snprintf(appointment -> appointmentId, MAX_ID, "D%03d", appointmentCount + 1);
    printf("Ma Hen Kham: %s\n", appointment -> appointmentId);
    
    printf("Nhap Ma Benh Nhan: ");
    deleteFgets(appointment ->patientId, MAX_ID);

    printf("Nhap Ngay Hen (DD/MM/YYYY): ");
    deleteFgets(appointment -> appointmentDate, MAX_DATE);

    printf("Nhap Khung Gio: "); 
    deleteFgets(appointment -> timeSlot, MAX_TIME);

    if (!checkPatientId (patients, patientCount, appointment-> patientId)) {
        printf("Ma benh nhan khong hop le, Vui long kiem tra lai\n");
    }

    if(slotIsTaken(list, appointmentCount, appointment -> appointmentDate, appointment -> timeSlot)) {
        printf("Khung Gio Nay Da Co Nguoi Dat Truoc\n");
    }
    appointment -> status = APP_DANG_CHO;
    return 1;
}

const char * appointmentStatusText (int status) {
    if(status == APP_DANG_CHO) {
        return ("Dang Cho");
    }else if (status == APP_THANH_CONG) {
        return  ("Thanh Cong");
    }
        return ("Khong Xac Dinh");
}

void printAppointmentList (const Appointment list [], int appointmentCount) {
    printf("\n===DAT LICH HEN ===\n");
    printf("Gio Phong Kham: Mo Cua %s - Dong Cua %s\n",CLINIC_OPEN_TIME,CLINIC_CLOSE_TIME);
    
    printf("| %-12s | %-12s | %-12s | %-10s | %-15s |\n", "Ma Lich Hen", "Ngay Hen", "Ma Benh Nhan", "Khung Gio", "Trang Thai");
    for (int i = 0; i < appointmentCount; i++) {
    printf("| %-12s | %-12s | %-12s | %-10s | %-15s |\n",list[i].appointmentId, list[i].appointmentDate,list[i].patientId, list[i].timeSlot,appointmentStatusText(list[i].status));
    }
}

