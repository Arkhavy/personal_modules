# personal_modules

All modules are libraries you have to compile through their own Makefile \
All modules can use text colors and text styles, defined below as preprocessor macros \
All modules can use debug, defined below as preprocessor macros \
Debug module will ALWAYS display on `std::cerr` unless specified otherwise
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

//debug
#define LINE		__LINE__
#define FILE		__FILE__
#define FUNC		__PRETTY_FUNCTION__
#define CALL		__builtin_FUNCTION()
```

<!-- **************************************************************************************************** -->

# `Debug` class definition

## Attributes
Do not forget attributes declaration at the beginning of each file where they could be used
```C++
static unsigned int	level; //works from 1 to 4
static u_int64_t	time;
```

<!-- **************************************************************************************************** -->

## `Debug::print_msg` function overloads

**Overload 1** : print a string on `std::cerr`
```C++
static void	ft_print_msg(std::string const& message) throw();
```

**Overload 2** : Print a string on `std::cerr` given its style and color
```C++
static void	ft_print_msg(char const* style, char const* color, std::string const& message) throw();
```

**Overload 3** : Print a string on `std::cerr` and return the last parameter
```C++
template<typename T>
static T	ft_print_msg(std::string const& message, T const val) throw();
```

**Overload 4** : Print a string on `std::cerr` given a style and color and return the last parameter
```C++
template<typename T>
static T	ft_print_msg(char const* style, char const* color, std::string const& message, T const val) throw();
```

<!-- **************************************************************************************************** -->

## `Debug::info` function prototype
Takes up to 4 parameters to display, the 5th one is default to display the **calling function name** \
Display depends on level set
```C++
template<typename T1, typename T2, typename T3, typename T4>
static void	info(T1 t1, T2 t2, T3 t3, T4 t4, std::string const& str = CALL) throw();
```

<!-- **************************************************************************************************** -->

## `Debug::detail` function prototype
Will always be used `Debug::detail(FILE, LINE, FUNC);` using preprocessor macros defined \
Display details about the current function
```C++
static void	detail(std::string const& file, int const& line, std::string const& function) throw();
```

<!-- **************************************************************************************************** -->

## `Debug::start_time` and `Debug::end_time` function prototypes
`start_time` will set the `time` attribute \
While `end_time` will display the current time elapsed from the most recent `start time` function call \
Display is in miliseconds
```C++
static void	start_time() throw();
static void	end_time() throw();
```

BREAKPOINT MODULE IS WIP