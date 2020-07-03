void set_env(char s[], char s1[])
{ 
	if(s1==NULL)
		s1 = "";
	if(setenv(s,s1,1)<0)
	{
		perror("error: ");
	}
}