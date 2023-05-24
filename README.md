# Ark Modules

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
<!-- DEBUG CLASS DEFINITION -->
<!-- **************************************************************************************************** -->

# `Debug` class definition

## Attributes
Do not forget attributes declaration at the beginning of each file where they could be used
```C++
static unsigned int							level; //works from 1 to 4
static u_int64_t							time; // used in time module

//Breakpoint module
static u_int64_t							bp_time;
static unsigned int							bp_count;
static std::map<unsigned int, u_int64_t>	bp_map_time;
static std::map<unsigned int, std::string>	bp_map_info;
```

<!-- **************************************************************************************************** -->
<!-- INFORMATION MODULE -->
<!-- **************************************************************************************************** -->

# Information module

## `Debug::print_msg()` function overloads

**Overload 1** : print a string on `std::cerr`
```C++
static void	print_msg(std::string const& message) throw();
```

**Overload 2** : Print a string on `std::cerr` given its style and color
```C++
static void	print_msg(char const* style, char const* color, std::string const& message) throw();
```

**Overload 3** : Print a string on `std::cerr` and return the last parameter
```C++
template<typename T>
static T	print_msg(std::string const& message, T const val) throw();
```

**Overload 4** : Print a string on `std::cerr` given a style and color and return the last parameter
```C++
template<typename T>
static T	print_msg(char const* style, char const* color, std::string const& message, T const val) throw();
```

<!-- **************************************************************************************************** -->

## `Debug::info()` function prototype
Takes up to 4 parameters to display, the 5th one is default to display the **calling function name** \
Display depends on level set
```C++
template<typename T1, typename T2, typename T3, typename T4>
static void	info(T1 t1, T2 t2, T3 t3, T4 t4, std::string const& str = CALL) throw();
```

<!-- **************************************************************************************************** -->

## `Debug::detail()` function prototype
Will always be used `Debug::detail(FILE, LINE, FUNC);` using preprocessor macros defined \
Display details about the current function
```C++
static void	detail(std::string const& file, int const& line, std::string const& function) throw();
```

<!-- **************************************************************************************************** -->
<!-- TIME MODULE -->
<!-- **************************************************************************************************** -->

# Time module

## `Debug::start_time()` and `Debug::end_time()` function prototypes
`start_time` will set the `time` attribute \
While `end_time` will display the current time elapsed from the most recent `start time` function call \
Display is in miliseconds
```C++
static void	start_time() throw();
static void	end_time() throw();
```

## `Debug::display_milestone()` function prototype
`display_milestone` will display the elapsed time since `start_time` call \
Display the calling function as well thanks to the default argument and macro `CALL`
```C++
static void	display_milestone(std::string const& str = CALL) throw();
```

<!-- **************************************************************************************************** -->
<!-- BREAKPOINT MODULE -->
<!-- **************************************************************************************************** -->

# Breakpoint module
_note : This module has a high chance of being updated in the near future_

## `Debug::bp_start()` and `Debug::bp_end()` function prototypes
`bp_start` will set the `bp_time` and `bp_count` attributes while clearing both bp_maps \
`bp_end` will clear both bp_maps, set `bp_time` and `bp_count` at 0 and display a message giving the number of bp cleared
```C++
static void			bp_start() throw();
static void			bp_end() throw();
```

<!-- **************************************************************************************************** -->

## `Debug::bp()` function prototype
`bp` will set a breakpoint : \
It will use the time elapsed since `bp_start` call and link it to an index and the calling function \
`bp_map_time` will be updated with a new element with index as key and time elapsed since start as value \
`bp_map_info` will be updated with a new element with index as key and calling function info as value \
Both `bp_map_time` and `bp_map_info` will be updated with the same index. \
The function will also display breakpoint informations.
```C++
static void			bp(std::string const& str = CALL) throw();
```

<!-- **************************************************************************************************** -->

## `Debug::display_bp_map()` function prototype
This function will use map iterators to display the full list of breakpoints and informations