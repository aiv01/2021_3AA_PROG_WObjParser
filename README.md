# Wavefront OBJ Parser

Mesh parser for Wavefront OBJ format.

## Useful API for reading files:
```
FILE* file = fopen("resources/quad.obj", "r");
if (file == NULL) { /*error*/ }

char buffer[1024];
// Read 1024 bytes at time until end of line
// and continue until the end of file
while(fgets(buffer, sizeof(buffer), file)} {
   //do something with buffer.
}

fclose(FILE);
```

Restart file reading from the beginning
```
rewind(file);
```

## Useful API for working with strings in the parser scenario

Splitting String
```
strtok_s(...) 
```

Comparing String (to implement start_with function)
```
strncmp(...)
```

