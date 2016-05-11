#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int periodLength(char *str){

  int len = strlen(str);
  int pos,cnd;
  // printf("%s %d\n",str,len);
  int *arr = (int*)malloc(sizeof(int)*len);
  // int arr[100];
  arr[0] = arr[1] = 0;
  for(pos =1,cnd=0; pos<len;){
    if(str[pos] == str[cnd]){
      // ++cnd;
      arr[pos++] = ++cnd;
      // pos++;
    }else if(cnd > 0){
      cnd = arr[cnd];
    }else{
      arr[pos++] = 0;
      // pos++;
    }
    if(arr[pos-1]>=len/2){
      return (pos-len/2);
    }else{
      // printf("V[%d] = %d\n",pos-1,arr[pos-1]);
    }
  }
  return -1;
}

int main(int argc, char **argv){
  if(argc>1){
    char *cont_str = (char*)malloc(sizeof(char)*strlen(argv[1])*2);
    strcat(cont_str,argv[1]);
    strcat(cont_str,argv[1]);
    printf("%d\n",periodLength(cont_str));
  }  
  return 0;
}