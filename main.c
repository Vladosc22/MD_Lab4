#include <stdio.h>
#include <stdlib.h>

                                //nodul de start pt parcurgere
    void pl(int** graf, int noduri, int radacina) {
        int *stiva = (int*)malloc(noduri * sizeof(*stiva));
        int top_s = 0;//initializare cu 0 varful (goala)
        int vizitat[100] = {0};//nodurile ca vizitat

        vizitat[radacina] = 1;  //marcam nodul de start(radacina)
        stiva[top_s++] = radacina; //punem r in s

        printf("Arborele de acoperire (muchii):\n");

        while (top_s > 0) {
            int varf = stiva[--top_s]; // Extragem nodul din vârful

            for (int j = noduri - 1; j >= 0; j--) { // Parcurgem vecinii
                if (graf[varf][j] == 1 && !vizitat[j]) { //exista muchie,nod, vecin nu a fost vizitat
                    stiva[top_s++] = j; // se introduce fiul in stiva
                    vizitat[j] = 1;//marca

                    // Afisam muchia care face parte din arbore
                    printf("(%d, %d)\n", varf + 1, j + 1); // (varful , fiul )
                }
            }
        }

        // Verificam daca au fost vizitate toate nodurile
        int complet = 1; //presupunem nodurile
        for (int i = 0; i < noduri; i++) { //parcurgem
            if (vizitat[i] == 0) {//nevizitat
                complet = 0; //marcam parcurgere
                break;
            }
        }

        if (!complet) {
            printf("Nu au fost parcurse toate nodurile. Introduceti alta radacina: ");
            scanf("%d", &radacina);
            radacina--; // Indexare de la 0
            pl(graf, noduri, radacina); // Recursiv, cu noua rădăcină
        }

        free(stiva);
    }


int main() {
    int noduri = 5;

    // Alocam memorie pentru matricea de adiacenta
    int** graf = (int**)malloc(noduri * sizeof(int*));
    for (int i = 0; i < noduri; i++) { //// Pentru fiecare linie
        graf[i] = (int*)calloc(noduri, sizeof(int)); // Initializam cu zerouri
    }
//parcurgerea matricei
    for (int i = 0 ; i < noduri; i++) { //linia
        for (int j = 0 ; j < noduri; j++) { //coloane
            scanf("%d", &graf[i][j]);
        }
    }
    printf("Introdu radacina");
    int radacina ;
    scanf("%d", &radacina);
    printf("Rezultate obtinute:\n");
    printf("Adancime: ");
    pl(graf, noduri, radacina-1);

    for (int i = 0; i < noduri; i++) { // Parcurgem fiecare linie din matrice
        free(graf[i]);
    }
    free(graf);

    return 0;
}

//subgraf aciclic al grafulu g format din componente conexe care formeaaza (secheletul grafului g)
//