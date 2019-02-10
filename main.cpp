/*
 * Project 5: SpeechGrade
 */

#include<stdio.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cctype>

using namespace std;

// Display your identifying information (Name, lab day and time)

void displayIdentifyingInformation()

{
    printf("Author: Mohamed Imran Mohamed Siddique \n");
    printf("Class: CS 141, Spring 2016 \n");
    printf("Program #5: SpeechGrade  \n");
    printf("System: XCode on Mac \n");
    printf(" \n");
}

void displayIdentifyingInstruction()

{
    printf("Presidential Announcement Speech reading grade levels: \n");
    
}
void countwords(char filenames[], int &wordcount, int &sentcount, int &sylcount, double &total)
{
    char ch;
    char c;
    char a;
    wordcount=0;
    sentcount=0;
    sylcount=0;
    total=0;
    
    ifstream myFile;
    myFile.open(filenames);   //Open the file
    ch = myFile.get();
    while (ch != EOF) //While file does not reach the end
    {
        if (ch == 32 || ch == 9 || ch == 10 || ch == 13 || ch == 45  )
        {
            wordcount++;//increment the word count parameter
        }
        
        if (ch == 46 || ch == 63 )
        {
            sentcount++;//increment the sentence count parameter
        }
        if (ch == 97 || ch == 101 || ch == 105 || ch == 111 || ch == 117 || ch == 121
            )
        {
            sylcount++;//increment the sentence count parameter
            c = myFile.peek(); //peeks the next character to see if its another vowel
            if (c==97 || c == 101 || c == 105 || c == 111 || c == 117 || c == 121){
                sylcount--;//decrement the sentence count parameter when there are 2 adjacent vowels
            }
            c = myFile.peek();// peeks the next character to see if its a space
            
            if ((ch == 101 && a == 32) ){
                sylcount--;//decrement the sentence count parameter when a word ends vowel-consonant-'e'
            }
            
        }
        ch = myFile.get(); //get the next char
    }
    
    total = 0.39*wordcount/sentcount + 11.8*sylcount/wordcount - 15.59;// calculates the total reading level grade
    
    
}
// swaps name.txt to first and last name
void swap(char* filenames, char* realnames)
{
    char* temp = filenames;
    filenames = realnames;
    realnames = temp;
}

//---------------------

int main(){
    //initialise the variable
    int wordcount[17], sentcount[17], sylcount[17];
    double total[17];
    int i;
    //declare the variables to 0....
    
    char filenames[17][20] = {"BenCarson.txt", "BernieSanders.txt", "ChrisChristie.txt", "CarlyFiorina.txt", "DonaldTrump.txt", "HillaryClinton.txt", "JamesWebb.txt", "JebBush.txt", "JohnKasich.txt", "LindseyGraham.txt", "MarcoRubio.txt", "MikeHuckabee.txt", "RandPaul.txt", "RickPerry.txt", "RickSantorum.txt", "ScottWalker.txt", "TedCruz.txt"};
    
    char realnames[17][20] = {"Carson, Ben", "Sanders, Bernie", "Christie, Chris", "Fiorina, Carly", "Trump, Donald", "Clinton, Hillary", "Webb, James", "Bush, Jeb", "Kasich, John", "Graham, Lindsey", "Rubio, Marco", "Huckabee, Mike", "Paul, Rand", "Perry, Rick", "Santorum, Rick", "Walker, Scott", "Cruz, Ted"};
    
    for(i=0; i<17; i++) {
        //counts the words and sentences and vowels
        countwords(filenames[i], wordcount[i], sentcount[i], sylcount[i], total[i]);
        // swaps the original file names with the correct names
        swap(filenames[i],realnames[i]);
    }
    
    //rearranges the values and the names from highest to lowest
    double temp;
    char temp2;
    for(int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if (total[i] < total[j])
            {
                //swap the values
                temp = total[i];
                total[i] = total[j];
                total[j] = temp;
                
                //swap the filenames
                strcpy(&temp2, realnames[i]);
                strcpy(realnames[i], realnames[j]);
                strcpy(realnames[j], &temp2);
            }
        }
        
    }
    
    
    // Display the final total numbers alongside the names
    for(i=16; i >= 0; i--){
        printf("%.1f %s\n", total[i], realnames[i] );
    }
    printf("\n");
    for(i=16; i >= 0; i--){
        printf("%s\n",realnames[i]);
        printf("Total number of words are: %d\n", wordcount[i]);
        
        printf("Total number of sentences are: %d\n", sentcount[i]);
        printf("Total number of syllables are: %d\n", sylcount[i]);
        printf("\n");
    }
}