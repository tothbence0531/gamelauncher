//--------------------INCLUDE-------------------//

#include <stdio.h>
#include "stdlib.h"
#include "conio.h"
#include "time.h"

/*
 *
 *     _________  ________  ______       _________  ________   ______       _________  ______   ______
 *    /________/\/_______/\/_____/\     /________/\/_______/\ /_____/\     /________/\/_____/\ /_____/\
 *    \__.::.__\/\__.::._\/\:::__\/     \__.::.__\/\::: _  \ \\:::__\/     \__.::.__\/\:::_ \ \\::::_\/_
 *       \::\ \     \::\ \  \:\ \  __      \::\ \   \::(_)  \ \\:\ \  __      \::\ \   \:\ \ \ \\:\/___/\
 *        \::\ \    _\::\ \__\:\ \/_/\      \::\ \   \:: __  \ \\:\ \/_/\      \::\ \   \:\ \ \ \\::___\/_
 *         \::\ \  /__\::\__/\\:\_\ \ \      \::\ \   \:.\ \  \ \\:\_\ \ \      \::\ \   \:\_\ \ \\:\____/\
 *          \__\/  \________\/ \_____\/       \__\/    \__\/\__\/ \_____\/       \__\/    \_____\/ \_____\/
 *
 *      By: Toth Bence
 *      2023.11.24
 *      SZTE PTI BSC Programming Basics
*/

//----------DEFINE----------

#define rows 3
#define cols 3

//----------------------------------Function declatarions------------------------------------------

int main_tictactoe();
void print_logo_tictactoe();
int gameplay_tictactoe();
void print_game_end_tictactoe(int board[rows][cols], int player);
void update_board_tictactoe(int board[rows][cols], const int* y_ptr, const int* x_ptr, int player, int* i);
int is_board_full_tictactoe(int board[rows][cols]);
int is_won_tictactoe(int board[rows][cols]);
void player_input_tictactoe(int* y_pos, int* x_pos);
void print_board_tictactoe(int board[rows][cols]);
int restart_tictactoe();
int print_introduction_tictactoe(int board[rows][cols]);
int yes_or_no_tictactoe();

//--------------------------------------------FUNCTIONS---------------------------------------------------

