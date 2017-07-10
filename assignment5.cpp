//
//  assignment5.cpp
//  assignment5
//
//  Created by Tamara Sekularac on 7/09/17.
//  Copyright © 2017 Tamara Sekularac. All rights reserved.
//
#include <list>
#include <set>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

list<char> unknownLanguage(list<string> words)
{
    if(words.size()==0)
        return list<char>();
    
    list<char> letters;
    unordered_map<char, set<char>> lettersBefore;//set of letters that needs to be before current letter
    unordered_map<char, set<char>> lettersAfter; //set of letters that needs to be after current letter


    list<string>::iterator curr = words.begin();
    string currStr=(*curr);
    for(char c: currStr)
    {
        unordered_map<char,set<char>>::const_iterator currLetter=lettersBefore.find(c);
        if(currLetter==lettersBefore.end())
        {
            lettersBefore[c]=set<char>();
            lettersAfter[c]=set<char>();
        }
    }
    
    list<string>::iterator prev=curr;
    curr++;
    //adding all the relations between letters
    for (; curr != words.end(); curr++)
    {
        string currStr=(*curr);
        string prevStr=(*prev);
        for(char c: currStr)
        {
            unordered_map<char,set<char>>::const_iterator currLetter=lettersBefore.find(c);
            if(currLetter==lettersBefore.end())
            {
                lettersBefore[c]=set<char>();
                lettersAfter[c]=set<char>();
            }
        }
        int i=0;
        while(i<prevStr.length() && i<currStr.length() && prevStr[i]==currStr[i])
            i++;
        if(i<prevStr.length() && i<currStr.length())
        {
            lettersBefore[currStr[i]].insert(prevStr[i]);
            lettersAfter[prevStr[i]].insert(currStr[i]);
        }
            
        prev=curr;
    }
    
    //finding all the posible letters that can be adding in each iteration
    queue<char> posibleLetters;
    for(auto& x: lettersBefore)
        if(x.second.size()==0)
            posibleLetters.push(x.first);
    while(!posibleLetters.empty())
    {
        char currChar=posibleLetters.front();
        letters.push_back(currChar);
        posibleLetters.pop();
        for(char c:lettersAfter[currChar])
        {
            lettersBefore[c].erase(currChar);
            if(lettersBefore[c].empty())
                posibleLetters.push(c);
        }
    }
    if(letters.size()==lettersBefore.size())
        return letters;
    
    return list<char>(); // this means that the alphabet is not correct
}

int main()
{
    list<string> words={"ART", "RAT", "CAT", "CAR"};
    list<char> letters=unknownLanguage(words);
    for(char c:letters)
        cout<<c<<" ";
    
    return 0;
}
