#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define size 4
int field[size][size];//to store the game field
int score=0;//to store current score
int highScore;//to store high score

//functions declarations
void makeFeild();//initialize field with 0
void printField();//print the field
void gameLoop(char input);//game logic based on input
void goUp();//move up
void goDown();//move down
void goLeft();//move left
void goRight();//move right
void generateRandom();//generate a random 2 in empty cell
void clearScreen();//clear console screen
void titleScreen();
void scoreCounter();//calculate score
void checkGameOver();//check if game over(no more moves or 2048 reached)
void inpLoop();//main input loop/game loop
void loadHighScore();//load high score from file at the start of the game

void loadHighScore(){//load high score from file
    FILE *fptr;
    fptr = fopen("scores.txt", "r");
    if(fptr == NULL) {
        highScore = 0;
        return;                        
    }
    fscanf(fptr, "%d", &highScore);
    fclose(fptr);
}

void makeFeild(){//initialize field with 0
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            field[i][j]=0;
        }
    }
}

void printField(){//print the field
    scoreCounter();//update score
    if(score>highScore){
        highScore=score;
    }
    printf("Score: %d\t\t High score:%d\n", score, highScore);//print current score and high score
    for(int i=0;i<size;i++){
        printf("|   ");
        for(int j=0;j<size;j++){
            if(field[i][j]==0){
                printf("#       ");
            }
            else
            printf("%-5d   ",field[i][j]);//%-5 forces the field to be 5 characters wide, left aligned
        }
        printf("|\n");
    }
}
void inpLoop(){
    char input;
    while(1){
        if(_kbhit){//if a key is pressed
            input=_getch();//get input without enter
            checkGameOver();
            if(input=='w' || input=='a' || input=='s' || input=='d' || input=='8'||input=='4'||input=='2'||input=='6'){
                gameLoop(input);
            }
            else if(input==27){//ESC key to exit
                exit(0);
            }
            
        }
    }
}
void gameLoop(char input){//game logic based on input
    if(input=='w'|| input=='8' ){
        goUp();
    }
    else if(input=='s'||input=='2'){
        goDown();
    }
    else if(input=='a'||input=='4'){
        goLeft();
    }
    else if(input=='d'||input=='6'){
        goRight();
    }
    else{
        printf("Invalid input\n");
        return;
    }
    clearScreen();
    generateRandom();
    printField();
}

void goUp(){//move up
    for(int i=size-1;i>0;i--){
        for(int j=0;j<size;j++){
            if(field[i][j]!=0){
                if(field[i-1][j]==0){
                    field[i-1][j]=field[i][j];
                    field[i][j]=0;
                }
                else if (field[i-1][j]==field[i][j]){
                    field[i-1][j]=field[i-1][j]*2;
                    field[i][j]=0;
                }

            }
        }
    }
}
void goDown(){//move down
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size;j++){
            if(field[i][j]!=0){
                if(field[i+1][j]==0){
                    field[i+1][j]=field[i][j];
                    field[i][j]=0;
                }
                else if (field[i+1][j]==field[i][j]){
                    field[i+1][j]=field[i+1][j]*2;
                    field[i][j]=0;
                }
            }
        }
    }
}
void goLeft(){//move left
    for(int j=size-1;j>0;j--){
        for(int i=0;i<size;i++){
            if(field[i][j]!=0){
                if(field[i][j-1]==0){
                    field[i][j-1]=field[i][j];
                    field[i][j]=0;
                }
                else if (field[i][j-1]==field[i][j]){
                    field[i][j-1]=field[i][j-1]*2;
                    field[i][j]=0;
                }
            }
        }
    }
}
void goRight(){//move right
    for(int j=0;j<size-1;j++){
        for(int i=0;i<size;i++){
            if(field[i][j]!=0){
                if(field[i][j+1]==0){
                    field[i][j+1]=field[i][j];
                    field[i][j]=0;
                }
                else if (field[i][j+1]==field[i][j]){
                    field[i][j+1]=field[i][j+1]*2;
                    field[i][j]=0;
                }
            }
        }
    }
}

void generateRandom(){//generate a random 2 in empty cell
    int x=rand()%size;
    int y=rand()%size;
    while (field[x][y]!=0){//check if cell is empty
        x=rand()%size;
        y=rand()%size;
    }
    field[x][y]=2;
}
void clearScreen() {
    system("cls");//clear console screen
     
}
void scoreCounter(){//calculate score
    score=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            score+=field[i][j];//score is sum of all the numbers in field
        }
    }
}

void titleScreen(){//display title screen
    char c;
    printf("Welcome to 2048!\n");
    printf("Use W A S D to move the tiles up, left, down, and right respectively.\n");
    printf("Combine tiles with the same number to create larger numbers and reach 2048!\n");
    printf("Press ESC to exit the game at any time.\n");
    printf("Press enter key to start the game...\n");
    while(1){
        if(_kbhit)
            c=_getch();
            if(c==27){//ESC key to exit
                exit(0);
            }
            else if(c==EOF || c==13 ){//Enter key to start
                clearScreen();
                return;
            }
    }
}
void checkGameOver(){
    int gameOver=1;
    for(int i=0;i<size;i++){//check for possible moves
        for(int j=0;j<size;j++){
            if(field[i][j]==0){
                gameOver=0;
            }
            if(i<size-1 && field[i][j]==field[i+1][j]){
                gameOver=0;
            }
            if(j<size-1 && field[i][j]==field[i][j+1]){
                gameOver=0;
            }
        }
    }
    if(score>2048){//check if 2048 is reached
        printf("Congratulations! You've reached 2048!\n");
        gameOver=1;//end the game
    }
    if(gameOver){//if no moves left or 2048 reached
        int one=1;
        FILE *fptr;
        fptr = fopen("scores.txt", "w");
        if(fptr == NULL) {
            printf("Error opening file!\n");                        
        }
        fprintf(fptr, "%d", highScore);//save high score to file
        fclose(fptr);
        clearScreen();
        printField();
        printf("Game Over! Your final score is: %d\n", score);
        printf("Press any Esc to exit...\n");
        printf("Press R to restart...\n");
        while (1){
            if(_kbhit){
                char c=_getch();
                if(c==27){//ESC key to exit
                    exit(0);
                }
                else if(c=='r' || c=='R'){//restart game
                    clearScreen();
                    score=0;
                    makeFeild();
                    generateRandom();
                    printField();
                    return;
                }
            }
        }
        

    }

}
void main() {
    loadHighScore();//load high score from file
    titleScreen();//display title screen
    srand(time(0));//seed for random number generation
    makeFeild();//make elements of field 0
    generateRandom();//genetate random position and put 2 there
    printField();//prints the field
    inpLoop();//main game loop
    
}