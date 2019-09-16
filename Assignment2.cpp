//Irvin Carbajal
//Assignment 2
//Rhonda H


#include <iostream> 
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

struct wordItem
{
	string word;
	int count;
};

void reSize(wordItem*& array, int* cap)
{
	wordItem* new_array = new wordItem[(*cap) * 2];

	for (int i = 0; i < (*cap); i++)
	{
		new_array[i] = array[i];
	}

	delete [] array;

	(*cap) = (*cap) * 2;
	array = new_array;
}

void getStopWords(char *ignoreWordFileName, string ignoreWords[])
{
	//ignoreWords[50];
	ifstream infile;
	string line;
	int i = 0;

	infile.open(ignoreWordFileName);
	if (infile.is_open())
	{
		while(getline(infile, line, '\n'))
		{
			ignoreWords[i] = line;
			i++;
		}
	}

	else
	{
		cout << "File not opened." << endl;
	}

	infile.close();
}

bool isStopWord(string word, string ignoreWords[])
{	
	for (int i = 0; i < 50; i++)
	{
		if(ignoreWords[i] == word)
		{
			return true;
		}
	}
	return false;
}

int getTotalNumberNonStopWords(wordItem wordItemList[], int numberOfUniqueWords)
{
    int count = 0;
    for(int i = 0; i < numberOfUniqueWords; i++)
    {
        count = count + wordItemList[i].count;
    }
    return count;
}

void arraySort(wordItem wordItemList[], int numberOfUniqueWords){
    for(int i = 1; i < numberOfUniqueWords; i++){
        int indexCount = wordItemList[i].count;
        string indexName = wordItemList[i].word;
        int j = i;
        while(j > 0 && wordItemList[j-1].count<indexCount){
            wordItemList[j] = wordItemList[j-1];
            j = j - 1;
        }
        wordItemList[j].count = indexCount;
        wordItemList[j].word = indexName;
    }
}

void printTopN(wordItem wordItemList[], int topN)
{
	for (int i = 0; i < topN; i++)
	{
		cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
	}
}

int main(int argc, char * argv[])
{
	int cap = 100;
	int i = 0;
    //int count = 0;
    int doubles = 0;
    string ignore [50];
    //wordItem wordItemList [cap];
    bool found = false;
    wordItem* wordItemList = new wordItem[cap];
    
    fstream fp;
    string line;

    getStopWords(argv[3], ignore);
    
    fp.open(argv[2]);
    if(fp.is_open())
    {
        while(getline(fp, line))
        {
            stringstream ss (line);
            string pp;

            while(ss >> pp)
            {
                if(isStopWord(pp, ignore))
                {
                    for(int x = 0; x < i; x++)
                    {
                        if(wordItemList[i].word == pp)
                        {
                            wordItemList[i].count++;
                            found = true;
                            break;
                        }
                    }
                }
                
                if(!found)
                {
                    //wordItem(pp, 1);

                    //i++;
                    if(cap == i)
                    {
                        reSize(wordItemList, &cap);
                    }

                    wordItemList[i].word = pp;
                    wordItemList[i].count = 1;

                }
                found = false;
            }
        }
        arraySort(wordItemList, i);
        printTopN(wordItemList, stoi(argv[1]));
        cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
        cout << "#" << endl;
        cout << "Array doubled: " << doubles << endl;
        cout << "#" << endl;
        cout << "Unique non-common words: " << getTotalNumberNonStopWords(wordItemList, i) << endl;
    }

   	else
   	{
   		cout << "File not opened" << endl;
   	}

}


