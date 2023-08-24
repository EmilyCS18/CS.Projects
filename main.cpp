//Emily G. Contreras
//7/3/2022
//Apple U-Pick

#include <iostream>
using namespace std;
int main() 

{
double pounds = 1.72, total = 0 ;
int picked;

cout << "\n" << endl;

cout << "I hope you had a great time at Hartnell Apple Orchards U-Pick Event! Now, how many pounds of apples did you pick? ";
  cin >> picked;

cout << "\n" << endl;
  
if (picked <= 4)
{
  total = picked * pounds;

cout << "Enjoy some fresh apples!";

cout << "\n" << endl;
  
cout << "Your total is $" << total << endl; 

cout << "\n" << endl;
  
cout << "Have a great rest of your day!";
  }

else if (picked >= 5 && picked <= 10)
{
total = picked * pounds;

cout << "Here is a recipe for apple butter!";

cout << "\n" << endl;
  
cout << "Your total is $" << total << endl; 

cout << "\n" << endl;
  
cout << "Have a great rest of your day!";
  }


else 
{
total = picked * pounds;

cout << "Here is a recipe for apple pie!";

cout << "\n" << endl;
  
cout << "Your total is $" << total << endl; 

cout << "\n" << endl; 
  
cout << "Have a great rest of your day!";

}

  


return 0; 
}


/* OUTPUT OUTPUT

I hope you had a great time at Hartnell Apple Orchards U-Pick Event! Now, how many pounds of apples did you pick? 8


Here is a recipe for apple butter!

Your total is $13.76


Have a great rest of your day!

*/