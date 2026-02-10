#include "main.h"

int stories[] = {1, 2, 3, 4};

int set_start_floor(int floor){
    if(floor < 0){
        elevio_motorDirection(DIRN_DOWN);
    }
    else{
        elevio_motorDirection(DIRN_STOP);
    }
    return floor;
}

int main(){
    elevio_init();
    while(1){
        int floor = elevio_floorSensor();
        int start_floor = set_start_floor(floor);
        printf("Start floor %d", start_floor);
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}



/*
        
         for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }
        */



/*
 if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
*/

 /*
         if(floor == 0){
            elevio_motorDirection(DIRN_UP);
        }

        if(floor == N_FLOORS-1){
            elevio_motorDirection(DIRN_STOP);
        }
        */