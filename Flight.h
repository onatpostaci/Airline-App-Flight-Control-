//
// Created by sinap on 2.11.2020.
//

#ifndef PROJECT1_FLIGHT_H
#define PROJECT1_FLIGHT_H
#include "Reservation.h"
using namespace std;
class Flight{
public:

    Flight();

    Flight( const int flightNo, const int rowNo, const int seatNo);



    int getFlightNo();
    int getRowNo();
    int getSeatNo();
    void showTheFlight();
    void showSeats();
    int getAvailableSeats();
    bool getCheck( );
    void changeSeat( const int rowNo, const char seatNo, int code );
    void populateAlphabet( int seatNo );
    void populatesRow( int rowNo );
    void cancelSeat( int code );
    Reservation *getReservations();
    int getAllSeats();
    void operator=( const Flight&);
    void printReservations( int code );
    void changeReference( int code );
    int getSeatForCode();
    void setSeatForCode(int set);

    virtual ~Flight();

private:
    int flightNo;
    int rowNo;
    int seatNo;
    char *alphabet;
    int *sRow;
    bool check;
    int availableSeats;
    Reservation *reservations;
    int allSeats;
    int seatForCode;
};
#endif //PROJECT1_FLIGHT_H
