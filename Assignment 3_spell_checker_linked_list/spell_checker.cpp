// Gustavo J. Munoz
// Assignment 1 - Spell Checker
// cpp file

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "dictionary.h"
#include "LinkedList.h"

using namespace std;

string carriageRet = "\n";

void printVector(vector<string> inputFile) {
  
    for (vector<string>::iterator it=inputFile.begin(); it!=inputFile.end(); it++){
	cout <<  *it <<  endl;
    }
}

void writeVectoFile(vector<string> inputFile, string outputFn){

    fstream ofs(outputFn.c_str(), fstream::out);

    for(vector<string>::iterator it=inputFile.begin(); it!=inputFile.end();it++){
	if(carriageRet.compare(*it)==0)
	ofs << *it;
	else
	ofs << *it << " ";
    }
    ofs.close();
  
}

int main(int argc, char* argv[]) {			


    Dictionary usrdict("/usr/share/dict/words");	//dictionaries in system	
    Dictionary usrdict2(string((string(getenv("HOME"))+"/_Dictionary")));

    vector<string> inputFile; 			//reading in the input file 
    vector<string> globalIgnoredWords;

    //parse input file into vector for easy access
    ifstream ifs(argv[1]);
    string str;

    while (ifs >> str){
	inputFile.push_back(str);
	
	if(ifs.peek() =='\n'){
	inputFile.push_back(string(1,'\n'));
	}
    }
    //writeVectoFile(inputFile,"immout.txt");
    ifs.close();

    for (vector<string>::iterator it=inputFile.begin(); it!=inputFile.end(); it++){ //check word against both dictionaries
	string word = *it;
	
	if(carriageRet.compare(word)==0)
	continue;
	
	if(!usrdict.match(word) && !usrdict2.match(word) && (find(globalIgnoredWords.begin(), globalIgnoredWords.end(), word)==globalIgnoredWords.end())){
				
	//Replacing incorrect word
	string user_input;
	cout << '\n' << endl;
	cout << "The mispelled word is: " << *it << "\nWhat do you want to do? " << endl;
	cout << "Options: " << endl;
	cout << "	's corrected-word' : Swap wrong-word with corrected-word" << endl;
	cout << "	'S corrected-word' : Swap the current and all future occurrences of wrong-word with corrected-word" << endl;
	cout << "	'i' 		   : Ignore wrong-word" << endl;
	cout << "	'I' 		   : Ignore wrong-word for the current occurrence and all future ones" << endl;
	cout << "	'a' 		   : Add wrong-word to _Dictionary in the user's home directory, creating this" 
	<< "file if it is not already present. Also, treat wrong-word as correct" << endl;
	cout << "	'q' 		   : Quit spell checker and save contents" << endl;

	getline(cin,user_input);
	
	while (true) {
	    
	    if (user_input[0] == 's') { 
		string swappedWord = user_input.substr(2,user_input.length());
		replace( it, it+1, word, swappedWord);
		break;
	    }
				    
	    else if (user_input[0] == 'S' ) {
		string swappedWord = user_input.substr(2,user_input.length());
		
		replace(inputFile.begin(), inputFile.end(),word, swappedWord);
		globalIgnoredWords.push_back(swappedWord);
		break;
	    }
	    
	    else if (user_input[0] == 'i' ) {
	    break;
	    }
		    
	    else if (user_input[0] == 'I' ) {
		globalIgnoredWords.push_back(word);
		break;
	    }
	    
	    else if (user_input[0] == 'a' ) {
		usrdict2.addWord(word);
		break;
	    }
	    else if (user_input[0] == 'q' ) {
		writeVectoFile(inputFile, "outputFile.txt");
		cout << "Duration: " << usrdict.timeInSeconds << " seconds" << '\n';
		cout << "First 3 words in self-organizing linked list: " << '\n';
		usrdict.printFirstThree();
		exit(1);
		break;
	    }
	    else
		cout << "Invalid entry; Please try again\n";
	}  
	}
    }

    // write outputFile
    writeVectoFile(inputFile, "outputFile.txt");

    // write back _Dictionary
    usrdict2.dump();

    return 0;

}





























