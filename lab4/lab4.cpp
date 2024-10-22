#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
//our constents
const int EXTROVERSION = 0;
const int AGREEABLENESS = 1;
const int CONSCIENTIOUSNESS = 2;
const int NEUROTICISM = 3;
const int OPEN_TO_EXPERIENCE = 4;
const int NUM_QUESTIONS = 50;
const int NUM_TRAITS = 5;
const int MAX_ASSESSMENTS = 26;
struct Big5 {
   string firstName;
   string lastName;
   int age;
   int answers[NUM_QUESTIONS]; // assessment answers
   double normalizedTraits[NUM_TRAITS];   // trait scores
};
void getdata(Big5 ba[],ifstream &input,int &num);  //function prototypes
void calculate(Big5 ba[],int numberOfElements);
void sortnames(Big5 ba[],int numberOfElements);
void print(Big5 ba[],int numberOfElements);
int main(){
    Big5 ba[MAX_ASSESSMENTS];
    char c;    //declare our variables and creat our arrays.
    char filename[30];
    ifstream input;
    cout<<"Welcome to the Big 5 Assessment Reporter."<<endl;
    cout<<"Enter input file name:";
    cin>>filename;
    input.open(filename);
     if (input.fail ()){
        // when file could  not open an error message prints out
        cout << "Input file " <<filename<< " does not exist.";
        cout<<endl;  //error message for no files
        cout<<"Thank you for using the Big 5 Assessment Reporter."<<endl;
      return 1;
    }

    input.get (c);
if (input.eof ()){
        cout << "Input file " <<filename<< " is empty";
        cout<<endl;
        //error message for empty file
        cout<<"Thank you for using the Big 5 Assessment Reporter."<<endl;
        return 1;
    }
   int numberOfRead =0;
   input.putback (c);
   getdata(ba,input, numberOfRead);
   calculate(ba, numberOfRead);
   sortnames(ba,numberOfRead);
   print(ba,numberOfRead);
   cout<<"Thank you for using the Big 5 Assessment Reporter."<<endl;
}
/* void getdata: reads data from input file into struct array.
   Parameters:Big5 ba[],ifstream &input
   Post-condition: parameter has been filled with data from file.
   Returns: nothing
*/


void getdata(Big5 ba[],ifstream &input, int &num ){
  int i=0;
     for(i=0;i<MAX_ASSESSMENTS;i++){

         input>>ba[i].firstName; //get first word up to white space.
         input>>ba[i].lastName;
         input>>ba[i].age;
            for(int ctr=0;ctr<50;ctr++){
                input>>ba[i].answers[ctr];
            }
	if(input.eof()){
                break;
        }
     }
     num = i; // contains how many we read
}
/* void calculate: calculates traits using formulas for all 5..
   Parameters:Big5 ba[].
   Post-condition: traites have been calculated and normalized.
   Returns: nothing
*/

void calculate(Big5 ba[], int numberOfElements ){
        cout.precision(1);
        cout.setf(std::ios::fixed);
        //calculate traits
      for(int i=0;i<numberOfElements;i++){
          double extroversion = 20+(ba[i].answers[0])-(ba[i].answers[5])+(ba[i].answers[10])-   
               (ba[i].answers[15]) +(ba[i].answers[20])-(ba[i].answers[25])+(ba[i].answers[30])-    
               (ba[i].answers[35])+(ba[i].answers[40])-(ba[i].answers[45]);
                double agreeableness = 14-(ba[i].answers[1])+(ba[i].answers[6])- 
                (ba[i].answers[11])+(ba[i].answers[16])-(ba[i].answers[21])+(ba[i].answers[26])
                -(ba[i].answers[31])+(ba[i].answers[36])+(ba[i].answers[41])+(ba[i].answers[46]);

                double conscientiousness = 14+(ba[i].answers[2])-   
               (ba[i].answers[7])+(ba[i].answers[12])-(ba[i].answers[17])+(ba[i].answers[22])-
               (ba[i].answers[27])+(ba[i].answers[32])-
               (ba[i].answers[37])+(ba[i].answers[42])+(ba[i].answers[47]);

               double neuroticism = 38-(ba[i].answers[3])+(ba[i].answers[8])-
               (ba[i].answers[13])+(ba[i].answers[18])-(ba[i].answers[23])-(ba[i].answers[28])

              -(ba[i].answers[33])-(ba[i].answers[38])-(ba[i].answers[43])-(ba[i].answers[48]);
               double  openness_to_experience = 8+(ba[i].answers[4])-
               (ba[i].answers[9])+(ba[i].answers[14])-(ba[i].answers[19])+(ba[i].answers[24])-

          (ba[i].answers[29])+(ba[i].answers[34])+(ba[i].answers[39])+(ba[i].answers[44])+(ba[i].answers[49]);
          //normalize traits
          ba[i].normalizedTraits[EXTROVERSION]=(extroversion + 10)/10;
          ba[i].normalizedTraits[AGREEABLENESS]=(agreeableness + 10)/10;
          ba[i].normalizedTraits[CONSCIENTIOUSNESS]=(conscientiousness+ 10)/10;
          ba[i].normalizedTraits[NEUROTICISM]=(neuroticism + 10)/10;
          ba[i].normalizedTraits[OPEN_TO_EXPERIENCE]=(openness_to_experience+ 10)/10;

       }

}
/* void sortnames: reads data from input file into struct array.
   Parameters:Big5 ba[],const int MAX_ASSESSMENTS.
   Post-condition: names have been sorted alphabeticlly by last name
   Returns: nothing
*/

