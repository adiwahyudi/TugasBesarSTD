/// Parent as Single Linked List and Kaset

#include "list_parent.h"

void createList(List_parent &L) {
    first(L) = NULL;
    last(L) = NULL;
}

adr_parent alokasi(infotype_parent x) {

    adr_parent P;

    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirstParent(List_parent &L, adr_parent P) {
    adr_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = NULL;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfterParent(adr_parent Prec, adr_parent P){

    next(P) = next(Prec);
    next(Prec) = P;

}
void insertLastParent(List_parent &L, adr_parent P){
    adr_parent Q;
    if(first(L) == NULL){
        insertFirstParent(L,P);
    } else {
       next(last(L)) = P;
       last(L) = P;
       next(P) = NULL;
    }
}

void deleteFirstParent(List_parent &L, adr_parent &P){
    if (first(L) != NULL){
        if (first(L) == last(L)) {
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(first(L));
            next(P) = NULL;
        }
    }
}
void deleteLastParent(List_parent &L, adr_parent &P){ ///masih bingung lupa euy
   if (first(L) != NULL){
        if (first(L) == last(L)){
            deleteFirstParent(L,P);
        } else {
            adr_parent Q = first(L);
            while ( next(Q) != last(L) ) {
                Q = next(Q);
            }
            last(L) = Q;
            next(last(L))= NULL;
        }
   }
}

void deleteAfterParent(List_parent &L, adr_parent Prec, adr_parent &P){
        P = next(Prec);
        next(Prec) = P;
        next(P) = NULL;
}
void printParent(List_parent L) {
   adr_parent P = first(L);

   while ( P != NULL) {
       cout << info(P) << endl;
       P = next(P);
   }
}

adr_parent findElm(List_parent L, infotype_parent x) {
    adr_parent P = first(L);

    while ((P != NULL) && (info(P) != x)){
        P = next(P);
    }
    return P;
}
