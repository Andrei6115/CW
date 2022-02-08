#include "plenty.h"

int	startWorkWithStruct(char *structName)
{
	int	select;
	printf("Start work with \"%s\"\n1\tStart\nAny\tExit\nU enter:", structName);
	scanf("%d", &select);
	system("cls");
	if (select == 1)
		return (1);
	else
		return (0);
}

void	cleanerPlenty(t_plenty **plenty)
{
	t_plenty	*tmp;
	t_plenty	*list;
	
	if (*plenty)
	{	
		list = *plenty;
		while (list)
		{
			tmp = list->next;
			free(list);
			list = tmp;
		}
		*plenty = NULL;
	}
	else
	{
		printf("Plenty clear\n");
	}
}

void isEmpty(t_plenty *plenty)
{
	if (!plenty)
		printf("List clear\n");
	else
		printf("List not clear\n");
}

int	equalPlenty(t_plenty *first, t_plenty *second)
{
	if(first->data == second->data)
	{
		return 1;
	}
	else
		return 0;

}

static t_plenty	*lastText(t_plenty *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void addEl(t_plenty **plenty)
{
	t_plenty	*new;
	t_plenty	*last;
	t_plenty	*temp;

	new = malloc(sizeof(t_plenty));
	if (!new)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	new->next = NULL;
	new->prev = NULL;
	printf("Enter data el: ");
	scanf("%d", &new->data);
	printf("\n");
	temp = (*plenty);
	while (temp)
	{
		if (equalPlenty(temp, new))
		{
			printf("Equal el!\n");
			free (new);
			return;
		}
		temp = temp->next;
	}
	if (!*plenty)
	{
		*plenty = new;
	}
	else
	{
		last = lastText(*plenty);
		last->next = new;
	}
}

void	deleteEl(t_plenty **plenty)
{
	t_plenty	*temp;
	t_plenty	*del;
	t_plenty	*new;

	if (!*plenty)
	{
		printf("Plenty empty\n");
		return;
	}
	new = malloc(sizeof(t_plenty));
	if (!new)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	new->next = NULL;
	printf("Enter the data el to be removed: ");
	scanf("%d", &new->data);
	printf("\n");
	temp = (*plenty);
	if (equalPlenty(temp, new))
	{
		free (new);
		*plenty = temp->next;
		free (temp);
		return;
	}
	while (temp->next)
	{
		if (equalPlenty(temp->next, new))
		{
			free (new);
			del = temp->next;
			temp->next = temp->next->next;
			free (del);
			return;
		}
		temp = temp->next;
	}
}

void	takeEl(t_plenty **plenty, t_plenty **taked)
{
	t_plenty	*temp;
	t_plenty	*new;

	if (!*plenty)
	{
		printf("Plenty empty\n");
		return;
	}
	new = malloc(sizeof(t_plenty));
	if (!new)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	new->next = NULL;
	printf("Enter the data el to be taked: ");
	scanf("%d", &new->data);
	printf("\n");
	temp = (*plenty);
	if (equalPlenty(temp, new))
	{
		if (*taked)
		{
			free (*taked);
			*taked = NULL;
		}
		free (new);
		*plenty = temp->next;
		*taked = temp;
		printf("Taked El: %d\n", (*taked)->data);
		return;
	}
	while (temp->next)
	{
		if (equalPlenty(temp->next, new))
		{
			if (*taked)
			{
				free (*taked);
				*taked = NULL;
			}
			free (new);
			*taked = temp->next;
			printf("Taked El: %d\n", (*taked)->data);
			temp->next = temp->next->next;
			return;
		}
		temp = temp->next;
	}
}

void searchEl(t_plenty **plenty)
{
	t_plenty	*new;
	t_plenty	*temp;

	if (!*plenty)
	{
		printf("Plenty empty\n");
		return;
	}
	new = malloc(sizeof(t_plenty));
	if (!new)
	{
		printf("MEM ERROR\n");
		exit(1);
	}
	new->next = NULL;
	printf("Enter the data el to be search: ");
	scanf("%d", &new->data);
	printf("\n");
	temp = (*plenty);
	while (temp)
	{
		if (equalPlenty(temp, new))
		{
			printf("Equal el\n");
			free (new);
			return;
		}
		temp = temp->next;
	}
	printf("No equal el\n");
}		

void	printPlenty(t_plenty *plenty)
{
	if (plenty)
	{
		printf("Plenty:\n");
		while (plenty)
		{
			printf("%d\t", plenty->data);
			plenty = plenty->next;
		}
		printf("\n");
	}
	else
	{
		printf("Empty plenty\n");
	}
}

void	plentyMenu(t_plenty **plenty)
{
	int			flag;
	t_plenty	*taked;

	if(!startWorkWithStruct("Plenty"))
		return;
	flag = 1;
	*plenty = NULL;
	taked = NULL;
	while (flag)
	{
		printPlenty(*plenty);
		printf("1. Cleaner\n2. Plenty clear?\n3. Delete El\n4. Take el\n5. Add el\n6. Search el\n7. Print\n0. Exit\n");
		scanf("%d", &flag);
		printf("\n");
		system("cls");
		
		switch (flag)
		{
		case 1:
			cleanerPlenty(plenty);
			break;
		case 2:
			isEmpty(*plenty);
			break;
		case 3:
			deleteEl(plenty);
			break;
		case 4:
			takeEl(plenty, &taked);
			break;
		case 5:
			addEl(plenty);
			break;
		case 6:
			searchEl(plenty);
			break;
		case 7:
			printPlenty(*plenty);
			break;
		case 0:
			return;
		default:
			printf("Input error\n");
			break;
		}
	}
}