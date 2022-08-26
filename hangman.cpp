//build a little hangman game

/*the initial hangman will look like:

|----|
|    |
|    O
|   /|\
|   / \

*/

//V1: the user inputs the word and gets 5 guesses

//V2: bug fixes, ask the user to choose a category and randomly select a word from the chosen category

//V3 (to be done): add hints and make a std::map for categories

//--------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//hangman function: to display the hangman

void hangman(int tries)
{
    std::cout<<"|----| \n";
    std::cout<<"|    | \n";
    std::cout<<"|    O \n";

    //first three lines are constant, always there regardless of number of tries left

    //4th line

    std::cout<<"|   ";

    if(tries > 0)
    {
        std::cout<<"/";
    }
    if(tries > 1)
    {
        std::cout<<"|";
    }
    if(tries > 2)
    {
        std::cout<<"\\ \n";
    }
    else
    {
        std::cout<<"\n";
    }

    //5th line

    std::cout<<"|   ";

    if(tries > 3)
    {
        std::cout<<"/";
    }
    if(tries > 4)
    {
        std::cout<<" \\ \n";
    }
    else
    {
        std::cout<<"\n";
    }

}

std::vector<std::string> categories = {"Animals", "Flowers", "Zodiac", "Months"};

int main()
{
    srand(time(NULL)); //initialise random seed

    std::cout<<"Greetings, user! Welcome to this game of Hangman! Type the number corresponding to one of the categories below to start. \n \n";

    for(int i{0}; i < categories.size(); i++)
    {
        std::cout<<i+1 <<". " <<categories[i] <<"\n";
    }
    std::cout<<"\n";


    std::cout<<"Enter your number: ";
    int category_number; //the category number from the list
    std::cin>>category_number;

    std::vector<std::string> category; //the category chosen

    switch(category_number)
    {
        case 1: //animals
            category = {"dog", "cat", "pig", "cow", "crocodile", "tiger"};
            break;

        case 2: //flowers
            category = {"rose", "tulip", "daisy", "dandelion", "orchid"};
            break;

        case 3: //zodiac
            category = {"aquarius", "virgo", "capricorn", "leo", "taurus", "aries", "gemini", "pisces", "libra"};
            break;

        case 4: //months
            category = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
            break;

        default:
            std::cout<<"Invalid number. Please try again.";
    }

    std::cout<<"\n" <<"You have chosen the category: " <<categories[category_number-1] <<"\n \n"; //-1 because in the list, the categories start from 1 vs the vector index starts from 0

    int random = rand() % (category.size()-1); //pick a random number 
    
    std::string word = category[random];

    std::string guessed_string;

    for(int i{0}; i < word.length(); i++)
    {
        guessed_string.push_back('_');
    }

    /*std::vector<char> word_letters;
    for(int i{0}; i < word.length(); i++)
    {
        if(std::find(word_letters.begin(), word_letters.end(), word[i]) == word_letters.end())
            {
                word_letters.push_back(word[i]);
            }       
    }*/

    //greet the user

    std::cout<<"Hello, user! Welcome to this game of Hangman! You get a word and you have to guess the word, one letter at a time. You can make upto 5 wrong guesses. For each wrong guess, you (see below) lose a part of your body, till you have only your head left (at which point, you're dead). \n \n";
    std::cout<<"This is you now: \n \n";

    int tries{5}; //initialise tries = 5 ie 5 tries left

    bool solved = false;

    while(tries > 0 && solved == false)
    {
        //print the man

        hangman(tries);

        //the word

        std::cout<<"\n" <<"Guess the word: ";

        //print the letters so far

        std::cout<<guessed_string;
        
        std::cout<<" (you have " <<tries <<" tries left)" <<"\n \n";

        std::cout<<"Enter a letter: ";

        char ch; //this is the char the user inputs
        std::cin>>ch;

        std::cout<<"\n";

        int index{};

        bool correct_letter = false;

        for(index = 0; index < word.length(); index++)
        {
            if(ch == word[index])
            {
                guessed_string[index] = ch;
                correct_letter = true;
            }
        }

        if(correct_letter == false)
        {
            tries--;
        }


        if(word == guessed_string)
        {
            solved = true;
        }

    }

    if(solved == true)
    {
        std::cout<<"Congratulations! You won! The word was " <<word <<".";
    }

    else
    {
        hangman(0);
        std::cout<<"Game over! You died. The word was " <<word <<".";
    }  

    return 0;
}