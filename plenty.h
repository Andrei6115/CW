#ifndef PLENTY_H
# define PLENTY_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_plenty
{
	int				data;
	struct s_plenty	*next;
	struct s_plenty	*prev;
} t_plenty;

void	plentyMenu(t_plenty **plenty);
int		startWorkWithStruct(char *structName);
void	cleanerPlenty(t_plenty **plenty);
void	printPlenty(t_plenty *plenty);
#endif