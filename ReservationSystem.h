//
// Created by sinap on 2.11.2020.
//

#ifndef PROJECT1_RESERVATIONSYSTEM_H
#define PROJECT1_RESERVATIONSYSTEM_H

#include "Flight.h"

class ReservationSystem {
public:
    ReservationSystem();

    ~ReservationSystem();


    void addFlight( const int flightNo, const int rowNo, const int seatNo );
    void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );
    int makeReservation( const int flightNo, const int numPassengers,
                         const int *seatRow, const char *seatCol );
    void cancelReservation( const int resCode );
    void showReservation( const int resCode );

private:
    Flight *flights;
    int flightNumber;
    int pasNum;

};
#endif //PROJECT1_RESERVATIONSYSTEM_H
