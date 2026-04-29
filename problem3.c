#include <stdio.h>
#include <stdlib.h>

void func1(int n, char file[]) {
    FILE *fp = fopen(file, "w");    //Open the file in write-only mode
    int *res =(int *)malloc(n * sizeof(int));  //Allocate memory
    res[0]=1,res[1]=1;   //Build a Fibonacci sequence with the first two elements of the array set to 1
    int i,j;
    for(i=2;i<n;i++){
        res[i]=res[i-1]+res[i-2];   //The Fibonacci sequence, where the value of each term equals the sum of the two preceding terms.
    }
    
    for(j=0;j<n;j++){
        fprintf(fp,"%d ",res[j]);  //print the result
    }
    free(res); //Release memory
    fclose(fp); //Close the file 
}

void func2(char file[]) {
    FILE *fp=fopen(file, "r");  //Open the file in read-only mode

    int sum=0,cnt=0;  //use sum to record the sum of the number,cnt to record the times of even number
    int num; //use num to record every bit of the number
    while(fscanf(fp,"%d",&num)==1){  //If a number is read, it means the numbers have not been fully traversed, and the loop continues.
        sum += num;
        if (num % 2 == 0) {  //This indicates that the number is even.
            cnt++;
        }
    }
    
    fclose(fp); //Close the file
    printf("Sum: %d, Even count: %d\n", sum, cnt);
}

int main() {
    int n;
    char filename[100];  
    
    printf("please enter interger n and filename:\n");
    scanf("%d %s", &n, filename);
    func1(n, filename);  //Call func1
    printf("create file: %s\n", filename);
    

    char nameFile[100] = "yangyue.txt";   
    FILE *fp=fopen(nameFile, "w");  //Create a file whose name is "yangyue.txt" 
    if(fp!=NULL){
        int ID[10] = {2,5,3,7,0,2,0,2,1,6};  //Input my student ID
		int i;  
        for(i=0;i<10;i++){
            fprintf(fp,"%d ",ID[i]);    //Print the ID number into the file
        }
        fclose(fp);
    }
    func2(nameFile);//Call func2
    
    return 0;
}
