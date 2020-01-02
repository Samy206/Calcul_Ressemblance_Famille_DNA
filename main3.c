									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "alignement.h"
									#include "famille.h"
									
									int main(int argc , char ** argv )
									{
										FAMILLE f[6];
										SEQUENCE D[21];
										
										creer_familles(argv,f,D);
										for(int i = 0 ; i < 6 ; i++)
										{
											int Tab_marqueur[f[i].n];
											for(int j = 0 ; j < f[i].n ; j++)
											{
													Tab_marqueur[j] = 0 ;
											}
											char ** Sek = malloc(f[i].n*sizeof(char*));
											aligne_famille(Sek,f[i],Tab_marqueur);	

											/*for (int u= 0; u<f[i].n ; u++){
												printf("Sek %s\n", Sek[u]);
											}*/
											
											char *con = creer_seq_consensus (Sek , f[i].n);
											char * fileName = familleFileName(i);
											ecrire_seq_consensus_fichier(con, fileName);
											free(Sek);
											free(con);
										}


										exit(0);
									}


