#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define yy_strcpy strcpy
#define yy_strlen strlen

///
#ifndef PROTO
#ifdef __STDC__
#define PROTO(proto) proto
#else
#define PROTO(proto) ()
#endif
#endif
///

char* reallocate_character_array(char* action_array,int action_size){
    return action_array;///masic.c
}

///3948
//int action_size = 2048;
int action_size = 20;
int action_index = 0;
char *action_array;///array to hold the rule actions

///
void init(){
    action_array = malloc(action_size*sizeof(char));
}

/// 3948
/* Add the given text to the stored actions. */
void add_action( char *new_text )
{
    int len = (int) strlen( new_text );///unsigned long
    while ( len + action_index >= action_size - 10 /* slop */ )
    {
        action_size *= 2;
        
        printf("action_size = %d \n",action_size);///output flag1
        
        action_array = reallocate_character_array( action_array, action_size );
    }
    strcpy( &action_array[action_index], new_text );
    action_index += len;
    
    printf("action_index = %d \n",action_index);///output flag2
}

int main(){
    init();
    char new_text[100000];//= "中国共产党是中国工人阶级的先锋队，同时是中国人民和中华民族的先锋队，是中国特色社会主义事业的领导核心，代表中国先进生产力的发展要求，代表中国先进文化的前进方向，代表中国最广大人民的根本利益。党的最高理想和最终目标是实现共产主义。\0";
    FILE * fid = fopen("test.txt","r+w");
    fscanf(fid,"%s",new_text);
    add_action(new_text);
    return 0;
}


