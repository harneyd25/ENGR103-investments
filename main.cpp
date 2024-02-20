/* Author: David Harney harneyd25@oregonstate.edu
   Description: Prompts user for available funds, APY values for HYSA, index funds, and I bonds,
   max insured amount for HYSA, and calculates how to invest for maximum profit, prints this strategy
   to terminal, and prints expected one year profit
*/

#include <iostream>


// Function: investment_funds_prompt
// Description: prompts user for available investment funds, stores as int
// Returns: int
int investment_funds_prompt(){
    std::cout << "Enter your available investment funds in dollars as a whole number): " << std::endl;
    int investment_funds;
    std::cin >> investment_funds;
    return investment_funds;
}

// Function: HYSA_APY_prompt
// Description: gets HYSA APY from user. If negative value entered, will print error and default to 4%
// Returns: double
double HYSA_APY_prompt(){
    std::cout << "Enter your HYSA APY as a number between 0 and 100" << std::endl;
    double HYSA_APY;
    std::cin >> HYSA_APY;
    if (HYSA_APY < 0){
        std::cout << "Error: negative value entered. Default of 4% will be used" << std::endl;
        HYSA_APY = 4;
    }
    return HYSA_APY;
}

// Function: HYSA_insurance_max_prompt
// Description: gets HYSA FDIC insurance max rom user. If negative value entered, will print error and default to $250,000
// Returns: int
int HYSA_insurance_max_prompt(){
    std::cout << "Enter the maximum dollar amount insured by your HYSA as a whole number" << std::endl;
    int HYSA_insur_max;
    std::cin >> HYSA_insur_max;
    if (HYSA_insur_max < 0){
        std::cout << "Error: negative value entered. Default of $250,000 will be used" << std::endl;
        HYSA_insur_max = 250000;
    }
    return HYSA_insur_max;
}

// Function: ibond_APY_prompt
// Description: gets I bond APY from user. If negative value entered, will print error and default to 6%
// Returns: double
double ibond_APY_prompt(){
    std::cout << "Enter your I bond APY  as a number between 0 and 100" << std::endl;
    double ibond_APY;
    std::cin >> ibond_APY;
    if (ibond_APY < 0){
        std::cout << "Error: negative value entered. Default of 6% will be used" << std::endl;
        ibond_APY = 6;
    }
    return ibond_APY;
}

// Function: index_fund_APY_prompt
// Description: gets index fund APY from user. If negative value entered, will print error and default to 6%
// Returns: double
double index_fund_APY_prompt(){
    std::cout << "Enter your I bond APY  as a number between 0 and 100" << std::endl;
    double index_fund_APY;
    std::cin >> index_fund_APY;
    if (index_fund_APY < 0){
        std::cout << "Error: negative value entered. Default of 10% will be used" << std::endl;
        index_fund_APY = 10;
    }
    return index_fund_APY;
}

int main(){

    // promting user for amount of funds available for investment
    int investment_funds = investment_funds_prompt();

    // checks for positive number, will terminate program if negative
        if (investment_funds >= 0){
    
            // prompting user for HYSA APY. Will default if negative value entered by user
            double HYSA_APY = HYSA_APY_prompt();
            
            // prompting user for HYSA FDIC insurance max. Will default if negative value entered by user
            int HYSA_insur_max = HYSA_insurance_max_prompt();
            
            // prompting user for I bond APY. Will default if negative value entered by user
            double ibond_APY = ibond_APY_prompt();
            
            // prompting user for index fund APY. Will default if negative value entered by user
            double index_fund_APY = index_fund_APY_prompt();









    // prints error message if negative investment funds were entered in beginning off program
        }else {
             std::cout << "Error: a negative amount of funds were entered" << std::endl;
        }
}
