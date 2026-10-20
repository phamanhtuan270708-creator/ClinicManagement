#include <stdio.h>
#include "clinic.h"

MedicalRecord records[MAX];
int recordCount = 0;

// xoa du lieu con du trong bo nho dem
void clearBuffer(void) 
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Kiem tra sau so khong co chu hoac ky tu la
int checkNumberEnd(void) 
{
    int c;

    while ((c = getchar()) == ' ' || c == '\t');

    if (c == '\n' || c == EOF)
        return 1;

    while (c != '\n' && c != EOF)
        c = getchar();

    return 0;
}

// Nhap so nguyen 
int inputInt(const char *message) 
{
    int value;

    while (1) 
    {
        printf("%s", message);

        if (scanf("%d", &value) == 1) 
        {
            if (checkNumberEnd())
                return value;
        } 
        else 
        {
            clearBuffer();
        }

        printf("Loi: Chi duoc nhap so nguyen! Vui long nhap lai.\n");
    }
}

// Nhap so thuc
float inputFloat(const char *message, float min, float max) 
{
    float value;

    while (1) {
        printf("%s", message);

        if (scanf("%f", &value) == 1) 
        {
            if (checkNumberEnd() &&
                value >= min && value <= max) 
            {
                return value;
            }
        } 
        else 
        {
            clearBuffer();
        }

        printf("Loi: Nhap so hop le trong khoang %.1f den %.1f!\n", min, max);
    }
}

// Nhap vao chi gom chu cai va khoang trang
int inputText(const char *message, char text[], int size) 
{
    while (1) {
        int c;
        int i = 0;
        int hasLetter = 0;
        int tooLong = 0;
        int valid = 1;
        printf("%s", message);

        while ((c = getchar()) != '\n' && c != EOF) 
        {
            if (i < size - 1)
                text[i++] = (char)c;
            else
                tooLong = 1;

            if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                c >= 128) {
                hasLetter = 1;
            } 
            else if (c != ' ' && c != '\t') 
            {
                valid = 0;
            }
        }

        text[i] = '\0';

        if (valid && hasLetter && !tooLong)
            return 1;

        printf("Loi: Chi nhap chu va khoang trang, "
               "khong nhap so hoac ky tu dac biet!\n");

        if (c == EOF)
            return 0;
    }
}

// Nhap chuoi ma ID (cho phep chu va so, khong chua khoang trang)
int inputCode(const char *message, char text[], int size) 
{
    while (1) {
        int c;
        int i = 0;
        int hasChar = 0;
        int tooLong = 0;
        int valid = 1;
        printf("%s", message);

        while ((c = getchar()) != '\n' && c != EOF) 
        {
            if (i < size - 1)
                text[i++] = (char)c;
            else
                tooLong = 1;

            if ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9')) {
                hasChar = 1;
            } 
            else 
            {
                valid = 0;
            }
        }

        text[i] = '\0';

        if (valid && hasChar && !tooLong)
            return 1;

        printf("Loi: Ma chi gom chu va so, khong chua khoang trang hoac ky tu dac biet!\n");

        if (c == EOF)
            return 0;
    }
}

// Ham so sanh 2 chuoi thu cong (khong dung string.h)
int compareString(const char *s1, const char *s2) 
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Kiem tra luot kham da ton tai 
int findRecord(const char *visitId) 
{
    for (int i = 0; i < recordCount; i++) 
    {
        if (compareString(records[i].visitId, visitId) == 0)
            return i;
    }

    return -1;
}

// Them ho so kham benh
void addMedicalRecord(void) 
{
    if (recordCount >= MAX) 
    {
        printf("Danh sach ho so da day!\n");
        return;
    }

    MedicalRecord temp;

    if (!inputCode("Nhap luot kham: ", temp.visitId, sizeof(temp.visitId)))
        return;

    if (findRecord(temp.visitId) != -1) {
        printf("Loi: Luot kham da co ho so!\n");
        return;
    }

    if (!inputText("Nhap trieu chung: ",
                   temp.symptoms,
                   sizeof(temp.symptoms)))
        return;

    temp.height = inputFloat("Nhap chieu cao (cm): ",
                             1.0f, 300.0f);

    temp.weight = inputFloat("Nhap can nang (kg): ",
                             1.0f, 500.0f);

    if (!inputText("Nhap chan doan: ",
                   temp.diagnosis,
                   sizeof(temp.diagnosis)))
        return;

    records[recordCount] = temp;
    recordCount++;

    printf("Them ho so kham benh thanh cong!\n");
}

// Hien thi danh sach ho so
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

// Tim kiem ho so theo luot kham
void searchMedicalRecord(void) 
{
    char searchId[20];
    if (!inputCode("Nhap luot kham can tim: ", searchId, sizeof(searchId)))
        return;

    int index = findRecord(searchId);

    if (index == -1) 
    {
        printf("Khong tim thay ho so!\n");
        return;
    }

    printf("Luot kham  : %s\n", records[index].visitId);
    printf("Trieu chung: %s\n", records[index].symptoms);
    printf("Chieu cao  : %.1f cm\n", records[index].height);
    printf("Can nang   : %.1f kg\n", records[index].weight);
    printf("Chan doan  : %s\n", records[index].diagnosis);
}

int main(void) 
{
    int choice;

    do {
        printf("\n===== MEDICAL RECORD =====\n");
        printf("0. Thoat\n");
        printf("1. Them ho so kham benh\n");
        printf("2. Hien thi ho so\n");
        printf("3. Tim kiem ho so\n");

        choice = inputInt("Lua chon: ");

        switch (choice) 
        {
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