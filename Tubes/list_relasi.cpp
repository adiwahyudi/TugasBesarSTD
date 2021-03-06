#include "list_relasi.h"

void createListRelasi(List_relasi &L){
    first(L) = NULL;
    last(L) = NULL;
}/// I Wayan Adi Wahyudi (1301194084)

void insertFirstRelasi(List_relasi &L, adr_relasi P){
    if (first(L) != NULL){
        next(P) = first(L);
        first(L) = P;
        last(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
    }
}/// I Wayan Adi Wahyudi (1301194084)

void insertLastRelasi(List_relasi &L, adr_relasi P){

    if (first(L) == NULL){
        insertFirstRelasi(L,P);
    } else {
        next(last(L)) = P;
        last(L) = P;
        next(P) = NULL;
    }
}/// I Wayan Adi Wahyudi (1301194084)

void insertAfterRelasi(adr_relasi Prec, adr_relasi P){

    next(P) = next(Prec);
    next(Prec) = P;

}/// I Wayan Adi Wahyudi (1301194084)

void deleteFirstRelasi(List_relasi &L, adr_relasi &P){

     if (first(L) != NULL){
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(first(L));
            next(P) = NULL;
        }
    }
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

void deleteLastRelasi(List_relasi &L, adr_relasi &P){
    P = first(L);
    while ( next(P) != last(L) ) {
        P = next(P);
    }
    last(L) = P;
    P = next(P);
    next(last(L)) = NULL;
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

void deleteAfterRelasi(List_relasi &L,adr_relasi Prec, adr_relasi &P){

    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;

} ///Muhammad Ikram Kaer Sinapoy(1301193341)

adr_relasi alokasiRelasi( adr_parent P, adr_child C){

    adr_relasi Q = new elmlist_relasi;

    child(Q) = C;
    parent(Q) = P;
    return Q;
}/// I Wayan Adi Wahyudi (1301194084)

void dealokasiRelasi(adr_relasi &P){
    delete P;
}

adr_relasi findElmRelasi(List_relasi L, int diC, int diP){
    adr_relasi Q = first(L);
    while (Q != NULL) {
        if (info(parent(Q)).kodeKaset == diP  && info(child(Q)).memberID == diC){
            return Q;
        } else {
            Q = next(Q);
        }
    }
    return NULL;
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

void printRelasi(List_relasi L){
    adr_relasi P = first(L);
    int i = 1;
    if (P != NULL) {
        while (P != NULL){
            cout <<i<<"."<<info(child(P)).Nama <<" membeli kaset "<<info(parent(P)).tipe<<" berjudul ";
            cout << info(parent(P)).judul <<" seharga Rp. " << info(parent(P)).harga <<endl;
            P = next(P);
            i++;
        }
    } else {
        cout << "Tidak ada data pembelian" <<endl;
    }
    cout<<endl;
}/// I Wayan Adi Wahyudi (1301194084)

void bersih (){
    cout<<endl;
    system("pause > 0 | echo tekan enter untuk melanjutkan..");
    system("CLS");
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

void case3(List_child &LC,List_parent &LP,List_relasi &LR,adr_child &AC,adr_parent &AP,adr_relasi &AR) {

    int cariIDmem;
    int cariKodeKaset;

    cout << "ID Member\t: ";
    cin >> cariIDmem;
    cout << "ID Kaset\t: ";
    cin >> cariKodeKaset;
    AC = findElmChild(LC,cariIDmem);AP = findElmParent(LP,cariKodeKaset);
    if (findElmRelasi(LR,cariIDmem,cariKodeKaset) == NULL){
        if (AC && AP) {
            AR = alokasiRelasi(AP,AC);
            insertLastRelasi(LR,AR);
            cout << "\nSelamat anda berhasil membeli kaset!" << endl;
        } else {
            cout << "\nMaaf anda tidak terdaftar sebagai Member"<<endl;
        }
    } else {
        cout << "\nMaaf anda sudah mengambil kaset tersebut" <<endl;
    }
    bersih();
}/// I Wayan Adi Wahyudi (1301194084)

adr_relasi cariParentDiRelasi(List_relasi LR,int x){

    adr_relasi P = first(LR);

    while (P != NULL) {
        if (info(parent(P)).kodeKaset == x){
            return P;
        } else {
            P = next(P);
        }
    }
    return P;
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

adr_relasi cariChildDiRelasi(List_relasi LR,int x){

    adr_relasi P = first(LR);

    while (P != NULL) {
        if (info(child(P)).memberID == x){
            return P;
        } else {
            P = next(P);
        }
    }
    return NULL;
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

void deleteParentdiRelasi(List_relasi &LR,int AP) {

    adr_relasi P,Q;
    while (cariParentDiRelasi(LR,AP) != NULL){
        if (info(parent(first(LR))).kodeKaset == AP ){
            deleteFirstRelasi(LR,P);
            dealokasiRelasi(P);
        } else if (info(parent(last(LR))).kodeKaset == AP ){
            deleteLastRelasi(LR,P);
            dealokasiRelasi(P);
        } else {
            Q = first(LR);
            while (cariParentDiRelasi(LR,info(parent(P)).kodeKaset) != NULL){
                if (info(next(parent(Q))).kodeKaset == AP){
                    deleteAfterRelasi(LR,Q,next(Q));
                    dealokasiRelasi(Q);
                }
                Q = next(Q);
            }
        }
    }
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

void deleteChilDiRelasi(List_relasi &LR, int AP){
    adr_relasi P;
    while (cariChildDiRelasi(LR,AP) != NULL) {
        if(info(child(first(LR))).memberID == AP ){
            deleteFirstRelasi(LR,P);
            dealokasiRelasi(P);
        } else if (info(child(last(LR))).memberID == AP){
            deleteLastRelasi(LR,P);
            dealokasiRelasi(P);
        } else {
            adr_relasi Q = first(LR);
            while (P != NULL && info(child(Q)).memberID != AP) {
                   P = Q;
                   Q = next(Q);
                }
            deleteAfterRelasi(LR,P,Q);
            dealokasiRelasi(Q);
        }
    }
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

void deleteListRelasi(List_relasi &LR,int Par,int Chi) {

    adr_relasi P;

    if (first(LR) != NULL){
        if (info(child(first(LR))).memberID == Chi && info(parent(first(LR))).kodeKaset == Par){
            deleteFirstRelasi(LR,P);
            dealokasiRelasi(P);
            cout << "Selamat anda tidak jadi membeli!" <<endl;
        } else if(info(child(last(LR))).memberID == Chi && info(parent(last(LR))).kodeKaset == Par) {
            deleteLastRelasi(LR,P);
            dealokasiRelasi(P);
            cout << "Selamat anda tidak jadi membeli!" <<endl;
        } else {
            adr_relasi Q = first(LR);
            while (Q != NULL && info(child(Q)).memberID != Chi && info(parent(Q)).kodeKaset != Par) {
                P = Q;
                Q = next(Q);
            }

            deleteAfterRelasi(LR,Q,P);
            dealokasiRelasi(Q);
            cout << "Selamat anda tidak jadi membeli!" <<endl;
        }

    } else {
        cout << "Tidak ada data pembelian" <<endl;
    }
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

void hitungHargaKaset(List_relasi &L,List_child &LC){

    adr_relasi Q = first(L);
    string nama;
    int input;
    int total = 0;

    cout << "Masukan ID Member Anda : ";
    cin >> input;

    if(findElmChild(LC,input)){
        if (cariChildDiRelasi(L,input) != NULL){
            while (Q != NULL){
                if (info(child(Q)).memberID == input ){
                    total = total + info(parent(Q)).harga;
                    nama = info(child(Q)).Nama;
                }
                Q = next(Q);
            }
            cout << "\nJadi total belanjaan kaset dari "<<nama <<" adalah Rp. "<< total <<endl;
        } else {
            cout << "\nAnda belum mengambil satupun kaset" <<endl;
        }
    }else {
        cout << "\nMaaf data member tidak ditemukan" <<endl;
    }
}/// I Wayan Adi Wahyudi (1301194084)

void jenisKasetFavorit(List_relasi &L, adr_relasi P){
    int musik, film;
    musik = 0;
    film = 0;
    P = first(L);
    while (P != NULL){
        if(info(parent(P)).tipe == "Musik"){
            musik = musik + 1;
        } else if(info(parent(P)).tipe == "Film"){
            film = film + 1;
        }
        P = next(P);
    }
    cout << "Kaset film laku sebanyak " <<film << " dan kaset musik laku sebanyak "<< musik <<".";;
    cout << endl;
    cout << "Jadi jenis kaset ter-favorit adalah ";
    if(film > musik){
        cout << "Film dengan jumlah " << film << " kaset." <<endl;
    }else if (film < musik ) {
        cout << "Musik dengan jumlah " << musik << " kaset." <<endl;
    } else {
        cout <<"sama banyak yaitu " << film << " kaset." <<endl;
    }
} ///Muhammad Ikram Kaer Sinapoy(1301193341)

void printChildTOParent(List_relasi &LR,int X){

    adr_relasi P = first(LR);
    adr_relasi Q = cariParentDiRelasi(LR,X);

    if ( Q != NULL) {
        cout << "\nKaset " << info(parent(Q)).judul << " dibeli oleh : \n";
            if (info(parent(P)).kodeKaset == X){
                cout << "- "<< info(child(P)).Nama <<endl;
            }
            P = next(P);
        }else {
       cout << "Kaset belum dibeli oleh siapapun" <<endl;
        }
} /// I Wayan Adi Wahyudi (1301194084)

void Child4EachParent (List_relasi &LR,List_parent &LP){
    adr_parent P;
    adr_relasi R;
    cout << "DAFTAR SEMUA KASET DIBELI OLEH SIAPA SAJA"<<endl;

    P = first(LP);
    int i = 1;
    while (P != NULL){
        cout << i <<".Kaset "<< info(P).judul <<" dibeli oleh : "<<endl;
        R = first(LR);
        int j = 1;
        while (R != NULL){
            if (info(P).kodeKaset == info(parent(R)).kodeKaset) {
                cout <<"\t"<<j<<"."<<info(child(R)).Nama <<endl;
                j++;
            }
            R = next(R);
        }
        cout<<endl;
        i++;
        P = next(P);
    }

}/// I Wayan Adi Wahyudi (1301194084)