void board_clear(int board[rows][cols]){            // sets every item in the matrix to 0
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = 0;
        }
    }
}
void print_board_tictactoe(int board[rows][cols]){            // prints to whole board with dividers
    printf( "\n %c | %c | %c", board[0][0]==1 ? 'X' : board[0][0]==0 ? ' ' : 'O', board[0][1]==1 ? 'X' : board[0][1]==0 ? ' ' : 'O', board[0][2]==1 ? 'X' : board[0][2]==0 ? ' ' : 'O');
    printf("\n---|---|---\n");
    printf( " %c | %c | %c", board[1][0]==1 ? 'X' : board[1][0]==0 ? ' ' : 'O', board[1][1]==1 ? 'X' : board[1][1]==0 ? ' ' : 'O', board[1][2]==1 ? 'X' : board[1][2]==0 ? ' ' : 'O');
    printf("\n---|---|---\n");
    printf( " %c | %c | %c\n\n", board[2][0]==1 ? 'X' : board[2][0]==0 ? ' ' : 'O', board[2][1]==1 ? 'X' : board[2][1]==0 ? ' ' : 'O', board[2][2]==1 ? 'X' : board[2][2]==0 ? ' ' : 'O');
}
void player_input_tictactoe(int* y_pos, int* x_pos){          // takes input from user (standard input) and tests if it's a valid value
    int y, x;
    printf("Type in the coordinates! (row, column)\n");
    do{
        scanf("%d %d", &y, &x);
        if((y != 1 && y != 2 && y != 3) || (x != 1 && x != 2 && x != 3)){
            printf("Out of bounds!\n");
        }
    } while((y != 1 && y != 2 && y != 3) || (x != 1 && x != 2 && x != 3));
    *y_pos = y;
    *x_pos = x;
}
int is_won_tictactoe(int board[rows][cols]){          // checks if either of the players has won or not
    int ret =

            //diagonal cases for 1

            ((board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) ||
             (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) ||

             //horizontal cases for 1

             (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) ||
             (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) ||
             (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) ||

             //vertical cases for 1

             (board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 1) ||
             (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) ||
             (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1))

            ||

            //diagonal cases for 2

            ((board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) ||
             (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) ||

             //horizontal cases for 2

             (board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2) ||
             (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2) ||
             (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2) ||

             //vertical cases for 2

             (board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 2) ||
             (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2) ||
             (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2))
            ? 1 : 0;

    return ret;
}
int is_board_full_tictactoe(int board[rows][cols]){           // checks if the board is full of values (important to check if it's a tie or not)
    int var = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(board[i][j] == 0)
                var = 0;
        }
    }
    return var;
}
void update_board_tictactoe(int board[rows][cols], const int* y_ptr, const int* x_ptr, int player, int* i){           // updates the board with the values from the user input
    if(board[*y_ptr-1][*x_ptr-1] == 0) {
        board[*y_ptr - 1][*x_ptr - 1] = player;
        *i += 1;
    }
}
int restart_tictactoe(){          // checks if the input is y or anything else
    char ans = '\0';
    scanf(" %c", &ans);
    return ans == 'y' ? 1 : 0;
}
void print_game_end_tictactoe(int board[rows][cols], int player){         // prints the winner or tie if its tie
    system("cls");
    print_logo_tictactoe();
    print_board_tictactoe(board);
    if(is_board_full_tictactoe(board) == 1 && is_won_tictactoe(board) == 0){
        printf("Tie!\n");
    } else if(is_won_tictactoe(board) == 1){
        printf("\nThe winner is player %d!\n\n", player);
    }
}
int gameplay_tictactoe(){         // handles the other functions (this is the actual main program)
    int board[rows][cols];
    system("cls");
    print_logo_tictactoe();
    if(print_introduction_tictactoe(board) == 0){
        return 0;
    }
    board_clear(board);
    print_board_tictactoe(board);
    int* i = (int*)malloc(sizeof(int));
    *i = 1;
    int player;
    while(is_won_tictactoe(board) == 0 && is_board_full_tictactoe(board) == 0){
        system("cls");
        print_logo_tictactoe();
        print_board_tictactoe(board);
        int* y_ptr = (int*)malloc(sizeof(int));
        int* x_ptr = (int*)malloc(sizeof(int));
        player = *i % 2 == 0 ? 2 : 1;
        player_input_tictactoe(y_ptr, x_ptr);
        update_board_tictactoe(board, y_ptr, x_ptr, player, i);
        free(y_ptr);
        free(x_ptr);
    }
    print_game_end_tictactoe(board, player);
    free(i);
    return 1;
}
void print_logo_tictactoe(){          // prints the logo at the start
    printf("______________________________________________________________________________________________________\n");
    printf("|    _|_|_|_|_|  _|                _|_|_|_|_|                        _|_|_|_|_|                      |\n");
    printf("|        _|            _|_|_|          _|      _|_|_|    _|_|_|          _|      _|_|      _|_|      |\n");
    printf("|        _|      _|  _|                _|    _|    _|  _|                _|    _|    _|  _|_|_|_|    |\n");
    printf("|        _|      _|  _|                _|    _|    _|  _|                _|    _|    _|  _|          |\n");
    printf("|        _|      _|    _|_|_|          _|      _|_|_|    _|_|_|          _|      _|_|      _|_|_|    |\n");
    printf("|____________________________________________________________________________________________________|\n");
    printf("\n");


}
int print_introduction_tictactoe(int board[rows][cols]){         // Prints the tutorial and introductions for the game and asks the player whether they want to start or not
    board_clear(board);
    board[1][0] = 1;
    printf("Welcome to TicTacToe!\n\n");
    printf("How to play:\nPlayers take turns putting their marks in empty squares. \nThe first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner.\n");
    printf("Player 1 is 'X' and Player 2 is 'O'\n");
    printf("The game is played with number character inputs (only inputs accepted: 1-3). \nThe first one is for the row and the second one is for the column.\n\nInput example: 2 (ENTER) 1 (ENTER):");
    print_board_tictactoe(board);
    printf("\nDo you want to start? (y/n)\n");
    if(yes_or_no_tictactoe() == 0){
        return 0;
    }
    return 1;
}
int yes_or_no_tictactoe(){           // checks if the input is y exits if it's anything else
    char ans = '\0';
    scanf(" %c", &ans);
    if(ans != 'y' && ans != 'Y'){
        system("cls");
        print_logo_tictactoe();
        return 0;
    }
    return 1;
}
int main_tictactoe() {            // main program with restart_tictactoe option and exit text
    int restart_ttt = 1;
    while(restart_ttt == 1){
        if(gameplay_tictactoe() == 0){
            goto end;
        }
        printf("Do you want to start another round? (y/n)\n");
        restart_ttt = restart_tictactoe();
    }
    system("cls");
    print_logo_tictactoe();
    end:
    printf("Press ENTER to exit to menu...\n");
    getch();
    return 0;
}


