//
// Created by Mahfuzul Islam on 10/20/2021.
// Email: mislam048@citymail.cuny.edu
//

#include <iostream>
#include <cassert>	// ASSERT FOR PRECONDITIONS
#include <algorithm>// COPY FOR CONSTRUCTOR AND ASSIGNMENT OPERATOR
#include "sequence2.h"
#include "seq_ex2.cpp"
using namespace std;

namespace main_savitch_4
{
    // TYPEDEFS and MEMBER CONSTANTS for the sequence class:
    typedef double value_type;
    typedef size_t size_type; //typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 30; //enum {DEFAULT_CAPACITY = 30};

    // CONSTRUCTOR for the sequence class:
    sequence::sequence(size_type initial_capacity)
//     Postcondition: The sequence has been initialized as an empty sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
    {
        data = new value_type[initial_capacity];
        used = 0;
        current_index = 0;
        capacity = initial_capacity;
    }

    sequence::sequence(const sequence& source)
    //Postcondition: The sequence's data members are copied from the source sequence.
    {
        data = new value_type[source.capacity];
        used = source.used;
        current_index = source.current_index;
        capacity = source.capacity;
        copy(source.data, source.data + used, data);
    }

    sequence::~sequence()
    //Postcondition: Releases the dynamically allocated memory
    {
        delete[] data;
    }

    // MODIFICATION MEMBER FUNCTIONS for the sequence class:
    void sequence::resize(size_type new_capacity)
//     Postcondition: The sequence's current capacity is changed to the
//     new_capacity (but not less that the number of items already on the
//     sequence). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
    {
        value_type* bigger_array;

        if (new_capacity == capacity)
        {
            return;
        }

        if (new_capacity < used)
        {
            new_capacity = used;
        }

        bigger_array = new value_type[new_capacity];
        copy(data, data + used, bigger_array);
        delete[] data;
        data = bigger_array;
        capacity = new_capacity;
    }

    void sequence::start()
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
    {
        if (size() > 0)
        { current_index = 0; }
    }

    void sequence::advance()
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item on the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
    {
        assert(is_item());
        current_index++;
    }

    void sequence::insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence before
//     the current item. If there was no current item, then the new entry has
//     been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
    {
        if (size() == capacity)
        {
            resize(capacity + DEFAULT_CAPACITY);
        }
        if (!is_item())
        {
            current_index = 0;
        }
        for (size_type i = used; i > current_index; i--)
        {
            data[i] = data[i - 1];
        }
        data[current_index] = entry;
        used++;
    }

    void sequence::attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
    {
        if (size() == capacity)
        { resize(capacity + DEFAULT_CAPACITY); }
        if (!is_item())
        { current_index = used - 1; }
        current_index++;
        for (size_type i = used; i > current_index;i--)
        {
            data[i] = data[i - 1];
        }
        data[current_index] = entry;
        used++;
    }

    void sequence::remove_current()
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
    {
        assert(is_item());
        for (size_type i = current_index; i < (used - 1); ++i)
        {
            data[i] = data[i + 1];
        }
        used--;
    }

    void sequence::operator=(const sequence& source)
//		Postcondition: Overloaded assignment operator for sequence class
    {
        value_type* new_data;
        // checks for self-assignment
        if (this == &source)
        {
            return;
        }
        if (capacity != source.capacity)
            // checks to see if sequence capacity needs to be adjusted for source capacity before assignment
        {
            new_data = new value_type[source.capacity];
            delete[] data;
            data = new_data;
            capacity = source.capacity;
        }
        current_index = source.current_index;
        used = source.used;
        copy(source.data, source.data + used, data);
    }
    // REFERENCED FROM Data Structures and Other Objects Using C++ PAGE 188 bag assignment operator

    void sequence::operator+=(const sequence& source)
//		Precondition: size() + source.size() <= capacity.
//		Postcondition: Appends all the items in source to the end of what’s already in the sequence
    {
        assert(size() + source.size() <= capacity);
        if (capacity < used + source.used)
        { resize(used + source.used); }
        copy(source.data, source.data + source.used, data + used);
        used += source.used;
    }
    // REFERENCED FROM Data Structures and Other Objects Using C++ PAGE 116 A Member Function Implementation

    // CONSTANT MEMBER FUNCTIONS for the sequence class:
    size_type sequence::size() const
//     Postcondition: The return value is the number of items on the sequence.
    {
        return used;
    }

    bool sequence::is_item() const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
    {
        return (current_index < used);
    }

    value_type sequence::current() const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item on the sequence.
    {
        assert(is_item());
        return data[current_index];
    }

    value_type sequence::operator[](size_type index) const
//     Precondition: is_item( ) returns true.
//     Postcondition: Subscript operator which allows sequence x to use x[1], x[2], x[3]... etc
    {
        assert(is_item());
        return data[index];
    }

    sequence operator+(const sequence& source1, const sequence& source2)
//		Postcondition: Returns a sequence which ontains all the items of source1, followed by all the items in source2.
    {
        sequence sum;
        sum += source1;
        sum += source2;
        return sum;
    }
}

