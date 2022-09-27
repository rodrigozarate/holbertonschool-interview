#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Mon Sep 26 20:15:15 2022

@author: Rodrigo Zárate Algecira
"""

def rotate_2d_matrix(matrix):
    """ Rotate matrix 90 degres clockwise """
    allmat = []
    for i in range(len(matrix)):
        newmat = []
        for j in range(len(matrix)):
            newmat.insert(0, matrix[j][i])
        allmat.append(newmat)
    
    for i in range(len(matrix)):
        matrix[i] = allmat[i]
        
