//
// Created by sinap on 2.11.2020.
//

#include "Flight.h"
#include "Reservation.h"
#include <iostream>
using namespace std;

Flight::Flight( const int flightNo, const int rowNo,  int seatNo) {
    this -> flightNo = flightNo;
    this -> rowNo = rowNo;
    this -> seatNo = seatNo;
    availableSeats = this-> rowNo * this -> seatNo;
    reservations = new Reservation[ rowNo * seatNo ];
    //showSeats();
    allSeats = seatNo * rowNo;
    alphabet = NULL;
    sRow = NULL;
    populateAlphabet( seatNo );
    /*for (int i = 0; i < seatNo ; ++i) {
        cout << alphabet[i] << " ";
    }*/
    populatesRow( rowNo );
    int seatForCode;
    check = true;
}

void Flight::operator=(const Flight &second) {
    this -> flightNo = second.flightNo;
    this -> rowNo = second.rowNo;
    this -> seatNo = second.seatNo;
    this -> allSeats = second.allSeats;
    this -> availableSeats = second.availableSeats;
    this -> check = second.check;

    this -> alphabet = NULL;
    alphabet = new char [seatNo];
    for (int i = 0; i < seatNo; ++i) {
        this -> alphabet[i] = second.alphabet[i];
    }

    this -> sRow = NULL;
    sRow = new int [rowNo];
    for (int i = 0; i < rowNo; ++i) {
        this -> sRow[i] = second.sRow[i];
    }

    this -> reservations = NULL;
    reservations = new Reservation[allSeats];
    for (int i = 0; i < allSeats; ++i) {
        this -> reservations[i] = second.reservations[i];
    }


}

int Flight::getFlightNo() {
    return flightNo;
}

int Flight::getRowNo() {
    return  rowNo;
}

int Flight::getSeatNo() {
    return  seatNo;
}

int Flight::getAvailableSeats() {
    return availableSeats;
}

int Flight::getAllSeats() {
    return allSeats;
}

Reservation *Flight::getReservations() {
    return reservations;
}

int Flight::getSeatForCode() {
    return seatForCode;
}

void Flight::setSeatForCode(int set) {
    seatForCode = set;
}

void Flight::populateAlphabet( int seatNo ) {
    char *tmp = new char[seatNo];
    tmp[0] = 'A';
    for (int i = 1; i < seatNo; ++i) {
        tmp[i] = tmp [ i - 1 ] + 1;
    }
    alphabet = tmp;
    tmp = NULL;
}

void Flight::populatesRow(int rowNo) {
    int *tmp = new int[ rowNo ];
    for( int i = 0; i < rowNo; i++){
        tmp[i] = i+1;
    }
    sRow = tmp;
    tmp = NULL;
}

void Flight::changeSeat(const int rowNo, const char seatNo, int code) {
    int index = -1;
    for(int i = 0; i < this -> seatNo; i++) {
        if( seatNo == alphabet[i]){
            index = i;
        }
    }

    if(!reservations[ (rowNo-1)*3-1 + (index +1) ].getIsOccupied()) {
        seatForCode++;
        reservations[ (rowNo-1) * 3 - 1 + (index+1) ].changeDisplay();
        reservations[(rowNo-1)*3-1+(index+1)] .setIsOccupied(true);
        reservations[(rowNo-1)*3-1+(index+1)].setCode(code);
        reservations[(rowNo-1)*3-1+(index+1)].setRow(rowNo);
        reservations[(rowNo-1)*3-1+(index+1)].setColumn(seatNo);
        availableSeats--;
    }
    else{
        cout << rowNo << seatNo << " is not available" << endl;
    }
}

void Flight::cancelSeat(int code) {

    for (int i = 0; i < getRowNo() * getSeatNo(); i++) {
        if( reservations[i].getCode() == code ) {
            reservations[i].reSetDisplay();
            reservations[i].setIsOccupied(false);
            availableSeats++;
        }
    }
}

void Flight::changeReference(int code) {
    for (int i = 0; i < getRowNo() * getSeatNo(); i++) {
        if( reservations[i].getCode() == code ) {
            reservations[i].setRow(0);
            reservations[i].setColumn('*');
        }
    }
}

void Flight::printReservations(int code) {
    for (int i = 0; i < allSeats; ++i) {
        if( reservations[i].getRow() != 0 && reservations[i].getColumn() != '*' && reservations[i].getCode() == code){
            cout << reservations[i].getRow() << reservations[i].getColumn() << " ";
        }
    }
}

bool Flight::getCheck() {
    for (int i = 0; i < allSeats; ++i) {
        if (reservations[i].getRow() != 0 && reservations[i].getColumn() != '*'){
            return true;
        }
    }

    return false;
}

void Flight::showTheFlight() {
    cout << "Flight " << getFlightNo() << " (" << getAvailableSeats() << " available seats)." << endl;
}

Flight::Flight() {
}

Flight::~Flight() {
    if( reservations != NULL)
        delete [] reservations;
}


void Flight::showSeats() {
    for (int i = 0; i < seatNo; ++i) {
        cout << alphabet[i] << " ";
    }

    cout << endl;

    int k = 0;
    int j = 0;

    for( int i = 0; i < rowNo; i++ ){
        cout << sRow[i] << " ";
        k = 0;
        while (k < seatNo){
            cout << reservations[j].getDisplay() << " ";
            j++;
            k++;
        }
        if( i == rowNo - 1){
            cout;
        }
        else
            cout << endl;
    }

    cout << endl;

}





