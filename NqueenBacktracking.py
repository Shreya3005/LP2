# -*- coding: utf-8 -*-
"""
Created on Sat May 14 20:40:05 2022

@author: shree
"""

# N-Queen Problem using backtracking
global N
N = int(input('Enter value of N-'))

def printSolution(board):
 print("NQueen solution-")
 for i in range(N):
  for j in range(N):
   print (board[i][j], end = " ")
  print()

# A utility function to check if a queen can be placed on board[row][col]
def isSafe(board, row, col):

 # Check this row on left side
 for i in range(col):
  if board[row][i] == 1:
   return False

 # Check upper diagonal on left side
 for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
  if board[i][j] == 1:
   return False

 # Check lower diagonal on left side
 for i, j in zip(range(row, N, 1), range(col, -1, -1)):
  if board[i][j] == 1:
   return False
 return True



def solveNQUtil(board, col):
   if col >= N:
    return True
   for i in range(N):
    if isSafe(board, i, col):
     board[i][col] = 1
     if solveNQUtil(board, col + 1) == True:
      return True
     board[i][col] = 0
   return False


def solveNQ():
 board = [[0 for i in range(N)]
 for j in range(N)]
 if solveNQUtil(board, 0) == False:
  print ("Solution does not exist for N = {}".format(N))
  return False
 printSolution(board)
 return True

solveNQ()
