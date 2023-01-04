// Author: Muhammad Asad Naveed
// U.No.: 3035957848
// Assignment 2 Question 1
// Description : Write a C++ program which reads in some Pokémon names from user input and outputs them i certain order

#include <iostream>
#include <string>

using namespace std;



void swap(string &a, string &b)   //swap function to swap the pokemons accordingly
{ 
     string temporary = a; 
     a = b; 
     b = temporary; 
     return;
}

void output( string pokemons[], int counter)   // to print the sorted pokemons accordingly
{
    for (int i=0;i<counter;i++)
    {
        cout << pokemons[i] << endl;
    }
}


void sort_pokemons(string pokemons[], int counter)       //this program first checks if the pokemons are shorter or longer in length if a pokemon of similar length is found the sorting is done lexicrographically
{
    

    int index=0;
    string min;

    for(int i=0; i<counter+1; i++)        //iterator to go through the pokemons one after the other
    {
        index = i;
        min= pokemons[i];
        for(int j=i+1; j<counter+1; j++ )
        {
            if(pokemons[j].length()>min.length())        //if length of next pokemon greater
            {
                min=pokemons[j];
                index=j;
            }
            else if (pokemons[j].length()==min.length())    //if length same
            {
                string duplicate_names, store;
                

                for(int x=0; x< (pokemons[j].length()); x++)
                {
                    duplicate_names += tolower(pokemons[j][x]);

                }
                for (int y=0; y<min.length(); y++)
                {
                    store += tolower(min[y]);

                }
                
                if(duplicate_names < store)
                {
                    min=pokemons[j];
                    index=j;
                }
                
            }
        }

        if(index != i)
        {
            swap(pokemons[i], pokemons[index]);       // swap function called here
        }
    }
}



int main()
{

    string pokemons[ 30 ], input;  // array to store pokemon names
    string stop = "???";  
    cin >> input;  // input from the user
    int counter = 0;  // to count the number of pokemon names entered
   
    while ( input != stop )  
    {
      pokemons[counter ] = input;  // assigning pokemon names in the array
      cin >> input;
      counter++;  
    }


    sort_pokemons(pokemons, counter);


    output(pokemons, counter);

    return 0;

    
}
