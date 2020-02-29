#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <limits>
using std::numeric_limits;
using std::streamsize;

#include <string>
using std::string;

#include <ctime>

void ClearScreen()
{
    for(int n = 0; n < 50; n++)
    {
        cout << "\n";
    }
}

void PressEnterTo(string str)
{
    cout << "\n\nPress ENTER to " << str << "..." ;
    cin.clear();
    cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
    ClearScreen();
}

void PressEnterContinue()
{
    PressEnterTo("continue");
}

void PrintHistory()
{
    ClearScreen();

    cout << "The year is 9Cx5.\n" <<
            "You are an archaeologist and you found a relic from a past civilization.\n" <<
            "This relic is a strange machine with an archaic digital structure, where you can " <<
            "find a keyboard with 9 keys and a display.\n" <<
            "Miraculously after running this device through you recovery tool and after making "
            "few modifications on the alimentation system the relic started working.\n" <<
            "It apears that the code inside was still intact!";
    PressEnterContinue();

    cout << "The screen diplayed some words that you could not understand, " <<
            "therefore you headed to the language department of the local university that you work in.\n" <<
            "There you found Dr. Wheasley, he is an expert on ancient languages.\n" <<
            "He was very happy with the relic that you brought, the writings were indeed quite unique, making him puzzled with them.\n" <<
            "He asked if could you would wait some time util he coould be able to translante the text, he would " <<
            "contact you once this was done.\n" <<
            "Of course you acepted it and now were more anxious then never thinking about what this device would turn out to be.";
    PressEnterContinue();
    
    cout << "Few weeks had passed when Dr. Wheasley contacted you.\n" <<
            "The language used on the device was from the Sylicon Period of the Cristian Era that " <<
            "happened thounsands of years in the past,\n" <<
            "most likely beeing from the late 20th or early 21th century of that era, the begining of the Sylicon Period.\n" <<
            "The language was know as english and was of the most common in its time.";
    PressEnterContinue();

    cout << "Not surprisingly you have never heard about this language before.\n" <<
            "But this information was amasing, this device was probably one of the first of it kind " <<
            "made by an ancient civilization that was not well known in the modern world.\n" <<
            "Now you could start to tell the history of a lost period of time, and this was truly exiting!";
    PressEnterContinue();

    cout << "You were now able to use your Universal Translator Tool (UTT) which was not possible before.\n" <<
            "The UTT auto translation function runs wild with ancient languages and you had to count on luck to " <<
            "get the corret translation with it.\n" <<
            "It was frustrating but could not be helped.\n" <<
            "But now, by knowing the language and the period, you could set the UTT and it would give you the correct translation.\n" <<
            "You thank Dr. Wheasley and go on to your office to find out what mysteries were hidden within the relic.";
    PressEnterContinue();

    cout << "You were dazzled by what you found.\n"
            "Such an archaic machine was in fact a game!\n"
            "It was a simple math game where you were suposed solve a problem displayed on the screen.\n"
            "By typing the correct answer you would advance in level where the dificulty of the problem would increase with it.\n"
            "And after ten levels the game would finish...";
            PressEnterContinue();
}

bool PlayGame(int Dificulty)
{

    int CodeA = rand() % Dificulty + Dificulty;
    int CodeB = rand() % Dificulty + Dificulty;
    int CodeC = rand() % Dificulty + Dificulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    cout << "Level: " << Dificulty << endl;
    cout << "- There are 3 Natural numbers such as:\n";
    cout << "\t+ Their sum is: " << CodeSum << endl;
    cout << "\t+ Their protuct is: " << CodeProduct << endl;

    int PlayerGuessA, PlayerGuessB, PlayerGuessC;

    cout << endl;
    cout << "Enter your guess: ";
    cin >> PlayerGuessA;
    cin >> PlayerGuessB;
    cin >> PlayerGuessC;
    cin.clear();
    cin.ignore();
    
    int GuessSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    int GuessProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

    ClearScreen();
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\n\nCongratulations, you've input the correct numbers =D\n\n";
        PressEnterContinue();
        return true;
    } else
    {
        cout << "\n\nUnfortunately these number do not satisfy the condicions above D=\n\n";
        PressEnterContinue();
        return false;
    }
}

void MainLoop() {
    srand(time(NULL));

    int LevelDificulty = 1;
    const int MaxDificulty = 10;

    while (LevelDificulty <= MaxDificulty)
    {
        bool bLevelComplete = PlayGame(LevelDificulty);
        
        if (bLevelComplete)
        {
            ++LevelDificulty;
        }
        
    }

}

void Ending()
{
    ClearScreen();
    cout << "You found your self playing the game for a while now.\n" <<
            "You came back to yourself and realized that you have to go back to work!";
}

void Farwell()
{
    ClearScreen();
    cout << "+ Written and developed by @ffemdeiros2\n";
    cout << "+ This work was done as an exercise to the course: Unreal Engine C++ Developer: Learn C++ and Make Video Games\n\n";
    cout << "Thank you for playing this little game, hope you enjoyed it =D\n\n";
    cout << "     ***********                  ***********\n" <<
            "  *****************            *****************\n" <<
            " *********************        *********************\n" <<
            " ***********************      ***********************\n" <<
            " ************************    ************************\n" <<
            " *************************  *************************\n" <<
            "  **************************************************\n" <<
            "   ************************************************\n" <<
            "     ********************************************\n" <<
            "       ****************************************\n" <<
            "          **********************************\n" <<
            "            ******************************\n" <<
            "               ************************\n" <<
            "                 ********************\n" <<
            "                    **************\n" <<
            "                      **********\n" <<
            "                        ******\n" <<
            "                          **\n";
    PressEnterTo("exit");
    ClearScreen();
}

int main()
{
    PrintHistory();
    MainLoop();
    Ending();
    Farwell();

    return 0;
}