void sortnames(Big5 ba[],int numberOfElements ){
        int mini;
        Big5 temp;
        int i;
	    int j;
       for(int i=0;i<numberOfElements-1;i++){
          mini=i;
            for(int j=i+1;j<numberOfElements;j++){
                if(ba[j].lastName<ba[mini].lastName){
                   mini=j;
                }

            }

        temp=ba[i];
       ba[i]=ba[mini];
       ba[mini]=temp;

    }


}
/* void print: prints all data sorted and calculated..
   Parameters:Big5 ba[].
   Post-condition: data is sorted and calculated.
   Returns: nothing
*/

void print(Big5 ba[], int numberOfElements){
          double sumE=0;
          double sumA=0;
          double sumC=0;
          double sumN=0;   //our varibles
          double sumO=0;
          cout<< setw(15) <<left<<"Lastname";
          cout<< setw(15) <<left<<"firstname";
          cout<<setw(6)<<"age";
          cout<<setw(6)<<"E";
          cout<<setw(6)<<"A";
          cout<<setw(6)<<"C";
          cout<<setw(6)<<"N";
          cout<<setw(6)<<"O"<<endl;
    cout<<"---------------------------------------------";
    cout<<"-----------------------------"<<endl;

        for(int i=0;i<numberOfElements;i++){  
      //for loop to print data for each person
          cout<<setw(15)<<left<<ba[i].lastName;
          cout<<setw(15)<<left<<ba[i].firstName;
          cout<<setw(6)<<left<<ba[i].age;
          cout<<setw(6)<<left<<ba[i].normalizedTraits[EXTROVERSION];
          cout<<setw(6)<<left<<ba[i].normalizedTraits[AGREEABLENESS];
          cout<<setw(6)<<left<<ba[i].normalizedTraits[CONSCIENTIOUSNESS];
          cout<<setw(6)<<left<<ba[i].normalizedTraits[NEUROTICISM];
          cout<<setw(6)<<left<<ba[i].normalizedTraits[OPEN_TO_EXPERIENCE]<<endl;
          sumE+= ba[i].normalizedTraits[EXTROVERSION];
          sumA+=ba[i].normalizedTraits[AGREEABLENESS];
          sumC+= ba[i].normalizedTraits[CONSCIENTIOUSNESS];
          sumN+=ba[i].normalizedTraits[NEUROTICISM];
          sumO+=ba[i].normalizedTraits[OPEN_TO_EXPERIENCE];
      }

        cout<<setw(36)<<left<<"Avrages";
        cout<<setw(6)<<left<<sumE/numberOfElements;
        cout<<setw(6)<<left<<sumA/numberOfElements; 
 // calculate the avges of 
        cout<<setw(6)<<left<<sumC/numberOfElements;
        cout<<setw(6)<<left<<sumN/numberOfElements;
        cout<<setw(6)<<left<<sumO/numberOfElements<<endl;

}


