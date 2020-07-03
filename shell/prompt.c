void prompt(char *s1, char *h, char *s,char *str )
{
	int l1 = strlen(str);
	int l = strlen(s1);
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
		if(f==0)
		{
			if(str[l]!='/'&&str[l]!='\0')
				f = 1;
		}
	}
	if(f==0)
	{
		char *s2= (char *)malloc(len*sizeof(char));
		for(int i=l;i<l1;i++)
		{
			s2[i-l] = str[i];
		}
		s2[l1-l]='\0';
		printf("%s@%s:~%s$ ",s,h,s2);
	}
	else 
		printf("%s@%s:%s$ ",s,h,str);
}