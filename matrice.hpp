/**
 * @file matrice.hpp
 * @author Katel Hignard (katel.hgd@gmail.com)
 * @brief Définitions des fonctions sur les matrices
 * @date 2023-03-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

struct Matrice {
    int n, m;
    float** matrice;
};

void    alloc_matrice(Matrice *A, int n, int m);
void    desalloc_matrice(Matrice *A);
void    aff_matrice(Matrice *A);
bool    produit_matriciel_naif(Matrice *A, Matrice *B, Matrice *Res);