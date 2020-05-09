#include <stdio.h>
#include <string.h>

/***************
* Jeffrey Marple
* Lab 6: Wordlist
****************/

// Makes each word backwards, based on a total of count words.  Note that you will always start with index 2, since index 0 is the name of the executable and index 1 is the list of flags.
void backwards(char **argv, int count);
// Reverses the sentence argv, based on a total of count words.  Again, the list of words starts at index 2.
void reverse(char **argv, int count);
// Sorts the string array argv, based on a total of count words.  Again, the list of words starts at index 2 (which needs to be accounted for in your sorting algorithm).
void sort(char **argv, int count);

int main(int argc, char* argv[]){




		if(argc < 2){

			printf(" Usage: program [-(b|r|s)+]\n");

		}else if (argv[1][0] == '-'){ 
			
			int length = strlen(argv[1]);
			//after every char past "-" (before the first word) call the appropriate function
			for (int j = 1; j < length ; j++){

				if (argv[1][j] == 'b'){
					backwards(argv, argc);

				}else if (argv[1][j] == 'r'){
					reverse(argv, argc);

				}else if (argv[1][j] == 's'){
					sort(argv, argc);		
				}	

			}


			//print out the final config. of chars
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



	//printf("b\n");
}//end backwards()


void reverse(char **argv, int count){

	int start = 2;
	int end = count-1;
	char* temp;

	while(start<end){

		temp = argv[end];
		argv[end] = argv[start];
		argv[start] = temp;

		start++;
		end--;

	}
	
}



void sort(char **argv, int count){
	
	int length = 0;	

	//lame bubblesort algorithm
	for(int i=2; i<count-1; i++){
		for(int j=2; j<count-i-1; j++){
			
			
			if(strlen(argv[j]) > strlen(argv[j+1])){//string1 is longer than string2 check until len(string2)
				length = strlen(argv[j+1]);
			}else{//check until len(string1)
				length = strlen(argv[j]);
			}			

			//run through both strings to see which comes first
			for(int k=0; k<length; k++){
				
				if(argv[j][k]<argv[j+1][k]){//char in string1 comes before, is correct
					break;
				}else if(argv[j][k]>argv[j+1][k]){//char in string2 comes before, swap strings
					//swap(&argv[j], &argv[j+1]);
					break;
				}

			}
	
		}

	}

	printf("s\n");

}



