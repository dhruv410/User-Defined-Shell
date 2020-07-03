void check(int job[], char names[][100])
{
	int status;
	pid_t wpid;
	while((wpid = waitpid(-1, &status, WNOHANG)) > 0) // Checks for the child processes which have changed there status. 
	{
		{
			for(int j = 0; j < 100; j++)
			{
				if(job[j] == wpid)
				{
					printf("%s[%d]+	Done\t PID %d ",names[j],job[j], wpid);
					int rp = WEXITSTATUS(status);
					if(rp==0)
						printf("\t exited normally\n");
					else 
						printf("\t exited abnormally\n");
					job[j]=-1;
				}
			}
		}
	}
	fflush(stdout);
}