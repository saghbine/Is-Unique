//
//  main.cpp
//  Is Unique
//
//  Created by daniel saghbine on 12/8/24.
//  CTCI 1.1 Is Unique

#include <iostream>
using namespace std;

bool Is_Unique(string &s);

int main()
{
    string str;
    
    cout<<"problem\n-------\n\tImplement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?\n\n";
    
    cout<<"input\n-----\n\tType: ";
    cin>>str;
    
    cout<<"\noutput\n------\n\tThe string is"<<(Is_Unique(str) ? "" : "n't")<<" unique.\n\n";
    
    cout<<"solution\n--------\n\tAuxiliary space complexity: O(1); time complexity: O(n log n).\n\n";
    
    return 0;
}

void char_swap(char &c1, char &c2)
{
    c1=c1+c2;
    c2=c1-c2;
    c1=c1-c2;
}

void max_heapify(string &s, int n, int i)
{
    bool swap;
    int lc, rc, gc;
    
    do
    {
        swap=false;
        lc=2*i+1;
        
        if(lc < n)
        {
            rc=lc+1;
            
            if(rc < n && s[rc] > s[lc])
                gc=rc;
            else
                gc=lc;
            
            if(s[gc] > s[i])
            {
                char_swap(s[gc], s[i]);
                
                if(gc*2+1 < n)
                {
                    swap=true;
                    i=gc;
                }
            }
        }
    }
    while(swap);
}

void build_max_heap(string &s)
{
    for(int i=int(s.size())/2-1; i >= 0; i--)
        max_heapify(s, int(s.size()), i);
}

void heapsort(string &s)
{
    int counter=int(s.size());
    
    build_max_heap(s);
    
    while(counter > 1)
    {
        char_swap(s[0], s[--counter]);
        max_heapify(s, counter, 0);
    }
}

bool Is_Unique(string &s) // s is input string
{
    heapsort(s); // sort s using heapsort
    
    for(int i=0; i < s.size()-1; i++) // check char at indices 0...N-2 in s
    {
        if(s[i] == s[i+1]) // check if adjacent char pairs are equivalent
            return false; // s isn't unique
    }
    
    return true; // s is unique
}
