
#include <iomanip>
#include <iostream>
using namespace std;

void printPiles(int pile1[], int pile2[], int pile3[], int size)
{
    cout << endl;
    cout << "Pile 1 \t" << "Pile 2 \t" << "Pile 3" << endl;
    for(int counter = 0; counter < size; counter++){
        cout << pile1[counter] << "\t" << pile2[counter];
        cout << "\t" << pile3[counter] << endl;
    }
}

int choosePile()
{
    int choice;
    do{
    cout << endl;
        cout << "Which pile is your card in? ";
        cin >> choice;
    }while(choice < 1 && choice > 3);

    return choice;
}

int main() {

    const int SIZE = 21, PILESIZE = 7;
    int choice;
    int cards[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                        11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    int cardsPile1[PILESIZE], cardsPile2[PILESIZE];
    int cardsPile3[PILESIZE];

    do{
        cout << "Choose a card" << endl;

            for(int counter = 0; counter < SIZE; counter++){
                    cout << cards[counter] << endl;
            }

        cout << "Enter 0 once you have chosen: ";
            cin >> choice;
    }while(choice != 0);

    for(int shuffle = 0; shuffle < 3; shuffle++){
          for(int i = 0, counter = 0; counter < PILESIZE; counter++){
                cardsPile1[counter] = cards[i];
                i += 3;
          }

          for(int i = 1, counter = 0; counter < PILESIZE; counter++){
                cardsPile2[counter] = cards[i];
                i += 3;
          }

          for(int i =2, counter = 0; counter < PILESIZE; counter++){
                cardsPile3[counter] = cards[i];
                i += 3;
          }

          printPiles(cardsPile1, cardsPile2, cardsPile3, PILESIZE);
          choice = choosePile();
          switch (choice){
              case 1: for(int counter = 0; counter < PILESIZE; counter++){
                          cards[counter] = cardsPile2[counter];
                      }

                      for(int counter = 0; counter < PILESIZE; counter++){
                          cards[counter + 7] = cardsPile1[counter];
                      }

                  for(int counter = 0; counter < PILESIZE; counter++){
                      cards[counter + 14] = cardsPile3[counter];
                  }
                  break;
          case 2: for(int counter = 0; counter < PILESIZE; counter++){
                      cards[counter] = cardsPile3[counter];
                  }

                  for(int counter = 0; counter < PILESIZE; counter++){
                      cards[counter + 7] = cardsPile2[counter];
                  }

                  for(int counter = 0; counter < PILESIZE; counter++){
                      cards[counter + 14] = cardsPile1[counter];
                  }
                  break;
          case 3: for(int counter = 0; counter < PILESIZE; counter++){
                      cards[counter] = cardsPile1[counter];
                  }

                  for(int counter = 0; counter < PILESIZE; counter++){
                      cards[counter + 7] = cardsPile3[counter];
                  }

                  for(int counter = 0; counter < PILESIZE; counter++){
                          cards[counter + 14] = cardsPile2[counter];
                  }
                  break;
          }
    }


    cout << "Your card is " << cards[10] << '.' << endl;
    return 0;
}
