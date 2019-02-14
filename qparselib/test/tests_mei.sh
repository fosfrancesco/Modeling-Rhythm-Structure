#!/bin/bash 

# Mozart duettino:
./test/run_quant.sh mozart_duettino/mozart_duettino_midi_quant.mid\
         mozart_duettino/mozart_duettino_grammar.txt \
         mozart_duettino.mei \
         2.0 2   \
         "4/4"
 

# Kulhau sonatina
./test/run_quant.sh kuhlau_sonatina/kuhlau_sonatina_midi_quant.mid \
         kuhlau_sonatina/kuhlau_sonatina_grammar.txt \
         kuhlau_sonatina.mei \
         4.0 2 \
         "4/4"

# Beethoven trio
./test/run_quant.sh beethoven_trio/beethoven_trio_midi_quant.mid \
         beethoven_trio/beethoven_trio_grammar.txt  \
         beethoven_trio.mei \
         2.0 2 \
         "2/4"

# Romance Mendelssohn
./test/run_quant.sh mendelssohn_romance/mendelssohn_romance_midi_quant.mid \
         mendelssohn_romance/mendelssohn_romance_grammar.txt  \
         mendelssohn_romance.mei \
         4.0 2 \
         "4/4"

# Spiritual
./test/run_quant.sh spiritual/spiritual_midi_quant.mid \
         spiritual/spiritual_grammar.txt  \
         spiritual.mei \
         2.0 2 \
         "2/4"

# Wolf chanson
./test/run_quant.sh wolf_chanson/wolf_chanson_midi_quant.mid \
         wolf_chanson/wolf_chanson_grammar.txt  \
         wolf_chanson.mei \
         4.0 2 \
         "4/4"
 