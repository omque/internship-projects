#! /usr/bin/env python3
# hashtagcount.py - Quickly check how many hashtags you have before posting to Instagram. Supply as command line argument in "". 

import sys

#Check to make sure hashtags are supplied as command line argument.
if len(sys.argv) < 2:
	print("Please enter some hashtags to count. Use a command line argument.")
	sys.exit()

#Import hashtags into dictionary.
dictionary = str(sys.argv[1:])

#Count how many # are in dictionary.
count = dictionary.count("#")

#Print how many hashtags you have.
print("----")
print("You have {} hashtags.".format(count))

#Print how many hashtags you have left.
print("----")
print("{} hashtags left.".format(30 - count))
print("----")