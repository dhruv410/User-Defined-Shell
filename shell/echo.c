void echo(char *s, int len)
{
	char *buf = (char *)malloc(len*sizeof(char));
	int tmp;
	int strl = strlen(s);
	int x = 0;
	for(int i=0;i<strl;i++)
	{
		if(s[i]!=' '&&x==2)
		{
			// x = 1;
			tmp =i;
			break;
		}
		else if(s[i]!=' ')
		{
			x = 1;
			continue;
		}
		if(s[i]==' '&&x==1)
		{
			x = 2;
			continue;
		}
	}
	// printf("%d ",tmp);
	int fl=0,st=0,p1=0,lol=0;
	for(int i=tmp;i<len;i++)
	{
		if(s[i]!=' ')
			st = 1;
		if(st!=0)
		{
			if((s[i]==' '||s[i]=='\0')&&lol==0)
			{
				buf[p1] = '\0';
				p1++;
				lol =1;
			}
			else if(s[i]!=' ')
			{
				buf[p1] = s[i];
				p1++;
				lol= 0;
			}
			if(s[i]=='\"')
			{
				buf[p1-1]='\0';
				printf("%s",buf);
				buf[0] = '\0';
				p1 = 0;
				char *p = (char *)malloc(len*sizeof(char));
				int t=i+1, f =0, k;
				for(int j = t; j < len; j++)
				{
					if(s[j]=='\"')
					{
						f = 1;
						k = j;
						break;
					}	
				}
				if(f==0)
				{
					printf("\n");
				}
				else 
				{
					for(int j=t;j<k;j++)
					{
						p[j-t] = s[j]; 
					}
				}
				p[k-t]='\0';
				printf("%s",p);
				i = k;
			}

			else if(s[i]=='\'')
			{
				buf[p1-1] = '\0';
				printf("%s",buf);
				buf[0] = '\0';
				p1 = 0;
				char *p = (char *)malloc(len*sizeof(char));
				int t=i+1, f =0, k;
				for(int j = t; j < len; j++)
				{
					if(s[j]=='\'')
					{
						f = 1;
						k = j;
						break;
					}	
				}
				if(f==0)
				{
					printf("\n");
				}
				else 
				{
					for(int j=t;j<k;j++)
					{
						p[j-t] = s[j]; 
					}
				}
				p[k-t]='\0';
				printf("%s",p);
				i = k;
			}
		}
	}
	buf[len]='\0';
	printf("%s\n",buf);
}