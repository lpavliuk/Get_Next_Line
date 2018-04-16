# Get_Next_Line

__get_next_line__ - function that will allows you to read every line ending with a newline character from a file descriptor.

You can manage multiple file descriptor with get_next_line. For ex- ample, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors
