#pragma once
#include <iostream>
struct Node
{
	int number;
	Node* next;
};

class ListNode
{
private:
	struct Node* head = nullptr;
public:
	void insertNode(int number);
	void display();
	void deleteItem();
};
