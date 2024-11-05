#include <iostream>

void showBalance(double balance){
    std::cout << "Your Balance is: $" << balance << std::endl;
}

double deposit(){
    double amount = 0 ;
    std::cout << "Enter the amount : ";
    std::cin >> amount ;
    if(amount>0){
        return amount;
    }
    else{
        std::cout << "Enter a valid amount.\n";
        return 0 ;
    }
}

double withdraw(double balance){
    double amount = 0;
    std::cout << "Enter the amount : ";
    std::cin >> amount ;
    if(amount>balance){
        std::cout << "over the balance.\n";
        return 0 ;
    }
    else if (amount < 0){
        std::cout << "Enter valid amount\n" ;
        return 0 ;
    }
    else{
        return amount ;
    }
    
}

int main(){
    double balance = 0 ;
    int choice ;
    do{
        std::cout << "***** Welcome *****\n";
        std::cout << "1. Show Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cout << "*******************\n";
        std::cout << "Enter : " ;
        std::cin >> choice ;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Invalid input\n";
            continue;
        }

        switch (choice){
        case 1 :
            showBalance(balance);
            break;
        
        case 2 :
            balance += deposit();
            showBalance(balance);
            break;
        
        case 3 :
            balance -= withdraw(balance);
            showBalance(balance);
            break;
        
        case 4 :
            std::cout << "Goodbye";
            break;
        default:
            std::cout << "Invalid choice";
            break;
        }
    } while (choice != 4);
    
    return 0 ; 
}