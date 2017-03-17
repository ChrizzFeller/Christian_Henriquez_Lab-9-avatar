Main: Main.o Bender.o airbenders.o earthbenders.o firebenders.o waterbenders.o
	g++ Main.o Bender.o airbenders.o earthbenders.o firebenders.o waterbenders.o -o Main

Main.o: Main.cpp Bender.h airbenders.h earthbenders.h firebenders.h waterbenders.h
	g++ -c Main.cpp

Bender.o: Bender.cpp Bender.h
	g++ -c Bender.cpp

airbenders.o: airbenders.cpp airbenders.h Bender.h
	g++ -c airbenders.cpp

earthbenders.o: earthbenders.cpp earthbenders.h Bender.h
	g++ -c earthbenders.cpp

firebenders.o: firebenders.cpp firebenders.h Bender.h
	g++ -c firebenders.cpp

waterbenders.o: waterbenders.cpp waterbenders.h Bender.h
	g++ -c waterbenders.cpp

clean:
	rm -f *.o Main