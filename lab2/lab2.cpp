/* file:lab2.cpp
author Hamza Awad
This program asks users for name platecapacity and
passes them to diffrent functions to calculate
how much power the windturbine generated in watts,kilowatts,or megawatts using the formula w=g(〖s/25)〗^3.
The program will give error messages if the numbers entered do not meet requirments.
*/
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
bool getNameplateCapacity(double &nameplate);
bool checkNameplateCapacity (double nameplate);
bool getAndCheckWindSpeed( double &speed);
double calcWattsGenerated(double nameplate, double speed);
void printWattsGenerated( double watts);
const int MIN_SPEED=6;
const int MAX_SPEED=55;
const int MIN_NAMEPLATE=300;
const int MAX_NAMEPLATE=8000000;

int main()
{
   double nameplateCapacity;// maxwatts can be generated per          
   //day by windmill
   double windSpeed; // average wind speed in mph per day
   bool goodInput; // maxWatts or average windspeed error
   double watts;  // watts generated in one particular day


   // set precision for all output
   cout.setf( ios::showpoint | ios::fixed );
   cout.precision( 1);

   // say hello and get maxWatts for the first time
   cout << "Welcome to the Wind Turbine Calculator. "<<endl;;
   while ( getNameplateCapacity( nameplateCapacity )){
      goodInput = getAndCheckWindSpeed( windSpeed );
          // if no error in maxWatts and windSpeed then
          // calculate and print watts generated
         if( goodInput ){
    watts = calcWattsGenerated( nameplateCapacity, windSpeed );
            printWattsGenerated( watts );
         } // end if no input error in maxWatts and windSpeed
      }// end if good maxWatts
   // end while maxWatts < 0

   cout << "Thank you for using the Wind Turbine"; 
	cout<< "Calculator."<<endl;
   return( 0 );
}
/*
function name:getNameplateCapacity
this function gets the users input for nameplate and
if it is a valid input it returns it as true otherwise it returns falls.

bool getNameplateCapacity(double &nameplate){

cout << "Please enter the generator’s nameplate capacity in";
          cout<< "watts (0 to end):";
    cin >> nameplate ;
    if (nameplate == 0){
    return false;
    }
    else{
    return true;
    }
}

*/
bool getNameplateCapacity(double &nameplate)
{
  cout << "Please enter the generator’s nameplate capacity in"; 
  cout<< "watts (0 to end):";
    cin >> nameplate ;
    if (nameplate == 0){
    return false;
    }
    else{
    return true;
  }
}
/*
function checkNameplateCapacity gets the nameplate and checks if it falls under the right conditions and if it is in the correct number range
if it does not it returns it false
*/

bool checkNameplateCapacity (double nameplate)
{

       if (nameplate > 300 && nameplate < 8000000){
        return true;
       }
    else if (nameplate < 0){
         cout << "Nameplate capacity must be greater than"; 
		 cout<< "zero"<<endl;
        }
	else if ( nameplate < 300 ){
        cout << "Nameplate capacity must be between 300 and"; 
		cout<< "8000000 watts"<<endl;
        }
	else if ( nameplate > 8000000){
         cout << "Nameplate capacity must be less than";
         cout<< "8000000 watts"<<endl;

        }
       return false;


}
/*
funcion  getAndCheckWindSpeed gets and checks if the wind speed entered by the user is in between the correct range
and passes it to calcWattsGenerated
*/
bool getAndCheckWindSpeed( double &speed)
{

        cout << "Please enter today’s average wind speed in"; 
		cout<< "miles per hour: ";
        cin >> speed;
         if (speed >6 && speed <= 55){
         return true;
         }
	else if (speed < 0 ){
            cout << " Wind speed must be greater than"; 
			cout<< "zero."<<endl;
        }
         else if (0 <= speed && speed < 6 ){
         cout <<"Wind speed is not sufficient to power the";
		 cout << "generator."<<endl;
        }
	else if (speed > 55){
        cout << "Wind speed too high.";
        cout << "turbine is not operating." <<endl;
        }
       return false;
}
/*
function calcWattsGenerated gets nameplate and speed and uses a formula to calculate watts
and returns watts
*/

double calcWattsGenerated(double nameplate, double speed){

double watts;
 watts= pow((speed/25.0) ,3)*nameplate;
return (watts);

}

/* function printWattsGenerated prints out watts calculated to the user
in watts kilowatts or megawatts depending on the amount
*/
void printWattsGenerated( double watts ){
     if (watts >=1000 && watts<1000000){
     cout<< "The wind turbine generated "<<watts/1000;
     cout << "Kilowatts today"<<endl;
        }
	else if (watts >=1000000 ){
       cout<<"The wind turbine generated "<< watts/1000;
	  cout << " Megawatts today" <<endl;
        }

	else if (watts <1000 ){
        cout<< "The wind turbine generated " << watts/1000; 
        cout <<  " watts today"<<endl;
        }
}


