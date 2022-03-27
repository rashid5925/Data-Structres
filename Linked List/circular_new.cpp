#include <iostream>

using namespace std;

struct Stu
{
	int id;
	Stu *next = NULL;
};

void display(int num);
void insert(int num);
void merge();

Stu *last1 = NULL;
Stu *last2 = NULL;
Stu *merged = NULL;

int main()
{
	int exit = 1;
	do
	{
		cout << "Enter number to perform operation\n"
			 << "1. Display 1st\n"
			 << "2. Insert in 1st\n"
			 << "3. Display 2nd\n"
			 << "4. Insert in 2nd\n"
			 << "5. Merge\n"
			 << "6. Display merged\n"
			 << "0. Exit\n";
		cin >> exit;

		switch (exit)
		{
		case 0:
			cout << "Exit...\n";
			break;
		case 1:
			display(1);
			break;
		case 2:
			insert(1);
			break;
		case 3:
			display(2);
			break;
		case 4:
			insert(2);
			break;
		case 5:
			merge();
			break;
		case 6:
			display(3);
			break;
		default:
			cout << "Wrong input\n";
			break;
		}
	} while (exit != 0);
}

void display(int num)
{
	if (last1 != NULL)
	{
		if (num == 1)
		{
			Stu *p = last1->next;
			while (p != last1)
			{
				cout << "ID: " << p->id << "\n";
				p = p->next;
			}
			cout << "ID: " << p->id << "\n";
		}
	}
	if (last2 != NULL)
	{
		if (num == 2)
		{
			Stu *p = last2->next;
			while (p != last2)
			{
				cout << "ID: " << p->id << "\n";
				p = p->next;
			}
			cout << "ID: " << p->id << "\n";
		}
	}
	if (merged != NULL)
	{
		if (num == 3)
		{
			Stu *p = merged->next;
			while (p != merged)
			{
				cout << "ID: " << p->id << "\n";
				p = p->next;
			}
			cout << "ID: " << p->id << "\n";
		}
	}
}

void insert(int num)
{
	Stu *p = new Stu;
	if (last1 != NULL)
	{
		if (num == 1)
		{
			cout << "Enter ID: ";
			cin >> p->id;
			p->next = last1->next;
			last1->next = p;
			last1 = p;
		}
	}
	if (last2 != NULL)
	{
		if (num == 2)
		{
			cout << "Enter ID: ";
			cin >> p->id;
			p->next = last2->next;
			last2->next = p;
			last2 = p;
		}
	}
	if (last1 == NULL)
	{
		cout << "Enter ID: ";
		cin >> p->id;
		if (num == 1)
		{
			last1 = p;
			p->next = last1;
		}
	}
	if (last2 == NULL)
	{
		if (num == 2)
		{
			cout << "Enter ID: ";
			cin >> p->id;
			last2 = p;
			p->next = last2;
		}
	}
}

void merge()
{
	if (last1 == NULL)
	{
		merged = last2;
		last2 = NULL;
	}
	else if (last2 == NULL)
	{
		merged = last1;
		last1 = NULL;
	}
    else if (last1 == NULL && last2 == NULL)
    {
        return;
    }
    
	else
	{
		Stu *p = NULL;
		Stu *q = NULL;
		Stu *large1 = NULL;
		Stu *large2 = NULL;
		Stu *temp = NULL;
		while (last1 != NULL || last2 != NULL)
		{
			if (last1 != NULL)
			{
				p = last1;
				large1 = last1->next;
				do
				{
					if (p->id > large1->id)
					{
						large1 = p;
					}
					p = p->next;
				} while (p != last1);
			}
			if (last2 != NULL)
			{
				q = last2;
				large2 = last2->next;
				do
				{
					if (q->id > large2->id)
					{
						large2 = q;
					}
					q = q->next;
				} while (q != last2);
			}

			if (last2 != NULL)
			{
				if (large2 == last2)
				{
					if (large2 == large2->next)
					{
						last2 = NULL;
					}
					else
					{
						temp = last2;
						while (temp->next != last2)
						{
							temp = temp->next;
						}
						temp->next = large2->next;
						last2 = temp;
					}
				}
				else
				{
					temp = last2;
					while (temp->next != large2)
					{
						temp = temp->next;
					}
					temp->next = large2->next;
				}

				if (merged == NULL)
				{
					merged = large2;
					merged->next = large2;
				}
				else
				{
					large2->next = merged->next;
					merged->next = large2;
					merged = large2;
				}
			}
			if (last1 != NULL)
			{
				if (large1 == last1)
				{
					if (large1 == large1->next)
					{
						last1 = NULL;
					}
					else
					{
						temp = last1;
						while (temp->next != last1)
						{
							temp = temp->next;
						}

						temp->next = large1->next;
						last1 = temp;
					}
				}
				else
				{
					temp = last1;
					while (temp->next != large1)
					{
						temp = temp->next;
					}

					temp->next = large1->next;
				}

				if (merged == NULL)
				{
					merged = large1;
					merged->next = large1;
				}
				else
				{
					large1->next = merged->next;
					merged->next = large1;
					merged = large1;
				}
			}
			
		}
	}
}
