# Short options
A single `-` followed by one or multiples letters, where each letter is an
option.


# Long options
Two `-` as `--` followed by a single word (1 - ... letters), where the word
is the option.


# Options switch
The short option `-o` is the option switch. If this option is not included
in a short-options chain, it will be treated as an option switch. The following
word will be interpreted as an long option.


# Options arguments
If one of the following sequence is found during parsing:
`<options> <spaces|tabs> <words...>`
`<options> [spaces|tabs] [=|:] [spaces|tabs] <words...>`
Then `words` will be used as an option arguments, until a new option
(short or long) is found in `words`.


# Std options
The following options are standard and produces:
- An output in ERROR output
- Programm exit with status code `0` (success)

`--help`   : Produce a help message
`--version`: Produce a version message