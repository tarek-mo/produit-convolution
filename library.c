#include <stdio.h>
#include <time.h>
#include <stdlib.h>



int** get_random_matrice(int size) {
    int** matrice = (int**)calloc(size,sizeof(int *));
    
    if (matrice == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return NULL; // Return an error status to the operating system
    }

    for (int i = 0; i < size; i++) {
        matrice[i] = (int *)calloc(size,sizeof(int));

        if (matrice[i] == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            return NULL; // Return an error status to the operating system
        }
        for (int j = 0; j < size; j++)
        {
            if(i==0|| i==size-1 || j==0 || j==size-1) {
                continue;
            } else {
                matrice[i][j] = rand() % 10;
            }
        }
        
    }

    return matrice;
}

int** creer_resultat_matrice(int** matrice_A, int** matrice_B, int size_A, int size_B) {
    int** resultat_matrice = (int**)calloc(size_A, sizeof(int *));
    
    if (resultat_matrice == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return NULL; // Return an error status to the operating system
    }

    for (int i = 0; i < size_A; i++) {
        resultat_matrice[i] = (int *)calloc(size_A, sizeof(int));

        if (resultat_matrice[i] == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            return NULL; // Return an error status to the operating system
        }
        
        for (int j = 0; j < size_A; j++)
        {
            
            if(i == 0 || j == 0 || i == size_A -1 || j == size_A -1) {
                continue;
            } else {
                int output = 0;
                for (int k = 0; k < size_B; k++)
                {
                    for (int l = 0; l < size_B; l++)
                    {
                        
                        output += matrice_A[i-1+k][j-1+l] * matrice_B[k][l];
                    }
                }
                resultat_matrice[i][j] = output;
            }
            
            
        }
        
    }

    return resultat_matrice;

}


int trace_matrice(int** matrice, int size) {
    int trace=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(i == j) {
                trace += matrice[i][j];
            }
        }
        
    }

    return trace;
    
}

void free_matrice(int** matrice, int size) {
    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(matrice[i]);
    }
    free(matrice);
}

void print_matrice(int** matrice, int size) {
    printf("----------- MATRICE %dx%d------------- \n", size, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");  
    }
    printf("----------------------------\n");
    
}
int get_convolution_size(int size_A) {
    int size_B = 0;
    while (size_B%2 == 0 || 1 > size_B || (float)size_B > (float)size_A/3)
    {
        printf("Entrer la taille 2p+1 (impaire) du matrice de convolution (doit etre 1<2p+1<N/3): ");
        scanf("%d", &size_B); 
    }
    return size_B;
}

int** create_convolution(int size_B) {
    
    int** matrice_B = (int**)malloc(size_B * sizeof(int*));
    for (int i = 0; i < size_B; i++)
    {
        matrice_B[i] = (int*)malloc(size_B * sizeof(int));
        for (int j = 0; j < size_B; j++)
        {
            printf("Entrer B[%d][%d]: ", i,j);
            scanf("%d", &matrice_B[i][j]);
        }
        
    }
    return matrice_B;
}