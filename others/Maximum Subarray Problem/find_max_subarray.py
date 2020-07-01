# -*- coding: utf-8 -*-
"""
Created on Wed Nov  6 09:30:46 2019

@author: Phalin Pancholi
"""

def maximum_crossing_subarray(A,low,mid,high):
    """ A is a list it returns a contiguous subarray A[i....j]
        such that low <= i <= mid <= j <= high such that it has maximum sum
    """
    left_sum = A[mid]
    left_max = mid
    i = mid
    Sum = 0
    while(i >= low):
        Sum = Sum + A[i]
        if Sum > left_sum:
            left_sum = Sum
            left_max = i
        i -= 1
    right_sum = A[mid+1]
    right_max = mid + 1
    Sum = 0
    for j in range(mid+1,high):
        Sum = Sum + A[j]
        if Sum > right_sum:
            right_sum = Sum
            right_max = j
    return (left_max,right_max,left_sum + right_sum)

def maximum_subarray(A,low,high):
    """ Returns the subarray of A having maximum sum
    """
    if low == high:
        return(low,high,A[low])                                                         #basecase
    else:
        mid = (low + high)//2                                                           #dividestep
        (left_high,left_low,left_sum) = maximum_subarray(A,low,mid)                     #conquer
        (right_high,right_low,right_sum) = maximum_subarray(A,mid + 1, high)            #    step
        (cross_high,cross_low,cross_sum) = maximum_crossing_subarray(A,low,mid,high)    # 41-50 combine
        if(left_sum >= right_sum and left_sum >= cross_sum):                            
            print(left_high,left_low,left_sum)
            return (left_high,left_low,left_sum)
        elif(right_sum >= left_sum and right_sum >= cross_sum):
            print(right_high,right_low,right_sum)
            return (right_high,right_low,right_sum)
        else:
            print(cross_high,cross_low,cross_sum)
            return (cross_high,cross_low,cross_sum)
            