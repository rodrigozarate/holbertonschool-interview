#ifndef REGEX_H
#define REGEX_H

int regexPiece(char const *str, char const *pattern,
		     const char **str_end, const char **pttrn_end);
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
