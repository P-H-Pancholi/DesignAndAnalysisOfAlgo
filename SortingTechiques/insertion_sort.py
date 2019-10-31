# -*- coding: utf-8 -*-
"""
Created on Mon Sep  9 14:24:16 2019

@author: Phalin Pancholi
"""

def insertionsort(l):
    """ Sorts list l, using an incremental approach "Insertion Sort"
    """
    for j in range(1, len(l)):
        i = j - 1
        key = l[j]   #l[1...j] is sorted and contains same element as previous. 
        while i >=  0 and l[i] > key:
            l[i+1] = l[i]
            i = i - 1
        l[i+1] = key
        print(l)

it = int(input())
t_list = []
while it > 0:
    temp = int(input())
    t_list.append(temp)
    it -= 1
insertionsort(t_list) #prints list after every swapping