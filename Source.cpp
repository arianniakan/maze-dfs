#include<iostream>

using namespace std;
class node {
public:
	int num;
	int num_of_edges;
	int* edges;
	node* next;
};

node* create_node(int value) {
	node* new_node = new node;
	new_node->num = value;
	new_node->edges = new int;
	new_node->edges = NULL;
	new_node->num_of_edges = 0;
	new_node->next = NULL;
	return new_node;
}

void insert_edges(node** start, int left, int right)
{
	node* curr = *start;
	if (curr == NULL)
	{
		node* new_start = new node;
		new_start = create_node(left);
		new_start->num_of_edges++;
		new_start->edges = (int*)realloc(new_start->edges, new_start->num_of_edges * sizeof(int));
		new_start->edges[new_start->num_of_edges - 1] = right;
		*start = new_start;
		return;
	}
	while (1 == 1)
	{
		if (curr->num == left)
		{
			curr->num_of_edges++;
			curr->edges = (int*)realloc(curr->edges, curr->num_of_edges * sizeof(int));
			curr->edges[curr->num_of_edges - 1] = right;
			return;
		}
		curr = curr->next;
		if (curr == NULL)
		{
			node* new_node = new node;
			new_node = create_node(left);
			new_node->num_of_edges++;
			new_node->edges = (int*)realloc(new_node->edges, new_node->num_of_edges * sizeof(int));
			new_node->edges[new_node->num_of_edges - 1] = right;
			new_node->next = *start;
			*start = new_node;
			curr = *start;
			return;
		}
	}
}

int* solution;


int get_out(node* start, int start_num, int end_num,int index)
{
	node* curr = start;
	int is_the_way = 0;
	while (true)
	{
		if (curr == NULL)
		{
			return 0;
		}

		if (start_num == end_num)
		{
			return 1;
		}
		
		if (curr->num == start_num)
		{
			if (curr->num_of_edges != 0)
			{
				index++;
				for (int i = 0;i < curr->num_of_edges;i++)
				{
					is_the_way = get_out(start, curr->edges[i], end_num,index);
					if (is_the_way == 1)
					{
						
						solution[index-1] = curr->edges[i];
						return 1;
					}
				}

			}
			else if (curr->num_of_edges == 0)
			{
				return 0;
			}
		}
		curr = curr->next;

	}
	

}


int main()
{
	int nodes, edges = 0;
	cin >> nodes;
	cin >> edges;
	int left, right = 0;
	node* Start = NULL;
	int i = 0;
	solution = (int*)malloc(edges * sizeof(int));
	while (1 == 1)
	{
		if (i == edges)
		{
			break;
		}
		cin >> left;
		cin >> right;
		insert_edges(&Start, left, right);
		i++;
	}
	get_out(Start, 1, nodes,0);
	int j = 0;
	cout << 1<<" ";
	while (1 == 1)
	{
		cout << solution[j]<<" ";
		j++;
		if (solution[j-1] == nodes)
		{
			break;
		}
	}
}