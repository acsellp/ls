/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourUser <YourMail>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 11:08:43 by YourUser          #+#    #+#             */
/*   Updated: 2016/10/17 16:30:23 by YourUser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <xlocale.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "libft.h"

#define D_TEST	60
#define RANDT	512
#define LONG	10000


int					uf_free_tab(void **tab)
{
	unsigned int	i;

	if (tab == NULL)
		return (0);
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i = i + 1;
	}
	free(tab);
	return (1);
}

//===========================================================


//.........................TEST FUNCS................


//===========================================================

int		uf_test_itoa(void)
{
	char		*ret;
	if (strcmp(ret = ft_itoa(0), "0") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[33mft_itoa(0).\nExpected ret = \"0\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(-123), "-123") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[32mft_itoa(-123).\nExpected ret = \"-123\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(123), "123") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[33mft_itoa(123).\nExpected ret = \"123\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(-2147483648), "-2147483648") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[33mft_itoa(-2147483648).\nExpected ret = \"-2147483648\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	if (strcmp(ret = ft_itoa(2147483647), "2147483647") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[33mft_itoa(2147483647).\nExpected ret = \"2147483647\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(ret);
		return (0);
	}
	free(ret);
	printf("\033[32m ft_itoa  [OK]\033[0m\n");
	return (1);
}

int					uf_test_strtrim(void)
{
	char			str[] = "  \t    \t\nBon\t \njour\t\n  \n     ";
	char			str2[] = "Bonjour";
	char			str3[] = "  \t\t\t   ";
	char			*r;

	ft_strtrim(NULL);
	r = ft_strtrim(str);
	if (strcmp(r, "Bon\t \njour"))
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"  \t    \t\nBon\t \njour\t\n  \n     \").\nExpected ret = \"Bon\t \njour\" \
			   but have ret = \"%s\"\033[0m\n", __LINE__ - 2, __func__, r);
		free(r);
		return (0);
	}
	free(r);
	r = ft_strtrim(str2);
    if (strcmp(r, "Bonjour") || (str2 == r))
    {
        printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"Bonjour\").\nExpected ret = \"Bonjour\" and differents pointers\
			   but have ret = \"%s\" and our: %p / your: %p\033[0m\n", __LINE__ - 2, __func__, r, str2, r);
		free(r);
        return (0);
    }
    free(r);
	r = ft_strtrim(str3);
    if (strcmp(r, "") || (str3 == r))
    {
        printf("Error Line %d, Funct %s : \n\033[31mft_strstrim(\"  \t\t\t  \").\nExpected ret = \"\" and different\
s pointers but have ret = \"%s\" and our: %p / your: %p\033[0m\n", __LINE__ - 2, __func__, r, str3, r);
		free(r);
        return (0);
    }
//    free(r);
	printf("\033[32m ft_strtrim  [OK]\033[0m\n");
	return (1);
}

int					uf_test_strsplit(void)
{
	char			**ret;

	ft_strsplit(NULL, 0);
	ft_strsplit(NULL, 'a');
	ret = ft_strsplit("", '*');
	if (ret == NULL || ret[0] != NULL)
	{
		printf("Error Line %d, Funct %s : \
			   \nYour function has return NULL or the first pointer in your tab is NULL\n", __LINE__ - 2, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	uf_free_tab((void **)ret);
	ret = ft_strsplit("*********", '*');
	if (ret == NULL || ret[0] != NULL)
	{
		printf("Error Line %d, Funct %s : \
			   \nYour function has return NULL or the first pointer in your tab is NULL\n", __LINE__ - 2, __func__);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \nUnable to free your tab in first test\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("hello", '*');
	if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"hello\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
			   but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in second test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("*hello", '*');
	if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hello\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
			   but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in third test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("*hello*", '*');
	if (ret[1] != NULL && strcmp(ret[0], "hello") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hello*\", '*').\nExpected tab[0] = \"hello\" and tab[1] = NULL \
			   but have tab[0] = \"%s\" and tab[1] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in third test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("*hel*lo*", '*');
	if (ret[2] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel*lo*\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\" and tab[2] = NULL \
			   but have tab[0] = \"%s\", tab[1] = \"%s\" and tab[2] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in fourth test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("*hel*lo*f", '*');
	if (ret[3] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0 &&
		strcmp(ret[2], "f") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel*lo*f\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\", tab[2] = \"f\" and tab[3] = NULL \
			   but have tab[0] = \"%s\", tab[1] = \"%s\", tab[2] = \"%s\" and tab[3] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2], ret[3]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in fifth test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("g*hel*lo*f", '*');
	if (ret[4] != NULL && strcmp(ret[0], "g") != 0 && strcmp(ret[1], "hel") != 0 &&
		strcmp(ret[2], "lo") != 0 && strcmp(ret[3], "f") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"g*hel*lo*f\", '*').\nExpected tab[0] = \"g\", tab[1] = \"hel\", tab[2] = \"lo\", tab[3] = \"f\" and tab[4] = NULL \
			   but have tab[0] = \"%s\", tab[1] = \"%s\", tab[2] = \"%s\", tab[3] = \"%s\" and tab[4] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2], ret[3], ret[4]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in sixth test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	ret = ft_strsplit("***hel****lo**", '*');
	if (ret[2] != NULL && strcmp(ret[0], "hel") != 0 && strcmp(ret[1], "lo") != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strsplit(\"*hel****lo*\", '*').\nExpected tab[0] = \"hel\", tab[1] = \"lo\" and tab[2] = NULL \
			   but have tab[0] = \"%s\", tab[1] = \"%s\" and tab[2] = \"%s\"\033[0m\n", __LINE__ - 2, __func__, ret[0], ret[1], ret[2]);
		uf_free_tab((void **)ret);
		return (0);
	}
	if (uf_free_tab((void **)ret) == 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mUnable to free your tab in seventh test\033[0m\n", __LINE__ - 2, __func__);
		return (0);
	}
	printf("\033[32m ft_strsplit  [OK]\033[0m\n");
	return (1);
}

int				uf_test_isascii(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isascii(i) != ft_isascii(i))
		{
			printf("\033[31m ft_isascii  [ERR]\033[0m\n");
			return (0);		
		}		
		i = i + 1;
	}
	printf("\033[32m ft_isascii  [OK]\033[0m\n");
	return (1);
}

int				uf_test_isalnum(void)
{
	int			i;

	i = -300;
	while (i < 256)
	{
		if (isalnum(i) != ft_isalnum(i))
		{
			printf("%d - orig %d copy %d\n",i,isalnum(i),ft_isalnum(i));
			printf("\033[31m ft_isalnum  [ERR]\033[0m\n");
			return (0);		
		}
		i = i + 1;
	}
	printf("\033[32m ft_isalnum  [OK]\033[0m\n");
	return (1);
}

int				uf_test_isprint(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isprint(i) != ft_isprint(i))
		{
			printf("%d - orig %d copy %d\n",i,isprint(i),ft_isprint(i));

			printf("\033[31m ft_isprint  [ERR]\033[0m\n");
			return (0);		
		}
		i = i + 1;
	}
	printf("\033[32m ft_isprint  [OK]\033[0m\n");
	return (1);
}

int				uf_test_tolower(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (tolower(i) != ft_tolower(i))
		{
			printf("%d - orig %d copy %d\n",i,tolower(i),ft_tolower(i));

			printf("\033[31m ft_tolower  [ERR]\033[0m\n");
			return (0);		
		}
		i = i + 1;
	}
	printf("\033[32m ft_tolower [OK]\033[0m\n");
	return (1);
}

int				uf_test_toupper(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (toupper(i) != ft_toupper(i))
		{
			printf("%d - orig %d copy %d\n",i,toupper(i),ft_toupper(i));

			printf("\033[31m ft_toupper  [ERR]\033[0m\n");
			return (0);		
		}
		i = i + 1;
	}
	printf("\033[32m ft_toupper [OK]\033[0m\n");
	return (1);
}

int				uf_test_isdigit(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isdigit(i) != ft_isdigit(i))
		{
			printf("%d - orig %d copy %d\n",i,isdigit(i),ft_isdigit(i));

			printf("\033[31m ft_isdigit  [ERR]\033[0m\n");
			return (0);		
		}
		i = i + 1;
	}
	printf("\033[32m ft_isdigit [OK]\033[0m\n");
	return (1);
}

int				uf_test_isalpha(void)
{
	int			i;

	i = -300;
	while (i < 300)
	{
		if (isalpha(i) != ft_isalpha(i))
		{
			printf("%d - orig %d copy %d\n",i,isalpha(i),ft_isalpha(i));

			printf("\033[31m ft_isalpha  [ERR]\033[0m\n");
			return (0);		
		}
		i = i + 1;
	}
	printf("\033[32m ft_isalpha [OK]\033[0m\n");
	return (1);
}

int				uf_test_strncmp(void)
{
	int			a;

	a = ft_strncmp("abc", "abcde", 2);
#ifdef  __clang__
	if (strncmp("abc", "abcde", 2) != a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
#ifndef  __clang__
	if (a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
	a =  ft_strncmp("cba", "abc", 2);
#ifdef  __clang__
	if (strncmp("cba", "abc", 2) != a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
#ifndef  __clang__
	if (!a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
	a =  ft_strncmp("abc", "cba", 2);
#ifdef  __clang__
	if (strncmp("abc", "cba", 2) != a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
#ifndef  __clang__
	if (!a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
	a = ft_strncmp("", "", 3);
#ifdef  __clang__
	if (strncmp("", "", 3) != a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
#ifndef  __clang__
	if (a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
	a = ft_strncmp("q", "a", 0);
#ifdef  __clang__
	if (strncmp("q", "a", 0) != a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
#ifndef  __clang__
	if (a)
	{
		printf("\033[31m ft_strncmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
	printf("\033[32m ft_strncmp  [OK]\033[0m\n");
	return (1);
}

int				uf_test_strcmp(void)
{
	int			a;

	a = ft_strcmp("abc", "abc");
#ifdef  __clang__
	if (a != strcmp("abc", "abc"))
	{
		printf("\033[31m ft_strcmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
#ifndef  __clang__
	if (a)
	{
		printf("\033[31m ft_strcmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
	a = ft_strcmp("cba", "abc");
#ifdef  __clang__
	if (a != strcmp("cba", "abc"))
	{
		printf("\033[31m ft_strcmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
#ifndef  __clang__
	if (!a)
	{
		printf("\033[31m ft_strcmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
	a = ft_strcmp("abc", "cba");
#ifdef  __clang__
	if (a != strcmp("abc", "cba"))
	{
		printf("\033[31m ft_strcmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
#ifndef  __clang__
	if (!a)
	{
		printf("\033[31m ft_strcmp  [ERR]\033[0m\n");
		return (0);		
	}
#endif
	if (ft_strcmp("", "") != strcmp("", ""))
	{
		printf("\033[31m ft_strcmp  [ERR]\033[0m\n");
		return (0);		
	}
	printf("\033[32m ft_strcmp   [OK]\033[0m\n");
	return (1);
}

int				uf_test_atoi(void)
{
	size_t		i, j;
	char		str[12] = {0};

	if (atoi("\n\v\t\r\f -123") != ft_atoi("\n\v\t\r\f -123"))
	{
		printf("orig %d copy %d\n",atoi("\n\v\t\r\f -123") ,ft_atoi("\n\v\t\r\f -123"));
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("12-3") != ft_atoi("12-3"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("-+123") != ft_atoi("-+123"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("a123") != ft_atoi("a123"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("123a") != ft_atoi("123a"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("123") != ft_atoi("123"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("-123") != ft_atoi("-123"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("+123") != ft_atoi("+123"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi(" - 123") != ft_atoi(" - 123"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("\t -123") != ft_atoi("\t -123"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("-2147483648") != ft_atoi("-2147483648"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("2147483647") != ft_atoi("2147483647"))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	if (atoi("") != ft_atoi(""))
	{
		printf("\033[31m ft_atoi  [ERR]\033[0m\n");
		return (0);		
	}
	i = 0;
	while (i < RANDT)
	{
		j = 0;
		while (j < 11)
		{
			str[j] = ((char)rand() % 10) + '0';
			j++;
		}
		str[11] = 0;
		if (atoi(str) != ft_atoi(str))
		{
			printf("\033[31m ft_atoi  [ERR]\033[0m\n");
			return (0);		
		}
		i++;
	}
	printf("\033[32m ft_atoi  [OK]\033[0m\n");
	return (1);
}

int				uf_test_strstr(void)
{
	char		*str = "Hello les genw";

	if (strstr(str, "Hello") != ft_strstr(str, "Hello"))
	{
		printf("\033[31m ft_strstr  [ERR]\033[0m\n");
		return (0);		
	}
	if (strstr(str, "les") != ft_strstr(str, "les"))
	{
		printf("\033[31m ft_strstr  [ERR]\033[0m\n");
		return (0);		
	}
	if (strstr(str, "gen") != ft_strstr(str, "gen"))
	{
		printf("\033[31m ft_strstr  [ERR]\033[0m\n");
		return (0);		
	}
	if (strstr(str, "w") != ft_strstr(str, "w"))
	{
		printf("\033[31m ft_strstr  [ERR]\033[0m\n");
		return (0);		
	}
	if (strstr(str, "") != ft_strstr(str, ""))
	{
		printf("\033[31m ft_strstr  [ERR]\033[0m\n");
		return (0);		
	}
	if (strstr("", "") != ft_strstr("", ""))
	{
		printf("\033[31m ft_strstr  [ERR]\033[0m\n");
		return (0);		
	}
	printf("\033[32m ft_strstr  [OK]\033[0m\n");
	return (1);
}

int				uf_test_strrchr(void)
{
	char		str[] = "Hello je tesx";

	if (strrchr(str, 'H') != ft_strrchr(str, 'H'))
	{
		printf("notre=%s\nvotre=%s\n", strrchr(str, 'H'), ft_strrchr(str, 'H'));
			printf("\033[31m 1 ft_strrchr  [ERR]\033[0m\n");
			return (0);		
	}
	if (strrchr(str, 'j') != ft_strrchr(str, 'j'))
	{
		printf("\nnotre=%s\nvotre=%s\n", strrchr(str, 'j'), ft_strrchr(str, 'j'));
			printf("\033[31m 2 ft_strrchr  [ERR]\033[0m\n");
			return (0);		
	}
	if (strrchr(str, 'x') != ft_strrchr(str, 'x'))
	{
		printf("\nnotre=%s\nvotre=%s\n", strrchr(str, 'x'), ft_strrchr(str, 'x'));
			printf("\033[31m 3 ft_strrchr  [ERR]\033[0m\n");
			return (0);		
	}
	if (strrchr(str, 0) != ft_strrchr(str, 0))
	{
		printf("\nnotre=%s\nvotre=%s\n", strrchr(str, 0), ft_strrchr(str, 0));
			printf("\033[31m 4 ft_strrchr  [ERR]\033[0m\n");
			return (0);		
	}
	printf("\033[32m ft_strrchr  [OK]\033[0m\n");
	return (1);
}

int				uf_test_strchr(void)
{
	char		str[] = "Hello je tesx";

	if (strchr(str, 'H') != ft_strchr(str, 'H'))
	{
		printf("\033[31m 1 ft_strchr  [ERR]\033[0m\n");
		return (0);		
	}
	if (strchr(str, 'j') != ft_strchr(str, 'j'))
	{
		printf("\033[31m 2 ft_strchr  [ERR]\033[0m\n");
		return (0);		
	}
	if (strchr(str, 'x') != ft_strchr(str, 'x'))
	{
		printf("\033[31m 3 ft_strchr  [ERR]\033[0m\n");
		return (0);		
	}
	if (strchr(str, 'y') != ft_strchr(str, 'y'))
	{
		printf("\033[31m 4 ft_strchr  [ERR]\033[0m\n");
		return (0);		
	}
	if (strchr(str, 0) != ft_strchr(str, 0))
	{
		printf("orig %s copy %s\n",strchr(str,0),ft_strchr(str, 0));
		printf("\033[31m 5 ft_strchr  [ERR]\033[0m\n");
		return (0);		
	}
	printf("\033[32m ft_strchr  [OK]\033[0m\n");
	return (1);
}

int				uf_test_strncat(void)
{
	char		dest[50] = {0};
	char		dest2[50] = {0};

	if (strncat(dest, "hello ", 2) != ft_strncat(dest, "hello ", 2))
	{
		printf("\033[31m ft_strncat [ERR]\033[0m\n");
		return (0);		
	}
	memset(dest, 0, sizeof(dest));
	strncat(dest, "Hello ", 4);
	ft_strncat(dest2, "Hello ", 4);
	if (strcmp(dest, dest2) != 0)
	{
		printf("\033[31m ft_strncat [ERR]\033[0m\n");
		return (0);		
	}
	strncat(dest, "Hello ", 2);
	ft_strncat(dest2, "Hello ", 2);
	if (strcmp(dest, dest2) != 0)
	{
		printf("\033[31m ft_strncat [ERR]\033[0m\n");
		return (0);		
	}
	strncat(dest, "Hello ", 10);
    	ft_strncat(dest2, "Hello ", 10);
    	if (strcmp(dest, dest2) != 0)
		{
			printf("\033[31m ft_strncat [ERR]\033[0m\n");
			return (0);		
		}
	strncat(dest, "1234\n78", 7);
    	ft_strncat(dest2, "1234\n78", 7);
    	if (strcmp(dest, dest2) != 0)
		{
			printf("\033[31m ft_strncat [ERR]\033[0m\n");
			return (0);		
		}
	printf("\033[32m ft_strncat [OK]\033[0m\n");
	return (1);
}


int				uf_test_strcat(void)
{
	char		dest[50] = {0};
	char		dest2[50] = {0};

	if (strcat(dest, "hello ") != ft_strcat(dest, "hello "))
	{
		printf("\033[31m ft_strcat [ERR]\033[0m\n");
		return (0);		
	}
	memset(dest, 0, sizeof(dest));
	strcat(dest, "Hello ");
	ft_strcat(dest2, "Hello ");
	if (strcmp(dest, dest2) != 0)
	{
		printf("\033[31m ft_strcat [ERR]\033[0m\n");
		return (0);		
	}
	strcat(dest, "Hello ");
	ft_strcat(dest2, "Hello ");
	if (strcmp(dest, dest2) != 0)
	{
		printf("\033[31m ft_strcat [ERR]\033[0m\n");
		return (0);		
	}
	printf("\033[32m ft_strcat [OK]\033[0m\n");
	return (1);
}

int				uf_test_strncpy(void)
{
	char		ctab[11], ctab2[21], ctab3[21];
	int			i, j;
	size_t		k;

	k = 0;
	while (k < 21)
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 21)
			{
				if (j < 11)
					ctab[j] = ((char)rand() % 26) + 'a';
				ctab2[j] = 'Z';
				ctab3[j] = 'Z';
				j++;
			}
			ctab[10] = 0;
			ctab2[20] = 0;
			ctab3[20] = 0;
			if (strncpy(ctab2, ctab, k) != ctab2 || ft_strncpy(ctab3, ctab, k) != ctab3)
			{
				printf("\033[31m ft_strncpy [ERR]\033[0m\n");
				return (0);		
			}
			if (strcmp(ctab2, ctab3))
			{
				printf("\033[31m ft_strncpy [ERR]\033[0m\n");
				return (0);		
			}
			++i;
		}
		k++;
	}
	printf("\033[32m ft_strncpy [OK]\033[0m\n");
	return (1);
}

int				uf_test_strcpy(void)
{
	char		dest[50] = {0};
	char		dest2[50] = {0};


	char			ctab[11], ctab2[11], ctab3[11];
    int				i, j;
    size_t			k;

    k = 0;
    while (k <= sizeof(ctab))
    {
        i = 0;
        while (i < RANDT)
        {
            j = 0;
            while (j < 11)
            {
                ctab[j] = (char)rand();
                ctab2[j] = 0; ctab3[j] = 0;
                j++;
            }
			ctab[10] = 0;
			if (strcpy(ctab2, ctab) != ctab2 || ft_strcpy(ctab3, ctab) != ctab3)
			{
				printf("\033[31m ft_strcpy [ERR]\033[0m\n");
				return (0);		
			}
			if (strcmp(ctab2, ctab3))
			{
				printf("\033[31m ft_strcpy [ERR]\033[0m\n");
				return (0);		
			}
			++i;
		}
		k++;
	}
	if (strcpy(dest, "Hello foo") != ft_strcpy(dest, "Hello foo"))
	{
		printf("\033[31m ft_strcpy [ERR]\033[0m\n");
		return (0);		
	}
	strcpy(dest, "Hello foo");
	ft_strcpy(dest2, "Hello foo");
	if (strcmp(dest, dest2) != 0)
	{
		printf("\033[31m ft_strcpy [ERR]\033[0m\n");
		return (0);		
	}
	strcpy(dest, "Hello");
	ft_strcpy(dest2, "Hello");
	if (strcmp(dest, dest2) != 0)
	{
		printf("\033[31m ft_strcpy [ERR]\033[0m\n");
		return (0);		
	}
	printf("\033[32m ft_strcpy [OK]\033[0m\n");
	return (1);
}

int				uf_test_strdup(void)
{
	char		*ret1;
	char		*ret2;

	ret1 = strdup("");
	ret2 = ft_strdup("");
	if (strcmp(ret1, ret2) != 0)
	{
		printf("\033[31m ft_strdup [ERR]\033[0m\n");
		return (0);		
	}
	free(ret1);
	free(ret2);
	ret1 = strdup("hello");
	ret2 = ft_strdup("hello");
	if (strcmp(ret1, ret2) != 0)
	{
		printf("\033[31m ft_strdup [ERR]\033[0m\n");
		return (0);		
	}
	free(ret1);
	free(ret2);
	printf("\033[32m ft_strdup [OK]\033[0m\n");
	return (1);
}

int				uf_test_strlen(void)
{
	if (strlen("") != ft_strlen(""))
	{
		printf("\033[31m ft_strlen [ERR]\033[0m\n");
		return (0);		
	}
	if (strlen("abc") != ft_strlen("abc"))
	{
		printf("\033[31m ft_strlen [ERR]\033[0m\n");
		return (0);		
	}
	if (strlen("a") != ft_strlen("a"))
	{
		printf("\033[31m ft_strlen [ERR]\033[0m\n");
		return (0);		
	}
	printf("\033[32m ft_strlen [OK]\033[0m\n");
	return (1);
}

int				uf_test_memmove(void)
{
	char		str[] = "memmove can be very useful......";
	char		str2[] = "memmove can be very useful......";
	char		str3[] = "memmove can be very useful......";
	char		str4[] = "memmove can be very useful......";

	char		s1[101], t1[101];
	char		s2[101], t2[101];
	size_t		i, j;

	i = 0;
	while (i < RANDT)
	{
		j = 0;
		while (j < 100)
		{
			s1[j] = (char)rand();
			s2[j] = (char)rand();
			j++;
		}
		s1[100] = 0;    s2[100] = 0;
		memcpy(t1, s1, sizeof(s1));
		memcpy(t2, s2, sizeof(s2));
		if (strcmp(memmove(str + 10, str + 5, 10), ft_memmove(str2 + 10, str2 + 5, 10)) != 0)
		{
			printf("\033[31m ft_memmove [ERR]\033[0m\n");
			return (0);		
		}
		if (strcmp(memmove(str3 + 5, str3 + 10, 10), ft_memmove(str4 + 5, str4 + 10, 10)) != 0)
		{
			printf("\033[31m ft_memmove [ERR]\033[0m\n");
			return (0);		
		}
		if (strcmp(memmove(s1, s2, 2), ft_memmove(t1, t2, 2)) != 0)
		{
			printf("\033[31m ft_memmove [ERR]\033[0m\n");
			return (0);		
		}
		if (strcmp(memmove(s1, s1 + 25, 30), ft_memmove(t1, t1 + 25, 30)) != 0)
		{
			printf("\033[31m ft_memmove [ERR]\033[0m\n");
			return (0);		
		}
		if (strcmp(memmove(s1 + 30, s1, 40), ft_memmove(t1 + 30, t1, 40)) != 0)
		{
			printf("\033[31m ft_memmove [ERR]\033[0m\n");
			return (0);		
		}
		++i;
	}
	printf("\033[32m ft_memmove [OK]\033[0m\n");
	return (1);
}

int				uf_test_memchr(void)
{
	char			ctab[11];
	int				itab[11];
	unsigned long	ltab[11];
	size_t			j;
	int				i;

	i = -300;
	memchr(NULL, 0, 0);
	ft_memchr(NULL, 0, 0);
	while (i < 300)
	{
		j = 0;
		while (j < 11)
		{
			ctab[j] = (char)rand();
			itab[j] = rand();
			ltab[j] = (unsigned long)rand() * LONG;
			j++;
		}
		if (memchr(ctab, i, sizeof(ctab)) != ft_memchr(ctab, i, sizeof(ctab)))
		{
			printf("\033[31m 1 ft_memchr [ERR]\033[0m\n");
			return (0);		
		}
		if (memchr(itab, i, sizeof(itab)) != ft_memchr(itab, i, sizeof(itab)))
		{
			printf("\033[31m 2 ft_memchr [ERR]\033[0m\n");
			return (0);		
		}
		if (memchr(ltab, i, sizeof(ltab)) != ft_memchr(ltab, i, sizeof(ltab)))
		{
			printf("\033[31m 3 ft_memchr [ERR]\033[0m\n");
			return (0);		
		}
		++i;
	}
	printf("\033[32m ft_memchr [OK]\033[0m\n");
	return (1);
}

int				uf_test_memcmp(void)
{
    char            ctab[11], ctab2[11];
    int             itab[11], itab2[11];
    unsigned long   ltab[11], ltab2[11];
    size_t          i, j;

#ifdef	__clang__
	if (memcmp(NULL, NULL, 0) != ft_memcmp(NULL, NULL, 0))
	{
		printf("\033[31m 1 ft_memcmp [ERR]\033[0m\n");
		return (0);		
	}
#endif
    i = 0;
    while (i < 11)
    {
        j = 0;
        while (j < 11)
        {
            ctab[j] = (char)rand();
            ctab2[j] = (char)rand();
			itab[j] = rand();
			itab2[j] = rand();
            ltab[j] = (unsigned long)rand() * LONG;
			ltab2[j] = (unsigned long)rand() * LONG;
            j++;
        }
		if (memcmp(ctab, ctab2, sizeof(ctab)) != ft_memcmp(ctab, ctab2, sizeof(ctab)))
		{
			printf("\033[31m 2 ft_memcmp [ERR]\033[0m\n");
			return (0);		
		}
        memcpy(ctab2, ctab, sizeof(ctab));
		if (memcmp(ctab, ctab2, sizeof(ctab)) != ft_memcmp(ctab, ctab2, sizeof(ctab)))
		{
			printf("\033[31m 3 ft_memcmp [ERR]\033[0m\n");
			return (0);		
		}
		if (memcmp(itab, itab2, sizeof(itab)) != ft_memcmp(itab, itab2, sizeof(itab)))
		{
			printf("\033[31m 4 ft_memcmp [ERR]\033[0m\n");
			return (0);		
		}
		memcpy(itab2, itab, sizeof(itab));
        if (memcmp(itab, itab2, sizeof(itab)) != ft_memcmp(itab, itab2, sizeof(itab)))
		{
			printf("\033[31m 5 ft_memcmp [ERR]\033[0m\n");
			return (0);		
		}
		memcpy(ltab2, ltab, sizeof(ltab));
        if (memcmp(ltab, ltab2, sizeof(ltab)) != ft_memcmp(ltab, ltab2, sizeof(ltab)))
		{
			printf("orig %d opy %d\n",memcmp(ltab,ltab2,sizeof(ltab)),ft_memcmp(ltab,ltab2,sizeof(ltab)));
			printf("\033[31m 7 ft_memcmp [ERR]\033[0m\n");
			return (0);		
		}
				++i;
    }
	printf("\033[32m ft_memcmp [OK]\033[0m\n");
	return (1);
}


int				uf_test_memccpy(void)
{
	char			ctab[11], ctab2[11], ctab3[11];
	int				itab[11], itab2[11], itab3[11];
	unsigned long	ltab[11], ltab2[11], ltab3[11];
	int				i, j;
	size_t			k;
	void			*temp, *temp2;

#ifdef	__clang__
	memccpy(NULL, NULL, 0, 0);
	ft_memccpy(NULL, NULL, 0, 0);
#endif
	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				itab[j] = rand();
				itab2[j] = 0; itab3[j] = 0;
				ltab[j] = (unsigned long)rand() * LONG;
				ltab2[j] = 0; ltab3[j] = 0;
				j++;
			}
			temp = memccpy(ctab2, ctab, 'a', (k < sizeof(ctab)) ? k : sizeof(ctab));
			memcpy(ctab3, ctab2, sizeof(ctab));
			temp2 = ft_memccpy(ctab2, ctab, 'a', (k < sizeof(ctab)) ? k : sizeof(ctab));
			if ((memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || (temp != temp2)))
			{
				printf("\033[31m ft_memccpy [ERR]\033[0m\n");
				return (0);		
			}
			temp = memccpy(itab2, itab, 'a', (k < sizeof(itab)) ? k : sizeof(itab));
			memcpy(itab3, itab2, sizeof(itab));
			temp2 = ft_memccpy(itab2, itab, 'a', (k < sizeof(itab)) ? k : sizeof(itab));
			if ((memcmp(itab2, itab3, sizeof(itab)) != 0 || (temp != temp2)))
			{
				printf("\033[31m ft_memccpy [ERR]\033[0m\n");
				return (0);		
			}
			temp = memccpy(ltab2, ltab, 'a', (k < sizeof(ltab)) ? k : sizeof(ltab));
			memcpy(ltab3, ltab2, sizeof(ltab));
			temp2 = ft_memccpy(ltab2, ltab, 'a', (k < sizeof(ltab)) ? k : sizeof(ltab));
			if ((memcmp(ltab2, ltab3, sizeof(ltab)) != 0 || (temp != temp2)))
			{
				printf("\033[31m ft_memccpy [ERR]\033[0m\n");
				return (0);		
			}
			++i;
		}
		++k;
	}
	printf("\033[32m ft_memccpy [OK]\033[0m\n");
	return (1);
}


int					uf_test_memcpy(void)
{
	char			ctab[11], ctab2[11], ctab3[11];
	int				itab[11], itab2[11], itab3[11];
	unsigned long	ltab[11], ltab2[11], ltab3[11];
	int				i, j;
	size_t			k;
	void			*temp, *temp2, *temp3;

#ifdef	__clang__
	memcpy(NULL, NULL, 0);
	ft_memcpy(NULL, NULL, 0);
#endif
	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				itab[j] = rand();
				itab2[j] = 0; itab3[j] = 0;
				ltab[j] = (unsigned long)rand() * LONG;
				ltab2[j] = 0; ltab3[j] = 0;
				j++;
			}
			memcpy(ctab2, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp = ft_memcpy(ctab3, ctab, (k < sizeof(ctab)) ? k : sizeof(ctab));
			memcpy(itab2, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = ft_memcpy(itab3, itab, (k < sizeof(itab)) ? k : sizeof(itab));
			memcpy(ltab2, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp3 = ft_memcpy(ltab3, ltab, (k < sizeof(ltab)) ? k : sizeof(ltab));
			if ((memcmp(itab2, itab3, sizeof(itab)) != 0 || (temp2 != itab3)))
			{
				printf("\033[31m ft_memcpy [ERR]\033[0m\n");
				return (0);		
			}
			if (memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || temp != ctab3)
			{
				printf("\033[31m ft_memcpy [ERR]\033[0m\n");
				return (0);		
			}
			if (memcmp(ltab2, ltab3, sizeof(ltab)) != 0 ||( temp3 != ltab3))
			{
				printf("\033[31m ft_memcpy [ERR]\033[0m\n");
				return (0);		
			}
			++i;
		}
		++k;
	}
	printf("\033[32m ft_memcpy [OK]\033[0m\n");
	return (1);
}


int					uf_test_memset(void)
{
	char			ctab[11], ctab2[11];
	int				itab[11], itab2[11];
	unsigned long	ltab[11], ltab2[11];
	size_t			i, j, k;
	void			*temp, *temp2;

#ifdef	__clang__
	memset(NULL, 0, 0);
	ft_memset(NULL, 0, 0);
#endif
	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				itab[j] = rand();
				ltab[j] = (unsigned long)rand() * LONG;
				j++;
			}
			memcpy(ctab2, ctab, sizeof(ctab));
			memcpy(itab2, itab, sizeof(itab));
			memcpy(ltab2, ltab, sizeof(ltab));
			temp = ft_memset(itab, i, (k < sizeof(itab)) ? k : sizeof(itab));
			temp2 = memset(itab2, i, (k < sizeof(itab)) ? k : sizeof(itab));
			if (memcmp(itab, itab2, sizeof(itab)) != 0 || temp != itab || temp2 != itab2)
			{
				printf("\033[31m ft_memset [ERR]\033[0m\n");
				return (0);		
			}
			temp = ft_memset(ctab, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			temp2 = memset(ctab2, i, (k < sizeof(ctab)) ? k : sizeof(ctab));
			if (memcmp(ctab, ctab2, sizeof(ctab)) != 0 || temp != ctab || temp2 != ctab2)
			{
				printf("\033[31m ft_memset [ERR]\033[0m\n");
				return (0);		
			}
			temp = ft_memset(ltab, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			temp2 = memset(ltab2, i, (k < sizeof(ltab)) ? k : sizeof(ltab));
			if (memcmp(ltab, ltab2, sizeof(ltab)) != 0 || temp != ltab || temp2 != ltab2)
			{
				printf("\033[31m ft_memset [ERR]\033[0m\n");
				return (0);		
			}
			++i;
		}
		++k;
	}
	printf("\033[32m ft_memset [OK]\033[0m\n");
	return (1);
}

int					uf_test_bzero(void)
{
	char			ctab[11], ctab2[11];
	int				itab[11], itab2[11];
	unsigned long	ltab[11], ltab2[11];
	size_t			i, j;

	i = 0;
#ifdef	__clang__
	bzero(NULL, 0);
	ft_bzero(NULL, 0);
#endif
	while (i < 11)
	{
		j = 0;
		while (j < 11)
		{
			ctab[j] = (char)rand();
			itab[j] = rand();
			ltab[j] = (unsigned long)rand() * LONG;
			j++;
		}
		memcpy(ctab2, ctab, sizeof(ctab));
		memcpy(itab2, itab, sizeof(itab));
		memcpy(ltab2, ltab, sizeof(ltab));
		bzero(ctab2, i);
		ft_bzero(ctab, i);
		if (memcmp(ctab, ctab2, sizeof(ctab)) != 0)
		{
			printf("\033[31m ft_bzero [ERR]\033[0m\n");
			return (0);		
		}
		bzero(itab2, i);
		ft_bzero(itab, i);
		if (memcmp(itab, itab2, sizeof(itab)) != 0)
		{
			printf("\033[31m ft_bzero [ERR]\033[0m\n");
			return (0);		
		}
		bzero(ltab2, i);
		ft_bzero(ltab, i);
		if (memcmp(ltab, ltab2, sizeof(ltab)) != 0)
		{
			printf("\033[31m ft_bzero [ERR]\033[0m\n");
			return (0);		
		}
		++i;
	}
	printf("\033[32m ft_bzero [OK]\033[0m\n");
	return (1);
}


int				uf_test_strjoin(void)
{
	char		*ret;

	ft_strjoin(NULL, NULL);
	ft_strjoin(NULL, "");
	ft_strjoin("", NULL);
	ret = ft_strjoin("Hello ", "boys");
	if (strcmp(ret, "Hello boys") != 0)
	{
		printf("\033[31m ft_strjoin [ERR]\033[0m\n");
		free(ret);
		return (0);
	}
	free(ret);
	ret = ft_strjoin("", "boys");
    if (strcmp(ret, "boys") != 0)
    {
		printf("\033[31m ft_strjoin [ERR]\033[0m\n");
        free(ret);
        return (0);
    }
    free(ret);
	ret = ft_strjoin("Hello ", "");
    if (strcmp(ret, "Hello ") != 0)
    {
		printf("\033[31m ft_strjoin [ERR]\033[0m\n");
        free(ret);
        return (0);
    }
    free(ret);
	ret = ft_strjoin("", "");
    if (strcmp(ret, "") != 0)
    {
		printf("\033[31m ft_strjoin [ERR]\033[0m\n");
        free(ret);
        return (0);
    }
    free(ret);
	printf("\033[32m ft_strjoin [OK]\033[0m\n");
	return (1);
}

int				uf_test_strsub(void)
{
	char		*ret;
	char		str[] = "*hello*";

	ft_strsub(NULL, 0, 0);
	ft_strsub(NULL, 1, 0);
	ft_strsub(NULL, 1, 1);
	ft_strsub(NULL, 0, 1);
	ret = ft_strsub(str, 1, 5);
	if (strcmp(ret, "hello") != 0)
	{
		printf("\033[31m ft_strsub [ERR]\033[0m\n");
		return (0);
	}
	ret = ft_strsub(str, 3, 1);
    if (strcmp(ret, "l") != 0)
    {
		printf("\033[31m ft_strsub [ERR]\033[0m\n");
        return (0);
    }
	printf("\033[32m ft_strsub [OK]\033[0m\n");
	return (1);
}

int				uf_test_strnequ(void)
{
	int			ret;

	ft_strnequ(NULL, NULL, 0);
	ft_strnequ(NULL, NULL, 1);
	ft_strnequ(NULL, "", 1);
	ft_strnequ("", NULL, 1);
	ret = 0;
	if ((ret = ft_strnequ("abc", "abc", 2)) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"abc\", \"abc\", 2).\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strnequ("cba", "abc", 2)) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"cba\", \"abc\", 2).\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strnequ("abc", "cba", 2)) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"abc\", \"cba\", 2).\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strnequ("abc", "abd", 2)) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"abc\", \"abd\", 2).\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strnequ("", "", 3)) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strnequ(\"\", \"\", 3).\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	printf("\033[32m ft_strnequ [OK]\033[0m\n");
	return (1);
}

int				uf_test_strequ(void)
{
	int			ret;
	char		*str;

	ft_strequ(NULL, NULL);
	ft_strequ("", NULL);
	ft_strequ(NULL, "");
	ret = 0;
	str = strdup("abc"); 
	if ((ret = ft_strequ(str, "abc")) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abc\", \"abc\").\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		free(str);
		return (0);
	}
	free(str);
	if ((ret = ft_strequ("cba", "abc")) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"cba\", \"abc\").\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strequ("abc", "cba")) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abc\", \"cba\").\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strequ("", "")) != 1)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"\", \"\").\nExpected ret = \"1\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strequ("abc", "abcd")) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abc\", \"abcd\").\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	if ((ret = ft_strequ("abcd", "abc")) != 0)
	{
		printf("Error Line %d, Funct %s : \n\033[31mft_strequ(\"abcd\", \"abc\").\nExpected ret = \"0\" \
			   but have ret = \"%d\"\033[0m\n", __LINE__ - 2, __func__, ret);
		return (0);
	}
	printf("\033[32m ft_strequ [OK]\033[0m\n");
	return (1);
}

void			uf_striteri_callback(unsigned int i, char *s)
{
	*s = *s + i;
}

char			uf_strmap_callback(char s)
{
	return (s + 1);
}

char			uf_strmapi_callback(unsigned int i, char s)
{
	return (s + i);
}

int				uf_test_strmapi(void)
{
	char		str[] = "Hello";
	char		empty[] = "";
	char		*ret;

	ft_strmapi(NULL, NULL);
	ft_strmapi(empty, NULL);
	ret = ft_strmapi(str, uf_strmapi_callback);
	if (strcmp(ret, "Hfnos") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	printf("\033[32m ft_strmapi [OK]\033[0m\n");
	return (1);
}


int				uf_test_strmap(void)
{
	char		str[] = "Hello";
	char		*ret;

	ft_strmap(NULL, NULL);
	ft_strmap("", NULL);
	ret = ft_strmap(str, uf_strmap_callback);
	if (strcmp(ret, "Ifmmp") != 0)
	{
		printf("Error Line %d, Funct %s ", __LINE__ - 1, __func__);
		free(ret);
		return (0);
	}
	free(ret);
	printf("\033[32m ft_strmap [OK]\033[0m\n");
	return (1);
}

void			uf_striter_callback(char *s)
{
	*s = *s + 1;
}

int				uf_test_striteri(void)
{
	char		str[] = "Hello";

	ft_striteri(NULL, NULL);
	ft_striteri(str, NULL);
	ft_striteri(str, uf_striteri_callback);
	if (strcmp(str, "Hfnos") != 0)
	{
		printf("\033[31m ft_striteri [ERR]\033[0m\n");
		return (0);
	}
	printf("\033[32m ft_striteri [OK]\033[0m\n");
	return (1);
}

int				uf_test_striter(void)
{
	char		str[] = "Hello";

	ft_striter(NULL, NULL);
	ft_striter(str, NULL);
	ft_striter(str, uf_striter_callback);
	if (strcmp(str, "Ifmmp") != 0)
	{
		printf("\033[31m ft_striter [ERR]\033[0m\n");
		return (0);
	}
	printf("\033[32m ft_striter [OK]\033[0m\n");
	return (1);
}


int				uf_test_strclr(void)
{
	int			i;
	char		str[] = "Hello";

	i = 0;
	ft_strclr(NULL);
	ft_strclr(str);
	while (i < 6)
	{
		if (str[i] != '\0')
		{
			printf("\033[31m ft_strclr [ERR]\033[0m\n");
			return (0);
		}
		i = i + 1;
	}
	printf("\033[32m ft_strclr [OK]\033[0m\n");
	return (1);
}


int				uf_test_strdel(void)
{
	char		*ret;

	ft_strdel(NULL);
	ret = ft_strnew(4);
	ft_strdel(&ret);
	if (ret != NULL)
	{
		printf("\033[31m ft_strdel [ERR]\033[0m\n");
		return (0);
	}
	ret = ft_strnew(0);
	ft_strdel(&ret);
	if (ret != NULL)
	{
		printf("\033[31m ft_strdel [ERR]\033[0m\n");
		return (0);
	}
	printf("\033[32m ft_strdel [OK]\033[0m\n");
	return (1);
}

int				uf_test_strnew(void)
{
	char		*ret;
	int			i;

	i = 0;
	ret = ft_strnew(4);
	if (ret != NULL)
	{
		while (i < 5)
		{
			if (ret[i] != '\0')
			{
				printf("\033[31m ft_strnew [ERR]\033[0m\n");
				return (0);
			}
			i = i + 1;
		}
	}
	printf("\033[32m ft_strnew [OK]\033[0m\n");
	return (1);
}

int				uf_test_memalloc_and_del(void)
{
	void		*ret;

	ret = ft_memalloc(4);
	ft_memdel(&ret);
	if (ret != NULL)
	{
		printf("\033[31m ft_memalloc_and_del [ERR]\033[0m\n");
		return (0);
	}
	printf("\033[32m ft_memalloc_and_del [OK]\033[0m\n");
	return (1);
}

void	uf_iter_callback(t_list *v)
{
	*(size_t*)v->content = *(size_t*)v->content + 1;
}



int					uf_test_lstnew(void)
{
	t_list	*begin;
	size_t	v;

	v = 1;
	begin = ft_lstnew(NULL, 36);
	if (begin != 0 && (begin->content_size != 0 || begin->content != NULL))
	{
		printf("\033[31m ft_lstnew [ERR]\033[0m\n");
		return (0);
	}
	free(begin);
	begin = ft_lstnew(&v, sizeof(size_t));
	if (begin != NULL)
	{
		if (&v == begin->content)
		{
			printf("\033[31m ft_lstnew [ERR]\033[0m\n");
			return (0);
		}
		if (*(size_t*)begin->content != 1)
		{
			printf("\033[31m ft_lstnew [ERR]\033[0m\n");
			return (0);
		}
		if (begin->content_size != sizeof(size_t))
		{
			printf("\033[31m ft_lstnew [ERR]\033[0m\n");
			return (0);
		}
		if (begin->next != 0)
		{
			printf("\033[31m ft_lstnew [ERR]\033[0m\n");
			return (0);
		}
	}
	printf("\033[32m ft_lstnew [OK]\033[0m\n");
	free(begin);
	return (1);
}

void	uf_del_callback(void *d, size_t s)
{
	free(d);
	(void)s;
}

int					uf_test_lstdel(void)
{
	t_list	*begin;
	size_t	v;

	v = 1;
	begin = ft_lstnew(&v, sizeof(void *));
	begin->next = ft_lstnew(&v, sizeof(void *));
	begin->next->next = ft_lstnew(&v, sizeof(void *));
	ft_lstdel(&begin, uf_del_callback);
	if (begin != NULL)
	{
		printf("\033[31m ft_lstdel [ERR]\033[0m\n");
		return (0);
	}
	printf("\033[32m ft_lstdel [OK]\033[0m\n");
	return (1);
}



int					uf_test_lstadd(void)
{
	t_list	*begin;
	t_list	*add;
	t_list	*tmp;
	size_t	v;

	v = 1;
	begin = ft_lstnew(&v, sizeof(size_t));
	tmp = begin;
	add = ft_lstnew(&v, sizeof(size_t));
	ft_lstadd(&begin, add);
	if (begin != add)
	{
		printf("\033[31m ft_lstadd [ERR]\033[0m\n");
		return (0);
	}
	if (begin->next != tmp)
	{
		printf("\033[31m ft_lstadd [ERR]\033[0m\n");
		return (0);
	}
	free(begin->next);
	free(begin);
	printf("\033[32m ft_lstadd [OK]\033[0m\n");
	return (1);
}


int					uf_test_lstdelone(void)
{
	t_list	*begin;
	size_t	v;

	v = 1;
	begin = ft_lstnew(&v, sizeof(void *));
	begin->next = ft_lstnew(&v, sizeof(void *));
	begin->next->next = ft_lstnew(&v, sizeof(void *));
	ft_lstdelone(&begin->next->next, uf_del_callback);
	if (begin->next->next != NULL)
	{
		printf("\033[31m ft_lstdelone [ERR]\033[0m\n");
		return (0);
	}
	ft_lstdelone(&begin->next, uf_del_callback);
	if (begin->next != NULL)
	{
		printf("\033[31m ft_lstdelone [ERR]\033[0m\n");
		return (0);
	}
	ft_lstdelone(&begin, uf_del_callback);
	if (begin != NULL)
	{
		printf("\033[31m ft_lstdelone [ERR]\033[0m\n");
		return (0);
	}
	printf("\033[32m ft_lstadelone [OK]\033[0m\n");
	return (1);
}


int					uf_test_lstiter(void)
{
	t_list	*begin;
	size_t	v;
	size_t	w;

	v = 1;
	w = 2;
	begin = ft_lstnew(&v, sizeof(size_t));
	begin->next = ft_lstnew(&w, sizeof(size_t));
	ft_lstiter(begin, uf_iter_callback);
	if (*(size_t*)begin->content != 2)
	{
		printf("\033[31m ft_lstiter [ERR]\033[0m\n");
		return (0);
	}
	if (*(size_t*)begin->next->content != 3)
	{
		printf("\033[31m ft_lstiter [ERR]\033[0m\n");
		return (0);
	}
	free(begin->next);
	free(begin);
	printf("\033[32m ft_lstiter [OK]\033[0m\n");
	return (1);
}



t_list		*uf_testmap(t_list *elem)
{
	t_list	*new;
	char	*content;
	int		i;

	content = ft_strdup((char *)(elem->content));
	i = 0;
	while (i < ft_strlen(content))
	{
		content[i] += 1;
		++i;
	}
	new = ft_lstnew((void const *) content, 5);
	free(content);
	return (new);
}


void				printlst(t_list *l)
{
	while (l)
	{
		printf("%s -> ",(char*)l->content);
		l = l->next;
	}
	printf("\n\n");
}


int					uf_test_lstmap(void)
{
    t_list			*lst_initial;
    t_list			*lst;
    char			*content;
    t_list			*(*f)(t_list *);

	content = "toto";
	lst_initial = ft_lstnew((void const *) content, 5);
	content = "tata";
	lst_initial->next = ft_lstnew((void const *) content, 5);
	content = "tutu";
	lst_initial->next->next = ft_lstnew((void const *) content, 5);
	f = &uf_testmap;
	lst = ft_lstmap(lst_initial, f);
//	printlst(lst_initial);
//	printlst(lst);
	if (!strcmp((const char *) lst->content, (const char *) lst_initial->content) || strcmp((const char *) lst->content, "upup"))
	{
		printf("\033[31m 1 ft_lstmap [ERR]\033[0m\n");
		return (0);
	}
    if (!strcmp((const char *) lst->next->content, (const char *) lst_initial->next->content) || strcmp((const char *) lst->next->content, "ubub"))
	{
		printf("\033[31m 2 ft_lstmap [ERR]\033[0m\n");
		return (0);
	}
    if (!strcmp((const char *) lst->next->next->content, (const char *) lst_initial->next->next->content) || strcmp((const char *) lst->next->next->content, "uvuv"))
	{
		printf("\033[31m 3 ft_lstmap [ERR]\033[0m\n");
		return (0);
	}
	printf("\033[32m ft_lstmap [OK]\033[0m\n");
    return (1);
}

int	main()
{
	uf_test_itoa();
	uf_test_isascii();
	uf_test_isalnum();
	uf_test_tolower();
	uf_test_toupper();
	uf_test_isdigit();
	uf_test_isalpha();
	uf_test_strncmp();
	uf_test_strcmp();
	uf_test_atoi();
	uf_test_strstr();
	uf_test_strrchr();
	uf_test_strchr();
	uf_test_strncat();
	uf_test_strcat();
	uf_test_strncpy();
	uf_test_strcpy();
	uf_test_strdup();
	uf_test_strlen();
	uf_test_memchr();
	uf_test_memcmp();
	uf_test_memccpy();
	uf_test_memcpy();
	uf_test_memset();
	uf_test_bzero();
	uf_test_memalloc_and_del();
	uf_test_strnew();
	uf_test_strclr();
	uf_test_strdel();
	uf_test_strnequ();
	uf_test_strequ();
	uf_test_strmapi();
	uf_test_strmap();
	uf_test_striteri();
	uf_test_striter();
	uf_test_strjoin();
	uf_test_strsub();
	uf_test_strtrim();
	uf_test_strsplit();
	uf_test_lstnew();
	uf_test_lstdel();
	uf_test_lstadd();
	uf_test_lstdelone();
	uf_test_lstiter();
	uf_test_lstmap();
	

	return (1);
}
