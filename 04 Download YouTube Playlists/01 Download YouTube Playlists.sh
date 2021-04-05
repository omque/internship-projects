#!/bin/bash
#
# Name of the Script: Download YouTube Playlists
# Author: Omair Qazi
# Date: 2021/01/03
#
# Purpose: Downloads YouTube playlists as a part of a cron-job.
#
# Description: Uses YouTube-DL to download new videos from a batch of playlists. Requires archive to keep up to date.
#
# Date Modified:
# Mod Author: 
# Mod Reason:

# Set PATH for crontab
PATH=/usr/local/sbin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin

clear

#Define Variables/Constants
#Directories
YOUTUBE_FOLDER_DIRECTORY=/Volumes/DexterStore/Saved\ Videos/Saved\ YouTube\ Videos
ARCHIVE_FILE=/Volumes/DexterStore/Saved\ Videos/Saved\ YouTube\ Videos/00\ Script\ Data/01\ Archive\ Status.txt
ERROR_MESSAGE=/Users/Omair/Desktop/ERROR_YouTubeCronJob.txt
PLAYLIST_INDEX=/Volumes/DexterStore/Saved\ Videos/Saved\ YouTube\ Videos/00\ Script\ Data/02\ Playlist\ Index.txt
OUTPUT_NULL=/dev/null

#Use only for debugging
#OUTPUT_TEXT=/Users/Omair/Desktop/Output.txt

#Program Start
echo -e "Beginning backup of YouTube playlists.\n"

#Update Homebrew
echo -e "Updating Homebrew..."
{ brew update && brew upgrade && brew doctor; } > /dev/null
echo -e "Homebrew Updated.\n"

#Open Saved YouTube Video directory
cd "$YOUTUBE_FOLDER_DIRECTORY"

#Check if Archive Text.txt is present.
if [ -f "$ARCHIVE_FILE" ]
    then
        echo -e "Found archive record.\n"
        
        #Check for playlist index.
        if [ -f "$PLAYLIST_INDEX" ]
            then
                echo -e "Found playlist index.\n"
                echo -e "Beginning backup...\n"

                #Begin backup of YouTube playlists.
                youtube-dl --batch-file "$PLAYLIST_INDEX" --ignore-errors --download-archive "$ARCHIVE_FILE" -o '%(playlist)s/%(playlist_index)03d - %(title)s.%(ext)s' >> "$OUTPUT_NULL"
                
                #Backup complete.
                echo -e "\nBackup complete.\n"
        else
            echo -e "Unable to find playlist index, aborting backup." >> $ERROR_MESSAGE
        fi

    else
        echo -e "Unable to find archive record, aborting backup.\n" >> $ERROR_MESSAGE
fi