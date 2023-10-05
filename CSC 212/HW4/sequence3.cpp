//
// Created by Mahfuzul Islam on 11/2/2021.
// ID: 23839057
//
#include <iostream>
#include <cassert> // ASSERT FOR PRECONDITIONS
#include "sequence3.h"
#include "seq_ex3.cpp"

using namespace std;

namespace main_savitch_5
{
// TYPEDEF
    typedef size_t size_type;
    typedef node::value_type value_type;

// CONSTRUCTOR for the sequence class:
    // Linked List Big-O: O(1)
    // Dynamic Array Big-O: O(1)
    sequence::sequence()
    // Postcondition: The sequence has been initialized as an empty sequence.
    {
        cursor = NULL;
        precursor = NULL;
        head_ptr = NULL;
        tail_ptr = NULL;
        used = 0;
    }

    // Linked List Big-O: O(n)
    // Dynamic Array Big-O: O(n)
    sequence::sequence(const sequence& source)
    // Postcondition: The sequence's data members are copied from the source sequence.
    {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        cursor = head_ptr;
        precursor = NULL; // invariant 3
        used = source.used; // used = source.size();

        precursor = source.cursor; // sets precursor as source's cursor, which is
        // cannot set cursor to be item after source.cursor
        // workaround: use a temporary node to move to source.precursor while also moving cursor, which is at head_ptr.
        node* temp = source.head_ptr; // set a temporary node at source's first item
        while (temp != source.cursor) // while temp is not at the source cursor
        {
            temp = temp->link(); //moves temp to the next item in sequence until it is at the item before source.cursor, which is source.precursor
            cursor = cursor->link(); // moves the cursor starting at source.head_ptr to the next item until it reaches the item after source.cursor
        }
    }

    // Linked List Big-O: O(n)
    // Dynamic Array Big-O: O(n)
    sequence::~sequence()
    // Postcondition: Destructor for sequence class
    {
        list_clear(head_ptr);
        used = 0; // "zeroing out the list"- Data Structures and Other Objects Using C++ PAGE 266 bag destructor
    }

// MODIFICATION MEMBER FUNCTIONS for the sequence class:
    // Linked List Big-O: O(1)
    // Dynamic Array Big-O: O(1)
    void sequence::start()
    // Postcondition: The first item on the sequence becomes the current item
    // (but if the sequence is empty, then there is no current item).
    {
        cursor = head_ptr;
        precursor = NULL; // Invariant 3
    }

    // Linked List Big-O: O(1)
    // Dynamic Array Big-O: O(1)
    void sequence::advance()
    // Precondition: is_item returns true.
    // Postcondition: If the current item was already the last item on the
    // sequence, then there is no longer any current item. Otherwise, the new
    // current item is the item immediately after the original current item.
    {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }

    // Linked List Big-O: O(1)
    // Dynamic Array Big-O: O(n)
    void sequence::insert(const value_type& entry)
    // Postcondition: A new copy of entry has been inserted in the sequence before
    // the current item. If there was no current item, then the new entry has
    // been inserted at the front of the sequence. In either case, the newly
    // inserted item is now the current item of the sequence.
    {
        if (!is_item() || cursor == head_ptr) // if there is no current item or the current item is the first item on the list
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr; // new entry becomes current item
            precursor = NULL; // Invariant 3
        }

        else // if there is a current item and it isn't the first item on the list
        {
            list_insert(precursor, entry);
            cursor = precursor->link();
        }
        used++;
    }

    // Linked List Big-O: O(1)
    // Dynamic Array Big-O: O(n)
    void sequence::attach(const value_type& entry)
    // Postcondition: A new copy of entry has been inserted in the sequence after
    // the current item. If there was no current item, then the new entry has
    // been attached to the end of the sequence. In either case, the newly
    // inserted item is now the current item of the sequence.
    {
        if (is_item()) // if there is a current item
        {
            list_insert(cursor, entry);
            precursor = cursor;
            cursor = cursor->link();
        }

        else
        {
            if (precursor == NULL) // if the current item is the first item on the list
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL; // Invariant 3
            }

            else // if current item is not the first item on the list
            {
                cursor = list_locate(head_ptr, list_length(head_ptr)); // sets current item to head pointer
                list_insert(cursor, entry);
                cursor = precursor->link();
            }
        }
        used++;
    }

    // Linked List Big-O: O(1)
    // Dynamic Array Big-O: O(n)
    void sequence::remove_current()
    // Precondition: is_item returns true.
    // Postcondition: The current item has been removed from the sequence, and the
    // item after this (if there is one) is now the new current item.
    {
        assert(is_item());
        if (cursor == head_ptr) // if the current item is the first item in the sequence
        {
            list_head_remove(head_ptr);
            cursor = head_ptr;
            precursor = NULL; // Invariant 3
        }

        else
        {
            cursor = cursor->link(); // the next item becomes the current item
            list_remove(precursor);
        }
        used--;
    }

    // Linked List Big-O: O(n)
    // Dynamic Array Big-O: O(n)
    void sequence::operator=(const sequence& source)
    // Postcondition: Overloaded assignment operator for sequence class
    {
        if (this == &source) // checks for self assignment
        { return; }

        list_clear(head_ptr);
        used = 0;

        list_copy(source.head_ptr, head_ptr, tail_ptr);
        used = source.used; // used = source.size();
        cursor = head_ptr;
        precursor = NULL; // Invariant 3

        precursor = source.cursor; // sets precursor as source's cursor, which is
        // same issue as copy constructor; cannot set cursor to be item after source.cursor
        node* temp = source.head_ptr;
        while (temp != source.cursor)
        {
            temp = temp->link();
            cursor = cursor->link();
        }
    }

    // CONSTANT MEMBER FUNCTIONS for the sequence class:
    // Linked List Big-O: O(1)
    // Dynamic Array Big-O: O(1)
    size_t sequence::size() const
    // Postcondition: The return value is the number of items on the sequence.
    {
        return used;
    }

    // Linked List Big-O: O(1)
    // Dynamic Array Big-O: O(1)
    bool sequence::is_item() const
    // Postcondition: A true return value indicates that there is a valid
    // "current" item that may be retrieved by activating the current
    // member function (listed below). A false return value indicates that
    // there is no valid current item.
    {
        return (cursor != NULL);
    }

    // Linked List Big-O: O(1)
    // Dynamic Array Big-O: O(1)
    value_type sequence::current() const
    // Precondition: is_item( ) returns true.
    // Postcondition: The item returned is the current item on the sequence.
    {
        assert(is_item());
        return cursor->data();
    }
}