
int** get_random_matrice(int size);
int** creer_resultat_matrice(int** matrice_A, int** matrice_B, int size_A, int size_B);
int trace_matrice(int** matrice, int size);
void free_matrice(int** matrice, int size);
void print_matrice(int** matrice, int size);
int get_convolution_size(int size_A);
int** create_convolution(int size_B);