/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbran <sbran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 18:25:45 by sbran             #+#    #+#             */
/*   Updated: 2015/04/02 17:40:35 by sbran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

# define ABS(X) (X > 0 ? X : -X)

/*
** color
*/
# define C_0 "\033[38;5;0;1m"
# define C_1 "\033[38;5;1;1m"
# define C_2 "\033[38;5;2;1m"
# define C_3 "\033[38;5;3;1m"
# define C_4 "\033[38;5;4;1m"
# define C_5 "\033[38;5;5;1m"
# define C_6 "\033[38;5;6;1m"
# define C_7 "\033[38;5;7;1m"
# define C_8 "\033[38;5;8;1m"
# define C_9 "\033[38;5;9;1m"
# define C_10 "\033[38;5;10;1m"
# define C_11 "\033[38;5;11;1m"
# define C_12 "\033[38;5;12;1m"
# define C_13 "\033[38;5;13;1m"
# define C_14 "\033[38;5;14;1m"
# define C_15 "\033[38;5;15;1m"
# define C_16 "\033[38;5;16;1m"
# define C_17 "\033[38;5;17;1m"
# define C_18 "\033[38;5;18;1m"
# define C_19 "\033[38;5;19;1m"
# define C_20 "\033[38;5;20;1m"
# define C_21 "\033[38;5;21;1m"
# define C_22 "\033[38;5;22;1m"
# define C_23 "\033[38;5;23;1m"
# define C_24 "\033[38;5;24;1m"
# define C_25 "\033[38;5;25;1m"
# define C_26 "\033[38;5;26;1m"
# define C_27 "\033[38;5;27;1m"
# define C_28 "\033[38;5;28;1m"
# define C_29 "\033[38;5;29;1m"
# define C_30 "\033[38;5;30;1m"
# define C_31 "\033[38;5;31;1m"
# define C_32 "\033[38;5;32;1m"
# define C_33 "\033[38;5;33;1m"
# define C_34 "\033[38;5;34;1m"
# define C_35 "\033[38;5;35;1m"
# define C_36 "\033[38;5;36;1m"
# define C_37 "\033[38;5;37;1m"
# define C_38 "\033[38;5;38;1m"
# define C_39 "\033[38;5;39;1m"
# define C_40 "\033[38;5;40;1m"
# define C_41 "\033[38;5;41;1m"
# define C_42 "\033[38;5;42;1m"
# define C_43 "\033[38;5;43;1m"
# define C_44 "\033[38;5;44;1m"
# define C_45 "\033[38;5;45;1m"
# define C_46 "\033[38;5;46;1m"
# define C_47 "\033[38;5;47;1m"
# define C_48 "\033[38;5;48;1m"
# define C_49 "\033[38;5;49;1m"
# define C_50 "\033[38;5;50;1m"
# define C_51 "\033[38;5;51;1m"
# define C_52 "\033[38;5;52;1m"
# define C_53 "\033[38;5;53;1m"
# define C_54 "\033[38;5;54;1m"
# define C_55 "\033[38;5;55;1m"
# define C_56 "\033[38;5;56;1m"
# define C_57 "\033[38;5;57;1m"
# define C_58 "\033[38;5;58;1m"
# define C_59 "\033[38;5;59;1m"
# define C_60 "\033[38;5;60;1m"
# define C_61 "\033[38;5;61;1m"
# define C_62 "\033[38;5;62;1m"
# define C_63 "\033[38;5;63;1m"
# define C_64 "\033[38;5;64;1m"
# define C_65 "\033[38;5;65;1m"
# define C_66 "\033[38;5;66;1m"
# define C_67 "\033[38;5;67;1m"
# define C_68 "\033[38;5;68;1m"
# define C_69 "\033[38;5;69;1m"
# define C_70 "\033[38;5;70;1m"
# define C_71 "\033[38;5;71;1m"
# define C_72 "\033[38;5;72;1m"
# define C_73 "\033[38;5;73;1m"
# define C_74 "\033[38;5;74;1m"
# define C_75 "\033[38;5;75;1m"
# define C_76 "\033[38;5;76;1m"
# define C_77 "\033[38;5;77;1m"
# define C_78 "\033[38;5;78;1m"
# define C_79 "\033[38;5;79;1m"
# define C_80 "\033[38;5;80;1m"
# define C_81 "\033[38;5;81;1m"
# define C_82 "\033[38;5;82;1m"
# define C_83 "\033[38;5;83;1m"
# define C_84 "\033[38;5;84;1m"
# define C_85 "\033[38;5;85;1m"
# define C_86 "\033[38;5;86;1m"
# define C_87 "\033[38;5;87;1m"
# define C_88 "\033[38;5;88;1m"
# define C_89 "\033[38;5;89;1m"
# define C_90 "\033[38;5;90;1m"
# define C_91 "\033[38;5;91;1m"
# define C_92 "\033[38;5;92;1m"
# define C_93 "\033[38;5;93;1m"
# define C_94 "\033[38;5;94;1m"
# define C_95 "\033[38;5;95;1m"
# define C_96 "\033[38;5;96;1m"
# define C_97 "\033[38;5;97;1m"
# define C_98 "\033[38;5;98;1m"
# define C_99 "\033[38;5;99;1m"
# define C_100 "\033[38;5;100;1m"
# define C_101 "\033[38;5;101;1m"
# define C_102 "\033[38;5;102;1m"
# define C_103 "\033[38;5;103;1m"
# define C_104 "\033[38;5;104;1m"
# define C_105 "\033[38;5;105;1m"
# define C_106 "\033[38;5;106;1m"
# define C_107 "\033[38;5;107;1m"
# define C_108 "\033[38;5;108;1m"
# define C_109 "\033[38;5;109;1m"
# define C_110 "\033[38;5;110;1m"
# define C_111 "\033[38;5;111;1m"
# define C_112 "\033[38;5;112;1m"
# define C_113 "\033[38;5;113;1m"
# define C_114 "\033[38;5;114;1m"
# define C_115 "\033[38;5;115;1m"
# define C_116 "\033[38;5;116;1m"
# define C_117 "\033[38;5;117;1m"
# define C_118 "\033[38;5;118;1m"
# define C_119 "\033[38;5;119;1m"
# define C_120 "\033[38;5;120;1m"
# define C_121 "\033[38;5;121;1m"
# define C_122 "\033[38;5;122;1m"
# define C_123 "\033[38;5;123;1m"
# define C_124 "\033[38;5;124;1m"
# define C_125 "\033[38;5;125;1m"
# define C_126 "\033[38;5;126;1m"
# define C_127 "\033[38;5;127;1m"
# define C_128 "\033[38;5;128;1m"
# define C_129 "\033[38;5;129;1m"
# define C_130 "\033[38;5;130;1m"
# define C_131 "\033[38;5;131;1m"
# define C_132 "\033[38;5;132;1m"
# define C_133 "\033[38;5;133;1m"
# define C_134 "\033[38;5;134;1m"
# define C_135 "\033[38;5;135;1m"
# define C_136 "\033[38;5;136;1m"
# define C_137 "\033[38;5;137;1m"
# define C_138 "\033[38;5;138;1m"
# define C_139 "\033[38;5;139;1m"
# define C_140 "\033[38;5;140;1m"
# define C_141 "\033[38;5;141;1m"
# define C_142 "\033[38;5;142;1m"
# define C_143 "\033[38;5;143;1m"
# define C_144 "\033[38;5;144;1m"
# define C_145 "\033[38;5;145;1m"
# define C_146 "\033[38;5;146;1m"
# define C_147 "\033[38;5;147;1m"
# define C_148 "\033[38;5;148;1m"
# define C_149 "\033[38;5;149;1m"
# define C_150 "\033[38;5;150;1m"
# define C_151 "\033[38;5;151;1m"
# define C_152 "\033[38;5;152;1m"
# define C_153 "\033[38;5;153;1m"
# define C_154 "\033[38;5;154;1m"
# define C_155 "\033[38;5;155;1m"
# define C_156 "\033[38;5;156;1m"
# define C_157 "\033[38;5;157;1m"
# define C_158 "\033[38;5;158;1m"
# define C_159 "\033[38;5;159;1m"
# define C_160 "\033[38;5;160;1m"
# define C_161 "\033[38;5;161;1m"
# define C_162 "\033[38;5;162;1m"
# define C_163 "\033[38;5;163;1m"
# define C_164 "\033[38;5;164;1m"
# define C_165 "\033[38;5;165;1m"
# define C_166 "\033[38;5;166;1m"
# define C_167 "\033[38;5;167;1m"
# define C_168 "\033[38;5;168;1m"
# define C_169 "\033[38;5;169;1m"
# define C_170 "\033[38;5;170;1m"
# define C_171 "\033[38;5;171;1m"
# define C_172 "\033[38;5;172;1m"
# define C_173 "\033[38;5;173;1m"
# define C_174 "\033[38;5;174;1m"
# define C_175 "\033[38;5;175;1m"
# define C_176 "\033[38;5;176;1m"
# define C_177 "\033[38;5;177;1m"
# define C_178 "\033[38;5;178;1m"
# define C_179 "\033[38;5;179;1m"
# define C_180 "\033[38;5;180;1m"
# define C_181 "\033[38;5;181;1m"
# define C_182 "\033[38;5;182;1m"
# define C_183 "\033[38;5;183;1m"
# define C_184 "\033[38;5;184;1m"
# define C_185 "\033[38;5;185;1m"
# define C_186 "\033[38;5;186;1m"
# define C_187 "\033[38;5;187;1m"
# define C_188 "\033[38;5;188;1m"
# define C_189 "\033[38;5;189;1m"
# define C_190 "\033[38;5;190;1m"
# define C_191 "\033[38;5;191;1m"
# define C_192 "\033[38;5;192;1m"
# define C_193 "\033[38;5;193;1m"
# define C_194 "\033[38;5;194;1m"
# define C_195 "\033[38;5;195;1m"
# define C_196 "\033[38;5;196;1m"
# define C_197 "\033[38;5;197;1m"
# define C_198 "\033[38;5;198;1m"
# define C_199 "\033[38;5;199;1m"
# define C_200 "\033[38;5;200;1m"
# define C_201 "\033[38;5;201;1m"
# define C_202 "\033[38;5;202;1m"
# define C_203 "\033[38;5;203;1m"
# define C_204 "\033[38;5;204;1m"
# define C_205 "\033[38;5;205;1m"
# define C_206 "\033[38;5;206;1m"
# define C_207 "\033[38;5;207;1m"
# define C_208 "\033[38;5;208;1m"
# define C_209 "\033[38;5;209;1m"
# define C_210 "\033[38;5;210;1m"
# define C_211 "\033[38;5;211;1m"
# define C_212 "\033[38;5;212;1m"
# define C_213 "\033[38;5;213;1m"
# define C_214 "\033[38;5;214;1m"
# define C_215 "\033[38;5;215;1m"
# define C_216 "\033[38;5;216;1m"
# define C_217 "\033[38;5;217;1m"
# define C_218 "\033[38;5;218;1m"
# define C_219 "\033[38;5;219;1m"
# define C_220 "\033[38;5;220;1m"
# define C_221 "\033[38;5;221;1m"
# define C_222 "\033[38;5;222;1m"
# define C_223 "\033[38;5;223;1m"
# define C_224 "\033[38;5;224;1m"
# define C_225 "\033[38;5;225;1m"
# define C_226 "\033[38;5;226;1m"
# define C_227 "\033[38;5;227;1m"
# define C_228 "\033[38;5;228;1m"
# define C_229 "\033[38;5;229;1m"
# define C_230 "\033[38;5;230;1m"
# define C_231 "\033[38;5;231;1m"
# define C_232 "\033[38;5;232;1m"
# define C_233 "\033[38;5;233;1m"
# define C_234 "\033[38;5;234;1m"
# define C_235 "\033[38;5;235;1m"
# define C_236 "\033[38;5;236;1m"
# define C_237 "\033[38;5;237;1m"
# define C_238 "\033[38;5;238;1m"
# define C_239 "\033[38;5;239;1m"
# define C_240 "\033[38;5;240;1m"
# define C_241 "\033[38;5;241;1m"
# define C_242 "\033[38;5;242;1m"
# define C_243 "\033[38;5;243;1m"
# define C_244 "\033[38;5;244;1m"
# define C_245 "\033[38;5;245;1m"
# define C_246 "\033[38;5;246;1m"
# define C_247 "\033[38;5;247;1m"
# define C_248 "\033[38;5;248;1m"
# define C_249 "\033[38;5;249;1m"
# define C_250 "\033[38;5;250;1m"
# define C_251 "\033[38;5;251;1m"
# define C_252 "\033[38;5;252;1m"
# define C_253 "\033[38;5;253;1m"
# define C_254 "\033[38;5;254;1m"
# define C_255 "\033[38;5;255;1m"

