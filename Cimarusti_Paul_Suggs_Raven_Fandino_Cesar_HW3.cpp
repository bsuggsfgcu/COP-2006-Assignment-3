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


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
