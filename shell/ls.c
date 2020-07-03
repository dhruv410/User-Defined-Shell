void ls(char *str, int len, char *sp,int lg)
{
	int tmp =0;
	if(str==NULL)
	{
		len =0;
	}
	char *n =(char *)malloc(len*sizeof(char));
	char *p =(char *)malloc(len*sizeof(char));
	DIR *md;
	struct dirent *mf;
	struct stat ms;
	char buf[512],buf1[512];
	struct group *grp;
	struct passwd *pwd;
	struct dirent **mx;
	int le = strlen(n);
	int fa=0,fl =0;
	for(int i=tmp;i<len;i++)
		p[i-tmp] = str[i];
	p[len-tmp] = '\0';
	for(int i=1;i<len-tmp;i++)
	{
		if(p[i-1]=='-'&&p[i]=='a')
			fa =1;
		if(p[i-1]=='-'&&p[i]=='l')
			fl=1;
	}
	int fc = 0;
	for(int i = 0; i < len-tmp;i++)
	{
		if(p[i]!= ' ')
		{
			fc = 1;
			if(p[i]!='-'&&p[i]!='~'&&fl!=1&&fa!=1)
			{
				for(int j=i;j<len-tmp;j++)
				{
					if(p[j]==' ')
						break;
					n[j-i] = p[j];
				}
				n[len-tmp-i] = '\0';
				if(n[0]=='\0')
				{
					n[0] ='.';
					n[1] = '\0';
				}
				if((md = opendir(n))==NULL)
				{
					printf("Directory doesn't exist\n");
					return ;
				}
				if(stat(n,&ms)<0)
					return ;
				
				fflush(stdout);
				int hu = scandir(n,&mx,0,alphasort);
				int t5=hu;
				if(hu<0)
					perror("scandir");
				else
				{
					while(hu--)
					{
						if(hu==0)
							break;
						sprintf(buf, "%s/%s", n, mx[t5-hu]->d_name);
				        if(mx[t5-hu]->d_name[0]== '.')
				        	continue;
						printf("%s \n", mx[t5-hu]->d_name);
					}
					closedir(md);
				}
				break;
			}
			else if (p[i+1]=='l'&&(p[i+2]==' ' || p[i+2]=='\0')&&fa==0)
			{
				for(int j = i+3; i < len-tmp ; j++)
				{
					if(p[j]!=' ')
					{
						for(int k=j;k<len-tmp;k++)
						{
							if(p[j]!=' ')
							n[k-j] = p[k];
							else 
							break;
						}
						n[len-tmp-j] = '\0';
						break;
					}
				}
				if(p[i+2]=='\0')
				{
					n[0] ='.';
					n[1] = '\0';
				}
				if((md = opendir(n))==NULL)
				{
					printf("Directory doesn't exist\n");
					return ;
				}
				if(stat(n,&ms)<0)
				{
					return ;
				}
				fflush(stdout);
				int hu = scandir(n,&mx,0,alphasort);
				int t5=hu;
				int sop=0;
				if(hu<0)
					perror("scandir");
				else
				{
					while(hu)
					{
						sprintf(buf, "%s/%s", n, mx[t5-hu]->d_name);
				        if(mx[t5-hu]->d_name[0]== '.')
				        {
				        	hu--;
				        	if(hu==0)
				        		break;
				        	continue;
				        }
				        if(stat(buf,&ms)==0)
				        {
					        printf( (S_ISDIR(ms.st_mode)) ? "d" : "-");
						    printf( (ms.st_mode & S_IRUSR) ? "r" : "-");
						    printf( (ms.st_mode & S_IWUSR) ? "w" : "-");
						    printf( (ms.st_mode & S_IXUSR) ? "x" : "-");
						    printf( (ms.st_mode & S_IRGRP) ? "r" : "-");
						    printf( (ms.st_mode & S_IWGRP) ? "w" : "-");
						    printf( (ms.st_mode & S_IXGRP) ? "x" : "-");
						    printf( (ms.st_mode & S_IROTH) ? "r" : "-");
						    printf( (ms.st_mode & S_IWOTH) ? "w" : "-");
						    printf( (ms.st_mode & S_IXOTH) ? "x " : "- ");

						    printf("%ld ", ms.st_nlink);

						    grp = getgrgid(ms.st_gid);

						    pwd = getpwuid(ms.st_uid);

						    printf("%s %s ", pwd->pw_name, grp->gr_name);

						    printf("%5ld",ms.st_size);

						    sprintf(buf,"%s ", ctime(&ms.st_ctime));

						    buf[16]='\0';

						    printf("%s ",buf+3);

							printf("%s \n", mx[t5-hu]->d_name);
						}
						hu--;
						if(hu==0)
							break;
					}
					closedir(md);
					break;
				}
			}
			else if(p[i+1]=='a'&&(p[i+2]==' ' || p[i+2]=='\0')&&fl==0)
			{
				for(int j = i+3; i < len-tmp ; j++)
				{
					if(p[j]!=' ')
					{
						for(int k=j;k<len-tmp;k++)
						{
							if(p[j]!=' ')
							n[k-j] = p[k];
							else 
							break;
						}
						n[len-tmp-j] = '\0';
						break;
					}
				}	
				if(p[i+2]=='\0')
				{
					n[0] ='.';
					n[1] = '\0';
				}
				if((md = opendir(n))==NULL)
				{
					printf("Directory doesn't exist\n");
					return ;
				}
				if(stat(n,&ms)<0)
					return ;
				fflush(stdout);
				int hu = scandir(n,&mx,0,alphasort);
				int t5=hu;
				if(hu<0)
				{
					perror("scandir");
					return ;
				}
				else
				{
					while(hu)
					{
						sprintf(buf, "%s/%s", n, mx[t5-hu]->d_name);
						printf("%s \n", mx[t5-hu]->d_name);
						hu--;
						if(hu==0)
							break;
					}
					closedir(md);
				}
				break;
			}
			else if(p[i]=='~')
			{	
				int j;
				lg = strlen(sp);
				for(j = i+1; j<len-tmp;j++)
				{
					if(p[j]==' ')
						break;
					sp[lg+j-i-1] = p[j]; 
				}
				sp[lg+j-i-1] = '\0';
				// printf("%s ",sp);
				if((md = opendir(sp))==NULL)
				{
					printf("Directory doesn't exist\n");
					return ;
				}
				if(stat(sp,&ms)<0)
					return ;
				fflush(stdout);
				int hu = scandir(sp,&mx,0,alphasort);
				int t5=hu;
				if(hu<0)
					perror("scandir");
				else
				{
					while(hu--)
					{
						if(hu==0)
							break;
						sprintf(buf, "%s/%s", sp, mx[t5-hu]->d_name);
				        if(mx[t5-hu]->d_name[0]== '.')
				        	continue;
						printf("%s \n", mx[t5-hu]->d_name);
					}
					closedir(md);
					// printf("\n");
				}
				break;
			}
			else if((p[i+1]=='a'&&p[i+2]=='l')||(p[i+1]=='l'&&p[i+2]=='a')&&(p[i+3]==' '||p[i+3]=='\0')||(fl==1&&fa==1))
			{
				// printf("1");
				for(int j = i+4; i < len-tmp ; j++)
				{
					if(p[j]!=' ')
					{
						for(int k=j;k<len-tmp;k++)
						{
							if(p[j]!=' ')
							n[k-j] = p[k];
							else 
							break;
						}
						n[len-tmp-j] = '\0';
						break;
					}
				}
				if(p[i+3]=='\0'||(fl==1&&fa==1))
				{
					n[0] ='.';
					n[1] = '\0';
				}
				if((md = opendir(n))==NULL)
				{
					printf("Directory doesn't exist\n");
					return ;
				}
				if(stat(n,&ms)<0)
					return ;				
				fflush(stdout);
				int hu = scandir(n,&mx,0,alphasort);
				int t5=hu;
				int sop=0;
				if(hu<0)
					perror("scandir");
				else
				{
					while(hu)
					{
						sprintf(buf, "%s/%s", n, mx[t5-hu]->d_name);
				        if(stat(buf,&ms)==0)
				        {
					        printf( (S_ISDIR(ms.st_mode)) ? "d" : "-");
						    printf( (ms.st_mode & S_IRUSR) ? "r" : "-");
						    printf( (ms.st_mode & S_IWUSR) ? "w" : "-");
						    printf( (ms.st_mode & S_IXUSR) ? "x" : "-");
						    printf( (ms.st_mode & S_IRGRP) ? "r" : "-");
						    printf( (ms.st_mode & S_IWGRP) ? "w" : "-");
						    printf( (ms.st_mode & S_IXGRP) ? "x" : "-");
						    printf( (ms.st_mode & S_IROTH) ? "r" : "-");
						    printf( (ms.st_mode & S_IWOTH) ? "w" : "-");
						    printf( (ms.st_mode & S_IXOTH) ? "x " : "- ");

						    printf("%ld ", ms.st_nlink);
						    
						    grp = getgrgid(ms.st_gid);
						    
						    pwd = getpwuid(ms.st_uid);
						    
						    printf("%s %s ", pwd->pw_name, grp->gr_name);
						    
						    printf("%5ld",ms.st_size);
						    
						    sprintf(buf,"%s ", ctime(&ms.st_ctime));
						    
						    buf[16]='\0';

						    printf("%s ",buf+3);

							printf("%s \n", mx[t5-hu]->d_name);
						}
						hu--;
						if(hu==0)
							break;				
					}
					closedir(md);
					break;
				}
			}
		}
	}	
	if(fc==0)
	{
		if((md = opendir("."))==NULL)
		{
			printf("Directory doesn't exist\n");
			return ;
		}
		if(stat(".",&ms)<0)
			return ;
		fflush(stdout);
		int hu = scandir(".",&mx,0,alphasort);
		int t5=hu;
		if(hu<0)
			perror(".");
		else
		{
			while(hu--)
			{
				if(hu==0)
					break;
				sprintf(buf, "%s/%s", n, mx[t5-hu]->d_name);
		        if(mx[t5-hu]->d_name[0]== '.')
		        	continue;
				printf("%s \n", mx[t5-hu]->d_name);
			}
			closedir(md);
			// printf("\n");
		}
	}
	return ;
}