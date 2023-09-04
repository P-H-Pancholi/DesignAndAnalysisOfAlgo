# -*- coding: utf-8 -*-
"""
Created on Tue Oct 29 11:22:31 2019

@author: Phalin Pancholi
"""

def merge(A,p,q,r):
    """Assumes A to be a list and p,q and r an int
       merges the sorted sub-lists into the single list A 
    """
    temp1 = q - p + 1
    temp2 = r - q
    L = []
    R = []
    for i in range(temp1):
        L.append(A[p+i])
    for j in range(temp2):
        R.append(A[q+1+j])
    i = 0
    j = 0
    for k in range(p,r+1):
        if i == temp1:
            while j < temp2:      #L[1....temp1] is placed in A
                A[k] = R[j]       #copies remaining elements of R in A
                j += 1
                k += 1
            break
        if j == temp2:          #R[1...temp2] is placed in A
            while i < temp1:    #copies remaining elements of L in A
                A[k] = L[i]
                i += 1
                k += 1
            break
        if L[i] > R[j]:        #places the smaller element in A
            A[k] = R[j]
            j += 1
        else:
            A[k] = L[i]
            i+= 1
    return A
def mergesort(A,p,r):
    """ Divides A in subsequences , sorts them and then
        merges sorted subsequences into A
    """
    if r > p:
        q = (p + r)//2
        mergesort(A,p,q)
        mergesort(A,q+1,r)
        merge(A,p,q,r)