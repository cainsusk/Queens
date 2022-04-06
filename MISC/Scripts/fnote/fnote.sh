#!/bin/bash

school_root="$HOME/.queens/"

opt=$1

case $opt in

        "-c") # find classes

                miscs=`find $school_root -name 'misc'`
                classes=`ls $miscs | grep -E "\.mknote" | cut -d '.' -f 1`


                if [ -z $2 ] # if no class given, print options
                then
                        out=$classes

                else
                        in=$2
                        # check if given class: $in is one of the set up classes (denoted by a .mknote file)
                        if grep -q "$in" <<< "$classes"
                        then
                                # get the path for the given class: $in
                                cpath=`find $school_root -name "$in"`
                                #    list all notes                remove extra stuff printed by ls        add bar bewtween note name and number
                                notes=`ls $cpath/Notes/* | grep -v -E "^/" | grep -v -E "^$" | tr ' ' '\n' | tr '_' '|' | sort`
                                # print with pretty formatting
                                out="|=== Notes ===|\n$notes\n---------------"
                        else
                                # error message
                                out="fnote: this is not a class, please choose from the list which can be seen with\nfnote -c">&2
                        fi
                fi
        ;;
esac


printf "$out\n"

