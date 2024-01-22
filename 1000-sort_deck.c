#include "deck.h"

int cmp_str(const char *str1, const char *str2);
char fetch_val(deck_node_t *crd_ptr);
void deck_kind_insert_sort(deck_node_t **dck_ptr);
void deck_val_insert_sort(deck_node_t **dck_ptr);
void sort_deck(deck_node_t **deck);

/**
 * cmp_str - Function to compare two strings
 * @str1: The first string
 * @str2: The second string
 * Return: If str 1 == str2: 0
 * if str1 > str2: positive byte difference
 * if str1 < str2: negative byte difference
*/
int cmp_str(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * fetch_val - Fetches the card's numerical value
 * @crd_ptr: The pointer to a deck_node_t card
 * Return: The card's numerical value
*/
char fetch_val(deck_node_t *crd_ptr)
{
	if (cmp_str(crd_ptr->card->value, "Ace") == 0)
		return (0);
	if (cmp_str(crd_ptr->card->value, "1") == 0)
		return (1);
	if (cmp_str(crd_ptr->card->value, "2") == 0)
		return (2);
	if (cmp_str(crd_ptr->card->value, "3") == 0)
		return (3);
	if (cmp_str(crd_ptr->card->value, "4") == 0)
		return (4);
	if (cmp_str(crd_ptr->card->value, "5") == 0)
		return (5);
	if (cmp_str(crd_ptr->card->value, "6") == 0)
		return (6);
	if (cmp_str(crd_ptr->card->value, "7") == 0)
		return (7);
	if (cmp_str(crd_ptr->card->value, "8") == 0)
		return (8);
	if (cmp_str(crd_ptr->card->value, "9") == 0)
		return (9);
	if (cmp_str(crd_ptr->card->value, "10") == 0)
		return (10);
	if (cmp_str(crd_ptr->card->value, "Jack") == 0)
		return (11);
	if (cmp_str(crd_ptr->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * deck_kind_insert_sort - Sorts a deck from spades to diamonds
 * @dck_ptr: Pointer to deck_node_t doubly linked list head
*/
void deck_kind_insert_sort(deck_node_t **dck_ptr)
{
	deck_node_t *x, *embed, *temp;

	for (x = (*dck_ptr)->next; x != NULL; x = temp)
	{
		temp = x->next;
		embed = x->prev;
		while (embed != NULL && embed->card->kind > x->card->kind)
		{
			embed->next = x->next;
			if (x->next != NULL)
				x->next->prev = embed;
			x->prev = embed->prev;
			x->next = embed;
			if (embed->prev != NULL)
				embed->prev->next = x;
			else
				*dck_ptr = x;
			embed->prev = x;
			embed = x->prev;
		}
	}
}

/**
 * deck_val_insert_sort - Function to sort a card deck from
 * spades to diamonds and from ace to king
 * @dck_ptr: Pointer to a deck_node_t doubly linked list head
*/
void deck_val_insert_sort(deck_node_t **dck_ptr)
{
	deck_node_t *x, *embed, *temp;

	for (x = (*dck_ptr)->next; x != NULL; x = temp)
	{
		temp = x->next;
		embed = x->prev;
		while (embed != NULL &&
			embed->card->kind == x->card->kind &&
			fetch_val(embed) > fetch_val(x))
		{
			embed->next = x->next;
			if (x->next != NULL)
				x->next->prev = embed;
			x->prev = embed->prev;
			x->next = embed;
			if (embed->prev != NULL)
				embed->prev->next = x;
			else
				*dck_ptr = x;
			embed->prev = x;
			embed = x->prev;
		}
	}
}

/**
 * sort_deck - Sorts a card deck form Ace to king
 * and from spades to diamonds
 * @deck: Pointer to a deck_node_t doubly linked list head
*/
void sort_deck(deck_node_t **deck)
{
	if (!deck || !*deck || !(*deck)->next)
		return;

	deck_kind_insert_sort(deck);
	deck_val_insert_sort(deck);
}
