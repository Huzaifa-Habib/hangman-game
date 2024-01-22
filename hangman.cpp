#include <graphics.h>
#include <string.h>
#include<conio.h>

void secondGuess(void);
void guess(char[], char[], char[]);
void hangman(int);
void menu(void);
void gameOverScreen(void);
void displayGuessedCharacters(char[]);

void hangman(int lives)
{
    // Base
    setcolor(WHITE);
    line(100, 400, 500, 400);

    // Vertical pole
    setcolor(WHITE);
    line(300, 400, 300, 100);

    // Horizontal beam
    setcolor(WHITE);
    line(300, 100, 400, 100);

    // Rope
    if (lives == 1)
    {
        setcolor(WHITE);
        line(400, 100, 400, 150);
    }

    // Head
    if (lives == 2)
    {
        setcolor(WHITE);
        circle(400, 175, 25);
    }

    // Body
    if (lives == 3)
    {
        setcolor(WHITE);
        line(400, 200, 400, 300);
    }

    // Left arm
    if (lives == 4)
    {
        setcolor(WHITE);
        line(400, 225, 350, 250);
    }

    // Right arm
    if (lives == 5)
    {
        setcolor(WHITE);
        line(400, 225, 450, 250);
    }

    // Left leg
    if (lives == 6)
    {
        setcolor(WHITE);
        line(400, 300, 350, 350);
    }

    // Right leg
    if (lives == 7)
    {
        setcolor(WHITE);
        line(400, 300, 450, 350);
    }
}

void menu()
{
    char gameName[50] = "HANGMAN";
    setcolor(RED);
    settextstyle(10, HORIZ_DIR, 10);
    outtextxy(500, 100, gameName);

    char gameInstruction[50] = "Press Enter To play!";
    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(520, 220, gameInstruction);

    char gameInstruction1[50] = "Press ESC To Quit!";
    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(520, 250, gameInstruction1);
}

void gameOverScreen()
{
    char gameOver[50] = "GAME OVER!";
    char playAgain[100] = "Press Enter To play again";
    char backToMenu[100] = "Press Esc to exist game!";
    setcolor(RED);
    settextstyle(10, HORIZ_DIR, 10);
    outtextxy(500, 100, gameOver);

    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(520, 220, playAgain);

    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(520, 250, backToMenu);
	char userInput = getch();
    if (userInput == 13)
    {
        cleardevice();
        guess("GUESS THE FIRST WORD", "Hint: It's a four leg animal", "DOG");
    }

    if (userInput == 27)
    {
    	cleardevice();
        closegraph();
    }
}

void displayGuessedCharacters(char correctWords[])
{

    settextstyle(10, HORIZ_DIR, 4);
    setcolor(WHITE);
    outtextxy(700, 200, correctWords);
}

void guess(char questionHead[], char hint[], char guessWord[]) //take three input question,hint and word to be guess.
{
    // For Question Text
    hangman(0);
    setcolor(BLUE);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(650, 100, questionHead);

    // For Hint Text
    setcolor(GREEN);
    settextstyle(10, HORIZ_DIR, 2);
    outtextxy(650, 150, hint);

    int lives = 0; //initallize lives with 0
    char userInput; // used for to take character of user and store in this variable
    int guessWordLength = strlen(guessWord); //strlen() to get the length of string which is to be guess.
    char tempWord[guessWordLength + 1]; // here we plus 1 to actuall size to implement null character for loop to know that string 1 is comleted
    									//and we make tempWord[] to repalce each characters with dash 

    // Initialize tempWord with dashes
    for (int count = 0; count < guessWordLength; count++)
    {
        tempWord[count] = '-';
    }
    tempWord[guessWordLength] = '\0'; // Null to terminate the string

    while (1) // infinite loop until it breaks
    {
        userInput = getch(); //get each characters from user
        int correctGuess = 0; //initiallize var to 0 to know whether the guess character is right or not.

        for (int i = 0; i < guessWordLength; i++) //we run loop till the size of guess string or word.
        {
            if (toupper(userInput) == guessWord[i]) //toupper() make all the char enter by user to uppercase and match with the char of guessWord string.
            {
                tempWord[i] = guessWord[i]; //if match we replace each dash with the correct character.
                correctGuess = 1; //we initallize counter to 1 for each correct guess
            }
        }

        displayGuessedCharacters(tempWord); // pass the correct string which is guess by user and its length as inputs.

        if (correctGuess == 0) // if its 0 it means the guess char is wrong so he lost his one live
        {
            lives++;
            hangman(lives);
        }

        // Check if the entire word or string is guessed
        if (strcmp(guessWord, tempWord) == 0)
        {
            break;
        }

        if (lives >= 7)
        {
            cleardevice();
            gameOverScreen();
            break;
        }
    }
}

main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    initwindow(getmaxwidth(), getmaxheight());

    menu();
    char userInput = getch();

    if (userInput == 13)
    {
        cleardevice();
        hangman(0);

        // First Question
        guess("GUESS THE FIRST WORD", "Hint: It's a four leg animal", "DOG");
        delay(500);
        cleardevice();

        // Second Question
        guess("GUESS THE SECOND WORD", "Hint: It's an animal often used for riding", "HORSE");
        delay(500);
        cleardevice();

        // Third Question
        guess("GUESS THE THIRD WORD", "Hint: It's an object often used for drawing", "PENCIL");
        delay(500);
        cleardevice();
        
         // Fourth Question
        guess("GUESS THE FOURTH WORD", "Hint: It's a fruit, Orange and juicy", "ORANGE");
        delay(500);
        cleardevice();
        
        // Fifth Question
        guess("GUESS THE EIGHTH WORD", "Hint: It's a musical instrument with black and white keys", "PIANO");
        delay(500);
        cleardevice();
        
    }
    
    else if (userInput != 27)
    {
        menu();    
	}
    
    else
    {
    	closegraph();
      
    }
}

