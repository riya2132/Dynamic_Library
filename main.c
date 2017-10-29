#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
void main()
{
    int c;
    while(1)
    {
        printf("\n1.linked list\n2.doubly linked list\n3.circular linked list\n4.stack using array\n5.stack usinglinked list\n6.queue\n7.circular queue\n8.dequeue\n9.priority queue\n10.searching an array\n11.sorting an array\n12.expression tree\n13.bst\n14.threaded tree\n15.quit\nenter ur choice:");
        scanf("%d",&c);
        system("cls");
        switch(c)
        {
            case 1:
                linkedlist();
                break;
            case 2:
                doublyll();
                break;
            case 3:
                cirll();
                break;
            case 4:
                stack1();
                break;
            case 5:
                stackll();
                break;
            case 6:
                queue1();
                break;
            case 7:
                cirqueue();
                break;
            case 8:
                dequeue1();
                break;
            case 9:
                prique();
                break;
            case 10:
                searcha();
                break;
            case 11:
                sorta();
                break;
            case 12:
                exptree();
                break;
            case 13:
                bst();
                break;
            case 14:
                threadedtree();
                break;
            case 15:
                exit(1);
        }
    }
}
