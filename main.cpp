#include "mbed.h"

DigitalOut a(PA_10);
DigitalOut b(PA_9);
DigitalOut c(PA_8);
DigitalOut d(PB_10);
DigitalOut e(PB_5);
DigitalOut f(PB_4);
DigitalOut g(PB_3);

DigitalOut SEL1(PB_6);
DigitalOut SEL2(PC_7);

int preostaloVreme = 0;

// Funkcija za ispisivanje cifre
void napisiBroj(int broj) {
    // Pogasi sve segmente
    a = 1;
    b = 1;
    c = 1;
    d = 1;
    e = 1;
    f = 1;
    g = 1;
    switch(broj){
    case 0:
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
        break;
    case 1:
        b = 0;
        c = 0;
        break;
    case 2:
        a = 0;
        b = 0;
        d = 0;
        e = 0;
        g = 0;
        break;
    case 3:
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        g = 0;
        break;
    case 4:
        b = 0;
        c = 0;
        f = 0;
        g = 0;
        break;
    case 5:
        a = 0;
        c = 0;
        d = 0;
        f = 0;
        g = 0;
        break;
    case 6:
        a = 0;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
        g = 0;
        break;
    case 7:
        a = 0;
        b = 0;
        c = 0;
        break;
    case 8:
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
        g = 0;
        break;
    case 9:
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        f = 0;
        g = 0;
    }
}


void ISR_taster() {
    // Pokreni tajmer
    preostaloVreme = 15000;
}


int main()
{
    InterruptIn taster(BUTTON1);
    taster.fall(&ISR_taster);

    // Oba displeja iskljucena
    SEL1 = 1;
    SEL2 = 1;

    while (true) {
        // Izracunaj pojedinacne cifre
        int broj1 = preostaloVreme / 10000;
        int broj2 = (preostaloVreme / 1000) % 10;

        // Napisi prvu cifru
        SEL1 = 0;
        napisiBroj(broj1);
        wait_us(5000);
        SEL1 = 1;

        //Napisi drugu cifru
        SEL2 = 0;
        napisiBroj(broj2);
        wait_us(5000);
        SEL2 = 1;

        if(preostaloVreme > 0) {
            preostaloVreme -= 10;
        }
    }
}

    
