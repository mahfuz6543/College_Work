//
// Created by Mahfuzul Islam on 10/07/2021.
// ID: 23839057
//
#include <iostream>
#include <cassert>	// ASSERT FOR PRECONDITIONS
#include "sequence1.h"
using namespace std;

namespace main_savitch_3
{
// TYPEDEFS and MEMBER CONSTANTS
    typedef double value_type;
    typedef size_t size_type; //typedef std::size_t size_type;
    static const size_type CAPACITY = 30; // enum {CAPACITY = 30}; //

// CONSTRUCTOR for the sequence1 class:
    sequence1::sequence1()
    {
        used = 0; //the amount of the array used is set to 0
        current_index = 0; //the current index is set to 0
        data[current_index] = 0; // array initialized
    }

// MODIFICATION MEMBER FUNCTIONS for the sequence1 class:
//		Postcondition: The first item on the sequence1 becomes the current item
//		(but if the sequence1 is empty, then there is no current item).
    void sequence1::start()
    { current_index = 0; }

//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence1, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
    void sequence1::advance()
    {
        assert(is_item());
        current_index++;
    }

//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence1
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence1. In either case, the newly
//     inserted item is now the current item of the sequence1.
    void sequence1::insert(const value_type& entry)
    {
        assert(size() < CAPACITY);
        if (!is_item()) // if there is no current item
        {current_index = 0;}
        for (size_type i = used; i > current_index; --i)
        {data[i] = data[i - 1];}
        data[current_index] = entry;
        ++used;
    }
// REFERENCED FROM Data Structures and Other Objects Using C++ PAGE 131

//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence1 after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence1. In either case, the newly
//     inserted item is now the current item of the sequence1.
    void sequence1::attach(const value_type& entry)
    {
        assert(size() < CAPACITY);
        if (!is_item()) // if there is no current item
        {
            data[current_index] = entry;
        }
        else
        {
            for (size_type i = used; i > current_index; --i)
            {
                data[i] = data[i - 1];
            }
            data[current_index + 1] = entry;
            current_index += 1;
        }
        ++used;
    }

//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence1, and the
//     item after this (if there is one) is now the new current item.
    void sequence1::remove_current()
    {
        assert(is_item());
        for (size_type i = current_index;i < used; ++i)
        { data[i] = data[i + 1]; }
        --used;
// REFERENCED FROM Data Structures and Other Objects Using C++ PAGE 131 The Sequence Class—Pseudocode for the Implementation
    }

// CONSTANT MEMBER FUNCTIONS for the sequence1 class:
//     Postcondition: The return value is the number of items in the sequence1.
    size_type sequence1::size() const
    {
        return used;
    }

//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
    bool sequence1::is_item() const
    {
        return (current_index < used);
    }

//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence1.
    value_type sequence1::current() const
    {
        assert(is_item());
        return data[current_index];
    }

}
