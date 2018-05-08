# Logger

Basic C++ Logger, nothing more, nothing less. It's not the prettiest solution but it works.

## Instructions

Hopefully, this simple explanation will make life easier for anybody who decided to use this code and don't want to spend too much time into looking of how this Logger works.

### Log_WriteIn

Function Log_WriteIn adds to log file string of text and finishes it with line break. Two parameters *std::string text* and *std::string filename* are used for your text and name of your log file.

```
Log_WriteIn("Hello World!", "debug.log");
```

### Log_Open and Log_Close

Function Log_Open requires only one parameter and that is name of your log file. Function Log_Close closes it.

```
Log_Open("debug.log");
Log_Close();
```

### Log_Write

Function Log_Write does exactly the same thing as Log_WriteIn, it logs text but in order to do that it also requires to have log file accessible. It uses only parameter for string.
```
Log_Open("debug.log");
Log_Write("Hello World!");
Log_Close();
```

### Logging errors

Error(x) outputs the file path and line in code where something went wrong.
```
HRESULT hr = something();
	if (hr != S_OK)
	{
		Log_Open("debug.log");
		Error(hr);
		Log_Write("We have problem here.");
		Log_Close();
	}
```


Output line in log file looks somewhat like this:

```
Logging: Func: hr in file: main.cpp on line 27
```

### Optional functions

Log_Init and Log_End are completely optional, they don't do much except they add some text in the beginning and at the end of log file. Log_Init function also clears anything that was stored in log file before, so keep that in mind. I found this to be useful, however they can be both simply replaced by Log_WriteIn if needed.
