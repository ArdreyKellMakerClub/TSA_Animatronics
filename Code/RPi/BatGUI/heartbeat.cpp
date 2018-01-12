#include "heartbeat.h"

int something = 0;
string thing1;
string thing2;

int heartbeat(SerialStream& stream){
    while(something<1000){
        cin >> thing1;
        stream <<  thing1 << endl;
        stream >> thing2;
        cout << thing2 << endl;
        something++;
    }
    return 0;
}
