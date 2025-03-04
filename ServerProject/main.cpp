/* --------------------------------------------------------------------------------------------------
                             _     _     _        _            _
          ___  ___ _ __ __ _| |__ | |__ | | ___  | |_ ___  ___| |_ ___
         / __|/ __| '__/ _` | '_ \| '_ \| |/ _ \ | __/ _ \/ __| __/ __|
         \__ \ (__| | | (_| | |_) | |_) | |  __/ | ||  __/\__ \ |_\__ \
         |___/\___|_|  \__,_|_.__/|_.__/|_|\___|  \__\___||___/\__|___/

 The Scrabble v.0.5 game is still in its creation stage and we are solving the errors
 of this version to launch the next one as soon as possible.For the moment, we provide
 a guide on how the graphical and server interface can be tested correctly.(While we correct the bugs)
 =====================================================================================================

 1. DEPLOY THE SERVER -> To run the server you must follow the following steps:
    (a) In the config.properties enter the IP address of your computer.
    (b) If you want to change the communication port you must do it in the config.properties, otherwise
        the program will take the default port.
    (c) Set the expert telephone number in words, as well as the number of the sender and the account_SID
        and the token in the properties file.
    (d) once you have everything configured you can run the main function. If everything goes correctly, a
    message will be printed on the console:
                "Board has been initialized successfully!
                 Waiting for Customer! "
  2. RUN CLIENTS -> Once the server is deployed, the clients are started:
    (A) CREATE GAME: To create a new game press the << NEW GAME >> button, then select the number of players
        the game will have and press <Ok>. Then it will show you on the screen the code of the game.
    (B) JOIN TO GAME: To join a game press the << PLAY >> button, then enter the code of the game, if this is
        correct the game will wait until all the players are connected to show the game board.

  3. PLAY A WORD [ISSUE]

   +-------------------------------------------------------------------------------------------------------+
   | ** This part is where the error related to the JSON parser occurs on both the client and server sides.|
   | We think that it is a mistake in the buffer, input of both programs.                                  |
   +-------------------------------------------------------------------------------------------------------+

    In this part, the game windows will open with the chips awarded to each player. You can drag the tiles to the
    board to form words. When you have your word ready, press the scrabble button, this will generate a json with
    the message information and try to send it to the server through the socket.

  4. OK...IT GOES DOWN BUT...DO THEY WORK SEPARATELY?

    (A) To test the server ... run the <Socket Client> test app from qt. Open an initial window and indicate the number
    of players that the game will have (This first will create the game).
    (B) Run the remaining clients to complete the required amount. Remember to enter the game code.
    (C) Send the following messages in the suggested order:

        -> Insert word test
        p1 {"id":2,"word":"p,e,rr,o","firstRow":7,"firstCol":7,"is_Vertical":true}
        p2 {"id":2,"word":"h,o,g,a,r","firstRow":0,"firstCol":0,"is_Vertical":false}
        p3 {"id":2,"word":"a,t,o,n","firstRow":1,"firstCol":4,"is_Vertical":true}

        -> Insert composed word test
        p1 {"id":2,"word":"a,p,a,y,a","firstRow":7,"firstCol":8,"is_Vertical":false}

        -> Pass test
        p2 {"id":3,"pass":true}

        -> Expert test
        p1 {"id":4,"word":"a,s,e,r,e,j,e","firstRow":12,"firstCol":0,"is_Vertical":false}


 * --------------------------------------------------------------------------------------------------*/

// Libraries
#include <iostream>
#include <pthread.h>

// Game Logic
#include "gameLogic/Server.hpp"
#include "gameLogic/Game.hpp"
#include "gameLogic/Expert.hpp"

// gtest
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>

int server_release();

using namespace std;

int main(int argc,char* argv[]) {

    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();

    server_release();

    return 0;
}

int server_release(){

    // Se crea un servidor
    Server* server1_ = new Server();

    /* ------------------------------------------------------
     *              ESTRUCTURA DE EJECUCION
     *
     * 1. Se crea un nuevo juego
     * 2. Se agregan los clientes
     * 3. Se ejecuta la funcion Game::play() dentro de un hilo
     * ------------------------------------------------------*/
    server1_->new_game();
    thread t(&Server::launch_game,server1_);
    t.join();

    return 0;
}

/*------------------------------------------------
 *                  END OF CODE ZONE
 * -----------------------------------------------*/
