#include<stdio.h>
#include<string.h>
char grid[5][5];
void playfair(char a,char b)
{
	int i,j,r1,c1,r2,c2;
for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++)
    {
       if(grid[i][j] == a)
       {
         r1=i; c1=j;
       }
       if(grid[i][j] == b)
       {
         r2=i; c2=j;
       }
    }
  }
  if(r1==r2) //when both characters in same row
  {
    if(c2==4) //for char in last column
       printf("%c%c ", grid[r1][c1+1], grid[r2][0]);  
    else
       printf("%c%c ", grid[r1][c1+1], grid[r2][c2+1]);
  }
  if(c1==c2)//when both characters in same column
  {
    if(r2==4) //for char in last row
       printf("%c%c ", grid[r1+1][c1], grid[0][c2]); 
    else
       printf("%c%c ", grid[r1+1][c1], grid[r2+1][c2]); 
  }
  //when characters are not in a same row and column
  if(r1 != r2 && c1 != c2) 
  {
    printf("%c%c ", grid[r1][c2], grid[r2][c1]); 
  }

}
int main()
{
	char text[50],key[50],filter[26],temptext[50];
	char temp[26]={'a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int i=0,j=0,k=0,flag=0,check=0,row,col,count=0;
	printf("enter only lower case");
    scanf("%s",text);
    scanf("%s",key);
    for(k=0;k<strlen(key);k++)
    	{
    		if(key[k]=='j')
    		{
    			grid[i][j]=='i';
    			flag=1;
			}
			else
			{
    		grid[i][j]=key[k];
    		j+=1;
    		if(j==5)
    		{
    			j=0;
    			i+=1;
			}
		    }
    		
	   }
	   row=i;
	   col=j;
    //filter keys from alphabets.
    k=0;
    for(i=0;i<26;i++)
    {
    	check=0;
    	for(j=0;j<strlen(key);j++)
    	{
    	   if(key[j]==temp[i])
		   {
		   	check=1;
		   	break;
		   }
		}
		if(check==0)
		{
			filter[k++]=temp[i];
		}
		
	}
	printf("\n");
	k=0;
	//inserting other alphabets in grid
	j=col;
	for(i=row;i<5;i++)
	{
		while(j<5)
		{
			grid[i][j]=filter[k];
			j++;
			k++;
		}
		j=0;
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ",grid[i][j]);
		}
		printf("\n");
	}
	
// converting into playfair cipher
	for(i=0;i<strlen(text);)
	{  
		//if all segments are unique and you are left with last column you have to place 'z'
		 if(text[i]&&text[i+1]=='\0')
		{
			playfair(text[i],'z');
			break;
		}
		
		else if(text[i]==text[i+1])
		{
			playfair(text[i],'x');
			i+=1;
		}
		else
		{
			playfair(text[i],text[i+1]);
			i+=2;
		}
		
	}
}

