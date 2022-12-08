# libft - complete
The libft complete combines [libft](https://github.com/pedro-pn/libft), [GNL](https://github.com/pedro-pn/GNL) and [ft_printf](https://github.com/pedro-pn/ft_printf) in one library, which is allowed in some projects of 42 school.

# Usage

### Requirements

libft complete requires gcc compiler and standard c libraries.

### Compilation

Clone this repository in your project folder:

	$> git clone https://github.com/pedro-pn/libft_complete

Run `make` command in the repository folder:

	$> make

Make supports the following rules:

> - `make`/`make all` - compile the library;
> - `make clean` - remove all objects (`.o`) files;
> - `make fclean` - perform `clean` and also remove the library (`libft.a`);
> - `make re` - perform `fclean` and `all` recompiling the library.

### Use

Once compiled, the library `libft.a` is generated in the repository folder. You need to include the header `libft.h` in your project to be able to use libft functions:

```c
#include "libft.h"
```

To compile libft complete with your project, use the flag `-L. -lft`. The header file `libft.h` is located in `include/` and must be given to compiler with the flag `-I`. Example:

	$> gcc myproject.c -I include/ -L. -lft





