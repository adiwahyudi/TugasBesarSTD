/// Child as Double Circular Linked List and Penyewa

#include "list_child.h"

void createList_Child(List_child &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_child alokasi(infotype_child x) {

    adr_child P = new elmlist_child;
    info(P).NoIdent = x.NoIdent;
    info(P).Nama = x.Nama;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

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
}
void insertLastChild(List_child &L, adr_child P){
    if(first(L) == NULL){
       insertFirst(L,P);
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        next(P) = first(L);
        prev(first(L)) = P;
        last(L) = P;
    }
}

void insertAfterChild(adr_child &Prec, adr_child P) {

    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

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
}

void deleteLastChild(List_child &L, adr_child &P){

    if ( first(L) != last(L) ){
        P = prev(first(L));
        next(prev(P)) = first(L);
        prev(first(L)) = prev(prev(P));
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        deleteFirst(L,P);
    }
}
void deleteAfterChild(List_child &L, adr_child Prec, adr_child &P){

    if ( next(Prec) != first(L) ) {
        P = next(Prec);
        prev(next(P)) = Prec;
        next(Prec) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    } else {
        deleteFirst(L,P);
    }
}

void printChild(List_child L) {
    adr_child P = first(L);

    do {
        cout << info(P).NoIdent << endl;
        cout << info(P).Nama << endl;
        P = next(P);
    } while (P != first(L));
}


adr_child findElm(List_child L, infotype_child x) {
    adr_child P = first(L);

    do{
        if(info(P) == x ) {
            return P;
        }
        P = next(P);
    } while(P != first(L));

    return NULL;
}
