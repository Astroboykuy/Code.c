#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Fungsi untuk memvalidasi apakah karakter adalah angka
bool intInpValidation(char input[], int size) {
    bool is_int = false, is_not_int = false;
    for (int i = 0; i < size && input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            is_int = true;
        } else {
            is_not_int = true;
        }
    }

    if (is_int == true && is_not_int == false) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char repeat;
    do {
    char date[3], month[3];
    int d = 0, m = 0, mrepeat = 1, drepeat = 1;
    system ("cls");
    printf("+======================================+\n");
    printf("|      Program Menentukan Zodiak       |\n");
    printf("+======================================+\n");
    printf("|            Daftar Bulan              |\n");
    printf("+======================================+\n");
    printf("| 1.  Januari                          |\n");
    printf("| 2.  Februari                         |\n");
    printf("| 3.  Maret                            |\n");
    printf("| 4.  April                            |\n");
    printf("| 5.  Mei                              |\n");
    printf("| 6.  Juni                             |\n");
    printf("| 7.  Juli                             |\n");
    printf("| 8.  Agustus                          |\n");
    printf("| 9.  September                        |\n");
    printf("| 10. Oktober                          |\n");
    printf("| 11. November                         |\n");
    printf("| 12. Desember                         |\n");
    printf("+======================================+\n");
    do
    {
        printf("Masukkan bulan lahir (dalam angka) : ");
        scanf("%s", month);
        if (intInpValidation(month, sizeof(month) / sizeof(month[0])) == true)
        {
            m = atoi(month);
            if (m > 0 && m < 13)
            {
                mrepeat = 0;

            }
            else {
                printf("Bulan tidak valid\n\n");
            }
        }
        else {
            mrepeat = 1;
            printf("Input bukan angka, ulangi\n\n");
        }
        
    } while (mrepeat == 1);
    
    do
    {
        printf("Masukkan tanggal lahir (dalam angka) : ");
        scanf("%s", date);
        if (intInpValidation(date, sizeof(date) / sizeof(date[0])) == true)
        {
            d = atoi(date);
            if (d > 0 && d < 32)
            {
                if (m == 2){
                    if (d > 29)
                    {
                        printf("Tanggal tidak valid\n\n");
                    }
                    else {
                        drepeat = 0;
                    }
                }
                else if (m == 4 || m == 6 || m == 9 || m ==11)
                {
                    if (d > 30)
                    {
                        printf("Tanggal tidak valid\n\n");
                    }
                    else {
                        drepeat = 0;
                    }
                }
            }
            else {
                printf("Tanggal tidak valid\n\n");
            }
        }
        else {
            drepeat = 1;
            printf("Input bukan angka, ulangi\n\n");
        }
    } while (drepeat == 1);
    
    printf("\nBulan : %d\n", m); // Debug
    printf("Tanggal : %d\n", d);

    switch(m) {
        case 1 :
            if(d>=1 && d<=19)
            printf("Zodiak anda adalah Capricorn\n\n");
            else if(d>=20 && d<=31)
            printf("Zodiak anda adalah Aquarius\n\n");
            break;
        case 2 :
            if(d>=1 && d<=18)
            printf("Zodiak anda adalah Aquarius\n\n");
            else if(d>=19 && d<=29)
            printf("Zodiak anda adalah Pisces\n\n");
            break;              
        case 3 :
            if(d>=1 && d<=20)
            printf("Zodiak anda adalah Pisces\n\n");
            else if(d>=21 && d<=31)
            printf("Zodiak anda adalah Aries\n\n");
            break;
        case 4 :
            if(d>=1 && d<=19)
            printf("Zodiak anda adalah Aries\n\n");
            else if(d>=20 && d<=30)
            printf("Zodiak anda adalah Taurus\n\n");
            break;
        case 5 :
            if(d>=1 && d<=20)
            printf("Zodiak anda adalah Taurus\n\n");
            else if(d>=21 && d<=31)
            printf("Zodiak anda adalah Gemini\n\n");
            break;
        case 6 :
            if(d>=1 && d<=20)
            printf("Zodiak anda adalah Gemini\n\n");
            else if(d>=21 && d<=30)
            printf("Zodiak anda adalah Cancer\n\n");
            break;
        case 7 :
            if(d>=1 && d<=22)
            printf("Zodiak anda adalah Cancer\n\n");
            else if(d>=23 && d<=31)
            printf("Zodiak anda adalah Leo\n\n");
            break;
        case 8 :
            if(d>=1 && d<=22)
            printf("Zodiak anda adalah Leo\n\n");
            else if(d>=23 && d<=31)
            printf("Zodiak anda adalah Virgo\n\n");
            break;
        case 9 :
            if(d>=1 && d<=22)
            printf("Zodiak anda adalah Virgo\n\n");
            else if(d>=23 && d<=30)
            printf("Zodiak anda adalah Libra\n\n");
            break;
        case 10 :
            if(d>=1 && d<=22)
            printf("Zodiak anda adalah Libra\n\n");
            else if(d>=23 && d<=31)
            printf("Zodiak anda adalah Scorpio\n\n");
            break;
        case 11 :
            if(d>=1 && d<=21)
            printf("Zodiak anda adalah Scorpio\n\n");
            else if(d>=22 && d<=30)
            printf("Zodiak anda adalah Sagitarius\n\n");
            break;
        case 12 :
            if(d>=1 && d<=21)
            printf("Zodiak anda adalah Sagitarius\n\n");
            else if(d>=22 && d<=31)
            printf("Zodiak anda adalah Capricorn\n\n");
            break;
        default :
        }

        printf("Apakah Anda ingin mengulang menentukan zodiak? (y/n): ");
        scanf(" %c", &repeat);
        system ("CLS");
    } while (repeat == 'y' || repeat == 'Y');
    return 0;
}