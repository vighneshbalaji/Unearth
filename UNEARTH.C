#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void norep(int a[])//array as parameter......it is used to call by refence
{
int flag=0,c[80],i=0,j=0,s=0;
c[0] = a[0];//first num to assign another array..because it is never repeat
for ( i=1 ; i < 20 ; i++ )   //this for loop it is used no rep num
{   flag=0;
	for ( j=0 ; j < i ; j++ )
	  {
	    if (a[j]==a[i])
	      {  flag=1;   break;  }
	   }
  if (flag==0)  c[s++]=a[i];
  if(s==10)       break;
}
for( i=0 ; i < 10 ; i++ )//again the numbers are assigned in A array
       a[i]=c[i];
}
void norepran(int a[])
{
int i=0;
for ( i = 0 ; i < 20; i++ )//this for loop it is used to generate randomly n numbers
a[i]=rand()%24;
norep( a );//this function is used to no rep number...
}
int arrst(char a[][80],char b[],int l,int j,int y)
{
int i=0;
for(i=0;i<l;i++)
{
if(a[j][i]==' ')  { b[i]=' '; y++; }
else              b[i]='*';
}
b[i]='\0';
return(y);
}
int chec(char s[][80],char crct[],char c,int l,int m,int i,int y,char wr[][80],int w)
{
int k=0,x=0,di=0;
di=i;
for(x=0;x<l;x++)
  if( s[m][x] == c )
  {  crct[x] = c; y++; k=1; }
  if( k != 1 ){ wr[w][di++] = c ; wr[w][di++]=' '; wr[w][di]='\0'; i++;}
  return(i);
}
void che(char c[],char op,int l)
{
int i=0;
for(i=0;i<l;i++)
if(c[i]==toupper(op))
	 c[i]=' ';
}

