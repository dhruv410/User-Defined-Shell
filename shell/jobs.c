void jobs(int jo[], char name[][100])
{
	for(int i = 0; i <100; i++)
	{
		if(jo[i]!=-1)
		{
			// printf("%d ",i );
			// fflush(stdout);
		int x=1,pd=0,so=0;
		char ss[50];
		char sp[50];
		// printf("%d ",i );
			// fflush(stdout);
		sprintf(ss,"/proc/%d/exe",jo[i]);
		sprintf(sp,"/proc/%d/status",jo[i]);
		FILE *fp;

		int cnt =0,xl=0;
		char stri[100],g1[5];
		fp = fopen(sp,"r");

		if(fp==NULL)
		{
			perror("xx");
			return ;
		}
		else
		{
			int y=0;
			while(fscanf(fp,"%s",stri)!=EOF)
			{
				cnt++;
				if(!strcmp(stri,"State:"))
				{
					y = 1;
					continue;
				}
				if(y==1)
				{
					y = 2;
					// printf(" %s\n", stri);
					if(stri[0]=='T')
					{
						printf("[%d] Stopped %s [%d]\n", i+1,name[i],jo[i]);
						break;
					}
					// if(stri[0]=='R')
					else
					{
						printf("[%d] Running %s [%d]\n", i+1,name[i],jo[i]);
						break;
					}
				}
			}
		}
		fclose(fp);
	}
	}
}