/*
 *    ▀█████████▄   ▄█          ▄████████  ▄████████    ▄█   ▄█▄      ▄█    ▄████████  ▄████████    ▄█   ▄█▄
 *      ███    ███ ███         ███    ███ ███    ███   ███ ▄███▀     ███   ███    ███ ███    ███   ███ ▄███▀
 *      ███    ███ ███         ███    ███ ███    █▀    ███▐██▀       ███   ███    ███ ███    █▀    ███▐██▀
 *     ▄███▄▄▄██▀  ███         ███    ███ ███         ▄█████▀        ███   ███    ███ ███         ▄█████▀
 *    ▀▀███▀▀▀██▄  ███       ▀███████████ ███        ▀▀█████▄        ███ ▀███████████ ███        ▀▀█████▄
 *      ███    ██▄ ███         ███    ███ ███    █▄    ███▐██▄       ███   ███    ███ ███    █▄    ███▐██▄
 *      ███    ███ ███▌    ▄   ███    ███ ███    ███   ███ ▀███▄     ███   ███    ███ ███    ███   ███ ▀███▄
 *    ▄█████████▀  █████▄▄██   ███    █▀  ████████▀    ███   ▀█▀ █▄ ▄███   ███    █▀  ████████▀    ███   ▀█▀
 *                 ▀                                   ▀         ▀▀▀▀▀▀                            ▀
 *                                          Made By: Tóth Bence
 *                                   SZTE PTI BSC 2023 Programming Basics
 */


//////////////////// DEFINE /////////////////////
#define DECK_SIZE 52
#define STARTING_BALANCE 5000

///////////////////////////////    FUNCTION DECLARATIONS    /////////////////////////////////////
int main_blackjack();
void summon_dealer(int is_concluded, int sum_hand, int* dealer, double* balance, double* bet, int* deck, int cards, int* total_won, int* total_lost, double* total_profit, double* total_wagered);
void make_deck(int* deck);
void print_array(int* deck, int cards);
int summon_player(int* deck, int* dealer, double* balance, double* bet, int* total_won, int* total_lost, double* total_profit, double* total_wagered);
int restart();
int bet_balance(double* balance, double* bet);
void print_logo();
/////////////////////////////////////////////////////////////////////////////////////////////////


// Fills upp a deck pointer with random numbers
void make_deck(int* deck){
    srand(time(0));
    for (int i = 0; i < DECK_SIZE; ++i) {
        deck[i] = rand() % 10 + 1;
    }
}

// Prints an array of cards (deck)
void print_array(int* deck, int cards){
    for (int i = 0; i < cards; ++i) {
        printf("%d ", deck[i]);
    }
}

// Prints the logo of the game
void print_logo(){
    printf("___________________________________________________________________________________________________________\n");
    printf("|                                                                                                         |\n");
    printf("|    :::::::::  :::            :::      ::::::::  :::    ::: ::::::::::: :::      ::::::::  :::    :::    |\n");
    printf("|    :+:    :+: :+:          :+: :+:   :+:    :+: :+:   :+:      :+:   :+: :+:   :+:    :+: :+:   :+:     |\n");
    printf("|    +:+    +:+ +:+         +:+   +:+  +:+        +:+  +:+       +:+  +:+   +:+  +:+        +:+  +:+      |\n");
    printf("|    +#++:++#+  +#+        +#++:++#++: +#+        +#++:++        +#+ +#++:++#++: +#+        +#++:++       |\n");
    printf("|    +#+    +#+ +#+        +#+     +#+ +#+        +#+  +#+       +#+ +#+     +#+ +#+        +#+  +#+      |\n");
    printf("|    #+#    #+# #+#        #+#     #+# #+#    #+# #+#   #+#  #+# #+# #+#     #+# #+#    #+# #+#   #+#     |\n");
    printf("|    #########  ########## ###     ###  ########  ###    ###  #####  ###     ###  ########  ###    ###    |\n");
    printf("|_________________________________________________________________________________________________________|\n");
    printf("\n");
}

// Prints the current balance and bet pointers
void print_balance(double* balance, double* bet){
    printf("Your current balance is: $%.2lf\n", *balance - *bet);
    printf("Your current bet is: $%.2lf\n\n", *bet);
}

