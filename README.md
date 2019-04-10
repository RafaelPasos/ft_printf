# ft_printf
Recreating the printf function in C's stdio library with most of its functionality.

<h2>How the function is prototyped</h2>
<code>int printf(const char* format, ...)</code>

Syntax of a conversion specifier
----------------------------
<code>%[parameter][flags][width][.precision][length]type</code>

Handled Conversion specifiers
-------------------
|Character | Description|
|----------|------------|
|<code>%</code> | literal % character.|
|<code>d,i</code> | int as a signed decimal number.|
|<code>o</code> | unsigned int in octal.|
|<code>u</code> | decimal unsigned int.|
|<code>x</code> | unsigned int as a hexadecimal number (lowercase).|
|<code>X</code> | unsigned int as a hexadecimal number (UPPERCASE).|
|<code>f</code> | double in normal (fixed-point) notation.|

Handled Flags
------------
|Character | Description|
|----------|------------|
|<code>h</code> | For integer types, expects an int-sized integer argument which was promoted from a short.|
|<code>hh</code> | For integer types, expects an int-sized integer argument which was promoted from a char.|
|<code>l</code> | For integer types, expects a long-sized integer argument. No effects on floating point vars.|
|<code>ll</code> | For integer types, expects a long long-sized integer argument.|
|<code>L</code> | For floating point types, causes printf to expect a long double argument.|
|<code>#</code> | Prints alternate form.|
|<code>0</code> | When the 'width' option is specified, prepends zeros for numeric types. (The default prepends spaces)|
|<code> </code> | Prepends a space for positive signed-numeric types. (Overwritten by '+' flag)|
|<code>-</code> | Left-align the output of this placeholder.|
|<code>+</code> | Prepends a plus for positive signed-numeric types.|
