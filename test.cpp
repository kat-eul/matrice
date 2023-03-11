/**
 * @file test.cpp
 * @author Katel Hignard (katel.hgd@gmail.com)
 * @brief Fonctions permettant la vérification des fonctions sur les matrices
 * @date 2023-03-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include "matrice.hpp"

using namespace std;

void test_fonctions_initiales(){
    cout << "Matrice Mat - 5x2 ---------------------------" << endl;
    Matrice *mat = new Matrice;
    alloc_matrice(mat, 5, 5);
    aff_matrice(mat);
    desalloc_matrice(mat);
}

void test_produit_matriciel_naif(){
    cout << "Produit Matriciel ---------------------------" << endl;
    Matrice *A = new Matrice, *B= new Matrice, *C = new Matrice;
    alloc_matrice(A,2,1);
    alloc_matrice(B,1,5);

    A->matrice[0][0] = 1; 
    A->matrice[1][0] = 2;
    B->matrice[0][0] = 1; B->matrice[0][1] = 2; B->matrice[0][2] = 3; B->matrice[0][3] = 4; B->matrice[0][4] = 5;

    if(produit_matriciel_naif(A,B,C)){
        aff_matrice(C);
    }
}

void test_resolution_systeme_triangulaire_inferieur(){
    cout << "Resolution systeme triangulaire inferieur ---" << endl;
    Matrice *L = new Matrice, *b = new Matrice, *x = new Matrice;
    alloc_matrice(L, 3 ,3);
    alloc_matrice(b, 3, 1);

    L->matrice[0][0] = 1; L->matrice[0][1] = 0; L->matrice[0][2] = 0;
    L->matrice[1][0] = 2; L->matrice[1][1] = 1; L->matrice[1][2] = 0;
    L->matrice[2][0] = 3; L->matrice[2][1] = 1; L->matrice[2][2] = 1;
    b->matrice[0][0] = 1; b->matrice[1][0] = 2; b->matrice[2][0] = 4;

    if(resolution_systeme_triangulaire_inferieur(L, b, x)){
        aff_matrice(x);
    }
}

void test_resolution_systeme_triangulaire_superieur(){
    cout << "Resolution systeme triangulaire superieur ---" << endl;
    Matrice *L = new Matrice, *b = new Matrice, *x = new Matrice;
    alloc_matrice(L, 3 ,3);
    alloc_matrice(b, 3, 1);

    L->matrice[0][0] = 1; L->matrice[0][1] = 2; L->matrice[0][2] = 3;
    L->matrice[1][0] = 0; L->matrice[1][1] = 1; L->matrice[1][2] = 1;
    L->matrice[2][0] = 0; L->matrice[2][1] = 0; L->matrice[2][2] = 1;
    b->matrice[0][0] = 1; b->matrice[1][0] = 2; b->matrice[2][0] = 4;

    if(resolution_systeme_triangulaire_superieur(L, b, x)){
        aff_matrice(x);
    }
}

void test_cholesky(){
    cout << "Cholesky ------------------------------------" << endl;
    Matrice *A = new Matrice;
    alloc_matrice(A, 4, 4);

    A->matrice[0][0] = 1; A->matrice[0][1] = 1; A->matrice[0][2] = 1; A->matrice[0][3] = 1; 
    A->matrice[1][0] = 1; A->matrice[1][1] = 5; A->matrice[1][2] = 5; A->matrice[1][3] = 5; 
    A->matrice[2][0] = 1; A->matrice[2][1] = 5; A->matrice[2][2] = 14; A->matrice[2][3] = 14; 
    A->matrice[3][0] = 1; A->matrice[3][1] = 5; A->matrice[3][2] = 14; A->matrice[3][3] =15 ; 

    cholesky(A);
    aff_matrice(A);
}

int main(){
    //test_fonctions_initiales();
    //test_produit_matriciel_naif();
    //test_resolution_systeme_triangulaire_inferieur();
    //test_resolution_systeme_triangulaire_superieur();
    //test_cholesky();
}