void pinfo(char *st, char *po, int len,char *xp,int l)
{
	// char *po = (char *)malloc(sizeof(char));
	int x=1,i,pd=0,so=0;
	if(po==NULL||po[0]=='\0')
		x=0;
	char ss[20];
	char sp[20];
	if(x==0)
	{
		sprintf(ss,"/proc/%d/exe",getpid());
		sprintf(sp,"/proc/%d/status",getpid());
	}
	else 
	{
		sprintf(ss,"/proc/%s/exe",po);
		sprintf(sp,"/proc/%s/status",po);
	}
	FILE *fp;
	char stri[100],g1[5];
	fp = fopen(sp,"r");
	int cnt =0,xl=0;
	if(fp==NULL)
	{
		perror("");
		return ;
	}
	else
	{
		if(x==0)
		{
			printf("pid -- %d\n",getpid());
		}
		else 
		{
			printf("pid -- %s\n",po);
		}
		int y=0;
		while(fscanf(fp,"%s",stri)!=EOF)
		{
			cnt++;
			if(!strcmp(stri,"State:"))
			{
				y = 1;
				continue;
			}
			if(!strcmp(stri,"VmSize:"))
			{
				// y = 2;
				xl = 1;
				continue;
			}
			if(y==1)
			{
				y = 2;
				printf("Process Status -- %s\n", stri);
			}
			else if(xl==1)
			{
				xl=2;

				printf("memory --   %s (kB) \n", stri);
				break;
			}
		}
	}
	if(xl!=2)
		printf("memory --  unknown \n");
	int length;
	char fullpath[200];
	length = readlink(ss, fullpath, sizeof(fullpath));
	fullpath[length]='\0';
	int kk=0;
	if(length!=-1)
	{
		if(l>length)
			kk=1;
		else 
		{
			for(int i=0;i<l;i++)
			{
				if(xp[i]!=fullpath[i])
				{
					kk=1;
					break;
				}
			}
		}
		if(kk==1)
		printf("Executable path -- %s\n",fullpath);
		else 
		{
			printf("Executable path -- ~");
			for(int i=l;i<length;i++)
				printf("%c",fullpath[i]);
			printf("\n");
		}
	}
	else 
		printf("Executable path -- unknown \n");
	return ;
}