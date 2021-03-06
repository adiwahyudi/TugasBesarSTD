/// Child as Double Circular Linked List and Penyewa

#include "list_child.h"
#include "list_relasi.h"

void createListChild(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
} /// I Wayan Adi Wahyudi (1301194084)

adr_child alokasiChild(infotype_child x) {

    adr_child P = new elmlist_child;
    info(P).NoIdent = x.NoIdent;
    info(P).Nama = x.Nama;
    info(P).memberID = x.memberID;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
} /// I Wayan Adi Wahyudi (1301194084)

void insertFirstChild(List_child &L, adr_child P) {
    if (first(L) != NULL){
        next(P) = first(L);
        prev(P) = prev(first(L));
        next(prev(first(L))) = P;
        prev(first(L)) = P;
        first(L) = P;
    } else {
        first(L) = P;
        next(P) = P;
        prev(P) = P;
        last(L) = P;
    }
} /// I Wayan Adi Wahyudi (1301194084)

void insertLastChild(List_child &L, adr_child P){
    if(first(L) == NULL){
       insertFirstChild(L,P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        next(P) = first(L);
        prev(first(L)) = P;
        last(L) = P;
    }
} /// I Wayan Adi Wahyudi (1301194084)

void insertAfterChild(List_child &L, adr_child &Prec, adr_child P) {
    if (first(L) == NULL)
    {
        insertFirstChild(L, P);
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
} /// I Wayan Adi Wahyudi (1301194084)

void deleteFirstChild(List_child &L, adr_child &P){
    P = first(L);
    if (next(first(L))!= P){
        first(L) = next(P);
        next(prev(P)) = first(L);
        prev(first(L)) = prev(P);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
    }
} /// I Wayan Adi Wahyudi (1301194084)

void deleteLastChild(List_child &L, adr_child &P){

    if ( first(L) != last(L) ){
        P = prev(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(prev(P));
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        deleteFirstChild(L,P);
    }
} /// I Wayan Adi Wahyudi (1301194084)

void deleteAfterChild(List_child &L, adr_child Prec, adr_child &P){

    if ( next(Prec) != first(L) ) {
        P = next(Prec);
        prev(next(P)) = Prec;
        next(Prec) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        deleteFirstChild(L,P);
    }
} /// I Wayan Adi Wahyudi (1301194084)

void insertSortChild(List_child &L, adr_child Q){
    adr_child R;
    adr_child P = first(L);

    if(P == NULL || info(first(L)).memberID >= info(Q).memberID){
        insertFirstChild(L,Q);
    } else if (info(last(L)).memberID <= info(Q).memberID){
        insertLastChild(L,Q);
    } else {
        do {
            R = P;
            P = next(P);
        } while(P != first(L) && info(P).memberID < info(Q).memberID);
        insertAfterChild(L,R,Q);
    }
} /// I Wayan Adi Wahyudi (1301194084)


void deleteListChild(List_child &L, int x){
    adr_child P, Q;
    P = first(L);
    if(info(first(L)).memberID == x){
        deleteFirstChild(L,Q);
        dealokasiChild(Q);
        cout<<"\nData berhasil dihapus" <<endl;
    } else if(info(prev(P)).memberID == x){
        deleteLastChild(L, Q);
        dealokasiChild(Q);
        cout<<"\nData berhasil dihapus" <<endl;
    } else {
        do {
            P = next(P);
        } while (P != first(L) && info(prev(P)).memberID != x);
        deleteAfterChild(L, prev(prev(P)), Q);
        dealokasiChild(Q);
        cout<<"\nData berhasil dihapus" <<endl;
    }
} /// I Wayan Adi Wahyudi (1301194084)

void printChild(List_child L) {
    adr_child P = first(L);
    if (first(L) != NULL ) {
        do {
        cout << "ID Member       : " << info(P).memberID << endl;
        cout << "Nama            : " << info(P).Nama << endl;
        cout << "Nomer Identitas : " << info(P).NoIdent << endl;
        P = next(P);
        cout<<endl;
    } while (P != first(L));
    } else {
        cout << "Tidak ada data member" <<endl;
    }
} /// I Wayan Adi Wahyudi (1301194084)


adr_child findElmChild(List_child L, int x) {
    adr_child P = first(L);
    if (P != NULL){
        do{
            if(info(P).memberID == x ) {
                return P;
            }
            P = next(P);
        } while(P != first(L));
    }
    return NULL;
} /// I Wayan Adi Wahyudi (1301194084)

void dealokasiChild(adr_child &P) {
    delete P;
} /// I Wayan Adi Wahyudi (1301194084)

int randomIDmember(){
    int rndm = 100000 + rand() % 999999;
    return rndm ;
} /// I Wayan Adi Wahyudi (1301194084)

void case1(List_child &L,infotype_child &ITC) {

    cout << "Masukan Nama Anda\t: ";
    cin.get();
    getline(cin, ITC.Nama);
    cout << "Masukan Nomor Identitas\t: ";
    cin >> ITC.NoIdent;

    ITC.memberID = randomIDmember();
    if(findElmChild(L,ITC.memberID) != NULL){
        ITC.memberID = randomIDmember();
    }
    insertSortChild(L,alokasiChild(ITC));

    cout << "\nSelamat data berhasil anda dibuat!" <<endl;
    cout << "ID Member anda : "<<ITC.memberID<<" mohon untuk diingat!"<<endl;
    bersih();

} /// I Wayan Adi Wahyudi (1301194084)
