# ft_printf
Recreating the printf function in C's stdio library with most of its functionality.

<h3>Description</h3>
<p>The function ft_printf produces output according to a format. It writes output to stdout.</p>

<h3>Return values</h3>
<p>Upon successful return, this function returns the number of characters printed (excluding the null byte used to end output to strings). If an output error is encountered, a negative value is returned.</p>
<h3>How the function is prototyped</h3>
<code>int ft_printf(const char* format, ...)</code>
<p>Where <code>...</code> is the variable argument list of the respective matching conversion specifiers parameters.</p>

<h3>Syntax of a conversion specifier</h3>

<code>%[parameter][flags][width][.precision][length]type</code>

<h3>Handled Conversion specifiers</h3>

|Character | Description|
|----------|------------|
|<code>%</code> | literal % character.|
|<code>c</code> | a specified char.|
|<code>s</code> | string, a sequence of characters preceded of a '\0' char.|
|<code>p</code> | the address of a variable in hexadecimal form|
|<code>d,i</code> | int as a signed decimal number.|
|<code>o</code> | unsigned int in octal.|
|<code>u</code> | decimal unsigned int.|
|<code>x</code> | unsigned int as a hexadecimal number (lowercase).|
|<code>X</code> | unsigned int as a hexadecimal number (UPPERCASE).|
|<code>f</code> | double in normal (fixed-point) notation.|

<h3>Handled Flags</h3>

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
