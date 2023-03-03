# The first project of the core curriculum - libft
Libft is the first project of the core curriculum of the 42 network. The project is about coding your own C library. It contains various general purpose functions.

## [Testernette for libft](https://github.com/lspohle/PRIVATE_testernette_42) might be interisting for you if you're doing the core at the moment.

## Part 1: libc functions
    int     ft_isalpha(int c);
    int     ft_isdigit(int c);
    int     ft_isalnum(int c);
    int     ft_isascii(int c);
    int     ft_isprint(int c);
    size_t  ft_strlen(const char *str);
    void    *ft_memset(void *b, int c, size_t len);
    void    ft_bzero(void *s, size_t n);
    void    *ft_memcpy(void *dst, const void *src, size_t n);
    void    *ft_memmove(void *dst, const void *src, size_t len);
    size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
    size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
    int     ft_toupper(int c);
    int     ft_tolower(int c);
    char    *ft_strchr(const char *s, int c);
    char    *ft_strrchr(const char *s, int c);
    int     ft_strncmp(const char *s1, const char *s2, size_t n);
    void    *ft_memchr(const void *s, int c, size_t n);
    int     ft_memcmp(const void *s1, const void *s2, size_t n);
    char    *ft_strnstr(const char *s1, const char *s2, size_t len);
    int     ft_atoi(const char *str);
    void    *ft_calloc(size_t count, size_t size);
    char    *ft_strdup(const char *src);
    
## Part 2: additional functions
    char    *ft_substr(const char *s, unsigned int start, size_t len);
    char	*ft_strjoin(const char *s1, const char *s2);
    char	*ft_strjoin.c
    char	*ft_strtrim(const char *s1, const char *set);
    char	**ft_split(const char *str, char c);
    char	*ft_itoa(int n);
    char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
    void	ft_striteri(char *s, void (*f)(unsigned int, char *));
    void	ft_putchar_fd(char c, int fd);
    void	ft_putstr_fd(char *c, int fd);
    void	ft_putendl_fd(char *c, int fd);
    void	ft_putnbr_fd(int n, int fd);
    
## Part 3: bonus functions
    t_list  *ft_lstnew(void *content);
    void    ft_lstadd_front(t_list **lst, t_list *new);
    int     ft_lstsize(t_list *lst);
    t_list  *ft_lstlast(t_list *lst);
    void    ft_lstadd_back(t_list **lst, t_list *new);
