#include <iostream>
using namespace std;

int length(char arr[]){
    int i;
    for(i=0; arr[i] != '\0'; ++i);
    return i;
}

void concatenate(char dest[], const char arr1[], const char arr2[]){
    int i;
    for(i=0; arr[i] != '\0'; ++i){
        dest[i] = arr1[i];
    }
    for(int j=0; arr2[j] != '\0'; ++j, ++i){
        dest[i] = arr2[j];
    }
    dest[i] = '\0';
}

void insertsub(char dest[], const char sub[], int position){
    int i=0, j=0;
    while(dest[i] != '\0'){
        i++;
    }
    int subLen = 0;
    while(sub[subLen] != '\0'){
        subLen++;
    }
    if(position<0 || position>i){
        cout<< "Invalid!" << endl;
        return;
    }
    for(int k=i; k>=position; --k){
        dest[k+subLen] = dest[k];
    }
    for(j=0; j<subLen; ++j){
        dest[position+j] = sub[j];
    }
    dest[i+subLen] = '\0';
}

int compare(const char str1[], const char str2[]){
    int i=0;
    while(str[i] != '\0' && str2[i] != '\0'){
        if(str1[i]<str2[i]){
            return -1;
        }else if(str1[i]>str2[i]){
            return 1;
        }
        i++;
    }
    if(str1[i] == '\0' && str2[i] == '\0'){
        return 0;
    }else if(str1[i] == '\0'){
        return -1;
    } else{
        return 1;
    }
}

int main(){
    char str1[50] = "Hello";
    char str2[50] = "World1";
    cout << "Length of str1 is: " << length(str1) << endl;
    cout << "Length of str2 is: " << length(str2) << endl;
    char concatenated[100];
    concatenate(concatenated, str1, str2);
    cout << "String after inserting substring is: " << insertsub(str1, str2, 5) << endl;
    int comparisonResult = compare(str1, str2);
    cout << str1 << (comparisonResult < 0? "is less than" : (comparisonResult>0)? "is greater than" : "is equal to") <<str2 << endl;
}