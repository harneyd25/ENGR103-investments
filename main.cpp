/* Author: David Harney harneyd@oregonstate.edu
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

// Function: HYSA_insurance_max_prompt
// Description: gets HYSA FDIC insurance max from user. If negative value entered, will print error and default to $250,000
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

// Function: ibond_APY_prompt
// Description: gets I bond APY from user. If negative value entered, will print error and default to 6%
// Returns: double
double ibond_APY_prompt(){
    std::cout << "Enter your I bond APY as a number between 0 and 100" << std::endl;
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
    std::cout << "Enter your index fund APY  as a number between 0 and 100" << std::endl;
    double index_fund_APY;
    std::cin >> index_fund_APY;
    if (index_fund_APY < 0){
        std::cout << "Error: negative value entered. Default of 10% will be used" << std::endl;
        index_fund_APY = 10;
    }
    return index_fund_APY;
}



int main(){

    // prompting user for amount of funds available for investment
    int investment_funds = investment_funds_prompt();

    // checks for positive number, will terminate program if negative
        if (investment_funds >= 0){

            // prompting user for HYSA FDIC insurance max. Will default if negative value entered by user
            int HYSA_insur_max = HYSA_insurance_max_prompt();
            
            // prompting user for HYSA APY. Will default if negative value entered by user
            double HYSA_APY = HYSA_APY_prompt();

            // prompting user for I bond APY. Will default if negative value entered by user
            double ibond_APY = ibond_APY_prompt();
            
            // prompting user for index fund APY. Will default if negative value entered by user
            double index_fund_APY = index_fund_APY_prompt();

            //initializing default investments to $0
            int HYSA_invest_amount = 0;
            int ibond_invest_amount = 0;
            int index_invest_amount = 0;
            
            

            // calculating max investment strategy
            
            // case 1: HYSA APY is greatest
            if (HYSA_APY >= ibond_APY && HYSA_APY >= index_fund_APY){
                if (investment_funds <=  HYSA_insur_max){
                    // all gets invested in HYSA
                    HYSA_invest_amount = investment_funds;
                } else {
                    // invest max allowed in HYSA
                    investment_funds = investment_funds - HYSA_insur_max;
                    HYSA_invest_amount = HYSA_insur_max;
                    if (ibond_APY >= index_fund_APY){
                       if (investment_funds <= 10000){
                            // remainder invested in I bonds
                            ibond_invest_amount = investment_funds;
                        } else {
                            // invest max allowed in I bonds, remainder in index
                           ibond_invest_amount = 10000;
                            investment_funds = investment_funds - 10000;
                           index_invest_amount = investment_funds;
                        }
                    } else {
                        // remainder invested in index
                         index_invest_amount = investment_funds;
                    }
                }
            }
            // case 2: I bond APY is greatest    
            else if (ibond_APY >= HYSA_APY && ibond_APY >= index_fund_APY){
            if (investment_funds <= 10000){
                // all gets invested in i bonds
                ibond_invest_amount = investment_funds;
            }   else {
                // invest max allowed in I bonds
                ibond_invest_amount = 10000;
                investment_funds = investment_funds - 10000;
                if (HYSA_APY >=index_fund_APY){
                    if (investment_funds <= HYSA_insur_max){
                        // remainder invested in HYSA
                        HYSA_invest_amount = investment_funds;
                    } else {
                        // invest max allowed in HYSA, remainder in index
                        HYSA_invest_amount = HYSA_insur_max;
                        investment_funds = investment_funds - HYSA_insur_max;
                        index_invest_amount = investment_funds;
                    }
                }
            }
            }
             else { 
            // case 3:index APY is greatest
                // invest all in index
                index_invest_amount = investment_funds;
            }



            // printing investment amounts to terminal
            std::cout << "You should invest ";
            std::cout << HYSA_invest_amount;
            std::cout << " into your target HYSA." << std::endl;
            std::cout << "You should invest ";
            std::cout << ibond_invest_amount;
            std::cout << " into I bonds." << std::endl;
            std::cout << "You should invest ";
            std::cout << index_invest_amount;
            std::cout << " into your target index fund." << std::endl;

	    // calculating and printing expected profit
   	    double expected_profit = ((HYSA_invest_amount * HYSA_APY + ibond_invest_amount * ibond_APY + index_invest_amount * index_fund_APY)/ 100);
  	    std::cout << "In total, these investments should earn you $";
    	    std::cout << expected_profit;
    	    std::cout << " over the next year." << std::endl;



    // prints error message if negative investment funds were entered in beginning of program
        }else {
             std::cout << "Error: a negative amount of funds were entered" << std::endl;
        }
}
