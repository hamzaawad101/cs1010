/* File: lab3.cpp
  Authors: Hamza Awad
  This file reads haikus from a file picks a random one and replaces its astrik with words from user
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <cstdlib>
using namespace std;
const int MAX_CH = 50;
const int MAX_ROW = 111;
const int MAX_WORDS= 3;
const int NEW_HAIKU_LINE=3;
void getwords(char word[MAX_WORDS][50]);
void print (char haiku[MAX_ROW][MAX_CH], int num,char word[MAX_WORDS][MAX_CH]);
int main (){
  char c; //declare our variables and creat our arrays.
  char answer;
  char myHaiku[MAX_ROW][MAX_CH]; //2d array
  char word[MAX_WORDS][MAX_CH];
  ifstream input;
  input.open("haikus.dat");
  cout<<"Welcome to Mad Lib Haikus!"<<endl;

    ;//open and check file if it exists
  if (input.fail ()){
   // when file could  not open an error message prints out
cout << "Haiku file non-existent. Please contact the administrator" <<endl;  //error message for no files
      cout<<"Thank you for using Mad Lib Haikus!"<<endl;
     return 1;
  }
  else{
   //checks if it is empty
      input.get (c);
      if (input.eof ()){
          cout << "Haiku file is empty. Please contact the administrator." << endl;  //error message for empty file
          cout<<"Thank you for using Mad Lib Haikus!"<<endl;
          return 1;
      }
      input.putback (c);
  }


  int i;
  for (i = 0; i < MAX_ROW; i++)
    {      // loop for reading rows from file into array

      input.getline(myHaiku[i],50);

      if (input.eof ())  //once all rows are read break from loop
        {
          break;

        }
  }
  input.close();
  do{      //loop to creat new haikus while user answers yes or y.
  int Haikunumber = i / 3;
  srand (time (0));
  int randomNumber = rand () % Haikunumber;//random haiku generated.
  getwords(word);     //function to get words
  print(myHaiku,randomNumber,word);  //print new haiku
  cout<<"Continue (Y/N)?:";  //ask user if they want another haiku.
  cin>>answer;
  }while(answer == 'y' || answer =='Y');  //loop condition

  return 0;
}


/* void getwords: get words from user to replace astriks.
   Parameters:char word[MAX_WORDS][MAX_CH]
   Post-condition: parameter has been filled with words from user.
   Returns: nothing

*/

void getwords(char word[MAX_WORDS][MAX_CH]){
  cout<<"Enter a one syllable noun:";
  cin>>word[0];
  cout<<"Enter a two syllable adjective:";
  cin>>word[1];
  cout<<"Enter a two syllable gerund (a verb ending in 'ing' like asking, trying";
  cin>>word[2];
  char letter = word[2][0];  //fist letter of gerund is uppercased.
  char upperCaseLetter = toupper(letter);
  word[2][0] = upperCaseLetter;
}

/* File: void print gets random haiku and words to find and replace astriks and prints new haiku.
   Parameters:char haiku[MAX_ROW][MAX_CH],int num,char word[MAX_WORDS][MAX_CH]
   Post-condition:haiku is altered and now has words instead of astriks.
   Returns: nothing
*/

void print (char haiku[MAX_ROW][MAX_CH], int num,char     word[MAX_WORDS][MAX_CH]){
  int haikustart = num * 3;   //picks what line haiku starts
  int haikuend = haikustart + 3;
  char astrik='*';
  char newhaiku[NEW_HAIKU_LINE][MAX_CH]={{0}}; //new haiku array
  int newline=0;
  cout<<"Your Mad Lib Haiku:"<<endl;
    for (int i= haikustart; i< haikuend; i++){
        int len = strlen(haiku[i]);
        for(int j=0;j<len;j++){   
//find astrik and replace with words for all three lines.
            if(haiku[i][j]==astrik){
              strncpy(newhaiku[newline],haiku[i], j);
              strcat(newhaiku[newline], word[newline]);
              strcat(newhaiku[newline], &haiku[i][j+1]);
              break;

           }
       }
       cout<<newhaiku[newline]<<endl; //print new haiku lines.
       newline++;
    }
}



