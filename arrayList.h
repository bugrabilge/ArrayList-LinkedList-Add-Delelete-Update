#ifndef VERIYAPILARIODEV1_ARRAYLIST_H
#define VERIYAPILARIODEV1_ARRAYLIST_H
#include <iostream>
using namespace std;

struct ArrayList {
    int* bas; //dizinin başlangıç adresini tutar
    void olustur(); //başlangıç için gereken tanımları içerir
    void ekle(int, int); //değer ve sıra numarası alarak ekleme yapar
    void guncelle(int, int);//değer ve sıra numarası alarak günceller
    void sil(int); //sıra numarası alarak silme yapar
    void yazdir(); //liste içeriğini ekrana yazar
    void bosalt(); //listenin bellek alanlarını iade eder
    int sayac; //liste kaç eleman olduğunu tutar
};
#endif //VERIYAPILARIODEV1_ARRAYLIST_H
