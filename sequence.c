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

									SEQUENCE* distance_dyn (char *a , char *b , int i , int j ,SEQUENCE *current , SEQUENCE ***sequences)
									{


										SEQUENCE *d1,*d2,*d3,*m;
										float d1V, d2V, d3V;
										int length;

										//printf("a[%d] : %c , b[%d]: %c , distance : %f , T[%d][%d] : %f \n",i,a[i],j,b[j],distance,i,j,T[i][j]);
											if(i == 0 && j > 0)
											{

												m=malloc(sizeof(SEQUENCE));
												m->distance = 1.5 * j;
												m->b = malloc(1);
												m->b[0] = a[i];

												m->a = malloc(j);
												for(int k = 0; k < j; k++){
													m->a[k] = '-';
												}

												return m;
											}

											else if ( j == 0 && i > 0)
											{


												m=malloc(sizeof(SEQUENCE));
												m->distance = 1.5 * i;


												m->a = malloc(1 * sizeof(char));
												m->a[0] = b[j];

												m->b = malloc(i * sizeof(char));
												for(int k = 0; k < i; k++){
													m->b[k] = '-';
												}


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

												d1 = distance_dyn(a,b,i-1,j-1,current,sequences);
												d1V = d1->distance + compare_carac(a[i],b[j]);

												d2 = distance_dyn(a,b,i,j-1,current,sequences);
												d2V = d2->distance + compare_carac('-',b[j]);

												d3 = distance_dyn(a,b,i-1,j,current,sequences);
												d3V = d3->distance + compare_carac(a[i],'-');

												m=malloc(sizeof(SEQUENCE));

												if(d1V < d2V && d1V < d3V){

													m->distance = d1V;
													printf("d1 %s %s\n", d1->a, d1->b);


													if(d1->a != NULL){

														length = strlen(d1->a);

														m->a = malloc((length + 1) * sizeof(char));

														for(int k = 1; k <= length; k++){
															m->a[k] = d1->a[k-1];
														}

													} else {

														m->a = malloc(1);

													}

													m->a[0] = a[i];

													if(d1->b != NULL){
														length = strlen(d1->b) ;
														m->b = malloc((length + 1) * sizeof(char));
														for(int k = 1; k <= length; k++){
															m->b[k] = d1->b[k-1];
														}
													}else {
														m->b = malloc(1);

													}
													m->b[0] = b[j];
													printf("ici d1 %s %s\n", d1->a, d1->b);



												} else if(d2V < d3V){
													printf("d2 %s %s\n", d1->a, d1->b);

												if(d2->a != NULL){

														length = strlen(d2->a) ;

														m->a = malloc((length + 1) * sizeof(char));

														for(int k = 1; k <= length; k++){
															m->a[k] = d2->a[k-1];
														}

													} else {

														m->a = malloc(1);

													}

													m->a[0] = '-';

													if(d2->b != NULL){
														length = strlen(d2->b) ;
														m->b = malloc((length + 1) * sizeof(char));
														for(int k = 1; k <= length; k++){
															m->b[k] = d2->b[k-1];
														}
													}else {
														m->b = malloc(1);

													}
													m->b[0] = b[j];
													m->distance = d2V;
												} else {

												printf("d2 %s %s\n", d3->a, d3->b);
												if(d3->a != NULL){

														printf("IF compare if '%s' \n", d3->a);
														length = strlen(d3->a) ;

														m->a = malloc((length + 1) * sizeof(char));

														for(int k = 1; k <= length; k++){
															m->a[k] = d3->a[k-1];
														}

													} else {

														m->a = malloc(1);

													}

													m->a[0] = a[i];

													if(d3->b != NULL){
														length = strlen(d3->b) ;
														m->b = malloc((length + 1) * sizeof(char));
														for(int k = 1; k <= length; k++){
															m->b[k] = d3->b[k-1];
														}
													}else {
														m->b = malloc(1);

													}
													m->b[0] = '-';
													m->distance = d3V;
												}



												sequences[i][j] = m ;
											}

											return sequences[i][j] ;
									}

