# personal_modules

#### All modules are libraries you have to compile through their own Makefile
#### All modules can use text colors and text styles, defined below

```C++
//colors
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

//styles
# define BOLD		"\033[1m"
# define FAINT		"\033[2m"
# define ITALIC		"\033[3m"
# define UNDERLINE	"\033[4m"

# define ERASE		"\033[2K\r"
# define RESET		"\033[0m"
```

m1 = debug WiP
m2 = .


# m1 prototypes

## `ft_print_msg` function overloads

```C++
// Overload 1 : print a string on `std::cerr`
void	ft_print_msg(std::string const& message);

// Overload 2 : Print a string on `std::cerr` given its style and color
void	ft_print_msg(char const* style, char const* color, std::string const& message);

// Overload 3 : Print a string on `std::cerr` and return the last parameter
template<typename T>
T	ft_print_msg(std::string const& message, T const val);

// Overload 4 : Print a string on `std::cerr` given a style and color and return the last parameter
template<typename T>
T	ft_print_msg(char const* style, char const* color, std::string const& message, T const val);
```

## `Debug` class definition

Has `static unsigned int level` as attribute that works from 1 to 4

### `Debug::info` function prototype
Takes up to 4 parameters to display, the 5th one is default to display the **calling function name**
Display depends on level set
```C++
template<typename T1, typename T2, typename T3, typename T4>
static void	info(T1 t1, T2 t2, T3 t3, T4 t4, std::string const& str = __builtin_FUNCTION()) throw();
```
