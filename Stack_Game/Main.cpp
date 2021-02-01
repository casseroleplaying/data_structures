// Program to implement simple card game.
// A deck of cards (with integer values) is generated as an array based list.
// The deck is then shuffled randomly and pushed onto a stack (as a linked list).
// Two players are alternatively dealt three cards each from the top of the deck.
// A player's score is calculated as the total value of their 3 cards in hand.
// The player with the highest score wins :)
// The user can choose a player to bet on before the results are displayed.
// Good Luck!

#include <iostream>
#include "arrayListType.h"
#include "Stack.h"
using namespace std;

int main() {

    // create a deck of cards, two players, and variables for the winner and user's bet
    arrayListType<int> deck(24), player1(3), player2(3);
    int choice, winner = 0;
    Stack<int> s;

    cout << "\nCreating a deck of " << deck.getMaxSize() << " cards...";
    for (int i = 0; i < deck.getMaxSize(); ++i)     // populate the deck with numbers 1-24
        deck.insertAt(i, i + 1);

    cout << "\nShuffling the deck...";
    deck.shuffleArray();                            // shuffle the deck

    cout << "\nStacking up the shuffled deck...";
    for (int i = 0; i < deck.getMaxSize(); ++i) {   // push the shuffled deck onto the stack
        try {
            s.push(deck.getElement(i));
        }
        catch (fullStack) {
            cout << "Stack full.\n";
        }
    }

    cout << "\nDealing each player 3 cards..."
        << "\nThe player whose cards add up to the highest value wins.\n";
    for (int i = 0; i < 6; ++i) {                   // alternatively 'deal' cards to players
        if (i % 2 == 0) {                           // from the top of the deck
            player1.insertAt(i / 2, s.peek());
            s.pop();
        }
        else {
            player2.insertAt(i / 2, s.peek());
            s.pop();
        }
    }

    do {                                            // let the user place bet on a player
        cout << "\nChoose a player to bet on (enter 1 or 2): ";
        cin >> choice;
    } while (choice < 1 || choice > 2);

    cout << "\nplayer 1's hand: ";                  // output each players 'hand'
    player1.print();
    cout << "player 2's hand: ";
    player2.print();

    // declare the winner
    if (player1.getTotal() > player2.getTotal()) {
        cout << "\nPlayer 1 wins with total of " << player1.getTotal() << "\n";
        winner = 1;
    }
    else if (player1.getTotal() < player2.getTotal()) {
        cout << "\nPlayer 2 wins with total of " << player2.getTotal() << "\n";
        winner = 2;
    }
    else
        cout << "\nDraw, both players have total of " << player1.getTotal() << "\n";

    // output the results of the user's bet
    if (choice == winner)
        cout << "\nYou got lucky and chose the winner!\n";
    else
        cout << "\nYour chosen player " << choice << " lost, better luck next time!\n";

    return 0;
}

/* below can be pasted into the end of main to verify shuffle and more stack functions

    cout << "\nStack 1: ";
    s.display();
    Stack<int> s2(s);
    cout << "\nStack 2 made from copy constructor: ";
    s2.display();
    cout << "\nPopping from Stack 1...";
    s.pop();
    cout << "\nStack 1: ";
    s.display();
    cout << "\nLet's check on our copy (Stack 2): ";
    s2.display();

    Stack<int> s3;
    s3 = s2;
    cout << "\nLet's check the overloaded assignment operator, Stack 3: ";
    s3.display();
    cout << "\nLet's now pop from Stack 2...";
    s2.pop();
    cout << "\nAnd check back on our Stack 3: ";
    s3.display();

    cout << "\nShuffled deck: ";
    deck.print();
    cout << "\nStacked deck (after dealing popping 7 cards): ";
    s.display();

    cout << "\nLet's pop an item off the stack now and re-print...\n";
    s.pop();
    s.display();
    cout << "\nNow let's push the number 100 on the stack and re-print...\n";
    s.push(100);
    s.display();

    cout << "\nIs the stack empty? ";
    if (s.isEmpty())
        cout << "Yes.\n";
    else
        cout << "No.\n";

    cout << "\nLet's delete the whole stack and try to print...\n";
    s.deleteStack();
    cout << "Stack contents: ";
    s.display();

    cout << "\nIs the stack empty? ";
    if (s.isEmpty())
        cout << "Yes.\n";
    else
        cout << "No.\n";

*/