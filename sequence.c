									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"



									int get_taille_seq(char *argv)
									{
										int t = 0 ;
										FILE *F ;
										F = fopen(argv,"r");										//On ouvre le ficher nommé argv
										if(F == NULL)
										{
											printf("Problème d'ouverture fichier %s\n",argv);
											exit(1);
										}
										while(fgetc(F) != EOF)
										{
											t++;                              //On compte le nombre de caractères
										}
										rewind(F);							//On remet le curseur au début
										fclose(F);							//On ferme le fichier
										return t ;
									}

									char * lire_fichier(char *argv)
									{
										FILE *F ;
										F = fopen(argv,"r");
										if(F == NULL)
										{
											printf("Problème d'ouverture fichier %s\n",argv);
											exit(1);
										}
										int t = get_taille_seq(argv);
										char *s ;
										s = malloc(t);
										fscanf(F,"%s",s); 			 //enregistrement de la séquence dans s
										fclose(F);
										return s;
									}

									SEQUENCE initialiser_sequence ( char * argv1)
									{
										SEQUENCE A ;
										A.taille = get_taille_seq(argv1) ;		//On définit la taille de la séquence
										A.s = lire_fichier(argv1);				//On copie la chaîne de caractères dans la séquence
										return A ;
									}


									void initialiser_tab_seq (SEQUENCE D[] , char ** argv)
									{

										for(int i = 1 ; i <21 ; i++)
										{
											D[i] = initialiser_sequence(argv[i]);    //On stocke les 20 séquences dans un tableau
										}
									}


									float distance_sequence_sans_insertions( SEQUENCE A, SEQUENCE B)
									{
										float distance = 0.0 ;
										int i = 0 ;

										if(A.taille > B.taille)  //la première séquence est plus longue que la deuxième
										{
											int difference ;
											difference = A.taille - B.taille ;

											 while( i < (B.taille) )
											 {
													//Comparaison caractères par caractères dans la séquence la plus courte

													 if(A.s[i] != B.s[i] )
													 {
														 //si les caractères sont les mêmes on ne fait rien

														 if(A.s[i] == 'A')
														 {
															 if(B.s[i] == 'C')
																distance = distance + 2.0 ;
															 else if(B.s[i] == 'G')
																distance = distance + 1.0 ;
															 else if(B.s[i] == 'T')
																distance = distance + 2.0 ;
															 else if(B.s[i] == '-')
																distance = distance + 1.5 ;
														 }

														 else if(A.s[i] == 'C')
														 {
															 if(B.s[i] == 'A')
																distance = distance + 2.0 ;
															 else if(B.s[i] == 'G')
																distance = distance + 2.0 ;
															 else if(B.s[i] == 'T')
																distance = distance + 1.0 ;
															 else if(B.s[i] == '-')
																distance = distance + 1.5 ;
														 }

														else  if(A.s[i] == 'G')
														 {
															 if(B.s[i] == 'C')
																distance = distance + 2.0 ;
															 else if(B.s[i] == 'A')
																distance = distance + 1.0 ;
															 else if(B.s[i] == 'T')
																distance = distance + 2.0 ;
															 else if(B.s[i] == '-')
																distance = distance + 1.5 ;
														}

														else if(A.s[i] == 'T')
														{
														   if(B.s[i] == 'C')
																distance = distance + 1.0 ;
														   else if(B.s[i] == 'G')
																distance = distance + 2.0 ;
														   else if(B.s[i] == 'A')
																distance = distance + 2.0 ;
														   else if(B.s[i] == '-')
																distance = distance + 1.5 ;
														}

														else if(A.s[i] == '-')
														{
														   if(B.s[i] == 'C')
																distance = distance + 1.5 ;
														   else if(B.s[i] == 'G')
																distance = distance + 1.5 ;
														   else if(B.s[i] == 'A')
																distance = distance + 1.5 ;
														   else if(B.s[i] == 'T')
															   distance = distance + 1.5 ;
														}
														i++ ;
													}
													else
														i++;
												}
												 i =0 ;

												 // partie où il n'y a plus de carac dans B.s :

												 while(i < difference )
												 {
													 distance = distance + 1.5 ;
													 i++;
												 }
										}

										 if(A.taille < B.taille)  //la première séquence est plus courte que la deuxième
										{
											int difference1 ;
											difference1 = B.taille - A.taille ;
											while( i < (A.taille) )
											{

												//si les caractères sont les mêmes on ne fait rien


											    if(B.s[i] != A.s[i] )
												{

													if(B.s[i] == 'A')
												    {
														if(A.s[i] == 'C')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'G')
															distance = distance + 1.0 ;
														else if(A.s[i] == 'T')
															distance = distance + 2.0 ;
														else if(A.s[i] == '-')
															distance = distance + 1.5 ;
													}											// on compare les caractères uns à uns en modifiant la distance selon le tableau des distances

													else if(B.s[i] == 'C')
													{
														if(A.s[i] == 'A')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'G')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'T')
															distance = distance + 1.0 ;
														else if(A.s[i] == '-')
															distance = distance + 1.5 ;
													 }

													 else if(B.s[i] == 'G')
													 {
														if(A.s[i] == 'C')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'A')
															distance = distance + 1.0 ;
														else if(A.s[i] == 'T')
															distance = distance + 2.0 ;		// on compare les caractères uns à uns en modifiant la distance selon le tableau des distances
														else if(A.s[i] == '-')
															distance = distance + 1.5 ;
													}

													else if(B.s[i] == 'T')
													{
														if(A.s[i] == 'C')
															distance = distance + 1.0 ;
														else if(A.s[i] == 'G')
															distance = distance + 2.0 ;
														else if(A.s[i] == 'A')
															distance = distance + 2.0 ;
														else if(A.s[i] == '-')
															distance = distance + 1.5 ;
													 }

													 else if(B.s[i] == '-')
													{
														 if(A.s[i] == 'C')
															distance = distance + 1.5 ;
													    else if(A.s[i] == 'G')					// on compare les caractères uns à uns en modifiant la distance selon le tableau des distances
															distance = distance + 1.5 ;
														 else if(A.s[i] == 'A')
															distance = distance + 1.5 ;
														 else if(A.s[i] == 'T')
														   distance = distance + 1.5 ;
													}
													i++;
												}
												else
													i++;
											}
												 i = 0 ;

												  // partie où il n'y a plus de carac dans A.s :

												 while(i < difference1 )
												 {
													 distance = distance + 1.5 ;
													 i++;
												 }

										 }

										if(A.taille == B.taille)  //la première séquence a la même taille que la deuxième
										{
											 while( i < (B.taille))
											{
												if(A.s[i] != B.s[i] )
												{
													if(A.s[i] == 'A')
													{
														 if(B.s[i] == 'C')
															distance = distance + 2.0 ;
														 else if(B.s[i] == 'G')
															distance = distance + 1.0 ;
														 else if(B.s[i] == 'T')                // on compare les caractères uns à uns en modifiant la distance selon le tableau des distances
															distance = distance + 2.0 ;
														 else if(B.s[i] == '-')
															distance = distance + 1.5 ;
													 }

													 else if(A.s[i] == 'C')
													 {
														 if(B.s[i] == 'A')
															distance = distance + 2.0 ;
														 else if(B.s[i] == 'G')
															distance = distance + 2.0 ;
														 else if(B.s[i] == 'T')
															distance = distance + 1.0 ;
														 else if(B.s[i] == '-')
															distance = distance + 1.5 ;
													 }


													 else if(A.s[i] == 'G')
													 {
														 if(B.s[i] == 'C')
															distance = distance + 2.0 ;
														 else if(B.s[i] == 'A')
															distance = distance + 1.0 ;
														 else if(B.s[i] == 'T')
															distance = distance + 2.0 ;
														else if(B.s[i] == '-')
															distance = distance + 1.5 ;
													 }

													else if(A.s[i] == 'T')
													 {
														 if(B.s[i] == 'C')
															distance = distance + 1.0 ;
														 else if(B.s[i] == 'G')
															distance = distance + 2.0 ;
														 else if(B.s[i] == 'A')
															distance = distance + 2.0 ;
														 else if(B.s[i] == '-')
															distance = distance + 1.5 ;
													 }

													 else if(A.s[i] == '-')
													 {
														if(B.s[i] == 'C')
															distance = distance + 1.5 ;
														 else if(B.s[i] == 'G')
															distance = distance + 1.5 ;
														 else if(B.s[i] == 'A')
															distance = distance + 1.5 ;
														 else if(B.s[i] == 'T')
															distance = distance + 1.5 ;
													}
													i++ ;
												}

												else
													i++;
											}
											// pas de partie où il n'y a pas de caractères en face de '-'
										}



										return distance ;
									}

									void afficher_tab(SEQUENCE D[])
									{
										for ( int i = 1 ; i < 21 ; i++)
										{
											printf("D[%2d] : %s , taille : %d\n",i,D[i].s,D[i].taille);  //on parcourt le tableau de séquences et on affiche la chaîne de carac. et la taille de chacune d'elles
										}
										printf("\n");

									}

									void liberer_seq(SEQUENCE * A)
									{
										if(A != NULL) {
											if(A->s != NULL){
												free(A->s);
											}
											free(A);
										}

									}

									void ajouter_seq_fichier(char * s , char * v  , int indiceg , int indiced , char * argv , float val)
									{
										FILE *F = fopen(argv,"a");
										if(F == NULL)
										{																// on écrit dans le nom de fichier passé en argument
											printf("problème d'ouverture de fichier ecriture\n");
											exit(3);
										}

										fprintf(F,"La distance entre la sequence %d (%s) et %d (%s) est : %f \n ",indiceg,s,indiced,v,val);

										fclose(F);
									}

									float compare_carac ( char a , char b)
									{
										if ( a == b)
										{
											return 0.0 ;
										}
										else
										{
											if( a == 'A')
											{
												if(b == 'T')
													return 2.0 ;
												else if( b == 'C')
													return 2.0 ;
												else if ( b == 'G')
													return 1.0 ;
												else
													return 1.5 ;
											}


											else if( a == 'T')
											{
												if(b == 'A')
													return 2.0 ;
												else if( b == 'C')
													return 1.0 ;
												else if ( b == 'G')
													return 2.0 ;
												else
													return 1.5 ;
											}


											else if( a == 'G')
											{
												if(b == 'A')
													return 1.0 ;
												else if( b == 'C')
													return 2.0 ;
												else if ( b == 'T')
													return 2.0 ;
												else
													return 1.5 ;
											}

											else if( a == 'C')
											{
												if(b == 'A')
													return 2.0 ;
												else if( b == 'G')
													return 2.0 ;
												else if ( b == 'T')
													return 1.0 ;
												else
													return 1.5 ;
											}

											else
												return 1.5 ;
										}
									}

									float min ( float a , float b)
									{
										if ( a < b )
											return a ;

										else
											return b ;


									}


									void remplir_tab(SEQUENCE ***tab ,int ligne , int colonne)
									{
										for(int i = 0 ; i < ligne ; i++)
										{
											for(int j = 0 ; j < colonne ; j++)
											{
												tab[i][j] = NULL;
											}
										}
									}


