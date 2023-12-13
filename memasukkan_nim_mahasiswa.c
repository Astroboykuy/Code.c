#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define nameMaxLength 33
#define nimMaxLenght 15
#define fileName "data_mahasiswa.txt"
struct mahasiswa
{
    char name[nameMaxLength];
    char nim[nimMaxLenght];
};

void clearInputBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){};
}

int countDataBlock(FILE *file){
    file = fopen(fileName, "r");
    int count = 0;
    char c;
    if (file == NULL)
    {
        printf("countDataBlock: Tidak Dapat Membuka File %s\n", fileName);
        exit (10);
    }
 
    for (c = getc(file); c != EOF; c = getc(file)){
        if (c == ';'){
            count++;
        }
    }
    fclose(file);
    if (count == 0 && c == EOF)
    {
        count++;
    }
    return count;
}

void appendToFile(FILE *file, struct mahasiswa mhs){
    file = fopen(fileName, "a");
    if (file == NULL)
    {
        printf("appendToFile: Tidak Dapat Membuka File %s\n", fileName);
        exit (20);
    }

    // Append some text to the file
    fprintf(file, "%s, ", mhs.name);
    fprintf(file, "%s;\n", mhs.nim);

    fclose(file);
}

int readFile(FILE *file, struct mahasiswa imported[]){
    char c;
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("readFile: Tidak Dapat Membuka File %s\n", fileName);
        exit (30);
    }

    int data_block = 0, data = 0;
    for (data_block = 0; c != ';'; data_block++)
    {
        if (c == EOF)
        {
            break;
        }
        for (int j = 0; c != ','; j++)
        {
            c = fgetc(file);
            if (c == EOF)
            {
                break;
            }
            if (c == ';')
            {
                imported[data_block].nim[j] = '\0';
                data = 0;
                c = fgetc(file);
                j = 0;
                break;
            }
            else if (c == ',')
            {
                imported[data_block].name[j] = '\0';
                j = -1;
                data++;
                c= fgetc(file);
            }
            
            else if (data == 0)
            {
                imported[data_block].name[j] = c;
            }
            else if (data == 1)
            {
                imported[data_block].nim[j] = c;
            }
        }
    }

    fclose(file);

    return 0;
}

void printAllDataInStruct(struct mahasiswa input[], int max_data_block){
    FILE* file;
    char c;
    int i = 0, empty = 0;
    file = fopen(fileName, "r");
    fclose(file);
    if (empty != 1)
    {
        for (int i = 0; i < max_data_block; i++)
            {
                printf("Nama: %s\n", input[i].name);
                printf("NIM: %s\n", input[i].nim);
            }
    }
}

void searchData(struct mahasiswa imported[], int max_data_block, struct mahasiswa search) {
    int found = 0;
    for (int i = 0; i < max_data_block; i++) {
        if (strcmp(imported[i].nim, search.nim) == 0) {
            printf("Data Ditemukkan :\n");
            printf("Nama: %s\n", imported[i].name);
            printf("NIM: %s\n", imported[i].nim);
            found = 1;
        }

    }
    
    if (found == 0)
    {
        printf("Tidak Dapat Menemukkan NIM: %s\n", search.nim);
    }
}

void inputData(FILE *file, struct mahasiswa input[], int max_data_block){
    struct mahasiswa mhs1;
    int loop = 1;
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        printf("readFile: Tidak Dapat Membuka File %s\n", fileName);
        exit (30);
    }
    do
    {
        printf("NIM : ");
        scanf("%[^\n]%*c", mhs1.nim);
        for (int i = 0; i < max_data_block; i++) {
            if (strcmp(input[i].nim, mhs1.nim) == 0) {
                loop = 1;
                printf("NIM Sama, ulangi!\n");
                break;
            }
            else {
                loop = 0;
            }
        }
    } while (loop == 1);
    
    printf("Nama : ");
    scanf("%[^\n]%*c", mhs1.name);
    appendToFile(file, mhs1);
    fclose(file);
}

int main()
{
    FILE *file;
    file = fopen(fileName, "a+");
    int max_data_block = countDataBlock(file);
    struct mahasiswa mhs1, imported[max_data_block];
    
    int choice = 0;
    do {
        max_data_block = countDataBlock(file);
        readFile(file, imported);
        printf("+==================+\n");
        printf("|       Menu       |\n");
        printf("+==================+\n");
        printf("| 1. Tambah Data   |\n");
        printf("| 2. Cari Data     |\n");
        printf("| 3. Cetak Data    |\n");
        printf("| 4. Keluar        |\n");
        printf("+==================+\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                system("cls");
                inputData(file, imported, max_data_block);
                break;
            case 2:
                system("cls");
                printf("Masukan NIM dicari : ");
                scanf("%[^\n]%*c", mhs1.nim);
                searchData(imported, max_data_block, mhs1);
                system("pause");
                break;
            case 3:
                system("cls");
                printAllDataInStruct(imported, max_data_block);
                break;
            case 4:
                printf("Program terminated.\n");
                break;
            default:
                system("cls");
                printf("Pilihan tidak ada.\n");
        }
    } while (choice != 4);

    return 0;
}
// modul 3 flowchart sama pseudocode
// waktu cetak nim isiin pause