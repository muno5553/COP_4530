// Gustavo J. Munoz
// Assignment 1 - Spell Checker
// Header File

#include <fstream>
#include <set>
#include <locale>

using namespace std;

class Dictionary{

        public:
		set<string> dictSet; 			
		locale loc;
		string fileLoc;
		
                Dictionary(string fileLocation){	

			fileLoc = fileLocation;
			fstream ifs(fileLocation.c_str(), fstream::in);	
			
			if(ifs.is_open()){
			  string str;								  
			  while (ifs >> str){
			    dictSet.insert(str);
			  }
			  ifs.close();
			}
			else{

			  ifs.open(fileLocation.c_str(),fstream::out);
			  ifs.close();
			}
                } 
                
                void printSelf(){			//print to screen dictionary word
                        for (set<string>::iterator it = dictSet.begin()  ; it!=dictSet.end()  ; it++  ){
                                cout << *it << endl;
			}
                }
                
                bool match(string word){
		  string upWord = string(1,toupper(word[0],loc))+word.substr(1);
		  string loWord = string(1,tolower(word[0],loc))+word.substr(1);

		  return(  (dictSet.find(loWord) != dictSet.end()) || (dictSet.find(upWord) != dictSet.end())  );    
		}
		
		void addWord(string word){
		  dictSet.insert(word);
		}
		
		void dump(){
		  fstream tmp(string(fileLoc).c_str(), fstream::out);
		  for(set<string>::iterator it=dictSet.begin(); it!=dictSet.end();it++){
		    tmp << *it << " ";
		  }
		}

};
