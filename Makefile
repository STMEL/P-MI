Projet.exe : fonctionsK.o fonctionscalcul.o test.o main.o
	g++ fonctionsK.o fonctionscalcul.o test.o main.o -o Projet.exe

fonctionsK.o: fonctionsK.c fonctionsK.h
	g++ -Wall -c fonctionsK.c

fonctionscalcul.o: fonctionscalcul.c fonctionscalcul.h fonctionsK.c fonctionsK.h
	g++ -Wall -c fonctionscalcul.c

test.o: test.c test.h fonctionscalcul.c fonctionscalcul.h fonctionsK.c fonctionsK.h
	g++ -Wall -c test.c

main.o: main.c fonctionscalcul.c fonctionscalcul.h fonctionsK.c fonctionsK.h test.c test.h
	g++ -Wall -c main.c

clean:
	rm *.o *.png *.txt Projet.exe

cleangraphe:
	rm *.png

cleantxt:
	rm *.txt