// Creates player gameplay
int summon_player(int* deck, int* dealer, double* balance, double* bet, int* total_won, int* total_lost, double* total_profit, double* total_wagered){
    print_logo();
    int sum_hand = 0;
    int isFirstRound = 1;
    int cards = 0;
    char ans = 'y';
    int is_concluded;
    make_deck(deck);
    make_deck(dealer);
    if(bet_balance(balance, bet) == 0){
        getch();
        return 1;
    }
    while (ans == 'y'){
        start:
        system("cls");
        print_logo();
        print_balance(balance, bet);
        if(isFirstRound == 1){
            printf("Press Enter to draw a card. Good luck!\n");
            getch();
            isFirstRound = 0;
            goto start;
        }
        sum_hand += deck[cards];
        is_concluded = 0;
        cards++;
        printf("-------------------------------------\n");
        printf("Cards in your hand: ");
        print_array(deck, cards);
        printf("\nYour score: %d\n", sum_hand);
        printf("-------------------------------------\n");

        if(sum_hand > 21){
            printf("\nYou went over 21. You lost!\n\n");
            *total_wagered += *bet;
            *total_profit -= *bet;
            (*total_lost)++;
            *balance -= *bet;
            is_concluded++;
            break;
        } else if(sum_hand == 21){
            printf("\nCongratulations, you won!\n");
            printf("$%.2lf has been added to your balance!\n\n", *bet * 2);
            *total_profit += *bet;
            (*total_won)++;
            *balance += *bet;
            is_concluded++;
            break;
        }
        printf("\nDo you want to draw again? (y/n)\n");
        scanf(" %c", &ans);
        putchar('\n');
    }
    summon_dealer(is_concluded, sum_hand, dealer, balance, bet, deck, cards, total_won, total_lost, total_profit, total_wagered);
    return 0;
}

// Creates dealer gameplay if match hasn't concluded yet
void summon_dealer(int is_concluded, int sum_hand, int* dealer, double* balance, double* bet, int* deck, int cards, int* total_won, int* total_lost, double* total_profit, double* total_wagered){
    int dealer_sum_hand = 0;
    int dealer_cards = 25;
    if(is_concluded == 0){
        system("cls");
        print_logo();
        printf("-------------------------------------\n");
        printf("Cards in your hand: ");
        print_array(deck, cards);
        printf("\nYour score: %d\n", sum_hand);
        printf("-------------------------------------\n");
        printf("The Dealer's hand: ");
        while (dealer_sum_hand < sum_hand && dealer_sum_hand < 21){
            printf("%d ", dealer[dealer_cards]);
            dealer_sum_hand += dealer[dealer_cards];
            dealer_cards++;
        }
        printf("\nThe Dealer's score: %d\n", dealer_sum_hand);
        printf("-------------------------------------\n");
        if(dealer_sum_hand > 21){
            printf("\nDealer bust! You win!\n");
            printf("$%.2lf has been added to your balance!\n\n", *bet * 2);
            *total_wagered += *bet;
            *total_profit += *bet;
            (*total_won)++;
            *balance += *bet;
        } else if(dealer_sum_hand == sum_hand){
            printf("\n\nIt's a Tie!\n");
            printf("$%.2lf has been added to your balance!\n\n", *bet);
            *total_wagered += *bet;
            (*total_won)++;
        } else {
            printf("\nThe dealer won!\n\n");
            *total_wagered += *bet;
            *total_profit -= *bet;
            (*total_lost)++;
            *balance -= *bet;
        }
    }
}

// Asks the player if they want to restart
int restart(){
    char ans;
    printf("Do you want to start a new round? (y/n)\n");
    scanf(" %c", &ans);
    return ans == 'y' ? 1 : 0;
}

// Handles balance and bet also prints it
int bet_balance(double* balance, double* bet){
    if(*balance > 0){
        printf("Your current balance is: $%.2lf\n", *balance);
        printf("How much do you want to bet? ");
        do {
            scanf("%lf", bet);
            if(*bet <= 0 || *bet > *balance){
                printf("Invalid amount given. Try again: ");
            }
        } while(*bet <= 0 || *bet > *balance);
        putchar('\n');
        return 1;
    } else {
        printf("You are out of money!\n");
        return 0;
    }
}

