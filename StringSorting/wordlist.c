#include <stdio.h>
#include <string.h>

/***************
* Jeffrey Marple
* Lab 6: Wordlist
****************/

// Makes each word backwards, based on a total of count words.  
void backwards(char **argv, int count);
// Reverses the sentence argv, based on a total of count words. 
void reverse(char **argv, int count);
// Sorts the string array argv, based on a total of count words.  
void sort(char **argv, int count);

int main(int argc, char* argv[]){

		//-----command line checks-----//
		if(argc < 2){
			printf(" Usage: program [-(b|r|s)+]\n");
		}else if (argv[1][0] == '-'){ 
			
			int length = strlen(argv[1]);
			//after every char past "-" (aka, before the first word) 
			//call the appropriate function
			for (int j = 1; j < length ; j++){
				if (argv[1][j] == 'b'){
					backwards(argv, argc);
				}else if (argv[1][j] == 'r'){
					reverse(argv, argc);
				}else if (argv[1][j] == 's'){
					sort(argv, argc);		
				}	
			}
			
			//-----final print of output-----//
			for(int i=2; i<argc; i++){
				printf("%s ", argv[i]);
			}			
			printf("\n");
		}else{
			printf(" Usage: program [-(b|r|s)+]\n");
		}
}//end main


void backwards(char **argv, int count){
	
	char *endPointer, *startPointer, temp;
	int length;

	//for each word after the -b
	for(int j=2; j<count; j++){

		length = strlen(argv[j]);
		//start pointers at front
		startPointer = argv[j];
		endPointer = argv[j];

		//put endPointer at end of word
		for(int i=0; i<length-1; i++){		
			endPointer++;
		}

			//starting from the front and back, swap the chars then ++ and -- respectfully	
			for(int i=0; i<length/2; i++){			
	
				//swap characters in word
				temp = *endPointer;
				*endPointer = *startPointer;
				*startPointer = temp;	
								
				//update pointer positions
				startPointer++;
				endPointer--;
			}
	}
}//end backwards()


void reverse(char **argv, int count){

	int start = 2;
	int end = count-1;
	char* temp;
	
	//swap the first and last word untill pointers overlap
	while(start<end){
		temp = argv[end];
		argv[end] = argv[start];
		argv[start] = temp;

		start++;
		end--;
	}
}//end reverse


void sort(char **argv, int count){

	char* temp;

	//lame bubblesort algorithm
	for(int i=2; i<count-1; i++){
		for(int j=2; j<count-(i-2)-1; j++){
			//compare through both strings to see which comes first				
			if(strcmp(argv[j], argv[j+1]) > 0){//the string2 comes in the alphabet before
				temp = argv[j+1];
				argv[j+1] = argv[j];
				argv[j] = temp;
			}
		}
	}
}//end sort
