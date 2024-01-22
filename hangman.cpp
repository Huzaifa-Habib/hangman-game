#include <graphics.h>
#include <string.h>

void secondGuess(void);
void firstGuess(char[], char[], char[]);
void hangman(int);
void menu();
void gameOverScreen();
void displayGuessedCharacters(char[], int);

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
    char backToMenu[100] = "Press Esc Key to go back to menu";
    setcolor(RED);
    settextstyle(10, HORIZ_DIR, 10);
    outtextxy(500, 100, gameOver);

    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(520, 220, playAgain);

    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 3);
    outtextxy(520, 250, backToMenu);

    if (getch() == 13)
    {
        cleardevice();
        menu();
    }

    if (getch() == 27)
    {
        cleardevice();
        menu();
    }
}

void displayGuessedCharacters(char correctWords[], int size)
{
    int xCoordinate = 700;
    char displayString[100];

    settextstyle(10, HORIZ_DIR, 4);
    setcolor(WHITE);

    for (int j = 0; j < size; j++)
    {
        if (correctWords[j] != '-')
        {
            displayString[j] = correctWords[j];
        }
        else
        {
            displayString[j] = '-';
        }
    }

    displayString[size] = '\0';
    outtextxy(xCoordinate, 200, displayString);
}

void guess(char questionHead[], char hint[], char guessWord[])
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

    int lives = 0;
    char userInput;
    int guessWordLength = strlen(guessWord);
    char tempWord[guessWordLength + 1];

    // Initialize tempWord with dashes
    for (int count = 0; count < guessWordLength; count++)
    {
        tempWord[count] = '-';
    }
    tempWord[guessWordLength] = '\0'; // Null-terminate the string

    while (1)
    {
        userInput = getch();
        int correctGuess = 0;

        for (int i = 0; i < guessWordLength; i++)
        {
            if (toupper(userInput) == guessWord[i])
            {
                tempWord[i] = guessWord[i];
                correctGuess = 1;
            }
        }

        displayGuessedCharacters(tempWord, guessWordLength);

        if (correctGuess == 0)
        {
            lives++;
            hangman(lives);
        }

        // Check if the entire word is guessed
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

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    initwindow(getmaxwidth(), getmaxheight());

    menu();

    if (getch() == 13)
    {
        cleardevice();
        hangman(0);

        // First Question
        guess("GUESS THE FIRST WORD", "Hint: It's a four leg animal", "DOG");
        delay(1000);
        cleardevice();

        // Second Question
        guess("GUESS THE SECOND WORD", "Hint: It's an animal often used for riding", "HORSE");
        delay(1000);
        cleardevice();

        // Third Question
        guess("GUESS THE THIRD WORD", "Hint: It's an object often used for drawing", "PENCIL");
        delay(1000);
        cleardevice();

        if (getch() == 27)
        {
            closegraph();
        }
    }

    return 0;
}

