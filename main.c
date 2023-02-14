/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], date[11];
    char event[100];
    char line[200];
    int year, month, day;
    int print;

    printf("Masukkan file jadwal pacar: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Itu siapa dah?");
        return 0;
    }

    printf("Masukkan tanggal (yyyy-mm-dd): ");
    scanf("%s", date);
    if (strlen(date) != 10 || date[4] != '-' || date[7] != '-') {
        printf("Yang bener dong tanggalnya");
        return 0;
    }
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3) {
        printf("Yang bener dong tanggalnya");
        return 0;
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %*s", event);
        if (strncmp(event, date, 10) == 0) {
            printf("%s",line);
            print=1;
        }
    }
    if (print==1)
    {
        printf("Jangan lupa bawa duit!");
    }else{
        printf("Gaada apa-apa bang tenang");   
    }
    
    fclose(fp);
    return 0;
}
