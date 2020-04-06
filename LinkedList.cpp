/*
 *
 * 
 * 
 * 
 * 
 * 
 * 
 */

#include <iostream>
using namespace std;

struct list
{
    int val;
    list *next;
};

class Node {
private:
    list *data;
public:
    void insert(int x) {
        list* t = data;
        if (data != NULL) {
            while(t->next != NULL){
                t = t->next;
            }
            list *n = new list;
		    t->next = n;
		    n->val = x;
		    n->next = NULL;
        } else {
		    list *n = new list;
		    n->val = x;
		    n->next = NULL;
		    data = n;
	    }
    }

    void remove(int x) {
        list *t = data;
        list *p;
        while(t->val!=x)
        {
            p=t;
            t=t->next;
        }
        p->next=t->next;
        delete t;
    }

    void search(int x) {
        list *t= data;
        int found =0;
        while(t!=NULL)
        {
            if(t->val==x)
            {
                cout<<"\nFound";
                found = 1;
                break;
            }
            t = t->next;
        }
        if(found==0)
        {
            cout << "\nNot Found" << endl;
        }
    }

    void show() {
        list *t = data;
        while(t != NULL)
        {
            cout << t->val << "  " << endl;
            t = t->next;
        }
    }
};

int
main(void) {
    Node test;
    test.insert(1);
    test.show();
    return 0;
}
