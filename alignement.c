#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "sequence.h"
#include "distance.h"
#include "alignement.h"
#include "famille.h"


void creer_familles(char **argv , FAMILLE *f , SEQUENCE *D)
{
	initialiser_tab_seq(D,argv);
	afficher_tab(D);
	LISTE *l = creer_liste_initiale(D,argv);
	
	int T[10] , numero , taille ;
	float d ;
	int i = 0 ;
	while(!est_vide(l))
	{
		d = recherche_distance_min(l);
		numero  = get_num_freq_max(d,l);
		T[0] = numero  ;
		taille =get_num_autre(T,d,numero,l);
		f[i] = creer_famille_initiale(taille);
		remplir_famille(f[i],T,D);
		ecrire_fich_fam(f[i],T,argv[23+i]);

		for(int j = 0 ; j < taille ; j++)
		{
			supp_numero_seq(l,T[j]);
		}
		ecrire_fichier_liste_fin(l,argv[22]);		
		i++;				
	}
}

void liberer_chaine(CHAINES S)
{
	free(S.a);
	free(S.b);
	free(S.anew);
	free(S.bnew);
	//free(&S);
}

void align (CHAINES *S , int i , int j , float **T) {
                                    //A diagonal arrow represents a match or mismatch, so the letter of the column and the letter 
                                    //of the row of the origin cell will align.
                                    //A horizontal or vertical arrow represents an indel. 
                                    //Horizontal arrows will align a gap ("-") to the letter of the row (the "side" sequence), 
                                    //vertical arrows will align a gap to the letter of the column (the "top" sequence).
                                    //If there are multiple arrows to choose from, they represent a branching of the 


	float enHaut = 1000;
	float aGauche = 1000;
	float diag = 1000;
							
	do {
		//printf("i : %d , j : %d \n",i,j);
		if (i > 0 && j >=0) {
			enHaut = T[i-1][j];
		} else {
			enHaut = 1000;
		}

		if (j > 0&& i >=0) {
			aGauche = T[i][j-1];
		} else {
			aGauche = 1000;
		}
		if (i > 0 && j > 0) {
			diag = T[i-1][j-1];
		} else {
			diag = 1000;
		}
		

		if (enHaut < aGauche && enHaut < diag) {
			S->bnew = prepend(S->bnew, '-'); 
			S->anew = prepend(S->anew, S->a[i]);
			//printf("%f %f %f %c \n", enHaut, aGauche,  diag, '-');

			//printf("%c\n", S->a[i]);
			i--;
		}
		else if (aGauche < diag) {
			S->bnew = prepend(S->bnew, S->b[j]); 
			S->anew = prepend(S->anew, '-');
			//printf("%c\n", '-');
			j--;
		}
		else {
			
			S->bnew = prepend(S->bnew, S->b[j]); 
			S->anew = prepend(S->anew, S->a[i]);
			//printf("%c\n", S->a[i]);
			i--;
			j--;
		}

	}
	while ( i >= 0 && j>=0 );

}



char * prepend(char* s, const char t)
{
	
	if (s == NULL) {
		s = malloc(1);
		s[0] = t;
	} else {
	
		int length = strlen(s);
		for(int i = length+1 ; i > 0 ; i--)
		{
			s[i] = s[i-1];
		}
		s[0] = t ;
	}
	return s;
}

CHAINES initialiser_chaines(char *a , char*b)
{
	CHAINES S ;
	S.a = malloc(strlen(a)+1);
	S.b = malloc(strlen(b)+1);
	strcpy(S.a,a);
	strcpy(S.b,b);
	S.anew = malloc(strlen(a)+20);
	S.bnew = malloc(strlen(b)+20);
	S.anew[0] = '\0';
	S.bnew[0] = '\0';
	
	return S; 
}

float ** init_matrice_dyn(int n)
{
	float **T = malloc(19*sizeof(float*));
	for(int i = 0 ; i < n ; i++ )
	{
		T[i] = malloc(19*sizeof(float));
		for(int j = 0 ; j < n ; j++)
		{
			T[i][j] = -1;
		}

	}
	return T ;
}
ALIGNEMENT creer_alignement ( int nb )
{
	ALIGNEMENT A ;
	A.nb = nb ;
	A.s = NULL ;
	return A ;
}

INDICES align_two(char **Tab_seq , FAMILLE f, int Tab_marqueur[])
{
	float minDist , d ;
	INDICES Indices ;
	minDist = 10000 ;
	float **matrices;
	float **matriceForMin; 
	
	for(int i = 0 ; i < f.n ; i++ )
	{
		for(int j = 0 ; j < f.n ; j++)
		{
			if(i != j )
			{
				matrices = init_matrice_dyn(19);
				d = distance_dyn(f.table[i].s,f.table[j].s,f.table[i].taille-1,f.table[j].taille-1,matrices);
				if(d < minDist)
				{
					minDist = d ;
					Indices.indiceG = i ;
					Indices.indiceD = j ;
					matriceForMin = copyTab(matrices);
				}
				free(matrices);
			}
		}
	}

	init_and_call_align(f.table[Indices.indiceG].s,
		f.table[Indices.indiceD].s,
		f.table[Indices.indiceG].taille-1,
	  	f.table[Indices.indiceD].taille-1 ,
	  	matriceForMin,
		Tab_marqueur,
		Tab_seq,
		Indices.indiceG,
		Indices.indiceD
	);		
	return Indices;								
}

