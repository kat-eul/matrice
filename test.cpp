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

int main(){
    cout << "Matrice Mat - 5x2 ---------------------------" << endl;
    Matrice *mat = new Matrice;
    alloc_matrice(mat, 5, 5);
    aff_matrice(mat);
    desalloc_matrice(mat);
}