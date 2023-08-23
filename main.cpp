//Emily G. Contreras
//7/17/2022
//Emy's Number Lottery
#include <iostream>
using namespace std;

int main() 
{
int numbers[5]; //= {4, 50, 33, 22, 60}; 
int mega = 0;
string input;

  
do {
cout << "\nWelcome to Emy's Number Lottery!\n";

//numbers
cout << "\nplease enter 5 numbers between 1-69 one at a time " << endl;
  cin >> numbers [0] >> numbers [1] >> numbers [2] >> numbers [3] >> numbers [4];

//mega
cout << "\nPlease enter a mega number" << endl; 
  cin >> mega; 
  
// to win
  if (numbers [0] == 4 && numbers [1] == 50 && numbers [2] == 33 && numbers [3] == 22 && numbers [4] == 60 && mega == 15)
  {
     cout << "\n" << endl;
    cout << "You won!" << endl; 
    cout << "Thank you for playing Emy's number lottery!" << endl; 
  }
    
    // to lose
  else 
  {
     cout << "\n" << endl;
    cout << "Sorry, those are not winning numbers" << endl;
  }

  
cout << "\nDo you want to try Emy's Number Lottery again? Type yes or stop to exit " << endl;
cin >> input;
        
 }while(input == "yes" || input == "Yes");

  if (input == "stop" || "Stop")
{
 cout << "\nThank you playing Emy's number lottery, try us again next time!" << endl; 
}




return 0; 
}
    

/* OUTPUT OUTPUT : TO LOSE AND STOP
Welcome to Emy's Number Lottery!

please enter 5 numbers between 1-69 one at a time 
1
2
3
4
5

Please enter a mega number
5


Sorry, those are not winning numbers

Do you want to try Emy's number lottery again? Type yes or stop to exit 
stop

Thank you playing Emy's number lottery, try us again next time!




OUTPUT OUTPUT : TO WIN AND CONTUIE
Welcome to Emy's Number Lottery!

please enter 5 numbers between 1-69 one at a time 
4 50 33 22 60

Please enter a mega number
15


You won!
Thank you for playing Emy's Number Lottery!

Do you want to try Emy's number lottery again? Type yes or stop to exit 
yes

Welcome to Emy's Number Lottery!

please enter 5 numbers between 1-69 one at a time 


*/