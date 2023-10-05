//
// Created by Mahfuzul Islam on 9/23/2021.
//
#include "stats.h"
#include <iostream>
#include <assert.h> //PRECONDITIONS


using namespace std;
namespace main_savitch_2C
{
    // CONSTRUCTOR
    statistician::statistician(){
        /*     Postcondition: Statistics will be calculated about the
             sequence.*/
        m_len = 0;
        m_sum = 0;
        m_min = 0;
        m_max = 0;
    }

    // MODIFICATION MEMBER FUNCTIONS
    void statistician::next(double r)
    /*     The number r has been given to the statistician as the next number in
         its sequence of numbers.*/
    {
        if (m_len == 0) // If m_len==1, meaning it's the first number. Then r is both the largest and smallest
        {
            m_len = 1;
            m_sum = r;
            m_min = r;
            m_max = r;
            return;
        }

        m_len += 1;
        m_sum += r;

        if (r < m_min) //If r is smaller than previous, replace smallest with r
        {m_min = r;}

        if (r > m_max) //If r is larger than previous, replace largest with r
        {m_max = r;}
    }

    void statistician::reset()
    /*     Postcondition: The statistician has been cleared, as if no numbers had
           yet been given to it. */
    {
        m_len = 0; //Reset numbers
        m_sum = 0; //Reset sums
        m_min = 0; //Reset min
        m_max = 0; //Reset max
    }

    // CONSTANT MEMBER FUNCTIONS
    int statistician::length() const{
        return m_len;}

    double statistician::sum() const{
        return m_sum;}

    double statistician::mean() const{
        assert(length() > 0); //PRECONDITION
        double avg = 0;
        avg = m_sum / m_len;
        return avg;}

    double statistician::minimum() const{
        assert(length() > 0); //PRECONDITION
        return m_min;}

    double statistician::maximum() const{
        assert(length() > 0); //PRECONDITION
        return m_max;}

    // FRIEND FUNCTIONS
    statistician operator + (const statistician& s1, const statistician& s2)
    /* Since defualt constructor sets all private member values to 0,
     If both statisticians are empty, you can return the empty statistician s3 */
    {
        statistician s3;
        s3.m_len = s1.m_len + s2.m_len;
        s3.m_sum = s1.m_sum + s2.m_sum;

        if (s1.m_min < s2.m_min)
        {s3.m_min = s1.m_min;}
        else { s3.m_min = s2.m_min; }

        if (s1.m_max > s2.m_max)
        {s3.m_max = s1.m_max;}
        else { s3.m_max = s2.m_max; }
        return s3; // return s3 post modifications if else block runs
    }

    statistician operator * (double scale, const statistician& s)
    /*     Postcondition: The returned statistician has the same numbers as s,
            but each integer has been multiplied by the scale number.*/
    {
        statistician product; //product of statistician and scale number
        product.m_len = s.m_len;
        product.m_sum = s.m_sum * scale;

        if (scale < 0)
        {
            product.m_min = s.m_max * scale;
            product.m_max = s.m_min * scale;
        }

        else
        {
            product.m_min = s.m_min * scale;
            product.m_max = s.m_max * scale;
        }
        return product;
    }

    // NON-MEMBER functions for the statistician class
    bool operator== (const statistician& s1, const statistician& s2)
    /*     Postcondition: If s1 and s2 both have zero length, the return value is true.
      Furthermore, if the length is larger than zero, s1 and s2 must be the same length, mean, minimum, maximum, and total.*/
    {
        if (s1.length() == 0 && s2.length() == 0) //if s1 and s2 have 0 length, return true
        {return true;}

        return (s1.length() == s2.length());
    }
}

