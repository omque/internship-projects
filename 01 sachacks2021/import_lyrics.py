# Program/File name: import_lyrics.py
# Author: Omair Qazi
# Date: 2021/02/20
#
# Purpose: Downloads lyrics from Genius using Genius API.
#
# Description: Uses API call to output file of lyrics using Genius API. Largely drawn from https://towardsdatascience.com/song-lyrics-genius-api-dcc2819c29
#
# Date Modified:
# Mod Author: 
# Mod Reason:

# TODO: Specify it so they want to do a specific band. Maybe we can sort by something? Popularity. 
# Stick one band one song and put into array.
# Angelo: Will work on function to clean up arrays and remove punctuation.
#

#Import standard modules
import sys
import os

#Import Constants
import constants

#Import API Keys
import config

#Import Libraries
import lyricsgenius


#Processing Module: Open output file.
def openFile():
    try
        file = open("LYRICS_FILE", "w")
    
    except:
        print("Unable to write to file.")
        sys.exit(0)


#Input Module (API Search Parameters): Skip non songs as part of search paramenters.
def skipNonSongs():
    answer = ""

    while (answer != "y") or (answer != "n"):
        print("Do you want to skip non song items? (Y/N): ")
        
        if (answer == "y" or "Y"):
            return True
        
         elif (answer == "n" or "N"):
            return False     
    
    else: 
        print("Not a valid input.")

  

#Input Module (API Search Parameters): Remove section headers as part of search parameters.
def skipSectionHeaders():
    answer = ""

    while ((answer != "y") or (answer!="n"))
        print("Do you want to remove section headers? (Y/N): ")
        
        if (answer = "y" or "Y")
            return skipSectionHeaders True
        else if (answer = "n" or "N")
            return skipSectionHeaders() False     

    else: 
        print("Not a valid input.")

#Processing Module (API Search Parameters): Get terms to exclude from API search and format for output.
def excludedTerms():
    
    #Take input from user, separate with comma.
    inputTerms = input("Specify which terms you wish to exclude from search. Separate with commas. Press 'Enter' when done.: \n")

    #Split terms separated with comma.
    excludedTerms = inputTerms.split(", ")
    
    #List Comprehension to format each list element with API requirements. Ex: Remix -> "(Remix)"
    finalTerms = ['"({0})"'.format(element) for element in excludedTerms]

	#Removes brackets.
    return(finalTerms)


#Processing Module: Set parameters for Genius API search.
    genius = lg.Genius(
        'Client_Access_Token_Goes_Here', 
        skip_non_songs=True, 
        excluded_terms=["(Remix)", "(Live)"], 
        remove_section_headers=True)


    
#Processing Module: Get lyrics from Genius API
def getLyrics(artistNames, numberOfSongs)