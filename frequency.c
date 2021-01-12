#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
 
#define alpha_size 26
 

 
// A Trie node
struct Trie
{
    bool isLeaf;    // true when node is a leaf node
    struct Trie* character[alpha_size];
    long unsigned int count;  // count the number of occurrences per node in the Trie
};
 
// build new Trie node
struct Trie* getNewTrieNode()
{
    struct Trie* node = (struct Trie*)malloc(sizeof(struct Trie));
    node->isLeaf = false;
    for (int i = 0; i < alpha_size; i++){
        node->character[i] = NULL;
 	node->count =0;
 	}
    return node;
}
 
// insert a string to the Trie
void insert(struct Trie *head, char* str, int numOfchars)
{
    struct Trie* curr = head;
    for(int i=0;i<=numOfchars;i++)
    {
        if (curr->character[*(str+i) - 'a'] == NULL)
            curr->character[*(str+i) - 'a'] = getNewTrieNode();    
        curr = curr->character[*(str+i) - 'a'];
    }
    curr->isLeaf = true;
    curr->count++;
}
 

// check if current node is leaf node or not 
bool isLeafNode(struct Trie* root) 
{ 
    return root->isLeaf != false; 
} 

// display the content of Trie by alphabet order
void display(struct Trie* root, char str[], int level) 
{ 
    if (isLeafNode(root))  
    { 
        str[level] = '\0'; 
        printf("%s %ld\n",str,root->count);
    } 
    int i; 
    for (i=0; i<alpha_size ; i++)  
    { 
        if (root->character[i])  
        { 
            str[level] = i + 'a'; 
            display(root->character[i], str, level + 1); 
        } 
    } 
} 

// display the content of Trie by reverse order
void displayReverse(struct Trie* root, char str[], int level) 
{ 
    if (isLeafNode(root))  
    { 
        str[level] = '\0'; 
        printf("%s %ld\n",str,root->count);
    } 
  
    int i; 
    for (i=alpha_size-1; i >=0 ; i--)  
    { 
        if (root->character[i])  
        { 
            str[level] = i + 'a'; 
            displayReverse(root->character[i], str, level + 1); 
        } 
    } 
} 
   
 
 

int main(int argc, char* argv[])
{

    FILE *fp;
    char ch;
    char *c;
    int result;
    struct Trie* head = getNewTrieNode();
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
	    int numOfchars = -1;
	    while ((ch = fgetc(fp)) != EOF)
            {
		result = isspace(ch);
		if(result!=0) // if ch is space
		{ 
			for(int i = 0; i<=numOfchars; i++)
			{
				*(c+i) = tolower(*(c+i));
			}
				insert(head,c,numOfchars);
				free(c);	
				numOfchars = -1;
			
		}
	      	else if(isalpha(ch))
	      	{
	      		numOfchars++;
	      		if (numOfchars==0)
	      		{
				c = (char*)malloc(sizeof(char));
      			}
	      		else
	      		{
	      			c = (char*)realloc(c,sizeof(char));
	      		}
		strncat(c,&ch,1); 
		}
	     }
	}
	
	
    int level = 0; 
    char str[20]; 
  
     if(argc==1){
    	display(head, str, level); 
     }
     else if(argc==2){
     	if(*argv[1]=='r')
     	displayReverse(head,str,level);
     	}
     	
    
    //printf("\n");
    //displayReverse(head,str,level);
    free(head);
    
    fclose(fp);
    //free(fp);

    
    return 0;
    
}
