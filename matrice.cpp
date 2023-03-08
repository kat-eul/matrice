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
#include <math.h>
using namespace std;

/**
 * @brief Alloue une matrice de dimension n*m et assigne les coefficients à 0
 *  
 * @param n le nombre de lignes
 * @param m le nombre de colonnes
 * @return A la matrice allouée, et nulle
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
 * @return Res le résultat du produit de A et B
 * @return true si les matrices A et B sont compatibles
 * @return false sinon
 */
bool    produit_matriciel_naif(Matrice *A, Matrice *B, Matrice *Res){
    alloc_matrice(Res, A->n, B->m);
    
    if(A->m == B->n){
        for(int i=0; i<A->n; i++){
            for(int j=0; j<B->m; j++){
                float s = 0;
                for(int k=0; k<A->m; k++){
                    s += A->matrice[i][k]*B->matrice[k][j];
                }
                Res->matrice[i][j] = s;
            }
        }
        return true;
    }else{
        return false;
    }
}

/**
 * @brief Résout le système triangulaire inferieur
 * 
 * @param L une matrice triangulaire inferieur
 * @param b un vecteur
 * @return x le résultat du système
 * @return true si la matrice L et le vecteur b sont compatibles
 * @return false sinon
 */
bool    resolution_systeme_triangulaire_inferieur(Matrice *L, Matrice *b, Matrice *x){
    if(L->n == b->n){
        alloc_matrice(x, L->n, 1);
        for(int i=0; i<L->n; i++){
            float s = b->matrice[i][0];
            for(int j=0; j<i; j++){
                s-=L->matrice[i][j]*x->matrice[j][0];
            }
            x->matrice[i][0] = s/L->matrice[i][i];
        }
        return true;
    }else{
        return false;
    }
}

/**
 * @brief Résout le système triangulaire superieur
 * 
 * @param U une matrice triangulaire superieure
 * @param b un vecteur
 * @return x le résultat du système 
 * @return true si la matrice U et le vecteur b sont compatibles
 * @return false sinon 
 */
bool    resolution_systeme_triangulaire_superieur(Matrice *U, Matrice *b, Matrice *x){
    if(U->n == b->n){
        alloc_matrice(x, U->n, 1);
        for(int i=U->n-1; i>=0; i--){
            float s = b->matrice[i][0];
            for(int j=i+1; j<U->n; j++){
                s-=U->matrice[i][j]*x->matrice[j][0];
            }
            x->matrice[i][0] = s/U->matrice[i][i];
        }
        return true;
    }else{
        return false;
    }
}

/**
 * @brief Décomposition de la matrice A tel que A=B*transposee(B)
 * 
 * @param A une matrice symétrique
 * @return B la matrice triangulaire inferieure étant le resultat de la decomposition
 */
void cholesky(Matrice *A, Matrice *B){
    alloc_matrice(B, A->n, A->m);
    for(int i=0; i<A->n; i++){
        float somme = 0;
        for(int k=0; k<i-1; k++){
            somme += A->matrice[i][k]*A->matrice[i][k];
        }
        B->matrice[i][i] = sqrt(A->matrice[i][i] - somme);
        for(int j= i; j<A->n; j++){
            float somme = 0;
            for(int k=0; k<i-1; k++){
                somme += A->matrice[j][k]*A->matrice[i][k];
            }
            B->matrice[j][i] = (A->matrice[j][i] - somme)/A->matrice[i][i];

        }

    }


}