// Main code with pointers memory allocations and freeing
int main_blackjack(){
    int* deck = (int*)malloc(sizeof(int) * DECK_SIZE);
    int* dealer = (int*) malloc(sizeof(int) * DECK_SIZE);
    double* balance = (double*)malloc(sizeof(double));
    double* bet = (double*)malloc(sizeof(double));
    double* total_profit = (double*)malloc(sizeof(double));
    double* total_wagered = (double*)malloc(sizeof(double));
    int* total_lost = (int*)malloc(sizeof(int));
    int* total_won = (int*)malloc(sizeof(int));
    *total_lost = 0;
    *total_profit = 0;
    *total_won = 0;
    *balance = STARTING_BALANCE;
    int res = 1;
    while(res == 1) {
        if(summon_player(deck, dealer, balance, bet, total_won, total_lost, total_profit, total_wagered) == 1){
            goto end;
        }
        res = restart();
        system("cls");
    }
    end:
    system("cls");
    print_logo();
    printf("Press ENTER to see the statistics...");
    getch();
    system("cls");
    print_logo();
    printf("---------------------\n");
    printf("  Player statistics: \n");
    printf("---------------------\n");
    printf("Number of rounds played: %d\n", *total_won + *total_lost);
    printf("Lost rounds throughout the game: %d\n", *total_lost);
    printf("Rounds won throughout the game: %d\n", *total_won);
    printf("Total money wagered: %.2lf\n", *total_wagered);
    printf("Final balance: %.2lf\n", *balance);
    printf("Profits made: %.2lf\n\n", *total_profit);
    free(total_wagered);
    free(total_won);
    free(total_lost);
    free(total_profit);
    free(balance);
    free(bet);
    free(dealer);
    free(deck);
    printf("Press ENTER to exit to menu...\n");
    getch();
    return 0;
}


// GameLauncher: calling games from input
int main(){
    int game;
    main_start:
    system("cls");
    printf("\n");
    printf("       ##         ##     ########  ##          ###     ######  ##    ##       ##    ###     ######  ##    ## \n");
    printf("     ####        ####    ##     ## ##         ## ##   ##    ## ##   ##        ##   ## ##   ##    ## ##   ##  \n");
    printf("       ##         ##     ##     ## ##        ##   ##  ##       ##  ##         ##  ##   ##  ##       ##  ##   \n");
    printf("       ##                ########  ##       ##     ## ##       #####          ## ##     ## ##       #####    \n");
    printf("       ##         ##     ##     ## ##       ######### ##       ##  ##   ##    ## ######### ##       ##  ##   \n");
    printf("       ##        ####    ##     ## ##       ##     ## ##    ## ##   ##  ##    ## ##     ## ##    ## ##   ##  \n");
    printf("     ######       ##     ########  ######## ##     ##  ######  ##    ##  ######  ##     ##  ######  ##    ## \n");
    printf("\n\n");
    printf("       #######      ##     ######## ####  ######  ########    ###     ######  ########  #######  ######## \n");
    printf("      ##     ##    ####       ##     ##  ##    ##    ##      ## ##   ##    ##    ##    ##     ## ##       \n");
    printf("             ##     ##        ##     ##  ##          ##     ##   ##  ##          ##    ##     ## ##       \n");
    printf("       #######                ##     ##  ##          ##    ##     ## ##          ##    ##     ## ######   \n");
    printf("      ##            ##        ##     ##  ##          ##    ######### ##          ##    ##     ## ##       \n");
    printf("      ##           ####       ##     ##  ##    ##    ##    ##     ## ##    ##    ##    ##     ## ##       \n");
    printf("      #########     ##        ##    ####  ######     ##    ##     ##  ######     ##     #######  ######## \n");
    printf("\n\n");
    printf("                                 #######      ##     ######## ##     ## #### ######## \n");
    printf("                                ##     ##    ####    ##        ##   ##   ##     ##    \n");
    printf("                                       ##     ##     ##         ## ##    ##     ##    \n");
    printf("                                 #######             ######      ###     ##     ##    \n");
    printf("                                       ##     ##     ##         ## ##    ##     ##    \n");
    printf("                                ##     ##    ####    ##        ##   ##   ##     ##    \n");
    printf("                                 #######      ##     ######## ##     ## ####    ##    \n");
    printf("\n\n                                      Welcome to the console game launcher!\n"
           "                                            Choose the game(1-2-3): ");
    scanf("%d", &game);
    if(game == 1){
        system("cls");
        main_blackjack();
        goto main_start;
    } else if(game == 2){
        system("cls");
        main_tictactoe();
        goto main_start;
    }
    system("cls");
    printf("Press any key to exit...");
    getch();
    return 0;
}