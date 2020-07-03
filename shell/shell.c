#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h> 
#include<sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "cd.c"
#include "echo.c"
#include "pwd.c"
#include "ls.c"
#include "pinfo.c"
#include<wait.h>
#include "history.c"
#include<stdint.h>
#include "watch.c"
#include <termios.h>
#include <sys/ioctl.h>
#include <stdbool.h>
#include"jobs.c"
#include"kjob.c"
#include"overkill.c"
#include "handler.c"
#include "bg.c"
#include "setenv.c"
#include "unsetenv.c"
#include "check.c"
#include "redir.c"
#include "pipe.c"
#include "fore.c"
#define len 100000
#include "prompt.c"
int jo[100];
char *args[100];
int point;
char name[100][100];
char s[len], h[len], s1[len], str[len];
int f=0, l, l1;
int ppid;
void handler(int sig)
{
	handler1(s1,h,s,str,sig,jo);
	return ;
}
void handler2()
{
	printf("\n");
	return ;
}

void handler3()
{
	if(ppid!=0)
	{
		int flag = 1;
		for(int i=0;i<100;i++)
		{
			if(jo[i] == ppid)
			{
				flag = 0;
				printf("\n%s\t\t%s\t[%d]\n","Stopped",name[i],jo[i]);
				break;
			}
		}
		if(flag)
		{
			jo[point] = ppid;
			// back_proc[num_background_proc].state = 1;
			if(strcmp(args[0],"fg"))
			strcpy(name[point],args[0]);
			else 
			{
				strcpy(name[point],name[atoi(args[1])-1]);
			}
			// back_proc[num_background_proc].jobid = num_background_proc;

			printf("\n%s\t\t%s\t[%d]\n","Stopped",name[point],jo[point]);

			point++;
		}

		int temp = ppid;
		kill(ppid, SIGSTOP);
		ppid = 0;
	}
}

