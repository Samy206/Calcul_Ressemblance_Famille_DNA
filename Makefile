run2 : partie2 
	./partie2 sequences/seq01.txt sequences/seq02.txt  sequences/seq03.txt sequences/seq04.txt sequences/seq05.txt sequences/seq06.txt sequences/seq07.txt sequences/seq08.txt sequences/seq09.txt sequences/seq10.txt sequences/seq11.txt sequences/seq12.txt sequences/seq13.txt sequences/seq14.txt sequences/seq15.txt sequences/seq16.txt sequences/seq17.txt sequences/seq18.txt  sequences/seq19.txt  sequences/seq20.txt distance_sequences_a_modif Familles 
	

partie2 :main2.o sequence.o distance.o famille.o
	gcc -Wall -Wextra main2.o sequence.o distance.o famille.o -o partie2 -g

main2.o : main2.c
	gcc -Wall -c main2.c -g

famille.o : famille.c
	gcc -Wall -c famille.c -g

sequence.o : sequence.c
	gcc -Wall -c sequence.c -g
	
distance.o : distance.c
	gcc -Wall -c distance.c -g

clean : 
	rm -f *.o
	rm partie2
	ls 
	
