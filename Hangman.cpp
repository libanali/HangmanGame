#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>



using namespace std;

const int Maximum_Tries = 6;

int LetterFill (char, string, string&);

int main()
{

    string name;
    char letter;
    int nnumber_of_wrong_guesses = 0;
    string word;
    string words[] =
    {
        "Goku", "Vegeta", "Krillin", "Piccolo", "Gohan", "Trunks", "Goten", "Tien", "Yamcha", "Chiaotzu", "Master Roshi"
    };

    srand(time(NULL));
    int n=rand()% 10;
    word = words[n];

    string unknown(word.length(), '*');


    cout << "\n\n\t-Hangman- Guess the Z-Fighter!";
    cout << "\n\nIn order to win, all you have to do is guess the word correctly";
    cout << "\n\nYou can only type one letter per try";
    cout << "\n\nYou have " <<Maximum_Tries<< "tries to guess the word";


    while (nnumber_of_wrong_guesses < Maximum_Tries)
    {
        cout << "\n\n" << unknown;
        cout << "\n\nGuess a letter: ";
        cin >> letter;

        if(LetterFill(letter, word, unknown)==0)
        {
            cout << endl << "Uh Oh! This letter isn't in here" << endl;
            nnumber_of_wrong_guesses++;
        }
        else
        {
            cout << endl << "WOOHOO! You got it right!" << endl;
        }
 
// informing the player how many guesses they have left

        cout << "You have " << Maximum_Tries - nnumber_of_wrong_guesses;
        cout << " guesses left." << endl;

        if(word==unknown)
        {
            cout << word << endl;
            cout << "Congrats! You got it!";
            break;
        }

    }

//if player reaches maximum number of wrong guesses, then it will be game over 
    if(nnumber_of_wrong_guesses == Maximum_Tries)
    {

        cout << "\n Sorry, better luck next time!" << endl;
        cout << "The word was : " << word << endl;

    }
    
    cin.ignore();
    cin.get();
    return 0;

}


int LetterFill (char guess, string secretword, string &guessword) 
{
    int i;
    int mathces=0;
    int len = secretword.length();
    for (i = 0; i< len; i++)
    {


        if (guess == guessword[i])
        return 0;

        if(guess == secretword[i])
        {

            guessword[i] = guess;
            mathces++;
        }
    }

    return mathces;
}