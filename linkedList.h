#ifndef VERIYAPILARIODEV1_LINKEDLIST_H
#define VERIYAPILARIODEV1_LINKEDLIST_H
#include <iostream>
using namespace std;

struct Node{
    int deger; //düğümün sayısal değeri
    Node* sonraki; //sonraki düğüme işaretçi
};

struct LinkedList {
    Node *bas; //listenin başlangıç adresini tutar
    void olustur(); //başlangıç için gereken tanımları içerir
    void ekle(int, int); //değer ve sıra numarası alarak ekleme yapar
    void guncelle(int, int);//değer ve sıra numarası alarak günceller
    void sil(int); //sıra numarası alarak silme yapar
    void yazdir(); //liste içeriğini ekrana yazar
    void bosalt(); //listenin bellek alanlarını iade eder
    int sayac; //liste kaç eleman olduğunu tutar
};

#endif //VERIYAPILARIODEV1_LINKEDLIST_H
