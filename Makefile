Reservation: Reservation.o Flight.o ReservationSystem.o main.o
	g++ Reservation.o Flight.o ReservationSystem.o main.o -o Reservation
Reservation.o: Reservation.cpp
	g++ -c Reservation.cpp
Flight.o: Flight.cpp
	g++ -c Flight.cpp
ReservationSystem.o: ReservationSystem.cpp
	g++ -c ReservationSystem.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o Reservation