void fore(int job[] , char str[])
{
	int status;
	int x = atoi(str);
	if(job[x-1]!=-1)
	{
		kill(job[x-1],SIGCONT);
		int p = job[x-1];
		job[x-1]=-1;
		waitpid(p,&status,WUNTRACED);		
	}
}