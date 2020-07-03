#include <termios.h>
#include <sys/ioctl.h>
#include <stdbool.h>
bool keyDown() {
    struct termios oldt, newt;
    int bytes;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ioctl(STDIN_FILENO, FIONREAD, &bytes);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return bytes > 0;
}
void dirty(char *s1, char *s2)
{
	int tm =atoi(s2);
	while(1)
	{
		if(keyDown())
		{
			char ch = getchar();
			if(ch=='q')
				return ;
		}
		sleep(tm);
		char ss[40];
		strcpy(ss,"/proc/meminfo");
		FILE *fp;
		fp = fopen(ss,"r");
		if(fp==NULL)
		{
			perror("");
			return ;
		}
		if(keyDown())
		{
			char ch = getchar();
			if(ch=='q')
				return ;
		}
		char stri[40];
		int h = 0;
		int val =0;
		while(fscanf(fp,"%s",stri)!=EOF)
		{
			fflush(stdout);
			if(!strcmp(stri,"Dirty:"))
			{
				h = 1;
				continue;
			}
			if(keyDown())
		{
			char ch = getchar();
			if(ch=='q')
				return ;
		}
			if(h==1)
			{
				h = 0;
				printf("%s\n", stri);
				break;
			}
		}
		fclose(fp);
		if(keyDown())
		{
			char ch = getchar();
			if(ch=='q')
				return ;
		}
	}
}
void rupt(char *s2)
{
	int xp =0 ;
	int yp=0;
	int tm =atoi(s2);
	while(1)
	{
		if(keyDown())
		{
			char ch = getchar();
			if(ch=='q')
				return ;
		}
		sleep(tm);
		char ss[40];
		strcpy(ss,"/proc/interrupts");
		FILE *fp;
		fp = fopen(ss,"r");
		if(fp==NULL)
		{
			perror("");
			return ;
		}
		if(keyDown())
		{
			char ch = getchar();
			if(ch=='q')
				return ;
		}
		char stri[1001];
		int h = 0;
		int val =0;
		int count=0;
		
		while(fgets(stri,1000,fp)!=NULL)
		{
			fflush(stdout);
			if(count==0||count==2)
			{
				h = 0;
				char *end;
				// printf("%s\n", stri);
				char* token1 = strtok_r(stri, " ", &end);
	            char *args[100];
				int i = 0;
				
				if(count==0&&xp==0)
				{
					xp = 1;
					while(token1!=NULL)
					{
						i++;
						if(i==1)
							printf("\t\t");
						// else
						printf("%s\t\t",token1);
						token1 = strtok_r(NULL," ", &end);
					}
					// printf("\n\n\n");
				}
				else if(count==2)
				{
					while(token1!=NULL&&i<12)
					{
						i++;
						if(yp!=0&&i==1)
							printf("\t\t");
						else if(i==1)
							yp=1;

						printf("%s\t\t",token1);
						token1 = strtok_r(NULL," ", &end);
					}
					printf("\n\n\n");
				}
				// break;
			}
			count++;
		}
		fclose(fp);
		if(keyDown())
		{
			char ch = getchar();
			if(ch=='q')
				return ;
		}
	}
}

