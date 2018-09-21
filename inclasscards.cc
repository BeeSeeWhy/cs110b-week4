#include <iostream>
using namespace std;

const int NUM_PLAYERS = 4, NUM_CARDS = 3;
int cards[NUM_PLAYERS][NUM_CARDS] = {
    {40, 30, 20},
    {20, 60, 70},
    {120, 456, 677},
    {300, 464, 243}
};

void printCards(int cards[NUM_PLAYERS][NUM_CARDS])
{
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        
        for (int j = 0; j < NUM_CARDS; j++)
        {
            cout << "cards [" << i << "][" << j << "]: ";
            cout << cards[i][j] << endl;
        }

    }
}

void putHundreds(int cards[NUM_PLAYERS][NUM_CARDS])
{
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        for (int j = 0; j < NUM_CARDS; j++)
        {
            cards[i][j] = 100;
        }
    }

    printCards(cards);
}

bool checkCards(int cards[NUM_PLAYERS][NUM_CARDS])
{   
    bool check = false;

    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        for (int j = 0; j < NUM_CARDS; j++)
        {
            if (cards[i][j] == 120)
            {
                check = true;
            }
        }
    }

    cout << endl;
    if ( check == true)
    {
        cout << "120 is in the array" << endl;
    }
    else 
    {
        cout << "120 is not in the array" << endl;
    }
    return check;
}

int main()
{

    printCards(cards);
    //putHundreds(cards);
    checkCards(cards);
}
