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


			for (int j = 1; j < length ; j++){

				if (argv[1][j] == 'b'){
					backwards(argv, argc);

				}else if (argv[1][j] == 'r'){
					reverse(argv, argc);

				}else if (argv[1][j] == 's'){
					sort(argv, argc);		
				}	

			}//end for


			
		}//end outter if



}//end main


void backwards(char **argv, int count){
	
	int* endPointer;
	int* startPointer;
	int* temp;
	int length = 0;
	int i = 0;

	for(int j=2; j<count; j++){
	
		i = 0;
		length = strlen(argv[j]);
		while(*endPointer != *startPointer){		
			
				
				*endPointer = argv[j][length-i] ;
				*startPointer = argv[j][i] ;
					if(*endPointer > *startPointer){
			
						*temp = *endPointer;	
						*endPointer = *startPointer;
						*startPointer = *temp;					
				
					}
		
				i++;				
				
		}//end while
	}//end outterFor



	printf("b");
}//end backwards()


void reverse(char **argv, int count){

	printf("r");
}


void sort(char **argv, int count){

	printf("s");

}

