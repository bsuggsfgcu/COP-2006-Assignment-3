// Coder/Developer: Paul Cimarusti, Cesar Fandino, & Raven Suggs
// Class:           COP 2006-80599, Fall 2024
// Date:            October 24, 2024
// Description:     C++ Program to generate an amortization table based on given parameters
// Log:             October 24, 2024, Project file created, basic input validation and amortization algorithm completed
//                  October 25, 2024, Added code header
#include <iostream>

//Validate user input for floats
float GetFloat()
{
    //Loop forever, until the function returns valid input
    while(true)
    {
        //String to hold user input
        std::string input;
        std::cin >> input;
        int decimal_counter = 0;
        bool invalidInLoop = false;
        if(input.empty())
        {
            //Restarts loop to take new input if user somehow entered an empty string
            std::cout << "Invalid input, try again." << std::endl;
            continue;
        }
        for(int i = 0; i < input.length(); i++)
        {
            //If character at index i is not a number then this runs
            if(!std::isdigit(input[i]))
            {
                if(input[i] == '.')
                {
                    decimal_counter++;
                    if(decimal_counter > 1)
                    {
                        //If there are too many decimal places, then the input is marked invalid
                        invalidInLoop = true;
                        break;
                    }
                }
                else
                {
                    invalidInLoop = true;
                    break;
                }
            }
        }
        if(invalidInLoop)
        {
            //Since we cannot use continue in the for loop above, using bool to delay it until we leave the loop
            std::cout << "Invalid input, try again." << std::endl;
            continue;
        }

        //Since function did not restart at this point, input is valid and returned
        return atof(input.c_str());
    }
}

//Logic from given flowchart
//Principle is a pointer since it changes while rate and payment are constant
void Amortization(float *principle, float interestRate, float payment)
{
    while(*principle > 0)
    {
        //Must first pay off interest first (a % of principle)
        //Divide interestRate / 100 to get from % to decimal and by 12 to convert from yearly interest to monthly interest
        float interestPaid = *principle * (interestRate / 100 / 12);
        //Then the rest of the payment goes to principle
        float principlePaid = payment - interestPaid;

        if(interestPaid > payment)
        {
            std::cout << "Monthly payment too low to keep up with interest, " << std::endl;
            std::cout << "Payment must be greater than " << interestPaid << " for this interest rate and principle." << std::endl;
            break;
        }

        if(principlePaid > *principle)
        {
            //To stop the payment from overflowing past the principle
            principlePaid = *principle;
        }
        //Prints a line for the amortization schedule
        std::cout << *principle << " " << interestPaid << " " << principlePaid << " " << payment << " " << *principle - principlePaid << std::endl ;
        *principle = *principle - principlePaid;
    }
}

int main()
{
    float principle;
    float interestRate;
    float payment;

    std::cout << "Enter Principle: " << std::endl;
    principle = GetFloat();
    std::cout << "Enter Interest Rate (in percent %):" << std::endl;
    interestRate = GetFloat();
    std::cout << "Enter Monthly Payment: " << std::endl;
    payment = GetFloat();

    Amortization(&principle, interestRate, payment);
    
    return 0;
}
