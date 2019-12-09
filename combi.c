											#include <stdio.h>
											#include <stdlib.h>
											#include <string.h>
											#include "combi.h"
											#include "sequence.h"
											#include "distance.h"
										
											
											
											
											COMB put_dash( char * seq )
											{
												int taille ;
												char **tab_seq ;
												int j = 1 ;
												taille = strlen(seq);
												int taillemax = taille+1 ;
												char *c = malloc(taillemax+1);
												c[taillemax-1] = '-';
												copie_string(c,seq,taille);
												c[taillemax] = '\0' ;
												c[taillemax-1] = '-' ;
												tab_seq = malloc(taillemax*taillemax);
												tab_seq[0] = malloc(taillemax);
												strcpy(tab_seq[0],c);
												
											
												for(int i = taille ; i > 0 ; i--)
												{
													tab_seq[j] = malloc(taillemax);
													if(c[i-1] != '-')
													{
														c[i] = c[i-1] ;
														c[i-1] = '-' ;
														strcpy(tab_seq[j],c);
														j++;
													}
												}
												COMB cons ;
												cons.tab = tab_seq ;
												cons.taille = j ;
												return cons ;
											}
											
											
											COMB append ( COMB result , COMB x)
											{
												COMB c ;
												c.taille = result.taille + x.taille ;
												c.tab = malloc(c.taille * sizeof(char *));
												
												for(int i = 0 ; i < result.taille ;i++)
												{
													c.tab[i] = result.tab[i] ;
												}
												for(int j = result.taille ; j < c.taille ; j++)
												{
													c.tab[j] = x.tab[j-result.taille];
												}
												
												return c ;
											}
											
										    
										    
										    COMB put_double_dash( char *seq )
											{					
												COMB c = put_dash(seq);
												COMB result , x ;
												result.taille = 0 ;
												for(int i = 0  ; i < c.taille ; i++)
												{	
													x = put_dash(c.tab[i]);
													result = append(result,x);
												}
												return result ;
											}
												
																							
										
