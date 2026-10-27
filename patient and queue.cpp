#include "clinic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Delete '\n'
void deleteFgets (char *buffer, int max_len) {
    fgets(buffer, max_len,stdin); 
    size_t len = strlen(buffer);
    if(len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }else {
        int discardedChar;
        while ((discardedChar = getchar()) != '\n' && discardedChar != EOF) { }   // bo phan thua
    }
}

//define stdin 1 patient
void inputPatient (Patient * p) {
    printf("Nhap ID Benh Nhan: ");
    deleteFgets (p ->patientId, MAX_ID);

    printf("Nhap sdt Benh Nhan: ");
    deleteFgets (p ->phone, MAX_PHONE);

    printf("Nhap Ho va Ten Benh Nhan: ");
    deleteFgets (p ->fullName, MAX_NAME);

    printf("Nhap Ngay Sinh Benh Nhan: ");
    deleteFgets (p ->dateOfBirth, MAX_DATE);

}

// define print ttin 1 patient
void printPatient (const Patient * p) {
    printf("| %-10s | %-13s | %-25s | %-12s | \n", p ->patientId, p ->phone, p ->fullName, p ->dateOfBirth);
}

//define tĩnh
void inputPatientList (Patient list[], int * n) {
    printf("Nhap So Luong Benh Nhan Hien Tai (Toi da %d): ", MAX_PATIENTS);
    scanf("%d",  n);
    getchar();

    //neu gia tri cua bien ma con tro n tro toi>max
    if (*n > MAX_PATIENTS) {
        printf("Vuot qua kich thuoc mang! Tu dong dat lai thanh %d\n",MAX_PATIENTS);
        *n = MAX_PATIENTS;
    }
    for(int i = 0; i < *n; i++) {
        printf("\n=== Nhap Thong Tin Benh Nhan Thu %d ===\n", i+1);
        inputPatient(&list[i]);
    }
}

void printPatientList (const Patient list [], int n) {
    printf("\n==== Sanh Sach Benh Nhan ====\n");
    printf("| %-10s | %-13s | %-25s | %-12s |\n", "Ma ID", "SDT", "Ho va Ten", "Ngay sinh");
    printf("--------------------------------\n");

    for(int i = 0; i < n;i++) {
        printPatient(&list[i]);
    }
}
//Doi tu gio sang phut de sap xep thu tu kham
int convertHoursToMinutes(const char * timetext) {
    int hours = (timetext[0] - '0') * 10 + (timetext [1] - '0');
    int minutes = (timetext [3] - '0')* 10 + (timetext [4] - '0');
    return hours * 60 + minutes;
}
//Le tan len lich hen va thoi gian khach den 
void inputQueueList (Patient * patient) {
    char inputText[INPUT_BUFFER_SIZE];
    printf("\nChon loai khach hang cho [%s] (1: ONLINE, 2: OFFLINE)", patient -> fullName);
    deleteFgets(inputText,INPUT_BUFFER_SIZE);
    patient->type = atoi(inputText); 

    if(patient-> type == TYPE_ONLINE) {
        printf("Nhap gio hen (HH:MM):");
        char tempTime [MAX_TIME];
        deleteFgets(tempTime,MAX_TIME);
        patient-> appointmentTime = convertHoursToMinutes(tempTime);

        printf("Nhap gio den check in thuc te (HH:MM):");
        char arrTime [MAX_TIME];
        deleteFgets(arrTime,MAX_TIME);
        patient -> arrivalTime =  convertHoursToMinutes(arrTime);

        // Khung gio kham moi 
        if (patient-> arrivalTime > patient -> appointmentTime) {
            printf("[THONG BAO]: Khach hang den tre so voi lich hen ban dau [%s]\n", tempTime);
            printf("Nhap khung gio kham moi gan nhat cho khach hang (HH:MM)");
            deleteFgets(patient -> displayTime,MAX_TIME);
            patient-> appointmentTime = convertHoursToMinutes(patient -> displayTime);
            patient-> currentStatus = STT_TRE_HEN;
        }else  {
            strcpy(patient-> displayTime,tempTime);
            patient -> currentStatus = STT_CHO_KHAM;
        }
    }
    if(patient-> type == TYPE_OFFLINE) {
        printf("Nhap gio khach offline den (HH:MM)");
        deleteFgets(patient -> displayTime,MAX_TIME);
       patient->arrivalTime = convertHoursToMinutes(patient -> displayTime);
        patient ->appointmentTime = patient ->arrivalTime;
        patient->currentStatus = STT_CHO_KHAM;
    }
}

//Exchange sort
void sortQueue (Patient list [], int patientCount) {
    for(int outside = 0; outside < patientCount- 1;outside++) {
        for (int inside = outside + 1; inside < patientCount;inside++) {
            if(list [outside].appointmentTime > list [inside].appointmentTime) {
                Patient temp = list [outside];
                list[outside] = list [inside];
                list[inside] = temp;
            }else if (list [outside].appointmentTime == list [inside].appointmentTime) {
                if(list [outside].type == TYPE_OFFLINE && list [inside].type == TYPE_ONLINE) {
                    Patient temp = list[outside];
                    list [outside] = list [inside];
                    list [inside] = temp;
                }
            }

        }
    }
}

// in bang va updata trang thai
void printSortQueue(Patient list [], int patientCount) {
    printf("\n===== Bang Dieu Phoi Phong Kham ======\n");
    printf("| %-25s | %-12s | %-21s |\n", "Ho va Ten","Gio kham","Trang thai");
    char statusIndex [35];
    for(int index = 0; index < patientCount; index++) {    
        if (index == 0) {
            strcpy (statusIndex,"Dang Kham");
        }else if (index== 1) {
            strcpy (statusIndex,"Chuan Bi Kham");
        }else if(list [index].currentStatus == STT_TRE_HEN ) {
            strcpy (statusIndex, "Doi Gio Kham");
        }else {
            strcpy(statusIndex,"Dang Cho");
        }
        printf("\n");
        printf("| %-25s | %-12s | %-21s |\n", list[index].fullName, list[index].displayTime, statusIndex );
       
    }
}
