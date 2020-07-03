void cd(char *str, int l, char *x)
{
	int fl =0;
	if(str!=NULL)
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		{
			fl =1;
			if(str[i]=='.')
			{
				if(str[i+1]=='.')
				{
					chdir("..");
					if(str[i+2]=='/'){
					char *p = (char *)malloc(100*sizeof(char));
					int j;
					for(j=i+3;str[j]!='\0';j++)
					{
						p[j-i-3]=str[j];
					}
					p[j-i-3] = '\0';
					chdir(p);
				}
				}
				else if(str[i+1]=='\0')
					break;
			}
			else if(str[i]=='~')
			{
				chdir(x);
				if(str[i+1]=='\0')
					break;
				if(str[i+1]!='/'&&str[i+1]!=' ')
					printf("error\n");
				char *p = (char *)malloc(100*sizeof(char));
				int j;
				for(j=i+2;str[j]!='\0';j++)
				{
					p[j-i-2]=str[j];
				}
				p[j-i-2] = '\0';
				chdir(p); 
			}	
			else 
			{
				char *p = (char *)malloc(100*sizeof(char));
				int j;
				for(j=i;str[j]!='\0';j++)
				{
					p[j-i]=str[j];
				}
				p[j-i] = str[j];
				chdir(p);
			}
			break;
		}
	}
	else 
		chdir(x);
	if(fl==0)
		chdir(x);
}