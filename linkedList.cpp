#include "linkedList.h"

void LinkedList::olustur() {
    bas = NULL;
    sayac = 0;
}

void LinkedList::ekle(int eklenecekDeger, int siraNumarasi) {
    if (!bas){ // liste bossa ve ilk eleman eklenecekse
        bas = new Node();
        bas->deger = eklenecekDeger;
        bas->sonraki=NULL;
        sayac++;
        return;
    }
    else{ // listede halihazırda eleman varsa
        Node* tara;
        tara = bas;
        Node* onceki;
        Node* temp= new Node();
        temp->deger = eklenecekDeger;
        temp->sonraki = NULL;
        if (siraNumarasi==1){ // eleman olmasına ragmen ilk siraya eklenecekse
            temp->sonraki = bas;
            bas = temp;
            sayac++;
            return;
        }
        for (int i = 1; i < siraNumarasi-1 ; i++) {
            onceki = tara;
            tara = tara->sonraki;
        }
        temp->sonraki = tara->sonraki;
        tara->sonraki = temp;
        sayac++;
    }
}

void LinkedList::guncelle(int deger, int siraNumarasi) {
    Node* tara;
    tara = bas;
    if (!tara){
        cout << "Liste boş!" << endl;
        return;
    }
    while (siraNumarasi != 1){
        tara = tara->sonraki;
        siraNumarasi--;
    }
    tara->deger= deger;
}

void LinkedList::sil(int silinecekSiraNumarasi) {
    Node* tara;
    Node* onceki;
    tara = bas;
    for (int i = 1; i < silinecekSiraNumarasi ; i++) {
        onceki = tara;
        tara = tara->sonraki;
    }
    if (silinecekSiraNumarasi == 1){ // başa ekleme yapıyorsak
        bas = tara->sonraki;
        sayac--;
        delete tara;
        return;
    }
    if (tara->sonraki){ // araya ekleme yapıyorsak
        onceki->sonraki = tara->sonraki;
        sayac--;
        delete tara;
        return;
    } else{ // tara-> sonraki NULL ise yani son eleman ise
        onceki->sonraki = NULL;
        sayac--;
        delete tara;
    }
}

void LinkedList::yazdir() {
    Node* tara;
    tara = bas;
    if (!tara){
        cout << "Liste boş!" << endl;
        return;
    }
    while (tara){
        cout << tara->deger << " ";
        tara = tara->sonraki;
    }
    cout << endl;
}

void LinkedList::bosalt() {
    Node* tara;
    tara = bas;
    Node* temp;
    while(tara){
        temp = tara->sonraki;
        delete tara;
        tara= temp;
    }
    bas = NULL;
    sayac = 0;
}
