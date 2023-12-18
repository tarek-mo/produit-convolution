#include <stdio.h>
#include "library.h"


int main() {

    // Recuperation du taille du matrice A
    int size_A;
    printf("Entrer la taille n du matrice: ");
    scanf("%d", &size_A);

    // Creation d'une matrice size_A*size_A aleatoire
    int** matrice_A = get_random_matrice(size_A);
    print_matrice(matrice_A, size_A);

    // Trace du matrice A
    int trace = trace_matrice(matrice_A, size_A);
    printf("la trace de cette matrice est egale a %d \n", trace);

    // Remplissage du taille de matrice de convolution B par l'utilisateur
    int size_B = get_convolution_size(size_A);

    // Creation du matrice de convolution B par l'utilisateur avec taille (2p+1)*(2p+1)
    int** matrice_B = create_convolution(size_B);
    print_matrice(matrice_B, size_B);

    int** resultat_matrice = creer_resultat_matrice(matrice_A, matrice_B, size_A, size_B);
    print_matrice(resultat_matrice, size_A);
    

    // Free matrice A
    free_matrice(matrice_A, size_A);
    

    return 0;
}
