#include "arrayList.h"

void ArrayList::olustur() {
    bas = NULL;
    sayac = 0;
}

void ArrayList::ekle(int eklecekDeger, int indexNumarasi) {

    if (sayac == 0){ // eleman bulunmuyorsa ve ilk elemanımızı ekleyeceksek
        bas = new int[indexNumarasi + 1];
        *bas = eklecekDeger;
        sayac++;
        return;
    }
    else{ // eleman halihazırda bulunuyorsa
        int* temp = new int[sayac + 1];
        copy(bas, bas + sayac, temp);
        if (indexNumarasi < sayac){ // araya ekleme yapmak istiyorsak
            for (int i = sayac; i > indexNumarasi ; i--) {
                *(temp + i) = *(temp + (i-1));
            }
            *(temp + indexNumarasi) = eklecekDeger;
            sayac++;
            copy(temp, temp + sayac, bas);
        }
        else{ // sona ekleme yapmak istiyorsak
            *(temp + indexNumarasi) = eklecekDeger;
            sayac++;
            bas = new int[sayac];
            copy(temp, temp + sayac, bas);
        }
        // bellekte yer kaplamamasi icin olusturdugumuz gecici alani siliyoruz.
        delete [] temp;
    }

}

void ArrayList::guncelle(int deger, int guncellenecekIndexNumarasi) {
    // bas pointer uzerinden guncellenecek degere ulasip guncelliyoruz.
    *(bas + guncellenecekIndexNumarasi) = deger;
}

void ArrayList::sil(int silinecekIndexNumarasi) {

    int* temp = new int[sayac-1];
    for (int i = silinecekIndexNumarasi; i < sayac; i++) {
        *(bas + i) = *(bas +(i + 1));
    }
    sayac--;
    copy(bas, bas+sayac, temp);
    bas = new int[sayac];
    copy(temp, temp+sayac, bas);
    delete [] temp;
}

void ArrayList::yazdir() {
    for (int i = 0; i <sayac; i++) {
        cout << *(bas + i) << " ";
    }
    if (sayac == 0)
        cout << "Dizinin elemani bulunmuyor!" << endl;
    cout << "---------------------------------------" << endl;
}

void ArrayList::bosalt() {
    delete []bas;
    sayac = 0;
}