int main(int argc, char const *argv[])
{
	// signal(SIGCHLD, handler);
	check(jo,name);
	// signal(SIGCHLD,check(jo,name));
	char const*sy = argv[0];
	char ac [len];
	char *ptr;
	signal(SIGINT, handler2);
	signal(SIGTSTP,handler3);
	struct node *rear=NULL;
    struct node *front =NULL;
	ptr = realpath(sy, ac);
	int heh = strlen(ac);
	int t2,all=0,counter =0;
	for(int i=heh-1;i>=0;i--)
	{
		if(ac[i]=='/')
		{
			t2 =i;
			break;
		}
	}
	for(int i=0;i<t2;i++)
	{
		s1[i] = ac[i];
	}
	s1[t2] = '\0';
	int start=0;
	char *str1= (char *)malloc(len*sizeof(char));
	for(int i = 0; i < 100; i++)
		jo[i] = -1;
	// int point = 0;
	while(1)
	{
		char *x= (char *)malloc(len*sizeof(char));
		strcpy(s,getlogin());
		int a = gethostname(h, len);
		check(jo,name);
		getcwd(str,len);
		ptr = realpath(sy, x);
		for(int i=0;i<l;i++)
		{
			x[i]=s1[i];
		}
		x[l] = '\0';
		f =0;
		prompt(s1,h,s,str);
		char *str2 = (char *)malloc(len*sizeof(char));
		scanf(" %[^\n]%*c",str2);
		str1 = strtok(str2,";");
		while(str1!=NULL)
		{	
			strcpy(x,s1);
			struct node * lo = hw(counter,rear,front,str1,x);
			rear = lo;
			front = lo->prev;
			counter++;
			check(jo,name);
			int bg =0,li=-1, status, i=0;
			int stud=strlen(str1);
			char* end;
			char *stupa = (char *)malloc(len*sizeof(char));;
			strcpy(stupa,str1);
			// char* token1 = strtok_r(stupa, " ", &end);
            
            char *arg[10][100];
			i = 0;
			char *end2;
			char *token2 = strtok_r(stupa,"|",&end2);
			int flag3=0;
			int noco=0;
			while(token2!=NULL)
			{
				flag3++;
				int p12= 0;
				char* token1 = strtok_r(token2, " ", &end);
				while(token1!=NULL)
				{
					if(strcmp(token1, "&")!=0)
					{
						arg[flag3-1][p12++] = token1;
						args[i++] = token1;
					}
					token1 = strtok_r(NULL," ", &end);
				}
				arg[flag3-1][p12] = NULL;
				token2 = strtok_r(NULL,"|",&end2);
			}
			args[i] = NULL;
			if(flag3!=1)
			{
				pip(flag3,arg);
				str1 = strtok(NULL,";");
			}
			else
			{
			args[i]=NULL;
			int yop = i;
			int r1 = 0, r2 = 0, r3 = 0,p6=0, p7 = 0, p8= 0;
			for(int j=strlen(str1)-1;j>=0;j--)
			{
				if(str1[j]=='&')
				{
					bg = 1;
					li = j;
					break;
				}
			}
			for(int j = 0; j < i ; j++)
			{
				if(!strcmp(args[j],"<"))
				{	
					p6 = j;
					r1 = 1;
				}
				else if(!strcmp(args[j],">"))
				{
					p7 = j;
					r2 = 1;
				}
				else if(!strcmp(args[j],">>"))
				{
					p8 = j;
					r3 = 1;
				}
				
				// printf("%s %d %d ",args[j],j,i );
			}
			// printf("%d %d %d",r1,r2,r3);
			if(r1==1&&r2==0&&r3==0)
			{
				redir(p6,i,args);
			}
			else if(r2==1&&r1==0)
			{
				redir1(p7,i,args);
			}
			else if(r1==1&&r2==1)
			{
				redir2(p6,p7,i,args);
			}
			else if(r1==1&&r3==1)
			{
				redir3(p6,p8,i,args);
			}
			else if(r3==1&&r1==0)
			{
				redir4(p8,i,args);
			}
			else{
			int strl = strlen(str1);
			check(jo,name);
			if(!strcmp(args[0],"cd"))
			{
				cd(args[1],strl,x);
			}
			else if(!strcmp(args[0],"pwd"))
			{
				pwd(len);
			}
			else if(!strcmp(args[0],"echo"))
			{
				if(yop>1)
					echo(str1,strl);
				else if(args[yop]==NULL)
					printf("\n");
			}
			else if(!strcmp(args[0],"ls"))
			{
				ls(args[1],strl,x,l);
			}
			else if(!strcmp(args[0],"pinfo"))
			{
				pinfo(str1,args[1],strl,x,l);
			}
			else if(!strcmp(args[0],"exit")||!(strcmp(args[0],"quit")))
				exit(0);
			else if(!strcmp(args[0],"history"))
			{
				if(args[1]==NULL)
					hp("10",x);
				else 
					hp(args[1],x);
			}
			else if(!strcmp(args[0],"nightswatch"))
			{
				if(!strcmp(args[yop-1],"dirty"))
					dirty(args[1],args[2]);
				else
					rupt(args[2]);
			}
			else if(!strcmp(args[0],"jobs"))
			{
				jobs( jo, name);
			}
			else if(!strcmp(args[0],"kjob"))
			{
				kjob(args[1],args[2],jo);
			}
			else if(!strcmp(args[0],"overkill"))
			{
				overkill(jo,name);
				check(jo,name);
			}
			else if(!strcmp(args[0],"bg"))
			{
				if(i!=2)
				{
					printf("Invalid Input\n");
				}
				else
				back(jo,args[1]);
			}
			else if(!strcmp(args[0],"fg"))
			{
				ppid = atoi(args[1]);
				int tmp = ppid;
				ppid = jo[ppid-1];
				// jo[tmp-1] = -1;
				fore(jo,args[1]);
			}
			else if(!strcmp(args[0],"setenv"))
			{
				if(args[1]==NULL||args[3]!=NULL)
				printf("error\n");
				else
				set_env(args[1],args[2]);
			}
			else if(!strcmp(args[0],"unsetenv"))
			{
				if(args[1]==NULL||args[2]!=NULL)
					printf("error\n");
				else
				unset_env(args[1]);
			}
			else
			{
				int wpid;
	            int pid = fork();
	            if(pid == -1) {
	                printf("No such command\n");
	                exit(1);
	            }
	            else if(pid == 0) {
	            	if(bg)
	            		setpgid(0,0);
	                execvp(args[0], args);
	                exit(0);
	            }
	            else if(bg==0){

	            	ppid=pid;
                	waitpid(pid,&status, WUNTRACED );
	            }
	            else
	            {
	            	jo[point] = pid;
	            	strcpy(name[point],args[0]);
	            	point++;
	            }
	        }
	        check(jo,name);
		}
			str1 = strtok(NULL,";");
		}
		}
	}
}
