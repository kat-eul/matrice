/**
 * @file matrice.cpp
 * @author Katel Hignard (katel.hgd@gmail.com)
 * @brief Implémentation des fonctions sur les matrices
 * @date 2023-03-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "matrice.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Alloue une matrice de dimension n*m et assigne les coefficients à 0
 *  
 * @param n le nombre de lignes
 * @param m le nombre de colonnes
 * @return L'adresse de la matrice allouée
 */
void alloc_matrice(Matrice *A, int n, int m){
    A->n = n;
    A->m = m;
    A->matrice = new float*[A->n];
    for (int i=0; i<n; i++){
        A->matrice[i] = new float[A->m];
        for(int y=0; y<A->m; y++){
                A->matrice[i][y] = 0;
        }
    }
}

/**
 * @brief Désalloue la matrice d'entrée
 * 
 * @param A la matrice a désallouer
 */
void    desalloc_matrice(Matrice *A){
    for (int i=0; i<A->n; i++){
        delete A->matrice[i];
    }
    delete A->matrice;
}

/**
 * @brief Affiche la matrice d'entrée
 * 
 * @param A la matrice a afficher
 */
void    aff_matrice(Matrice *A){

    for(int i=0; i<A->n-1; i++){
        for(int y=0; y<A->m-1; y++){
            cout << A->matrice[i][y] << " | ";
        }
        cout << A->matrice[i][A->m-1] << endl ;
        for(int y=0; y<A->m; y++){
            cout << "---";
        }
        cout << endl;
    }
    for(int y=0; y<A->m-1; y++){
            cout << A->matrice[A->n-1][y] << " | ";
    }
    cout << A->matrice[A->n-1][A->m-1] << endl ;
}

/**
 * @brief Réalise le produit matriciel entre A et B 
 * 
 * @param A une matrice
 * @param B une matrice
 * @param Res le résultat du produit de A et B
 * @return true si les matrices A et B sont compatibles
 * @return false sinon
 */
bool    produit_matriciel_naif(Matrice *A, Matrice *B, Matrice *Res){
    //TODO
}