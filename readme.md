LS:
    ls -R:
        $test1   test2   test3
        $
        $./folder1:
        $
        $./folder2:

The family of functions was extended to implement large file support. Functions named stat64(), lstat64() and fstat64() return attributes in a struct stat64 structure, which represents file sizes with a 64-bit type, allowing the functions to work on files 2 GiB and larger (up to 8 EiB). When the _FILE_OFFSET_BITS macro is defined to 64, these 64-bit functions are available under the original names.
