void pip(int noco, char *args[][100])
{
	printf("sdaf");
	int t1 = dup(0);
	int t2 = dup(1);
	int fdin = dup(0);
	int fout = dup(1);
	int ret;
	// printf("%d ", noco);
	for(int i = 0; i<noco; i++)
	{
		// if(strcmp(args[i],"quit")==0)
		dup2(fdin, 0);
		close(fdin);
		printf("asdf");
		if(i== noco-1)
		{
			fout = dup(t2);
		}
		else
		{
			int fp[2];
			pipe(fp);
			fdin = fp[0];
			fout = fp[1];
		}
		dup2(fout,1);
		close(fout);
		ret = fork();
		printf(" %s ",args[i]);
		int out=0,app=0,in = 0;
		if(ret==0)
		{
			for(int j = 0; args[i][j] != NULL; j++)
			{
				if(!strcmp(args[i][j],"<"));
				{
					in = 1;	
					// printf("xx");
					redir(j,0,args[i]);
				}
				break;
			}
			for(int j = 0; args[i][j] != NULL; j++)
			{
				if(!strcmp(args[i][j],">"));
				{
					out = 1;	
					redir1(j,0,args[i]);
				}
				break;
			}
			for(int j = 0; args[i][j] != NULL; j++)
			{
				if(!strcmp(args[i][j],">>"));
				{
					app = 1;	
					redir4(j,0,args[i]);
				}
				break;
			}
			if(in==0&&out==0&&app==0)
				execvp(args[i][0],args[i]);
			exit(0);
		}
		else
		{
			int st;
			waitpid(ret,&st,0);
			dup2(t1,0);
			dup2(t2,1);
		}
	}
	// if(args)
}