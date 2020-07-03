void redir(int p7, int i, char *s1[])
{
	int pid = fork();
	int status;
	if(pid<0)
	{
		printf("error");
		return ;
	}
	else if(!pid)
	{
		int fd;
		if(p7==0)
		{
			printf("Invalid Input\n");
			exit(0);
		}
		fd = open(s1[p7+1],O_RDONLY);
		if(fd<0)
		{
			printf("error\n");
			exit(0);
		}
		dup2(fd,0);
		int ex;
		s1[p7] = NULL;
			ex = execvp(s1[p7-1],s1);
		if(ex<0)
		{
			printf("yerror");
			exit(0);
		}
		close(fd);
		exit(0);
	}
	else
	{
		waitpid(pid,&status,0);
		return ;
	}
}
void redir1(int p7, int i, char *s1[])
{
	int pid = fork();
	int status;
	if(pid<0)
	{
		printf("error");
		return ;
	}
	else if(!pid)
	{
		int fd;
		if(s1[p7+1]==NULL)
		{
			printf("Inavlid input\n");
			exit(0);
		}	
		else
		fd = open(s1[p7+1], O_WRONLY | O_TRUNC | O_CREAT ,0644);
		if(fd<0)
		{
			printf("error\n");
			exit(0);
		}
		dup2(fd,1);
		s1[p7]=NULL;
		int ex;
		ex = execvp(s1[0],s1);
		if(ex<0)
		{
			printf("error");
			exit(0);
		}
		close(fd);
		exit(0);
	}
	else
	{
		waitpid(pid,&status,0);
		return ;
	}
}
void redir2(int p6, int p7, int i, char *s1[])
{
		int pid = fork();
	int status;
	if(pid<0)
	{
		printf("error");
		return ;
	}
	else if(!pid)
	{
		int fd,fd2;
		if(s1[p7+1]==NULL||p6==0||s1[p6+1]==NULL)
		{
			printf("Inavlid input\n");
			exit(0);
		}	
		else
		fd = open(s1[p6+1], O_RDONLY);
		if(fd<0)
		{
			printf("error\n");
			exit(0);
		}
		dup2(fd,0);
		s1[p6]=NULL;
		int ex;
		fd2 = open(s1[p7+1], O_WRONLY | O_TRUNC | O_CREAT ,0644);
		dup2(fd2,1);
		ex = execvp(s1[p6-1],s1);
		if(ex<0)
		{
			printf("error");
			exit(0);
		}
		close(fd);
		close(fd2);
		exit(0);
	}
	else
	{
		waitpid(pid,&status,0);
		return ;
	}
}
void redir3(int p6, int p7, int i, char *s1[])
{
		int pid = fork();
	int status;
	if(pid<0)
	{
		printf("error");
		return ;
	}
	else if(!pid)
	{
		int fd,fd2;
		if(s1[p7+1]==NULL||p6==0||s1[p6+1]==NULL)
		{
			printf("Inavlid input\n");
			exit(0);
		}	
		else
		fd = open(s1[p6+1], O_RDONLY);
		if(fd<0)
		{
			printf("error\n");
			exit(0);
		}
		dup2(fd,0);
		s1[p6]=NULL;
		int ex;
		fd2 = open(s1[p7+1], O_WRONLY | O_APPEND | O_CREAT ,0644);
		dup2(fd2,1);
		ex = execvp(s1[p6-1],s1);
		if(ex<0)
		{
			printf("error");
			exit(0);
		}
		close(fd);
		close(fd2);
		exit(0);
	}
	else
	{
		waitpid(pid,&status,0);
		return ;
	}
}
void redir4(int p7, int i, char *s1[])
{
	int pid = fork();
	int status;
	if(pid<0)
	{
		printf("error");
		return ;
	}
	else if(!pid)
	{
		int fd;
		// if(!strcmp(s1[p7],">"))
		if(s1[p7+1]==NULL)
		{
			printf("Inavlid input\n");
			exit(0);
		}	
		else
		fd = open(s1[p7+1], O_WRONLY | O_APPEND | O_CREAT ,0644);
		if(fd<0)
		{
			printf("error\n");
			exit(0);
		}
		dup2(fd,1);
		s1[p7]=NULL;
		int ex;
		ex = execvp(s1[0],s1);
		if(ex<0)
		{
			printf("error");
			exit(0);
		}
		close(fd);
		exit(0);
	}
	else
	{
		waitpid(pid,&status,0);
		return ;
	}
}
