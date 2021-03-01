//
// Created by sinap on 4.11.2020.
//

#include "Reservation.h"

Reservation::Reservation() {
    display = 'o';
    isOccupied = false;
    code = 0;
    row = 0;
    column = '*';

}

Reservation::~Reservation() {

}

Reservation::Reservation(int numPassengers, const int *seatRow, const int *seatCol) {

}

void Reservation::operator=(const Reservation &second) {
    this-> display = second.display;
    this-> isOccupied = second.isOccupied;
    this-> code = second.code;
    this-> row = second.row;
    this-> column = second.column;
}

bool Reservation::getIsOccupied() {
    return isOccupied;
}

void Reservation::setIsOccupied(bool occupation) {
    isOccupied = occupation;
}

char Reservation::getDisplay() {
    return display;
}

void Reservation::changeDisplay() {
    display = 'x';
}

void Reservation::reSetDisplay() {
    display = 'o';
}

void Reservation::setCode(int code) {
    this -> code = code;
}

int Reservation::getCode() {
    return code;
}

int Reservation::getRow() {
    return row;
}

char Reservation::getColumn() {
    return column;
}

void Reservation::setRow(int row) {
    this->row = row;
}

void Reservation::setColumn(char column) {
    this->column = column;
}
