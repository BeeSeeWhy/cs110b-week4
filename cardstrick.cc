
#include <iomanip>
#include <iostream>
using namespace std;

void printPiles(int pile1[], int pile2[], int pile3[], int size) {
    cout << endl;
    cout << "Pile 1 \t" << "Pile 2 \t" << "Pile 3" << endl;
    for(int counter = 0; counter < size; counter++) {
        cout << pile1[counter] << "\t" << pile2[counter];
        cout << "\t" << pile3[counter] << endl;
    }
}

int choosePile()
{
    int choice;
    do {
    cout << endl;
        cout << "Which pile is your card in? ";
        cin >> choice;
    } while(choice < 1 && choice > 3);

    return choice;
}

void shufflePile(int firstI, int cardsPile[], int pileSize, const int cards[]) {
    for(int i = firstI, counter = 0; counter < pileSize; i += 3, counter++) {
        cardsPile[counter] = cards[i];
    }
}

void combinePilesFirst(int initialI, int cardsPile[], int pileSize, int cards[]) {
    for(int counter = initialI; counter < pileSize; counter++) {
        cards[counter] = cardsPile[counter];
    }
}

void combinePilesSecond(int initialI, int cardsPile[], int pileSize, int cards[]) {
    for(int counter = initialI; counter < pileSize; counter++) {
        cards[counter + 7] = cardsPile[counter];
    }
}

void combinePilesThird(int initialI, int cardsPile[], int pileSize, int cards[]) {
    for(int counter = initialI; counter < pileSize; counter++) {
        cards[counter + 14] = cardsPile[counter];
    }
}

int main() {

    const int SIZE = 21, PILESIZE = 7;
    int choice;
    int cards[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                       11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    int cardsPile1[PILESIZE], cardsPile2[PILESIZE];
    int cardsPile3[PILESIZE];

    do {
        cout << "Choose a card" << endl;

            for(int counter = 0; counter < SIZE; counter++) {
                    cout << cards[counter] << endl;
            }

        cout << "Enter 0 once you have chosen: ";
        cin >> choice;
    } while(choice != 0);

    for(int shuffle = 0; shuffle < 3; shuffle++) {
          shufflePile(0, cardsPile1, PILESIZE, cards);
          shufflePile(1, cardsPile2, PILESIZE, cards);
          shufflePile(2, cardsPile3, PILESIZE, cards);

          printPiles(cardsPile1, cardsPile2, cardsPile3, PILESIZE);
          choice = choosePile();
          switch (choice) {
              case 1: combinePilesFirst(0, cardsPile2, PILESIZE, cards);
                      combinePilesSecond(0, cardsPile1, PILESIZE, cards);
                      combinePilesThird(0, cardsPile3, PILESIZE, cards);
                      break;
              case 2: combinePilesFirst(0, cardsPile3, PILESIZE, cards);
                      combinePilesSecond(0, cardsPile2, PILESIZE, cards);
                      combinePilesThird(0, cardsPile1, PILESIZE, cards);
                      break;
              case 3: combinePilesFirst(0, cardsPile1, PILESIZE, cards);
                      combinePilesSecond(0, cardsPile3, PILESIZE, cards);
                      combinePilesThird(0, cardsPile2, PILESIZE, cards);
                      break;
          }
    }


    cout << "Your card is " << cards[10] << '.' << endl;
    return 0;
}
