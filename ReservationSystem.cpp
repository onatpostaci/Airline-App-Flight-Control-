//
// Created by sinap on 2.11.2020.
//

#include "ReservationSystem.h"
#include "Flight.h"
#include <iostream>

using namespace std;

ReservationSystem::ReservationSystem() {
    flights = NULL;
    flightNumber = 0;
    pasNum = 0;

}

ReservationSystem::~ReservationSystem() {
    if( flights != NULL ) {
        delete[] flights;
    }
}

void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int seatNo) {

    Flight *tmp = new Flight[flightNumber + 1];
    bool control = true;
    for (int i = 0; i < flightNumber; i++) {
        if (flights[i].getFlightNo() == flightNo) {
            control = false;
            break;
        }
    }
    if (control){
        if (flightNumber != 0) {
            for (int i = 0; i < flightNumber; i++) {
                tmp[i] = flights[i];
            }


            tmp[flightNumber] = Flight(flightNo, rowNo, seatNo);

            flights = NULL;

            flights = tmp;

        } else {
            cout << "flightNumber: " << flightNumber << endl;
            tmp[0] = Flight(flightNo, rowNo, seatNo);

            flights = tmp;
        }
        tmp = NULL;
        flightNumber++;
        cout << "Flight " << flightNo << " has been created." << endl;
    }else{
        cout << "Flight " << flightNo << " has already exists." << endl;
    }

}


void ReservationSystem::showAllFlights() {
    if( flightNumber == 0 ){
        cout << "No flights exist." << endl;
    }
    else{
        cout << "Flights currently operated: " << endl;
        for( int i = 0; i < flightNumber; i++){
            flights[i].showTheFlight();
        }
    }
}

int ReservationSystem::makeReservation(const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol) {

    static int reservationCode = 0;
    int index = -1;
    for (int i = 0; i < flightNumber; i++) {
        if (flights[i].getFlightNo() == flightNo)
            index = i;
    }

    if (index != -1){
        flights[index].setSeatForCode(0);
        reservationCode++;
        for (int i = 0; i < numPassengers; i++) {
            flights[index].changeSeat(seatRow[i], seatCol[i], reservationCode);
        }

        if ( flights[index].getSeatForCode() == 0 ) {
            return -1;
        }

        return reservationCode;
    }else{
        return 0;
    }
}

void ReservationSystem::cancelFlight(const int flightNo) {
    int index = -1;
    if (flightNumber != 0){

        Flight *tmp = new Flight[flightNumber - 1];
        for (int i = 0; i < flightNumber; i++) {
            if (flights[i].getFlightNo() == flightNo) {
                index = i;
            }
        }

        if (index != -1) {
            int j;
            for (j = 0; j < index; j++) {
                tmp[j] = flights[j];
            }
            for (int j = index + 1; j < flightNumber; j++) {
                tmp[j - 1] = flights[j];
            }
            flights = NULL;
            flights = tmp;
            flightNumber--;
            cout << "The flight " << flightNo << " and all of its reservations are cancelled." << endl;
        } else {
            cout << "Flight " << flightNo <<" does not exist." << endl;
        }
    }else{
        cout << "There is no flight." << endl;
    }

}

void ReservationSystem::showFlight(const int flightNo) {
    int index = -1;
    for( int i = 0; i < flightNumber; i++){
        if ( flightNo == flights[i].getFlightNo())
            index = i;
    }
    if(index != -1) {
        int index2 = -1;
        cout << "Flight " << flightNo << " has " << flights[index].getAvailableSeats() << " available seats." << endl;
        flights[index].showSeats();
    }
    else{
        cout<< "Flight "<< flightNo <<" does not exist." << endl;
    }
}

void ReservationSystem::cancelReservation(const int resCode) {
    bool check = false;
    int index = -1;

    for (int i = 0; i < flightNumber; ++i) {

        for (int j = 0; j < flights[i].getAllSeats(); ++j) {
            if( flights[i].getReservations()[j].getCode() == resCode ) {
                index = i;

                check = true;

            }
        }
    }


    if( check ){

        flights[index].cancelSeat(resCode);
        cout << "Reservation for the seat(s) " ;
        flights[index].printReservations(resCode);
        cout << " is canceled in Flight " << flights[index].getFlightNo() << endl;
        flights[index].changeReference(resCode);
    }

}

void ReservationSystem::showReservation(const int resCode) {
    bool check = false;
    int index = -1;

    for (int i = 0; i < flightNumber; ++i) {
        for (int j = 0; j < flights[i].getAllSeats(); ++j) {
            if (flights[i].getReservations()[j].getCode() == resCode) {
                index = i;
                check = true;
            }
        }
    }
    if (index != -1){
        if (flights[index].getCheck()) {
            cout << "Reservations under Code " << resCode << " in Flight " << flights[index].getFlightNo() << ": ";
            flights[index].printReservations(resCode);
            cout << endl;
        } else
            cout << "No reservations found under Code " << resCode << endl;


}else{
        cout << "No reservations found under Code " << resCode << endl;
    }
}