float **copyTab(float ** source)
{
	float **T = malloc(19*sizeof(float*));
	for(int i = 0 ; i < 19 ; i++ )
	{
		T[i] = malloc(19*sizeof(float));
		for(int j = 0 ; j < 19 ; j++)
		{
			T[i][j] = source[i][j];
		}
	}
	return T ;
}

void init_and_call_align (char *chaine1,
 char *chaine2,
 int taille1,
 int taille2, 
 float **matrice,
 int Tab_marqueur [],
 char **Tab_seq,
 int indiceDistg,
 int indiceDistd
 ) {
	CHAINES S = initialiser_chaines(chaine1, chaine2);	
	align(&S,taille1,taille2,matrice);

	if (Tab_marqueur[indiceDistg] == 0){
		Tab_seq[indiceDistg] = malloc(strlen(S.anew));
		for (int i =0 ; i< strlen(S.anew); i++){
			Tab_seq[indiceDistg][i] = S.anew[i];
		}
		Tab_seq[indiceDistg][strlen(S.anew)] = '\0';
		strcpy(Tab_seq[indiceDistg],S.anew);
		
		//Tab_seq[indiceDistg][strlen(S.anew)] = '\0';
	}
		
	if (Tab_marqueur[indiceDistd] == 0){
		Tab_seq[indiceDistd] = malloc(sizeof(strlen(S.bnew))+100);
		//Tab_seq[indiceDistd][0] = '\0';
		strcpy(Tab_seq[indiceDistd],S.bnew);
		//Tab_seq[indiceDistg][strlen(S.bnew)] = '\0';
	}	
	
	Tab_marqueur[indiceDistg] = 1 ;
	Tab_marqueur[indiceDistd] = 1 ;
	liberer_chaine(S);
}


void aligne_famille(char **Tab_seq , FAMILLE f, int Tab_marqueur[])
{
	INDICES Indices = align_two(Tab_seq,f,Tab_marqueur);
	float dist ;
	float dist_min = 10000;
	float ** matriceMin;
	SEQUENCE seqx, seqk ;
	float **matrice;
	int indiceToAlign;
	//pour toutes les sequences qui nont pas encore ete traitees
	for(int k = 0 ; k < f.n ; k++){
		if(Tab_marqueur[k] == 0){
			//je vais les comparer avec celles qui ont ete traitees
			for (int x = 0 ; x < f.n; x++){
				if (Tab_marqueur[x] == 1) {
					matrice= init_matrice_dyn(19);
					seqx = f.table[x];
					seqk = f.table[k];
					dist = distance_dyn(seqx.s,seqk.s,seqx.taille-1,seqk.taille-1,matrice);
					if (dist < dist_min) {
						//si je trouve une distance minimale, jenregistre l'indice
						dist_min = dist;
						indiceToAlign = x;
						matriceMin = copyTab(matrice);
					}
				}
			}
			//a ce niveau, on sait avec quel indice deja traite on doit comparer la nouvelle sequence k
			init_and_call_align(f.table[indiceToAlign].s,
								f.table[k].s,
								f.table[indiceToAlign].taille-1,
	  							f.table[k].taille-1 ,
	  							matriceMin,
								Tab_marqueur,
								Tab_seq,
								indiceToAlign,
								k
							);	
		}
		dist_min = 10000;

	}
}

char freq_majoritaire(int Freq[], int nb_seq)
{
	for(int l = 0 ; l < 5 ; l++)
	{
		if( ((nb_seq/2 == 0) && Freq[l] > nb_seq/2) || (((nb_seq/2) != 0)  && Freq[l] >= nb_seq/2))
		{
			if(l == 0)
				return 'A';
			else if(l == 1)
				return 'C';
			else if(l == 2)
				return 'G';
			else if(l == 3)
				return 'T';
			else 
				return '-';
		}
	}
	return '.' ;
}


char * creer_seq_consensus (char **Tab_seq , int nb_seq)
{	
	int taillemax = 0 ;
	for(int i = 0 ; i < nb_seq ; i++)
	{
		if(taillemax < strlen(Tab_seq[i]))
		{
			taillemax = strlen(Tab_seq[i]) ;
		}
	}
	char * consensus = malloc(taillemax);
	int Freq[5];
	for(int k = 0 ; k < 5 ; k++)
	{
		Freq[k] = 0 ;
	}

	for(int letter = 0 ; letter < taillemax; letter++)
	{
		for(int seqNum = 0 ; seqNum < nb_seq ; seqNum++)
		{
			if (strlen(Tab_seq[seqNum]) > letter) {
				char seq_letter = Tab_seq[seqNum][letter];
				if(seq_letter == 'A')
					Freq[0]++;

				else if(seq_letter == 'C')
					Freq[1]++;

				else if(seq_letter == 'G')
					Freq[2]++;

				else if(seq_letter == 'T')
					Freq[3]++;

				else 
					Freq[4]++;
			}
			else 
				Freq[4]++;								
		}
		//printf("%c new char", freq_majoritaire(Freq, nb_seq));
		consensus[letter]= freq_majoritaire(Freq, nb_seq);
		//init Freq for next call
		for(int k = 0 ; k < 5 ; k++)
		{
			Freq[k] = 0 ;
		}
	}
	consensus[taillemax] = '\0';
	return consensus;
}
