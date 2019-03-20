
// Libraries
#include <iostream>
#include <pthread.h>

// Game Logic
#include "gameLogic/Dictionary.hpp"
#include "gameLogic/GameDeck.hpp"
#include "gameLogic/Board.hpp"
#include "gameLogic/Player.hpp"

// Sockets
#include "SocketComunication/socketClient.hpp"
#include "SocketComunication/socketServer.hpp"

// JSON
#include "ScrabbleTest/JsonTest/JSON_Test.hpp"

// Forward Declaration :: Methods

void dictionaryTest();
void boardTest1();
void boardTest2();
void playerTest1();
void socketTest();
void* startServer(void*);


int main() {

    /*dictionaryTest();
    boardTest1();
    boardTest2();
    playerTest1();*/

    JSON_Test::test1();
}

/* -----------------------------
 *          TEST METHODS
 * ----------------------------*/

void dictionaryTest(){
    Dictionary *dictionary = new Dictionary();
    cout<<"Searching for zutano: ";
    if(dictionary->searchInDictionary("zutano")) cout<<"Found."<<endl;
    else cout << "Not Found.\n\n\n";

    GameDeck *gd = new GameDeck();
    gd->printDeck();

    cout<<"Randomly extracting all letter tiles: "<<endl;
    LetterTile* l;
    for(int i = 0; i < 100; i++) {
        cout << "GameDeck [letter, amount, score]: ";
        gd->printDeck();
        l = gd->giveRandomLetter();
        cout << l->getLetter() << "\n\n";
    }
}

void boardTest1(){
    Board* myBoard = new Board();
    myBoard->printGameBoard();
    LetterTile* tile = new LetterTile("a",12,1);
    myBoard->addLetterTile(0,0,tile);
    cout<<endl;
    myBoard->printGameBoard();
    myBoard->getLetterTile(0,0);
    myBoard->getLetterTile(0,1);

}

void boardTest2(){
    Board* myBoard = new Board();
    myBoard->printScoreBoard();
    cout<<myBoard->getScore(0,0)<<endl;
    cout<<myBoard->getScore(1,0)<<endl;
    cout<<myBoard->getScore(7,7)<<endl;
}

void playerTest1(){
    GameDeck *gameDeck = new GameDeck();

    cout<<"\nCreando player1..."<<endl;
    Player *player1 = new Player();
    cout<<"Creando player2..."<<endl;
    Player *player2 = new Player();

    cout<<"Llenando deck de player1..."<<endl;
    while(player1->getAmountOfLetterTiles() != 7){
        LetterTile *randomLetterTile = gameDeck->giveRandomLetter();
        player1->addLetterTile(randomLetterTile);
    }

    cout<<"Llenando deck de player1..."<<endl;
    while(player2->getAmountOfLetterTiles() != 7){
        LetterTile *randomLetterTile = gameDeck->giveRandomLetter();
        player2->addLetterTile(randomLetterTile);
    }
    cout<<"Deck player1: "; player1->printPlayerDeck();
    cout<<"Deck player2: "; player2->printPlayerDeck();
}

socketServer *server; // Esta variable debe ser global... para el ejemplo

/*void* startServer(void *){
    try {
        server->runServer();
    }catch(string exception){
        cout << exception <<endl;
    }
    pthread_exit(nullptr);

}*/

/*
void socketTest(){

    server = new socketServer;

    pthread_t serverThread;
    pthread_create(&serverThread, 0, startServer, nullptr);
    pthread_detach(serverThread);

    while (true) {
        string message;
        cin >> message;
        server->sendMessage(message.c_str());
    }

}
*/



