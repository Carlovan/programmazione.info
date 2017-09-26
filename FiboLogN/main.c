#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Rappresenta una matrice 2x2
struct Matrix2By2 {
	// A  B
	// C  D
	unsigned long long a, b, c, d;
};

// Esegue il prodotto fra matrici 2x2
struct Matrix2By2 dot(struct Matrix2By2 a, struct Matrix2By2 b)
{
	return (struct Matrix2By2){a.a * b.a + a.b * b.c,    a.a * b.b + a.b * b.d,
	                           a.c * b.a + a.d * b.c,    a.c * b.b + a.d * b.d};
}

// Calcola l'n-esima potenza di una matrice 2x2
struct Matrix2By2 mpower(struct Matrix2By2 m, int e)
{
	assert(e >= 0);
	if(e == 0)
		return (struct Matrix2By2){1, 0, 0, 1}; // Se l'esponente e' 0 ritorna la matrice identita'
	if(e == 1)
		return m;                               // Se l'esponente e' 1 ritorna la matrice inalterata
	struct Matrix2By2 t = mpower(m, e/2);
	if(e % 2 == 1)
		return dot(dot(t, t), m);
	else
		return dot(t, t);
}

// Calcola l'n-esimo numero di Fibonacci con complessita logaritmica
long long fibologn(int n)
{
	return mpower(((struct Matrix2By2){1, 1, 1, 0}), n-1).a;
}

int main(int argc, char **argv)
{
	int n;
	printf("Trova l'N-esimo numero di Fibonacci\nInserisci un numero <= 0 per uscire\n\n");
	do {
		printf("N: ");
		scanf("%d", &n);
		if(n > 0)
			printf("> %llu\n", fibologn(n));
	} while(n > 0);
}
