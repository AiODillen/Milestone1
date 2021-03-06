//
//  main.cpp
//  Milestone1 1a
//
//  Created by Niklas on 19.10.18.
//  Copyright © 2018 Niklas. All rights reserved.
//
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include <algorithm> //maybe not needed
#include <iterator> //maybe not needed



using namespace std;

void copy(int arraya[][30], int arrayb[]);

void print_array1(int array[], int length);

void print_array2(int array[][30]);

void generate_2d_array();

void interface();

int main()
{
    srand(time(0));
    interface();
    return 0;
}

void print_array1(int array[], int length)
{
    int m=0;
    for (int n=0; n<length; n++){
        m+=1;
        cout << array[n];
        if (m==30){
            cout << endl;
            m=0;
        }
    }
}

void print_array2(int array[][30])
{
    for (int x=0; x<30; x++){
        for (int y=0; y<30; y++){
            cout << array[x][y];
        }
        cout << endl;
    }
    cout << endl;
}
    
void copy(int arraya[][30], int arrayb[])
{
    memcpy(arrayb, arraya, 900*sizeof(int));
}

void generate_2d_array(int array[][30])
{
    for (int x=0; x<30; x++){
        for (int y=0; y<30; y++){
            array[x][y] = rand()%10;
        }
    }
}
void interface()
{
    int array2d [30][30]; int* array1d = new int [900];
    string i; cout << "(Für eine Liste an Befehlen (? oder help) eingeben." << endl;
    while (i != "exit"){
        cout << "Welche Aktion ausführen? >>"; cin >> i;
        if (i=="?" || i=="help"){
            cout << "2D Array generieren:  generate2D" << endl;
            cout << "2D in 1D kopieren:  copy2D" << endl << "2D Array ausgeben:  print2D" << endl;
            cout << "1D array ausgeben:  print1D" << endl << "Zum beenden des Programms:  exit" << endl << endl;
        }
        else if (i=="generate2D"){
            generate_2d_array(array2d);
        }
        else if (i=="copy2D"){
            copy(array2d, array1d);
        }
        else if (i== "print2D"){
            print_array2(array2d);
        }
        else if (i=="print1D"){
            print_array1(array1d, 900);
        }
        else if (i=="exit"){
            return;
        }
        else{
            cout << "Falsche Eingabe!" << endl << endl;
            return interface();
        }
    }
}
