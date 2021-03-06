/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agesp <agesp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 13:20:43 by agesp             #+#    #+#             */
/*   Updated: 2020/07/20 11:26:12 by agesp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "libft.h"
# include "ft_printf.h"
# include <stdint.h>
# include <math.h>
# include <limits.h>


#ifndef __APPLE__
# include <byteswap.h>
#elif defined(__APPLE__)
#include <libkern/OSByteOrder.h>
#define __bswap_16(x) OSSwapInt16(x)
#define __bswap_32(x) OSSwapInt32(x)
#define __bswap_64(x) OSSwapInt64(x)
#endif
# define FORBID_FLAGS 1

# define CONSOLE_FLAG 2
# define REVERSE_FLAG 4
# define QUIET_FLAG 8
# define STRING_FLAG 16
# define ENCODE_FLAG 32
# define DECODE_FLAG 64
# define INPUT_FLAG 128
# define OUTPUT_FLAG 256


# define BUFFER_SIZE 5

typedef struct s_bytes
{
    char *bytes;
    uint64_t nb_bytes;
}               t_bytes;

typedef struct s_filename
{
    char *name;
    t_bytes *output;
    struct s_filename *next;
}               t_filename;

typedef struct s_console
{
    char *msg;
    t_bytes *output;
    struct s_console *next;
}              t_console; 

typedef struct s_string
{
    char *str;
    t_bytes *output;
    struct s_string *next;
}               t_string;

typedef struct s_input
{
    int8_t alg;
    t_bytes *(*alg_func)(t_bytes);
    int8_t flags;
    t_console *console;
    t_string *strings;
    t_filename *filenames;
}               t_input;

typedef struct s_md5
{
    int8_t round;
    uint32_t tmp[4];
    uint32_t func;
    uint64_t block_index;
    uint64_t nb_blocks;
}               t_md5;

typedef struct s_sha256
{
    int8_t round;
    uint32_t tmp[4];
    uint32_t func;
    uint64_t block_index;
    uint64_t nb_blocks;
}               t_sha256;

/*
Parsing
*/
void parser(int argc, char **argv, t_input *input);

void ssl_exit(char *msg, t_input *input, int8_t code);

void handle_files(t_input *input);
void print_files(t_filename *head);

void add_to_console(t_bytes *output, t_input *input, char *msg);
void print_console(t_console *head);
void handle_noninteractive(t_input *input);
void handle_interactive(t_input *input);

void add_to_string(t_bytes *output, t_input *input, char *msg);
void print_string(t_string *head);

/*
Crypto
*/
t_bytes *ft_md5(t_bytes data);
t_bytes *ft_sha256(t_bytes data);
uint32_t rotl32 (uint32_t value, unsigned int count);
uint32_t rotr32 (uint32_t value, unsigned int count);
void print_b(void *s, uint64_t len);
char *pad_msg(t_bytes data);

/*
Cypher
*/
t_bytes *ft_base64(t_bytes data);


#endif