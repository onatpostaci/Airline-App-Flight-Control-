//
// Created by sinap on 4.11.2020.
//

#ifndef PROJECT1_RESERVATION_H
#define PROJECT1_RESERVATION_H


class Reservation {
public:
    Reservation( int numPassengers, const int *seatRow, const int *seatCol);

    Reservation();

    virtual ~Reservation();


    bool getIsOccupied();
    char getDisplay();
    void changeDisplay();
    void setIsOccupied(bool occupation);
    void reSetDisplay();
    void setCode( int code );
    int getCode();
    void operator=( const Reservation&);
    int getRow();
    char getColumn();
    void setRow(int row);
    void setColumn(char column);

private:
    bool isOccupied;
    char display;
    int code;
    char column;
    int row;

};


#endif //PROJECT1_RESERVATION_H
