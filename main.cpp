#include <iostream>
#include <chrono>
#include "arrayList.h"
#include "linkedList.h"

using namespace std;

void elemanDoldur(ArrayList& arrayList, LinkedList& linkedList, int doldurulacakElemanSayisi){
    for (int i = 1; i <=doldurulacakElemanSayisi ; i++) {
        arrayList.ekle(i,i-1);
    }
    for (int i = 1; i <=doldurulacakElemanSayisi ; i++) {
        linkedList.ekle(i,i);
    }
}

void eklemeZamanFarkiniOlc(ArrayList islemYapilacakArray, LinkedList islemYapilacakLinked, int eklenecekSira){
    string isleminGerceklestigiYer = "sona";
    if (eklenecekSira==1)
        isleminGerceklestigiYer = "basa";
    else if (eklenecekSira == 5000)
        isleminGerceklestigiYer = "araya";

    cout << "************************************************************" << endl;
    cout << "10 bin elemanlı bir listede:" << endl << endl;
    auto begin = std::chrono::high_resolution_clock::now();
    islemYapilacakArray.ekle(10,eklenecekSira-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Dizi ile gerceklemede " << isleminGerceklestigiYer << " ekleme suresi => " << elapsed.count() << " nano-saniye" << endl << endl;

    begin = std::chrono::high_resolution_clock::now();
    islemYapilacakLinked.ekle(10,eklenecekSira);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Baglantili liste ile gerceklemede " << isleminGerceklestigiYer << " ekleme suresi => " << elapsed.count() << " nano-saniye" << endl;
    cout << "************************************************************" << endl;
}

void guncellemeZamanFarkiniOlc(ArrayList islemYapilacakArray, LinkedList islemYapilacakLinked, int guncellenecekSira){
    string isleminGerceklestigiYer = "sonda";
    if (guncellenecekSira==1)
        isleminGerceklestigiYer = "basta";
    else if (guncellenecekSira == 5000)
        isleminGerceklestigiYer = "arada";

    cout << "************************************************************" << endl;
    cout << "10 bin elemanlı bir listede:" << endl << endl;
    auto begin = std::chrono::high_resolution_clock::now();
    islemYapilacakArray.ekle(10,guncellenecekSira-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Dizi ile gerceklemede " << isleminGerceklestigiYer << " guncelleme suresi => " << elapsed.count() << " nano-saniye" << endl << endl;

    begin = std::chrono::high_resolution_clock::now();
    islemYapilacakLinked.ekle(10,guncellenecekSira);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Baglantili liste ile gerceklemede " << isleminGerceklestigiYer << " guncelleme suresi => " << elapsed.count() << " nano-saniye" << endl;
    cout << "************************************************************" << endl;
}

void silmeZamanFarkiniOlc(ArrayList islemYapilacakArray, LinkedList islemYapilacakLinked, int silinecekSira){
    string isleminGerceklestigiYer = "sonda";
    if (silinecekSira==1)
        isleminGerceklestigiYer = "basta";
    else if (silinecekSira == 5000)
        isleminGerceklestigiYer = "aradan";

    cout << "************************************************************" << endl;
    cout << "10 bin elemanlı bir listede:" << endl << endl;
    auto begin = std::chrono::high_resolution_clock::now();
    islemYapilacakArray.sil(silinecekSira-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Dizi ile gerceklemede " << isleminGerceklestigiYer << " silme suresi => " << elapsed.count() << " nano-saniye" << endl << endl;

    begin = std::chrono::high_resolution_clock::now();
    islemYapilacakLinked.sil(silinecekSira);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "Baglantili liste ile gerceklemede " << isleminGerceklestigiYer << " silme suresi => " << elapsed.count() << " nano-saniye" << endl;
    cout << "************************************************************" << endl;
}

void ekleMenusu(ArrayList islemYapilacakArray, LinkedList islemYapilacakLinked){
    int secim;
    bool menu = true;
    while (menu){
        cout << "\t\t\t *EKLEME MENUSU*" << endl;
        cout << " Listenin neresine ekleme islemi yapmak istediginizi seciniz." << endl;
        cout << "  1) Basa Ekleme Yap" << endl;
        cout << "  2) Araya Ekleme Yap" << endl;
        cout << "  3) Sona Ekleme Yap" << endl;
        cout << "  4) Ana Menuye Don" << endl;
        cin >> secim ;
        switch (secim) {
            case 1:
                eklemeZamanFarkiniOlc(islemYapilacakArray, islemYapilacakLinked, 1);
                break;
            case 2:
                eklemeZamanFarkiniOlc(islemYapilacakArray, islemYapilacakLinked, 5000);
                break;
            case 3:
                eklemeZamanFarkiniOlc(islemYapilacakArray, islemYapilacakLinked, 10000);
                break;
            case 4:
                menu = false;
                break;
            default:
                cout << " Gecersiz Deger Sectiniz, Lutfen Tekrar Deneyiniz." << endl << endl;
        }
    }
}

void silMenusu(ArrayList islemYapilacakArray, LinkedList islemYapilacakLinked){
    int secim;
    bool menu = true;
    while (menu){
        cout << "\t\t\t *SILME MENUSU*" << endl;
        cout << " Listenin neresinden silme islemi yapmak istediginizi seciniz." << endl;
        cout << "  1) Bastaki Degeri Sil" << endl;
        cout << "  2) Aradan Deger Sil" << endl;
        cout << "  3) Sondaki Degeri Sil" << endl;
        cout << "  4) Ana Menuye Don" << endl;
        cin >> secim ;
        switch (secim) {
            case 1:
                silmeZamanFarkiniOlc(islemYapilacakArray, islemYapilacakLinked, 1);
                break;
            case 2:
                silmeZamanFarkiniOlc(islemYapilacakArray, islemYapilacakLinked, 5000);
                break;
            case 3:
                silmeZamanFarkiniOlc(islemYapilacakArray, islemYapilacakLinked, 10000);
                break;
            case 4:
                menu = false;
                break;
            default:
                cout << " Gecersiz Deger Sectiniz, Lutfen Tekrar Deneyiniz." << endl << endl;
        }
    }
}

void guncelleMenusu(ArrayList islemYapilacakArray, LinkedList islemYapilacakLinked){
    int secim;
    bool menu = true;
    while (menu){
        cout << "\t\t\t *GUNCELLEME MENUSU*" << endl;
        cout << " Listenin neresinde guncelleme islemi yapmak istediginizi seciniz." << endl;
        cout << "  1) Bastaki Degeri Guncelle" << endl;
        cout << "  2) Aradaki Degeri Guncelle" << endl;
        cout << "  3) Sondaki Degeri Guncelle" << endl;
        cout << "  4) Ana Menuye Don" << endl;
        cin >> secim ;
        switch (secim) {
            case 1:
                guncellemeZamanFarkiniOlc(islemYapilacakArray, islemYapilacakLinked, 1);
                break;
            case 2:
                guncellemeZamanFarkiniOlc(islemYapilacakArray, islemYapilacakLinked, 5000);
                break;
            case 3:
                guncellemeZamanFarkiniOlc(islemYapilacakArray, islemYapilacakLinked, 10000);
                break;
            case 4:
                menu = false;
                break;
            default:
                cout << " Gecersiz Deger Sectiniz, Lutfen Tekrar Deneyiniz." << endl << endl;
        }
    }
}

int main() {
    LinkedList linked;
    ArrayList array;
    array.olustur();
    linked.olustur();
    elemanDoldur(array, linked, 10000);
    bool menu = true;
    while (menu){
        int secim;
        cout << "\t\t\t *ANA MENU*" << endl;
        cout << " Lütfen test etmek isteginiz islemi seciniz." << endl;
        cout << "  1) Eleman Ekleme İslemi" << endl;
        cout << "  2) Eleman Silme İslemi" << endl;
        cout << "  3) Eleman Guncelleme İslemi" << endl;
        cout << "  4) Cikis" << endl;
        cin >> secim;
        switch (secim) {
            case 1:
                ekleMenusu(array, linked);
                break;
            case 2:
                silMenusu(array, linked);
                break;
            case 3:
                guncelleMenusu(array, linked);
                break;
            case 4:
                menu = false;
                break;
            default:
                cout << " Gecersiz Deger Sectiniz, Lutfen Tekrar Deneyiniz." << endl << endl;
        }
    }
    array.bosalt();
    linked.bosalt();
    return 0;
}
