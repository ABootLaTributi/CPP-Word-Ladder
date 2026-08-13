#include <string>
#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
#include "WordLadder.h"
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
    Passes in the name of a file that contains a dictionary of 5-letter words.
    Fills the list (dict) with the words within this file.
    If the file does not open for any reason or if any word within the file does not have exactly 5 characters, this function should output an error message and return.
*/
WordLadder::WordLadder(const string &fileName)
{
  ifstream inFS;
  string word;
  inFS.open(fileName);
  if (!inFS.is_open())
  {
    cout << "Error opening file." << endl;
    return;
  }
  while (inFS >> word)
    {
      if (word.size() != 5)
      {
        cout << "Error: word is not 5 letters." << endl;
        return;
      }
      dict.push_back(word);
    }
  inFS.close();
}

/*
  Passes in two 5-letter words and the name of an output file.
  Outputs to this file a word ladder that starts from the first word passed in and ends with the second word passed in.
  If either word passed in does not exist in the dictionary (dict), this function should output an error message and return.
  Otherwise, this function outputs to the file the word ladder it finds or outputs to the file, the message, "No Word Ladder Found."
*/
void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile)
{
  if (!isAWord(start) || !isAWord(end))
  {
    cout << "Error: one or both of the words are not in the dictionary." << endl;
    return;
  }
  
  ofstream outFS;
  outFS.open(outputFile);
  if (!outFS.is_open())
  {
    cout << "Error opening file." << endl;
    return;
  }
  queue<string> wordQueue;
  unordered_set<string> visitedWords;
  unordered_map<string, string> parentMap;

  wordQueue.push(start);
  visitedWords.insert(start);

  bool ladderFound = false;
  while (!wordQueue.empty())
    {
      string theCurrentWord = wordQueue.front();
      wordQueue.pop();

      if (theCurrentWord == end)
      {
        ladderFound = true;
        break;
      }

      for (const string &theNextWord : dict)
        {
          if (oneLetterOff(theCurrentWord, theNextWord) && visitedWords.find(theNextWord) == visitedWords.end())
          {
            wordQueue.push(theNextWord);
            visitedWords.insert(theNextWord);
            parentMap[theNextWord] = theCurrentWord;
          }
        }
    }
  if (!ladderFound)
  {
    outFS << "No Word Ladder Found." << endl;
    return;
  }

  
  stack<string> theWordStack;
  string theCurrentWord = end;
  while (theCurrentWord != start)
    {
      theWordStack.push(theCurrentWord);
      theCurrentWord = parentMap[theCurrentWord];
    }
    theWordStack.push(start);

    while (!theWordStack.empty())
      {
        outFS << theWordStack.top() << endl;
        theWordStack.pop();
      }
  outFS.close();

}