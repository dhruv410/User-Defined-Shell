void unset_env(char s[])
{
	if(unsetenv(s)<0)
	{
		perror("error: ");
	}
}