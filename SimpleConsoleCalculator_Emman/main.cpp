#include <iostream>
#include <conio.h>
#include <limits>

using namespace std;
void restart();
void add();
void subtract();
void multiply();
void divide();


//number input only
double getNumericInput(const std::string& prompt) {
    double input;
    bool validInput = false;

    while (!validInput) {
        std::cout << prompt;

        if (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Number only. \n";
        } else {
            validInput = true;
        }
    }

    return input;
}


//letter input only
std::string getLetterInput(const std::string& prompt) {
    std::string input;
    bool validInput = false;

    while (!validInput) {
        std::cout << prompt;
        std::cin >> input;

        bool containsNonLetter = false;
        for (char c : input) {
            if (!std::isalpha(c)) {
                containsNonLetter = true;
                break;
            }
        }

        if (containsNonLetter) {
            std::cout << "\nInvalid input. Letter only. \n";
        } else {
            validInput = true;
        }
    }

    return input;
}



void calculator_choose() {

    char choose;
    cout << "-==WELCOME TO CALCULATOR PROGRAM==-" << endl;
    printf("\n[A] Addition");
    printf("\n[B] Subtruction");
    printf("\n[C] Multiplication");
    printf("\n[D] Division");
    printf("\nENTER YOUR CHOICE [A-D]: ");
    scanf(" %c", &choose);

    switch(choose) {

    case 'a' :
    case 'A' :
        add();
        break;

    case 'b' :
    case 'B' :
        subtract();
        break;

    case 'c' :
    case 'C' :
        multiply();
        break;

    case 'd' :
    case 'D' :
        divide();
        break;

    default :
        printf("\nInvalid input!\n ");
        calculator_choose();
    }

    //after computing from voids, the command will go to restart(); void
    restart();
}


//add
void add() {

    double numOne, numTwo;
    double result;

    cout<<"\n[+] ADDITION CALCULATOR\n";

    //get data
    numOne = getNumericInput("\nEnter the First Number: ");
    numTwo = getNumericInput("Enter the Second Number: ");

    result = numOne+numTwo;
    cout<<"Result = "<<result;
    cout<<"\n\n";
}


//minus
void subtract() {

    double numOne, numTwo;
    double result;

    //get data
    numOne = getNumericInput("\nEnter the First Number: ");
    numTwo = getNumericInput("Enter the Second Number: ");

    result = numOne-numTwo;
    cout<<"Result = "<<result;
    cout<<"\n\n";
}


//multiply
void multiply() {

    double numOne, numTwo;
    double result;

    cout<<"\n[X] MULTIPLICATION CALCULATOR\n";

    //get data
    numOne = getNumericInput("\nEnter the First Number: ");
    numTwo = getNumericInput("Enter the Second Number: ");

    result = numOne*numTwo;
    cout<<"Result = "<<result;
    cout<<"\n\n";
}


//divide
void divide() {

    double numOne, numTwo;
    double result;

    cout<<"\n[/]DIVISION CALCULATOR\n";

    //get data
    numOne = getNumericInput("\nEnter the First Number: ");
    numTwo = getNumericInput("Enter the Second Number: ");

    result = numOne/numTwo;
    cout<<"Result = "<<result;
    cout<<"\n\n";
}


//restart
void restart() {

    char start;

    cout << "Do You Want to Continue? [Y/N]: ";
    cin>> start;
    cout << "\n";

    if(std::tolower(start) == 'y') {
        system("cls"); //clear console screeen
        calculator_choose(); //go to main void

    } else if (std::tolower(start) == 'n') {
        cout << "Bye!" << endl;
        exit(0);

    } else {
        restart();
    }
}


//main start
int main() {
    calculator_choose();
}


//THIS CONSOLE PROGRAM IS TESTED ON CODEBLOCKS IDE
//Copyright 2021 emmanpbarrameda