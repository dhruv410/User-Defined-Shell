void handler1(char *s1, char *h, char *s, char *str, int sig, int jo[])
{
	FILE *fp;
	int l = strlen(s1);
	int l1 = strlen(str);
	char stri[100000];
	char ss[40];
	int status;
	pid_t pid;
	char *lol = (char *)malloc(len*sizeof(char));
	pid = waitpid(0, &status, WNOHANG);
	// job[i-1] = -1;
	if(WIFEXITED(status))
	{
		int rp = WEXITSTATUS(status);
		if(rp==0)
			sprintf(lol,"normally\n");
		else 
			sprintf(lol,"abnormally\n");
	}
	for(int i = 0; i<100;i++)
	{
		if(jo[i]==pid)
		{
			jo[i]=-1;
			// break;
		}
	}
	if(pid==0||pid==-1)
	 	return ;
	int f =0;
	if(l>l1)
		f = 1;
	else
	{
		for(int i=0;i<l;i++)
		{
			if(s1[i]!=str[i])
			{
				f = 1;
				break;
			}
		}
	}
	char *s2= (char *)malloc(len*sizeof(char));
	for(int i=l;i<=l1;i++)
	{
		s2[i-l] = str[i];
	}
	s2[l1-l]='\0';
    if(f==0)
    {
    	printf("\nprocess with pid %d exited\n%s", pid, lol);
    	printf("%s@%s:~%s$ ",s,h,s2);
    	fflush(stdout);
    }
	else 
	{
		printf("\nprocess with pid %d exited\n%s%s@%s:%s$ ", pid,lol,s,h,str);
		fflush(stdout);
	}
}



