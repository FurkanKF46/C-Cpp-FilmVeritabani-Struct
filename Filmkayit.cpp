#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "filmislemleri.h"
//FURKAN KOCA 221030910028
using namespace std;
int sayac = 0;
void filmekle(filminfo ptr1[], filmturu ptr2[]);
void filmliste(filminfo ptr1[], filmturu ptr2[]);
void filmcikar(filminfo ptr1[], filmturu ptr2[]);
int main()
{
    int secim;
    filminfo *ptr1 = new filminfo[1];
    filmturu *ptr2 = new filmturu[5];
    cout << "================================================================" << endl;
    cout << "          Film Veritabani Uygulamasina Hosgeldiniz" << endl;
    cout << "================================================================" << endl;
    do
    {
        cout << "Ana Menu" << endl;
        cout << "(1)Film Ekle" << endl;
        cout << "(2)Film Cikar" << endl;
        cout << "(3)Tum Film Listesi" << endl;
        cout << "(0) Cikis" << endl;
        cin >> secim;
        switch (secim)
        {
        case 1:
            filmekle(ptr1, ptr2);
            break;
        case 2:
            filmcikar(ptr1, ptr2);
            break;
        case 3:
            filmliste(ptr1, ptr2);
            break;
        case 0:
            break;
        default:
            cout << "Yanlis bir numara girdiniz" << endl;
            break;
        }
    } while (0 < secim);
    delete[] ptr1;
    delete[] ptr2;
    ptr1 = NULL;
    ptr2 = NULL;
    return 0;
}
void filmekle(filminfo ptr1[], filmturu ptr2[])
{
    cout << "Film Ekleme" << endl;
    cout << "Filmin ID: ";
    cin >> ptr1[sayac].ID;
    cout << "Filmin Adi: ";
    cin >> ptr1[sayac].ad;
    cout << "Filmin Yonetmeni: ";
    cin >> ptr1[sayac].yonetmen;
    cout << "Filmin Yapim yili: ";
    cin >> ptr1[sayac].yapimyili;
    cout << "Filmin Turu(0-Aksiyon,1-Gerilim,2-Komedi,3-Drama): ";
    scanf("%d", &ptr2[sayac]);
    sayac++;
    cout << "Film listeye eklendi" << endl;
}

void filmliste(filminfo ptr1[], filmturu ptr2[])
{
    cout << "Filmlerin Listesi:" << endl;
    for (int i = 0; i < sayac; i++)
    {
        cout << endl;
        cout << "Filmin ID: " << ptr1[i].ID << endl;
        cout << "Filmin Adi: " << ptr1[i].ad << endl;
        cout << "Filmin Yonetmeni: " << ptr1[i].yonetmen << endl;
        cout << "Filmin Yapim yili: " << ptr1[i].yapimyili << endl;
        cout << "Filmin Turu:";
        switch (ptr2[i])
        {
        case Aksiyon:
            cout << "Aksiyon" << endl;
            break;
        case Gerilim:
            cout << "Gerilim" << endl;
            break;
        case Komedi:
            cout << "Komedi" << endl;
            break;
        case Dram:
            cout << "Drama" << endl;
            break;
        }
    }
}
void filmcikar(filminfo ptr1[], filmturu ptr2[])
{
    cout << "Filmlerin Listesi:" << endl;
    int cikarma;
    for (int i = 0; i < sayac; i++)
    {
        cout << endl;
        cout << "Filmin ID: " << ptr1[i].ID << endl;
        cout << "Filmin Ad�: " << ptr1[i].ad << endl;
    }
    cout << "Cikarmak istediginiz filmin ID'sini giriniz:" << endl;
    cin >> cikarma;
    for (int a = 0; a < sayac; a++)
    {
        if (ptr1[a].ID == cikarma)
        {
            for (int b = a; b < (sayac - 1); b++)
            {
                ptr1[b].ID = ptr1[b + 1].ID;
                strcpy(ptr1[b].ad, ptr1[b + 1].ad);
                strcpy(ptr1[b].yonetmen, ptr1[b + 1].yonetmen);
                ptr1[b].yapimyili = ptr1[b + 1].yapimyili;
                ptr2[b] = ptr2[b + 1];
                a--;
                sayac--;
            }
        }
    }
    cout<<"Film basariyla silindi: "<< endl;
}
