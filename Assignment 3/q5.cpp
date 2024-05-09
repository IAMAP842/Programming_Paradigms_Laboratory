#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int coefficient;
    int exponent;
    Node *next;

    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void addNode(int coeff, int exp)
    {
        Node *newNode = new Node(coeff, exp);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->coefficient << "x^" << temp->exponent;
            if (temp->next != nullptr)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }

    LinkedList addPolynomials(LinkedList &poly2)
    {
        LinkedList result;
        Node *temp1 = head;
        Node *temp2 = poly2.head;

        while (temp1 != nullptr || temp2 != nullptr)
        {
            int coeff1 = (temp1 != nullptr) ? temp1->coefficient : 0;
            int exp1 = (temp1 != nullptr) ? temp1->exponent : 0;

            int coeff2 = (temp2 != nullptr) ? temp2->coefficient : 0;
            int exp2 = (temp2 != nullptr) ? temp2->exponent : 0;

            if (exp1 == exp2)
            {
                result.addNode(coeff1 + coeff2, exp1);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (exp1 > exp2)
            {
                result.addNode(coeff1, exp1);
                temp1 = temp1->next;
            }
            else
            {
                result.addNode(coeff2, exp2);
                temp2 = temp2->next;
            }
        }
        return result;
    }
};

int main()
{
    LinkedList poly1, poly2, result;

    // adding to polynomial 1
    poly1.addNode(3, 2); // 3x^2
    poly1.addNode(2, 1); // 2x^1
    poly1.addNode(5, 0); // 5x^0

    // adding to polynomial 2
    poly2.addNode(4, 3); // 4x^3
    poly2.addNode(1, 1); // 1x^1
    poly2.addNode(2, 0); // 2x^0

    cout << "Polynomial 1: ";
    poly1.display();
    cout << "Polynomial 2: ";
    poly2.display();

    result = poly1.addPolynomials(poly2);

    cout << "Resultant Polynomial: ";
    result.display();

    return 0;
}