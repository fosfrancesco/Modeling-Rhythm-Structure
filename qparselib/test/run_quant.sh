#!/bin/bash -v

#
# $1 = MIDI file (input)
# $2 = Grammar file (input)
# $3 = MEI file (output)
# $4 = bar duration
# $5 = bar metric denominator
# $6 time signature

# REPLACE THE FOLLOWING DEFINITION DEPENDING ON YOUR ENVIRONMENT

# Where is the Qparse corpus project?
declare PATH_TO_CORPUS=./test/test_suite

# Where is the grammars files folder
declare PATH_TO_GRAMMARS=./test/test_suite

# Where is the MEI folder 
declare PATH_TO_MEI=~/Documents/workspace/scorelib/app/media

echo Run the quantization + MEI score production for score $1 with grammar $2. 
echo Result will be found in $PATH_TO_MEI/$3
echo

./build/squant -v 4 -penalty -a $PATH_TO_GRAMMARS/$2 -i $PATH_TO_CORPUS/$1 \
       -config ./params.ini -norest -barsec $4 -barbeat $5 -ts $6 \
       -output $PATH_TO_MEI/$3
