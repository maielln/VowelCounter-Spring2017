/*  GHP #3 code

    Have the user enter the name of a file. Open said file, read it and count and report the number of vowels found in the file.

    Written by Nicole Maiello
        Used the code handed out during class (read_string.cpp) as a reference for this program.
    February 22, 2017
    Language: c++ (Written in Code::Blocks, g++ target)
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdio>

using namespace std;

int vowelCounter(string);

int main(void)
{
    string inputFileName;
    int i = 0;
    string s;
    ifstream fileIn;
    char ch;
    int counter;
    cout<<"Enter the name of the file of characters (ex. Example.txt): ";
    cin>>inputFileName;
    fileIn.open(inputFileName.data());
    assert(fileIn.is_open());
    while(!(fileIn.eof())){
        ch = fileIn.get();
        s.insert(i, 1, ch);                                 //puts the character taken from the file and puts it into a string (array of characters)
        i++;
    }

    counter = vowelCounter(s);
    cout<<"The number of vowels in this file of characters is: "<<counter;
    return 0;
}

int vowelCounter(string s){
/*  Takes in a string value, checks the array of characters for vowels, adds 1 to the counter for each vowel.

    Written by Nicole Maiello
    February 22, 2017
    Language: c++ (Written in Code::Blocks, g++ target)
    */
    int i;
    int counter = 0;
    int length = s.length();
    char c;
    int j;
    bool found = false;
    string vowel = "aeiou";
    for(i=0; i <= s.length(); i++){
        c = s[i];
        c = tolower(c);                                     //takes any character stored in c and makes it lower case
        found = false;
        for(j = 0; j < vowel.length() && (!found); j++){    //Checks if the character is a vowel or not
            if(c == vowel[j])
                found = true;
        }
        if(found)
            counter++;
    }
    return counter;
}