char noption(char ch,char check[],int rep,char chk[],char copt[][150],int m,int k,char cl[],int i,char wr[][80],int ans,char c[])
{
int j=0;
while(j<rep)
 if(ch==check[j])
  {
      system("cls");
printf("\n\n\n\t%s",chk);
printf("\n\n\n\n\t\t\t\t\t\t\t\t\tWRONG GUESS\n\n");
printf("\n\t\t\t\t\t\t\t\t\t%s\n",wr[i]);
printf("\t\t\tBONE OF CONTENTION\n\n");
printf("\t\t\t%s\n\n\n\n",c);
printf("\n\t\t\t\t\t\t\t\t\tAnswered");
printf("\n\t\t\t\t\t\t\t\t\t( %d / %d )",ans,i);


  if((k > 3 )&&(cl[i]=='!'))    { /*gotoxy(1,13);*/ printf("\t\t--------------clue-------------\n\n%s",copt[m]); }

  fflush(stdin);
  printf("\n\tEnter character: ");
  scanf("%c",&ch);
  j=0;
  continue;
  }
  else
  j++;

  return(ch);
}
void chkcl(char copt[][150],char cl[],int m,int k,int i,char wr[][80],int ans,char c[])
{

printf("\n\n\n\n\t\t\t\t\t\t\t\t\tWRONG GUESS\n\n");
printf("\n\t\t\t\t\t\t\t\t\t%s\n",wr[i]);
printf("\t\t\tBONE OF CONTENTION\n\n");
printf("\t\t\t%s\n\n\n\n",c);

//gotoxy(65,9);
printf("Answered");
//gotoxy(65,11);
printf("( %d / %d )",ans,i);
if((k>3)&&(cl[i]=='!')) { /*gotoxy(1,13);*/printf("\t\t--------------clue-------------\n\n%s",copt[m]);getch(); }
 else if ((k > 3 )&&(k<6))
  {
	/*gotoxy(1,12); */printf("For Clue press `!'");
	getch();
	if(cl[i]=='!') {/*gotoxy(1,13);*/ printf("\t\t--------------clue-------------\n\n%s",copt[m]);getch(); }
  }
}
int main ()
{
  FILE *fh,*fho,*com,*usrpas;
  char  a[30][80],b[80],c[80],check[80],chk[150],ch=0,opt[150],copt[30][150],cl[5],ex,wr[30][80];
  char rate[10],comment[200],name[30],cq;
  char usrpass[3][20],usrn[20],pasw[20],cp;
  char keys[150]={"A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z"};
  int i = 0,op=0,j=0,len=0,ran[20],l=0,m=0,k=0,y=0,key=0,ck=0,rep=0,leng=0,w=0,ans=0;
  int usr=0,pas=0,lu=0,q=0,t=0,ps=0,ascii=0;
time_t vb;
srand((unsigned) time(&vb));
system("cls");

		  printf("\t-------------UNEARTH------------\n\n\n");//game title

printf("1.INDIAN CRICKET PERSONALITY\n\n2.COMPUTER JARGON WORDS\n\n");//topics
printf("ENTER OPTION: ");//topic enter
fflush(stdin);

scanf("%d",&op);
            if(op==1)       {    fh=fopen("isp.mvb","r"); fho=fopen("ispop.mvb","r"); }
            else if(op==2)  {    fh=fopen("cjw.mvb","r"); fho=fopen("cjwop.mvb","r"); }
            else
                            goto exi;
                                if (( fh == NULL )||(fho == NULL))//if file is empty it cannot open
                             {
                                printf(" can't open " );
                                goto end ;
                             }



while ( fgets (b,79,fh ) != NULL )
{
  len=strlen(b);
	 for ( i = 0 ; i < len ; i++ )
		{
		if(b[i]==' ')
		a[j][i]=b[i];
		else
		{
		ascii=toascii(b[i]);
		ascii-=3;
		b[i] = (char) ascii ;
		a[j][i] = b[i];
		}
		 }
  i--;
  a[j++][i]='\0';
}
fclose(fh);//close the file..
j=0;ascii=0;//initialize the variable

while ( fgets (opt,149,fho ) != NULL )
{
  leng=strlen(opt);
	 for ( i = 0 ; i < leng ; i++ )
		{

		if(opt[i]==' ')
		copt[j][i]=opt[i];
		else
		{
		ascii=toascii(opt[i]);
		ascii-=3;
		opt[i] = (char) ascii ;
		copt[j][i] = opt[i];
		}

		}
  i--;
  copt[j++][i]='\0';
}
fclose(fho);//close the file..

norepran( ran );//this function is used for repeat question again.
key=strlen(keys);// is used to find the length of on-screen keyboard.
ans=0;//this variable is used to identify how many question user answers correctly.

for ( i = 0 ; i < 10 ; i++ )
{
k=0,y=0,rep=0,w=0;
l=0,m=0;

strcpy(chk,keys);//COPY THE on-screen keyboard again.
l=strlen(a[ran[i]]);//it is length random question.
m=ran[i];//random question no.
y=arrst(a,c,l,m,y);//this function is used to change question into * characters...
getch();


while(k<6)
{
system("cls");
printf("\n\n\n\t%s",chk);
printf("\n\n\n\n\t\t\t\t\t\t\t\t\tWRONG GUESS\n\n");
printf("\n\t\t\t\t\t\t\t\t\t%s\n",wr[i]);
printf("\t\t\tBONE OF CONTENTION\n\n");
printf("\t\t\t%s\n\n\n\n",c);
printf("\n\t\t\t\t\t\t\t\t\tAnswered");
printf("\n\t\t\t\t\t\t\t\t\t( %d / %d )",ans,i);


fflush(stdin);  printf("\n\tEnter character: "); scanf("%c",&ch);
if(ch=='!')// ! it is clue character ....
    { cl[i]='!'; goto clue;}

ch=tolower(ch);// change the character into lower case character ....

//getch();
//system("cls");

ch=noption(ch,check,rep,chk,copt,m,k,cl,i,wr,ans,c);//(user character,user character array,no of used user characters,question,clue array,random no,no of wrong attempt,clue array,wrong character array,no of question answered correct,question)
check[rep]=ch;  rep++;
k=chec(a,c,ch,l,m,k,y,wr,i);
che(chk,ch,key);

if(strcmp(a[ran[i]],c)==0)
{
     system("cls");
printf("\n\n\n\t%s",chk);
printf("\n\n\n\n\t\t\t\t\t\t\t\t\tWRONG GUESS\n\n");
printf("\n\t\t\t\t\t\t\t\t\t%s\n",wr[i]);
printf("\t\t\tBONE OF CONTENTION\n\n");
printf("\t\t\t%s\n\n\n\n",c);
printf("\n\t\t\t\t\t\t\t\t\tAnswered");
printf("\n\t\t\t\t\t\t\t\t\t( %d / %d )",ans,i);
printf("\n\n\tAWESOME YOU ROCK!!!!!!!"); ans++; break;
}
clue:
chkcl(copt,cl,m,k,i,wr,ans,c);
}
if(strcmp(a[ran[i]],c)!=0) { /*gotoxy(15,17);*/ printf("THE ANSWER IS: %s",a[ran[i]]);}
getch();
system("cls");
if(i<9)
{
printf("DO YOU WANT EXIT('y' or 'n'): ");
fflush(stdin);
scanf("%c",&ex);
ex=tolower(ex);
if(ex=='y')
goto end;
else
{
system("cls");
}}
}
i--;
end:
system("cls");
printf("FEED BACK\n");
com=fopen("comment.mvb","a");
printf("Name: ");
fflush(stdin);
gets(name);
fprintf(com,"%s",name);
printf("\n");
printf("Rate this game (for 5 star): ");
gets(rate);
fprintf(com,"%s",rate);
printf("\n");
printf("Comment: ");
gets(comment);
fprintf(com,"%s",comment);
fclose(fh);
getch();
system("cls");
printf("\t-------------------THANK YOU----------------");
//gotoxy(65,9);
printf("Answered");
//gotoxy(65,11);
printf("( %d / %d )",ans,i+1);
//gotoxy(5,10);
printf("THIS GAME CREATED BY VIGHNESH BALAJI M");
getch();

exi:
getch();

return 0;
}
