#include "main.hpp"

char tab[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {

    while(true) {
        p1();
        if(ifWin() == true) {
            return 0;
        }
        p2();
        if(ifWin() == true) {
            return 0;
        }
    }
}

void p1() {
    print();
    std::cout<<"Player 1's move, choose where to insert X: "<<std::endl;
    check('X');

}

void p2() {
    print();
    std::cout<<"Player 2's move, choose where to insert O: "<<std::endl;
    check('O');
}

void print() {
    system("cls");
    std::cout<<char(218)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(194)<<char(196)<<char(196)<<char(196)<<char(191)<<std::endl;
    std::cout<<char(179)<<char(32)<<tab[0]<<char(32)<<char(179)<<char(32)<<tab[1]<<char(32)<<char(179)<<char(32)<<tab[2]<<char(32)<<char(179)<<std::endl;
    std::cout<<char(195)<<char(196)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(196)<<char(180)<<std::endl;
    std::cout<<char(179)<<char(32)<<tab[3]<<char(32)<<char(179)<<char(32)<<tab[4]<<char(32)<<char(179)<<char(32)<<tab[5]<<char(32)<<char(179)<<std::endl;
    std::cout<<char(195)<<char(196)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(196)<<char(180)<<std::endl;
    std::cout<<char(179)<<char(32)<<tab[6]<<char(32)<<char(179)<<char(32)<<tab[7]<<char(32)<<char(179)<<char(32)<<tab[8]<<char(32)<<char(179)<<std::endl;
    std::cout<<char(192)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(193)<<char(196)<<char(196)<<char(196)<<char(217)<<std::endl;
    std::cout<<std::endl;
}

void check(char digit) {
    char where;
    std::cin>>where;
    bool pri=false;


    for(int i=0; i<9; ++i) {
        if(where == tab[i]) {
            tab[i] = digit;
            pri = true;
            break;
        }
    }

    if(pri == false) {
        std::cout<<"The wrong number was entered"<<std::endl;
        if(digit == 'X') {
            p1();
        } else{
            p2();
        }
    }
}

int win() {
    char wc = 'E';
    if(tab[0] == tab[1] && tab[1] == tab[2]) {
        wc = tab[0];
    } else if(tab[3] == tab[4] && tab[4] == tab[5]) {
        wc = tab[3];
    } else if(tab[6] == tab[7] && tab[7] == tab[8]) {
        wc = tab[6];
    } else if(tab[0] == tab[3] && tab[3] == tab[6]) {
        wc = tab[0];
    } else if(tab[1] == tab[4] && tab[4] == tab[7]) {
        wc = tab[1];
    } else if(tab[2] == tab[5] && tab[5] == tab[8]) {
        wc = tab[2];
    } else if(tab[0] == tab[4] && tab[4] == tab[8]) {
        wc = tab[0];
    } else if(tab[2] == tab[4] && tab[4] == tab[6]) {
        wc = tab[2];
    }

    bool tie = true;

    if(wc == 'E') {
        for(int i=0; i<9; ++i) {
            if(tab[i]!='X'&&tab[i]!='O') {
                tie = false;
            }
        }

        if(tie == false) {
            return 0;
        } else {
            return 3;
        }
    }

    if(wc == 'X') {
        return 1;
    } else if(wc == 'O') {
        return 2;
    }

    return 0;
}

bool ifWin() {
    int s = win();
    if(s == 1) {
        system("cls");
        std::cout<<"!!! PLAYER 1 WON !!!"<<std::endl;
        return true;
    } else if(s == 2) {
        system("cls");
        std::cout<<"!!! PLAYER 2 WON !!!"<<std::endl;
        return true;
    } else if(s == 3) {
        system("cls");
        std::cout<<"!!! DRAW !!!"<<std::endl;
        return true;
    }
    return false;
}