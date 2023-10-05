//
// Created by Mahfuzul on 10/7/2021.
// ID: 23839057
//
// FILE: sequence1.h
// CLASS PROVIDED: sequence1 (part of the namespace main_savitch_3)
// There is no implementation file provided for this class since it is
// an exercise from Section 3.2 of "Data Structures and Other Objects Using C++"
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence1 class:
//   typedef ____ value_type
//     sequence1::value_type is the data type of the items in the sequence1. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     sequence1::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence1.
//
//   static const size_type CAPACITY = _____
//     sequence1::CAPACITY is the maximum number of items that a sequence1 can hold.
//
// CONSTRUCTOR for the sequence1 class:
//   sequence1( )
//     Postcondition: The sequence1 has been initialized as an empty sequence1.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence1 class:
//   void start( )
//     Postcondition: The first item on the sequence1 becomes the current item
//     (but if the sequence1 is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence1, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence1
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence1. In either case, the newly
//     inserted item is now the current item of the sequence1.
//
//   void attach(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence1 after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence1. In either case, the newly
//     inserted item is now the current item of the sequence1.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence1, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence1 class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence1.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence1.
//
// VALUE SEMANTICS for the sequence1 class:
//    Assignments and the copy constructor may be used with sequence1 objects.

#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_3
{

    class sequence1
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef size_t size_type; //typedef std::size_t size_type;
        static const size_type CAPACITY = 30; // enum {CAPACITY = 30}; //
        // CONSTRUCTOR
        sequence1();
        // MODIFICATION MEMBER FUNCTIONS
        void start();
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const;
        bool is_item() const;
        value_type current() const;
    private:
        value_type data[CAPACITY]; // array of stored items
        size_type used; // the amount of array used
        size_type current_index; // the current index of the current item
        // REFERENCED FROM Data Structures and Other Objects Using C++ PAGE 127 The Sequence Class—Design
    };
}

#endif