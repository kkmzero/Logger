# Logger

Abandoned implementation of basic C++ logger for MSVC.

## Instructions

Hopefully, these simple instructions will make life easier for anybody who decided to use this code and don't want to spend too much time looking into details of how this Logger works.

### Log_WriteIn

Function Log_WriteIn adds to log file string of text plus a line break. Two parameters *std::string text* and *std::string filename* are used for your text and name of your log file.

```
Log_WriteIn("Hello World!", "debug.log");
```

### Log_Open and Log_Close

Function Log_Open requires only one parameter - name of your log file. Function Log_Close closes the filehandle.

```
Log_Open("debug.log");
Log_Close();
```

### Log_Write

Function Log_Write does exactly the same thing as Log_WriteIn, it logs text but in order to do that it also requires to have log file accessible with opened filehandle. It uses only one parameter for text string.
```
Log_Open("debug.log");
Log_Write("Hello World!");
Log_Close();
```

### Logging errors

Error(x) outputs the file path and line in code where something went wrong.
```
HRESULT hr = someFunction();
	if (hr != S_OK) {
		Log_Open("debug.log");
		Error(hr);
		Log_Write("Advanced description (if needed).");
		Log_Close();
	}
```


Output line in log file then looks somewhat like this:

```
Logging: Func: hr in file: main.cpp on line 27
Advanced description (if needed).
```

### Logging errors with macro

To make debugging easier, you can use macro similar to this one:
```
#define CHECK_RESULT(val)\
	if(val != S_OK){\
		Log_Open("debug.log");\
		Error(val);\
		Log_Close();\
		__debugbreak();\
	}
```
```
HRESULT hr = someFunction();
CHECK_RESULT(hr);
```

### Optional functions

Log_Init and Log_End are completely optional, they don't do much except they add some text in the beginning and at the end of log file. Log_Init function also clears anything that was stored in log file before. These functions can be both simply replaced by Log_WriteIn function if needed.
