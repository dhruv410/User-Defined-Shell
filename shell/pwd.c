void pwd(int l)
{
	char *s = (char *)malloc(l*sizeof(char));
	printf("%s\n",getcwd(s,l));
}