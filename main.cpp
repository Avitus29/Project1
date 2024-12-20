#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Room {
       int roomNumber;
       string roomType:
       bool isBooked;
       
       Room(int  number, string type):
roomNumber(number),roomType(type),isBooked(false) {}



void bookRoom () {
if(!isBooked) {
               isBooked = true;
               cout<<"Room"<<roomNumber<<"is already booked!\n"<<endl;
}
}


}