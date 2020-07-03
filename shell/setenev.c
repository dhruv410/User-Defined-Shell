void set_env(char s[], char s1[])
{ 
	if(setenv(args[1],args[2],1)<0)
	{
		perror("error: ");
	}
}