# define C_BLACK "\033[30m"
# define C_RED "\033[31m"
# define C_GREEN "\033[32m"
# define C_YELLOW "\033[33m"
# define C_BLUE "\033[34m"
# define C_PURPLE "\033[35m"
# define C_CYAN "\033[36m"
# define C_WHITE "\033[37m"

# define C_END "\033[0m"
/*
** color bold
*/
# define C_BLACK_B "\033[30;1m"
# define C_RED_B "\033[31;1m"
# define C_GREEN_B "\033[32;1m"
# define C_YELLOW_B "\033[33;1m"
# define C_BLUE_B "\033[34;1m"
# define C_PURPLE_B "\033[35;1m"
# define C_CYAN_B "\033[36;1m"
# define C_WHITE_B "\033[37;1m"

/*
** color underline
*/
# define C_BLACK_U "\033[30;4m"
# define C_RED_U "\033[31;4m"
# define C_GREEN_U "\033[32;4m"
# define C_YELLOW_U "\033[33;4m"
# define C_BLUE_U "\033[34;4m"
# define C_PURPLE_U "\033[35;4m"
# define C_CYAN_U "\033[36;4m"
# define C_WHITE_U "\033[37;4m"

/*
** color background
*/
# define C_BLACK_BK "\033[40m"
# define C_RED_BK "\033[41m"
# define C_GREEN_BK "\033[42m"
# define C_YELLOW_BK "\033[43m"
# define C_ULUE_BK "\033[44m"
# define C_PURPLE_BK "\033[45m"
# define C_CYAN_BK "\033[46m"
# define C_WHITE_BK "\033[47m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_flags
{
	char			flag;
	int				(*p)(va_list ap);
}					t_flags;

extern t_flags		g_flags[];

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr_c(char *color, char *str, char *end);
int					ft_putendl_c(char *color, char *str, char *end);

char				*ft_itoa(int n);

char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);

void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_atoi(char const *str);

int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char*s2);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
int					ft_strlen(const char *s);

int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);

int					ft_atoi(char const *str);
double				ft_atof(char const *str);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_printf(const char *str, ...);
int					ft_print_s(va_list ap);
int					ft_print_d(va_list ap);
int					ft_print_u(va_list ap);
int					ft_print_c(va_list ap);
int					ft_print_o(va_list ap);
int					ft_print_x(va_list ap);
int					ft_print_p(va_list ap);
int					ft_print_f(va_list ap);

void				ft_putnbr_u(unsigned int n);

double				ft_sqrt(int nb);

#endif
