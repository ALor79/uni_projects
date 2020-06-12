#include <stdio.h>
#include <string.h>

void swapChar(char string [], int i,int j){
    int temp = string[i];
    string[i] = string[j];
    string[j] = temp;
}


int partitionChar(char string[], int first, int last) {
    swapChar(string, first, (first + last) / 2); // swapChar middle value into first pos
    char pivot = string[first]; 	 // remember pivot

    int index1 = first + 1; // index of first unknown value
    int index2 = last;    // index of last unknown value
    
    
    
    while (index1 <= index2) { // while some values still unknown
        if (string[index1] <= pivot)
            index1++;
        else if (string[index2] > pivot)
            index2--;
        else {
            swapChar(string, index1, index2);
            index1++;
            index2--;
        }
    }
    swapChar(string, first, index2); // put the pivot value between the two
    // sublists and return its index
    return index2;
}



void QsortChar(char string[], int first, int last){

    //if the size of the string is equal to 0 or 1, the string is sorted by definition
    

    if(first < last){
        char pivotindex = partitionChar(string, first, last);
        QsortChar(string, first, pivotindex-1);
        QsortChar(string, pivotindex+1, last);
    }

}



int main() {
    char i, count;

    //printf("How many elements would you like to enter?: ");
    //scanf("%c", &count);
   char str[]="Hello World!";
    // printf("Enter %c elements: ", count);
    count=strlen(str);
    // for (i =0; i < count; i++)
    //     scanf("%c", &str[i]);

    QsortChar(str, 0, strlen(str)-1);

    printf("Sorted string:\n");
    for (i =0; i < count; i++){
        if (str[i]!='\0')
        {
            printf("%c", str[i]);
        }else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");    
        
        
}