void append(SEQUENCE *d, SEQUENCE *m, char ac, char bc){
	int length;
	printf("\t\t d a:'%s' b:'%s' ac:'%c' bc:'%c'\n", d->a,d->b, ac, bc );
	if(d->a != NULL){
		length = strlen(d->a);
		m->a = malloc((length + 1) * sizeof(char));
		for(int k = 0; k < length; k++){
			m->a[k] = d->a[k];
		}
	} else {
		m->a = malloc(1);
		length = 0;
	}
	m->a[length] = ac;

	if(d->b != NULL){
		length = strlen(d->b);
		m->b = malloc((length + 1) * sizeof(char));
		for(int k = 0; k < length; k++){
			m->b[k] = d->b[k];
		}
	} else {
		m->b = malloc(1);
		length = 0;
	}
	m->b[length] = bc;

	printf("\t\t m a:'%s' b:'%s' ac:'%c' bc:'%c'\n", m->a,m->b, ac, bc );
}
									SEQUENCE* distance_dyn (char *a , char *b , int i , int j , SEQUENCE ***sequences)
									{


										SEQUENCE *d1,*d2,*d3,*m;
										float d1V, d2V, d3V;
										int length;
											if(i == 0 && j > 0)
											{

												m=malloc(sizeof(SEQUENCE));
												m->distance = 1.5 * j;
												m->b = malloc(j + 1);
												for(int k = 0; k < j + 1; k++){
													m->b[k] = b[k];
												}

												m->a = malloc(1);
												m->a[0] = a[0];


												return m;
											}

											else if ( j == 0 && i > 0)
											{


												m=malloc(sizeof(SEQUENCE));
												m->distance = 1.5 * i;


												m->a = malloc(i + 1);
												for(int k = 0; k < i + 1; k++){
													m->a[k] = a[k];
												}
												m->b = malloc(1);
												m->b[0] = b[0];


												return m;
											}

											else if ( i == 0 && j == 0)
											{

												m=malloc(sizeof(SEQUENCE));
												m->a = malloc(sizeof(char));
												m->a[0] = a[i];
												m->b = malloc(sizeof(char));
												m->b[0] = b[j];
												m->distance = compare_carac(a[i],b[j]);


												return m;
											}

											else if ( sequences[i][j] != NULL )
											{

												return sequences[i][j];
											}

											else
											{
												printf("a:'%s' b:'%s'\n", a, b);
												d1 = distance_dyn(a,b,i-1,j-1,sequences);
												d1V = d1->distance + compare_carac(a[i],b[j]);

												d2 = distance_dyn(a,b,i,j-1,sequences);
												d2V = d2->distance + compare_carac('-',b[j]);

												d3 = distance_dyn(a,b,i-1,j,sequences);
												d3V = d3->distance + compare_carac(a[i],'-');

												m=malloc(sizeof(SEQUENCE));

												if(d1V < d2V && d1V < d3V){
													printf("\td1\n");
													append(d1, m, a[i], b[j]);
													m->distance = d1V;
												} else if(d2V < d3V){
													printf("\td2\n");
													append(d2, m,'-', b[j]);
													m->distance = d2V;
												} else {
													printf("\td3\n");
													append(d3, m, a[i], '-');
													m->distance = d3V;
												}
												sequences[i][j] = m;
												printf("m a:'%s' b:'%s'\n", m->a, m->b);
											}

											return sequences[i][j];
									}


