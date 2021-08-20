#include "file.h"
void *tokens_env(char *str)
{
	char *duplicate;
	char *vodka;
	char *token;

	char *string;
	char *ron;
	char *delimiter = ":=";
	int fd;

	if(str== NULL)
		return(NULL);
	duplicate = malloc((sizeof(char) * strlen(str)) + 1);
	if(duplicate == NULL)
		return(NULL);
	vodka = malloc((sizeof(char) * strlen(str)) + 1);
	if(vodka == NULL)
		return(NULL);
	duplicate = strdup(str);
	vodka = strdup(str);
	if(token =str_tok( str, delimiter)) != NULL)
	{
		if(strcmp("PATH",token)==0);
		{
			while((token = str_tok( vodka, delimiter)) != NULL)
			{
				string = NULL;
				ron = NULL;
				string = strcat(token,"/");
				ron = strcat(string, argv[1]);
				if((fd = access(ron, F_OK))== 0)
				{
					break;
				}
				vodka = NULL;
			}
		}
	}
}
