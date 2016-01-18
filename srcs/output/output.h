#ifndef OUTPUT_H
# define OUTPUT_H

void	bufferize(const char *str, size_t len, char flush);
void	bufferize_char(const char c, size_t len, char flush);

typedef enum	s_instruction
{
	NONE = 0,
	RESET
}				e_instruction;

size_t	get_total(e_instruction instruction);

#endif
